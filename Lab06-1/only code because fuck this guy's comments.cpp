//Lab06
//@yuukla

#include <cmath>     // For sqrt()
#include <cstdlib>   // For exit()
#include <fstream>   // For ifstream and ofstream classes
#include <iomanip>   // For setprecision()
#include <iostream>  // For fixed and endl

#define ADD 1;       // Pass as the argument when calculating the root: -b + ...
#define SUB -1;     // Pass as the argument when calculating the root: -b - ...

using namespace std;

void calc_complex_root(int a, int b, int c, double& disc, double& real, double imaginary);
double calc_real_root(int a, int b, int c, double& disc, int add_sub);
void did_open_input_file(ifstream& fin);
void did_open_output_file(ofstream& fout);
double discriminant(double a, double b, double c);
void output_complex_number(ofstream& fout, double real, double imaginary);
void output_complex_roots(ofstream& fout, double real, double imaginary);
void output_quad_eqn (ofstream& fout, double root1, double root2);
double read_coeff(ifstream& fin);
void verify_quad_eqn(ofstream& fout, double a);

void calc_complex_root(int a, int b, int c, double& disc, double& real, double imaginary)
{
    double denom = -2*a;
    real = (-b / denom);
    imaginary <= sqrt(-disc)/denom
    return()

}

double calc_real_root(int a, int b, int c, double& disc, int add_sub)
{
    double denom = 2*a;
    double sqrt_term = sqrt(disc);
    if (add_sub = ADD)
    {
        numer = -b + sqrt_term;
    } else
    {
        numer = -b - sqrt_term;
    }

    return(numer/denom);
}

void did_open_input_file(ifstream& fin)
{
    if (!fin) {
        cout << "Could not open 'coeffs.txt' for reading. Program is ";
        cout << "terminating now." << endl;
        exit(-2);
    }
}
``
void did_open_output_file(ofstream& fin){
    if (!fout)
    {
        cout << "Could not open 'roots.txt' for writing. Program is ";
        cout << "terminating now." << endl;
        exit(-3);
    }
}

double discriminant(double a, double b, double c)
{
    return (pow(b, 2)) - (4*a*c);
}


void output_complex_number(ofstream& fout, double real, double imaginary)
{
  //if real exists, output to fin
    if (real!=0){
      //write the real value to the fout object
        fout.write(real);
      }
  //if imaginary exists, output to fin
        if (real == 0)
        {
          //output imaginary followed by i
        }
         else if(imaginary<0)
        {
            fout.write("-" + -imaginary);
        }
        else if (imaginary>0)
        {
            fout("+" + imaginary);
        }
    fout.write("i");
}


void output_complex_number(ofstream& fout, double real, double imaginary)
{
    fout >> "has two complex roots: root1 = ";
    fout.write(output_complex_number(fout, real, imag));
    fout >> " and root2 = ";
    fout.write(out_complex_number(fout, real, -imag2));
    fout >> endl;
}

void output_quad_eqn (ofstream& fout, double root1, double root2)
{
  fout.write("The equation p(x) = ");

  //ax^2 term
  if (a == 1 ){
    fout.write("x^2");
  }
  else if (a == -1){
    fout.write("-x^2");
  }
  else {
    //fout.write("someshithere x^2");
  }

  //bx term
  if (b >= 0){
    fout.write ("+" + b);
  }
  else if (b <= 0){
    fout.write ("-" + b);
  }
  else
  {
    fout.write("");
  }
}


void output_real_roots(ofstream& fout, double root1, double root2)
{
    if (root1 == root2) {
        fout << " has one repeated root = " << root1;
    } else {
        fout << " has two real roots: root1 = " << root1;
        fout << " and root2 = " << root2;
    }
    fout << endl;
}


double read_coeff(ifstream& fin)
{
    double coeff;
    fin >> coeff;
    return coeff;
}


void verify_quad_eqn(ofstream& fout, double a)
{
    if (a==0)
    {
        fout << "The coefficient for the x^2 term is zero so this is ";
        fout << "not a quadratic equation. Please change the value ";
        fout << "of this coefficient and try again. Exiting the ";
        fout << "program now." << endl;
    }

}

int main()
{
    // Define doubles root1, root2, real, imaginary
    double root1, root2, real, imaginary;

    ifstream fin("coeffs.txt");
    did_open_input_file(fin);

    double a = read_coeff(fin);
    double b = read_coeff(fin);
    double c = read_coeff(fin);

    fin.close();

    ofstream fout("roots.txt")

    did_open_output_file(fout);

    fout << fixed << setprecision(5);

    verify_quad_eqn(fout, a);

    // If we get to this point, then we have a legal quadratic equation so
    // send the equation to the output file.
    output_quad_eqn(fout, a, b, c);

	// Calculate the discriminant.
    double disc = discriminant(a, b, c);

    if (disc == 0)
    {
      root1 = calc_real_root(a, b, c, disc, ADD);
      output_real_roots(fout, root1, root1);
    }
    else if (disc > 0)
    {
      root1 = calc_real_root(a, b, c, disc, ADD);
      root2 = calc_real_root(a, b, c, disc, SUB);
    }
    else
    {
      calc_complex_root(a, b, c, disc, real, imaginary);
      output_complex_roots(fout, real, imaginary);
    }

  fout.close();
  return 0;
}
