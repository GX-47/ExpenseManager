#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <iostream>

class Expense {
private:
    int recordID;
    std::string date;
    double amount;
    std::string category;
    std::string paymentMethod;
    std::string description;

public:
    // Constructor
    Expense(int recordID, const std::string& date, double amount, const std::string& category, const std::string& paymentMethod, const std::string& description = "");

    // Accessors (getters)
    int getRecordID() const;
    const std::string& getDate() const;
    double getAmount() const;
    const std::string& getCategory() const;
    const std::string& getPaymentMethod() const;
    const std::string& getDescription() const;

    // Print the expense details
    void printExpense() const;
};

#endif
