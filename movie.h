#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class movie {
    private:
        int id;
        string name;
        int price_per_person;
        int age_rating;
        char movie_length[5];
        ofstream out;
    public:
        movie();// in.open("movies.txt")
        void addmovie();
        void getmovies();
        ~movie();
};
