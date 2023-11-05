#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Record
{
    public:
        Record(int recordID, const std::string& date, double amount, const std::string& category, const std::string& paymentMethod, const std::string& payee = "", const std::string& description = "")
            : recordID(recordID), date(date), amount(amount), category(category), paymentMethod(paymentMethod), payee(payee), description(description) {}

        int getRecordID() const
        {
            return recordID;
        }

        std::string getDate() const
        {
            return date;
        }

        double getAmount() const
        {
            return amount;
        }

        std::string getCategory() const
        {
            return category;
        }

        std::string getPaymentMethod() const
        {
            return paymentMethod;
        }

        std::string getPayee() const
        {
            return payee;
        }

        std::string getDescription() const
        {
            return description;
        }

    private:
        int recordID;
        std::string date;
        double amount;
        std::string category;
        std::string paymentMethod;
        std::string payee;
        std::string description;
};

class RecordBook
{
    public:
        RecordBook()
        {
            loadRecords("record.csv");
        }

        void createRecord(const Record& record)
        {
            recordIDCounter++;
            records.push_back(record);
            saveRecords("record.csv");
        }

        void deleteRecord(int recordID)
        {
            records.erase(std::remove_if(records.begin(), records.end(), [recordID](const Record& record) { return record.getRecordID() == recordID; }), records.end());
            saveRecords("record.csv");
        }

        void modifyRecord(int recordID, const Record& newRecord)
        {
            for (Record& record : records)
            {
                if (record.getRecordID() == recordID)
                {
                    record = newRecord;
                    saveRecords("record.csv");
                    return;
                }
            }
            std::cout << "Record not found." << std::endl;
        }

        void viewAllRecords()
        {
            for (const Record& record : records)
            {
                displayRecord(record);
            }
        }

        void viewRecordsByCategory(const std::string& category)
        {
            for (const Record& record : records)
            {
                if (record.getCategory() == category)
                {
                    displayRecord(record);
                }
            }
        }

        void viewRecordsByPaymentMethod(const std::string& paymentMethod)
        {
            for (const Record& record : records)
            {
                if (record.getPaymentMethod() == paymentMethod)
                {
                    displayRecord(record);
                }
            }
        }

        void viewRecordsByDate(const std::string& date)
        {
            for (const Record& record : records)
            {
                if (record.getDate() == date)
                {
                    displayRecord(record);
                }
            }
        }

        void createNewRecord()
        {
            int recordID;
            std::string date, category, paymentMethod, payee, description;
            double amount;

            std::cout << "Enter Date: ";
            std::cin >> date;
            std::cout << "Enter Amount: ";
            std::cin >> amount;
            std::cout << "Enter Category: ";
            std::cin >> category;
            std::cout << "Enter Payment Method: ";
            std::cin >> paymentMethod;
            std::cout << "Enter Payee (optional): ";
            std::cin >> payee;
            std::cout << "Enter Description (optional): ";
            std::cin >> description;

            Record newRecord(++recordIDCounter, date, amount, category, paymentMethod, payee, description);
            createRecord(newRecord);
        }

        void deleteRecord()
        {
            int recordID;
            std::cout << "Enter Record ID to delete: ";
            std::cin >> recordID;
            deleteRecord(recordID);
        }

        void modifyRecord()
        {
            int recordID;
            std::cout << "Enter Record ID to modify: ";
            std::cin >> recordID;

            for (Record& record : records)
            {
                if (record.getRecordID() == recordID)
                {
                    std::string date, category, paymentMethod, payee, description;
                    double amount;

                    std::cout << "Enter New Date: ";
                    std::cin >> date;
                    std::cout << "Enter New Amount: ";
                    std::cin >> amount;
                    std::cout << "Enter New Category: ";
                    std::cin >> category;
                    std::cout << "Enter New Payment Method: ";
                    std::cin >> paymentMethod;
                    std::cout << "Enter New Payee (optional): ";
                    std::cin >> payee;
                    std::cout << "Enter New Description (optional): ";
                    std::cin >> description;

                    Record newRecord(recordID, date, amount, category, paymentMethod, payee, description);
                    modifyRecord(recordID, newRecord);
                    return;
                }
            }
            std::cout << "Record not found." << std::endl;
        }

        void viewRecordsByCategory()
        {
            std::string category;
            std::cout << "Enter Category to view records: ";
            std::cin >> category;
            viewRecordsByCategory(category);
        }

        void viewRecordsByPaymentMethod()
        {
            std::string paymentMethod;
            std::cout << "Enter Payment Method to view records: ";
            std::cin >> paymentMethod;
            viewRecordsByPaymentMethod(paymentMethod);
        }

        void viewRecordsByDate()
        {
            std::string date;
            std::cout << "Enter Date to view records: ";
            std::cin >> date;
            viewRecordsByDate(date);
        }

    private:
        std::vector<Record> records;
        int recordIDCounter = 0;

        void displayRecord(const Record& record)
        {
            std::cout << "Record ID: " << record.getRecordID() << "\n";
            std::cout << "Date: " << record.getDate() << "\n";
            std::cout << "Amount: " << record.getAmount() << "\n";
            std::cout << "Category: " << record.getCategory() << "\n";
            std::cout << "Payment Method: " << record.getPaymentMethod() << "\n";
            std::cout << "Payee: " << record.getPayee() << "\n";
            std::cout << "Description: " << record.getDescription() << "\n\n";
        }

        void saveRecords(const std::string& filename)
        {
            std::ofstream file(filename);
            for (const Record& record : records)
            {
                file << record.getRecordID() << "," << record.getDate() << "," << record.getAmount() << ","
                    << record.getCategory() << "," << record.getPaymentMethod() << "," << record.getPayee() << ","
                    << record.getDescription() << "\n";
            }
        }

        void loadRecords(const std::string& filename)
        {
            std::ifstream file(filename);
            if (!file.is_open())
            {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
                return;
            }

            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                int recordID;
                std::string date, category, paymentMethod, payee, description;
                double amount;

                if (iss >> recordID >> date >> amount >> category >> paymentMethod >> payee >> description)
                {
                    Record record(recordID, date, amount, category, paymentMethod, payee, description);
                    records.push_back(record);
                    if (recordID > recordIDCounter)
                    {
                        recordIDCounter = recordID;
                    }
                }
            }
        }
};



int main()
{
    RecordBook recordBook;
    int choice;

    do
    {
        std::cout << "\n\n\nExpense Manager\n";
        std::cout << "1. Create New Record\n";
        std::cout << "2. Delete Record\n";
        std::cout << "3. Modify Record\n";
        std::cout << "4. View All Records\n";
        std::cout << "5. View Records by Category\n";
        std::cout << "6. View Records by Payment Method\n";
        std::cout << "7. View Records by Date\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                recordBook.createNewRecord();
                break;
            case 2:
                recordBook.deleteRecord();
                break;
            case 3:
                recordBook.modifyRecord();
                break;
            case 4:
                recordBook.viewAllRecords();
                break;
            case 5:
                recordBook.viewRecordsByCategory();
                break;
            case 6:
                recordBook.viewRecordsByPaymentMethod();
                break;
            case 7:
                recordBook.viewRecordsByDate();
                break;
            case 8:
                // Exit
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

