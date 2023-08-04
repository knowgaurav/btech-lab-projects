USE sales;

CREATE TABLE salesman(
	salesman_id INT PRIMARY KEY NOT NULL,
    name VARCHAR(30),
    city VARCHAR(20),
    commission INT
);

CREATE TABLE customer(
	customer_id INT NOT NULL,
    cust_name VARCHAR(25),
    city VARCHAR(25),
    grade INT,
    salesman_id INT,
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);

ALTER TABLE salesman
MODIFY COLUMN commission DECIMAL(3,2);

INSERT INTO salesman VALUES(5001, 'James Hoog', 'New York', 0.15);
INSERT INTO salesman VALUES(5002, 'Nail Knite', 'Paris', 0.13);
INSERT INTO salesman VALUES(5005, 'Pit Alex', 'London', 0.11);
INSERT INTO salesman VALUES(5006, 'Mc Lyon', 'Paris', 0.14);
INSERT INTO salesman VALUES(5007, 'Paul Adam', 'Rome', 0.13);
INSERT INTO salesman VALUES(5003, 'Lauson Hen', 'San Jose', 0.12);


INSERT INTO customer VALUES(3002, 'Nick Rimando', 'New York', 100, 5001);
INSERT INTO customer VALUES(3007, 'Brad Davis', 'New York', 200, 5001);
INSERT INTO customer VALUES(3005, 'Graham Zusi', 'California', 200, 5002);
INSERT INTO customer VALUES(3008, 'Julian Green', 'London', 300, 5002);
INSERT INTO customer VALUES(3004, 'Fabian Johnson', 'Paris', 300, 5006);
INSERT INTO customer VALUES(3009, 'Geoff Cameron', 'Berlin', 100, 5003);
INSERT INTO customer VALUES(3003, 'Jozy Altidor', 'Moscow', 200, 5007);
INSERT INTO customer VALUES(3001, 'Brad Guzan', 'London', NULL, 5005);

SELECT * FROM salesman;
SELECT * FROM customer;

SELECT name AS "Salesman",
customer.cust_name, customer.city 
FROM salesman,customer 
WHERE salesman.city=customer.city;

ALTER TABLE customer
ADD PRIMARY KEY(customer_id);

CREATE TABLE orders(
	order_no INT,
    purch_amt DECIMAL(10,2),
    ord_date DATE,
    customer_id INT,
    salesman_id INT,
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);

INSERT INTO orders VALUES(70001, 150.5, '2012-10-05', 3005, 5002);
INSERT INTO orders VALUES(70009, 270.65, '2012-09-10', 3001, 5005);
INSERT INTO orders VALUES(70002, 65.26, '2012-10-05', 3002, 5001);
INSERT INTO orders VALUES(70004, 110.5, '2012-08-17', 3009, 5003);
INSERT INTO orders VALUES(70007, 948.5, '2012-09-10', 3005, 5002);
INSERT INTO orders VALUES(70005, 2400.6, '2012-07-27', 3007, 5001);
INSERT INTO orders VALUES(70008, 5760, '2012-09-10', 3002, 5001);
INSERT INTO orders VALUES(70010, 1983.43, '2012-10-10', 3004, 5006);
INSERT INTO orders VALUES(70003, 2480.4, '2012-10-10', 3009, 5003);
INSERT INTO orders VALUES(70012, 250.45, '2012-06-27', 3008, 5002);
INSERT INTO orders VALUES(70011, 75.29, '2012-08-17', 3003, 5007);
INSERT INTO orders VALUES(70013, 3045.6, '2012-04-25', 3002, 5001);

SELECT * FROM orders;

-- SELF Join
SELECT  a.order_no,a.purch_amt,
b.cust_name,b.city 
FROM orders a,customer b 
WHERE a.customer_id=b.customer_id 
AND a.purch_amt BETWEEN 500 AND 2000;

-- Write a SQL statement to know which salesman are working for which customer.
SELECT a.cust_name AS "Customer Name", 
a.city, b.name AS "Salesman", b.commission 
FROM customer a 
INNER JOIN salesman b 
ON a.salesman_id=b.salesman_id;

-- Write a SQL statement to find the list of customers who appointed a salesman for their jobs who gets a commission from the company is more than 12%.
SELECT a.cust_name AS "Customer Name", 
a.city, b.name AS "Salesman", b.commission 
FROM customer a 
INNER JOIN salesman b 
ON a.salesman_id=b.salesman_id 
WHERE b.commission>.12;

-- Write a SQL statement to find the list of customers who appointed a salesman for their jobs who does not live in the same city where their customer lives, and gets a commission is above 12%.
SELECT a.cust_name AS "Customer Name", 
a.city, b.name AS "Salesman", b.city,b.commission  
FROM customer a  
INNER JOIN salesman b  
ON a.salesman_id=b.salesman_id 
WHERE b.commission>.12 
AND a.city<>b.city;

-- Write a SQL statement to find the details of a order i.e. order number, order date, amount of order, which customer gives the order and which salesman works for that customer and commission rate he gets for an order.
SELECT a.order_no,a.ord_date,a.purch_amt,
b.cust_name AS "Customer Name", b.grade, 
c.name AS "Salesman", c.commission 
FROM orders a 
INNER JOIN customer b 
ON a.customer_id=b.customer_id 
INNER JOIN salesman c 
ON a.salesman_id=c.salesman_id;

-- Write a SQL statement to make a join on the tables salesman, customer and orders in such a form that the same column of each table will appear once and only the relational rows will come.
SELECT * 
FROM orders 
NATURAL JOIN customer  
NATURAL JOIN salesman;

-- Write a SQL statement to make a list in ascending order for the customer who works either through a salesman or by own.
SELECT a.cust_name,a.city,a.grade, 
b.name AS "Salesman",b.city 
FROM customer a 
LEFT JOIN salesman b 
ON a.salesman_id=b.salesman_id 
order by a.customer_id;

-- Write a SQL statement to make a list in ascending order for the customer who holds a grade less than 300 and works either through a salesman or by own.
SELECT a.cust_name,a.city,a.grade, 
b.name AS "Salesman", b.city 
FROM customer a 
LEFT OUTER JOIN salesman b 
ON a.salesman_id=b.salesman_id 
WHERE a.grade<300 
ORDER BY a.customer_id;

-- Write a SQL statement to make a report with customer name, city, order number, order date, and order amount in ascending order according to the order date to find that either any of the existing customers have placed no order or placed one or more orders.
SELECT a.cust_name,a.city, b.order_no,
b.ord_date,b.purch_amt AS "Order Amount" 
FROM customer a 
LEFT OUTER JOIN orders b 
ON a.customer_id=b.customer_id 
order by b.ord_date;

