#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
public:
    // Constructor
    Expense(int recordID, const std::string& date, double amount, const std::string& category, const std::string& paymentMethod, const std::string& description = "");

    // Getter methods
    int getRecordID() const;
    const std::string& getDate() const;
    double getAmount() const;
    const std::string& getCategory() const;
    const std::string& getPaymentMethod() const;
    const std::string& getDescription() const;

    // Setter methods
    void setRecordID(int recordID);
    void setDate(const std::string& date);
    void setAmount(double amount);
    void setCategory(const std::string& category);
    void setPaymentMethod(const std::string& paymentMethod);
    void setDescription(const std::string& description);

    // Print the expense details
    void printExpense() const;

private:
    int recordID;
    std::string date;
    double amount;
    std::string category;
    std::string paymentMethod;
    std::string description;
};

#endif
