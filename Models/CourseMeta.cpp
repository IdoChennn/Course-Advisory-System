#include "ModelHeader.h"


using namespace std;

///
///Empty constructor of the class. To create an object without passing parameters
///
CourseMeta::CourseMeta(){
}

///
///Destructor of the class
///
CourseMeta::~CourseMeta(){

}

///
///Constructor of the class. CourseMeta object includes all information about a course by wrapping up all other objects in this module.
///@brief wrapper class that includes all other class objects in this module
///@param student student object
///@param course course object
///@param StudentFeedback student evaluation about instructor
///@param studentRecommend student evaluation about the course
///
CourseMeta::CourseMeta(Student student,Course course,StudentFeedback studentFeedback,StudentRecommend studentRecommend){
        this->student = student;
        this->course = course;
        this->studentFeedback = studentFeedback;
        this->studentRecommend = studentRecommend;
}

///
///Setter method for private attribute student
///@brief setter
///@param student student object
///
void CourseMeta::setStudent(Student student){

    this->student = student;

}

///
///Setter method for private attribute course
///@brief setter
///@param course course object
///
void CourseMeta::setCourse(Course course){
    this->course=course;
}

///
///Setter method for private attribute studentFeedback
///@brief setter
///@param studentFeedback studentFeedback object
///
void CourseMeta::setStudentFeedback(StudentFeedback studentFeedback){
    this->studentFeedback=studentFeedback;
}

///
///Setter method for private attribute studentRecommend
///@brief setter
///@param studentRecommend studentRecommend object
///
void CourseMeta::setStudentRecommend(StudentRecommend studentRecommend){
    this->studentRecommend=studentRecommend;
}

///
///getter method for private attribute student
///@brief getter
///@return student object
///
Student CourseMeta::getStudent(){
    return student;
}

///
///getter method for private attribute course
///@brief getter
///@return course object
///
Course CourseMeta::getCourse(){
    return course;
}

///
///getter method for private attribute studentFeedback
///@brief getter
///@return studentFeedback object
///
StudentFeedback CourseMeta::getStudentFeedback(){
    return studentFeedback;
}

///
///getter method for private attribute studentRecommend
///@brief getter
///@return studentRecommend object
///
StudentRecommend CourseMeta::getStudentRecommend(){
    return studentRecommend;
}