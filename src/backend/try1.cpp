#include <iostream>
#include <vector>

class Record {
public:
    int recordID;
    std::string Date;
    std::string Time;
    double Amount;
    std::string Category;
    std::string PaymentMethod;
    std::string Payee;
    std::string Description;
    bool Deleted;

    Record(int id, const std::string& date, const std::string& time, double amount, const std::string& category, const std::string& paymentMethod, const std::string& payee, const std::string& description)
        : recordID(id), Date(date), Time(time), Amount(amount), Category(category), PaymentMethod(paymentMethod), Payee(payee), Description(description), Deleted(false) {}
};

class ExpenseManager {
private:
    std::vector<Record> records;

public:
    // Create a new record and add it to the database
    void CreateRecord(int recordID, const std::string& date, const std::string& time, double amount, const std::string& category, const std::string& paymentMethod, const std::string& payee, const std::string& description) {
        Record newRecord(recordID, date, time, amount, category, paymentMethod, payee, description);
        records.push_back(newRecord);
    }

    // Read all records
    void ReadAllRecords() {
        for (const Record& record : records) {
            if (!record.Deleted) {
                std::cout << "Record ID: " << record.recordID << ", Date: " << record.Date << ", Amount: " << record.Amount << ", Category: " << record.Category << ", Payee: " << record.Payee << std::endl;
            }
        }
    }

    // Update a record by recordID
    bool UpdateRecord(int recordID, double newAmount, const std::string& newCategory, const std::string& newDescription) {
        for (Record& record : records) {
            if (record.recordID == recordID && !record.Deleted) {
                record.Amount = newAmount;
                record.Category = newCategory;
                record.Description = newDescription;
                return true;
            }
        }
        return false; // Record not found
    }

    // Mark a record as deleted
    bool DeleteRecord(int recordID) {
        for (Record& record : records) {
            if (record.recordID == recordID && !record.Deleted) {
                record.Deleted = true;
                return true;
            }
        }
        return false; // Record not found
    }
};

int main() {
    ExpenseManager manager;

    // Create sample records
    manager.CreateRecord(1, "2023-11-01", "10:00", 50.0, "Food", "Credit Card", "Restaurant", "Lunch");
    manager.CreateRecord(2, "2023-11-02", "15:30", 30.0, "Travel", "Cash", "Taxi", "Airport");
    manager.CreateRecord(3, "2023-11-03", "12:45", 25.0, "Entertainment", "GPay", "Cinema", "Movie night");

    // Read all records
    std::cout << "All Records:\n";
    manager.ReadAllRecords();

    // Update a record
    if (manager.UpdateRecord(2, 35.0, "Travel", "Airport Shuttle")) {
        std::cout << "Record 2 updated successfully.\n";
    } else {
        std::cout << "Record 2 not found.\n";
    }

    // Delete a record
    if (manager.DeleteRecord(1)) {
        std::cout << "Record 1 deleted successfully.\n";
    } else {
        std::cout << "Record 1 not found.\n";
    }

    // Read all records after updates and deletions
    std::cout << "All Records (after updates and deletions):\n";
    manager.ReadAllRecords();

    return 0;
}
