/*------------------------------------------------------------
// AUTHOR: your name.
// FILENAME: title of the source file.
// SPECIFICATION: your own description of the program.
// FOR: CSE 100- Lab #8
// TIME SPENT: how long it took you to complete the assignment.
//-----------------------------------------------------------*/

#include <iostream>
// Import the Student header file here
// -->

using namespace std;

int main()
{
    // Declare variables where you will store
    // inputs from user
    // -->

    // ==================== Test The Constructor 1 ====================

    // Prompt and ask the user for
    //
    //      firstName and lastName.
    //
    // of the first student. Store these inputs in the local variables
    // -->

    // Use the constructor 1 of Student with two arguments to create a
    // brand-new object called student1, by using firstName and lastName
    // -->

    // Display the information of student1
    //
    // Please use the object and methods to retrieve the information. Do NOT
    // use the local varibales in this main function.
    //
    // The message template, the <> part should be replaced by the data
    // in student1:
    //
    //      FIRST STUDENT INFORMATIONS
    //      The name of the student is: <student1's fullname>
    //      Major is: <student1's major>
    //      The student's number of points is: <student1's points>
    //      Number of earned credits is: <student1's credits>
    //
    // -->
    cout << "FIRST STUDENT INFORMATIONS " << endl;


    // ==================== Test The Constructor 2 ====================

    // Prompt and ask the user for
    //
    //      firstName, lastName, studentMajor, studentCredits,
    //      studentGradePoints,
    //
    // of the second student. Store these inputs in the local variables
    // -->

    // Use the constructor 2 of Student class, which has 5 parameters,
    // to create a brand-new object student2. Be careful of the order of
    // parameters.
    // -->

    // Display the information of student2
    //
    // Please use the object and methods to retrieve the information. Do NOT
    // use the local varibales in this main function.
    //
    // The message template, the <> part should be replaced by the data
    // in student2:
    //
    //      SECOND STUDENT INFORMATIONS
    //      The name of the student is: <student2's fullname>
    //      Major is: <student2's major>
    //      The student's number of points is: <student2's points>
    //      Number of earned a is: <student2's credits>
    //
    // -->
    cout << "SECOND STUDENT INFORMATIONS " << endl;


    // ==================== Test changeMajor ====================

    // Use the helper function "changeMajor" to change the student2's major to
    // "International Affairs". After that, print the message as follows:
    //
    //     <student2's fullname> has changed majors to International Affairs
    //
    // -->


    // ==================== Test The loopHelper ====================

    // The following code is used to test your helper function loopHelper.
    // You don't have to modify it.

    cout << "STUDENT HELPER FUNCTIONS" << endl;
    student1.loopHelper(1, 30, 3);
    student1.loopHelper(5, 28, 2);

    return 0;
}
