// Module 8: Bank Account Simulation 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.00;
    }

    void deposit(double cash) {
        balance += cash;
cout << "Cash Before Spending was " << balance << endl;
        saveTransaction("Deposit", cash);
    }

    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
        } else {
            balance -= cost;
    	cout << "Purchased: " << item << " " << cost << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() {
        cout << "\nCurrent amount: $" << balance << endl;
    }

    void saveTransaction(string type, double cash) {
        ofstream file("transactions.txt", ios::app); //each action (deposit and purchase) is written to transaction.txt  
        if (file.is_open()) {
            file << type << ": $" << cash << endl;
            file.close();
        }
    }
};


int main() {
    
    BankAccount myAccount; //BankAccount object
    cout << "________________Bank Balance History________________ \n"; 
    
    cout << "\n" << endl;
    myAccount.deposit(793.21);
	cout << "\n" << endl;
	
    myAccount.makePurchase("Toy Truck", 9.99);
    myAccount.makePurchase("Fish Food", 15.00);
    myAccount.makePurchase("Lighter", 0.90);
    myAccount.makePurchase("Mittens", 12.50);

    myAccount.displayBalance(); //Prints final balance.
    
    return 0;
}




