#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int subject1, subject2, subject3;

    // Input
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter marks for subject 1: ";
    cin >> subject1;
    cout << "Enter marks for subject 2: ";
    cin >> subject2;
    cout << "Enter marks for subject 3: ";
    cin >> subject3;

    // Processing
    float total = subject1 + subject2 + subject3;
    float average = total / 3;
    char grade;

    if (average >= 90)
        grade = 'A';
    else if (average >= 80)
        grade = 'B';
    else if (average >= 70)
        grade = 'C';
    else if (average >= 60)
        grade = 'D';
    else
        grade = 'F';

    // Output
    cout << "\n----- Student Report -----" << endl;
    cout << "Name         : " << name << endl;
    cout << "Total Marks  : " << total << endl;
    cout << "Average      : " << average << endl;
    cout << "Grade        : " << grade << endl;

    return 0;
}
