#include <iostream>
using namespace std;

class record
{
    private:
        int recordID; // Will be auto assigned
        // date
        // time
        double amount; // +ve for income and -ve for expenses
        // category
        // payment method
        char payee[20];
        char description[100];
        int deleted;
    public:
        record();
        ~record();
};

