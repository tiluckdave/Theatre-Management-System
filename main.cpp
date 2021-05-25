// Theatre Maganement System
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
        movie(){
            out.open("movies.txt", ios::app);
            // in.open("movies.txt")
        }
        void addmovie(){
            cout << "Enter Movie ID: ";
            cin >> id;
            cout << "Enter Movie Name: ";
            getline(cin, name);
            cout << "Enter Movie Ticker Price Per Person: ";
            cin >> price_per_person;
            cout << "Enter Movie Age Rating (0 - all): ";
            cin >> age_rating;
            cout << "Enter Movie Movie Length (format - hh:mm): ";
            cin >> movie_length;
            if(out.is_open()){
                out<<"Id: "<<id<<"\nName: "<<name<<"\nPrice: "<<price_per_person<<"\nAge Rating: "<<age_rating<<"\nMovie Length: "<<movie_length<<"\n\n"; 
                cout << endl << "Record added successfully";
            }
            else {
                cout << endl << "Something Went Wrong!!";
            }
        }
        void getmovies(){
            // if(in.is_open()){
            //     string mv;
            //     while(getline(in, mv)){

            //     }
            // }
        }
        ~movie(){
            out.close();
            // in.close();
        }
};

class screen {
    private:
        int screen_no;
        char screen_type[2];
    public:
        screen(){
            // file open here
        }
        void addscreen(){
            cout << "Enter Screen Number: ";
            cin >> screen_no;
            cout << "Enter Screen Type (2D/3D): ";
            cin >> screen_type;
            cout << endl << "Record added successfully";
        }
        void getscreens(){
            // fetch from file
        }
        ~screen(){
            // file close here
        }
};


int main()
{
    movie m;
    m.addmovie();
    return 0;
}