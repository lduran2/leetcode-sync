# Write your MySQL query statement below

# Table: Patients
# patient_id is the primary key for this table.

# Write an SQL query to report the patient_id, patient_name all
# conditions of patients who have Type I Diabetes. Type I Diabetes
# always starts with DIAB1 prefix

SELECT
        patient_id,
        patient_name,
        conditions
    FROM
        Patients
    WHERE
        # all conditions matching
        #   beginning of string, or space character
        #   string 'DIAB1'
        #   surrounded by anything else
        regexp_like(conditions, '(^| )DIAB1')
;