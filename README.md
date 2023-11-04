# ExpenseManager
Repository for Expense Manager project for special topic(C++) project

# Basic data about our project

Data is stored in record.csv in format :
    recordID(unique)
    Date
    Time
    Amount(+ve for income, -ve for expense)
    Category(for food, travel, entertainment, etc)
    PaymentMethod(cash, credit card, gpay, etc)
    Payee(string, optional)
    Description(string, optional)
    Deleted(will explain)(make it true if record is deleted)

Frontend has specified folder. Done using Qt.

Backend has specified folder. Done using C++.
Backend has class record which has these(recordID, Date, Time, Amount, Category, PaymentMethod, Payee, Description, Deleted) fields.
Backend should perform CRUD(Create, Read, Update, Delete) operations :
    Create - Create a record object and write it to record.csv
    Read - Read all records
         - Read a specified record using recordID
         - Read using specific conditions(like date, category, etc)
    Update - Update the record.csv
    Delete - Delete from record.csv