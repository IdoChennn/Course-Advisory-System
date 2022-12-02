#include "config.h"
using namespace std;
///
///This is the third result generating algorithm
///This algorithm looks for  Student efficiency rate
///The arithmetic is: (Student's grade) / (Time spent in the course)
///Higher the rate; more effective the student studying the course.
///@brief Find student efficiency rate
///@author Yanwen wang
///@author Ido Chen
///@author Baishen Jiang
///
class Algorithm3 {
private:
    // student id <grade,time used>
    map<int, pair<float, float>> studentRecords; /*<a map container that stores all students' records>*/

public:
    ///
    ///Empty constructor
    ///
    Algorithm3(){}

    ///
    ///Constructor for this class. Find student efficiency rate
    ///@brief student efficiency rate
    ///@param studentRecords all student's data in the course.
    ///
    Algorithm3(map<int, pair<float, float>> studentRecords){
        this->studentRecords = studentRecords;
    }

    ///
    ///deconstructor of the class
    ///
    ~Algorithm3(){}

    ///
    ///This methods calculates a the student efficiency rate for a specific student.
    ///@brief efficiency rate for a specific student.
    ///@param record the record for the specific student
    ///@result the rate for that student
    ///
    float getStudentEfficientRatio(pair<float, float> record){

        const float TOTALSTUDYTIME = 144.0;
        const float TOTALGRADE = 100.0;


        float grade = record.first; /*< grade of the student>*/
        float timeUsed = record.second; /*< time spent by the student for the course*/
        if(timeUsed == 0 || grade == 0) throw 101;
        float timeUsedRatio = timeUsed/TOTALSTUDYTIME;
        float result = (grade/TOTALGRADE) / timeUsedRatio;
        return result;
    }

    ///
    ///This method calculates the student efficiency rate for every student at once
    ///@brief all students' efficiency rate
    ///@return rates for all students
    ///
    vector<int> getAllStudentEfficientRatio() {
        vector<int> result(11, 0);
        map<int, pair<float, float>>::iterator itr;
        for (itr = studentRecords.begin(); itr != studentRecords.end(); ++itr) {
            float ratio = getStudentEfficientRatio(itr->second);
            int level = ratio*10;
            if(level >= 10)
                level = 10;
            result[level] += 1;
        }
        return result;
    }
    ///
    ///set student records
    ///@brief setter
    ///@param studentRecords student records to be set.
    ///
    void setStudentRecords(map<int, pair<float,float>> studentRecords){
        this->studentRecords = studentRecords;
    }

};