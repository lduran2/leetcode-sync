# Write your MySQL query statement below

# select each day
SELECT activity_date AS day,
        # count users of that date
        count(DISTINCT user_id) AS active_users
    FROM Activity
    WHERE (
        Date(activity_date) BETWEEN
            date_add('2019-07-27', Interval -29 Day)
            AND '2019-07-27'
    )
    # group together activities on same date
    GROUP BY activity_date
;
