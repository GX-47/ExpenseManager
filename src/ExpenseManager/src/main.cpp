#include <iostream>
#include "ExpenseManager.h"
#include "CSVParser.h"

int main() {
    ExpenseManager expenseManager;
    std::string csvFileName = "data/expenses.csv"; // Change this to your CSV file location

    // Load expenses from the CSV file
    expenseManager.loadExpenses(csvFileName);

    while (true) {
        std::cout << "Expense Manager Menu:\n";
        std::cout << "1. Create a new expense\n";
        std::cout << "2. Delete an expense by Record ID\n";
        std::cout << "3. View all expenses\n";
        std::cout << "4. View expenses by date\n";
        std::cout << "5. View expenses by category\n";
        std::cout << "6. View expenses by payment method\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Create a new expense
                expenseManager.createExpenseFromUserInput();
                break;
            }

            case 2: {
                // Delete an expense by Record ID
                int recordIDToDelete;
                std::cout << "Enter Record ID to delete: ";
                std::cin >> recordIDToDelete;
                expenseManager.deleteExpense(recordIDToDelete);
                break;
            }

            case 3:
                // View all expenses
                expenseManager.viewAllExpenses();
                break;

            case 4: {
                // View expenses by date
                std::string dateToView;
                std::cout << "Enter date to view expenses: ";
                std::cin >> dateToView;
                expenseManager.viewExpensesByDate(dateToView);
                break;
            }

            case 5: {
                // View expenses by category
                std::string categoryToView;
                std::cout << "Enter category to view expenses: ";
                std::cin >> categoryToView;
                expenseManager.viewExpensesByCategory(categoryToView);
                break;
            }

            case 6: {
                // View expenses by payment method
                std::string paymentMethodToView;
                std::cout << "Enter payment method to view expenses: ";
                std::cin >> paymentMethodToView;
                expenseManager.viewExpensesByPaymentMethod(paymentMethodToView);
                break;
            }

            case 7:
                // Exit the program
                std::cout << "Exiting Expense Manager. Goodbye!" << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
