#include "../../Models/config.h"
using namespace std;

int main(){

    int studentID = 2;
    string studentName = "ido Chen";
    vector<float> quizMark;
    quizMark.push_back(70.0f);
    quizMark.push_back(80.0f);
    quizMark.push_back(90.0f);
    vector<float> exmMark;
    exmMark.push_back(70.0f);
    exmMark.push_back(80.0f);
    exmMark.push_back(90.0f);
    map<float, float> assignmentRecord;
    assignmentRecord[10.0f] = 10.0f;
    assignmentRecord[20.0f] = 20.0f;
    assignmentRecord[30.0f] = 30.0f;
    float totalHoursSpent = 100.0f;
    float overallGrade = 79.0f;

    StudentRecord oneStudentReord(studentID, studentName, quizMark, exmMark, assignmentRecord,totalHoursSpent,overallGrade);

    map<int, StudentRecord> studentData;
    studentData[1] = oneStudentReord;
    Student oneStudent(studentData);
    
    vector<float> testVector;
    testVector.push_back(1.0f);
    testVector.push_back(2.0f);

    Course courseTestingObj(studentID, totalHoursSpent, testVector,testVector,testVector,testVector,testVector,testVector,testVector,testVector);
    cout << "Course Object Create Success" << endl;
    StudentFeedback studentfbObj(testVector,testVector,testVector,testVector);
    cout << "StudentFeedback Object Create Success" << endl;
    StudentRecommend studentfbObjr(testVector,testVector,testVector,testVector);
    cout << "StudentRecommend Object Create Suceess" << endl;
    CourseMeta finalTesting(oneStudent,courseTestingObj,studentfbObj,studentfbObjr);
    map<int, StudentRecord> studentMap = finalTesting.getStudent().getStudentData();
    for(auto it = studentMap.begin(); it != studentMap.end(); ++it){
        if(it->first == 1)
            cout << "CourseMeta Object Create Suceess" << endl;
    }

    
};