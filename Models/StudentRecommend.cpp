#include "ModelHeader.h"
using namespace std;

///
///Empty constructor of the class. To create an object without passing parameters
///
StudentRecommend::StudentRecommend(){

};

///
///Constructor of the class. A studentRecommend object contains information of students' evaluation about the course (4 standards)
///@brief students' evaluation about the course
///@param recommendCourse students' evaluation about the course in terms of whether the student would like recommend the course to friends
///@param recommendInstructor students' evaluation about the course in terms of whether the student would like recommend the instructor to friends
///@param impactful students' evaluation about the course in terms of whether the student feel the course is impactful to his/her study or life
///@param improvements students' evaluation about the course in terms of whether the student feel the course can improve his/her skills
///
StudentRecommend::StudentRecommend(std::vector<float> recommendCourse,std::vector<float> recommendInstructor,
                     std::vector<float> impactful,std::vector<float> improvements){

    this->recommendCourse = recommendCourse;
    this->recommendInstructor = recommendInstructor;
    this->impactful = impactful;
    this->improvements=improvements;

};

void StudentRecommend::setRecommendCourse(std::vector<float> recommendCourse){
    this->recommendCourse=recommendCourse;
}

void StudentRecommend::setRecommendInstructor(std::vector<float> recommendInstructor){
    this->recommendInstructor = recommendInstructor;
}

void StudentRecommend::setImpactful(std::vector<float> impactful){
    this->impactful=impactful;
}

void StudentRecommend::setImprovements(std::vector<float> improvements){
    this->improvements=improvements;
}

std::vector<float> StudentRecommend::getRecommendCourse(){
    return recommendCourse;
}

std::vector<float> StudentRecommend::getRecommendInstructor(){
    return recommendInstructor;
}

std::vector<float> StudentRecommend::getImpactFul(){
    return impactful;
}

std::vector<float> StudentRecommend::getImprovements(){
    return improvements;
}
StudentRecommend::~StudentRecommend(){
};