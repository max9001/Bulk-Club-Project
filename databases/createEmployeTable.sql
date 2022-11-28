CREATE TABLE employeeTable (
    employeeID INT NOT NULL PRIMARY KEY,
    employeeName TEXT NOT NULL,
    employeeType TEXT NOT NULL,
    username TEXT NOT NULL,
    FOREIGN KEY (username) REFERENCES userTable(username) 
);


-- 123400, "Homi Bodhanwala", "Administrator", "ProfB"
-- 123456, "Elliot Stern", "Manager", "Pal"
-- 123457, "Rodger Covaks", "Shelf Stocker", "Shelby"

-- Insert into Employee table
INSERT INTO employeeTable (employeeID, employeeName, employeeType, username) 
VALUES (123400, "Homi Bodhanwala", "Administrator", "ProfB"),
         (123456, "Elliot Stern", "Manager", "Pal"),
         (123457, "Rodger Covaks", "Shelf Stocker", "Shelby");