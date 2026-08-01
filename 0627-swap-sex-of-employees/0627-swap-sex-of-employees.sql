# Write your MySQL query statement below
update Salary
set sex = Case when sex = 'm' then 'f' else 'm' end