#include "ModelHeader.h"

using namespace std;

///
///Empty constructor of the class. To create an object without passing parameters
///
Student::Student(){

}

///
///A student object wraps up all student record object. In other words, a student object is a container of student records objects
///@brief studentRecords objects wrapper
///@param studentData container of studentRecords
///
Student::Student(std::map<int, StudentRecord> studentData){

    this->studentData=studentData;

}

///
///setter method of private attribute studentData
///@brief setter
///@param studentData container of studentRecords
///
void Student::setStudent(std::map<int, StudentRecord> studentData){
    this->studentData=studentData;
}

///
///getter method of private attribute studentData
///@brief getter
///@param studentData container of studentRecords
///
map<int, StudentRecord> Student::getStudentData(){
    return studentData;
}

///
///Deconstructor of the class
///
Student::~Student(){

}