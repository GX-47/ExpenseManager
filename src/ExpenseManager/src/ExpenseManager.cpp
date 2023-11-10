#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

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
    // Auto-generate a unique recordID
    int recordID = generateUniqueRecordID();

    std::string date, category, paymentMethod, description;
    double amount;

    // Get input from the user
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

    // Save the expenses to the CSV file after creating a new expense
    saveExpensesToFile("data/expenses.csv");
}

// Function to generate a unique recordID
int ExpenseManager::generateUniqueRecordID() const {
    // Find the maximum existing recordID
    int maxRecordID = 0;
    for (const Expense& expense : expenses) {
        maxRecordID = std::max(maxRecordID, expense.getRecordID());
    }

    // Increment the maximum recordID to generate a unique one
    return maxRecordID + 1;
}

// Modify an expense by record ID
void ExpenseManager::modifyExpense(int recordID) {
    for (auto& expense : expenses) {
        if (expense.getRecordID() == recordID) {
            std::vector<int> chosenFields;

            while (chosenFields.empty()) {
                int choice;
                std::cout << "Select the fields to modify (separated by spaces):\n"
                          << "1. Date\n"
                          << "2. Amount\n"
                          << "3. Category\n"
                          << "4. Payment Method\n"
                          << "5. Description\n"
                          << "Enter your choices (e.g., '1 3 5'): ";

                // Get input from the user
                std::string input;
                std::getline(std::cin, input);
                std::istringstream iss(input);
                int fieldChoice;

                while (iss >> fieldChoice) {
                    chosenFields.push_back(fieldChoice);
                }

                if (chosenFields.empty()) {
                    std::cerr << "Invalid input. Please enter valid choices.\n";
                }
            }

            for (int chosenField : chosenFields) {
                std::string newValue;

                switch (chosenField) {
                    case 1:
                        std::cout << "Enter new date (YYYY-MM-DD): ";
                        std::cin >> newValue;
                        expense.setDate(newValue);
                        break;
                    case 2:
                        std::cout << "Enter new amount: ";
                        std::cin >> newValue;
                        expense.setAmount(std::stod(newValue));
                        break;
                    case 3:
                        std::cout << "Enter new category: ";
                        std::cin >> newValue;
                        expense.setCategory(newValue);
                        break;
                    case 4:
                        std::cout << "Enter new payment method: ";
                        std::cin >> newValue;
                        expense.setPaymentMethod(newValue);
                        break;
                    case 5:
                        std::cout << "Enter new description: ";
                        std::cin.ignore(); // Clear newline character from the buffer
                        std::getline(std::cin, newValue);
                        expense.setDescription(newValue);
                        break;
                    default:
                        std::cerr << "Invalid choice.\n";
                        return;
                }
            }

            saveExpensesToFile("data/expenses.csv"); // Update the CSV file
            std::cout << "Expense modified successfully.\n";
            return;
        }
    }

    std::cerr << "Expense not found with Record ID " << recordID << "\n";
}

// Function to calculate total expenses
double ExpenseManager::calculateTotalExpenses() const {
    double total = 0.0;
    for (const Expense& expense : expenses) {
        total += expense.getAmount();
    }
    return total;
}

// Function to display total expenses
void ExpenseManager::displayTotalExpenses() const {
    double total = calculateTotalExpenses();
    std::cout << "Total Expenses: $" << total << std::endl;
}

// Function to display total expenses by category
void ExpenseManager::displayExpensesByCategory(const std::string& category) const {
    double total = 0.0;
    std::cout << "Expenses in Category '" << category << "':" << std::endl;
    for (const Expense& expense : expenses) {
        if (expense.getCategory() == category) {
            total += expense.getAmount();
        }
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}

// Function to display total expenses by date
void ExpenseManager::displayExpensesByDate(const std::string& date) const {
    double total = 0.0;
    std::cout << "Expenses on Date '" << date << "':" << std::endl;
    for (const Expense& expense : expenses) {
        if (expense.getDate() == date) {
            total += expense.getAmount();
        }
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}

// Function to display total expenses by payment method
void ExpenseManager::displayExpensesByPaymentMethod(const std::string& paymentMethod) const {
    double total = 0.0;
    std::cout << "Expenses with Payment Method '" << paymentMethod << "':" << std::endl;
    for (const Expense& expense : expenses) {
        if (expense.getPaymentMethod() == paymentMethod) {
            total += expense.getAmount();
        }
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}
