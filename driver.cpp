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
            double x, y;
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
            cout << number;
        }
        else if (command == "NUM")
        {
            cout << number;
        }
    }
    // your code goes here...
}
// hello