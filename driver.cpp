// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"
using namespace std;

int main()
{
    string command;
    Players *head = nullptr;
    int number = 0;
    int &count = number;
    bool game = true;
    while (game)
    {
        cin >> command;
        if (command == "SPAWN")
        {
            float x, y;
            cin >> x >> y;
            cout << head->spawn(head, x, y, count) << endl;
        }
        else if (command == "TIME")
        {
            int t;
            cin >> t;
            head->time(head, t, number);
            cout << number << endl;
        }
        else if (command == "LUNCH")
        {
            head->lunch(head, number);
            cout << number << endl;
        }
        else if (command == "NUM")
        {
            cout << number << endl;
        }
        else if (command == "PRT")
        {
            int d;
            bool check = true;
            bool& check_recurse = check;
            cin >> d;

            head->prtNear(head, d, check_recurse);

            if (check){
                cout << "no players found" << endl;
            }
            else{
                cout << endl;
            }
        }
        else if (command == "OVER"){
            if(number != 0){
                cout << "player win" << endl;
                return 0;
            }
            else{
                cout << "wolf wins" << endl;
                return 0;
            }
        }
        
    }
}