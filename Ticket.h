#pragma once
#include <Movie.h>
class Ticket
{
  char name[50];
  Movie mv;

public:
  void generate(char cname[], Movie m);
  void display();
};