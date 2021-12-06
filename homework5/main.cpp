/*
    Compute the average grade based on PIC10A true syllabus grading schemes
    Coded by W. Chu, Nov 3, 2021
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/*
 *
 * put all code here....
 *
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

