# Bank_Management_C++
An interactive Banking System using C++ and GUI in C++. Includes features like Login, create/edit accounts, Transact, Display accuont

Introduction
This Bank Management System is designed to overcome the entire problem which we are facing currently, and to make complete atomization of manual system to computerized system. Since the current banking system is implemented in Manual, so the response is very slow. The Bank Management System eliminates this limitation of the existing software.  It has the following objectives:

Enhancement:
The main objective of Bank Management System is to enhance and upgrade the existing system by increasing its efficiency and effectiveness. The software improves the working methods by replacing the existing manual system with the computer-based system.

Automation:
The Bank Management System automates each and every activity of the manual system and increases its throughput. Thus the response time of the system is very less and it works very fast.

Accuracy:
The Bank Management System provides the uses a quick response with very accurate information regarding the users etc. Any details or system in an accurate manner, as and when required.

User-Friendly:
The software Bank Management System has a very user-friendly interface. Thus the users will feel very easy to work on it. The software provides accuracy along with a pleasant interface.
 
Maintenance Cost:

The Bank Management System reduces the cost of maintenance.

System Description
Bank Management System is used to maintain the records/information regarding bank accounts of the customers who create accounts in the T n M bank.
The project implements a complete banking procedure. T n M Bank makes some computerized facilities in the bank to implement customer records and their daily transaction records.
Here the main users of the system are the staff members of the T n M bank.  The Operating personnel of the bank can open a new account for the customers, can modify their existing account, and also, view all the accounts maintained in the bank. 

 
Requirement Analysis

The requirement of our system is to be able to store the information about the user’s account and to do the required transactions.
SOFTWARE REQUIREMENTS:
 	Turbo C++

The services provided by the system will be : -
•	Open new Account
•	List of all accounts
•	Deposit
•	Withdrawal
•	See particular account
•	Edit account details

Open New Account
Users can open a new account in the T n M bank. They have to      provide information such as name, address, initial deposit. The account number will be allocated automatically.
    Deposit and Withdrawal
Here, the user can deposit or withdraw money to/from their account. The account balance will be modified accordingly. 

List of all accounts
In this option, the staff member can check the list of all the accounts in the bank. He can also check the details of all the accounts such as name of the account holder, his address, and his last balance.

Edit account details
Using this option, one can edit the details of the account holder ; it means, the name and address of the person can be changed. The pre-requisite for this is the account number whose name and address is to be edited.

See particular account
The bank’s operating personnel can have a look at each account in the bank individually. The requirement for this is the account number of that particular account.

File Design Structure

Records.txt

Name	Type	Width	Description
name	Char(string)	40 characters	Name of the account holder
address	Char(string)	40 characters	Address of the account holder
age	int	2 bytes	age of the account holder
balance	float	4 bytes	Balance in the account 
account_no	Int	2 bytes	Account Number of the account.
Initial_deposit	float	4 bytes	Initial deposit



List of Header Files

Header files provide function prototype declarations for library functions. 

HEADER FILE	DESCRIPTION / FUNCTIONS USED
iostream.h	provides console input/output
conio.h	getch, delay, clrscr, gotoxy, kbhit
dos.h	delay
graphics.h	allows to insert graphical instruments in the program
stdio.h	gets, puts
string.h	manipulates strings and arrays
fstream.h	provides definitions for stream classes ifstream and ofstream
ctype.h	classifies and transforms individual characters

Class/Function 
Description

Class Graphics
DATA MEMBERS
Name	Type	Description
pass	char(string)	Stores the password.

MEMBER FUNCTIONS
  void gr1();	Function to display graphics

void login();
	Function to make the operating personnel login

void reset(char*);
	Function to reset the password

void blink(int,int);
	Function to blink the cursor

Class Bank

DATA MEMBERS
Name	Type	Description

account_no
	integer	stores the account number

    age
	integer	stores the age of the account holder
balance	float	stores the last balance of the user
initial_deposit	float	stores the initial deposit made by the user
name	char(string)	stores the name of the account holder
address	char(string)	stores the address of the user




MEMBER FUNCIONS
void transactions();	Function to deposit / withdraw money from the account
     void open_new_account();
	Function to create a new account
void list_of_all_accounts();
	Function to view all the accounts in the bank at a glance
void see_account();
	Function to view particular account
void edit_account();
	Function to modify the details of the account holder





Class Menu

DATA MEMBERS
Name	Type	Description
choice	integer	stores the choice in menu



MEMBER FUNCTIONS
void show_menu()	Function to display the main menu 
void toggle(int,int)
	Function to move the cursor in the main menu







Class File

DATA MEMBERS
Name	Type	Description
counter	integer	stores the count of accounts in the bank



MEMBER FUNCTIONS
void read_from_file(int)	Function to read the details of an account from the file records.txt 
void write_to_file(int)		Function to write the details of an account to the file records.txt
void count_records()		Function to count the number of accounts in the bank


