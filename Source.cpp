/* Blake kemp
* Project 2
* Southern New Hampshire Univessity
* Oct 2 2022
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "BankingCalc.h"
using namespace std;

int main() {

}
BankingCalc::BankingCalc() {
}

BankingCalc::BankingCalc(float t_initialInvest, float t_monthlyDep, float t_annInterest, float t_years) {
	initialInvest = t_initialInvest;
	monthlyDep = t_monthlyDep;
	annInterest = t_annInterest;
	years = t_years;
}

//accessors
float BankingCalc::getinitInvest() {
	return initialInvest;
}

float BankingCalc::getAnnualInterest() {
	return annInterest;
}

float BankingCalc::getMonthlyDep() {
	return monthlyDep;
}

float BankingCalc::getYears() {
	return years;
}

float BankingCalc::getMonths() {
	return months;
}

float BankingCalc::getTotalAmt() {
	return totalAmt;
}

float BankingCalc::getInterestAmt() {
	return interestAmt;
}

float BankingCalc::getYearTotInterest() {
	return yearTotInterest;
}

//Function that is going to display the input chart and allow the user to input data

void BankingCalc::dataInput() {
	cout << "*******************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount:";
	cin >> initialInvest;
	if (initialInvest < 0) {
		cout << "Intial investment amount cannot be less than $0" << endl;
		cout << "Initial Investment Amount:";
		cin >> initialInvest;
	}
	cout << "Monthly Deposit:";
	cin >> monthlyDep;
	if (monthlyDep < 0) {
		cout << "Initial Investment amount cannot be less than $0" << endl;
		cout << "Monthly Deposit:";
		cin >> monthlyDep;
	}
	cout << "Annual Interest:";
	cin >> annInterest;
	cout << "Number of years:";
	cin >> years;
	months = years * 12;
	system("PAUSE");
	system("CLS");
	totalAmt = initialInvest;
	//Prints the Data Input with the users Value
	cout << "*******************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount:" << initialInvest << endl;
	cout << "Monthly Deposit: $" << monthlyDep << endl;
	cout << "Annual Interest: %" << annInterest << endl;
	cout << "Number of Years: " << years << endl;
}

//Prints the static report from the information obtained in dataInput()

void BankingCalc::printReport() {
	cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "===========================================================================" << endl;
	cout << "Year         Year End Balance     Year End Earned Interest" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (int i = 0; i < years; i++) {
		//Calculate the yearly interest
		interestAmt = (totalAmt) * ((annInterest / 100));
		//Calculate total at years end
		totalAmt = totalAmt + interestAmt;
		//Prints the results at 2 decimal point precision
		cout << " " << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << interestAmt << "\n";
	}
	totalAmt = initialInvest;

	//Display the year data with monthly deposits from the account owner
	cout << endl;
	cout << "     Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << " Year         Year End Balance     Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	for (int i = 0; i < years; i++) {
		//sets the interest for the year at zero (for a new year)
		yearTotInterest = 0;

		
		for (int j = 0; j < 12; j++) {
			//Calculate the monthly interest 
			interestAmt = (totalAmt + monthlyDep) * ((annInterest / 100) / 12);

			//Calculate the interest at month's end
			yearTotInterest = yearTotInterest + interestAmt;
		}
		//Prints the results at a 2 decimal point precision
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << yearTotInterest << "\n";
	}
}
