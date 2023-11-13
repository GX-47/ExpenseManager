# ExpenseManager
Repository for Expense Manager project for special topic (C++) project

# Basic data about our project

Data is stored in record.csv in the format:
   - recordID (unique)
   - Date
   - Amount
   - Category (for food, travel, entertainment, etc)
   - PaymentMethod (cash, credit card, gpay, etc)
   - Description (string, optional)

Frontend has a specified folder. Done using Qt.

Backend has specified folder. Done using C++. Backend has class record which has these(recordID, Date, Time, Amount, Category, PaymentMethod, Payee, Description, Deleted) fields.

Backend should perform CRUD (Create, Read, Update, Delete) operations:
   - Create
   - Read
     - Read all records
     - Read a specified record using `recordID`
     - Read using specific conditions (like date, category, etc)
   - Update
     - Update the `record.csv`
   - Delete
     - Delete from `record.csv`
