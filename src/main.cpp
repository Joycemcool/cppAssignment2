#include <iostream>
#include "../inc/Student.h"  // Include the Student header

using namespace std;

int main() {

    string Continue;

    while(true){
        // Create the first student (student1)
        Student student1;
        string name1, course;
        cout << "Enter the name of the first student: ";
        cin >> name1;
        student1 = Student(name1);

        // TODO: Inputs all values from the user, including the list of class names supporting input for an
        // TODO: arbitrary number of courses. Key methods identify themselves when called.
        do {
            cout << "Enter a course for student 1 (or 'exit' to finish): ";
            cin >> course;
            if (course != "exit") {
                student1.addCourse(course);
            }
        } while (course != "exit");

        // Display the first student (student1)
        cout << "Student 1:\n";
        student1.print();



        // Create the second student (student2) by copying the first student's courses
        Student student2 = student1;

        string name2;
        cout << "Enter the name of the second student: ";
        cin >> name2;
        //student2 = Student(name2);


        // Display the courses originally from student1 for student2
        cout << "Student 2 (courses originally from Student 1) :\n";
        student2.print();


        // Reset courses for the first student (student1)
        student1.resetCourses();

        // Display the first student (student1) after resetting courses
        cout << "Student 1 (after resetting courses):\n";
        student1.print();

        // Create the third student (student3) by using the custom assignment operator
        Student student3;
        student3 = student2;

        // Display the third student (student 3)
        cout << "Student 3 (using the assignment operator):\n";
        student3.print();

        cout<<"Do you want to continue? (yes/no): ";

        cin>> Continue;
        if(Continue == "yes"){
            cout<<"Allow looping back or exit"<<endl;
            continue;
        }
        else{
            break;
        }
    }

    return 0;
}
