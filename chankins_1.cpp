#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip.h>
#include <cmath>
#include <math.h>

using namespace std;

#DEFINE CM_PER_INCH 2.54
#DEFINE LB_PER_KG 2.20462262

//calc lucky function
double calc_lucky (int date, int month, int year, double weight, double height){
  int x, y, z, lucky;
  double foo;
  x = 100 * (pow(month, 2));
  y = 10 * (pow(date, 3));
  z = ((x + y)/year);
  foo = (pow(weight, 6)/height);
  lucky = static_cast<int>(z + (sqrt(foo)) mod 10) + 1;
  return lucky;
};

//convert inch_to_cm
double convert_inch_to_cm (double inches){
  return inches * CM_PER_INCH;
};

//convert lb_to_kg
double convert_lb_to_kg (double lbs){
  return (lbs / LB_PER_KG);
};

//get_int
int get_int (string prompt){
  int n;
  cout << prompt;
  cout << "Enter a numeric value! ";
  cin >> n;
  cout << endl << n <<;
  return n;
};

//get_string
string get_string (string prompt){
  string s;
  cout << "Prompt is " << prompt << endl;
  cin >> s;
  return s;
};

int main (void){
  int date, height_in, lucky, month, year, weight_lb;
  double height_cm, weight_kg;
  string name;

  cout << "Zelda's Lucky Number Calculator" << endl;
  name = get_string("What is your name?");
  month = get_int("In what month were your born?");
  date = get_int ("What was the date? ");
  year = get_int ("What was the year (yyyy)? ");
  height_in = get_int("What is your weight in lbs?");
  height_cm = convert_inch_to_cm(height_in);
  weight_kg = convert_lb_to_kg(weight_lb);
  lucky = calc_lucky(date, hieght_cm, month, weight_kg, year);
  cout << name << ", your lucky number is " << lucky << ". Thank you, that will be $25.";
  return 0;
}
