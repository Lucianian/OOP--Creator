#include <iostream>
#include <string>

#include "Teacher.h"
#include "Student.h"
#include "Test.h"

using namespace std;

class Creator
{

public:
    Creator( /*char num, const string& text, bool isCorrect*/ ) : /*option(option), text(text), isCorrect(isCorrect)*/ {}



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





/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class Answer
{
public:
    Answer(char option, const string& text, bool isCorrect) : option(option), text(text), isCorrect(isCorrect) {}

    char getOption() const
    {
        return option;
    }

    const string& getText() const
    {
        return text;
    }

    bool isCorrectAnswer() const
    {
        return isCorrect;
    }

private:
    char option;
    string text;
    bool isCorrect;
};

class Pair
{
public:
    Pair(char leftOption, const string& left, char rightOption, const string& right) : leftOption(leftOption), left(left), rightOption(rightOption), right(right) {}

    char getLeftOption() const
    {
        return leftOption;
    }

    const string& getLeft() const
    {
        return left;
    }

    char getRightOption() const
    {
        return rightOption;
    }

    const string& getRight() const
    {
        return right;
    }

private:
    char leftOption;
    string left;
    char rightOption;
    string right;
};

class Question
{
public:
    Question(const string& questionText) : questionText(questionText) {}

    const string& getQuestionText() const
    {
        return questionText;
    }

    virtual void addAnswer(char option, const string& text, bool isCorrect)
    {
        answers.push_back(Answer(option, text, isCorrect));
    }

    const vector<Answer>& getAnswers() const
    {
        return answers;
    }

    virtual void display() const
    {
        cout << "Question: " << getQuestionText() << endl;
        cout << "Answers:" << endl;

        for (const auto& answer : answers)
        {
            cout << "- " << answer.getOption() << ". " << answer.getText() << endl;
        }
    }

    bool checkAnswer(char userAnswer) const
    {
        auto it = find_if(answers.begin(), answers.end(),
            [userAnswer](const Answer& answer) { return answer.getOption() == userAnswer; });

        return it != answers.end() && it->isCorrectAnswer();
    }

    virtual ~Question() {}

private:
    string questionText;
    vector<Answer> answers;
};

class SingleChoiceQuestion : public Question
{
public:
    using Question::Question;

    void display() const override
    {
        Question::display();
        cout << "Type: Single Choice" << endl;
    }
};

class MultipleChoiceQuestion : public Question
{
public:
    using Question::Question;

    void display() const override
    {
        Question::display();
        cout << "Type: Multiple Choice" << endl;
    }
};

class MatchingQuestion : public Question
{
public:
    using Question::Question;

    void addPair(char leftOption, const string& left, char rightOption, const string& right)
    {
        pairs.push_back(Pair(leftOption, left, rightOption, right));
    }

    void display() const override
    {
        Question::display();
        cout << "Type: Matching" << endl;
        cout << "Pairs:" << endl;

        for (const auto& pair : pairs)
        {
            cout << "- " << pair.getLeftOption() << ". " << pair.getLeft() << " <-> " << pair.getRightOption() << ". " << pair.getRight() << endl;
        }
    }

    bool checkAnswer(char leftOption, char rightOption) const
    {
        auto it = find_if(pairs.begin(), pairs.end(),
            [leftOption, rightOption](const auto& pair)
            {
                return pair.getLeftOption() == leftOption && pair.getRightOption() == rightOption;
            });

        return it != pairs.end();
    }

private:
    vector<Pair> pairs;
};

class ChronologyQuestion : public Question
{
public:
    using Question::Question;

    void display() const override
    {
        Question::display();
        cout << "Type: Chronology" << endl;
    }
};

