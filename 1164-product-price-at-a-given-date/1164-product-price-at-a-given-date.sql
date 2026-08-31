# Write your MySQL query statement below
SELECT p.product_id, p.new_price AS price
FROM Products p
WHERE p.change_date = (
    SELECT MAX(p1.change_date) 
    FROM Products p1
    WHERE p.product_id = p1.product_id AND change_date <= "2019-08-16"
)

UNION 

SELECT product_id, (
    CASE WHEN MIN(change_date) > "2019-08-16"
    THEN 10
    END
) AS price
FROM Products
GROUP BY product_id
HAVING MIN(change_date) > "2019-08-16"

