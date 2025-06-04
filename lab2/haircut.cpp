#include <iostream>
/*
Kaur Rajvir 
816815*/
// creating a haircut game using basic if and else statements.
using namespace std;

int main() {
    // declaring the options.
    std::string gender;
    std::string answer;
    std::string answer2;
    std::string superhero;
    std::string super_villian;
    std::string steak;
    std::string sushi;
    std::string anime;
    std::string sitcom;

    // Asking using cout.. character output
    std::cout << "What is your gender? Male or Female?" << '\n';
    std::cin >> gender;

    // using if statements
    if (gender == "Male" || gender == "male") {
        // asking another question
        std::cout << "Are you a super hero or super villain?" << '\n';
        std::cin >> answer;

        if (answer == "superhero") {
            std::cout << "last question, Do like steak or sushi?" << '\n';
            std::cin >> answer2; 
            // last question with answer..
            if (answer2 == "sushi") {
                std::cout << "You should get a flattop :)" << '\n';
            } else if (answer2 == "steak") {
                std::cout << "You should get a flattop :)" << '\n';
            }
        } else if (answer == "supervillain") {
            std::cout << "You should get a Mohawk." << '\n';
        }

    } else if (gender == "Female" || gender == "female") {
        // asking another question
        std::cout << "Are you a super hero or super villain?" << '\n';
        std::cin >> answer;

        if (answer == "superhero") {
            std::cout << "last question, Do like anime or sitcom?" << '\n';
            std::cin >> answer2; 
            // last question with answer..
            if (answer2 == "anime") {
                std::cout << "You should get bangs :)" << '\n';
            } else if (answer2 == "sitcom") {
                std::cout << "You should get bobmale :)" << '\n';
            }
        } else if (answer == "supervillain") {
            std::cout << "You should get Mohawk." << '\n';
        }
    }

    return 0;
}

