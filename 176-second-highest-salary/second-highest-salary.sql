# Write your MySQL query statement below
SELECT (SELECT DISTINCT salary from Employee Order By salary desc LIMIT 1 OFFSET 1) as SecondHighestSalary;