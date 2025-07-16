#include <iostream>
#include <random>
#include <string>
#include <iomanip>
//. 5 chances for user , hit or miss, total ships hit.

//decalring functions..
void original_game_board(char board[8][8]);
void printing_the_board(char board[8][8], bool revealships = false);
void random_ships(char board[8][8]);
bool hit_and_miss(char board[8][8] ,int row ,int colmn);

void original_game_board(char board[8][8]){
//giving water to the board.
    for(char i =0 ; i < 8; i++){
        for(char j = 0 ; j< 8; j++){
            board[i][j] = '~';
        }
        
    }
}

void printing_the_board(char board[8][8] ,bool revealships){
    //display like 1 to 8 

    std:: cout << std :: setw(2) << " ";
    for(int k = 1; k <= 8; ++k){
        std :: cout << std :: setw(2) << k;
    }

    std :: cout <<'\n';

    //now the board .

    for(int i=0 ; i < 8 ; i++ ){
        std :: cout << std :: setw(2) << i+1;
        for(int j =0 ; j < 8; j++){
            if(revealships == false && board[i][j] =='S'){
                std :: cout << std :: setw(2) << '~';
            } else {
                std :: cout << std :: setw(2) << board[i][j];
            }
        }
        std :: cout << '\n';
    }
}

void random_ships(char board[8][8]){

    //set up the random device to give s 
    std :: random_device ship;
    std :: default_random_engine rds (ship()); //rds i mean random distribution if ships 
    std :: uniform_int_distribution <int> give(0,7); // give i mean give that ship 

    int placing_ships = 0;
    int total = 20;

    while (placing_ships < total){
        // replacing water 
        int row= give(rds);
        int colmn= give(rds);

        if(board[row][colmn] == '~'){
            board[row][colmn] = 'S';
            placing_ships++;
        }
    }


}

bool hit_and_miss(char board[8][8], int row, int colmn) {
    return (board[row][colmn] == 'S');
}

bool players_turn(char board[8][8]) {
    int row, colmn;
    bool valid = false;

    // make sure player puts row / column correctly
    while (!valid) {
        std :: cout << "Choose row: ";
        std :: cin >> row;

        if (row >= 1 && row <= 8) {
            valid = true;
        } else {
            std :: cout << "Please enter a number between 1-8\n";
            continue;
        }

        std :: cout << "Choose column: ";
        std :: cin >> colmn;

        if (colmn >= 1 && colmn <= 8) {
            valid = true;
        } else {
            std :: cout << "Please enter a number between 1-8\n";
            valid = false;
        }
    }
    // subtract 1 because board is 1-8
    row--;
    colmn--;

    // check for hit and return true if hit
    if (hit_and_miss(board, row, colmn)) {
        board[row][colmn] = 'X';
        std :: cout << "Hit!" << std::endl;
        return true;
    } else {
        board[row][colmn] = 'O';
        std :: cout << "Miss!" << std::endl;
        return false;
    }
}

int main(){
    //printing for now..
    char board[8][8];

    std :: cout << "\tWELCOME TO THE SHIP GAME." << '\n' << "This is the board you have to guess from." << '\n';

    original_game_board(board);
    random_ships(board );
    printing_the_board(board);

    int hits = 0;
    for (int chances = 5; chances > 0; chances--) {
        std :: cout << "You have " << chances << " chances." << '\n';
        bool hit = players_turn(board);
        printing_the_board(board);

        if (hit) {
            hits++;
        }
        if (hits >= 3) {
            break;
        }
    }

    std :: cout << "Final board:\n";
    printing_the_board(board, true);
    if (hits >= 3) {
        std :: cout << "You have won the game.\n";
    } else {
        std :: cout << "Sorry, you lost, bambi for you.\n";
    }

return 0;
}