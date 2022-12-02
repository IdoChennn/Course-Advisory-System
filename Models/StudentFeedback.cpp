#include "ModelHeader.h"
using namespace std;

///
///Empty constructor of the class. To create an object without passing parameters
///
StudentFeedback::StudentFeedback(){

}

///
///constructor of the class. A studentFeedback object contains information of students' evaluation about the instructor (4 standards)
///@brief students' evaluation about the instructor
///@param assignmentFeedback students' evaluation about the instructor in terms of the assignment feedback instructor gives to the student
///@param assignmentDemonstrate students' evaluation about the instructor in terms of the clarity of the given assignment criteria.
///@param assignmentReturn students' evaluation about the instructor in terms of assignment return time
///@param classDesign students' evaluation about the instructor in terms of the overall design of the class structure
///
StudentFeedback::StudentFeedback(std::vector<float> assignmentFeedback,std::vector<float> assignmentDemonstrate,
                    std::vector<float> assignmentReturn,std::vector<float> classDesign){
    
    this->assignmentFeedback = assignmentFeedback;
    this->assignmentDemonstrate = assignmentDemonstrate;
    this->assignmentReturn = assignmentReturn;
    this->classDesign = classDesign;

}

///
///setter method of private attribute assignmentFeedback
///@brief setter
///@param assignmentFeedback students' evaluation about the instructor in terms of the assignment feedback instructor gives to the student
///
void StudentFeedback::setAssignmentFeedback(std::vector<float> assignmentFeedback){
    this->assignmentFeedback = assignmentFeedback;
}

///
///setter method of private attribute assignmentDemonstrate
///@brief setter
///@param assignmentDemonstrate students' evaluation about the instructor in terms of the clarity of the given assignment criteria.
///
void StudentFeedback::setAssignmentDemonstrate(std::vector<float> assignmentDemonstrate){
    this->assignmentDemonstrate=assignmentDemonstrate;
}

///
///setter method of private attribute assignmentReturn
///@brief setter
///@param assignmentReturn students' evaluation about the instructor in terms of assignment return time
///
void StudentFeedback::setAssignmentReturn(std::vector<float> assignmentReturn){
    this->assignmentReturn=assignmentReturn;
}

///
///setter method of private attribute classDesign
///@brief setter
///@param classDesign students' evaluation about the instructor in terms of the overall design of the class structure
///
void StudentFeedback::setAssignmentClassDesign(std::vector<float> classDesign){
    this->classDesign=classDesign;
}

///
///getter method of private attribute assignmentFeedback
///@brief getter
///@return students' evaluation about the instructor in terms of the assignment feedback instructor gives to the student
///
std::vector<float> StudentFeedback::getAssignmentFeedback(){
    return assignmentFeedback;
}

///
///getter method of private attribute assignmentDemonstrate
///@brief getter
///@return  students' evaluation about the instructor in terms of the clarity of the given assignment criteria.
///
std::vector<float> StudentFeedback::getAssignmentDemonstrate(){
    return assignmentDemonstrate;
}

///
///getter method of private attribute assignmentReturn
///@brief getter
///@return students' evaluation about the instructor in terms of assignment return time
///
std::vector<float> StudentFeedback::getAssignmentReturn(){
    return assignmentReturn;
}

///
///getter method of private attribute classDesign
///@brief getter
///@return students' evaluation about the instructor in terms of the overall design of the class structure
///
std::vector<float> StudentFeedback::getAssignmentClassDesign(){
    return classDesign;
}

///
///destructor of the class
///
StudentFeedback::~StudentFeedback(){
}