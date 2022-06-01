# Write your MySQL query statement below

# Table: Followers

# For each user, return the number of followers.

SELECT
        user_id,
        count(follower_id) AS followers_count
    FROM
        Followers
    GROUP BY user_id
    ORDER BY user_id
;