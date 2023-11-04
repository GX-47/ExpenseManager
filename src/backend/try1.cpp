#include <iostream>
#include <vector>
using namespace std;

class Record {
public:
    int recordID;
    string Date;
    string Time;
    double Amount;
    string Category;
    string PaymentMethod;
    string Payee;
    string Description;
    bool Deleted;

    Record(int id, const string& date, const string& time, double amount, const string& category, const string& paymentMethod, const string& payee, const string& description)
        : recordID(id), Date(date), Time(time), Amount(amount), Category(category), PaymentMethod(paymentMethod), Payee(payee), Description(description), Deleted(false) {}
};

class ExpenseManager {
private:
    vector<Record> records;

public:
    // Create a new record and add it to the database
    void CreateRecord(int recordID, const string& date, const string& time, double amount, const string& category, const string& paymentMethod, const string& payee, const string& description) {
        Record newRecord(recordID, date, time, amount, category, paymentMethod, payee, description);
        records.push_back(newRecord);
    }

    // Read all records
    void ReadAllRecords() {
        for (const Record& record : records) {
            if (!record.Deleted) {
                cout << "Record ID: " << record.recordID << ", Date: " << record.Date << ", Amount: " << record.Amount << ", Category: " << record.Category << ", Payee: " << record.Payee << endl;
            }
        }
    }

    // Update a record by recordID
    bool UpdateRecord(int recordID, double newAmount, const string& newCategory, const string& newDescription) {
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
    cout << "All Records:\n";
    manager.ReadAllRecords();

    // Update a record
    if (manager.UpdateRecord(2, 35.0, "Travel", "Airport Shuttle")) {
        cout << "Record 2 updated successfully.\n";
    } else {
        cout << "Record 2 not found.\n";
    }

    // Delete a record
    if (manager.DeleteRecord(1)) {
        cout << "Record 1 deleted successfully.\n";
    } else {
        cout << "Record 1 not found.\n";
    }

    // Read all records after updates and deletions
    cout << "All Records (after updates and deletions):\n";
    manager.ReadAllRecords();

    return 0;
}
