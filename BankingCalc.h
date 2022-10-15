using namespace std;

class BankingCalc {
public: 
	//accessors and methods 
	BankingCalc();
	BankingCalc(float t_initialInvest, float t_monthlyDep, float t_annInterest, float t_years);
	float getinitInvest();
	float getMonthlyDep();
	float getAnnualInterest();
	float getYears();
	void dataInput();
	void printReport();
	float getMonths();
	float getTotalAmt();
	float getInterestAmt();
	float getYearTotInterest();
	//private variables that were used in calculations 
private:
	float initialInvest = 0;
	float monthlyDep = 0;
	float annInterest = 0;
	float years = 0;
	float months = 0;
	float totalAmt = 0;
	float interestAmt = 0;
	float yearTotInterest = 0;
};
