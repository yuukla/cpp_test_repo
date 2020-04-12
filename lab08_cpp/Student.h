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
      string studentMajor, firstName, lastName;
      int studentCredits, studentPoints;

    // Define the methods/functions of this class below.
    // Make sure you define the functions as public so that the functions can be accessed outside this class.
    // ==================== Constructor 1 ====================

  public void Student (string fName, string lName)
    {
        // write the segment of code that assigns fName and Lname to the instance
        // variables.
        // -->
        firstName = fName;
        lastName = lName;

        // The rest of variables are initialized to default values
        studentMajor = "General Studies";
        studentPoints = 0;
        studentCredits = 0;

    }

    // ==================== Constructor 2 ====================

  public void Student (string major, int credits, int points, string fName, string lName)
    {
        studentMajor = major;
        firstName= fName;
        lastName = lName;
        studentPoints = points;
        studentCredits = credits;

    }

    // ===============  Define the helper (get and set) functions below   ==================

    public string getMajor()
    {
      return studentMajor;
    }

    public int getGradePoints()
    {
      return studentPoints;
    }

    public int getCredits()
    {
      return studentCredits;
    }

    public string getFullName()
    {
      string fullName = firstName + " " + lastName;
      return fullName;
    }

    public void changeMajor(string newMajor)
    {
      studentMajor = newMajor;
    }

    public void loopHelper(int start, int end, int incBy)
    {
        int sum = 0;

        for (int i = start; i <= end; i + incBy)
        {
          cout i;
          sum = sum + i;
        }

        cout << "Iterate from " + start + " till " + end + " with " + incBy + " steps.";
    }
}
