USE library;

/*CREATE TABLE member(
	mem_id int NOT NULL,
	mem_name varchar(255),
    mem_city varchar(30),
    mem_contact bigint
);

INSERT INTO member VALUES(101, 'Gaurav Singh', 'Faridabad' , 8700771318);
INSERT INTO member VALUES(102, 'Pratham Aggarwal', 'New Delhi' , 8799810291);
INSERT INTO member VALUES(103, 'Shivam Singh', 'Noida' , 8719230111);
INSERT INTO member VALUES(104, 'Siddhant Srivastava', 'Noida' , 9810234566);
INSERT INTO member VALUES(105, 'Akul Varshney', 'Noida' , 9990234569);

SELECT * FROM member;

CREATE TABLE book(
	b_id int NOT NULL,
	b_name varchar(255),
    b_author varchar(30),
    b_type varchar(30)
);

ALTER TABLE book
ADD b_price int;

desc book;

INSERT INTO book VALUES(1, 'Zero To One', 'Peter Thiel', 'Business', 299);
INSERT INTO book VALUES(2, 'The Lean Startup', 'Eric Ries', 'Business', 599);
INSERT INTO book VALUES(3, 'The Grand Design', 'Stephen Hawkings', 'Science', 799);
INSERT INTO book VALUES(4, 'The Power of your Subconcious Mind', 'Joseph Murphy', 'Self Help', 199);
INSERT INTO book VALUES(5, 'Becoming Steve Jobs', 'Brent Rick', 'Business', 999);

SELECT * FROM book;

CREATE TABLE issue(
	mem_id int NOT NULL,
    b_id int NOT NULL,
    issue_date date,
    return_date date
);

insert into issue values(105, 1, '2020-03-12', '2020-03-20');
insert into issue values(104, 2, '2020-04-01', '2020-04-08');
insert into issue values(103, 3, '2020-05-11', '2020-05-19');
insert into issue values(102, 4, '2020-06-15', '2020-06-23');
insert into issue values(101, 5, '2020-07-20', '2020-07-28'); 

SELECT * FROM issue;


SELECT b_id, b_name
FROM book
GROUP BY b_type;

SELECT mem_id, b_id
FROM issue
WHERE issue_date BETWEEN '2020-03-01' AND '2020-06-30';

SELECT mem_name
FROM member
WHERE mem_name LIKE 'S%';*/

SELECT count(*)
FROM 








