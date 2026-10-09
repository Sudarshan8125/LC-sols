# Write your MySQL query statement below

# i require count for a perticular department that is my window
# subquery solution
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
        OR employee_id IN (
                SELECT employee_id 
                FROM Employee 
                GROUP BY employee_id 
                HAVING COUNT(department_id) = 1
        );
