#include "config.h"
///
///This is the sixth result generating algorithm
///This algorithm focus on feedbacks that students give to the course instructor - instructor rate
///The arithmetic is: a feedback would contains four evaluation standards - 1. if the instructor can give positive feedback about assignments;
///2. if the instructor can give clear rubric and evaluation criteria for assignments and tests; 3. if the instructor makes the
///lecture interactive and fun; 4. if the instructor can return the assignment on time, each of the parts have a mark from 1 to 5
///, and finally we find the average of all four parts to find instructor rate
///@brief Find instructor rate (how student evaluate the instructor)
///@author Yanwen Wang
///@author Ido Chen
///@author Baishen Jiang
///
class Algorithm6 {
private:
    vector<float> assignmentFeedback; /*<points made by all students if the instructor can give positive feedback about assignments;>*/
    vector<float> assignmentDemonstrate; /*<points made by all students if the instructor can give clear rubric and evaluation criteria for assignments and tests;>*/
    vector<float> classDesign; /*<points made by all students if the instructor makes the lecture interactive and fun;>*/
    vector<float> assignmentReturn; /*<points made by all students if the instructor can return the assignment on time>*/

public:
    ///
    ///empty constructor
    ///
    Algorithm6() {}

    ///
    ///constructor of the algorithm. Find instructor rate (how student evaluate the instructor)
    ///@brief instructor rate
    ///@param assignmentFeedback points made by all students if the instructor can give positive feedback about assignments
    ///@param assignmentDemonstrate points made by all students if the instructor can give clear rubric and evaluation criteria for assignments and tests
    ///@param classDesign points made by all students if the instructor makes the lecture interactive and fun
    ///@param assignmentReturn points made by all students if the instructor can return the assignment on time
    ///
    Algorithm6(vector<float> assignmentFeedback, vector<float> assignmentDemonstrate, vector<float> classDesign, vector<float> assignmentReturn) {
        this->assignmentFeedback = assignmentFeedback;
        this->assignmentDemonstrate = assignmentDemonstrate;
        this->classDesign = classDesign;
        this->assignmentReturn = assignmentReturn;
    }
    ///
    ///deconstructor
    ///
    ~Algorithm6() {}

    ///
    ///This method finds students who gives the instructor a rate above 4 in any of the four evaluation standard.
    ///@brief find who gives high (above 4) rate
    ///@param dataset inputting one of evaluation standard
    ///@return number of students who gives the instructor a high rate
    ///
    float getHighCommentRate(vector<float> dataset){
        const float HIGHESTRATE = 5.0;
        float counter = 0.0; /*<number of students>*/
        float threshold = 0.8 * HIGHESTRATE; /*<defined "high" rate>*/
        for(float data : dataset){
            if(data >= threshold)
                counter += 1;
        }
        return counter;
    }

    ///
    ///This method finds the average point for an evaluation standard
    ///@brief finds the average point for an evaluation standard
    ///@param dataset inputting one of evaluation standard
    ///@return average point of an evaluation standard
    ///
    float getDataSetAverage(vector<float> dataset){
        float result = 0.0;
        int size = dataset.size();
        if(size == 0) throw 102;

        for(int i = 0; i < size; i++){
            result += dataset[i];
        }

        return result/size;
    }
    ///
    ///This method calculates the average point for all evaluation standards
    ///@brief average point for all evaluation standards
    ///@return the average point between all four standards
    ///
    float getOverallFeedbackScore(){
        float result = 0.0;
        result += getDataSetAverage(assignmentFeedback);
        result += getDataSetAverage(assignmentReturn);
        result += getDataSetAverage(assignmentDemonstrate);
        result += getDataSetAverage(classDesign);
        return result/4.0;
    }

    ///
    ///set new values in assignmentFeedback standard container
    ///@brief setter
    ///@param assignmentFeedback assignmentFeedback standard container that stores new points made by student
    ///
    void setAssignmentFeedback(vector<float> assignmentFeedback){
        this->assignmentFeedback = assignmentFeedback;
    }
    ///
    ///set new values in assignmentReturn standard container
    ///@brief setter
    ///@param assignmentReturn assignmentReturn standard container that stores new points made by student
    ///
    void setAssignmentReturn(vector<float> assignmentReturn){
        this->assignmentReturn = assignmentReturn;
    }
    ///
    ///set new values in assignmentDemonstrate standard container
    ///@brief setter
    ///@param assignmentDemonstrate assignmentDemonstrate standard container that stores new points made by student
    ///
    void setAssignmentDemonstrate(vector<float> assignmentDemonstrate){
        this->assignmentDemonstrate = assignmentDemonstrate;
    }

    ///
    ///set new values in classDesign standard container
    ///@brief setter
    ///@param classDesign classDesign standard container that stores new points made by student
    ///
    void setClassDesign(vector<float> classDesign){
        this->classDesign = classDesign;
    }


};