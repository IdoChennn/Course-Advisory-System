#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include "config.h"
using namespace std;

///
///In algorithm2, we calculate the Grade&time rate (what amount of time does the student normally spend to achieve certain course grade):
///sum of time for all students spent in the
///grade range / total number of students in the grade range / number of weeks for a term
///(eg. a total of 250 hours spent by 10 students in grade range from 80 to 90 / 10 students / 10 weeks = 2.5 hours
///--> student who gets 90 normally takes 2.5 hours a week).
///@brief calculate the Grade&time rate
///@author Yanwen wang
///@author Ido Chen
///@author Baishen Jiang
///
class Algorithm2{
    private:
        map<int, pair<int,vector<int>>> studentRecords; /*<a map that contains all student records, such as quiz mark, exam mark, time spent on this course, and etc.>*/
    public:

        ///
        ///constructor for not passing any parameters
        ///
        Algorithm2(){}

        ///
        ///constructor for algorithm 2 class. calculate the Grade&time rate
        ///@brief Grade&time rate
        ///@param studentRecords the container that stores all students' data
        ///
        Algorithm2(map<int, pair<int,vector<int>>> studentRecords){
            this->studentRecords = studentRecords;
        }
        ///
        ///deconstructor of the class
        ///
        ~Algorithm2(){}

        ///
        ///This class extracts students from a specific grade range, such as 60-70 or 85-90
        ///brief extracts students from a specific grade range
        ///@param range the desired range
        ///@return the records of students in that grade range
        ///
        pair<int, vector<int>> getStudentRecordsWithRange(int range){

            if(range > 9 || range < 0) throw 102;
            int count = 0;
            return studentRecords[range];
        }
         ///
         ///This class calculates the average grade&time rate for students in a specific grade range
         ///@brief average grade&time rate for certain range
         ///@param range the desired range
         ///@return the average grade&time rate for students in the input grade range
         ///
        float getAverageStudentEffortRate(int range){
            pair<int, vector<int>> studentPairs = getStudentRecordsWithRange(range); /*<container that stores the filtered student records based on the input grade range>*/
            float totalPeople = studentPairs.first; /*<number of students in the input grade range>*/
            //arithmetic error if number of students is zero but there are student records
            if (totalPeople == 0) throw 101;
            vector<int> timeVector = studentPairs.second; /*<container that stores the time spent by students in the input grade range>*/
            if(totalPeople != timeVector.size()) throw 102;
            float sum = 0;
            for(auto hours: timeVector){
                sum += hours;
            }
            return sum/totalPeople;
        }

        ///
        ///This class calculates students' average grade&time rate for all grade ranges.
        ///At the start, we intend to loop the getAverageStudentEffortRate() method to get all grade range's grade&time rate
        ///However, if we do so, then the time complexity would be huge O^3. Thus, in this getAllRangeRate, we just create a new
        ///way to access all grade range. (that is why you wouldn't see getAverageStudentEffortRate() method here. )
        ///@brief get students' average grade&time rate for all grade ranges.
        ///@return a map container that stores average grade&time rate for all grade ranges (from 1(0-10%) to 9(90% - 100%))
        ///
        map<int, float> getAllRangeRate(){
            map<int, float> result; /*<container that stores all average grade&time rate corresponding to grade ranges>*/
            int count = 0;
            map<int, pair<int,vector<int>>>::iterator itr;
            for (itr = studentRecords.begin(); itr != studentRecords.end(); ++itr) {
                int range = itr->first;
                pair<int, vector<int>> studentEffortTime = itr->second;
                if(range > 9 || range < 0) throw 102; //if the grade range exceeds the boundary, then return 102 value error.

                int totalPeople = studentEffortTime.first;
                if(totalPeople == 0) throw 101;
                vector<int> timeVector = studentEffortTime.second;
                if(totalPeople != timeVector.size()) throw 102;
                int sum = 0;
                for(auto hours: timeVector){
                    sum += hours;
                }
                //insert values of every grade&time rate for all grade range.
                result.insert(make_pair(range, sum/totalPeople));
                count++;
            }
            return result;
        }

        ///
        ///setter method for private attribute studentRecords
        ///@brief setter
        ///@param studentRecords a map that contains all student records
        ///
        void setStudentRecords(map<int, pair<int,vector<int>>> studentRecords){
            this->studentRecords = studentRecords;
        }

};