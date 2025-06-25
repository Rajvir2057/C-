#include <iostream>
#include <fstream>
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

CardType get_card() {
    //random..
    std :: random_device d;
    std :: default_random_engine el (d());
    std :: uniform_int_distribution <int> dice13(1,13);

    return static_cast <CardType> (dice13(el));


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

int dollars = 500;
int wager = 0;

void deduct_wager(){
    // declare money.

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
    std :: cout << "You have used this to bet " << wager << " now u have : $"<<  dollars << '\n';

}
CardType rolldealer_shown, rolldealer_not_shown;
CardType rollplayer_1, rollplayer_2;
int sum_dealer_points, sum_of_player;

// give the dealer's first cards
void dealer_cards(std::fstream &logfile) {
    rolldealer_shown =  get_card();
    rolldealer_not_shown =  get_card();

    sum_dealer_points = cardspoints(rolldealer_shown) + cardspoints(rolldealer_not_shown);

    std :: cout << "Dealer got " << cardsnames[rolldealer_shown] << " & " << " * ";
    logfile << "Dealer got " << cardsnames[rolldealer_shown] << " & " << " * ";
    std :: cout  << ", sum is " << sum_dealer_points << '\n';
    logfile << ", sum is " << sum_dealer_points << '\n';
}
// player first cards
void player_cards(std::fstream &logfile) {
   rollplayer_1 = get_card();
   rollplayer_2 = get_card();
   
   sum_of_player = cardspoints(rollplayer_1) + cardspoints(rollplayer_2);

   std :: cout << "You got " << cardsnames[rollplayer_1] << " & " << cardsnames[rollplayer_2] << ", sum is " << sum_of_player << '\n';
   logfile << "Player got " << cardsnames[rollplayer_1] << " & " << cardsnames[rollplayer_2] << ", sum is " << sum_of_player << '\n';

}

// function for dealer to hit
void dealer_hit(std::fstream &logfile) {
    CardType addedroll = get_card();
    sum_dealer_points += cardspoints(addedroll);

    std :: cout << "The new sum of the dealer will be : " << sum_dealer_points << '\n';  
    logfile << "The new sum of the dealer will be : " << sum_dealer_points << '\n';     
}
// function for player to hit
void player_hit(std::fstream &logfile) {
    CardType addedroll = get_card();
    sum_of_player += cardspoints(addedroll);
    
    std :: cout << "New sum will be: " << sum_of_player << '\n';
    logfile << "New sum will be: " << sum_of_player << '\n';
    
}
bool ask_player(std::fstream &logfile) { // true if player hits
    while (true) {
        std :: string useranswer;
        std :: cout << "Do you want to hit or stand? \n";
        std :: cin >> useranswer;
        if(useranswer == "Hit" || useranswer == "hit") {
            logfile << "- User hits.\n";
            player_hit(logfile);
            if (sum_of_player >= 21) {
                return false;
            }
            return true;
        }else if (useranswer == "Stand" || useranswer == "stand"){
            std :: cout << "Your sum wont change and you still have: " << sum_of_player << '\n';
            logfile << "- User stands.\n";
            logfile << "User's sum wont change. User still has: " << sum_of_player << '\n';
            return false;
        }else{
            std ::  cout << "Please enter a valid answer.\n";
        }
    }
}


void game() {
    std::fstream logfile("log.txt", std::ios::app);
    logfile << "Start game.\n";
    bool player_won = false;
    bool dealer_won = false;

    std :: cout << "You have : " << "$" <<dollars << '\n';
    logfile << "Player has : " << "$" <<dollars << '\n';
    deduct_wager();
    std :: cout << '\n';

    dealer_cards(logfile);
    player_cards(logfile);

    if (rollplayer_1 == CardType::Ace && rollplayer_2 == CardType::Ace) {
        player_won = true;
    } else if (sum_of_player == 21) {
        player_won = true;
    }

    bool player_hit = true;
    
    // players turn..
    // do again if player keeps hitting
    while (player_hit) {
        player_hit = ask_player(logfile);

        if (sum_of_player > 21) {
            std :: cout << "Bust. ";
            logfile << "Bust. ";
            dealer_won = true;
        } else if (sum_of_player == 21){
            std :: cout << "Blackjack.. ";
            logfile << "Blackjack.. ";
            player_won = true;
        }
    }

    // dealer turn
    if (!player_won && !dealer_won) {
        logfile << "- Dealer hits.\n";
        dealer_hit(logfile);

        if (sum_dealer_points > 21) {
            std :: cout << "The house has bust. ";
            logfile << "The house has bust. ";
            player_won = true;
        } else if (sum_dealer_points == 21){
            std :: cout << "The house has blackjacked.  ";
            logfile << "The house has blackjacked.  ";
            dealer_won = true;
        }
    }

    if (!player_won && !dealer_won) {
        if (sum_of_player > sum_dealer_points) {
            player_won = true;
        }else if (sum_dealer_points > sum_of_player){
            dealer_won = true;
        }else {
            player_won = true;
            dealer_won = true;
        }
    }

    if (player_won && dealer_won) {
        std :: cout << "Its a tie..." << '\n';
        logfile << "Its a tie..." << '\n';
        // give back wager
        dollars += wager;
    } else if (player_won) {
        std :: cout << "you win. Congs...\n";
        logfile << "Player wins...\n";
        // give 2x wager
        dollars += wager * 2;
    } else if (dealer_won) {
        std :: cout << "you lost Bambi for you...\n";
        logfile << "Player lost...\n";
    }

    std :: cout << "now u have : $"<<  dollars << '\n';
    logfile << "player has : $"<<  dollars << '\n';

    logfile << "End log.\n";
    logfile << "--------\n";
    logfile.close();
}

void menufunction(){
    // declare here
    int options = 0;

    while (options != 3 && dollars > 0){
        std :: cout << "Select the options.\n";
        std :: cout << "1) Rules" << '\n';
        std :: cout << "2) Play" << '\n';
        std :: cout << "3) Exit" << '\n';
        std :: cin >> options;

        switch (options){
            case 1:
                std :: cout << "The rules of blackjack are simple. Just play the game." << '\n';
                std :: cout << "You have two cards. Hit or stand, but don't go over twenty one!\n";
                std :: cout << "Your dealer has two cards as well, but only one can he tell.\n";
                std :: cout << "Use coconut. Think and win.\n";
                break;
            case 2: 
                std :: cout << "Play" << '\n';
                game();
                break;
            case 3:
                std :: cout << "Exit" << '\n';
                break;
            default:
                std :: cout << "Enter a valid option.\n";
                break;
        }
    }
    if (dollars <= 50) {
        std :: cout << "You're too broke to play, dummy!\n";
    }
    std :: cout << '\n';
}
int main() {
        menufunction();
}
