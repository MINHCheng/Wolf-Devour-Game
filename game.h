// define your classes here...
#include <iostream>
#include <string>
using namespace std;

class Players{
    private:
    //private variables
    float x_coordinate;
    float y_cooordinate;
    int id;
    Players* next = nullptr;
    Players* prev = nullptr;
    //private functions
    void deletePlayer(Players*& head, Players*& node, Players*& prev, int& number);

    public:
    //public functions
    Players();
    string spawn(Players*& head, float x, float y, int& number);
    int time(Players*& head, double t, int& number);
    void lunch(Players*& head, int& number);
    int getID();
    void prtNear(Players*& head, int d, bool& check);
    void deletePlayer(Players *&head);
    ~Players();
};