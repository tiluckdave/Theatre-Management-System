//Movie Reservation System
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <windows.h>
#include <Movie.h>
#include <Ticket.h>
using namespace std;
void gotoxy(int x,int y)
{
 printf("%c[%d;%df",0x1B,y,x);
}



int main()
{
  int ch;
  int id, chk = 0;
  fstream F, G;
  Movie b;
  Ticket t;
  int exit;

  do
  {
    system("cls");
    system("color 07");

    for (int i = 0; i < 21; i++)
    {
      gotoxy(9, i);
      cout << "|";
      gotoxy(75, i);
      cout << "|";
    }
    gotoxy(10, 5);
    cout << "Press 1 - Add a New Movie" << endl;
    gotoxy(10, 7);
    cout << "Press 2 - Show Selected Movie" << endl;
    gotoxy(10, 9);
    cout << "Press 3 - Display All Movies" << endl;
    gotoxy(10, 11);
    cout << "Press 4 - Delete a Movie" << endl;
    gotoxy(10, 13);
    cout << "Press 5 - Book a movie ticket " << endl;
    gotoxy(10, 15);
    cout << "Press 6 - Display Booked Tickets " << endl;
    gotoxy(10, 17);
    gotoxy(10, 19);
    cout << "Enter your choice :-";
    gotoxy(42, 19);
    cin >> ch;
    switch (ch)
    {
    case 1:
      F.open("movie.dat", ios::app | ios::binary);
      b.input();
      F.write((char *)&b, sizeof(b));
      F.close();
      gotoxy(12, 13);
      cout << "Movie added Successfully..." << endl;
      Sleep(10);
      getch();
      break;
    case 2:
    {
      system("cls");
      system("color 07");

      for (int i = 0; i < 21; i++)
      {
        gotoxy(9, i);
        cout << "::";
        gotoxy(75, i);
        cout << "::";
      }

      for (int i = 10; i < 75; i++)
      {
        gotoxy(i, 0);
        cout << "::";
      }

      for (int i = 75; i >= 9; i--)
      {
        gotoxy(i, 20);
        cout << "::";
      }
      gotoxy(12, 2);
      cout << "Enter the movie id to be displayed :-";
      cin >> id;
      F.open("movie.dat", ios::in | ios::binary);
      if (F.fail())
        cout << "Can't open file " << endl;
      else
      {
        while (F.read((char *)&b, sizeof(b)))
        {
          if (b.getid() == id)
          {
            b.show();
            chk = 1;
            break;
          }
        }
        if (chk == 0)
          cout << "Movie not Found..." << endl;
        Sleep(10);
      }
      F.close();
      getch();
    }
    break;
    case 3:
    {
      system("cls");
      system("color 07");

      F.open("movie.dat", ios::in | ios::binary);
      if (F.fail())
        cout << "Can't open file " << endl;
      else
      {
        while (F.read((char *)&b, sizeof(b)))
        {
          b.display();
        }
      }
      F.close();
      gotoxy(10, 20);
      cout << "Press a key to continue... ";
      getch();
    }
    break;
    case 4:
    {
      system("cls");
      system("color 07");

      for (int i = 0; i < 21; i++)
      {
        gotoxy(9, i);
        cout << "::";
        gotoxy(75, i);
        cout << "::";
      }

      for (int i = 10; i < 75; i++)
      {
        gotoxy(i, 0);
        cout << "::";
      }

      for (int i = 75; i >= 9; i--)
      {
        gotoxy(i, 20);
        cout << "::";
      }

      chk = 0;
      gotoxy(12, 5);
      cout << "Enter the Movie id to be deleted :-";
      cin >> id;
      F.open("movie.dat", ios::in | ios::binary);
      G.open("temp.dat", ios::out | ios::binary);

      if (F.fail())
        cout << "Can't open file " << endl;
      else
      {
        while (F.read((char *)&b, sizeof(b)))
        {
          if (b.getid() != id)
          {
            G.write((char *)&b, sizeof(b));
          }
          else
          {
            b.show();
            chk = 1;
          }
        }
        if (chk == 0)
        {
          gotoxy(12, 7);
          cout << "Movie not Found..." << endl;
        }
        else
        {
          gotoxy(12, 13);
          cout << "Movie Deleted..." << endl;
        }
      }
      F.close();
      G.close();
      remove("movie.dat");
      rename("temp.dat", "movie.dat");
      getch();
    }
    break;
    case 5:
    {
      char mvname[70], cname[50];
      int mid;
      system("cls");
      system("color 07");
      for (int i = 0; i < 21; i++)
      {
        gotoxy(9, i);
        cout << "::";
        gotoxy(75, i);
        cout << "::";
      }

      for (int i = 10; i < 75; i++)
      {
        gotoxy(i, 0);
        cout << "::";
      }

      for (int i = 75; i >= 9; i--)
      {
        gotoxy(i, 20);
        cout << "::";
      }
      gotoxy(12, 5);
      cout << "Enter the movie name :-";
      gotoxy(42, 5);
      cin >> mvname;
      F.open("movie.dat", ios::in | ios::out | ios::binary);
      if (F.fail())
        cout << "Can't open file " << endl;
      else
      {
        while (F.read((char *)&b, sizeof(b)))
        {
          if (strcmp(b.getMovie(), mvname) == 0)
          {
            b.show();
            chk = 1;
            gotoxy(12, 13);
            cout << "Enter the customer name :-";
            gotoxy(42, 13);
            cin >> cname;
            b.book();
            t.generate(cname, b);
            G.open("tickets.dat", ios::app | ios::binary);
            G.write((char *)&t, sizeof(t));
            G.close();
            F.seekp(F.tellg() - sizeof(b), ios::beg);
            F.write((char *)&b, sizeof(b));
            gotoxy(12, 15);
            cout << "Ticket booked..." << endl;
            break;
          }
        }
        if (chk == 0)
        {
          gotoxy(12, 8);
          cout << "No Movie Found..." << endl;
        }
      }
      F.close();
      getch();
    }
    break;
    case 6:
    {
      cout << "Booked Tickets. " << endl;
      G.open("tickets.dat", ios::in | ios::binary);
      if (G.fail())
        cout << "can't open file " << endl;
      else
      {
        while (G.read((char *)&t, sizeof(t)))
          t.display();
      }
      G.close();
      gotoxy(12, 13);
      cout << "Press a key to continue... ";
      getch();
    }
    }
  } while (ch != 7);
  return 0;
}
