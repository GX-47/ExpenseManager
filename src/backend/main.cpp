#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>



class Record
{
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

        Record(int id, const std::string& date, const std::string& time, double amount, const std::string& category, const std::string& paymentMethod, const std::string& payee, const std::string& description, bool deleted)
            : recordID(id), Date(date), Time(time), Amount(amount), Category(category), PaymentMethod(paymentMethod), Payee(payee), Description(description), Deleted(deleted) {
        }

        void display() const
        {
            std::cout << "Record ID: " << recordID << std::endl;
            std::cout << "Date: " << Date << std::endl;
            std::cout << "Time: " << Time << std::endl;
            std::cout << "Amount: " << Amount << std::endl;
            std::cout << "Category: " << Category << std::endl;
            std::cout << "Payment Method: " << PaymentMethod << std::endl;
            std::cout << "Payee: " << Payee << std::endl;
            std::cout << "Description: " << Description << std::endl;
            std::cout << "Deleted: " << (Deleted ? "Yes" : "No") << std::endl;
        }


};

class RecordBook
{
    private:
        std::vector<Record> records;

    public:
        RecordBook(const std::string& filename)
        {
            std::ifstream file(filename);
            if (!file)
            {
                std::cerr << "Error: Could not open the file." << std::endl;
                return;
            }

            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string token;
                std::vector<std::string> tokens;

                while (std::getline(iss, token, ','))
                {
                    tokens.push_back(token);
                }

                if (tokens.size() == 9)
                {
                    int recordID = std::stoi(tokens[0]);
                    std::string Date = tokens[1];
                    std::string Time = tokens[2];
                    double Amount = std::stod(tokens[3]);
                    std::string Category = tokens[4];
                    std::string PaymentMethod = tokens[5];
                    std::string Payee = tokens[6];
                    std::string Description = tokens[7];
                    bool Deleted = (tokens[8] == "1");

                    Record record(recordID, Date, Time, Amount, Category, PaymentMethod, Payee, Description, Deleted);
                    records.push_back(record);
                } 
                else
                {
                    std::cerr << "Error: Invalid record format in the CSV file." << std::endl;
                }
            }
        }

        void displayRecords()
        {
            for (const Record& record : records)
            {
                record.display();
                std::cout << "-----------------------------\n";
            }
        }

        void insertRecord()
        {
            // Create insertRecords function that takes user input, adds to recordbook object and updates the file
        }
};

int main()
{
    RecordBook r1("record.csv");
    r1.displayRecords();
    r1.insertRecord();

    return 0;
}
