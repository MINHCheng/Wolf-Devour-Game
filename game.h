// define your classes here...
#include <iostream>
#include <string>
using namespace std;

class Players{
    private:
    //private variables
    double x_coordinate;
    double y_cooordinate;
    int id;
    Players* next = nullptr;
    Players* prev = nullptr;
    //private functions
    void deletePlayer(Players*& head, Players*& prev, int& number);

    public:
    //public functions
    Players();
    string spawn(Players*& head, double x, double y, int& number);
    int time(Players*& head, int t, int& number);
    void lunch(Players*& head, int& number);
    int getID();
    int prtNear(Players*& head, int d);
    string over();
};