// Description: CS-210 Project 

// Author:  Charles Hilton
//          Charles.Hilton@gmail.com
//          Charles.Hilton@snhu.edu
// Date:    2021/06/07 04:14 EDT

#include <iostream>
#include <iomanip>

#include "BankAccount.h"
using namespace std;

void BankApp() {
    cout << "Welcome to Airgead Banking System" << endl;
    BankAccount userAccount(cout, cin);                                             // Create Bank Account.
    userAccount.ProjectedComparisonReport(cout);                                    // Output report for account.
    userAccount.ProcessReturn();                                                    
    cout << endl << "Account Balance: " << userAccount.GetTotalBalance() << endl;
    cout << endl << "Goodbye!" << endl;
}

int main() {
    BankApp();  // Launch Bank Application.
}
