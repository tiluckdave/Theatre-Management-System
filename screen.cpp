using namespace std;

#include <iostream>
#include <fstream>

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
