#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
  char first[10];
  char last[10];
  int id;
  float gpa;
};

void add(vector<Student> &list);
void print(vector<Student> list);
void del(vector<Student> &list);

int main() {
  bool running = true;
  char cAdd[8] = "add";
  char cPrint[8] = "print";
  char cDel[8] = "delete";
  char cQuit[8] = "quit";
  vector<Student> list;
  char command[8];

  cout << "Welcome to the student list!" << endl;
  while (running == true) {
    cout << "Please enter a command (add, print, delete, or quit)." << endl;
    cin >> command;
    cin.get();
    for (int i = 0; i < command[i]; i++) {
      if (command[i] >= 65 && command[i] <= 92) {
	command[i] = command[i] + 32;
      }
    }
    if (strcmp(cAdd, command) == 0) {
      add(list);
    }
    else if (strcmp(cPrint, command) == 0) {
      print(list);
    }
    else if (strcmp(cDel, command) == 0) {
      del(list);
    }
    else if (strcmp(cQuit, command) == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid command (add, print, delete, or quit);" << endl;
    }
  }
  return 0;
}

void add(vector<Student> &list) {
  char firstI[10];
  char lastI[10];
  int idI;
  float gpaI;
  cout << "Please enter the student's first name." << endl; 
  cin >> firstI;
  cin.get();
  cout << "Please enter the student's last name." << endl; 
  cin >> lastI;
  cin.get();
  cout << "Please enter the student's ID number." << endl; 
  cin >> idI;
  cin.get();
  cout << "Please enter the student's GPA." << endl; 
  cin >> gpaI;
  cin.get();

  Student s;
  strcpy(s.first, firstI);
  strcpy(s.last, lastI);
  s.id = idI;
  s.gpa = gpaI;
  
  list.push_back(s);
  cout << endl;
}
void print(vector<Student> list) {
  for (int i = 0; i < list.size(); i++) {
    cout << list[i].first << " " << list[i].last << ", " << list[i].id << ", " << list[i].gpa << endl;
  }
  cout << endl;
}

void del(vector<Student> &list) {
  int delID;
  cout << "Enter the ID number of the student you would like to delete." << endl;
  cin >> delID;
  for (int i = 0; i < list.size(); i++) {
    if (delID == list[i].id) {
      cout << list[i].first << " " << list[i].last << " has been deleted." << endl;
      list.erase(list.begin()+i);
    }
    else {
      cout << "None of the students in the list have an ID number matching what was inputted." << endl;
      cout << "If you want to delete a student, please type 'delete' again." << endl;
    }
  }
    cout << endl;
}
