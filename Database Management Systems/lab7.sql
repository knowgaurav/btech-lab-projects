USE lab;

CREATE TABLE suppliers(
	sid INT PRIMARY KEY,
    sname VARCHAR(25),
    address VARCHAR(30)
);

CREATE TABLE parts(
	pid INT PRIMARY KEY,
    pname VARCHAR(25),
    color VARCHAR(30)
);

CREATE TABLE catalog(
	sid INT,
    pid INT,
    cost VARCHAR(30),
    PRIMARY KEY (sid, pid),
	FOREIGN KEY (sid) REFERENCES suppliers(sid),
	FOREIGN KEY (pid) REFERENCES parts(pid)
);

ALTER TABLE catalog
MODIFY cost INT(10);

INSERT INTO suppliers VALUES(1, 'Apple', 'Cupertino, USA');
INSERT INTO suppliers VALUES(2, 'Samsung', 'South Korea');
INSERT INTO suppliers VALUES(3, 'OnePlus', 'China');
INSERT INTO suppliers VALUES(4, 'Google', 'USA');
INSERT INTO suppliers VALUES(5, 'TMC', 'China');

UPDATE suppliers
SET address='USA'
WHERE sid=5;
UPDATE suppliers
SET sname='Amazon'
WHERE sid=5;

INSERT INTO parts VALUES(101, 'iPhone', 'Black');
INSERT INTO parts VALUES(102, 'iPhone', 'Red');
INSERT INTO parts VALUES(103, 'S21', 'Black');
INSERT INTO parts VALUES(104, 'S21', 'Red');
INSERT INTO parts VALUES(105, 'Oneplus 8T', 'Silver Grey');
INSERT INTO parts VALUES(108, 'Oneplus 8T', 'Red');
INSERT INTO parts VALUES(106, 'Pixel', 'Red');
INSERT INTO parts VALUES(107, 'Pixel', 'Pale Green');


INSERT INTO catalog VALUES(1, 101, 90000);
INSERT INTO catalog VALUES(1, 102, 92000);
INSERT INTO catalog VALUES(2, 103, 75000);
INSERT INTO catalog VALUES(2, 104, 78000);
INSERT INTO catalog VALUES(3, 105, 50000);
INSERT INTO catalog VALUES(4, 106, 55000);
INSERT INTO catalog VALUES(4, 107, 45000);
INSERT INTO catalog VALUES(5, 101, 89000);
INSERT INTO catalog VALUES(5, 102, 90000);
INSERT INTO catalog VALUES(3, 108, 48000);
INSERT INTO catalog VALUES(5, 108, 47000);
INSERT INTO catalog VALUES(5, 106, 54000);
INSERT INTO catalog VALUES(5, 104, 77000);


SELECT * FROM parts;

SELECT * FROM suppliers;

SELECT * FROM catalog;

SELECT sname
FROM suppliers NATURAL JOIN catalog NATURAL JOIN parts
WHERE color='Red';

SELECT sid
FROM catalog NATURAL JOIN parts
WHERE (color='Red' or color='Silver Grey');

SELECT sid AS 'ID'
FROM catalog NATURAL JOIN parts
WHERE color='Red' OR color='Pale Green';

SELECT C.sid
FROM catalog C
WHERE NOT EXISTS (SELECT P.pid FROM parts P WHERE P.color='Red' AND NOT EXISTS
(SELECT C1.sid FROM catalog C1 WHERE c1.sid=sid AND C1.pid=P.pid));

(select S.sid
 from suppliers S
 where  not exists((select P.pid from parts P where P.color='Red')
 except (select C.pid from catalog C where C.sid=S.sid) )
)
union
(select S.sid
 from suppliers S
 where  not exists((select P.pid from parts P where P.color='Pale Green')
 except (select C.pid from catalog C where C.sid=S.sid))
);

-- Find the pids of parts that are supplied by at least two different suppliers.
select distinct C.pid
from   catalog C
where  exists(select C1.sid from catalog C1 where  C1.pid = C.pid and C1.sid != C.sid);

-- Find the pids of the most expensive part(s) supplied by suppliers named "Amazon".
select C.pid
from   Catalog C, Suppliers S
where  S.sname='Amazon' and C.sid=S.sid and C.cost >= all(select C2.cost from Catalog C2, Suppliers S2 where  S2.sname='Amazon' and C2.sid=S2.sid);

-- Find the pids of parts supplied by every supplier at a price less than 60000
select C.pid
from   Catalog C
where  C.cost  < 60000
group by C.pid;



