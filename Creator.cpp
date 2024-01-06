#include <iostream>
#include <string>

#include "Teacher.h"
#include "Student.h"
#include "Test.h"

using namespace std;

class Creator
{

public:
    Creator() {}



    void StartInterface() 
    {

        cout << "...";
        cin >> answer;

        switch (answer) 
        {
        case 1: 
            // Create new teacher account
            CreateTeacher();
            break;

        case 2: 
            // Log in as a teacher 
            LogInTeacher();
            break;

        case 3: 
            // Create new student account 
            CreateStudent();
            break;

        case 4: 
            // Log in as a student 
            LogInStudent();
            break;

        case 5: 
            // Exit
            break;

        default: 
            // Error
            cout << "Enter write command";
            StartInterface();
            break;
        }
    }

    void TeacherInterphase(Teacher* ptr) {}

    void StudentInterphase(Student* ptr) {}

    void CreateTeacher() 
    {
        cout << "Enter teacher's name";
        cin >> name;
        cout << "Enter teacher's password";
        cin >> password;

        Teachers[numTeachers] = new Teacher(name, password);
        StartInterface();
    }

    void CreateStudent() 
    {
        cout << "Enter student's name";
        cin >> name;
        cout << "Enter student's password";
        cin >> password;

        Students[numStudents] = new Student(name, password);
        StartInterface();
    }

    void LogInTeacher()
    {
        cout << "Enter teacher's name";
        cin >> name;
        for (int i = 0; i < numTeachers; i++) 
        {
            if (name == Teachers[i]->name) 
            {
                cout << "Enter teacher's password";
                cin >> password;
                if (password == Teachers[i]->password)
                {
                    TeacherInterphase(Teachers[i]);
                }
                return;
            }
        }
        cout << "Such person doesn't exist yet.";
        StartInterface();
    }

    void LogInStudent() 
    {
        cout << "Enter student's name";
        cin >> name;
        for (int i = 0; i < numStudents; i++)
        {
            if (name == Students[i]->name)
            {
                cout << "Enter student's password";
                cin >> password;
                if (password == Students[i]->password)
                {
                    StudentInterphase(Students[i]);
                }
                return;
            }
        }
        cout << "Such person doesn't exist yet.";
        StartInterface();
    }


    


private:

    Teacher* Teachers[10];
    Student* Students[50];
    Test* Tests[100];

    int answer;
    string name, password;

    int numTeachers = 0;
    int numStudents = 0;

    void CreateAccount() {}
    void logIn() {}
    void 

};




int main()
{
    bool run = 1;

    while (run) 
    {

    }
}


