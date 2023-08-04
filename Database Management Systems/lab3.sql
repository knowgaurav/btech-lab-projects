USE employee;

/*DROP TABLE IF EXISTS department;
DROP TABLE IF EXISTS details;

CREATE TABLE department(
    dept_id int NOT NULL UNIQUE,
    dept_name varchar(50),
    dept_loc varchar(50)
);

CREATE TABLE details(
	emp_id int NOT NULL,
    emp_name varchar(50),
    emp_hiredate date,
    emp_salary int,
    dept_id int,
    CONSTRAINT FK_Dept FOREIGN KEY (dept_id) REFERENCES department(dept_id),
    PRIMARY KEY (emp_id)
);

INSERT INTO department VALUES(101, 'Computer Science', 'Block 1');
INSERT INTO department VALUES(102, 'Information Technology', 'Block 2');
INSERT INTO department VALUES(103, 'Electronics Engg.', 'Block 3');
INSERT INTO department VALUES(104, 'Mechanical Engg.', 'Block 4');
INSERT INTO department VALUES(105, 'Civil Engg.', 'Block 5');

SELECT * FROM department;
SELECT * FROM details;

desc details;

INSERT INTO details VALUES(1, 'Gaurav', '2010-10-15', 100000, 101);
INSERT INTO details VALUES(2, 'Shivam', '2012-05-05', 90000, 102);
INSERT INTO details VALUES(3, 'Siddhant', '2015-01-18', 70000, 103);
INSERT INTO details VALUES(4, 'Akul', '2016-11-07', 60000, 104);
INSERT INTO details VALUES(5, 'Pratham', '2017-12-25', 50000, 105);

SELECT emp_id, emp_name, emp_hiredate, emp_salary FROM details WHERE emp_salary > 50000;

SELECT * FROM details WHERE emp_salary > 60000 AND dept_id = 101;

SELECT * FROM details WHERE emp_hiredate BETWEEN CAST('2012-05-05' AS DATE) AND CAST('2015-01-18' AS DATE);

SELECT * FROM details WHERE emp_name BETWEEN 'A' AND 'Q';

SELECT * FROM details ORDER BY emp_ ASC;

UPDATE details
SET emp_name = 'Akul Varshney'
WHERE emp_id=4;

SELECT * FROM details WHERE emp_id=4;

CREATE TABLE test(name varchar(255));
INSERT INTO test VALUES('Gaurav Singh');
TRUNCATE TABLE test;
SELECT * FROM test;
DROP TABLE test;*/

SELECT dept_id FROM department
UNION ALL
SELECT dept_id FROM details
WHERE emp_salary > 50000
ORDER BY dept_id;





