-- SELECT *
-- FROM library.issue;

-- SELECT *
-- FROM library.member;

-- SELECT *
-- FROM library.book;

-- SELECT mem_name AS 'Member Name'
-- FROM library.member, library.issue
-- WHERE library.member.mem_id=library.issue.mem_id AND library.issue.return_date='2020-07-28';

-- SELECT mem_id AS 'Member ID', b_price AS 'Book Cost'
-- FROM library.book AS B, library.issue AS I
-- WHERE B.b_id = I.b_id AND B.b_price > 500;

-- -- SELECT B.b_id, B.b_price, B.b_type, I.b_id
-- -- FROM library.book AS B, library.issue AS I
-- -- WHERE I.b_id+=B.b_id;

-- INSERT INTO book VALUES(6, 'The Intelligent Investor', 'Benjamin Graham', 'Business', 649);
-- INSERT INTO book VALUES(7, 'Harry Potter and The Half Blood Prince', 'JK Rowling', 'Fiction', 349);
-- INSERT INTO issue VALUES(101, 1, '2020-03-10', '2020-03-17');

-- FULL OUTER JOIN using UNION of LEFT JOIN and RIGHT JOIN
-- USE library;
-- SELECT *
-- FROM book B LEFT JOIN issue I
-- ON B.b_id = I.b_id
-- UNION
-- SELECT *
-- FROM book B RIGHT JOIN issue I
-- ON B.b_id = I.b_id;


-- USE employee2;

-- -- CREATE TABLE employee(
-- -- 	emp_code INT(10) NOT NULL,
-- --     emp_name VARCHAR(30),
-- --     salary_num INT(15),
-- --     mgr_name VARCHAR(10)
-- -- );

-- CREATE TABLE salary(
-- 	grade VARCHAR(5),
--     low_sal INT(5),
--     high_sal INT (15)
-- );

-- USE employee2;
-- DROP TABLE employee, salary;

-- CREATE TABLE employee(
-- 	emp_code INT(4) NOT NULL,
--     emp_name VARCHAR(30),
--     salary INT(7),
--     mgr_name VARCHAR(10)
-- );

-- CREATE TABLE salary(
-- 	grade VARCHAR(5),
--     low_sal INT(5),
--     high_sal INT (10)
-- );

-- USE employee2;
-- ALTER TABLE employee
-- ADD COLUMN grade VARCHAR(1);

-- UPDATE employee
-- SET grade='A'
-- WHERE salary BETWEEN 90000 AND 100000;

-- SELECT * FROM employee;

-- INSERT INTO employee VALUES(1001, 'Micheal Scott', 95000, 'Jan');
-- INSERT INTO employee VALUES(1002, 'Dwight Schrute', 70000, 'Micheal');
-- INSERT INTO employee VALUES(1003, 'Jim Halpert', 75000, 'Micheal');
-- INSERT INTO employee VALUES(1004, 'Pam Beesly', 55000, 'Micheal');
-- INSERT INTO employee VALUES(1005, 'Kevin Malone', 44000, 'Micheal');

-- INSERT INTO salary VALUES('A', 80000, 100000);
-- INSERT INTO salary VALUES('B', 60000, 80000);
-- INSERT INTO salary VALUES('C', 40000, 60000);

-- USE employee2;
-- SELECT *
-- FROM employee;

-- USE employee2;
-- SELECT *
-- FROM salary;

-- USE employee2;
-- SELECT emp_code, emp_name, salary, grade, low_sal, high_sal
-- FROM employee, salary
-- WHERE salary BETWEEN 60000 AND 80000 AND grade='B';

USE employee2;
DESC salary;

ALTER TABLE salary
ADD PRIMARY KEY(grade);

ALTER TABLE employee
ADD FOREIGN KEY (grade) REFERENCES salary(grade);

DESC employee;

SELECT *
FROM employee
NATURAL JOIN salary;



