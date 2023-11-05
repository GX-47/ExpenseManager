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
        double Amount;
        std::string Category;
        std::string PaymentMethod;
        std::string Payee;
        std::string Description;

        Record(int id, const std::string& date, double amount, const std::string& category, const std::string& paymentMethod, const std::string& payee, const std::string& description)
            : recordID(id), Date(date), Amount(amount), Category(category), PaymentMethod(paymentMethod), Payee(payee), Description(description) { }

        void display() const
        {
            std::cout << "Record ID: " << recordID << std::endl;
            std::cout << "Date: " << Date << std::endl;
            std::cout << "Amount: " << Amount << std::endl;
            std::cout << "Category: " << Category << std::endl;
            std::cout << "Payment Method: " << PaymentMethod << std::endl;
            std::cout << "Payee: " << Payee << std::endl;
            std::cout << "Description: " << Description << std::endl;
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

                if (tokens.size() == 7)
                {
                    int recordID = std::stoi(tokens[0]);
                    std::string Date = tokens[1];
                    double Amount = std::stod(tokens[2]);
                    std::string Category = tokens[3];
                    std::string PaymentMethod = tokens[4];
                    std::string Payee = tokens[5];
                    std::string Description = tokens[6];

                    Record record(recordID, Date, Amount, Category, PaymentMethod, Payee, Description);
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

        void insertRecord(int recordID, const std::string& Date, double Amount, const std::string& Category, const std::string& PaymentMethod, const std::string& Payee, const std::string& Description)
        {
            Record record(recordID, Date, Amount, Category, PaymentMethod, Payee, Description);
            records.push_back(record);

            std::ofstream file("record.csv", std::ios::app); // Open file in append mode
            file << recordID << "," << Date << "," << Amount << "," << Category << "," << PaymentMethod << "," << Payee << ",\"" << Description << "\"\n";
        }

        void insert1Record()
        {
            int recordID;
            std::string Date;
            double Amount;
            std::string Category;
            std::string PaymentMethod;
            std::string Payee;
            std::string Description;

            std::cout << "Enter Record ID: ";
            std::cin >> recordID;
            std::cout << "Enter Date: ";
            std::cin >> Date;
            std::cout << "Enter Amount: ";
            std::cin >> Amount;
            std::cout << "Enter Category: ";
            std::cin >> Category;
            std::cout << "Enter Payment Method: ";
            std::cin >> PaymentMethod;
            std::cout << "Enter Payee: ";
            std::cin >> Payee;
            std::cin.ignore();
            std::cout << "Enter Description: ";
            std::getline(std::cin, Description);

            insertRecord(recordID, Date, Amount, Category, PaymentMethod, Payee, Description);
        }


};

int main()
{
    RecordBook r1("record.csv");
    r1.displayRecords();
    r1.insert1Record();

    return 0;
}
