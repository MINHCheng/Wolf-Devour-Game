// define your classes here...
#include <iostream>
using namespace std;

class Players{
    private:
    int x_coordinate;
    int y_cooordinate;
    int id;
    Players* next;
    Players* prev;

    void deletePlayer(Players*& head, Players*& prev, int& number);

    public:
    string spawn(Players*& head, int x, int y, int& number);
    int time(Players*& head, int t, int& number);
    void lunch(Players*& head);
    int getID();
    int prtNear();
    string over();
};