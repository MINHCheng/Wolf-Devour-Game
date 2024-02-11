#include "game.h"
#include <cmath>
#include <iostream>
#include <string>

// implement classes' member functions here...
Players::Players()
{
    this->prev = nullptr;
    this->next = nullptr;
    this->x_coordinate = 0;
    this->y_cooordinate = 0;
}
string Players::spawn(Players *&head, double x, double y, int &number)
{
    if (x < 0 || y < 0)
    {
        return "failure";
    }
    Players *temp = new Players;
    temp->x_coordinate = x;
    temp->y_cooordinate = y;

    if (head != nullptr)
    {
        temp->next = head;
        head->prev = temp; // set prev to new node
    }
    head = temp;
    number++;
    return "success";
}

void Players::deletePlayer(Players *&head, Players *&prev, int &number)
{
    Players *temp = head;
    head = temp->next;
    if (prev != nullptr)
    {
        head->prev = temp->prev;
    }
    number--;
    delete temp;
    temp = nullptr;
    return;
}

int Players::time(Players *&head, int t, int &number)
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
void Players::lunch(Players *&head, int &number)
{
    if (head->next != nullptr)
    {
        lunch(head->next, number);
    }
    if (sqrt(pow(head->x_coordinate, 2) + pow(head->y_cooordinate, 2)) < 0)
    {
        deletePlayer(head, head->prev, number);
    }
}
int Players::prtNear(Players*& head, int d) {return 1;}
string Players::over() { return "hell"; }