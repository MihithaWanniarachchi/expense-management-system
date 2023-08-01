# Expense Management System
The Expense Management System is a simple command-line program written in C for managing income and expenses. It allows users to add income and expenses, view details, check the balance, search records, and access settings to change the password or reset the system.

## Features
Add income: Users can add their income by providing the date and amount. The income can be saved to a file for later retrieval.

Add expenses: Users can add their expenses by providing the date, category, and amount. The expenses can be saved to a file for later retrieval.

View details: Users can view the list of all incomes and expenses recorded in the system.

Check balance: The system calculates the total income and total expenses to display the current balance.

Search records: Users can search for income or expenses based on specific dates or categories.

Settings: Users can change the system's password or reset the system, which clears all data.

## Getting Started
To run the Expense Management System, follow these steps:

Ensure you have a C compiler installed on your system.

Clone the repository or download the source code.

Compile the source code using the C compiler. For example:

`gcc -o expense_manager expenseManager.c`

Run the executable:

`./expense_manager`

The program will prompt for a password. The default password is "1234." Enter the correct password to access the main menu.
## Usage
Follow the on-screen instructions to navigate through the different features of the program.

To add income or expenses, provide the required information when prompted.

To view details, check the balance, search records, or change settings, select the respective option from the main menu.

To exit the program, select "n" when asked to return to the main menu.

## File Management
The program stores income data in "incometracker.txt" and expense data in "expensetracker.txt."

The password is saved in "password.txt."

The system allows users to reset the data by clearing the contents of the income and expense files.

## Contributions
Contributions to the Expense Management System are welcome. If you encounter any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License
The Expense Management System is licensed under the MIT License. See the LICENSE file for more details.

## Disclaimer
This program is intended for educational and personal use only. It is not suitable for managing real financial transactions or sensitive data. The authors are not responsible for any misuse or damages caused by the program.