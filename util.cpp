#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int genAnswer(){
    mt19937 gen(time(NULL));

    uniform_int_distribution<int> dist(100,999);

    return dist(gen);
}