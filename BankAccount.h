#include <iostream>
using namespace std;

class BankAccount {
private:
    long double m_initialInvestment = 0.0L; // Initial investment in US Dollars.
    long double m_monthlyDeposit = 0.0L; // Monthly desposit in US Dollars.
    long double m_annualInterestRate = 0.0L; // annualInterest as a decimal (1% = 0.01).
    unsigned long m_investmentDuration = 0UL;  // Duration of investment in months.
    long double m_totalBalance = 0.0L; // Investment total after duration
public:
    // Constructors
    BankAccount(long double inv = 0.0L, long double deposit = 0.0L, long double interest = 0.0L, unsigned long duration = 0L) :
        m_initialInvestment(inv),
        m_monthlyDeposit(deposit),
        m_annualInterestRate(interest),
        m_investmentDuration(duration) {}

    BankAccount(ostream& oSt, istream& iSt);   // Create object using streams.

    // Methods
    void ProjectedComparisonReport(ostream& oSt = cout);                                            // Output two reports. One with the set monthly deposit. The other with no monthly deposit.
    void ProjectedYearEndReport(ostream& oSt = cout, const bool useAccountMonthlyDeposit = true);   // Output a projected report for the account.
    void ProcessReturn();                                                                           // Process return on investment and monthly deposit.

    // Setters
    void SetBankAccount(ostream& oSt, istream& iSt);                                            // Set account using streams.
    void SetInitialInvestment(long double investment) { m_initialInvestment = investment; }
    void SetMonthlyDeposit(long double deposit) { m_monthlyDeposit = deposit; }
    void SetAnnualInterest(long double interest) { m_annualInterestRate = interest; }
    void SetInvestmentDuration(unsigned long duration) { m_investmentDuration = duration; }
    void SetTotalBalance(long double total) { m_totalBalance = total; }

    // Getters
    long double GetInitialInvestment() { return m_initialInvestment; }
    long double GetMonthlyDeposit() { return m_monthlyDeposit; }
    long double GetAnnualInterest() { return m_annualInterestRate; }
    unsigned long GetInvestmentDuration() { return m_investmentDuration; }
    long double GetTotalBalance() { return m_totalBalance; }
};