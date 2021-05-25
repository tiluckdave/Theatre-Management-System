#pragma once
using namespace std;

#include <iostream>
#include <fstream>

class screen {
    private:
        int screen_no;
        char screen_type[2];
    public:
        screen();
            // file open here
        void addscreen();
        void getscreens();
            // fetch from file
        ~screen();
            // file close here
};
