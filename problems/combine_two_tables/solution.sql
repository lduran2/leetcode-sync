# Write your MySQL query statement below

# Table: Person
# personId is the primary key column for this table.
# Table: Address

# Report the first name, last name, city, and state of each person in
# the Person table. If the address of a personId is not present in the
# Address table, report null instead.

SELECT
        firstName,
        lastName,
        city,
        state
    FROM
        Person
        LEFT JOIN Address
        ON Person.personId = Address.personId
;