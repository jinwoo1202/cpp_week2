#include <iostream>

using namespace std;

int getStrikes(int guess, int answer) {
    int strikes = 0;
    int digit = 100;
    for (int i = 0; i < 3; i++){
        int compare_guess = guess / digit % 10;
        int compare_answer = answer / digit % 10;
        if (compare_guess == compare_answer)
            strikes++;
        digit = digit / 10;
    }
    return strikes;
}

int getBalls(int guess, int answer){
    int balls = 0;
    int compare_guess[3] = {guess/100, guess/10%10, guess%10};
    int compare_answer[3] = {answer/100, answer/10%10, answer%10};
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i!=j && compare_guess[i]==compare_answer[j]){
                balls++;
            }
        }
    }
    return balls;
}

void goGame(){
    int answer = genAnswer();

    while(true){
        int guess;
        cout << "Enter a guess: ";
        cin >> guess;

        int strikes = getStrikes(guess, answer);
        int balls = getBalls(guess, answer);

        if(strikes == 3){
            cout<<"You Win!";
            break;
        }
        else{
            cout << "Strikes: "<<strikes<< ", Balls: "<<balls<< "\n";
        }
    }
}