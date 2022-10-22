/* Blake kemp
* Project 2
* Southern New Hampshire Univessity
* Oct 2 2022
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Savings.h"
using namespace std;

//Contstructor
Savings::Savings(double investment, double monthDep, double rate, int years) {
	this->initDep = investment;
	this->monthlyDep = monthDep;
	this->interestRate = rate;
	this->numYears = years;
}

//destructor
Savings::~Savings() {}

//output report without additional monthly deposits
void Savings::reportNoMonthlyDep() {
	//heading
	cout << "       Balance and Interest Without Additional Monthly Deposits" << endl; 
	cout << "===================================================================================" << endl;
	//table heading 
	cout << setw(10) << "Year" << setw(25) << "Year End Balance" << setw(40) << "Year End Earned Interest Rate" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	//Loop through the given years and calculate the interest earned
	int currentYear = 1;
	double yearEndBal = this->initDep;

	while (currentYear <= this->numYears) {
		//interest calculated 
		double interestEarned = yearEndBal * this->interestRate / 100;
		//add to year end balance
		yearEndBal += interestEarned;
		//output result for each year
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << "$" << yearEndBal << setw(35) << "$" << interestEarned << endl;
		//increase the year by one 
		currentYear++;
	}
}

//output report with additional monthly deposits
void Savings::reportWithMonthlyDep() {
	//heading
	cout << "          Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "===================================================================================" << endl;
	//table heading 
	cout << setw(10) << "Year" << setw(25) << "Year End Balance" << setw(40) << "Year End Earned Interest Rate" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	//Loop through the given years and calculate the interest earned
	int currentYear = 1;
	double yearEndBal = this->initDep;

	while (currentYear <= this->numYears) {
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBal = yearEndBal;

		while (month <= 12) {
			//add the month deposit
			monthEndBal += this->monthlyDep;
			//interest calculated
			double monthlyInt = monthEndBal * this->interestRate / (100 * 12);
			interestEarned += monthlyInt;
			//add to monthly end balance
			monthEndBal += monthlyInt;
			//increment the month by one
			month++;
		}
		//after 12 months
		yearEndBal = monthEndBal;
		//output final results
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << "$" << yearEndBal << setw(35) << "$" << interestEarned << endl;
		currentYear++;
	}
}

int main() {
	while (true) {
		cout << "********************************" << endl;
		cout << "*********** Data Input *********" << endl;
		cout << endl;
		cout << "Initial Investment Amount:" << endl;
		cout << "Monthly Deposit:" << endl;
		cout << "Annual Interest:" << endl;
		cout << "Number of years:" << endl;
		cout << endl;

		//get input from the user
		double investment, monthlyDep, interestRate;
		int years;

		cin >> investment;
		cin >> monthlyDep;
		cin >> interestRate;
		cin >> years;

		cout << "********************************" << endl;
		cout << "*********** Data Input *********" << endl;
		cout << "Initial Investment Amount: $" << investment << endl;
		cout << "Monthly Deposit: $" << monthlyDep << endl;
		cout << "Annual Interest: %" << interestRate << endl;
		cout << "Number of years: " << years << endl;
		cout << endl;

		Savings mySavings = Savings(investment, monthlyDep, interestRate, years);
		cout << endl;

		//Call report with no monthly Deposits
		mySavings.reportNoMonthlyDep();
		cout << endl;

		//Call report with monthly deposits if the user inpout a value greater than 0 for their monthly deposits
		if (monthlyDep > 0) {
			mySavings.reportWithMonthlyDep();
		}

		//ask the user if they want to run another calculation 
		cout << endl << "Do you wish to perform another calculation? (y/n):";
		string choice;
		cin >> choice;

		//if user does not type y to perform another calculation, end program
		if (choice != "y") {
			break;
		}
		cout << endl;
	}
	return 0;
}
