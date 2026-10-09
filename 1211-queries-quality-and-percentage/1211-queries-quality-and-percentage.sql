# Write your MySQL query statement below


select query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    #ROUND(
    #    (select count(*) from queries t2 where t1.query_name = t2.query_name AND rating < 3)
    #    * 100/count(*), 2) as poor_query_percentage
    #ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2) AS poor_query_percentage
    ROUND(AVG(rating < 3) * 100, 2) AS poor_query_percentage
from queries t1
group by query_name