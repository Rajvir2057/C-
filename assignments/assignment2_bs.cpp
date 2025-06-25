#include <iostream>
#include <array>
#include <random>

enum CardType {
    Ace = 1,
    Two = 2, 
    Three = 3,
    Four = 4, 
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8, 
    Nine = 9, 
    Ten = 10,
    King = 11, 
    Queen= 12,
    Jack = 13   
};
std::array<std::string, 14> cardsnames = {"", "Ace", "Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","King","Queen","Jack"};

// declaring functions..
void menufunction(); // exit.rules.play game
void deduct_wager(); // deducting the money
int players_turn(); // code for the player
int dealers_turn(int sum_of_player, CardType rolldealer_shown, CardType rolldealer_not_shown);// code for computer.
bool game_winning_result(int sum_player_points, int sum_dealers_points); 
CardType get_card();
int cardspoints(CardType);

int dollars = 500;

//main function for working stuff..
int main(){

    std :: cout << "You start with : " << "$" <<dollars << '\n';
    
    deduct_wager();

    int sum_of_player = 0;
    int sum_dealers_points = 0;

    // ---------
    CardType rolldealer_shown =  get_card();
    CardType rolldealer_not_shown =  get_card();

    int sum_dealer_points = cardspoints(rolldealer_shown) + cardspoints(rolldealer_not_shown);

    std :: cout << "Dealer got " << cardsnames[rolldealer_shown] << " & " << " * " << ", sum is " << sum_of_player << '\n';
    // ---------

    while(!((sum_of_player > 21) || (sum_dealers_points > 21))) {
        sum_of_player = players_turn();
        std :: cout << '\n';

        if (sum_of_player > 21 || sum_dealers_points > 21) {
            break;
        }
        sum_dealers_points = dealers_turn(sum_of_player, rolldealer_not_shown, rolldealer_not_shown);
        std :: cout << '\n';

        if (game_winning_result(sum_of_player, sum_dealers_points)) {
            break;
        }
    }

}


CardType get_card() {
    //random..
    std :: random_device d;
    std :: default_random_engine el (d());
    std :: uniform_int_distribution <int> dice13(1,13);

    return static_cast <CardType> (dice13(el));


}
//defining the functions 
void deduct_wager(){
    // declare money.
    int wager;

    do{
        std:: cout << "Enter the wager amount: " << '\n';
        std ::cin >> wager;

        if(wager >= 500){
            std :: cout << "Enter amount lower than 500\n";
        }else if (wager < 50){
            std :: cout << "Enter amount more than 50 dollars\n";
        }
    }while(wager >= 500 || wager < 50);

    dollars -= wager;
    std :: cout << "You have used this to bet " << wager << " now u have :"<<  dollars << '\n';

}
int players_turn(){

   std :: string useranswer;
   CardType roll1 = get_card();
   CardType roll2 = get_card();
   CardType rollend = get_card();

   int sum_of_player = cardspoints(roll1) + cardspoints(roll2);

   std :: cout << "You got " << cardsnames[roll1] << " & " << cardsnames[roll2] << ", sum is " << sum_of_player << '\n';

    if (roll1 == CardType::Ace && roll2 == CardType::Ace) {
        std :: cout << "Player wins";
        return sum_of_player;
    }

   // placing the if statements to determine bust, hit , stand..
    
   if(sum_of_player < 21 ){

        std :: cout << "Do you want to hit or stand? \n";
        std :: cin >> useranswer;

        if(useranswer == "Hit" || useranswer == "hit") {
            cardspoints(rollend);
            std :: cout << "New sum will be: " << sum_of_player + rollend << '\n';

        }else if (useranswer == "Stand" || useranswer == "stand"){
            std :: cout << "Your sum wont change and you still have: " << sum_of_player << '\n';
        }else{
            std ::  cout << "Please enter a valid answer.\n";
        }
   }else if (sum_of_player == 21){
    std :: cout << "Blackjack.. you win. Congs...\n";
   }else if (sum_of_player > 21){
    std :: cout << "Bust. you lost Bambi for you...\n";
   }

   return sum_of_player;
}
int dealer_hit(int sum_of_player, CardType rolldealer_shown, CardType rolldealer_not_shown){

    

    if (sum_dealer_points > 21 ){
        std :: cout << "The house bust.. Player wins the game.\n";
    }else if (sum_dealer_points == 21 ){
        std :: cout << "Dealer wins the game .." << '\n';
    }else if (sum_dealer_points == sum_of_player){
        std :: cout << "Its a tie..." << '\n';
    }

    return sum_dealer_points;
    
}

bool game_winning_result(int sum_player_points, int sum_dealers_points){
    if (sum_player_points <= 21 && sum_dealers_points <= 21) {
        if (sum_player_points > sum_dealers_points) {
            std :: cout << "The house bust.. Player wins the game.\n";
        }else if (sum_dealers_points > sum_player_points){
            std :: cout << "Dealer wins the game .." << '\n';
        }else {
            std :: cout << "Its a tie..." << '\n';
        }
    }
    return true;
}
     
void menufunction(){
    // declare here
    int options;

    switch (options){
        case 1:
            std :: cout << "Rules" << '\n';
            break;
        case 2: 
            std :: cout << "Play" << '\n';
            break;
        case 3:
            std :: cout << "Exit" << '\n';
            break;
        default:
            break;
    }
    std :: cout << "Select the options.";
    std :: cin >> options;
}

int cardspoints(CardType cards){
    
    switch(cards){
        case Ace:
            return 11;
        case Two:
            return 2;
        case Three:
            return 3;
        case Four:
            return 4;
        case Five:
            return 5;
        case Six:
            return 6;
        case Seven:
            return 7;
        case Eight:
            return 8;
        case Nine:
            return 9;
        case Ten:
        case King:
        case Queen:
        case Jack:
            return 10;

    }
}