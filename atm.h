#include <iostream>
#include "bank.h"

using namespace std;

class Atm{
    private:
        int atm_balance;
        int current_card;
        bool is_checking;
        Bank* current_bank;
    
    public:
        Atm(Bank* b){
            cout << "--WELCOME TO BEAR BANK--" << endl;
            cout << "--PLEASE INSERT CARD--" << endl;
            atm_balance = 100;
            current_bank = b;
        }

        bool insert_card(int cn){
            cout << "Reading..." << endl;
            if(current_bank->exist_account(cn)){
                current_card = cn;
                cout << "--WELCOME CARD " << current_card << " HOLDER--" << endl;
                int pin;
                cout << "#Enter PIN: ";
                cin >> pin;
                if(current_bank->get_access(current_card, pin))
                    return true;
                else{
                    cout << "Wrong pin. Exiting..." << endl;
                    return false;
                }
            }else{
                cout << "--CARD NOT VALID--" << endl;
                cout << "Exiting..." << endl;
                return false;
            }
        }

        void start(){
            int cn;
            cout << "#Enter card num: ";
            cin >> cn;
            if(insert_card(cn)){
                cout << "#Select 0.Saving; 1.Checking: ";
                cin >> is_checking;
                cout << "--ENTER " << (is_checking ? "CHECKING" : "SAVING") << " ACCOUNT--" << endl;
                while(true){
                    int selection;
                    cout << "#Select 0.Balance; 1.Deposit; 2.Withdraw; 3.Exit: ";
                    cin >> selection;
                    if(selection < 0 || selection >= 3){
                        break;
                    }else if(selection == 0){
                        cout << "--YOUR ACCOUNT BALANCE: " << current_bank->get_balance(current_card, is_checking) << "--" << endl;
                    }else if(selection == 1){
                        int deposit;
                        cout << "#Enter deposit amount: ";
                        cin >> deposit;
                        if(deposit <= 0){
                            continue;
                        }
                        atm_balance += deposit;
                        cout << "--YOUR NEW ACCOUNT BALANCE: " << current_bank->change_balance(current_card, is_checking, true, deposit) << "--" << endl;
                    }else if(selection == 2){
                        int withdraw;
                        cout << "#Enter withdraw amount: ";
                        cin >> withdraw;
                        if(withdraw <= 0 || withdraw > atm_balance){
                            cout << "--WITHDRAW NOT VALID--" << endl;
                            continue;
                        }
                        int after = current_bank->change_balance(current_card, is_checking, false, withdraw);
                        if(after < 0){
                            cout << "--WITHDRAW NOT VALID--" << endl;
                            continue;
                        }
                        atm_balance -= withdraw;
                        cout << "--YOUR NEW ACCOUNT BALANCE: " << after << "--" << endl;
                    }
                }
            }else{
                return;
            }
        }

};
