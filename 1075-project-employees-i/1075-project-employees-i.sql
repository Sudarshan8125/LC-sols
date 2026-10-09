# Write your MySQL query statement below

select t1.project_id,IFNULL(ROUND(SUM(t2.experience_years) / COUNT(t1.employee_id), 2), 0) AS average_years from project t1
LEFT JOIN employee t2 on t1.employee_id = t2.employee_id
group by t1.project_id