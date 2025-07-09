#include <iostream>
#include <random>
#include <string>
#include <iomanip>
//. 5 chances for user , hit or miss, total ships hit.

//decalring functions..
void original_game_board(char board[8][8]);
void printing_the_board(char board[8][8]);
void random_ships(char board[8][8], bool revealships = false);
bool hit_and_miss(char board[8][8] ,int row ,int colmn);

void original_game_board(char board[8][8]){
//giving water to the board.
    for(char i =0 ; i < 8; i++){
        for(char j = 0 ; j< 8; j++){
            board[i][j] = '~';
        }
        
    }
}

void printing_the_board(char board[8][8]){
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
            std :: cout << std :: setw(2) << board[i][j];
            
        }
        std :: cout << '\n';
    }
}

void random_ships(char board[8][8] ,bool revealships){

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

    if(revealships == false){
        for(int i = 0; i < 8; i++){
            for(int j =0 ; j <8 ; j++){
                if(board[i][j] =='S'){
                    board[i][j] = '~';
                }
            }
        }
    }


}
int main(){
    //printing for now..
    char board[8][8];

    std :: cout << "\tWELCOME TO THE SHIP GAME." << '\n' << "This is the board you have to guess from." << '\n';

    original_game_board(board);
    random_ships(board , true );
    printing_the_board(board);


return 0;
}