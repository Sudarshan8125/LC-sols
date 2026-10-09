# Write your MySQL query statement below

WITH cte as (
select t1.name as Employee,t1.salary,t2.name as Department,t1.departmentId  from Employee t1 JOIN Department t2 ON t1.departmentId = t2.id)

select t.Department, t.Employee, t.Salary from (
select *, dense_rank() over(partition by departmentId order by salary desc) as dnk
from cte) t where t.dnk<=3;