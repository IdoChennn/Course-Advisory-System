#include "ModelHeader.h"

using namespace std;

///
///Destructor of the class
///
Course::Course(){

}

///
///Constructor of the class that defines a course object
///@param numberOfStudent number of students in the course
///@param courseAverage average mark of the course
///@param assignmentAssignTime time assigned to students to complete the course work
///@param assignmentGrade assignment mark
///@param exmGrade exam mark
///@param quizGrade quiz mark
///@param firstQuartData course information during first 1/4 of the term
///@param SecondQuartData course information during second 1/4 of the term
///@param ThirdQuartData course information during third 1/4 of the term
///@param FourthQuartData course information during fourth 1/4 of the term
///
Course::Course(int numberOfStudent,float courseAverage,
           std::vector<float> assignmentAssignTime,
           std::vector<float> assignmentGrade,std::vector<float> exmGrade,
           std::vector<float> quizGrade,std::vector<float> firstQuartData,
           std::vector<float> SecondQuartData,std::vector<float> ThirdQuartData,
           std::vector<float> FourthQuartData){
    this->numberOfStudent = numberOfStudent;
    this->courseAverage = courseAverage;
    this->assignmentAssignTime = assignmentAssignTime;
    this->assignmentGrade = assignmentGrade;
    this->exmGrade=exmGrade;
    this->quizGrade=quizGrade;
    this->firstQuartData=firstQuartData;
    this->SecondQuartData=SecondQuartData;
    this->ThirdQuartData=ThirdQuartData;
    this->FourthQuartData=FourthQuartData;
    
}

///
///setter method of private attribute number of student
///@param numberOfStudent number of students in the course
///
void Course::setNumberOfStudent(int numberOfStudent){
    this->numberOfStudent = numberOfStudent;
}

///
///setter method of private attribute courseAverage
///@param courseAverage average mark of the course
///
void Course::setCourseAverage(float courseAverage){
    this->courseAverage = courseAverage;
}

///
///setter method of private attribute assignmentAssignTime
///@param assignmentAssignTime time assigned to students to complete the course work
///
void Course::setAssignmentAssignTime(std::vector<float> assignmentAssignTime){
    this->assignmentAssignTime = assignmentAssignTime;
}

///
///setter method of private attribute assignmentGrade
///@param assignmentGrade assignment mark
///
void Course::setAssignmentGrade(std::vector<float> assignmentGrade){
    this->assignmentGrade = assignmentGrade;
}

///
///setter method of private attribute exmGrade
///@param exmGrade exam mark
///
void Course::setExmGrade(std::vector<float> exmGrade){
    this->exmGrade = exmGrade;
}

///
///setter method of private attribute quizGrade
///@param quizGrade quiz mark
///
void Course::setQuizGrade(std::vector<float> quizGrade){
    this->quizGrade = quizGrade;
}

///
///setter method of private attribute firstQuartData
///@param firstQuartData course information during first 1/4 of the term
///
void Course::setFirstQuartData(std::vector<float> firstQuartData){
    this->firstQuartData = firstQuartData;
}

///
///setter method of private attribute SecondQuartData
///@param SecondQuartData course information during second 1/4 of the term
///
void Course::setSecondQuartData(std::vector<float> SecondQuartData){
    this->SecondQuartData = SecondQuartData;
}

///
///setter method of private attribute ThirdQuartData
///@param ThirdQuartData course information during third 1/4 of the term
///
void Course::setThirdQuartData(std::vector<float> ThirdQuartData){
    this->ThirdQuartData = ThirdQuartData;
}

///
///setter method of private attribute FourthQuartData
///@param FourthQuartData course information during fourth 1/4 of the term
///
void Course::setFourthQuartData(std::vector<float> FourthQuartData){
    this->FourthQuartData = FourthQuartData;
}

///
///getter method of private attribute numberOfStudent
///@return number of students in the course
///
int Course::getNumberOfStudent(){
    return numberOfStudent;
}

///
///getter method of private attribute courseAverage
///@return average grades of the course
///
float Course::getCourseAverage(){
    return courseAverage;
}

///
///getter method of private attribute assignmentAssignTime
///@return time assigned to students to complete the course work
///
std::vector<float> Course::getAssignmentAssignTime(){
    return assignmentAssignTime;
}

///
///getter method of private attribute assignmentGrade
///@return assignment mark
///
std::vector<float> Course::getAssigmentGrade(){
    return assignmentGrade;
}

///
///getter method of private attribute exmGrade
///@return exam mark
///
std::vector<float> Course::getExmGrade(){
    return exmGrade;
}

///
///getter method of private attribute quizGrade
///@return quiz mark
///
std::vector<float> Course::getQuizGrade(){
    return quizGrade;
}

///
///getter method of private attribute firstQuartData
///@return course information during first 1/4 of the term
///
std::vector<float> Course::getFirstQuartGrade(){
    return firstQuartData;
}

///
///getter method of private attribute SecondQuartData
///@return course information during second 1/4 of the term
///
std::vector<float> Course::getSecondQuartGrade(){
    return SecondQuartData;
}

///
///getter method of private attribute ThirdQuartData
///@return course information during third 1/4 of the term
///
std::vector<float> Course::getThirdQuartGrade(){
    return ThirdQuartData;
}

///
///getter method of private attribute FourthQuartData
///@return course information during fourth 1/4 of the term
///
std::vector<float> Course::getFourthQuartGrade(){
    return FourthQuartData;
}

///
///destructor of the class
///
Course::~Course(){

}