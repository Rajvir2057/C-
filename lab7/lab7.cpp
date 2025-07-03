#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    //creating a vector.

    std :: vector<int> numbers= {10,20,30,40,50}; // forming one.

    numbers.push_back(60); // adding to the end a number

    numbers.insert(numbers.begin() +2,25); // plus 2 here is the index where u want to add

    for(int num = 0 ; num < numbers.size(); num++){
        std :: cout << numbers[num] << ",";
    }

    // sorting the numbers..
    sort(numbers.begin(),numbers.end(), std:: greater<int>());

    // for loop to create the desending order.
    std :: cout << '\n';
    
    std :: cout << "Sorted vectors: ";
    for(int i : numbers){
        std :: cout << i << " ";

    }
     return 0;

}