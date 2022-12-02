#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include "config.h"
using namespace std;
///
/// This is the first result generating algorithm
/// This algorithm will find out the degree of difficulty of assignments in one of the instructor's course
/// The arithmetic of this algorithm: (assignmentAssignedTime/CompletionTime) / averageAssignmentGrade. If the result is close
/// to 0, it means that the assignment is too easy; if the result is close to 1, it means that the assignment has moderate difficultly;
/// if the result close to 1.5 or greater, it means that the assignment is too hard.
///@brief find degree of difficulty of assignments
///@author Yanwen wang
///@author Ido Chen
///@author Baishen Jiang
///
class Algorithm1 {

    private:
        int size; /*!< the number of students doing the assigment */
        vector<float> completionTime; /*!< the vector container that contains all students' assignment completion time */
        int assignTime; /*!< the time assigned for finishing the assignment*/
        vector<float> mark; /*!< the vector container that contains all students' assignment mark*/


        int stdDeviationOfCompletionTime; /*!< The standard Deviation Of Completion Time among all students*/
        int stdDeviationOfaverageMark; /*!< The standard Deviation Of Completion Time among all students*/

        //these three variables will be used for removing outliers among values in a vector
        float median = 0; /*!< median of values in a vector*/
        float firstQmedian = 0; /*!< median of first quartile of values in a vector*/
        float thirdQmedian = 0; /*!< median of third quartile of values in a vector*/

    public:

        ///
        ///Empty constructor for creating an algorithm1 object without passing parameters
        ///
        Algorithm1(){}

        ///
        ///This is the actual constructor of the Algorithm1 class. Find degree of difficulty of assignments
        ///@brief Find difficulty of assignments
        ///@param size The number of students doing the assignment
        ///@param completionTime all students' actual assignment completion time
        ///@param time time assigned for finishing the assignment
        ///@param mark all students' assignment mark
        ///

        Algorithm1(int size, vector<float> completionTime, int assignTime, vector<float> mark){
            this->size = size;
            this->completionTime = completionTime;
            this->assignTime = assignTime;
            this->mark = mark;

            // if the size passed is zero, then there must a error during the inputting phase. Throw error 101
            if(size==0) throw 101;
        }

        ///
        ///This method calculates the average completion time for all student finishing the assignment.
        ///@brief calculates the average completion time
        ///@return average completion time
        ///
        float getAverageCompletionTime(){
            if(size==0) throw 101; // 0 can not be divided, throw 101 arithmetic error
            if(!isAllVectorSizeEqually()) throw 102; // if time and mark vectors does not have same size, then return 102 not matching error
            int sum = 0; /*!< adder of all completion times*/
            for(auto i = completionTime.begin(); i != completionTime.end(); ++i)
                sum += *i;
            return sum/size;
        }

        ///
        ///This method calculates the average completion time for all students finishing the assignment without outlier values
        ///@brief calculates the average completion time (no outliers)
        ///@return average completion time without outliers
        ///
        float getAverageCompletionTimeNoOutliers(){
            if(size==0) throw 101;
            // if(!isAllVectorSizeEqually()) throw 102;
            float sum = 0; /*!< adder of all completion times*/

            // calling the outlier remove to clean the outliers of completion time vector
            vector<float> temp2 = removeOutlierForTimeAndMark(completionTime);
            for(auto i = temp2.begin(); i != temp2.end(); ++i)
                sum += *i;
            return sum/size;

        }

        ///
        /// This method calculates the average assignment mark
        ///@brief average assignment mark
        /// @return average assignment mark in %
        ///
        float getAverageMark(){
            if(size==0) throw 101;
            // if(!isAllVectorSizeEqually()) throw 102;
            float sum = 0; /*!< adder of all assignment marks*/
            for(auto i = mark.begin(); i != mark.end(); ++i)
                sum += *i;

            return sum/size/10;
        }

        ///
        ///This method calculates the average assignment mark without outlier values
        ///@brief average assignment mark without outlier values
        ///@return average assignment mark in %
        ///
        float getAverageMarkNoOutlier(){
            if(size==0) throw 101;
            // if(!isAllVectorSizeEqually()) throw 102;
            float sum = 0; /*!< adder of all assignment marks*/
            vector<float> temp1 = removeOutlierForTimeAndMark(mark);

            for(auto i = temp1.begin(); i != temp1.end(); ++i){

                sum += *i;
                }

            return sum/size/10;
        }

        ///
        /// This method calculates both first and third quartiles for a vector values container.
        ////Part of finding result without outliers
        ///@brief calculates first and third quartiles of given vector
        /// The result of this function is later used by the outliers remover.
        /// @param targetVector value containers that is either for completion time or mark.
        ///
        void getQuartilesMedian(vector<float> targetVector){

            // sort the input vector in an acceding order.
            sort(targetVector.begin(), targetVector.end());

            int indexOfMedian = 0; /*!< The index of median value in the sorted values vector */

            // if the value of size is odd then find median directly;
            // if the value of size is even then find the average of two median numbers.
            if (size % 2 != 0){

                median = targetVector[size/2];
                indexOfMedian = size/2;
            }
            else{
                median = (targetVector[size/2] + targetVector[(size-1)/2]) / 2;
                indexOfMedian = size/2;
            }

            if( indexOfMedian % 2 == 0){

                if(size%2 != 0){
                    firstQmedian = (targetVector[(indexOfMedian/2)] + targetVector[(indexOfMedian/2)-1]) / 2;
                    thirdQmedian = (targetVector[indexOfMedian+indexOfMedian/2] + targetVector[indexOfMedian+indexOfMedian/2+1])/2;
                }
                else{

                    firstQmedian = targetVector[(indexOfMedian/2)-1];
                    thirdQmedian = targetVector[indexOfMedian+indexOfMedian/2];
                }

           }
           else{

                if (size%2 !=0){

                    firstQmedian = targetVector[indexOfMedian/2];
                    thirdQmedian = targetVector[indexOfMedian/2 + indexOfMedian + 1];
                }

                else{

                    firstQmedian = (targetVector[indexOfMedian/2] + targetVector[indexOfMedian/2 - 1])/2;
                    thirdQmedian = (targetVector[indexOfMedian + indexOfMedian/2] + targetVector[indexOfMedian + indexOfMedian/2 +1])/2;

                }

           }

        }

        ///
        /// This method removes the outliers from the first and third quartiles of values in a container
        /// , based on the quartiles defined by previous quartiles finding method
        ///@brief outlier remover
        /// @param inputVector the container from which the outliers are going to be removed
        /// @return clean container without outliers
        ///
        vector<float> removeOutlierForTimeAndMark(vector<float> inputVector){


            float iq = 0; /*!< Inter-quartile Range*/
            getQuartilesMedian(inputVector);
            iq = thirdQmedian - firstQmedian;
            vector<float> backupVector = inputVector; /*!< the vector that clones from the input vector is going to be modified */
            vector<float> storIndex; /*!< the index of outliers in the vector */

            //store te index of outliers
            for (int i = 0; i < size; i++){
                if(inputVector[i] < (firstQmedian - (1.5*iq))){

                    storIndex.push_back(i);


                }
                else if (inputVector[i] > (thirdQmedian + (1.5*iq)))
                {
                    storIndex.push_back(i);

                }

            }
            reverse(storIndex.begin(),storIndex.end());
            vector<float>::iterator itr = backupVector.begin(); /*!< the iterator that reads indexes in the index vector*/


            for(int i: storIndex){

                // removes outliers from the cloned input vector
                backupVector.erase(itr+i);


            }

            return backupVector;
        }

        ///
        /// This method calculates the standard deviation of the average completion time
        ///@brief standard deviation for average completion time .
        ///@return standard deviation of the average completion time
        ///
        float getStdDeviationOfAVGCompletionTime(){
            float variance = 0; /*!< the sum of all students' variance from average completion time*/
            float singleVariance = 0; /*!< variance for every single student*/
            float averageTimeForCompletion = getAverageCompletionTime(); /*!< average completion time*/
            for(auto i = completionTime.begin(); i != completionTime.end(); ++i){

                //arithmetic for standard deviation
                singleVariance = (*i - averageTimeForCompletion);
                variance += pow(singleVariance, 2.0);

            }
            variance = variance/size;
            stdDeviationOfCompletionTime = sqrt(variance);

            return stdDeviationOfCompletionTime;

        }

        ///
        /// This method calculates the standard deviation of the average assignment mark
        ///@brief standard deviation for average assignment mark.
        ///@return standard deviation of the average assignment mark
        ///
        float getStdDeviationOfAVGMark(){
            float variance = 0; /*!< the sum of all students' variance from average assignment mark*/
            float singleVariance = 0; /*!< variance for every single student*/
            float averageMark = getAverageMark() * 100;
            for(auto i = mark.begin(); i != mark.end(); ++i){

                singleVariance = (*i - averageMark);
                variance += pow(singleVariance, 2.0);

            }
            variance = variance/size;
            stdDeviationOfaverageMark = sqrt(variance);
            return stdDeviationOfaverageMark;

        }

        ///
        /// This method is the core of this algorithm that calculates the degree of assignment difficulty
        ///@brief calculates the degree of assignment difficulty
        /// @return the degree of assignment difficulty
        ///
        float getDegreeOfDifficulty(){
            if(getAverageCompletionTime()==0 || getAverageMark()==0) throw 101;
            return assignTime/getAverageCompletionTime()/getAverageMark();
        }

        ///
        /// This method is the core of this algorithm that calculates the degree of assignment difficulty without outliers
        ///@brief calculates the degree of assignment difficulty without outliers
        ///@return the degree of assignment difficulty without the effect of outliers
        ///
        float getDegreeOfDifficultyNoOutliers(){
            if(getAverageCompletionTimeNoOutliers() == 0 || getAverageMarkNoOutlier() == 0) throw 101;
            cout<<assignTime/getAverageCompletionTimeNoOutliers()/getAverageMarkNoOutlier()<<endl;
            return assignTime/getAverageCompletionTimeNoOutliers()/getAverageMarkNoOutlier();

        }

        ///
        /// test if the number of items in the two vectors are the same
        ///@brief same vector size validator
        ///@return true if same; false if not the same
        ///
        bool isAllVectorSizeEqually(){
            if(completionTime.size() != size && mark.size() != size) return true;
            return true;
        }

        ///
        /// get the size of students doing the assignment
        ///@brief attribute getter
        /// @return the number of size
        ///
        int getAssignmentSize(){
            return size;
        }
        ///
        /// setter for size variables
        ///@brief attribute setter
        ///@param value of new size that is going to be set.
        ///
        void setSize(int size){
            this->size = size;
        }

        ///
        ///get the container of all students' completion time
        ///@brief attribute getter
        ///@return the completion time container
        ///
        vector<float> getCompletionTime(){
            return completionTime;
        }

        ///
        ///set the container of all students' completion time
        ///@brief attribute setter
        ///@param the new completion container that is going to be used
        ///
        void setCompletionTime(vector<float> completionTime){
            this->completionTime = completionTime;
        }

        ///
        ///get the assign time
        ///@brief attribute getter
        ///@return assign time
        ///
        int getAssignTime(){
            return assignTime;
        }

        ///
        ///set the assign time
        ///@brief attribute setter
        ///@param new assign time that is going to be passed.
        ///
        void setAssignTime(int assignTime){
            this->assignTime = assignTime;
        }

        ///
        ///get the container for all students' assignment mark
        ///@brief attribute getter
        ///@return the mark container
        ///
        vector<float> getMark(){
            return mark;
        }

        ///
        ///set the new mark container
        ///@brief attribute setter
        ///@param new mark container
        ///
        void setMark(vector<float> mark){
            this->mark = mark;
        }
};
//end of file
