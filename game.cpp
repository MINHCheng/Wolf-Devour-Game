#include "game.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
// implement classes' member functions here...
Players::Players()
{
    this->prev = nullptr;
    this->next = nullptr;
    this->x_coordinate = 0;
    this->y_cooordinate = 0;
}
string Players::spawn(Players *&head, float x, float y, int &number)
{
    if (x <= 0 || y <= 0)
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

void Players::deletePlayer(Players *&head, Players *&node, Players *&prev, int &number)
{
    // Players *temp = node;
    if (node == head)
    {
        head = node->next;
    }
    if (prev != nullptr)
    {
        prev->next = node->next;
    }
    if (node->next != nullptr)
    {
        node->next->prev = prev;
    }
    number--;
    delete node;
    node = nullptr;
    return;
}

int Players::time(Players *&head, double t, int &number)
{
    if (head == nullptr)
    {
        return number;
    }
    Players *temp = head;
    while (temp != nullptr)
    {
        Players *nexttemp = temp->next;

        double x = t * cos(atan2(temp->y_cooordinate, temp->x_coordinate));
        double y = t * sin(atan2(temp->y_cooordinate, temp->x_coordinate));
        temp->x_coordinate -= x;
        temp->y_cooordinate -= y;
        // cout << head->x_coordinate << endl;;
        // cout << head->y_cooordinate << endl;

        if (temp->x_coordinate < 0 || temp->x_coordinate >= 500 || temp->y_cooordinate < 0 || temp->y_cooordinate >= 500)
        {
            deletePlayer(head, temp, temp->prev, number);
            if (nexttemp == nullptr)
            {
                return number;
            }
            else
            {
                temp = nexttemp;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    return number;
}
void Players::lunch(Players *&head, int &number)
{
    if (head == nullptr)
    {
        return;
    }
    Players *temp = head;
    while (temp != nullptr)
    {
        if (sqrt(pow(temp->x_coordinate, 2) + pow(temp->y_cooordinate, 2)) < 1)
        {
            deletePlayer(head, temp, temp->prev, number);
        }
        if (temp == nullptr)
        {
            return;
        }
        temp = temp->next;
    }
}
void Players::prtNear(Players *&head, int d, bool &check)
{
    if (head == nullptr)
    {
        return;
    }
    Players *temp = head;
    while (temp != nullptr)
    {
        cout << temp->x_coordinate << " " << temp->y_cooordinate << " ";
        temp = temp->next;
        check = false;
    }
}

void Players::deletePlayer(Players *&head)
{
    Players *temp = head;
    head = temp->next;
    delete temp;
    temp = nullptr;
    return;
}