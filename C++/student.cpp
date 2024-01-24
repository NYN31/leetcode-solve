#include <bits/stdc++.h>
using namespace std;

class Student {
  int id;
  string name;
  double cgpa;

 public:
  void getDetails() {
    cout << "----Enter a fresh  student details---- " << endl;
    cout << "Enter id: ";
    cin >> id;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter cgpa: ";
    cin >> cgpa;
  }

  void printDetails() {
    cout << "Student details output: " << endl;
    cout << "Id: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
  }
};

int main() {
  int n;
  cout << "Enter student number: ";
  cin >> n;

  Student student[n];

  for (int i = 0; i < n; i++) {
    student[i].getDetails();
  }

  for (int i = 0; i < n; i++) {
    student[i].printDetails();
  }

  return 0;
}