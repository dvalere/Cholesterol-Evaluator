#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
void evaluate_cholesterol(int, int, string&, string&);
void evaluate_blood_pressure(int, int, string&, string&);
float ratio_cal(int x, int y);
// Declaring function prototypes and including dictionaries

int main()
{
    int numbah;
    // Setting up variables 
    cout << "Enter the number of patient records:" << endl;
    cin >> numbah;
    /* Asking the person how many people's records they want to see, so the program can show them how many they choose. 
    numbah is the amount they choose. */

    ifstream myFile;
    string path = "infile.txt";
    myFile.open(path);
    // Opening the file so we can get the data

    for (int counter=1; counter<=numbah; counter++){
        string name;
        string status;
        int visits;
        myFile >> name >> status >> visits;
        /* Setting variables. Name is for the name of the patient. Status is to show if they're a current patient(C),
        a new patient(N), a referral(F), or a returning patient(R)
        */
       
        cout << "Current Patient's Name- " << name << endl << endl;
        for (int countertwo=1; countertwo<=visits; countertwo++){
            int HDL;
            int LDL;
            int systolic;
            int diastolic;
            myFile >> HDL >> LDL >> systolic >> diastolic;
            /* Creating variables for the numbers in the data. Using >> will set each variable to the number that
            matches their position on the line. So HDL is the 1st number, LDL is the 2nd number, systolic is the 3rd,
            diastolic is the 4th */

            cout << "DATA SET " << countertwo << endl;
            cout << evaluate_cholesterol(HDL, LDL);
            cout << evaluate_blood_pressure(systolic, diastolic) << endl << endl;
            // Calling the functions to evaluate cholesterol and blood pressure, and print the results.
        }
    myFile.close();
    }
    return 0;
}


// -------------------------------------------------------------------------------------------------------
float ratio_cal(int x, int y){
    float ratiovalue = x / y;
    return ratiovalue;
}
// A function to divide HDL by LDL, which is how you get the ratio.

void evaluate_cholesterol(int, int, string&, string&){

}



void evaluate_blood_pressure(int, int, string&, string&){

}
