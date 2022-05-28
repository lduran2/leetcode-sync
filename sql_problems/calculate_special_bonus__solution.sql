# Write your MySQL query statement below

SELECT
        employee_id,
        (
            CASE
                # if odd employee ID
                WHEN (employee_id & 1)
                    # and name does not begin with 'M'
                    AND NOT(name LIKE 'M%')
                # give 100% bonus
                THEN salary
                # otherwise, bonus = 0
                ELSE 0
            END
        ) AS bonus
    FROM
        Employees
;