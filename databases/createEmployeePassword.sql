CREATE TABLE employeePassword (
    username INT NOT NULL,
    password TEXT NOT NULL,
    PRIMARY KEY (username),
    FOREIGN KEY (username) REFERENCES employeeTable(username)
);

-- "ProfB", "password123"
-- "Pal", "Palword456"
-- "Shelby", "1234asdfghjkl"

-- Insert into employeePassword
INSERT INTO employeePassword (username, password)
VALUES ("ProfB", "password123"),
         ("Pal", "Palword456"),
         ("Shelby", "1234asdfghjkl");