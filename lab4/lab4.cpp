#include <iostream>
#include <fstream>
#include <cctype>   // Include cctype for character classification
#include <string>
using namespace std;

int main() {
    ifstream inStream;
    ofstream outStream;

    inStream.open("in.dat");
    if (inStream.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    outStream.open("out.dat");
    if (outStream.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    string number = "";   // To store each number as we extract them
    int sum = 0;
    char ch;

    // Read character by character from the file
    while (inStream.get(ch)) {
        if (isdigit(ch)) {
            number += ch; // If the character is a digit, add it to the number string
        }
        else if (ch == ',' || inStream.eof()) {
            if (!number.empty()) {
                sum += stoi(number);             // Convert string to int and add to sum
                outStream << number << "\n";     // Write number to file
                number = "";                     // Reset number string
            }
        }
    }

    // Handle the last number if the file does not end with a comma
    if (!number.empty()) {
        outStream << number << "\n";
        sum += stoi(number);
    }

    outStream << "The sum of the numbers are: " << sum;

    // Close the files
    inStream.close();
    outStream.close();

    return 0;
}
