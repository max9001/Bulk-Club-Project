# How to store data between runs?

### classroom example

- Course
  - #
  - name
  - desc
  - instructor
    - name
    - ...
  - lab instructor
  - department
  - student[]
    - for each student...
      - name
      - id number
      - course grade
  - course grades
    - 2d array...?

### how are these things related to tables
  
- fill primary table
- with references to other tables
- with editing, only one row in one table needs to be added to change entire structure
  - great for 1 to 1 model
  - if dynamic is needed
  - for example, students in a class, number is unknown
    - create new table called course students
    - links studentIDs to courseIDs (many to many relationship)

  - assignment grade
    - table with course
    - student ID

  - **OR**
    - assignment
      - course
      - name
      - desc
      - weight
      - points

    - table assignmennt grades
      - takes in assignment table ids
      - studentID
      - points earned


# query language
  - SQL
  - structured query language
---
  - ex
    ```
    SELECT  students.name, students.idNumber
    FROM    studentsTable, Courses, CourseStudents
    WHERE   courseName = 'CS1B' AND 
            courseID = courseStudents.ID AND 
            courseStudents.studentID = students.studentID
    ```
    
  - other styles
    - MySQL
    - Postgres
    - MS SQL Server
  - Sqlite (everything in one file, can store and fetch using SQL)
    
    
  
