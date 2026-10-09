# Write your MySQL query statement below

SELECT
    t1.product_id,
    IFNULL(round(sum(t1.price * t2.units)/sum(t2.units),2), 0) as average_price 
FROM 
    prices t1
LEFT JOIN 
    UnitsSold t2 
    ON t1.product_id = t2.product_id 
    AND t2.purchase_date between t1.start_date and t1.end_date
GROUP BY
    t1.product_id