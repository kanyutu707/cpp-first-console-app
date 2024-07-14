#include <iostream>


static void checker(int amount, int password)
    
{
    std::string x;
    int selectedAmount;
    int selectedPassword;
    std::cout << " \n WHAT SERVICE WOULD YOU LIKE TO TRY, \n W for withdrawal, \n D for deposit, \n C for cancel, \n R for reload: ";
    std::cin >> x, "\n";
    if (x == "W") {
        std::cout << "INPUT THE WITHDWAL AMOUNT: \n";
        std::cin >> selectedAmount;
        if (selectedAmount > amount) {
            std::cout << "AMOUNT SELECTED IS GREATER THAN AVAILABLE AMOUNT \n";
            std::cout << "TRY AGAIN \n";
            checker(amount, password);
        }
        else {
            std::cout << "INPUT THE ACCOUNT PASSWORD: \n";
            std::cin >> selectedPassword;
            if (password != selectedPassword) {
                std::cout << "PASSWORD MISMATCH \n";
                checker(amount, password);

            }
            else {
                amount = amount - selectedAmount;
                std::cout << "New amount is ";
                std::cout << amount, "\n";
                checker(amount, password);
                
            }
        }
    }
    else if (x == "D") {
        std::cout << "INPUT THE DEPOSIT AMOUNT: \n";
        std::cin >> selectedAmount;
        amount = amount + selectedAmount;
        std::cout << "TOTAL AMOUNT AVAILABLE IN THE ACCOUNT IS ";
        std::cout << amount;
        checker(amount, password);

    }
    else if (x == "C") {
        exit;
    }
    else if (x=="R"){
        std::cout << "PAGE RELOADED";
        checker(amount, password);
    }


 }

int main()
    
{
    checker(30000, 2000);
}

