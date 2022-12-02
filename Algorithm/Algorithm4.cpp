#include "config.h"
///
///This is the fourth result-generating algorithm.
///This algorithm introduces the idea of student lecture utilization ratio,
///meaning that how well the student can utilize the lecture to achieve better grade.
///The arithmetic for this algorithm is: grade average/[ ( ( average attendance/ total attendance of the course) +
//( average study time / total suggested study time ) ) / 2 ] = student lecture utilization rate.
///@brief Find student lecture utilization ratio
///@author Yanwen Wang
///@author Ido Chen
///@author baishen Jiang
///

class Algorithm4{
private:
    vector<float> studentGrades; /*<a vector that stores all students' grade>*/
    vector<float> studentAttendances; /*<a vector that stores all students' class attendance>*/
    vector<float> studentStudyHours; /*<a vector that stores all students' time spent in the course>*/
public:
    ///
    ///empty constructor of the class
    ///
    Algorithm4(){}

    ///
    ///constructor of the class. Find student lecture utilization ratio
    ///@brief lecture utilization ratio
    ///@param studentGrades all students' grade
    ///@param studentAttendances
    Algorithm4(vector<float> studentGrades, vector<float> studentAttendances,vector<float> studentStudyHours){
        this->studentGrades = studentGrades;
        this->studentAttendances = studentAttendances;
        this->studentStudyHours = studentStudyHours;
        if(!allSizeEquals() || studentGrades.empty() || studentAttendances.empty() || studentStudyHours.empty()) throw 102;
    }

    ///
    ///deconstructor of the class
    ///
    ~Algorithm4(){}

    ///
    ///This method calculates the average grade among all students' grade
    ///@brief average grade
    ///@return average grade
    ///
    float getAverageGrade(){
        if(studentGrades.empty() || !allSizeEquals()) throw 102;
        //calculating average using accumulate
        return accumulate(studentGrades.begin(),studentGrades.end(),0.0) / studentGrades.size();
    }

    ///
    ///This method calculates the average attendance among all students
    ///@brief average attendance
    ///@return average attendance
    ///
    float getAverageAttendance(){
        if(studentAttendances.empty() || !allSizeEquals()) throw 102;
        //calculating average using accumulate
        return accumulate(studentAttendances.begin(),studentAttendances.end(),0.0) / studentAttendances.size();
    }

    ///
    ///This method calculates the average study hours for all students
    ///@brief average study hours
    ///@return average grade
    ///
    float getAverageStudyHours(){
        if(studentStudyHours.empty() || !allSizeEquals()) throw 102;
        //calculating average using accumulate
        return accumulate(studentStudyHours.begin(),studentStudyHours.end(),0.0) / studentStudyHours.size();
    }

    ///
    ///This method check if the size of three vectors does not match.
    ///If not, then there must be error in data fetching phase
    ///@brief equal vector size checker
    ///@return ture if all equal; false otherwise
    ///
    bool allSizeEquals(){
        if(studentGrades.size() == studentAttendances.size() && studentAttendances.size() == studentStudyHours.size())
            return true;
        return false;
    }

    ///
    ///This is the core arithmetic of this algorithm calculating the student lecture utilization rate.
    ///@brief lecture utilization rate calculator
    ///@return student lecture utilization rate
    ///
    float getLectureUtilizationRates(){
        const float TOTALSTUDYTIME = 144.0;
        const float TOTALGRADE = 100.0;
        const float TOTALATTENDANCE = 8.0;

        float attendanceRatio = getAverageAttendance()/TOTALATTENDANCE; /*<propagation of students' average attendance relative to the total number of class of a course>*/
        float studyHoursRatio = getAverageStudyHours()/TOTALSTUDYTIME;  /*<propagation of students' average study hour relative to the total study hour suggested by the instructor>*/
        float averageGrade = getAverageGrade()/TOTALGRADE; /*<propagation of students' average grade relative to the full grade of the course>*/
        float studentEffort = attendanceRatio+studyHoursRatio; /*<efforts made by students>*/
        if(studentEffort == 0) throw 101;
        return averageGrade/(studentEffort/2);
    }

    ///
    ///pass new student grades to this algorithm
    ///@brief setter
    ///@param studentGrades new student grades to be passed
    ///
    void setStudentGrades(vector<float> studentGrades){
        this->studentGrades = studentGrades;
    }
    ///
    ///pass new student attendance to this algorithm
    ///@brief setter
    ///@param studentGrades new student attendance to be passed
    ///

    void setStudentAttendances(vector<float> studentAttendances){
        this->studentAttendances = studentAttendances;
    }

    ///
    ///pass new student study hours to this algorithm
    ///@brief setter
    ///@param studentGrades new student hours to be passed
    ///
    void setStudentStudyHours(vector<float> studentStudyHours){
        this->studentStudyHours = studentStudyHours;
    }

};
