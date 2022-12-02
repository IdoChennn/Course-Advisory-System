#include "../../Algorithm/Algorithm7.cpp"
///
///Testing class for algorithm7
///it is pretty much the same as testing class for algorithm6
///@Author Baishen Jiang
///@Author Mingyu Yu
///
class AlgorithmTest7 {
public:
    Algorithm7 algorithm7;

    AlgorithmTest7(vector<float> recommendCourse, vector<float> recommendInstructor, vector<float> impactfulFromTheCourse, vector<float> improvements){
        algorithm7.setRecommendCourse(recommendCourse);
        algorithm7.setRecommendInstructor(recommendInstructor);
        algorithm7.setImpactfulFromTheCourse(impactfulFromTheCourse);
        algorithm7.setImprovements(improvements);
    }

    ~AlgorithmTest7(){}

    bool getHighCommentRateTest(float expectedAnswer, vector<float> dataset){
        return expectedAnswer == algorithm7.getHighCommentRate(dataset);
    }

    bool getDataSetAverageTest(float expectedAnswer, vector<float> dataset){
        return abs(expectedAnswer - algorithm7.getDataSetAverage(dataset)) < 0.01 ? true : false;
    }

    bool getOverallFeedbackScoreTest(float expectedAnswer){
        return abs(expectedAnswer - algorithm7.getOverallFeedbackScore()) < 0.01 ? true : false;
    }

};

int main(){
    vector<float> recommendCourse{3,4,5};
    vector<float> recommendInstructor{3,4,5};
    vector<float> impactfulFromTheCourse{3,4,5};
    vector<float> improvements{3,4,5};

    AlgorithmTest7 algorithmTest7(recommendCourse, recommendInstructor, impactfulFromTheCourse, improvements);

    // all happy test
    float expectedAnswer1 = 2;
    if(algorithmTest7.getHighCommentRateTest(expectedAnswer1, recommendCourse))
        cout << "getHighCommentRate function happy test passed" << endl;
    else
        cout << "getHighCommentRate function happy test failed" << endl;

    float expectedAnswer2 = 4.0;
    if(algorithmTest7.getDataSetAverageTest(expectedAnswer2, recommendCourse))
        cout << "getDataSetAverage function happy test passed" << endl;
    else
        cout << "getDataSetAverage function happy test failed" << endl;

    float expectedAnswer3 = 4.0;
    if(algorithmTest7.getOverallFeedbackScoreTest(expectedAnswer3))
        cout << "getOverallFeedbackScore function happy test passed" << endl;
    else
        cout << "getOverallFeedbackScore function happy test failed" << endl;

    // all exception test
    // test for 102 value error in getDataSetAverage
    vector<float> temp;
    try {
        algorithmTest7.getDataSetAverageTest(expectedAnswer2, temp);
        cout << "getDataSetAverage 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getDataSetAverage 102 value error test passed" << endl;
    }

}