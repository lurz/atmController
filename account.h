#include <iostream>

using namespace std;

class Account{
    private:
        int card_number;
        int pin;
        int checking_balance;
        int saving_balance;

    public:
        Account(int cnum, int p, int cb, int sb){
            cout << "--SETTING UP ACCOUNT FOR CARD " << cnum << "--" << endl;
            card_number = cnum;
            pin = p;
            checking_balance = cb;
            saving_balance = sb;
        }

        int get_pin(){
            return pin;
        }

        int get_checking_balance(){
            return checking_balance;
        }

        int get_saving_balance(){
            return saving_balance;
        }

        int change_checking_balance(int c_amount){
            checking_balance += c_amount;
            return checking_balance;
        }

        int change_saving_balance(int s_amount){
            saving_balance += s_amount;
            return saving_balance;
        }
};
