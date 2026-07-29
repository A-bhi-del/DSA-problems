# Write your MySQL query statement below
select Person.firstName, lastName, Address.city,state From Person 
LEFT JOIN Address ON
Person.personId = Address.personId