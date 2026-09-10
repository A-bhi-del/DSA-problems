# Write your MySQL query statement below
WITH COPY AS (
    SELECT D.driver_id, D.driver_name, T.trip_date, (T.distance_km/T.fuel_consumed) AS fuel_per
    FROM drivers D
    JOIN trips T
    ON D.driver_id = T.driver_id
    WHERE D.driver_id IN (
        SELECT TT.driver_id 
        FROM trips TT
        WHERE TT.driver_id = D.driver_id AND
        MONTH(trip_date) >= 1 AND MONTH(trip_date) <= 6
    ) AND D.driver_id IN (
        SELECT TT.driver_id 
        FROM trips TT
        WHERE TT.driver_id = D.driver_id AND
        MONTH(trip_date) >= 7 AND MONTH(trip_date) <= 12
    )
)

SELECT driver_id, driver_name,
    ROUND(AVG(
        CASE WHEN MONTH(trip_date) BETWEEN 1 AND 6
        THEN fuel_per END
    ), 2) AS first_half_avg,
    ROUND(AVG(
        CASE WHEN MONTH(trip_date) BETWEEN 7 AND 12
        THEN fuel_per END
    ), 2) AS second_half_avg,
    ROUND(
        AVG(CASE WHEN MONTH(trip_date) BETWEEN 7 AND 12 THEN fuel_per END) -
        AVG(CASE WHEN MONTH(trip_date) BETWEEN 1 AND 6 THEN fuel_per END)
    , 2) AS efficiency_improvement
FROM COPY
GROUP BY driver_id, driver_name
HAVING efficiency_improvement > 0
ORDER BY efficiency_improvement DESC, driver_name;