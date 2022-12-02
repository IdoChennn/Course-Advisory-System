#include "../../Algorithm/Algorithm5.cpp"
///
///Tester for algorithm5
///This tester will test all three methods in algorithm by testing if the algorithm can give the expected answer.
///@author Baishen Jiang
///@author Mingyu Yu
///
class AlgorithmTest5 {
public:
    Algorithm5 algorithm5; /*<algorithm 5 testing object>*/

    ///
    ///constructor
    ///@param quizAttendance quiz attendance information for testing
    ///@param officeHourAttendance office hour attendance information for testing
    ///@param lectureAttendance lecture attendance information for testing
    ///
    AlgorithmTest5(vector <pair<float, float>> quizAttendance, vector <pair<float, float>> officeHourAttendance,
                   vector <pair<float, float>> lectureAttendance) {
        algorithm5.setQuizAttendance(quizAttendance);
        algorithm5.setOfficeHourAttendance(officeHourAttendance);
        algorithm5.setLectureAttendance(lectureAttendance);
    }

    ///
    ///deconstuctor
    ///
    ~AlgorithmTest5() {}

    ///
    ///Test if the algorithm can calculate the correct participation rate of an activity for a specific period
    ///@param expectedAnswer expected answer for the rate
    ///@param data testing data
    ///@return true if correct; otherwise, false
    ///
    bool getQuartRateTest(float expectedAnswer, pair<float, float> data) {
        return abs(expectedAnswer - algorithm5.getQuartRate(data)) < 0.01 ? true: false;
    }

    ///
    ///Test if the algorithm can calculate the correct participation rate of an activity for all four periods
    ///@param expectedAnswer expected answer for the rate
    ///@param data testing data
    ///@return true if correct; otherwise, false
    ///
    bool getAttendanceRateTest(vector<float> expectedAnswer, vector<pair<float, float>> dataset){
        vector<float> actualAnswer = algorithm5.getAttendanceRate(dataset);
        return equal(actualAnswer.begin(), actualAnswer.end(), expectedAnswer.begin());
    }

    ///
    ///Test if the algorithm can calculate the correct participation rate of an activity for all four periods
    ///@param expectedAnswer expected answer for the rate
    ///@param data testing data
    ///@return true if correct; otherwise, false
    ///
    bool getAttendanceRateChangeTest(vector<float> expectedAnswer, vector<float> dataset){
        vector<float> actualAnswer = algorithm5.getAttendanceRateChange(dataset);
        if(actualAnswer.size() != expectedAnswer.size()) return false;
        bool result = true;
        for(int i = 0; i < actualAnswer.size(); i++){
            if(abs(actualAnswer[i]-expectedAnswer[i]) > 0.01){
                result = false;
                break;
            }
        }
        return result;
    }

};

//driver code of the test
int main(){

    //making testing data
    vector<pair<float, float>> quizAttendance {make_pair(8,10), make_pair(10,10)};
    vector<pair<float, float>> officeHourAttendance {make_pair(8,10), make_pair(10,10)};
    vector<pair<float, float>> lectureAttendance {make_pair(8,10), make_pair(10,10)};

    AlgorithmTest5 algorithmTest5(quizAttendance, officeHourAttendance, lectureAttendance);

    // follow are test that we hope the algorithm to pass
    if(algorithmTest5.getQuartRateTest(0.8, quizAttendance[0]))
        cout << "getQuartRate function happy test passed" << endl;
    else
        cout << "getQuartRate function happy test failed" << endl;

    vector<float> expectedAnswer1{0.8,1};
    if(algorithmTest5.getAttendanceRateTest(expectedAnswer1, quizAttendance))
        cout << "getAttendanceRate function happy test passed" << endl;
    else
        cout << "getAttendanceRate function happy test failed" << endl;

    vector<float> expectedAnswer2{0.25};
    Algorithm5 algorithm5Temp;
    if(algorithmTest5.getAttendanceRateChangeTest(expectedAnswer2, algorithm5Temp.getAttendanceRate(quizAttendance)))
        cout << "getAttendanceRateChange function happy test passed" << endl;
    else
        cout << "getAttendanceRateChange function happy test failed" << endl;


    // following are test that we would like the algorithm to detect errors
    // test for 101 Arithmetic error in getQuartRate
    try {
        algorithm5Temp.getQuartRate(make_pair(100,0));
        cout << "getQuartRate 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 101)
            cout << "getQuartRate 101 Arithmetic error test passed" << endl;
    }

    // test for 101 Arithmetic error in getAttendanceRateChange
    quizAttendance[0] = make_pair(0,100);
    try {
        algorithm5Temp.getAttendanceRateChange(algorithm5Temp.getAttendanceRate(quizAttendance));
        cout << "getAttendanceRateChange 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 101)
            cout << "getAttendanceRateChange 101 Arithmetic error test passed" << endl;
    }
}