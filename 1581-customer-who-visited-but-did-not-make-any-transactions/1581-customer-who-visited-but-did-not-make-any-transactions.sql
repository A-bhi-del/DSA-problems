# Write your MySQL query statement below
select Visits.customer_id, Count(*) as Count_no_trans from Visits
LEFT JOIN Transactions ON
Visits.visit_id = Transactions.visit_id
where Transactions.transaction_id IS NULL
group by Visits.customer_id