#include "atm.h"

using namespace std;

int main(){
    Bank my_bank;

    //insert card number, pin, checking balance, saving balance
    my_bank.insert_account(1234, 1234, 10, 1);
    my_bank.insert_account(4567, 4567, 1, 101);
    my_bank.insert_account(7890, 7890, 0, 0);

    Atm my_atm(&my_bank);
    my_atm.start();

    return 0;
}
