CREATE TABLE inventory(
    itemID INT NOT NULL,
    productName TEXT NOT NULL,
    price INT NOT NULL,
    stock INT NOT NULL,
    sold INT NOT NULL,
    PRIMARY KEY (itemID)
);

-- 1111111, "Steak", 12.49, 0, 100
-- 2222222, "Milk", 20.00, 78, 22

-- Insert into inventory
INSERT INTO inventory (itemID, productName, price, stock, sold)
VALUES (1111111, "Steak", 12.49, 0, 100),
       (2222222, "Milk", 20.00, 78, 22);