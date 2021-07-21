#include<iostream>
#include<time.h>
#include <cstdlib>
#define CAPACITY 100
using namespace std;

struct details
{
	int account_number;
	char given_name[20];
	char family_name[20];
	double balance;
};

struct details client [CAPACITY];
double transactions [CAPACITY] [2];
int i = 0, noOfAccounts, acc, tranCounter = 0;
const int MIN = 10000, MAX = 10099;


int readIntegerInterval(int minNum,int maxNum)
{
	int x;
	cin >> x;
	while (cin.fail() || cin.peek() != '\n' || x > maxNum || x < minNum)
	{
		cin.clear();
		cin.ignore(512,'\n');
		cout << "Warning: Please enter only a valid choice" << endl;
		cin >> x;
	}	
	return x;
}



void addAccount(){
	
	acc = 0;
	srand(time(0));
	
	cout << endl << "Enter your first name :";
	cin >> client[i].given_name ;
	cout << endl << "Enter last name :";
	cin >> client[i].family_name;
	
	while(!acc)
	{
		acc = rand();
		acc = (acc % (MAX - MIN + 1)) + MIN;
		for(int j=0;j<i;j++)
		{
			if(client[j].account_number == acc)
			{
				acc = 0;
			}
		}
	}
	
	cout << endl << "Your randomly generated Account Number is : " << acc << endl << endl;
	client[i].account_number = acc;
	
	cout << "enter amount to put in your account : ";
	cin >> client[i].balance;
	
	i=i+1;
	noOfAccounts = noOfAccounts + 1;
	
	cout << endl << "Your account has been created!" << endl << endl;
	
	
	
}

void deleteAccount(){
	int counter = 0;
	cout << endl << "Enter account number to delete :";
	acc = readIntegerInterval(MIN,MAX);
	
	for (int j=0;j<i;j++)
	{
		if (client[j].account_number == acc)
		{
			client[j].account_number = 0;
			cout << endl << "The account has been deleted!";
			noOfAccounts = noOfAccounts - 1;
			counter = 1;
			break;
		}
	}
	if(!counter)
	{
		cout << endl << "Account Does Not Exist!";
	}
}

void displayDetails(){
	
	int counter = 0;
	cout << endl << "Enter account number for details :";
	acc = readIntegerInterval(MIN,MAX);
	
	for (int j=0; j<i; j++)
	{
		if(client[j].account_number == acc)
		{
			cout << endl << "First Name  Last Name  Balance" << endl;
			cout << "----------------------------------" << endl;
			cout << client[j].given_name << "\t\t" << client[j].family_name << "\t $" << client[j].balance << endl;
			cout << "----------------------------------" << endl;
			counter = 1;
			break;
		}
	}
	if(!counter)
	{
		cout << endl << "Account Does Not Exist!";
	}
}

void depositMoney(){
	
	double amount;
	int counter = 0;
	cout << endl << "Enter Account Number :" ;
	acc = readIntegerInterval(MIN,MAX);
	cout << endl << "Enter Amount to deposit : $";
	cin >> amount;
	for (int j=0;j<i;j++)
	{
		if(client[j].account_number == acc)
		{
			client[j].balance = client[j].balance + amount;
			cout << endl << " $" << amount <<" Deposited in Account Number : " << acc;
			cout << endl << "New Balance : $" << client[j].balance;
			counter = 1;
			transactions [tranCounter][0] = acc;
			transactions [tranCounter][1] = amount;
			tranCounter++;
			break;
		}
		
	}
	if(!counter)
	{
		cout << endl << "Account Does Not Exist!";
	}
}

void withdrawMoney(){
	
	int counter;	
	double amount;
	cout << endl << "Enter Account Number :" ;
	acc = readIntegerInterval(MIN,MAX);
	cout << endl << "Enter Amount to withdraw : $";
	cin >> amount;
	for (int j=0;j<i;j++)
	{
		if(client[j].account_number == acc)
		{
			if(client[j].balance < amount)
			{
				cout << endl << "Insufficient Funds in account!";
			}
			else
			{
				client[j].balance = client[j].balance - amount;
				cout << endl << amount <<" withdrawn from Account Number : " << acc;
				cout << endl << "Remaining Balance : $" << client[j].balance;
				transactions [tranCounter][0] = acc;
				transactions [tranCounter][1] = amount * (-1);
				tranCounter++;
				counter = 1;
			}
			break;
		}		
	}	
	if(!counter)
	{
		cout << endl << "Account Does Not Exist!";
	}
}

void clientList(){
	cout << "----------------------------------------------" << endl;
	cout << "First Name  Last Name  Account Number  Balance" << endl;
	for(int j=0;j<i;j++)
	{	if(client[j].account_number != 0)	
		{
			cout << "----------------------------------------------" << endl;
			cout << client[j].given_name << "\t\t" << client[j].family_name << "\t\t" << client[j].account_number << "\t $" << client[j].balance << endl;
			cout << "----------------------------------------------" << endl;
		}
	}
	cout << endl << endl;
}

void averageBalance(){
	double avg = 0;
	for (int j=0; j<i; j++)
	{
		if(client[j].account_number != 0)
		{
			avg = avg + client[j].balance;
		}
	}
	avg =  avg/noOfAccounts;
	cout << endl << "Average Balance in ISI Bank Accounts is : $" << avg;
}

void totalBalance(){
	double total = 0;
	for (int j=0; j<i; j++)
	{
		if(client[j].account_number != 0)
		{
			total = total + client[j].balance;
		}
	}
	cout << endl << "Total Balance in ISI Bank Accounts is : $" << total;
}

void transactionHistory()
{
	int counter = 0 ;
	cout << endl << "Enter Account Number :" ;
	acc = readIntegerInterval(MIN,MAX);
	for (int j=0; j<tranCounter; j++)
	{
		if(transactions[j][0] == acc)
		{
			if(transactions[j][1] > 0)
			{
				cout << endl << transactions[j][1] << " deposited in account";
			}
			else
			{
				cout << endl << (transactions[j][1])*(-1) << " withdrawn from account";
			}
			counter  = 1;
		}
	}
	if(!counter)
	{
		cout << endl << "Account Does Not Exist!";
	}
}
