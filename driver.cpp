// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"
using namespace std;


int main(){
    string command;
    cin >> command;
    Players* head;
    int number = 0;
    int& count = number;

    if(command == "SPAWN"){
        int x,y;
        cin >> x >> y;
        head->spawn(head, x, y, count);
    }
    // your code goes here...  

}