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
            string HDLreading;
            string LDLreading;
            string sysReading;
            string diaReading;
            myFile >> HDL >> LDL >> systolic >> diastolic;
            /* Creating variables for the numbers in the data. Using >> will set each variable to the number that
            matches their position on the line. So HDL is the 1st number, LDL is the 2nd number, systolic is the 3rd,
            diastolic is the 4th */

            cout << "DATA SET " << countertwo << endl;
            evaluate_cholesterol(HDL, LDL, HDLreading, LDLreading);
            evaluate_blood_pressure(systolic, diastolic, sysReading, diaReading);
            cout << endl << endl;
            // Calling the functions to evaluate cholesterol and blood pressure, and print the results.
            // The reading variables are to tell if the results are healthy or not.
        }
    }
    myFile.close();
    return 0;
}


// -------------------------------------------------------------------------------------------------------
float ratio_cal(int x, int y){
    float ratiovalue = (x / y);
    return ratiovalue;
}
// A function to divide HDL by LDL, which is how you get the ratio.

void evaluate_cholesterol(int hdl, int ldl, string&HDLreading, string&LDLreading){
    // print the title, which is the "Cholesterol Profile". 
    cout << "Cholesterol Profile" << endl;
    // prints the individual parts use in Cholesterol, which is HDL and LDL. 
    cout << "HDL: " << hdl << " LDL: " << ldl << endl;
    
    // prints the ratio of HDL and LDL
    cout << "Ratio: " << ratio_cal(hdl, ldl) << endl;
    
    //start to check the patient's HDL levels and see where it stands.
    if (hdl < 40){
        HDLreading = "Too low";
    }
    else if (hdl >= 40){
        if (hdl < 60){
            HDLreading = "Is okay";
        }
        else if (hdl >= 60){
            HDLreading = "Excellent";
        }
    }
    // after going through the nested if statement, it prints the HDl reading level
    cout << "HDL is " << HDLreading << endl;
    
    //Next, check the patient's LDL levels and see where it stands.
    if (ldl < 100){
        LDLreading = "Optimal";
    }
    else if ((ldl >=100) && (ldl < 130)){
        LDLreading = "Near Optimal";
    }
    else if ((ldl >= 130) && (ldl < 160)){
        LDLreading = "Borderline high";
    }
    else if (ldl >=160){
        if (ldl < 190){
            LDLreading = "High";
        }
        else if (ldl >= 190){
            LDLreading = "Very high";
        }
    }
    // Then, prints the LDL reading levels.
    cout << "LDL is " << LDLreading << endl;
    
    // check to see the ratio of HDL to LDL good or not.
    // prints the result of the restio of HDL to LDL reading.
    if ((hdl/ldl) > 0.3){
        cout << "Ratio of HDL to LDL is good" << endl;
    }
    else if ((hdl/ldl) <= 0.3){
        cout << "Ratio of HDL to LDL is not good" << endl;
    }
}



void evaluate_blood_pressure(int s, int d, string&sysReading, string&diaReading){
    cout << "Blood Pressure Profile" << endl;
    cout << "Systolic: " << s << "Diastolic: " << d << endl;
    // prints the systolic and diastolic values inputted by the user
    if (s<120){
        sysReading = "Optimal";
        }
    else if(s<130){
        sysReading = "Normal";
    }
    else if(s<140){
        sysReading = "High";
        }
    else if(s<160){
        sysReading = "Stage 1 Hypertension";
    }
    else if(s<180){
        sysReading = "Stage 2 Hypertension";
    }
    else if(s>=180){
        sysReading = "Stage 3 Hypertension";
    }
    if (d<80){
        diaReading = "Optimal";
    }
    else if (d<85){
        diaReading = "Normal";
    }
    else if (d<90) {
        diaReading = "High Normal";
    }
    else if (d<100) {
        diaReading = "Stage 1 Hypertension";
    }
    else if (d<110) {
        diaReading = "Stage 2 Hypertension";
    }
    else if(d>=110) {
        diaReading = "Stage 3 Hypertension";
    }
    cout << "Systolic reading is " << sysReading <<endl;
    cout << "Diastolic reading is " << diaReading << endl;
}
