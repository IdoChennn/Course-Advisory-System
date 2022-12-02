#include "../../Algorithm/Algorithm6.cpp"
///
///Testing class for algorithm 6.
///This testing class tests if the algorithm can produce the correct number students who give high feedback points to the instructor.
///This testing class tests if the algorithm can produce the correct average points for a specific evaluation standard.
///This testing class tests if the algorithm can produce the correct average points of average points for each of the four standards (find the average of averages).
///@author Baishen Jiang
///@author Mingyu Yu
///
class AlgorithmTest6 {
public:
    Algorithm6 algorithm6; /*<algorithm 6 testing object>*/

    ///
    ///constructor of the class
    ///@param assignmentFeedback testing data points made by all students if the instructor can give positive feedback about assignments
    ///@param assignmentDemonstrate testing data points made by all students if the instructor can give clear rubric and evaluation criteria for assignments and tests
    ///@param classDesign testing data points made by all students if the instructor makes the lecture interactive and fun
    ///@param assignmentReturn testing data points made by all students if the instructor can return the assignment on time
    ///
    AlgorithmTest6(vector<float> assignmentFeedback, vector<float> assignmentDemonstrate, vector<float> classDesign, vector<float> assignmentReturn){
        algorithm6.setAssignmentFeedback(assignmentFeedback);
        algorithm6.setAssignmentReturn(assignmentReturn);
        algorithm6.setAssignmentDemonstrate(assignmentDemonstrate);
        algorithm6.setClassDesign(classDesign);
    }

    ///
    ///deconstructor
    ///
    ~AlgorithmTest6(){}

    ///
    ///this method tests if the algorithm can produce the correct number students who give high feedback points to the instructor
    ///@param expectedAnswer the expected number that we wish the algorithm to produce
    ///@param dataset testing data for any of four standards
    ///@return ture if matched; false otherwise
    ///
    bool getHighCommentRateTest(float expectedAnswer, vector<float> dataset){
        return expectedAnswer == algorithm6.getHighCommentRate(dataset);
    }

    ///
    ///this method tests if the algorithm can produce the correct value of average points for the given standards
    ///@param expectedAnswer the expected number that we wish the algorithm to produce
    ///@param dataset testing data for any of four standards
    ///@return ture if matched; false otherwise
    ///
    bool getDataSetAverageTest(float expectedAnswer, vector<float> dataset){
        return abs(expectedAnswer - algorithm6.getDataSetAverage(dataset)) < 0.01 ? true : false;
    }

    ///
    ///this method tests if the algorithm can produce the correct value of the average of each standard's averages
    ///@param expectedAnswer the expected number that we wish the algorithm to produce
    ///@param dataset testing data for any of four standards
    ///@return ture if matched; false otherwise
    ///
    bool getOverallFeedbackScoreTest(float expectedAnswer){
        return abs(expectedAnswer - algorithm6.getOverallFeedbackScore()) < 0.01 ? true : false;
    }

};
//driver code for testing
int main(){
    //initializing testing code
    vector<float> assignmentFeedback{3,4,5};
    vector<float> assignmentDemonstrate{3,4,5};
    vector<float> classDesign{3,4,5};
    vector<float> assignmentReturn{3,4,5};

    AlgorithmTest6 algorithmTest6(assignmentReturn, assignmentDemonstrate, assignmentFeedback, classDesign);

    // all happy test
    float expectedAnswer1 = 2;
    if(algorithmTest6.getHighCommentRateTest(expectedAnswer1, assignmentFeedback))
        cout << "getHighCommentRate function happy test passed" << endl;
    else
        cout << "getHighCommentRate function happy test failed" << endl;

    float expectedAnswer2 = 4.0;
    if(algorithmTest6.getDataSetAverageTest(expectedAnswer2, assignmentFeedback))
        cout << "getDataSetAverage function happy test passed" << endl;
    else
        cout << "getDataSetAverage function happy test failed" << endl;

    float expectedAnswer3 = 4.0;
    if(algorithmTest6.getOverallFeedbackScoreTest(expectedAnswer3))
        cout << "getOverallFeedbackScore function happy test passed" << endl;
    else
        cout << "getOverallFeedbackScore function happy test failed" << endl;

    // all exception test
    // test for 102 value error in getDataSetAverage
    vector<float> temp;
    try {
        algorithmTest6.getDataSetAverageTest(expectedAnswer2, temp);
        cout << "getDataSetAverage 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getDataSetAverage 102 value error test passed" << endl;
    }

}