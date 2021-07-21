#include<iostream>
#include "C:\Users\admin\Desktop\ISI\course2\BankManagement.h"
using namespace std;

int readIntegerInterval(int minNum,int maxNum);
void addAccount();
void deleteAccount();
void displayDetails();
void depositMoney();
void withdrawMoney();
void clientList();
void averageBalance();
void totalBalance();
void transactionHistory();

int main()
{
	bool exit = 0;
	int choice;
	while(!exit)
	{
		cout << endl << endl << "----------------------------ISI BANK------------------------------" << endl << endl << endl;
		cout << "Welcome to ISI BANK, Please select one of the following options by" << endl << "entering the number of the option:" << endl << endl;
		cout << " 1. Add a Bank Account" << endl;
		cout << " 2. Remove a Bank Account" << endl;
		cout << " 3. Display the information of Bank Account" << endl;
		cout << " 4. Deposit Money" << endl;	
		cout << " 5. Withdraw Money" << endl;
		cout << " 6. Display List of Clients" << endl;
		cout << " 7. Display the average balance of all accounts" << endl;
		cout << " 8. Display the total balance value of the accounts" << endl;
		cout << " 9. Display Transaction history for an account" << endl;
		cout << " 10. Exit the application" << endl << endl;
		cout << endl << "Enter Your Choice : ";
		choice = readIntegerInterval(1,10);
		
		switch(choice)
		{
			case 1:
				addAccount();
				break;
			case 2:
				deleteAccount();
				break;
			case 3:
				displayDetails();
				break;
			case 4:
				depositMoney();
				break;
			case 5:
				withdrawMoney();
				break;
			case 6:
				clientList();
				break;
			case 7:
				averageBalance();
				break;
			case 8:
				totalBalance();
				break;
			case 9:
				transactionHistory();
				break;
			case 10:
				exit = 1;
				break;
			default:
				cout << "Enter only a valid choice" <<	endl;
				break;		
		}
	}
	return 0;
}

