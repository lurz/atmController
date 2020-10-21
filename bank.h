#include "account.h"
#include <unordered_map>
#include <vector>

using namespace std;

class Bank{
    private:
        unordered_map<int, Account*> accounts;
        vector<int> card_nums;

    public:
        Bank(){
            
        }

        ~Bank(){
            for(int i = 0; i < card_nums.size(); i++){
                delete accounts[card_nums[i]];
            }
        }

        bool exist_account(int cn){
            return (accounts.find(cn) != accounts.end());
        }

        void insert_account(int cn, int p, int cb, int sb){
            if(accounts.find(cn) != accounts.end()){
                cout << "--ACCOUNT ALREADY EXIST--" << endl;
                exit(EXIT_FAILURE);
            }
            Account* new_account = new Account(cn, p, cb, sb);
            accounts[cn] = new_account;
            card_nums.push_back(cn);
            return;
        }

        int change_balance(int cn, bool is_checking, bool is_deposit, int amount){
            if(accounts.find(cn) == accounts.end()){
                cout << "--ACCOUNT DOESN'T EXIST--" << endl;
                exit(EXIT_FAILURE);
            }
            Account* current = accounts[cn];
            int current_balance = get_balance(cn, is_checking);
            if(!is_deposit && abs(amount) > current_balance){
                return -1;
            }
            int after_change;
            if(is_checking){
                after_change = current->change_checking_balance(is_deposit ? amount : (-1 * amount));
            }else{
                after_change = current->change_saving_balance(is_deposit ? amount : (-1 * amount));
            }
            return after_change;
        }

        int get_balance(int cn, bool is_checking){
            if(accounts.find(cn) == accounts.end()){
                cout << "--ACCOUNT DOESN'T EXIST--" << endl;
                exit(EXIT_FAILURE);
            }
            Account* current = accounts[cn];
            return (is_checking ? current->get_checking_balance() : current->get_saving_balance());
        }

        bool get_access(int cn, int p){
            if(accounts.find(cn) == accounts.end()){
                cout << "--ACCOUNT DOESN'T EXIST--" << endl;
                exit(EXIT_FAILURE);
            }
            Account* current = accounts[cn];
            return (current->get_pin() == p);
        }

};
