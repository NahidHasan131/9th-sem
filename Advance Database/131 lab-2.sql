create database employeedb;
use employeedb;

CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50),
    Department VARCHAR(30),
    Position VARCHAR(30),
    Salary DECIMAL(10, 2),
    HireDate DATE
);

INSERT INTO Employee (EmployeeID, Name, Department, Position, Salary, HireDate)
VALUES (101, 'Alice Roy', 'HR', 'Manager', 65000, '2018-06-01'),
	   (102, 'Babu Khan', 'IT', 'Developer', 50000, '2019-03-15'),
       (103, 'Chadni Akter ', 'Finance', 'Analyst', 47000, '2020-01-10'),
	   (104, 'Dipon Das ', 'IT', 'Developer', 52000, '2021-11-12 '),
	   (105, 'Esha Rani ', 'HR', 'Executive', 40000, '2022-08-30'),
	   (106, 'Farid Ahmed', 'Finance', 'Manager', 68000, '2017-02-01'),
	   (107, 'Gulshan Ara', 'IT', 'Manager', 70000, '2016-12-20');


SELECT * FROM Employee WHERE Name LIKE 'A%';

SELECT Name, Department FROM Employee WHERE Position LIKE '%er';

SELECT SUBSTRING(name, 1,3) FROM Employee;


SELECT * FROM Employee  ORDER BY Salary DESC;


SELECT Name FROM Employee WHERE Department ='Hr' UNION SELECT Name FROM Employee WHERE Department ='Finance'; 

SELECT Name FROM Employee WHERE Department = 'IT' INTERSECT SELECT Name FROM Employee WHERE Department = 'Finance';

SELECT Name FROM Employee WHERE Department = 'IT' EXCEPT SELECT Name FROM Employee WHERE Department = 'HR';



SELECT SUM(Salary) AS TotalSalary FROM Employee;

SELECT AVG(Salary) AS AvgITSalary FROM Employee WHERE Department = 'IT';

SELECT MAX(Salary) AS MaxSalary FROM Employee;

SELECT COUNT(*) AS FinanceCount FROM Employee WHERE Department = 'Finance';


SELECT Department, AVG(Salary) AS AvgSalary FROM Employee GROUP BY Department;

SELECT Department, AVG(Salary) AS AvgSalary FROM Employee GROUP BY Department HAVING AVG(Salary) > 50000;

SELECT Position, COUNT(*) AS EmployeeCount FROM Employee GROUP BY Position;



SELECT * FROM Employee WHERE Salary > (SELECT AVG(Salary) FROM Employee);

SELECT Name FROM Employee WHERE HireDate < (SELECT MIN(HireDate) FROM Employee WHERE Department = 'HR');

SELECT Name FROM Employee WHERE Salary IN (SELECT Salary FROM Employee WHERE Department = 'Finance');

SELECT * FROM Employee WHERE Salary = (SELECT MAX(Salary) FROM Employee WHERE Salary < (SELECT MAX(Salary) FROM Employee));




select * from Employee;