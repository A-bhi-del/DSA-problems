# Write your MySQL query statement below
select P.product_id, IFNULL(
    ROUND(SUM(P.price * U.units)/SUM(units), 2), 0
) as average_price 
from Prices P 
    LEFT JOIN UnitsSold U 
        ON P.product_id = U.product_id 
            and 
U.purchase_date BETWEEN P.start_date and P.end_date
group by P.product_id