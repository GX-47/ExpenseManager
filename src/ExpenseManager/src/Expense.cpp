#include "Expense.h"
#include <iostream>

// Constructor
Expense::Expense(int recordID, const std::string& date, double amount, const std::string& category, const std::string& paymentMethod, const std::string& description)
    : recordID(recordID), date(date), amount(amount), category(category), paymentMethod(paymentMethod), description(description) {}

// Getter methods
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

// Setter methods
void Expense::setRecordID(int recordID) {
    this->recordID = recordID;
}

void Expense::setDate(const std::string& date) {
    this->date = date;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
}

void Expense::setCategory(const std::string& category) {
    this->category = category;
}

void Expense::setPaymentMethod(const std::string& paymentMethod) {
    this->paymentMethod = paymentMethod;
}

void Expense::setDescription(const std::string& description) {
    this->description = description;
}

// Print the expense details
void Expense::printExpense() const {
    std::cout << "Record ID: " << recordID << "\n"
              << "Date: " << date << "\n"
              << "Amount: " << amount << "\n"
              << "Category: " << category << "\n"
              << "Payment Method: " << paymentMethod << "\n"
              << "Description: " << description << "\n";
}
