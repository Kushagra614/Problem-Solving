# Write your MySQL query statement below

-- apply right join

SELECT 
    eu.unique_id,
    e.name
FROM 
    Employees e
LEFT JOIN 
    EmployeeUNI eu ON e.id = eu.id;