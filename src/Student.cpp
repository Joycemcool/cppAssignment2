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
    cout<<"Call default constructor"<<endl;
    //Need to call this method
}

//Set name for the default constructor
void Student::setName(const string& newName) {
    name = newName;
}

// TODO: IS THIS STRING CONSTRUCTOR Constructor with name
Student::Student(const string& studentName) : name(studentName), numCourses(0), courseList(nullptr) {
    cout<<"Call string constructor"<<endl;

}

// Copy constructor
Student::Student(const Student& other) : name(other.name), numCourses(other.numCourses), courseList(nullptr)
{
    cout<<"Call copy constructor"<<endl;
    if (other.numCourses > 0) {
        courseList = new string[other.numCourses];
        for (int i = 0; i < other.numCourses; ++i) {
            courseList[i] = other.courseList[i];
        }
    }
}

// Destructor
Student::~Student() {
    delete[] courseList;
}

//TODO:Solution implements a correctly functioning overloaded assignment operator. How to overload
Student& Student::operator=(const Student& other) {

    cout<<"Create the third student (student3) by using the custom assignment operator"<<endl;

    if (this != &other) {
        delete[] courseList; //Deallocate the memory used by the current courseList

        //Copy the name and the number of courses from the other student
        name = other.name;
        numCourses = other.numCourses;


        if (other.numCourses > 0) {
            courseList = new string[other.numCourses];
            //TODO: Is this satisfy Implements a 'dynamic' array
            // i.e. declared on the Heap that is manually 'resized' to demonstrate the concept of
            // a 'deep copy'

            for (int i = 0; i < other.numCourses; ++i) {
                courseList[i] = other.courseList[i];
            }

        }
    }
    return *this;
}

// Add a course to the student's list
void Student::addCourse(const string& course) {
    string* newCourseList = new string[numCourses + 1];
    for (int i = 0; i < numCourses; ++i) {
        newCourseList[i] = courseList[i];
    }
    newCourseList[numCourses] = course;
    delete[] courseList;
    courseList = newCourseList;
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
    //TODO: Student class contains one 'print()' method that outputs the name and list of all
    // courses and one overloaded use of << to do same.
    cout<<"Print Method: student name and course list"<<endl;
    cout << "Name: " << name << endl;
    cout << "Number of Courses: " << numCourses << endl;
    cout << "Courses: ";
    if(numCourses == 0){
        cout << "Not Available\n";
    }
    cout << "";
    for (int i = 0; i < numCourses; ++i) {
        cout << courseList[i] << endl;
    }
}

