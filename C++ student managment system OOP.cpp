#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    int marks[5]; 
    float average;
};

const int MAX_STUDENTS = 50;
Student students[MAX_STUDENTS]; 
int totalStudents = 0; 


void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        cout << "Maximum students "<<endl;
        return;
    }

    cout << "\n student name"<<endl;
    cin.ignore(); 
    getline(cin, students[totalStudents].name);
    
    cout << " student ID "<<endl;
    cin >> students[totalStudents].id;

    cout << " marks for 5 subjects"<<endl;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Subject "<<endl;
        cout << i + 1<<endl;
        cin >> students[totalStudents].marks[i];
        sum += students[totalStudents].marks[i];
    }
    students[totalStudents].average = sum / 5.0;

    totalStudents++;
    cout << "Student added successfully"<<endl;
}

void displayStudents() {
    if (totalStudents == 0) {
        cout << "No students"<<endl;
        return;
    }

    cout << " Student Records "<<endl;
    for (int i = 0; i < totalStudents; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Marks: ";
        for (int j = 0; j < 5; j++) {
            cout << students[i].marks[j] << " ";
        }
        cout << "\nAverage Marks" << students[i].average << endl;
    }
}

void removeStudent() {
    if (totalStudents == 0) {
        cout << "No students to remove"<<endl;
        return;
    }

    int id;
    cout << "student ID to remove"<<endl;
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].id == id) {
            found = true;
            
            for (int j = i; j < totalStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            totalStudents--;
            cout << "Student removed successfully"<<endl;
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found"<<endl;
    }
}

void calculateMarks() {
    if (totalStudents == 0) {
        cout << "No calculate marks"<<endl;
        return;
    }

    float highest = students[0].average;
    float lowest = students[0].average;

    for (int i = 1; i < totalStudents; i++) {
        if (students[i].average > highest)
            highest = students[i].average;
        if (students[i].average < lowest)
            lowest = students[i].average;
    }

    cout << "Highest Average  " << highest << endl;
    cout << "Lowest Average " << lowest << endl;
}


int main() {
    cout << " Ali Anan Ansari - ID'41268'"<<endl;
    cout <<  " STUDENT MANAGEMENT SYSTEM"<<endl;

    int choice;
    do {
        cout << "1. Add Student"<<endl;
        cout << "2. View Students"<<endl;
        cout << "3. Remove Student"<<endl;
        cout << "4. Calculate Highest & Lowest Avg"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1: 
                 addStudent(); 
                    break;
            case 2:
                  displayStudents();
                      break;
            case 3:
                  removeStudent();
                     break;
            case 4:
                  calculateMarks();
                       break;
            case 5: 
                 cout << "Exiting program"<<endl; 
                               break;
            default: 
                     cout << "Invalid choice"<<endl;
        }
    } 
    while (choice != 5);

    return 0;
}
