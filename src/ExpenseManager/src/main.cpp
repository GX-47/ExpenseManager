#include <iostream>
#include "ExpenseManager.h"
#include "CSVParser.h"

int main() {
    ExpenseManager expenseManager;
    std::string csvFileName = "data/expenses.csv";

    // Load expenses from the CSV file
    expenseManager.loadExpenses(csvFileName);

    while (true) {
        std::cout << "\nExpense Manager Menu:\n";
        std::cout << "1. Create a new expense\n";
        std::cout << "2. Delete an expense\n";
        std::cout << "3. Modify an expense\n";
        std::cout << "4. View expenses\n";
        std::cout << "5. Display total\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        int subchoice;
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

            case 3: {
                // Modify an expense
                int recordID;
                std::cout << "Enter Record ID of the expense to modify: ";
                std::cin >> recordID;
                expenseManager.modifyExpense(recordID);
                break;
            }

            case 4: {
                // View expenses
                std::cout << "\t1. View all expenses\n";
                std::cout << "\t2. View expenses by date\n";
                std::cout << "\t3. View expenses by category\n";
                std::cout << "\t4. View expenses by payment method\n";
                std::cout << "\tEnter your choice: ";
                std::cin >> subchoice;

                switch (subchoice) {
                    case 1: {
                        // View all expenses
                        expenseManager.viewAllExpenses();
                        break;
                    }

                    case 2: {
                        // View expenses by date
                        std::string dateToView;
                        std::cout << "Enter date to view expenses: ";
                        std::cin >> dateToView;
                        expenseManager.viewExpensesByDate(dateToView);
                        break;
                    }

                    case 3: {
                        // View expenses by category
                        std::string categoryToView;
                        std::cout << "Enter category to view expenses: ";
                        std::cin >> categoryToView;
                        expenseManager.viewExpensesByCategory(categoryToView);
                        break;
                    }

                    case 4: {
                        // View expenses by payment method
                        std::string paymentMethodToView;
                        std::cout << "Enter payment method to view expenses: ";
                        std::cin >> paymentMethodToView;
                        expenseManager.viewExpensesByPaymentMethod(paymentMethodToView);
                        break;
                    }

                    default: {
                        std::cout << "Invalid sub-choice. Please select a valid option.\n";
                        break;
                    }
                }
                break;
            }

            case 5: {
                // Display total
                std::cout << "\t1. Display total expenses\n";
                std::cout << "\t2. Display total expenses by date\n";
                std::cout << "\t3. Display total expenses by category\n";
                std::cout << "\t4. Display total expenses by payment method\n";
                std::cout << "Enter your choice: ";
                std::cin >> subchoice;

                switch (subchoice) {
                    case 1: {
                        // Display total expenses
                        expenseManager.displayTotalExpenses();
                        break;
                    }

                    case 2: {
                        // Display total expenses by date
                        std::string dateToDisplay;
                        std::cout << "Enter date to display total expenses: ";
                        std::cin >> dateToDisplay;
                        expenseManager.displayExpensesByDate(dateToDisplay);
                        break;
                    }

                    case 3: {
                        // Display total expenses by category
                        std::string categoryToDisplay;
                        std::cout << "Enter category to display total expenses: ";
                        std::cin >> categoryToDisplay;
                        expenseManager.displayExpensesByCategory(categoryToDisplay);
                        break;
                    }

                    case 4: {
                        // Display total expenses by payment method
                        std::string paymentMethodToDisplay;
                        std::cout << "Enter payment method to display total expenses: ";
                        std::cin >> paymentMethodToDisplay;
                        expenseManager.displayExpensesByPaymentMethod(paymentMethodToDisplay);
                        break;
                    }

                    default: {
                        std::cout << "Invalid sub-choice. Please select a valid option.\n";
                        break;
                    }
                }
                break;
            }

            case 6: {
                // Exit the program
                std::cout << "Exiting Expense Manager. Goodbye!\n";
                return 0;
            }

            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
