# Write your MySQL query statement below
SELECT  U.user_id AS buyer_id, U.join_date, COUNT(O.order_id) AS orders_in_2019 FROM Users U LEFT JOIN Orders O
ON O.buyer_id = U.user_id
AND O.order_date >= "2019-01-01" 
AND O.order_date < "2020-01-01"
GROUP BY U.user_id;