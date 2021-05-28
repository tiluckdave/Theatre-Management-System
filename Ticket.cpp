#include <Movie.h>
#include <iostream>
using namespace std;
class Ticket
{
  char name[50];
  Movie mv;

public:
  void generate(char cname[], Movie m)
  {
    strcpy(name, cname);
    mv = m;
  }
  void display()
  {
    cout << "Customer Name :- " << name << endl;
    cout << "Details of Movie :- " << endl;
    mv.show();
  }
};