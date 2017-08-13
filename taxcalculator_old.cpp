/*
 * taxcalculator.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: Samuel
 */

// C++TaxEstimator.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <iomanip>

using namespace std;

static enum taxStatus {
    Single = 1,
    MarriedFilingJointly,
    MarriedFilingSeparately,
    HeadOfHousehold,
    QualifyingWidow // or Widower
};
struct taxTable {
    double from;
    double to;
    double tax;
    double percent;
};
const double exemptionRate = 4000.00;
const int bracketCount = 7;
int inputStatus();
int inputExemptions();
double inputIncome();
double itemizeDeductions(int status);
double standardDeductions(int status);
double computedTax(int, double taxableIncome);
taxTable *tableSelection(int);

int main(int argc, char* argv[])
{
    int    status;
    int    itemize_deduction = 0;
    double totalIncome;
    int    exemptions;
    double deductions;
    double taxableIncome;
    double tax;
    double withholding;
    double refundOrTaxDue;

    cout << "2015 FEDERAL TAX ESTIMATOR" << endl;
    cout << "For information purposes only" << endl << endl;
    do
    {
        // input the data
        status = inputStatus();
        if (status == 0) break;   // end the program

        exemptions = inputExemptions();
        totalIncome = inputIncome();

        cout << "Which deduction do you want to use? \n0 --> Standard \n1 --> Itemized \n ";
        cin  >> itemize_deduction;

        if (itemize_deduction == 1)
        {
        	deductions = itemizeDeductions(status);
        }
        else
        {
        	deductions = standardDeductions(status);
        }

        cout << "Enter the amount withheld: ";
        cin  >> withholding;

        // compute the tax
        taxableIncome = totalIncome - exemptions*exemptionRate - deductions;
        if (taxableIncome <   0)
            taxableIncome = 0;
        tax = computedTax ((taxStatus)status, taxableIncome);
        refundOrTaxDue = withholding - tax;

        // display the results
        cout << setiosflags(ios::fixed | ios::showpoint) << endl;
        cout << setprecision(2);
        cout << endl;
        cout << "Income:          " << setw(9) << totalIncome << endl;
        cout << "Exemptions:      " << setw(9) << -exemptions * exemptionRate << endl;
        cout << "Deductions:      " << setw(9) << -deductions << endl;
        cout << "--------------------------" << endl;
        cout << "Taxable Income:  " << setw(9) << taxableIncome << endl << endl;
        cout << "Tax Estimate:    " << setw(9) << tax << endl;
        cout << "Withholding:     " << setw(9) << withholding << endl;
        if (refundOrTaxDue >= 0)
            cout << "Estimated refund:" << setw(9) << refundOrTaxDue << endl;
        else
            cout << "Please pay:      " << setw(9) << -refundOrTaxDue << endl;
        cout << endl;
    } while (status >=1 && status <= 5);
    return 0;
}

////// input taxpayer status (0-5) ////
int inputStatus()
{
    int status;

    do {
        cout << "=======================================================" << endl;
        cout << "Enter your tax status:" << endl
            << "1 = Single" << endl
            << "2 = Married filing jointly" << endl
            << "3 = Married filing separately" << endl
            << "4 = Head of Household" << endl
            << "5 = Qualifying widow(er)" << endl
            << "0 = END THE PROGRAM" << endl
            << "> ";
        cin  >> status;
        if (cin.fail() || status < 0 || status > 5)
            cout << "Illegal value, try again" << endl;
    } while (status < 0 || status > 5);
    return status;
}

////// input exemptions ////
int inputExemptions()
{
    int exemptions;
    cout << "Enter the number of exemptions: (you + dependants): ";
    cin  >> exemptions;
    return exemptions;
}

////// input income ////
double inputIncome()
{
    double income;
    cout << "Enter your total income: ";
    cin  >> income;
    return income;
}

////// input deductions ////
double itemizeDeductions(int s)
{
    double deductions;
    cout << "Enter the amount of your Itemized Deductions: ";
    cin  >> deductions;
    return deductions;
}

double standardDeductions(int status)
{
    double deductions;

    /*use the following standard deductions
    Single 6300.00
    Married filing jointly     12600.00
    Married filing separately   6300.00
    Head of Household           9250.00
    Qualifying Widow(er)       12600.00
	*/
	switch (status) {   // return a pointer to the table based on the filing status
	        case Single:                  deductions = 6300.00; break;
	        case MarriedFilingJointly:    deductions = 12600.00; break;
	        case MarriedFilingSeparately: deductions = 6300.00; break;
	        case HeadOfHousehold:         deductions = 9250.00; break;
	        case QualifyingWidow:         deductions = 12600.00; break;
	        default:                      deductions=0; break;
	    };

    cout << "Your standard Deduction is: " <<deductions <<endl;

    return deductions;
}

// The asterisk * indicates that a pointer is to be returned.
taxTable *tableSelection (int s)
{
    const double maxDouble = numeric_limits<double>::max();
        //from      to          tax         percent
    static taxTable SingleTaxTable[] = {
        {0.00,      9225.00,    0.00,       10.0},
        {9225.00,   37450.00,   922.50,     15.0},
        {37450.00,  90750.00,   5156.25,    25.0},
        {90750.00,  189300.00,  18481.25,   28.0},
        {189300.00, 411500.00,  46075.25,   33.0},
        {411500.00, 413200.00,  119401.25,  35.0},
        {413200.00, maxDouble,  119996.25,  39.6}
    };
    static taxTable MarriedFilingJointlyTaxTable[] = {
        {0.00,      18450.00,   0.00,       10.0},
        {18450.00,  74900.00,   1845.00,    15.0},
        {74900.00,  151200.00,  10312.50,   25.0},
        {151200.00, 230450.00,  29387.50,   28.0},
        {230450.00, 411500.00,  51577.50,   33.0},
        {411500.00, 464850.00,  111324.00,  35.0},
        {464850.00, maxDouble,  129996.50,  39.6}
    };
    static taxTable MarriedFilingSeparatelyTaxTable[] = {
        {0.00,      9225.00,    0.00,       10.0},
        {9225.00,   37450.00,   922.50,     15.0},
        {37450.00,  75600.00,   5156.25,    25.0},
        {75600.00,  115225.00,  14693.75,   28.0},
        {115225.00, 205750.00,  25788.75,   33.0},
        {205750.00, 232425.00,  55662.00,   35.0},
        {232425.00, maxDouble,  64998.25,   39.6}
    };
    static taxTable HeadOfHouseholdTaxTable[] = {
        {0.00,      13150.00,   0.00,       10.0},
        {13150.00,  50200.00,   1315.00,    15.0},
        {50200.00,  129600.00,  6872.50,    25.0},
        {129600.00, 209850.00,  26772.50,   28.0},
        {209850.00, 411500.00,  49192.50,   33.0},
        {411500.00, 439000.00,  115737.00,  35.0},
        {439000.00, maxDouble,  125362.00,  39.6}
    };
    static taxTable QualifyingWidowTaxTable[] = {
        {0.00,      18450.00,   0.00,       10.0},
        {18450.00,  74900.00,   1845.00,    15.0},
        {74900.00,  151200.00,  10312.50,   25.0},
        {151200.00, 230450.00,  29387.50,   28.0},
        {230450.00, 411500.00,  51577.50,   33.0},
        {411500.00, 464850.00,  111324.00,  35.0},
        {464850.00, maxDouble,  129996.50,  39.6}
    };
    switch (s) {   // return a pointer to the table based on the filing status
        case Single:                  return SingleTaxTable;
        case MarriedFilingJointly:    return MarriedFilingJointlyTaxTable;
        case MarriedFilingSeparately: return MarriedFilingSeparatelyTaxTable;
        case HeadOfHousehold:         return HeadOfHouseholdTaxTable;
        case QualifyingWidow:         return QualifyingWidowTaxTable;
        default:                      return NULL;
    };
    return NULL;
}
double computedTax (int s, double taxableIncome)
{
    taxTable *table = tableSelection(s);
    double baseTax;
    double tax=0.0;
    // find the entry in the tax table
    for (int i=0; i<bracketCount; i++)
    {
        if (taxableIncome>table[i].from && taxableIncome<=table[i].to)
        {
            baseTax = table[i].tax;
            tax = baseTax + (taxableIncome - table[i].from)*table[i].percent/100.0;
        }
    }
    return tax;
}


