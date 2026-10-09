# Write your MySQL query statement below
select distinct max(t.salary) as  'SecondHighestSalary' from (
select *, dense_rank() over(order by salary desc) as 'drnk' from employee)
t where t.drnk = 2;