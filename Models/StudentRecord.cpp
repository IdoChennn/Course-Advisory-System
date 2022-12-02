#include "ModelHeader.h"
using namespace std;

///
///Empty constructor of the class. To create an object without passing parameters
///
StudentRecord::StudentRecord(){

}

///
///Constructor of the class
///@param studentID student identification number
///@param studentName name of the student
///@param quizMark student quiz mark
///@param exmMark student exam mark
///@param assignmentRecord student assignments' mark (container of a student's all assignment grade)
///@param totalHoursSpent total amount of time spent by student on the course
///@param overallGrade student's course grade
///
StudentRecord::StudentRecord(int studentID, std::string studentName, std::vector<float> quizMark,
                  std::vector<float> exmMark, std::map<float, float> assignmentRecord,
                  float totalHoursSpent, float overallGrade){

    this->studentID = studentID;
    this->studentName = studentName;
    this->quizMark = quizMark;
    this->exmMark = exmMark;
    this->assignmentRecord = assignmentRecord;
    this->totalHoursSpent = totalHoursSpent;
    this->overallGrade = overallGrade;

}

///
///setter method of the private attribute studentID
///@param student identification number
///
void StudentRecord::setStudentId(int studentID){
    this->studentID = studentID;
}

///
///setter method of the private attribute studentName
///@param studentName student name
///
void StudentRecord::setStudentName(std::string studentName){
    this->studentName = studentName;
}

///
///setter method of the private attribute quizMark
///@param quizMark student quiz mark
///
void StudentRecord::setQuizMark(std::vector<float> quizMark){
    this->quizMark = quizMark;
}

///
///setter method of the private attribute exmMark
///@param quizMark student exam mark
///
void StudentRecord::setExmMark(std::vector<float> exmMark){

    this->exmMark = exmMark;
}

///
///setter method of the private attribute assignmentRecord
///@param assignmentRecord student assignments' mark (container of a student's all assignment grade)
///
void StudentRecord::setAssignmentRecord(std::map<float,float> assignmentRecord){
    this->assignmentRecord = assignmentRecord;
}

///
///setter method of the private attribute totalHoursSpent
///@param totalHoursSpent total amount of time spent by student on the course
///
void StudentRecord::setTotalHoursSpent(float totalHoursSpent){
    this->totalHoursSpent=totalHoursSpent;
}

///
///setter method of the private attribute overallGrade
///@param overallGrade student's course grade
///
void StudentRecord::setOverallGrade(float overallGrade){
    this->overallGrade = overallGrade;
}

///
///getter method of the private attribute studentID
///@return student identification number
///
int StudentRecord::getStudentId(){
    return studentID;
}

///
///getter method of the private attribute studentName
///@return studentName student name
///
std::string StudentRecord::getStudentName(){
    return studentName;
}

///
///getter method of the private attribute quizMark
///@return quizMark quiz mark
///
std::vector<float> StudentRecord::getQuizMark(){
    return quizMark;
}

///
///getter method of the private attribute exmMark
///@return exmMark exam mark
///
std::vector<float> StudentRecord::getExmMark(){
    return exmMark;
}

///
///getter method of the private attribute assignmentRecord
///@return assignmentRecord student assignments' mark (container of a student's all assignment grade)
///
std::map<float,float> StudentRecord::getAssignmentRecord(){
    return assignmentRecord;
}

///
///getter method of the private attribute totalHoursSpent
///@return totalHoursSpent total amount of time spent by student on the course
///
float StudentRecord::getTotalHoursSpent(){
    return totalHoursSpent;
}

///
///getter method of the private attribute overallGrade
///@return overallGrade student's course grade
///
float StudentRecord::getOverallGrade(){
    return overallGrade;
}

///
///destructor of the class
///
StudentRecord::~StudentRecord(){
}
