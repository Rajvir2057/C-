#include <iostream>
#include <random>
// 20 sticks game.. || kaur rajvir 816815

// https://cppreference.com/w/cpp/numeric/random.html
std :: random_device r;
std :: default_random_engine el (r());
std :: uniform_int_distribution <int> coinflip(0,1);

void display_rules(){
    std :: cout << "This is a simple game. If you follow the rules.\n"
                << "The objective is to remove sticks.\nYou start with 20 sticks.\nThe player who removes the last stick loses.\n\n";
}
void display_sticks(int sticks) {
    // show the number of sticks using the | symbol.
    std :: cout << "There are " << sticks << " sticks" << '\n';
    for (int i = 0; i < sticks ; i++){
        std :: cout << "|";
    }
    std::cout << "\n";
}
int getcomputernumber() {
    std :: uniform_int_distribution sticks_choice (1,3);
    return sticks_choice(el);
}
int computerinput(int sticks){
    int computer_choice = getcomputernumber();
    std :: cout << "Computer chose: " << computer_choice << '\n';
    return sticks - computer_choice;
}
int userinput(int sticks){
    //declare userchoice.
    int user_choice = 0;

    while (true) {
        // asking..
        std :: cout << "How many sticks do u want to remove from 1 to 3? ";
        std :: cin >> user_choice;

        //validation..
        if(user_choice > 3){
            std :: cout << "You can not pick more than this sorry.\n";
        } else if(user_choice < 1){
            std :: cout << "You can not pick less than this sorry.\n";
        } else if(sticks - user_choice < 0){
            std :: cout << "You must not go negative.\n";
        } else {
            return sticks - user_choice;
        }
    }
}

// returns 1 if computer is winner, returns 0 if human is winner
int playgame() {
    int sticks = 20;

    display_sticks(sticks);

    if (coinflip(el) == 1) {
        sticks = userinput(sticks);
    }
    std :: cout << "The game has started!\n";

    while (true) {
        /*
        1. If there are more than 4 sticks left, the computer should randomly
        generate the number (1-3).
        2. If there are 2 to 4 sticks left, then the computer should withdraw enough
        sticks to leave 1.
        3. If there is 1 stick left, then the computer must take it and loses.
        */
        if (sticks > 4){
            sticks = computerinput(sticks);
        } else if (sticks >= 2) {
            std :: cout << "Computer chose: " << (sticks - 1) << '\n';
            sticks = 1;
        } else {
            sticks = 0;
            return 0;
        }

        display_sticks(sticks);
        sticks = userinput(sticks);

        if (sticks == 0) {
            return 1;
        }


    }

}


// returns 1 when user picks exit. otherwise returns 0.
int menu() {
    // declaring..
    int menu;
    // menu for the game..
    std :: cout << "WELCOME TO THE GAME!\n"
                << "1. play game\n"
                << "2. show rules\n"
                << "3. exit\n";

    std::cin >> menu;

    int winner;
    switch (menu)
    {
    case 1:
        winner = playgame();
        std::cout << "Winner is: " << (winner == 1 ? "computer" : "human") << '\n';
        return 1;

    case 2:
        display_rules();
        break;

    case 3:
        return 1;
    default:
        break;
    }
    return 0;
}

bool askToPlayAgain(){
    std :: string answer;

    // repeat until the player answers correctly
    while (true) {
        std :: cout << "Do you want to play again? ";
        std :: cin >> answer;

        if (answer == "y" || answer == "yes") {
            return true;
        } else if (answer == "n" || answer == "no") {
            return false;
        } else {
            std :: cout << "You need to answer yes or no.\n";
        }
    }
}
int main(){
    while(true){
        if (menu() == 1) {
            break;
        }
    }
    if (askToPlayAgain()) {
        int winner = playgame();
        std::cout << "Winner is: " << (winner == 1 ? "computer" : "human") << '\n' ;
    }

    return 0;
    // 2 loops are required here.. one on keep playing till someone loses..
    // play again needs a loop.. random will be used to pick who well plasy first..
}
