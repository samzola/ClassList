/*
 * Author: Sam Zola
 * Date: 10/16/2019
 * Program: This program allows the user to make a list of students and their relevant information. They can add to the list, delete from the list, and print the list. 
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

struct Student { //create struct for each student's data
  char first[10]; //first name
  char last[10]; //last name
  int id; //student id number
  float gpa; //gpa
};

void add(vector<Student> &list);
void print(vector<Student> list);
void del(vector<Student> &list);

int main() {
  bool running = true; //variable keeps track of if program is running
  vector<Student> list; //vector list that holds the student struct
  char command[8]; //this char array is the command input
  //below are the valid commands that the user could input
  char cAdd[8] = "add";
  char cPrint[8] = "print";
  char cDel[8] = "delete";
  char cQuit[8] = "quit";

  cout << "Welcome to the student list!" << endl;
  cout << "In this program, you can make a list of students, including their name, ID, and GPA." << endl;
  while (running == true) {
    cout << "Please enter a command (add, print, delete, or quit)." << endl;
    cin >> command;
    cin.get();
    for (int i = 0; i < command[i]; i++) { //make the command input lowercase so it matches 
      if (command[i] >= 65 && command[i] <= 92) {
	command[i] = command[i] + 32;
      }
    }
    if (strcmp(cAdd, command) == 0) { //if command is "add"
      add(list); //run add method
    }
    else if (strcmp(cPrint, command) == 0) { //if command is "print"
      print(list); //run print method
    }
    else if (strcmp(cDel, command) == 0) { //if command is "delete"
      del(list); //run delete method
    }
    else if (strcmp(cQuit, command) == 0) { //if command is "quit"
      running = false; //make the game stop running
    }
    else { //if none of the command inputs match the 4 possibilities, tell the user and have them re-input
      cout << "Please enter a valid command (add, print, delete, or quit);" << endl;
    }
  }
  return 0;
}

void add(vector<Student> &list) { //method for adding students to the list
  //the following 4 lines keep track of the inputted names/values
  char firstI[10];
  char lastI[10];
  int idI;
  float gpaI;
  cout << "Please enter the student's first name." << endl; //prompt the user to enter the first name
  cin >> firstI; //read in input for first name
  cin.get();
  cout << "Please enter the student's last name." << endl; //prompt the user to enter the last name 
  cin >> lastI; //read in input for last name
  cin.get();
  cout << "Please enter the student's ID number." << endl; //prompt the user to enter the ID number
  cin >> idI; //read in input for ID
  cin.get();
  cout << "Please enter the student's GPA." << endl; //prompt the user to enter the GPA 
  cin >> gpaI; //read in input for GPA
  cin.get();

  Student s; //create a new student
  //set the inputted information as the new student's information
  strcpy(s.first, firstI);
  strcpy(s.last, lastI);
  s.id = idI;
  s.gpa = gpaI;
  
  list.push_back(s); //add the new student to the vector list
  cout << endl;
}
void print(vector<Student> list) { //method for printing the list
  for (int i = 0; i < list.size(); i++) {  //go through each student in the vector
    //print each students first & last name, id, and gpa (set to 2 decimal places)
    cout << list[i].first << " " << list[i].last << ", " << list[i].id << ", " << fixed << setprecision(2) << list[i].gpa << endl;
  }
  cout << endl;
}

void del(vector<Student> &list) { //method for deleting students from the list
  int delID; //create a variable to keep track of the inputted ID
  //ask the user to enter the ID of the student that will be deleted
  cout << "Enter the ID number of the student you would like to delete." << endl;
  cin >> delID; //read in inputted ID
  for (int i = 0; i < list.size(); i++) { //go through each student in the vector
    if (delID == list[i].id) { //if the inputted ID matches any of the student IDs
      //tell user which student is being deleted
      cout << list[i].first << " " << list[i].last << " has been deleted." << endl;
      list.erase(list.begin()+i); //erase student from vector and delete data
    }
  }
    cout << endl;
}
