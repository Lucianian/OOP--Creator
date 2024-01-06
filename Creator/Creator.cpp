#include <iostream>
#include <string>

#include "Teacher.h"
#include "Student.h"
#include "Test.h"

using namespace std;

class Creator
{

public:

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
            cout << "Enter right command";
            StartInterface();
            break;
        }
    }

    void CreateTeacher()
    {
        cout << "Enter teacher's name";
        cin >> name;
        cout << "Enter teacher's password";
        cin >> password;

        Teachers[numTeachers] = new Teacher(name, password);
        numTeachers += 1;
        StartInterface();
    }

    void CreateStudent()
    {
        cout << "Enter student's name";
        cin >> name;
        cout << "Enter student's password";
        cin >> password;

        Students[numStudents] = new Student(name, password);
        numStudents += 1;
        StartInterface();
    }

    void LogInTeacher()
    {
        cout << "Enter teacher's name";
        cin >> name;
        for (int i = 0; i < numTeachers && Teachers[i] != nullptr; i++)
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
        for (int i = 0; i < numStudents && Teachers[i] != nullptr; i++)
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

    //-----------------------------------

    void TeacherInterphase(Teacher* ptr) 
    {
        cout << "...";
        cin >> answer;

        switch (answer)
        {
        case 1:
            // Teacher's Data
            ptr->showData();
            break;

        case 2:
            // Create test
            CreateTest();
            break;

        case 3:
            // Choose test

            cout << "Enter test's name";
            cin >> name;
            for (int i = 0; i < numTests && Tests[i] != nullptr; i++)
            {
                if (name == Tests[i]->name)
                {
                    TestInterphase(Tests[i]);
                    return;
                }
            }
            cout << "Such test doesn't exist yet.";
            TeacherInterphase(ptr);

            break;

        case 4:
            // Show statistics
            ptr->ShowTeacherStat();
            break;

        case 5:
            // Delete account
            delete ptr;

            int replacer;
            for (int i = 0; Teachers[i] != nullptr; i++) { replacer  = i+1 }
            for (int i = replacer; i <= numTeachers; i++) { Teachers[i] = Teachers[i+1] }

            numTeachers -= 1;
            break;

        case 6:
            // Exit
            StartInterface();
            break;

        default:
            // Error
            cout << "Enter right command";
            TeacherInterphase(ptr);
            break;
        }
    }

    void CreateTest()
    {
        cout << "Enter test's name";
        cin >> name;

        Tests[numTests] = new Test(name);
        numTests += 1;
        TeacherInterphase();
    }

    void TestInterphase(Test* ptr) 
    {
        cout << "...";
        cin >> answer;

        switch (answer)
        {
        case 1:
            // Test Data
            ptr->showData();
            break;

        case 2:
            // Choose question

            cout << "Enter question's number";
            cin >> number;
            for (int i = 0; i < ptr->numQuestions && ptr->Question[i] != nullptr; i++)
            {
                if (number == ptr->Question[i]->number)
                {
                    QuestionInterphase(ptr->Question[i], ptr);
                    return;
                }
            }
            cout << "Such question doesn't exist yet.";
            TestInterphase(ptr);

            break;

        case 3:
            // Delete
            delete ptr;

            Test* replacer;
            for (int i = 0; Tests[i] != nullptr; i++) { replacer = i + 1 }
            for (int i = replacer; i <= numTests; i++) { Tests[i] = Tests[i + 1] }

            numTests -= 1;
            break;

        default:
            // Error
            cout << "Enter right command";
            TestInterphase(ptr);
            break;
        }
    }

    void QuestionInterphase(Question* ptr, Test* test) 
    {
        cout << "...";
        cin >> answer;

        switch (answer)
        {
        case 1:
            // Question Data
            ptr->showData();
            break;

        case 2:
            // Change answer

            cout << "Enter answer's number";
            cin >> number;
            for (int i = 0; i < ptr->numAnswers && ptr->Answer[i] != nullptr; i++)
            {
                if (number == ptr->Answers[i]->number)
                {
                    ptr->Answers[i]->Reduct();
                    return;
                }
            }
            cout << "Such answer doesn't exist yet.";
            QuestionInterphase(ptr);

            break;

        case 3:
            // Delete
            delete ptr;

            Question* replacer;
            for (int i = 0; test->Questions[i] != nullptr; i++) { replacer = i + 1 }
            for (int i = replacer; i <= test->numQuestions; i++) { test->Questions[i] = test->Questions[i + 1] }

            test->numQuestions -= 1;
            break;

        default:
            // Error
            cout << "Enter right command";
            QuestionInterphase(ptr, test);
            break;
        }
        
    }

    //-----------------------------------

    void StudentInterphase(Student* ptr) 
    {
        cout << "...";
        cin >> answer;

        switch (answer)
        {
        case 1:
            // Student's Data
            ptr->showData();
            break;

        case 2:
            // Pass the test

            cout << "Enter test's name";
            cin >> name;
            for (int i = 0; i < numTests && Tests[i] != nullptr; i++)
            {
                if (name == Tests[i]->name)
                {
                    Tests[i]->TestPass();
                    return;
                }
            }
            cout << "Such test doesn't exist yet.";
            StudentInterphase(ptr);
            break;

        case 4:
            // Show statistics
            ptr->ShowStudentStat();
            break;

        case 5:
            // Delete account
            delete ptr;

            Student* replacer;
            for (int i = 0; Students[i] != nullptr; i++) { replacer = i + 1 }
            for (int i = replacer; i <= numStudents; i++) { Students[i] = Students[i + 1] }

            numStudents -= 1;
            break;

        case 6:
            // Exit
            StartInterface();
            break;

        default:
            // Error
            cout << "Enter right command";
            StudentInterphase(ptr);
            break;
        }
        
    }

private:

    Teacher* Teachers[10];
    Student* Students[50];
    Test* Tests[100];

    int answer;
    string name, password;

    int numTeachers = 0, numStudents = 0, numTests = 0;

};




int main()
{
    Creator Testing;
    Testing->StartInterface();
    return 0;
}
