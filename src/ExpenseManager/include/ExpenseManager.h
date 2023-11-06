#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <string>
#include "Expense.h"
#include "CSVParser.h"

class ExpenseManager {
public:
    // Load expenses from a CSV file
    void loadExpenses(const std::string& filename);

    // Function to interactively create a new expense from user input
    void createExpenseFromUserInput();

    // Delete an expense by record ID
    void deleteExpense(int recordID);

    // View all expenses
    void viewAllExpenses() const;

    // View expenses by date
    void viewExpensesByDate(const std::string& date) const;

    // View expenses by category
    void viewExpensesByCategory(const std::string& category) const;

    // View expenses by payment method
    void viewExpensesByPaymentMethod(const std::string& paymentMethod) const;


private:
    std::vector<Expense> expenses;

    // Save the expenses to the CSV file
    void saveExpensesToFile(const std::string& filename);

    // Create a new expense
    void createExpense(const Expense& expense);
};

#endif
