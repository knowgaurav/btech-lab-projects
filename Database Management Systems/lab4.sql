USE customer;
USE employee;
CREATE TABLE customer_details(id int, name varchar(20), address varchar(20), phone char(10));

desc customer_details;

INSERT INTO customer_details values(1, 'Brock Lesnar', 'USA', '9999911020');
INSERT INTO customer_details values(2, 'Triple H', 'USA', '9999231110');
INSERT INTO customer_details values(3, 'Great Khali', 'India', '9988823020');
INSERT INTO customer_details values(4, 'The Rock', 'USA', '9229911020');

USE employee;
SELECT * FROM details
WHERE emp_name LIKE 'S%';

ALTER TABLE details
ADD emp_email varchar(30); 

ALTER TABLE details
MODIFY emp_email varchar(20) AFTER emp_name;

USE customer;
ALTER TABLE customer_details
ADD UNIQUE(phone);

desc customer_details;

USE customer;
ALTER TABLE customer_details
ADD PRIMARY KEY(id);

USE customer;
ALTER TABLE customer_details 
DROP COLUMN address;

desc customer_details;

USE customer;
ALTER TABLE customer_details
MODIFY phone char(15);

USE customer;
RENAME TABLE customer_details TO customer_pk;

USE employee;
CREATE INDEX emp_index
ON details(emp_name);

desc details;

USE customer;
CREATE TABLE books(id INT UNIQUE NOT NULL, title varchar(20) NOT NULL);
CREATE TABLE movies(id INT UNIQUE NOT NULL, title varchar(20) NOT NULL);
USE customer;

INSERT INTO books values(1, 'The Witcher');
INSERT INTO books values(2, 'Harry Potter');
INSERT INTO books values(3, '1984');
INSERT INTO books values(4, 'The Great Gatsby');

INSERT INTO movies values(1, 'Iron Man');
INSERT INTO movies values(2, 'Harry Potter');
INSERT INTO movies values(3, 'Dr. Strange');
INSERT INTO movies values(4, 'The Great Gatsby');

USE customer;

SELECT * FROM books 
UNION 
SELECT * FROM movies;

USE customer;
SELECT title FROM books
UNION ALL
SELECT title FROM movies;

USE customer;
SELECT title FROM books
WHERE title IN (SELECT title FROM movies);







