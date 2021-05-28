#pragma once
class Movie
{
private:
    int id;
    char mvname[200];
    char time[50];
    int tseats;
    int booked;

public:
    Movie();
    void input();
    void show();
    void display();
    int getid();
    void book();
    char *getMovie();
    char *getTime();
    int getBooked();
    int getMax();
};

void Movie::input();
void Movie::display();
void Movie::show();