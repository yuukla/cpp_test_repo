//******************************************************************************
// FILE: Lab06.cpp
//
// DESCRIPTION
// Reads the coefficients of quadratic equations from "coeffs.txt". Calculates
// the roots of each equation and outputs the results to "roots.txt". This lab
// is an extension to Lab Project 4, where we could not handle complex roots.
// Lab Project 6 permits complex roots and also uses if and if-else statements
// to more neatly format the output of the equation and the complex roots.
//
// AUTHOR1: your-name, your-asurite-username, your-email-address
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2020
// Lab 6, Date/Time: your-lab-date-and-time, TA: your-lab-ta's-name
//
//------------------------------------------------------------------------------
// NOTES REGARDING PASSING fin AND fout AS FUNCTION ARGUMENTS
//------------------------------------------------------------------------------
// When we pass fin and fout as arguments to a function, then in the function
// header of the function being called, we have to write an ampersand & follow-
// ing the data type, e.g.,
//
// void input(ifstream& fin, ...)
// {
//     ...
// }
//
// void output(ofstream& fout, ...)
// {
//     ...
// }
//
// int main()
// {
//     -- Define fin stream object and open "in.txt" for reading.
//     ifstream fin("in.txt");
//
//     -- Call input() to read some data from the input file. Note that when
//     -- we call input(), we do not put the data type of fin; we simply
//     -- just write: fin
//     input(fin, ...);
//     ...
//
//     -- When we have read all of the data from the input file, we must close
//     -- the file.
//     fin.close();
//
//     -- Define fout stream object and open "out.txt" for writing.
//     ofstream fout("out.txt");
//
//     -- Call output() to write some data to the output file. Note that when
//     -- we call output(), we do not put the data type of fout; we simply
//     -- just write: fout
//     output(fout, ...);
//     ...
//
//     -- When we have written all of the data to the output file, we must close
//     -- the file.
//     fout.close();
//     ...
// }
//
// This will be explained when we get back to Chapter 6 (Functions) and when we
// talk about the pass by-reference parameter passing technique. So, for now,
// don't worry about the syntax requiring the & but just be aware that it needs
// to be there.
//
// In a similar manner, when we return the real and imaginary parts of a complex
// number from calc_complex_root() the values are being returned in the 'real'
// and 'imaginary' parameters and those parameters must be defined as type
// double& so if your program is not correctly displaying the roots of complex
// numbers then check that the required ampersand is in place in that function
// header. Note also that in the calc_complex_root() function header that the
// only variables which must be declared as double& (rather than as just
// double) are 'real and 'imaginary'.
//
//------------------------------------------------------------------------------
// PSEUDOCODE NOTES
//------------------------------------------------------------------------------
// 1. In my pseudocode I usually omit the data types of variables, which one can
//    usually infer from the descriptions and comments in the code and from the
//    text of the lab project document.
//
// 2. I use -- for pseudocode comments, which function in pseudocode exactly as
//    // function in C++ code.
//
// 3. I use 'nothing' in pseudocode to represent void.
//
// 4. <= is assignment operator
//
// 5. Sometimes in the text of the comments or pseudocode, the name of a vari-
//    able, function, constant may be confused for text. If I wish to emphasize
//    the that name is the name of a variable, function, constant then I will
//    write the name in single quote marks, e.g., if I wish to explain that
//    variable a is assigned the value 3, then I could write: a is assigned the
//    value 3, but some people might just think the letter a is part of the
//    text and not the name of the variable. To emphasize this, I would write:
//    'a' is assigned the value 3. I don't do this all of the time, but you
//    will see it some of the time.
//
//------------------------------------------------------------------------------
// QUADRATIC EQUATIONS, COMPLEX ROOTS, AND REFERENCES
//------------------------------------------------------------------------------
// This is a nice and simple reference site for solving quadratic equations:
// https://www.purplemath.com/modules/quadform.htm
//
// Note that when the roots of a quadratic equation are complex numbers, they
// will be complex conjugates, i.e., suppose the solution when we calculate
// (-b + ...) / 2a we get root1 = root + imaginary 'i'. Because the roots are
// complex conjugates, the second root will be root2 = root - imaginary 'i'.

//==============================================================================
// TESTING - YOU ARE TO DOCUMENT THE EIGHT TEST CASES THAT ARE REQUESTED IN THE
// LAB PROJECT DOCUMENT HERE IN THE HEADER COMMMENT BLOCK.
//==============================================================================
// TEST CASE 1
//
// DESCRIPTION:
// -- Briefly describe what software requirements are being tested.
// Coefficients a and c are > 0 and b < 0 so the equation should be output as:
// p(x) = 122.50000x^2 - 6.70000x + 3.00000 = 0 where we note that the operator
// printed before b is subtraction and we actually output -b rather than b.
// Also, this equation has complex roots so the program should output two
// complex numbers which are complex conjugates.
//
// INPUT DATA:
// a = 122.5  b = -6.7  c = 3
//
// EXPECTED OUTPUT:
// -- Calculate the roots by hand using your calculator and then write here
// -- exactly what the output should be given the coefficients and roots.
// The equation p(x) = 122.50000x^2 - 6.70000x + 3.00000 = 0 has two complex
// roots: root1 = 0.02735 + 0.15408i and root2 = 0.02735 - 0.15408i
//
// ACTUAL OUTPUT:
// -- Copy-and-paste the contents of 'roots.txt' right here.
// The equation p(x) = 122.50000x^2 - 6.70000x + 3.00000 = 0 has two complex
// roots: root1 = 0.02735 + 0.15408i and root2 = 0.02735 - 0.15408i
//
// RESULT:
// -- Note that the actual output given the input must match EXACTLY the
// -- expected output (including spaces, tabs, endlines, numbers being printed
// -- with 5 decimal digits, upper- and lower-case letters and so on. If the
// -- expected and actual outputs EXACTLY match, then the test case passed so
// -- write PASS here. If there is any mismatch, no matter how minor, then the
// -- test case failed, so write FAIL here. When the test cases fail, you must
// -- determine why and correct the problem. It will either be due to a bug in
// -- your program, or it will be due to a mistake in your test case.
// PASS
//
// -----------------------------------------------------------------------------
// TEST CASE 2
//
// ... and so on for TEST CASE 8
//******************************************************************************
#include <cmath>     // For sqrt()
#include <cstdlib>   // For exit()
#include <fstream>   // For ifstream and ofstream classes
#include <iomanip>   // For setprecision()
#include <iostream>  // For fixed and endl

//==============================================================================
// NAMED CONSTANTS
//==============================================================================
// Define two named constants: ADD is an int and is equivalent to 1. SUB is an
// int and is equivalent to -1. These constants are used when calling
// calc_real_root(). Remember, the quadratic formula calculates the first root
//  using -b + ... in the numerator of the forumla, and it calculates the second
// root using -b - ... in the numerator. So, when we want to calculate the first
// root, we pass ADD as the argument and when we want to calculate the second
// root, we pass SUB as the argument. This permits us to just have one function
// that calculates both roots and we alter the behavior of the function by
// passing in this argument (which is named add_sub in the function header).
//
// Contrast the way I am calculating the two real roots in Lab 6 using one
// function versus the way we calculates the two real roots in Lab 4 using
// using two functions.
int ADD;  // Pass as the argument when calculating the root: -b + ...
int SUB;    // Pass as the argument when calculating the root: -b - ...

using namespace std;

//==============================================================================
// FUNCTION DEFINITIONS
//==============================================================================

//------------------------------------------------------------------------------
// calc_complex_root()
//
// This function calculates one of the complex roots of the quadratic equation
// ax^2 + bx + c = 0 using the (-b + ...) / 2a equation. See the Notes about
// quadratic equations and complex roots in the header comment block regarding
// the value of the second root.
//
// Note: make sure to write the required & when defining double& real and
// double& imaginary. See the comments in the header comment block which
// explains this is in a bit more detail. Because of the &, the values that
// we assign to 'real' and 'imaginary' will be returned from this function
// and assigned to the corresponding arguments in the function call.
//
// Pseudocode:
// function calc_complex_root(a, b, c, disc, real, imaginary) returns nothing
//     denom <= 2a
//     real <= -b / denom
//     imaginary <= sqrt(-disc) / denom  -- Why do we negate disc?
// end function
//------------------------------------------------------------------------------
double Calc_complex_root(a,b,c,disc,real,imaginary)
{
    double demon;
    double& real;
    double& imaginary;
    denom <= 2a;
    real <= -b/denom;
    imaginary <= sqrt(-disc)/denom
    return()

}

//------------------------------------------------------------------------------
// calc_real_root()
//
// This function calculates one of the real roots of the quadratic equation
// ax^2 + bx + c = 0. Which root we calculate is specified by the add_sub
// parameter. If add_sub is ADD we are calculating the root: -b + ... If
// add_sub is SUB we are calculating the root: -b - ...
//
// Pseudocode:
// function calc_real_root(a, b, c, disc, add_sub) returns double
//     denom <= 2a
//     sqrt_term <= square root(disc)
//     if (add_sub is ADD) then
//         numer <= -b + sqrt_term
//     else -- add_sub must be SUB
//         numer <= -b - sqrt_term
//     end if
//     return numer / denom
// end function
//
// Question: Why do you think I am defining sqrt_term and assigning it the
// value of square root of the discriminant. Why not just write:
//
//     numerator = -b + square root(disc)
//
// and
//
//     denominator = -b - square root(disc)
//
// Hint 1: How much time does it take to calculate the square root of a number?
// Hint 2: I dunno, but it is > 0 secs
//------------------------------------------------------------------------------
double calc_real_root(a, b, c, disc, add_sub)
{
    double demon;
    sqrt_term <= sqrt(disc);
    if (add_sub = ADD)
    {
        numer <= -b + sqrt_term;
        else
        {
            numer <= -b - sqrt_term;
        }
    }
    return(numer/denom);
}

//------------------------------------------------------------------------------
// did_open_input_file(ifstream& fin)
//
// Checks to see if we successfully opened the file input stream for reading.
// We know if we did not, because in a conditional expression, fin will be
// false if the file did not open. If fin is false, we display an error message
// and terminate the program.
//
// function did_open_input_file(ifstream& fin)
//     if (!fin) then -- fin is false
//         send to cout: "Could not open 'coeffs.txt' for reading. Program is "
//         send to cout: "terminating now."
//         end this line of output
//         exit(-2)  - negative exit codes are use to indicate failure
//     end if
// end function
//------------------------------------------------------------------------------
void did_open_input_file(ifstream& fin)
{
    if (!fin) {
        cout << "Could not open 'coeffs.txt' for reading. Program is ";
        cout << "terminating now." << endl;
        exit(-2);
    }
}

//------------------------------------------------------------------------------
// did_open_output_file(ofstream& fout)
//
// Checks to see if we successfully opened the file output stream for writing.
// We know if we did not, because in a conditional expression, fout will be
// false if the file did not open. If fout is false, we display an error message
// and terminate the program.
//
// function did_open_output_file(ofstream& fout)
//     if (!fout) then -- fout is false
//         send to cout: "Could not open 'roots.txt' for writing. Program is "
//         send to cout: "terminating now."
//         end this line of output
//         exit(-3)  - negative exit codes are use to indicate failure
//     end if
// end function
//------------------------------------------------------------------------------
void did_open_input_file(ofstream& fin)
{
    if (!fout) {
        cout << "Could not open 'roots.txt' for writing. Program is ";
        cout << "terminating now." << endl;
        exit(-3);
    }
}


//------------------------------------------------------------------------------
// discriminant()
//
// Calculates and returns the discriminant of a quadratic equation based on the
// coefficients a, b, and c.
//
// Pseudcode not provided; if you need pseudocode for this function at this
// point in the course, well, truthfully, you're not in great shape.
//------------------------------------------------------------------------------
double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

//------------------------------------------------------------------------------
// output_complex_number()
//
// Outputs the real and imaginary parts of a complex number. For example,
// if our complex number is 12.3456789897 - 5.12346789i then 'real' is
// 12.3456789897 and 'imaginary' is -5.12346789. The output shall be (note that
// we are outputting real numbers with 5 digits after the decimal point):
//
//     12.34568 - 5.12347i
//
// Note how the 5th decimal digit is rounded up. This is the default behavior
// of an output stream. I think there is way to configure the stream to NOT
// round up but we don't wanna do that so its good that I don't know how to.
//
// Pseudocode:
// function output_complex_number(fout, real, imaginary) returns nothing
//     -- For real we have two cases to handle:
//     -- 1. real is zero: we skip outputting it.
//     -- 2. real is nonzero: we output real.
//     if (real is not 0) then
//         send to fout: real
//     end if
//
//     -- Next, for imaginary we have three cases to handle. Note that imaginary
//     -- cannot be 0 or we would not be dealing with a complex number.
//     -- 1. real is zero: then we output imaginary followed by "i'.
//     -- 2. real is nonzero and imaginary is negative: we output " - "
//           followed by -imaginary followed by "i'.
//     -- 3. real is nonzero and imaginary is positive: we output " + "
//           followed by imaginary followed by "i'.
//     if (real is 0) then
//        send to fout: imaginary
//     else if (imaginary < 0) then
//        send to fout: " - " followed by -imaginary
//     else if (imaginary > 0) {
//        send to fout: " + " followed by imaginary
//     end if
//     send to fout: "i"  -- I love driving EE's crazy :)
// end function
//------------------------------------------------------------------------------
void out_complex_number (fout, real, imaginary)
{
    if (real!=0){
        fout(real);
    }
    if (real=0){
        fout(imaginary);
    }
    else{
        if (imaginary<0){
            fout("-" -imaginary);
        }
        if (imaginary>0){
            fout("+" imaginary);
        }
    }

}

//------------------------------------------------------------------------------
// output_complex_roots()
//
// Outputs the two complex roots of a quadratic equation. Note that fout has
// already been configured to output real numbers with 5 decimal digits.
// See the note in the header comment block about the complex roots being
// complex conjugates.
//
// Pseudocode:
// function output_complex_roots(fout, real, imag)
//     send to fout: " has two complex roots: root1 = "
//     output_complex_number(fout, real, imag)
//     send to fout: " and root2 = "
//     output_complex_number(fout, real, -imag2)
//     end this line of output
// end function
//------------------------------------------------------------------------------
void output_complex_roots(fout, real, imag)
{
    fout >> "has two complex roots: root1 = ";
    output_complex_number(fout, real, imag);
    fout >> " and root2 = ";
    out_complex_number(fout, real, -imag2)>>endl;
}

//------------------------------------------------------------------------------
// output_quad_eqn()
//
// This function outputs the formatted quadratic equation as described in the
// lab project document.
//
// Note: The output stream fout, which writes to "roots.txt" has already been
// opened when this function is called. This function must not close fout.
// fout has already been configured to output real numbers with 5 digits after
// the decimal point.
//
// Pseudocode:
// function output_quad_rn(fout, a, b, c) returns nothing
//     send to fout: "The equation p(x) = "
//
//     -- Output the x^2 term. Note first that coefficient a cannot be 0 because
//     -- if it were, then p(x) would not be a quadratic equation and we would
//     -- have terminated the program when verify_quad_eqn() was called. Next,
//     -- for 'a', we have three cases to handle:
//     -- 1. a is 1: we just output "x^2" without printing 1.00000 in
//     --    front of "x^2".
//     -- 2. a is -1: we just output "-x^2" without printing -1.00000 in
//     --    front of "x^2".
//     -- 3. Otherwise, a is not 0, not 1, and not -1: so we just print 'a'
//     --    followed by "x^2".
//     if (a is 1) then
//         send to fout: "x^2"
//     else if (a is -1) then
//         send to fout: "-x^2"
//     else
//         send to fout: a followed by "x^2"
//     end if
//
//     -- Output the x term. Unlike coefficient a, coefficients b and c can be
//     -- 0 so we have to check for those cases. For b, we have four cases to
//     -- handle:
//     -- 1. b is 1: we should not output b but just output " + x"
//     -- 2. b is -1: we should not output b but just output " - x"
//     -- 3. b is < 0: we should output " - " followed by -b "x"
//     -- 4. b is > 0: we should output " + " followed by b "x"
//     if (b is 1) then
//         send to fout: " + "
//     else if (b is -1) then
//         send to fout: " - "
//     else if (b < 0) then
//         send to fout: " - " followed by -b
//     else if (b > 0) then
//         send to fout: " + " followed by b
//     endif
//     sent to fout: "x"
//
//     -- Output the constant term. c can be 0. We have three cases to handle
//     -- for c:
//     -- 1. c < 0: we should output " - " followed by -c.
//     -- 2. c > 0: we should output " + " followed by c.
//     -- 3. c is 0: we should skip outputting the plus or minus operator and
//     --    the value of c, i.e., we output nothing.
//     if (c < 0) then
//         send to fout: " - " followed by -c
//     else if (c > 0) then
//         send to fout: " + " followed by c
//     end if
//
//     -- We just output p(x) which is a homogeneous equation so now output
//     -- the " = 0" part.
//     send to fout: " = 0"
// end function
//------------------------------------------------------------------------------
???

//------------------------------------------------------------------------------
// output_real_roots()
//
// Outputs the two real roots of the quadratic equation. We have two cases to
// handle: (1) if root1 equals root2 then we have only one repeated root, so we
// output the root and tell the user that this is a repeated root. (2) when
// root1 does not equal root2, we have two different roots, so we output both
// roots and tell the user that there are two real roots.
//
// Pseudocode:
// function output_real_roots(fout, root1, root2) returns nothing
//     -- Check for one repeated root.
//     if (root1 is root2) then
//         send to fout: " has one repeated root = " followed by root1
//     else -- there are two real roots
//         send to fout: " has two real roots: root1 = " followed by root1
//         send to fout: " and root2 = " followed by root2
//     end if
//     end this output line
// end function
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// read_coeff()
//
// Reads just a single coefficient from the file input stream fin and returns
// the coefficient as a double. Note that on input, fin is open, and fin should
// not be closed in this function.
//
// Note: See Lab Project 4.
//------------------------------------------------------------------------------
double read_coeff(ifstream& fin)
{
    double coeff;
    fin >> coeff;
    return coeff;
}

//------------------------------------------------------------------------------
// verify_quad_eqn()
//
// This function is called from main() after we have read the three coefficients
// and closed the input file. It checks that the coefficient of the x^2 term
// i.e., coefficient 'a', is 0 or not 0. If 'a' is 0 then we do not have a
// quadratic equation so we will send an error message to the output file
// 'roots.txt' and then end the program with an exit code of -1.
//
// Pseudocode:
// function verify_quad_eqn(fout, a) returns nothing
//     if (a is 0) then
//         send to fout: "The coefficient for the x^2 term is zero so this is "
//         send to fout: "not a quadratic equation. Please change the value "
//         send to fout: "of this coefficient and try again. Exiting the "
//         send to fout: "program now."
//         end this line of output
//         exit(-1)
//     end if
// end function
//------------------------------------------------------------------------------
void verify_quad_egn(fout, a)
{
    ofstream fout;
    if (a=0)
    {
        fout.open("");
        fout << "The coefficient for the x^2 term is zero so this is ";
        fout << "not a quadratic equation. Please change the value ";
        fout << "of this coefficient and try again. Exiting the ";
        fout << "program now." << endl;
        fout.close("");
    }

}

//------------------------------------------------------------------------------
// main()
//
// Pseudocode:
// function main() returns int value 0
//     Define two double variables to store the real roots: root1, root2
//     Define two double variables to store the real and imaginary
//         parts of a complex root: real, imaginary
//
//     Define input file stream object fin and open "coeffs.txt" for reading
//
//     -- Call did_open_input_file(fin) to verify that fin was successfully
//     -- opened.
//     did_open_input_file(fin)
//
//     -- did_open_input_file() does not return if fin did not open so if we
//     -- get here we know that we can read the roots.
//
//     Define a as double and then a <= read_coeff(fin)
//     Define b as double and then b <= read_coeff(fin)
//     Define c as double and then c <= read_coeff(fin)
//
//     Close the file input stream 'fin'
//
//     -- Verify that we have a quadratic equation. If coefficient 'a' is 0,
//     -- verify_quad_eqn() will display an error message on the output window
//     -- and then terminate the program.
//     verify_quad_eqn(fout, a)
//
//     -- If we return from verify_quad_eqn() then coefficient a is not 0 and
//     -- we can now solve the equation.
//
//     Define output file stream object fout and open "roots.txt" for writing
//
//     -- Call did_open_output_file(fout) to verify that fout was successfully
//     -- opened
//     did_open_output_file(fout)
//
//     -- did_open_output_file() does not return if fout did not open so if we
//     -- get here we know that we can write out the equation and roots.
//
//     Config fout to format real numbers with 5 decimal digits
//
//     -- Send the quadratic equation to the output file.
//     output_quad_eqn(fout, a, b, c)
//
//     -- Calculate the discriminant of a, b, and c, and store the value in a
//     -- double variable named 'disc'.
//     disc <= discriminant(a, b, c)
//
//     -- If the discriminant is 0 then we have only one repeated root. Call
//     -- calc_real_root() and store the return value in root1. Then call
//     -- output_real_roots() to display the repeated root. Note the last
//     -- argument in the output_real_roots() function call.
//     if (disc is 0) then
//         root1 <= calc_real_root(a, b, c, disc, ADD)
//         output_real_roots(fout, root1, root1)

//     -- Else if the discriminant is greater than 0 then we have two real roots
//     -- so call calc_real_root() twice to get the two roots and then call
//     -- output_real_roots() to display the two roots.
//     else if (disc > 0) then
//         root1 <= calc_real_root(a, b, c, disc, ADD)
//         root2 <= calc_real_root(a, b, c, disc, SUB)
//         output_real_roots(fout, root1, root2)
//
//     -- Else, if we reach this point, the discriminant is less than 0
//     -- indicating that we have two complex roots. Call calc_complex_root()
//     -- once to get the 'real' and 'imaginary' parts of the root that comes
//     -- from calculating (-b + ...). Because complex roots are complex
//     -- conjugates, the second root will be 'real' and '-imaginary'. Then we
//     -- call output_complex_roots() once which will output the two complex
//     -- roots.
//     else then
//         calc_complex_root(a, b, c, disc, real, imaginary)
//         -- upon return, real + imaginary 'i' is the first root and
//         -- real + -imaginary 'i' is the second root.
//         output_complex_roots(fout, real, imaginary)
//     end if
//     close the file output stream
//     return 0 to indicate the program finished successfully
// end function
//------------------------------------------------------------------------------
// ???
int main()
{
    // Define doubles root1, root2, real, imaginary
    double(root1, root2, real, imaginary);

    // Open coeffs.txt for reading. Call did_open_input_file() to check if
    // fin was opened. did_open_input_file() does not return if coeffs.txt
    // could not be opened. What it will do is: send an error message to cout
    // (the output window) and then terminate the program with an exit code
    // of -2.
    ifstream fin("coeffs.txt");
    did_open_input_file(fin);

	// So, if get to here then we know coeffs.txt was successfully opened.
	// Read the coefficients.
    double a = read_coeff(fin);
    double b = read_coeff(fin);
    double c = read_coeff(fin);

	// And we're done reading, so close the input file.
    fin.close();

    // Open roots.txt for writing.
    ofstream fout("roots.txt")

    // Call did_open_output_file() to check if the output file was successfully
    // opened for writing.
    did_open_output_file(fout);

    // If we get to this point, the output file was opened so config fout to
    // output real numbers in fixed notation with 5 digits after the decimal
    // point.
    fout << fixed << setprecision(5);

    // Call verify_quad_eqn() to verify that our coefficients actually make
    // a quadratic equation.
    verify_quad_eqn(fout, a);

    // If we get to this point, then we have a legal quadratic equation so
    // send the equation to the output file.
    output_quad_eqn(fout, a, b, c);

	// Calculate the discriminant.
    double disc = discriminant(a, b, c);

    // Check and handle the case when disc is 0 (one real repeated root)
    ???

    // Check and handle the case when disc is > 0 (two real roots)
    ???

    // Check and handle the case when disc is < 0 (two complex roots)
    ???

    // We are done with the output file so close it and return 0 from main
    // to indicate that the program finished successfully.
}
