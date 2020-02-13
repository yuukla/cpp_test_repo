////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//@zeklaus
//February 7, 2020
//help corbo not fail his class
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//include libraries here
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <iostream>

using namespace std;
void setTestScores (int* x, int* y){

  cout << "Test 1 score: ";
  cin >> *x;

  cout << "Test 2 score: ";
  cin >> *y;
}

double testScoreLogic (int x, int y){
  //find average of a batch of test testscores
  double testAverage = (x+y)/2;
  return testAverage;
}
int main (void){

//declare variables
int test1, test2;
setTestScores(&test1, &test2);
testScoreLogic(test1, test2);
cout << test1 << " " << test2 << endl;
cout << testScoreLogic(test1, test2);

return 0;
}
