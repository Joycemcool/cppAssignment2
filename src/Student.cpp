//
// Created by joyce on 2023-10-31.
//

#include <iostream>
#include <conio.h>
#include <algorithm>
#include "../inc/Student.h" // programmer defined header
using namespace std;

// Default constructor
Student::Student() : name(""), numCourses(0), courseList(nullptr) {
    cout<<"\nCall default constructor"<<endl;
}

//Set name
void Student::setName(const string& newName) {
    cout<<"Call setName method "<<endl;
    name = newName;
}

//STRING Constructor with name
Student::Student(const string& studentName) : name(studentName), numCourses(0), courseList(nullptr) {
    cout<<"\nCall string constructor"<<endl;
}

// Copy constructor
Student::Student(const Student& other) : name(other.name), numCourses(other.numCourses), courseList(nullptr)
{
    cout<<"\nCall copy constructor"<<endl;
    if (other.numCourses > 0) {
        courseList = new string[other.numCourses];
        for (int i = 0; i < other.numCourses; ++i) {
            courseList[i] = other.courseList[i];
        }
    }
}

// Destructor
Student::~Student() {
    cout<<"Dynamically allocated courseList is destroyed"<<endl;
    //If delete null pointer, crash
    if (courseList != nullptr){
        delete[] courseList;
    }
}
//Overloaded Assignment Operator
Student& Student::operator=(const Student& other) {

    cout<<"\nCreate the third student (student3) by using the custom assignment operator"<<endl;

    if (this != &other) {
        delete[] courseList; //Deallocate the memory used by the current courseList

        //Copy the name and the number of courses from the other student
        name = other.name;
        numCourses = other.numCourses;

        if (other.numCourses > 0) {
            courseList = new string[other.numCourses];
            //TODO: Is this satisfy Implements a 'dynamic' array
            for (int i = 0; i < other.numCourses; ++i) {
                courseList[i] = other.courseList[i];
            }

        }
    }
    return *this;
}

// Add a course to the student's list
void Student::addCourse(const string& course) {
    string* addCourseList = new string[numCourses + 1];
    for (int i = 0; i < numCourses; ++i) {
        addCourseList[i] = courseList[i];
    }
    addCourseList[numCourses] = course;
    delete[] courseList;
    courseList = addCourseList;
    numCourses++;
}

// Reset courses and courseList
void Student::resetCourses() {
    cout<<"Call reset method"<<endl;
    delete[] courseList;
    numCourses = 0;
    courseList = nullptr;
};

// Print student's name and courses
void Student::print() const {
    cout<<"Print Method: student name and course list"<<endl;
    cout << "Name: " << name << endl;
    cout << "Number of Courses: " << numCourses << endl;
    if(numCourses == 0){
        cout << "Courses Not Available\n";
    }
    cout << "";
    for (int i = 0; i < numCourses; ++i) {
        cout <<"Course " <<(i+1) <<" " + courseList[i] << endl;
    }
}

// Friend function to overload the << operator for Student objects
ostream& operator<<(ostream& os, const Student& student) {
    cout<<"\nFriend function to overload the << operator"<<endl;
    os << "Name: " << student.name << endl;
    os << "Number of Courses: " << student.numCourses << endl;
//    os << "Courses: ";
    if (student.numCourses == 0) {
        os << "Not Available\n";
    }
    for (int i = 0; i < student.numCourses; ++i) {
        os << "Course " <<(i+1) <<" "+student.courseList[i] << endl;
    }
    return os;
}

