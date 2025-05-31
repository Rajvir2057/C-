#include <iostream>
#include <random>
// 20 sticks game.. || kaur rajvir 816815

int main(){
    // declaring..
    int menu;
    // menu for the game..
    std :: cout << "WELCOME TO THE GAME!" << '\n';

    switch (menu)
    {
    case 1:
        std :: cout << "1. play game" << '\n';
        break; 

    case 2:
        std :: cout << "2. show rules" << '\n';
        break;

    case 3:
        std :: cout << "3. exit" << '\n';
        break;    
    default:
        break;
    }

    void display_rules(){
        std :: cout << "nothing" << '\n'; 
    }

    int getcomputerinput(){
        std :: cout << "nothing" << '\n';     
    }
    int userinput(){
        std :: cout << "nothing" << '\n';       
    }

    bool playagain(){
        std :: cout << "nothing" << '\n';
    }

    // 2 loops are required here.. one on keep playing till someone loses..
    // play again needs a loop.. random will be used to pick who well plasy first..

}