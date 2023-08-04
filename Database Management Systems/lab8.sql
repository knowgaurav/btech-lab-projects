USE sea;

CREATE TABLE sailors(
	sid INT PRIMARY KEY NOT NULL,
    sname VARCHAR(30),
    rating INT,
    age DECIMAL(3,1)
);

CREATE TABLE boats(
	bid INT PRIMARY KEY NOT NULL,
    bname VARCHAR(30),
    color VARCHAR(10)
);

CREATE TABLE reserves(
	sid INT,
    bid INT,
    day DATE,
    PRIMARY KEY(sid, bid),
    FOREIGN KEY (sid) REFERENCES sailors(sid),
    FOREIGN KEY (bid) REFERENCES boats(bid)
);

-- DROP TABLE sailors;
-- DROP TABLE reserves;

INSERT INTO sailors VALUES(22, 'Dustin', 7, 45);
INSERT INTO sailors VALUES(29, 'Brutus', 1, 33);
INSERT INTO sailors VALUES(31, 'Lubber', 8, 55.5);
INSERT INTO sailors VALUES(32, 'Andy', 8, 25.5);
INSERT INTO sailors VALUES(58, 'Rusty', 10, 35);
INSERT INTO sailors VALUES(64, 'Horatio', 7, 35);
INSERT INTO sailors VALUES(71, 'Zorba', 10, 16);
INSERT INTO sailors VALUES(74, 'Horatio', 9, 40);
INSERT INTO sailors VALUES(85, 'Art', 3, 25.5);
INSERT INTO sailors VALUES(95, 'Bob', 3, 63.5);

INSERT INTO boats VALUES(101, 'Interlake', 'blue');
INSERT INTO boats VALUES(102, 'Interlake', 'red');
INSERT INTO boats VALUES(103, 'Clipper', 'green');
INSERT INTO boats VALUES(104, 'Marine', 'red');

INSERT INTO reserves VALUES(22, 101, '1998-10-10');
INSERT INTO reserves VALUES(22, 102, '1998-10-10');
INSERT INTO reserves VALUES(22, 103, '1998-10-8');
INSERT INTO reserves VALUES(22, 104, '1998-10-7');
INSERT INTO reserves VALUES(31, 102, '1998-11-10');
INSERT INTO reserves VALUES(31, 103, '1998-11-6');
INSERT INTO reserves VALUES(31, 104, '1998-11-12');
INSERT INTO reserves VALUES(64, 101, '1998-9-5');
INSERT INTO reserves VALUES(64, 102, '1998-9-8');
INSERT INTO reserves VALUES(74, 103, '1998-9-8');

SELECT * FROM sailors;
SELECT * FROM boats;
SELECT * FROM reserves;

-- Using Distinct
SELECT distinct sname, age
FROM sailors AS S;

-- Find all information of sailors who have reserved boat number 101.
SELECT S.*
FROM Sailors S, Reserves R
WHERE S.sid = R.sid AND R.bid = 103;

-- Find the names of sailors who have reserved a red boat, and list in the order of age.
SELECT S.sname, S.age
FROM sailors AS S, reserves AS R, boats AS B
WHERE S.sid = R.sid AND R.bid = B.bid AND B.color = 'red'
ORDER BY S.age DESC;

-- Find the names of sailors who have reserved at least one boat.
SELECT DISTINCT sname
FROM sailors AS S, reserves AS R
WHERE S.sid = R.sid;

SELECT DISTINCT sname
FROM sailors NATURAL JOIN reserves;

-- Find the ids and names of sailors who have reserved two different boats on the same day.
SELECT DISTINCT S.sid, S.sname
FROM Sailors S, Reserves R1, Reserves R2
WHERE S.sid = R1.sid AND S.sid = R2.sid
AND R1.day = R2.day AND R1.bid <> R2.bid;

-- Using Expressions and Strings in the SELECT Command.
SELECT sname, age, rating+1 as sth
FROM sailors
WHERE sname like 'B_%b'
HAVING 2*sth-1<10;

-- Find the ids of sailors who have reserved a red boat or a green boat.
SELECT R.sid
FROM Boats B, Reserves R
WHERE R.bid = B.bid AND B.color = 'red'
UNION
SELECT R2.sid
FROM Boats B2, Reserves R2
WHERE R2.bid = B2.bid AND B2.color = 'green';

SELECT DISTINCT S.sid, S.sname
FROM sailors S NATURAL JOIN boats B NATURAL JOIN reserves R
WHERE B.color = 'Red' OR B.color = 'Green';

-- UNION ALL
SELECT S.sid, S.sname
FROM sailors S NATURAL JOIN boats B NATURAL JOIN reserves R
WHERE B.color = 'Red' OR B.color = 'Green';

-- Nested Queries
-- Find the names of sailors who have reserved boat 103.
SELECT S.sname AS 'Sailor Name'
FROM Sailors S
WHERE S.sid IN ( SELECT R.sid
FROM Reserves R
WHERE R.bid = 103);

-- (Correlated Nested Queries)
SELECT S.sname
FROM Sailors S
WHERE EXISTS (SELECT *
FROM Reserves R
WHERE R.bid = 103
AND R.sid = S.sid);

-- Find the name and the age of the youngest sailor.
SELECT S.sname, S.age
FROM Sailors S
WHERE S.age <= ALL( SELECT age
FROM Sailors);

SELECT sname AS 'Name', MIN(age) AS 'Age'
FROM sailors;

-- Find the names and ratings of sailor whose rating is better than some sailor called Horatio.
SELECT S.sname, S.rating
FROM Sailors S
WHERE S.rating > ANY ( SELECT S2.rating
FROM Sailors S2
WHERE S2.sname = 'Lubber');

-- Find the names of sailors who have reserved all boats.
SELECT S.sname
FROM Sailors S
WHERE NOT EXISTS (SELECT B.bid FROM Boats B
WHERE B.bid NOT IN (SELECT R.bid FROM Reserves R WHERE R.sid = S.sid));

-- Aggregation Operators
-- Find the average age of sailors for each rating level.
SELECT S.rating, AVG(S.age) AS avg_age
FROM Sailors S
GROUP BY S.rating
ORDER BY S.rating;

-- Find the average age of sailors for each rating level that has at least two sailors.
SELECT S.rating, AVG(S.age) AS avg_age
FROM Sailors S
GROUP BY S.rating
HAVING COUNT(*) > 1;

-- An example shows difference between WHERE and HAVING:
SELECT S.rating, AVG(S.age) as avg_age
FROM Sailors S
WHERE S.age >=40
GROUP BY S.rating
ORDER BY S.rating;

SELECT S.rating, AVG(S.age) as avg_age
FROM Sailors S
GROUP BY S.rating
HAVING AVG(S.age) >= 40
ORDER BY S.rating;

INSERT INTO sailors VALUES(99, 'Dan', NULL, 48.0);
-- Count simply discards null values

SELECT COUNT(*) AS 'No. of Sailors'
FROM sailors;

SELECT COUNT(rating) AS 'No. of Ratings'
FROM sailors;

-- Left Outer Join
SELECT sailors.sid, sailors.sname, reserves.bid
FROM sailors LEFT OUTER JOIN reserves
ON reserves.sid = sailors.sid
ORDER BY sailors.sid;



-- UNION ALL
-- SELECT S.sid, S.sname
-- FROM sailors S NATURAL JOIN boats B NATURAL JOIN reserves R
-- WHERE B.color = 'Green';

-- INTERSECT
-- SELECT DISTINCT S.sid, S.sname, B.color
-- FROM sailors S NATURAL JOIN boats B NATURAL JOIN reserves R
-- WHERE B.color = 'Red' AND S.sid IN (SELECT S.sid
-- FROM sailors S NATURAL JOIN boats B INNER JOIN reserves R
-- WHERE B.color = 'Green');

-- SELECT DISTINCT S.sid, S.sname, B.color
-- FROM sailors S NATURAL JOIN boats B NATURAL JOIN reserves R
-- WHERE B.color = 'Red' AND S.sid NOT IN (SELECT S.sid
-- FROM sailors S NATURAL JOIN boats B INNER JOIN reserves R
-- WHERE B.color = 'Green');





