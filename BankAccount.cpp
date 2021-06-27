#include <iostream>
#include <iomanip>
#include "BankAccount.h"

using namespace std;

const unsigned int MONTHS_IN_YEAR = 12U;

// Constructors
BankAccount::BankAccount(ostream& oSt, istream& iSt) {   // Create object using streams.
    SetBankAccount(oSt, iSt);
}

// Methods
void BankAccount::ProjectedComparisonReport(ostream& oSt) { // Outputs 2 reports...
    ProjectedYearEndReport(oSt, true);   // Year End Report using set monthly deposit.
    ProjectedYearEndReport(oSt, false);  // Year End Report using $0 monthly deposit.
}

void BankAccount::ProjectedYearEndReport(ostream& oSt, const bool useAccountMonthlyDeposit) {  // Display report for year by year potential return.
    long double deposit = useAccountMonthlyDeposit ? m_monthlyDeposit : 0.0L;
    long double monthlyEarnedInterest = 0.0L;
    long double yearlyInterestEarned = 0.0L;
    long double totalBalance = m_initialInvestment;

    oSt << endl << "Year End Report (Using $" << fixed << setprecision(2) << deposit << " as monthly desposit)" << endl;    // Output report header.
    oSt.width(68); oSt.fill('-'); oSt << "" << endl;
    oSt.fill(' ');
    oSt << left << setw(8) << "Year";                                                                                       // Table Header.
    oSt.width(30); oSt << right << "Year End Balance" << setw(30) << "Interest Earned" << endl;                             // Table Header Continued.
    for (unsigned long i = 1; i <= m_investmentDuration; i++) {                                                             // Process interest and accruals for each month...
        monthlyEarnedInterest = (totalBalance + deposit) * (m_annualInterestRate / MONTHS_IN_YEAR);                                   
        yearlyInterestEarned += monthlyEarnedInterest;
        totalBalance += deposit + monthlyEarnedInterest;
        if (i % MONTHS_IN_YEAR == 0) {
            oSt.fill(' ');
            oSt << fixed << left << setw(8) << (i / MONTHS_IN_YEAR) << right << setw(30) << setprecision(2) << totalBalance << setw(30) << yearlyInterestEarned << endl;    
            yearlyInterestEarned = 0.0L;
        }
    }
}
void BankAccount::ProcessReturn() { // Process return for setup account.
    long double monthlyEarnedInterest = 0.0L;

    for (unsigned long i = 1; i <= m_investmentDuration; i++) { // Process interest and accruals for each month...
        monthlyEarnedInterest = (m_totalBalance + m_monthlyDeposit) * (m_annualInterestRate / MONTHS_IN_YEAR);
        m_totalBalance += m_monthlyDeposit + monthlyEarnedInterest;
    }
}
// Setters
void BankAccount::SetBankAccount(ostream& oSt, istream& iSt) {
    unsigned long years = 0UL;
    long double interest = 0.0L;
    string errorString;

    oSt << endl << "Hello! Please setup your account." << endl;
    oSt.width(60);  oSt.fill('-');  oSt << "" << endl;
    while (true) {
        oSt << "Initial Investment (USD): ";    iSt >> m_initialInvestment;
        oSt << "Monthly Deposit (USD): ";       iSt >> m_monthlyDeposit;
        oSt << "Annual Interest (%): ";         iSt >> interest;                SetAnnualInterest(interest / 100.0L);
        oSt << "Number of Years: ";             iSt >> years;                   SetInvestmentDuration(years * MONTHS_IN_YEAR);
        if (iSt.fail()) {
            iSt.clear();
            iSt.ignore();
            oSt << endl << endl << "Please enter a valid number." << endl << endl;
            continue;
        }
        break;
    }

    SetTotalBalance(GetInitialInvestment());
    oSt << "Account Balance: " << GetTotalBalance() << endl;
}

