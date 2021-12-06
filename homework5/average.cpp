/*
    PIC 10A Homework 5, average.cpp
    Author: Megan Ma and W. Chu
    Date: 11/9/2021
 
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

/* Promotes user to input grades and stores them in vars.
@param hw: pass by reference vector that stores hw grades
@param vector: pass by reference vector that stores exam grades
@param participation: pass by reference double that stores participation grade
@return 0
*/
int read_grades(vector<double>& hw, vector<double>& exam, double& participation){
    //save user input to the hw vector
    cout << "Please enter homework grades 0-100: ";
    cin >> hw[0] >> hw[1] >> hw[2] >> hw[3] >> hw[4] >> hw[5] >> hw[6] >> hw[7];
    //save user input to the exam vector
    cout << "Please enter exam grades 0-100: ";
    cin >> exam[0] >> exam[1];
    //save user input to paricipation variable
    cout << "Please enter participation grade 0-100: ";
    cin >> participation;
    
    return 0;
}

/* Return average grade using Scheme 1 and Scheme 2. Also print all grade items on console (including which grades are dropped)
@param hw: pass by reference vector that stores hw grades
@param vector: pass by reference vector that stores exam grades
@param participation: pass by reference double that stores participation grade
@return: lowest average grade scheme
*/
double compute_average(vector<double>& hw, vector<double>& exam, double& participation){
    // find the two lowest hw grades to drop
    
    //initialize vars to hold the indices of the two lowest hw grades
    double lowest1 = 0;
    double lowest2 = 1;
    
    //loop through the values in hw
    for(int i = 0; i < hw.size(); i++){
        if(hw[i] < hw[lowest1] && hw[i] < hw[lowest2]){
            //if curent value is less than the values at indices lowest1 and lowest2
            //replace lowest1 with current index
            lowest1 = i;
        }else if(hw[i] < hw[lowest1]){
            //if curent value is less than the value at index lowest1
            //replace lowest1 with current index
            lowest1 = i;
        }else if(hw[i] < hw[lowest2]){
            //if curent value is less than the value at index lowest1
            //replace lowest1 with current index
            lowest2 = i;
        }else{
            //keep current lowest values
            lowest1 = lowest1;
            lowest2 = lowest2;
        }
    }
    

    //compute the average hw score after dropping the two lowest scores
    
    //initialize variables to store sum and average of hw scores after dropping the lowest 2 scores
    double hw_sum = 0;
    double hw_average;
    //loop through hw and add up values (except for two lowest scores)
    for(int i = 0; i < hw.size(); i++){
        if((i != lowest1) && (i != lowest2)){
            hw_sum = hw_sum + hw[i];
        }
    }
    
    hw_average = hw_sum/6; //divide hwsum by 6 to get the average hw score
    
    // compute the average for scheme 1 and store in variable scheme 1
    double scheme1 = (0.7*hw_average)+(0.09*exam[0])+(0.2*exam[1])+(0.01*participation);
    
    // compute the average for scheme 2
    double scheme2 = (0.7*hw_average)+(0.29*exam[1])+(0.01*participation);
    
    if(scheme1 > scheme2){
        //scheme1 is the higher average, print all grade items including 2 dropped lowest grades
        
        //loop through and print hw exams )
        for(int i = 0; i < hw.size(); i++){
            if((i == lowest1) || (i == lowest2)){
                //print dropped if hw[i] is a dropped homework
                cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << " (Dropped)" << endl;
            }else{
                cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << endl;
            }
        }
        cout << setw(13) << right << "Midterm Exam" << setw(8) << exam[0] << endl;
        cout << setw(13) << right << "Final Exam" << setw(8) << exam[1] << endl;
        cout << setw(13) << right << "Participation" << setw(8) << participation << endl;
        
        return scheme1;
    }else{
        //scheme2 is the higher average, print all grade items including 2 dropped lowest grades and dropped midterm grade
        //loop through and print hw exams
        for(int i = 0; i < hw.size(); i++){
            if((i == lowest1) || (i == lowest2)){
                //print dropped if hw[i] is a dropped homework
                cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << " (Dropped)" << endl;
            }else{
                cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << endl;
            }
        }
        cout << setw(13) << right << "Midterm Exam" << setw(8) << exam[0] << " (Dropped in Scheme II)" << endl;
        cout << setw(13) << right << "Final Exam" << setw(8) << exam[1] << endl;
        cout << setw(13) << right << "Participation" << setw(8) << participation << endl;
        
        return scheme2;
    }
}



/*
    Compute the average grade based on PIC10A true syllabus grading schemes
    Coded by W. Chu, Nov 3, 2021
*/

int main()
{
    // declare containers for different grade items
    vector<double> hw(8);
    vector<double> exam(2); // contains midterm and final
    double participation;
    
    // read grades from user
    read_grades(hw, exam, participation);

    // compute average based on the grading scheme
    // print items to the console, including dropped situation
    double average = compute_average(hw, exam, participation);

    // output average grade
    cout << "The average grade is " << average << "." << endl;

    return 0;
}



