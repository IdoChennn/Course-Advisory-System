#include "config.h"
///
///This is the fifth result-generating algorithm.
///This algorithm has two parts. Firstly, it calculates the course activity participation rate based on the attendance of various class activities
///, such as attendance of quiz, office hour, and lecture.
///Secondly, this algorithm calculates the fluctuation degree of activity participation rate ranging from {before-midterm midterm, after-midterm, before-finalExam}.
///In other words, how fluctuate is the activity participation rate throughout the term.
///@brief find course activity participation rate and course activity participation rate based on certain time range
///@author Yanwen Wang
///@author Ido Chen
///@author Baishen jiang
///
class Algorithm5{
private:

    //Note that: for every pair stored in each of the vector, the first float stores the number of total attendance for the activity during one of the four periods
    //; the second float stores the average attendance among all students for the activity during the corresponding period.
    vector<pair<float, float>> quizAttendance; /*<stores the quiz attendance information>*/
    vector<pair<float, float>> officeHourAttendance; /*<stores the office hour attendance information>*/
    vector<pair<float, float>> lectureAttendance;  /*<stores the lecture attendance information>*/
public:
    ///
    ///empty constructor
    ///
    Algorithm5(){}
    ///
    ///constructor of the class. find course activity participation rate and course activity participation rate based on certain time range
    ///@brief course activity participation
    ///@param quizAttendance quiz attendance information
    ///@param officeHourAttendance office hour attendance information
    ///@param lectureAttendance lecture attendance information
    ///
    Algorithm5(vector<pair<float, float>> quizAttendance,vector<pair<float, float>> officeHourAttendance,vector<pair<float, float>> lectureAttendance){
        this->quizAttendance = quizAttendance;
        this->officeHourAttendance = officeHourAttendance;
        this->lectureAttendance = lectureAttendance;
    }
    ///
    ///deconstructor
    ///
    ~Algorithm5(){}

    ///
    ///This method calculates one of activity rate during certain quart time
    ///@brief activity rate during certain quart time
    ///@param data attendance information about the activity in one period. .First is total attendance; .second is average attendance among students
    ///@return the attendance rate for a specific period.
    ///
    float getQuartRate(pair<float, float> data){
        float actualAttendance = data.first;/*<average attendance among students>*/
        float totalAttendace = data.second;/*<total attendance in one of the period for one of the activity>*/
        if(totalAttendace == 0) throw 101;
        return actualAttendance / totalAttendace;
    }

    ///
    ///This method produces attendance rates for one of activity.
    ///@brief attendance rates for one of activity.
    ///@param dataset activity attendance information.
    ///@return participation rates of an activity ranging from the four periods.
    ///
    vector<float> getAttendanceRate(vector<pair<float, float>> dataset) {
        vector<float> result; /*<result container for one activity>*/
        for(pair<float, float> data: dataset){
            result.push_back(getQuartRate(data));
        }
        return result;
    }
    ///
    ///This method calculates the fluctuation degree of participation rates for one activity
    ///(e.g. if participation rates for office hour throughout a term is [80%,70%,90%,40%,70%],
    ///then the flotation degree would be [80%-70%=-10%, 70%-90%=-20%, ......])
    ///@brief the fluctuation degree of participation rates for one activity during several time periods
    ///@param participation rates of an activity ranging from the four periods.
    ///@return flotation degree of participation rates of an activity ranging from the four periods.
    ///
    vector<float> getAttendanceRateChange(vector<float> dataset) {
        vector<float> result; /*<result container for one activity>*/
        float cur = 0.0;
        for(int i = 1; i < dataset.size(); i++){
            if(dataset[i-1] == 0) throw 101;
            result.push_back((dataset[i]-dataset[i-1])/dataset[i-1]);
        }
        return result;
    }
    ///
    ///get quiz attendance information
    ///@brief getter
    ///@return quiz attendance information
    ///
    vector<pair<float, float>> getQuizAttendance(){
        return quizAttendance;
    }

    ///
    ///get office hour attendance information
    ///@brief getter
    ///@return office hour attendance information
    ///
    vector<pair<float, float>> getOfficeHourAttendance(){
        return officeHourAttendance;
    }

    ///
    ///get lecture attendance information
    ///@brief getter
    ///@return lecture attendance information
    ///
    vector<pair<float, float>> getLectureAttendance(){
        return lectureAttendance;
    }

    ///
    ///set new quiz attendance information
    ///@brief setter
    ///@param quizAttendance new quiz attendance information
    ///
    void setQuizAttendance(vector<pair<float, float>> quizAttendance){
        this->quizAttendance = quizAttendance;
    }
    ///
    ///set new office hour attendance information
    ///@brief setter
    ///@param officeHourAttendance new office hour attendance information
    ///
    void setOfficeHourAttendance(vector<pair<float, float>> officeHourAttendance){
        this->officeHourAttendance = officeHourAttendance;
    }
    ///
    ///set new lecture attendance information
    ///@brief setter
    ///@param lectureAttendance new lecture  attendance information
    ///
    void setLectureAttendance(vector<pair<float, float>> lectureAttendance){
        this->lectureAttendance = lectureAttendance;
    }

};
//end of algorithm5