/*USE student;

CREATE table details(
	stu_id int NOT NULL,
	stu_name varchar(255),
    stu_city varchar(30),
    stu_contact bigint,
    stu_passingyear int
);

INSERT INTO details VALUES(101, 'Gaurav Singh', 'Faridabad' , 8700771318, 2023);
INSERT INTO details VALUES(102, 'Pratham Aggarwal', 'New Delhi' , 8799810291, 2023);
INSERT INTO details VALUES(103, 'Shivam Singh', 'Noida' , 8719230111, 2023);
INSERT INTO details VALUES(104, 'Siddhant Srivastava', 'Noida' , 9810234566, 2023);
INSERT INTO details VALUES(105, 'Akul Varshney', 'Noida' , 9990234569, 2023);

SELECT * FROM details;

SELECT * FROM details
WHERE stu_name = 'Gaurav Singh';*/

UPDATE details
SET stu_contact = 9833445566
WHERE stu_name = 'Akul Varshney';
