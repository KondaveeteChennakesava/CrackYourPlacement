# Write your MySQL query statement below
SELECT e1.name AS Employee
FROM Employee e1
LEFT JOIN Employee e2 ON e2.id = e1.managerId 
WHERE e2.salary < e1.salary;