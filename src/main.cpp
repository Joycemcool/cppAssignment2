#include <iostream>
#include <algorithm>
#include <string>
#include "../inc/Student.h"  // Include the Student header

using namespace std;

//Helper function - check input
bool isNullOrWhitespace(const std::string& str) {
    return str.empty()
           || std::all_of(str.begin(), str.end(), [](char c) {
        return std::isspace(static_cast<unsigned char>(c));
    });
}

// Function to trim leading and trailing spaces from a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) {
        return "";  // The string is all spaces
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {

    string Continue;

    while(true){
        // Create the first student (student1)
        Student student1;
        string name1, course;

        //create the first student using default constructor
        do{
            cout << "Enter the name of the first student: ";
            getline(cin,name1);
        } while(isNullOrWhitespace(name1));

        // Call default constructor

        student1 = Student();
        student1.setName(name1);
        //student1 = Student(name1);

        do {
            cout << "Enter a course for student 1 (or 'exit' to finish): ";
            getline(cin,course);
            if (course != "exit") {
                student1.addCourse(course);
            }
        } while (course != "exit");

        // Display the first student (student1)
        cout << "Student 1:\n";
        student1.print();

        // Create the second student (student2) by copying the first student's courses, this is copy constructor
        //Student student2 = student1;

        string name2;
        cout << "Enter the name of the second student: ";
        cin >> name2;
        //String constructor
        Student student2 = Student(student1);
        student2.setName(name2);


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
        cout << "Student 3 (using the assignment operator):\n";        //student3.print();
        student3 = student2;

        string name3;
        cout << "Enter the name of the third student: ";
        cin >> name3;
        student3.setName(name3);

        // Display the third student (student 3)
        cout << student3;

        cout<<"Do you want to continue? (yes/no): ";
        cin>>Continue;
        // Trim leading and trailing spaces and convert to lowercase
        if(!Continue.empty()){
            Continue = trim(Continue);
            Continue = toLower(Continue);
            if(Continue== "yes" ){
                cout<<"Allow looping back or exit"<<endl;
                //student3.~Student();
                //Destructor altomatically call.
                continue;

            } else
            {
                cout<<"Thank you"<<endl;
                break;
            }
        }
//        else{
//            break;
//        }
    }

    return 0;
}
