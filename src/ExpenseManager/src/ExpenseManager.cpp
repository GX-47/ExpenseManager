#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Load expenses from a CSV file
void ExpenseManager::loadExpenses(const std::string& filename) {
    expenses.clear();  // Clear existing expenses

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open the CSV file for loading expenses." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(iss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() >= 5) {
            int recordID = std::stoi(fields[0]);
            std::string date = fields[1];
            double amount = std::stod(fields[2]);
            std::string category = fields[3];
            std::string paymentMethod = fields[4];
            std::string description = (fields.size() > 5) ? fields[5] : "";

            Expense expense(recordID, date, amount, category, paymentMethod, description);
            expenses.push_back(expense);
        }
    }
    file.close();
}

// Create a new expense
void ExpenseManager::createExpense(const Expense& expense) {
    expenses.push_back(expense);
}

// Delete an expense by record ID
void ExpenseManager::deleteExpense(int recordID) {
    for (auto it = expenses.begin(); it != expenses.end(); ++it) {
        if (it->getRecordID() == recordID) {
            expenses.erase(it);
            saveExpensesToFile("data/expenses.csv"); // Update the CSV file
            break;
        }
    }
}

// View all expenses
void ExpenseManager::viewAllExpenses() const {
    for (const Expense& expense : expenses) {
        expense.printExpense();
        std::cout << std::endl;
    }
}

// View expenses by date
void ExpenseManager::viewExpensesByDate(const std::string& date) const {
    for (const Expense& expense : expenses) {
        if (expense.getDate() == date) {
            expense.printExpense();
            std::cout << std::endl;
        }
    }
}

// View expenses by category
void ExpenseManager::viewExpensesByCategory(const std::string& category) const {
    for (const Expense& expense : expenses) {
        if (expense.getCategory() == category) {
            expense.printExpense();
            std::cout << std::endl;
        }
    }
}

// View expenses by payment method
void ExpenseManager::viewExpensesByPaymentMethod(const std::string& paymentMethod) const {
    for (const Expense& expense : expenses) {
        if (expense.getPaymentMethod() == paymentMethod) {
            expense.printExpense();
            std::cout << std::endl;
        }
    }
}

// Save the expenses to the CSV file
void ExpenseManager::saveExpensesToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open the CSV file for saving expenses." << std::endl;
        return;
    }

    for (const Expense& expense : expenses) {
        // Format the expense into a CSV line and write it to the file
        std::vector<std::string> fields;
        fields.push_back(std::to_string(expense.getRecordID()));
        fields.push_back(expense.getDate());
        fields.push_back(std::to_string(expense.getAmount()));
        fields.push_back(expense.getCategory());
        fields.push_back(expense.getPaymentMethod());
        fields.push_back(expense.getDescription());
        std::string csvLine = CSVParser::formatCSVLine(fields);
        file << csvLine << std::endl;
    }
    file.close();
}

// Function to interactively create a new expense from user input
void ExpenseManager::createExpenseFromUserInput() {
    int recordID;
    std::string date, category, paymentMethod, description;
    double amount;

    // Get input from the user
    std::cout << "Enter Record ID: ";
    std::cin >> recordID;

    std::cout << "Enter Date (YYYY-MM-DD): ";
    std::cin >> date;

    std::cout << "Enter Amount: ";
    std::cin >> amount;

    std::cin.ignore(); // Clear newline character from the buffer

    std::cout << "Enter Category: ";
    std::getline(std::cin, category);

    std::cout << "Enter Payment Method: ";
    std::getline(std::cin, paymentMethod);

    std::cout << "Enter Description (optional): ";
    std::getline(std::cin, description);

    Expense newExpense(recordID, date, amount, category, paymentMethod, description);
    createExpense(newExpense);
}
