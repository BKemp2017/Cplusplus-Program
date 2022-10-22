#ifndef SAVINGS_H_
using namespace std;

class Savings {
public:
	//accessors and methods 
	Savings(double investment, double monthDep, double rate, int years);
	virtual ~Savings();
	void reportNoMonthlyDep();
	void reportWithMonthlyDep();

	//private variables that were used in calculations 
private:
	double initDep;
	double monthlyDep;
	double interestRate;
	int numYears;

};
#endif
