//******************************************************************************
// FILE: Lab04.cpp
//
// DESCRIPTION
// Reads the coefficients of quadratic equations from "coeffs.txt". Calculates
// the roots of each equation and outputs the results to "roots.txt".
//
// AUTHOR1: your-name, your-asurite-username, your-email-address
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2020
// Lab 4, Date/Time: your-lab-date-and-time, TA: your-lab-ta's-name
//==============================================================================
// TESTING
//
// -----------------------------------------------------------------------------
// TEST CASE 1:
//
// DESCRIPTION:
// Tests that the two real roots of 2.5x^2 + 7.6x - 3 = 0 are calculated
// correctly.
//
// TEST CASE INPUT DATA:
// a = 2.5, b = 7.6, c = -3
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// The equation 2.50000x^2 + 7.60000x + -3.00000 = 0 has roots 0.35361 and
// -3.39361.
//
// OBSERVED OUTPUT:
// <document the observed output here>
//
// TEST CASE RESULT: <document if the test case passed or failed>
// -----------------------------------------------------------------------------
// TEST CASE 2:
//
// DESCRIPTION:
// Tests that the two real roots ??? x^2 + ??? x + ??? = 0 are calculated
// correctly.
//
// TEST CASE INPUT DATA:
// a = ???, b = ???, c = ???
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// <document the expected ouput>
//
// OBSERVED OUTPUT:
// <document the observed output here>
//
// TEST CASE RESULT: <document if the test case passed or failed>
// -----------------------------------------------------------------------------
// TEST CASE 3:
//
// DESCRIPTION:
// Tests that the two real roots ??? x^2 + ??? x + ??? = 0 are calculated
// correctly.
//
// TEST CASE INPUT DATA:
// a = ???, b = ???, c = ???
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// <document the expected ouput>
//
// OBSERVED OUTPUT:
// <document the observed output here>
//
// TEST CASE RESULT: <document if the test case passed or failed>
// -----------------------------------------------------------------------------
// TEST CASE 4:
//
// DESCRIPTION:
// Tests that the two real roots ??? x^2 + ??? x + ??? = 0 are calculated
// correctly.
//
// TEST CASE INPUT DATA:
// a = ???, b = ???, c = ???
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// <document the expected ouput>
//
// OBSERVED OUTPUT:
// <document the observed output here>
//
// TEST CASE RESULT: <document if the test case passed or failed>
//*******************************************************************************
#include <math.h>
#include <cmath>     // For sqrt()
#include <fstream>     // For ifstream and ofstream classes
#include <iomanip>    // For setprecision()
#include <iostream>         // For fixed and endl
#include <string>

using namespace std;

//predefine functions b/c this structure is literally dogass
void discriminant();
void calc_root1 ();
void calc_root2 ();
void output ();
int main ();

// Write the function definition for read_coeff(). Make sure to specify that the
// parameter 'fin' is defined as type ifstream& (we will discuss what the & means
// later in the course so don't worry about it for now).

int main(void) {

  double a, b, c, root1, root2;
  ifstream fin;

  //read in variables from read_coeff()
  fin.open("coeffs.txt");
  if(fin.is_open()){
    a = read_coeff(fin);
    b = read_coeff(fin);
    c = read_coeff(fin);
  }
  fin.close();

  //calculate roots
  root1 = calc_root1(a, b, c);
  root2 = calc_root2(a, b, c);
  output (a, b, c, root1, root2);

  return 0;
}

void read_coeff(ifstream& fin){
  double coeff;
  string line;

  //should return one line?
  while (getline(fin, line){
    cout << line << endl;
  }
}

double discriminant(double a, double b, double c){
  return ((pow(b,2))-(4*a*c))
}

double calc_root1(double a, double b, double c){
  return (((-1*b)+(sqrt((discriminant(a,b,c,)))))/(2*a))
}

double calc_root2(double a, double b, double c){
  return (((-1*b)-(sqrt((discriminant(a,b,c,)))))/(2*a))
}

void output(double a, dobule b, double c, double root1, double root2){
  ofstream fout;
  fout.open("roots.txt");
  cout << setprecision(5) << "The equation " << a << "x^2 + " << b << "x + " << c << " = 0 has roots " << root1 << " and " << root2 << endl;
  fout.close();
}
