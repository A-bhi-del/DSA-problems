# Write your MySQL query statement below
select activity_date as day, Count(DISTINCT user_id) as active_users from Activity
where activity_date > "2019-06-27" and activity_date <= "2019-07-27" and activity_type is not null
group by activity_date 