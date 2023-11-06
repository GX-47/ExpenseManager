#include "Expense.h"

// Constructor
Expense::Expense(int recordID, const std::string& date, double amount, const std::string& category, const std::string& paymentMethod, const std::string& description)
    : recordID(recordID), date(date), amount(amount), category(category), paymentMethod(paymentMethod), description(description) {
}

// Getters
int Expense::getRecordID() const {
    return recordID;
}

const std::string& Expense::getDate() const {
    return date;
}

double Expense::getAmount() const {
    return amount;
}

const std::string& Expense::getCategory() const {
    return category;
}

const std::string& Expense::getPaymentMethod() const {
    return paymentMethod;
}

const std::string& Expense::getDescription() const {
    return description;
}

// Print the expense details
void Expense::printExpense() const {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Record ID: " << getRecordID() << std::endl;
    std::cout << "Date: " << getDate() << std::endl;
    std::cout << "Amount: " << getAmount() << std::endl;
    std::cout << "Category: " << getCategory() << std::endl;
    std::cout << "Payment Method: " << getPaymentMethod() << std::endl;
    if (!getDescription().empty()) {
        std::cout << "Description: " << getDescription() << std::endl;
    }
}
