#include <iostream>
using namespace std;

class record
{
    /* recordID, Date, Time, Amount, Category, PaymentMethod, Payee, Description, Deleted */
    private:
        int recordID;
        // date
        // time
        double amount;
        // category
        // payment method
        char payee[20];
        char description[100];
        int deleted;
    public:
        record(/* args */);
        ~record();
};
