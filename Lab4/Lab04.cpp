// @yuukla
// Feb 27, 2020
// File in project will take values from external .txt and use them in order to caluclate some stuff
#include <math.h>
#include <cmath>     // For sqrt()
#include <fstream>     // For ifstream and ofstream classes
#include <iomanip>    // For setprecision()
#include <iostream>         // For fixed and endl
#include <string>

using namespace std;

//predefine functions b/c this structure is literally dogass
void read_coeff ();
double calc_root1 ();
double calc_root2 ();
double discriminant();
void output ();
int main ();

// Write the function definition for read_coeff(). Make sure to specify that the
// parameter 'fin' is defined as type ifstream& (we will discuss what the & means
// later in the course so don't worry about it for now).


double read_coeff(ifstream& fin){
  double coeff;
  string line;

  //should return one line?
  while (getline(fin, line)){
    fin << line << endl;
  }
}

double discriminant(double a, double b, double c){
  return ((pow(b,2))-(4*a*c))
}

double calc_root1(double a, double b, double c){
  return (((-1*b)+(sqrt((discriminant(a,b,c,)))))/(2*a))
}

double calc_root2(double a, double b, double c){
  return (((-1*b)-(sqrt((discriminant(a,b,c)))))/(2*a))
}

void output(double a, double b, double c, double root1, double root2){
  ofstream fout;
  fout.open("roots.txt");
  fout << setprecision(5) << "The equation " << a << "x^2 + " << b << "x + " << c << " = 0 has roots " << root1 << " and " << root2 << endl;
  fout.close();
  cout << "Please check roots.txt for your input roots." << endl;
}

int main() {

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
