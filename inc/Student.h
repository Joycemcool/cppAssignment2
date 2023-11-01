//
// Created by joyce on 2023-10-31.
//
//Preprocessor guards guard
#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H

#include <string>
#include <iostream>
//TODO: Solution implements header files with appropriate pre-processor directives and guards.
using namespace std;

class Student{

private:
    string name;
    int numCourses;
    string* courseList;

public:
    //Constructors
    Student(); //Default constructor
    Student(const string& name); // Constructor with name
    Student(const Student& other); // Copy constructor

    //Methods
    void setName(const string& newName);

    // Destructor
    ~Student();

    // Assignment operator
    Student& operator=(const Student& other);

    // Add a course
    void addCourse(const string& courseName);

    // Print student info
    void print() const;

    // Reset courses and courseList
    void resetCourses();

    friend ostream& operator<<(ostream& os, const Student& student);

};

#endif //UNTITLED1_STUDENT_H
