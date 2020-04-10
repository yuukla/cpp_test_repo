/*------------------------------------------------------------
// AUTHOR: Corbett Hankins
// FILENAME: Lab08_Chankin2, Student.
// SPECIFICATION: your own description of the program.
// FOR: CSE 100- Lab #8
// TIME SPENT: how long it took you to complete the assignment.
//-----------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;


class Student
{
    // Declare the attributes of this class here.
    // Make sure you create the attributes as private variables.
    // -->
    private:
    string (studentMajor);
    string (firstName);
    string (lastName);
    int (studentCredits);
    int (studentPoints);

    // Define the methods/functions of this class below.
    // Make sure you define the functions as public so that the functions can be accessed outside this class.
    public:
    // ==================== Constructor 1 ====================

    void Student (string fName, string lName)
    {
        // write the segment of code that assigns fName and Lname to the instance
        // variables.
        // -->
        fName= string(firstName);
        lName= string(lastName);

        // The rest of variables are initialized to default values
        studentMajor = "General Studies";
        studentPoints = 0;
        studentCredits = 0;

    }

    // ==================== Constructor 2 ====================

    void Student (string major, int credits, int points, string fName, string lName)
    {
        // Write the segment of code
        // that assigns input data to the data members
        // -->

    }

    // ===============  Define the helper (get and set) functions below   ==================

    // Define a function getMajor() that takes no parameters
    // but returns the string stored in the attribute studentMajor
    // -->


    // Define a function getGradePoints() that takes no parameters
    // but returns the integer stored in the attribute studentPoints
    // -->

    // Define a function getCredits() that takes no parameters
    // but returns the integer stored in the attribute studentCredits
    // -->

    // Define a function getFullName() that takes no parameters
    // but returns the string stored in the attributes firstName and lastName combined together as one string
    // You must return a string that combines both names to form full name as firstName + " " + lastName.
    // -->

    // Define a function changeMajor() that takes one parameter which is a string called newMajor
    // and does not return anything.
    // Inside the function assign the 'studentMajor' attribute to the parameter passed to the function i.e. newMajor
    // studentMajor = newMajor;
    // -->

    // Define a function loopHelper() that takes three parameters start, end and incBy all of which are integers.
    // and does not return anything.
    // Inside the function using a loop construct
    // which computed the sum of the sequence of integers starting from start to end and incremented by the value incBy

    void loopHelper(int start, int end, int incBy)
    {
        // Declare a variable called sum to hold the value of the sum of the sequence
        // Initialize the value of sum to zero
        // -->

        // write your for loop below
        //for (int i = ??? ; i <= ???; i = ???)
        // -->

        // print the sum of the sequence starting from 'start' till 'end' with 'incBy' steps
        // -->

    }

}
