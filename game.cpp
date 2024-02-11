#include "game.h"
#include <cmath>

// implement classes' member functions here...
string Players::spawn(Players *&head, int x, int y, int &number)
{
    if (x < 0 || y < 0)
    {
        return "failure";
    }
    Players *temp = new Players;
    temp->x_coordinate = x;
    temp->y_cooordinate = y;
    temp->next = head;
    head->prev = temp; // set prev to new node
    head = temp;
    return "success";
}
void Players::deletePlayer(Players *&head, Players *&prev, int& number)
{
    Players *temp = head;
    if(prev == nullptr){
        head = temp->next;
    }
    else{
    head = temp->next;
    head->prev = temp->prev;
    }
    delete temp;
    number--;
    return;
}
int Players::time(Players *&head, int t, int& number)
{
    if (head->next != nullptr)
    {
        time(head->next, t, number);
    }
    int x = t * cos(atan2(this->y_cooordinate, this->x_coordinate));
    int y = t * sin(atan2(this->y_cooordinate, this->x_coordinate));
    this->x_coordinate -= x;
    this->y_cooordinate -= y;
    if (this->x_coordinate < 0 || this->x_coordinate >= 500 || this->y_cooordinate < 0 || this->y_cooordinate >= 500)
    {
        deletePlayer(head, head->prev, number);
    }
    return number;
}
void Players::lunch(Players *&head) {}
int Players::getID() {return 1;}
int Players::prtNear() {return 1;}
string Players::over() {return"hell";}