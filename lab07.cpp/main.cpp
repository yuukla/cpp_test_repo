//******************************************************************************
// FILE: Lab07.cpp
//
// DESCRIPTION
// Opens a file named "payroll.txt" for reading and reads payroll information
// for one employee. Calculates the employee's paycheck information. Outputs the
// employee paycheck data to a file named "paycheck.txt".
//
// This lab project illustrates the following C++ concepts:
// 1. Functions. Function calls. Pass parameters by-value. Return values.
// 2. Reading from a text file.
// 3. Writing to a text file.
// 4. Formatting output to a text file.
// 5. Writing if, if-else, and if-elseif-elseif... statements.
//
// AUTHOR1: Corbett Hankins, chankin2, chankin2@asu.edu
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2020
// Lab 7, Date/Time: Friday 11:50-12:40
// =============================================================================
// TESTING
//
// -----------------------------------------------------------------------------
// TEST CASE 1:
// -----------------------------------------------------------------------------
// Test Input Data (in payroll.txt)
// Simpson Homer
// 15.25 84
// 2
//
// Expected Output:
// -----------------------------
// EMPLOYEE: Simpson, Homer
//
// PAY RATE:           $   15.25
// HOURS:                  84.00
// GROSS PAY:          $ 1311.50
// MED INS DEDUCT:     $  110.13
// 401K DEDUCT:        $   78.69
// FED TAX GROSS PAY:  $ 1122.68
// TAX - FEDERAL:      $   89.48
// TAX - OASDI:        $   69.61
// TAX - MEDICARE:     $   16.28
// TAX - STATE:        $   38.62
// TAX - TOTAL:        $  213.98
// NET PAY:            $  908.70
// -----------------------------
//
// Actual Output:
// ??? copy-and-paste the contents of paycheck.txt here.
//
// Test Results: ??? document whether the program PASSED or FAILED the test case
//
// -----------------------------------------------------------------------------
// TEST CASE 2:
// -----------------------------------------------------------------------------
// Test Input Data (in payroll.txt)
// ???
// ???
// ???
//
// Expected Output:
// -----------------------------
// EMPLOYEE: ???, ???
//
// PAY RATE:           $   ?????
// HOURS:                  ?????
// GROSS PAY:          $   ?????
// MED INS DEDUCT:     $   ?????
// 401K DEDUCT:        $   ?????
// FED TAX GROSS PAY:  $   ?????
// TAX - FEDERAL:      $   ?????
// TAX - OASDI:        $   ?????
// TAX - MEDICARE:     $   ?????
// TAX - STATE:        $   ?????
// TAX - TOTAL:        $   ?????
// NET PAY:            $   ?????
// -----------------------------
//
// Actual Output:
// ??? copy-and-paste the contents of paycheck.txt here.
//
// Test Results: ??? document whether the program PASSED or FAILED the test case
//
// -----------------------------------------------------------------------------
// TEST CASE 3:
// -----------------------------------------------------------------------------
// Test Input Data (in payroll.txt)
// ???
// ???
// ???
//
// Expected Output:
// -----------------------------
// EMPLOYEE: ???, ???
//
// PAY RATE:           $   ?????
// HOURS:                  ?????
// GROSS PAY:          $   ?????
// MED INS DEDUCT:     $   ?????
// 401K DEDUCT:        $   ?????
// FED TAX GROSS PAY:  $   ?????
// TAX - FEDERAL:      $   ?????
// TAX - OASDI:        $   ?????
// TAX - MEDICARE:     $   ?????
// TAX - STATE:        $   ?????
// TAX - TOTAL:        $   ?????
// NET PAY:            $   ?????
// -----------------------------
//
// Actual Output:
// ??? copy-and-paste the contents of paycheck.txt here.
//
// Test Results: ??? document whether the program PASSED or FAILED the test case
//==============================================================================

// Include required header files.
#include <cstdlib>
#include <fstream>
#include <iomanip>   // For setprecision(), setw()
#include <iostream>
#include <string>    // For string class

using namespace std;

const double OASDI_RATE = 0.062; //define constant OASDI_RATE
const double FOUR01K_RATE = 0.06;
const double MEDICARE_RATE = 0.0145; //define constant MEDICARE_RATE
const double MED_INS_DEDUCT_EMPL_ONLY = 32.16; //define MED_INS_DEDUCT_EMPL_ONLY
const double MED_INS_DEDUCT_EMPL_ONE = 64.97; //define MED_INS_DEDUCT_EMPL_ONE
const double MED_INS_DEDUCT_FAMILY = 110.13; //define MED_INS_DEDUCT_FAMILY
const int MED_INS_STATUS_EMPL_ONLY = 0;  // Employee Only
const int MED_INS_STATUS_EMPL_ONE  = 1;  // Employee + One
const int MED_INS_STATUS_FAMILY    = 2;  // Family

//------------------------------------------------------------------------------
// FUNCTION: error_exit()
//
// Called when something "bad" happens. Displays the specified error message
// 'msg' and then terminates the program with an exit code of -1.
//------------------------------------------------------------------------------
void error_exit(string msg)
{
    cout << msg << endl;
    exit(-1);
}

//------------------------------------------------------------------------------
// FUNCTION: calc_gross_pay()
//
// Calculates and returns an employee's gross pay which is based on the number
// of hours worked (in parameter hrs_worked) and the employee's pay rate (in
// parameter pay_rate).
//------------------------------------------------------------------------------
double calc_gross_pay(double pay_rate, double hrs_worked)//Implement the pseudocode from the lab project document
{
    double gross_pay=0;
    if (hrs_worked <= 80)
    {
        gross_pay=hrs_worked*pay_rate;
    }
    else
    {
        gross_pay=(80*pay_rate)+(hrs_worked-80)*(1.5*pay_rate);
    }
    return (gross_pay);
}

//------------------------------------------------------------------------------
// FUNCTION: calc_med_ins_deduct()
//
// Determines and returns the employee's medical insurance deduction which is
// based on the employee's medical insurance status in parameter med_ins_status.
//------------------------------------------------------------------------------
double calc_med_ins_deduct(int med_ins_status) //Implement the pseudocode from the lab project document
{
    double med_ins_deduct=0;
    if (med_ins_status == MED_INS_DEDUCT_EMPL_ONLY)
    {
        med_ins_deduct = MED_INS_DEDUCT_EMPL_ONLY;
    }
    else if (med_ins_status == MED_INS_DEDUCT_EMPL_ONE)
    {
        med_ins_deduct = MED_INS_DEDUCT_EMPL_ONE;
    }
    else
    {
        med_ins_deduct = MED_INS_DEDUCT_FAMILY;
    }
    return (med_ins_deduct);
}

//------------------------------------------------------------------------------
// FUNCTION: calc_tax_fed()
//
// Calculates and returns the employee's federal income tax which is based on
// his or her federal taxable gross pay (in parameter fed_tax_gross_pay) and the
// federal tax withholding percentage table in the lab project document.
//------------------------------------------------------------------------------
double calc_tax_fed(double fed_tax_gross_pay) //Implement the pseudocode from the lab project document.
{
   double tax_fed = 0;
    if (fed_tax_gross_pay >= 384.62 && fed_tax_gross_pay < 1413.67)
    {
        tax_fed = fed_tax_gross_pay * 0.0797;
    }
    else if (fed_tax_gross_pay >= 1413.67 && fed_tax_gross_pay < 2695.43)
    {
        tax_fed = fed_tax_gross_pay * 0.1275;
    }
    else if (fed_tax_gross_pay >= 2695.43)
    {
        tax_fed = fed_tax_gross_pay * 0.195;
    }
    return tax_fed;
}

//------------------------------------------------------------------------------
// FUNCTION: calc_tax_state()
//
// Calculates and returns the employee's state income tax which is based on his
// or her federal taxable gross pay (in parameter fed_tax_gross_pay) and the
// state tax withholding percentage table in the lab project document.
//------------------------------------------------------------------------------
double calc_tax_state(double fed_tax_gross_pay)
{
    double tax_state = 0;
    if (fed_tax_gross_pay < 961.54) {
        tax_state = fed_tax_gross_pay * 0.0119;
    } else if (fed_tax_gross_pay < 2145.66) {
        tax_state = fed_tax_gross_pay * 0.0344;
    } else {
        tax_state = fed_tax_gross_pay * 0.0774;
    }
    return tax_state;
}

//------------------------------------------------------------------------------
// FUNCTION: open_input_file()
//
// Opens the file named by filename for reading. If the file cannot be opened
// then call error_exit() to terminate the program.
//------------------------------------------------------------------------------
void open_input_file(ifstream& fin, string filename)
{
    // Pass the C-string inside of filename to fin.open() to open the file.
    fin.open(filename.c_str());

    // If the file could not be opened (most likely because it does not exist),
    // then the ifstream variable fin will be false. So, if fin is false, we
    // call the  error_exit() function to terminate the program.
    if (!fin) {
        error_exit("Could not open input file for reading.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: open_output_file()
//
// Opens the file named by filename for writing. If the file cannot be opened
// then call error_exit() to terminate the program.
//------------------------------------------------------------------------------
void open_output_file(ofstream& fout, string filename)
{
    // Pass the C-string inside of filename to fout.open() to open the file.
    fout.open(filename.c_str());

    // If the file could not be opened then the ofstream variable fout will be
    // false. So, if fout is false, we call the error_exit() function to
    // terminate the program.
    if (!fout) {
        error_exit("Could not open output file for writing.");
    }
}

int main()
{
    // Define an ifstream object named 'fin' to read from the input file. Then
    // call open_input_file() passing "payroll.txt" as the name of the file to
    // be opened. If the file could not be opened for reading, then open_input_
    // file() will not return.
    ifstream fin;
    open_input_file(fin, "payroll.txt");

    // Read the employee's last and first names from the input file into string
    // objects/variables named last_name and first_name, which must be defined.
    string first_name, last_name;
    fin >> last_name >> first_name;

    // Read the employee's pay rate from the input file into double variable
    // pay_rate, which must be defined.
    double pay_rate;
    fin >> pay_rate;

    // Read the employee's hours worked from the input file into double variable
    // hrs_worked, which must be defined.
    double hrs_worked;
    fin >> hrs_worked;

    // Read the employee's medical insurance status from the input file into int
    // variable med_ins_status, which must be defined.
    int med_ins_status;

    fin >> med_ins_status;
    fin.close();
    double gross_pay = calc_gross_pay(pay_rate, hrs_worked);
    double four01k_deduct = gross_pay * FOUR01K_RATE;
    double med_ins_deduct = calc_med_ins_deduct(med_ins_status);
    double fed_tax_gross_pay = gross_pay-med_ins_deduct-four01k_deduct;
    double tax_fed = calc_tax_fed (fed_tax_gross_pay);
    double tax_oasdi = fed_tax_gross_pay * OASDI_RATE;
    double tax_medicare = fed_tax_gross_pay * MEDICARE_RATE;
    double tax_state = calc_tax_state(fed_tax_gross_pay);
    double tax_total = tax_fed + tax_oasdi + tax_medicare + tax_state;
    double net_pay = fed_tax_gross_pay-tax_total;

    // Define an ofstream object named 'fout' to write to the output file. Then
    // call open_output_file() passing "paycheck.txt" as the name of the file to
    // be opened. If the file could not be opened for writing, then open_output_
    // file() will not return.
    ofstream fout;
    open_output_file(fout, "paycheck.txt");

    // Configure fout so real numbers will be printed in fixed notation with two
    // digits after the decimal point.
    fout << right << setprecision(3);

    // Configure fout so the numbers will be printed right-justified in their
    // respective fields.

    fout << "-----------------------------"    << endl;
    fout << "EMPLOYEE: " << last_name << ", "  << first_name << endl << endl;
    fout << "PAY RATE:           $" << setw(8) << pay_rate << endl;
    fout << "HOURS:               " << setw(8) << hrs_worked << endl;
    fout << "GROSS PAY:          $" << setw(8) << gross_pay << endl;
    fout << "MED INS DEDUCT:     $" << setw(8) << med_ins_deduct << endl;
    fout << "401K DEDUCT:        $" << setw(8) << four01k_deduct << endl;
    fout << "FED TAX GROSS PAY:  $" << setw(8) << fed_tax_gross_pay << endl;
    fout << "TAX - FEDERAL:      $" << setw(8) << tax_fed << endl;
    fout << "TAX - OASDI:        $" << setw(8) << tax_oasdi << endl;
    fout << "TAX - MEDICARE:     $" << setw(8) << tax_medicare << endl;
    fout << "TAX - STATE:        $" << setw(8) << tax_state << endl;
    fout << "TAX - TOTAL:        $" << setw(8) << tax_total << endl;
    fout << "NET PAY:            $" << setw(8) << net_pay << endl;
    fout << "-----------------------------"    << endl;
    fout.close();
    return 0;
}
