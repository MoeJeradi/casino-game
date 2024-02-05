#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


void rules()
{
    std::cout << "-----------------RULES-----------------\n";
    std::cout << "1. Pick a; number between 1 through 10.\n";
    std::cout << "2.Choose an amount you want to bet for the roulette game // winner gets 10x there money\n";
    std::cout << "3. If you lose, you lose the amount of money you bet.\n";
    std::cout << "---------------------------------------\n";

}


    int balance; // user balance
    int bettingamount; // Amount user wants to bet
    int userguess; /// user guesses the PC NUMBER
    int dice; // srand(time(0) for the PC TO randomize a number
    char choice; // THIS FOR THE END Y / N
    
    std::string name;
    
    
    void entrance() {
        std::cout << "———————-*|Mohamads Casino|*———————" << std::endl;
        
        std::cout << "Enter your name - ";
        std::cin >> name;
        std::cout << "Hi, "<< name << " enter the amount you would like to deposit - ";
        std::cin >> balance;
        
        rules();
        
    }
    void betamount()
    {
        
        std::cout << "Cool, you have " << balance << "$, how much would you like to bet - ";
        std::cin >> bettingamount;
    }
    
void gameguess()
{
    std::cout << "Alright " << name << ", go ahead and guess a number between 1-10, I'll roll the dice when you pick - ";
    std::cin >> userguess;

    while (userguess <= 0 || userguess > 10)
    {
        std::cout << "The number should be between 1-10. Please try again: ";
        std::cin >> userguess;
    }

    dice = rand() % 10 + 1; // iterates the int dice and makes the PC guess

    if (dice == userguess)
    {
        std::cout << "You are very lucky " << name << ", you won " << bettingamount * 10 << "$\n";
        balance = balance + bettingamount * 10;
    }
    else
    {
        std::cout << "You lost, your new balance is " << balance - bettingamount << "$\n";
        balance = balance - bettingamount;
    }

    std::cout << "The winning number was " << dice << " your new balance is " << balance << "$\n";
}


void tryagain()
{
    std::cout << "———————-*|Mohamads Casino|*———————" << std::endl;

    if (balance > 0)
    {
        std::cout << "Your balance is " << balance << " do you want to play again? (Y/N) - ";
        std::cin >> choice;

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            std::cout << "Invalid choice. Please enter Y or N: ";
            std::cin >> choice;
        }
    }
}



int main (){
    
    
          entrance();
    do {
          betamount();
          gameguess();
          tryagain();
    } while ((choice == 'Y' || choice == 'y') && balance > 0);
    
    if ((choice == 'N' || choice == 'n') && balance >= 0){
        std::cout << "———————-*|Mohamads Casino|*———————\n";
        std::cout <<"Thank you for playing I hope you have an amazing rest of your day " << name << std::endl;
    }
    
    return 0;

}
