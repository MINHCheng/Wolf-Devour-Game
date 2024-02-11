// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "game.h"
using namespace std;

int main()
{
    string command;
    cin >> command;
    Players *head;
    int number = 0;
    int &count = number;
    bool game = true;
    while (game)
    {
        if (command == "SPAWN")
        {
            int x, y;
            cin >> x >> y;
            cout << head->spawn(head, x, y, count) << endl;
        }
        else if (command == "TIME")
        {
            int t;
            cin >> t;
            head->time(head, t, number);
        }
        else if (command == "LUNCH")
        {
            head->lunch(head, number);
            cout << number;
        }
        else if (command == "NUM")
        {
            cout << number;
        }
    }
    // your code goes here...
}
//hello