# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# Delete all the duplicate emails, keeping only one unique email with
# the smallest id.

# Table: Person

DELETE FROM Person
    # delete when the email is the same, but ids differ
    WHERE
        # id does not match the minimum ID for each email
        (id NOT IN
            (
                # select from the MinIds that match this email
                SELECT id
                    FROM
                        (
                            # use a table of emails to minimum IDs
                            SELECT
                                    email,
                                    # choose the minimum ID for each email
                                    min(id) AS id
                                FROM
                                    Person
                                GROUP BY email
                        ) As MinIds
                    WHERE
                        (Person.id = MinIds.id)
            )
        )
;