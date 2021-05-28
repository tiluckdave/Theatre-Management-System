class Movie
{
private:
  int id;
  char mvname[200];
  char time[50];
  int tseats;
  int booked;

public:
  Movie()
  {
    id = 0;
    tseats = 200;
    booked = 0;
    strcpy(time, "6:15pm");
    strcpy(mvname, "");
  }
  void input();
  void show();
  void display();
  int getid()
  {
    return id;
  }
  void book()
  {
    booked++;
  }
  char *getMovie()
  {
    return mvname;
  }
  char *getTime()
  {
    return time;
  }
  int getBooked()
  {
    return booked;
  }
  int getMax()
  {
    return tseats;
  }
};

void Movie::input()
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
  gotoxy(35, 2);
  cout << "\n\n\t\t\t\tAdding Movie ";
  gotoxy(12, 7);
  cout << "Enter Movie Id :-" << endl;
  gotoxy(42, 7);
  cin >> id;
  gotoxy(12, 9);
  cout << "Enter Movie Name :-" << endl;
  gotoxy(42, 9);
  cin >> mvname;
  gotoxy(12, 11);
  cout << "Enter the time of Movie :-" << endl;
  gotoxy(42, 11);
  cin >> time;
}
void Movie::display()
{
  cout << "Movie id is :-" << id << endl;
  cout << "Movie Name is :-" << mvname << endl;
  cout << "Movie start time is :-" << time << endl;
  cout << "Total seats :-" << tseats << endl;
  cout << " Total Booked seats :-" << booked << endl;
}
void Movie::show()
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
  gotoxy(12, 5);

  cout << "Movie Id is :-" << id << endl;
  gotoxy(12, 7);
  cout << "Movie Name is :-" << mvname << endl;
  gotoxy(12, 9);
  cout << "Time is :-" << time << endl;
  gotoxy(12, 11);
  cout << "No. of seats remaining :-" << tseats - booked << endl;
}
