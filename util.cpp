#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int genAnswer(){
    mt19937 gen(time(NULL));

    uniform_int_distribution<int> dist(1,9);
    int answer=0;
    int digits[3]={0};

    for(int i = 0; i<3; i++){
        int digit = dist(gen);
        while (digits[0]==digit || digits[1]== digit || digits[2]==digit){
            digit = dist(gen);
        }
        digits[i]=digit;
        answer = answer*10+digit;
    }

    return answer;
}