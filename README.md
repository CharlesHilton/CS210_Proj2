# CS210_Proj2

A simple bank account application, that prompts the user for an initial investment, and displays the project return on investment (ROI) over a given period of time.

Can be used with varying streams so that it usage can be be adapted.

I would like to implement the Boost library for better handling of rounding errors.

Some of the more challenging aspects of writing this code were handling user input. I used an admitiedly crude error handling method in BankAccount::SetBankAccount, but for the purposes of this project it sufficed.

Regarding skills that I learned while working on this project that would transferable to other projects, I learned that it is discouraged to use #define to define constants nowadays.

To make this program more maintainable, I used inline definitions for members where appropriate (if they could be defined easily in one line). More complicated members were placed in the appropriate CPP file.
