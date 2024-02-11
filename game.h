// define your classes here...
#include <iostream>
#include <string>
using namespace std;

class Players{
    private:
    //private variables
    int x_coordinate;
    int y_cooordinate;
    int id;
    Players* next;
    Players* prev;
    //private functions
    void deletePlayer(Players*& head, Players*& prev, int& number);

    public:
    //public functions
    string spawn(Players*& head, int x, int y, int& number);
    int time(Players*& head, int t, int& number);
    void lunch(Players*& head);
    int getID();
    int prtNear();
    string over();
};