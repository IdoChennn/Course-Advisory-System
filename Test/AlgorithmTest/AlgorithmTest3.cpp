#include <cstdlib>
#include "../../Algorithm/Algorithm3.cpp"
///
///Tester for Algorithm3
///@author Baishen Jiang
///@author Mingyu Yu
///
class AlgorithmTest3 {
public:
    Algorithm3 algorithm3; /*<algorithm 3 object to be tested*/

    ///
    ///Constructor of the testing class
    ///@param studentRecords the student records to be used for testing
    ///
    AlgorithmTest3(map<int, pair<float, float>> studentRecords){
        algorithm3.setStudentRecords(studentRecords);
    }

    ///
    ///deconstructor of the class
    ///
    ~AlgorithmTest3(){}

    ///
    ///Test if the algorithm can produce the correct student efficiency rate the individual student
    ///@param expectedAnswer expected rate that we hope the algorithm can generate
    ///@param record the record the specific student
    ///@return ture if match; false if not match
    ///
    bool getStudentEfficientRatioTest(float expectedAnswer, pair<float, float> record){
        return abs(expectedAnswer - algorithm3.getStudentEfficientRatio(record)) < 0.01 ? true : false;
    }

    ///
    ///Test if the algorithm can produce the correct student efficiency rate for every student in the course at once
    ///@param expectedAnswer expected answers we would like the algorithm to produce
    ///@return true if match for student record; false otherwise
    ///
    bool getAllStudentEfficientRatioTest(vector<float> expectedAnswer){
        vector<int> actualAnswer = algorithm3.getAllStudentEfficientRatio(); /*<get all student ratio>*/
        return equal(actualAnswer.begin(), actualAnswer.end(), expectedAnswer.begin());
    }
};

///
///Generating the fake student data for testing
///@return fake student data
///
map<int, pair<float, float>> generatorMap(){
    map<int, pair<float, float>> studentRecords;
    vector<int> grade {1,10,15,30,40,50,60,70,90,110,110};
    for(int i = 0; i <= 10; i++) {
        studentRecords.insert(pair < int, pair < float, float >> (i, make_pair(grade[i], 100)));
    }
    return studentRecords;
}

int main(){
    //initializing the expected answer for testing
    vector<float> exceptedResult{1,2,0,1,1,1,1,1,0,1,2}; /*<expected result of student efficiency rate for fake student records>*/
    map<int, pair<float, float>> studentRecords = generatorMap(); /*<generate the fake data*>*/
    AlgorithmTest3 algorithmTest3(studentRecords); /*<pass the fake data in algorithm3 object>  */

    // following are tests that we would like the algorithm to pass - happy test
    pair<float,float>test1(90,100);
    pair<float,float>test2(80,90);
    float pairAnswer1 = 90.0/100;
    float pairAnswer2 = (80.0/TOTALGRADE)/(90.0/TOTALSTUDYTIME);
    if(algorithmTest3.getStudentEfficientRatioTest(pairAnswer1, test1)
        && algorithmTest3.getStudentEfficientRatioTest(pairAnswer2, test2))
        cout << "getStudentEfficientRatio function happy test passed" << endl;
    else
        cout << "getStudentEfficientRatio function happy test failed" << endl;

    if(algorithmTest3.getAllStudentEfficientRatioTest(exceptedResult))
        cout << "getAllStudentEfficientRatio function happy test passed" << endl;
    else
        cout << "getAllStudentEfficientRatio function happy test failed" << endl;

    // all exception test

    // test for one grade as 0
    studentRecords[0] = make_pair(0,1);
    algorithmTest3.algorithm3.setStudentRecords(studentRecords);
    try{
        algorithmTest3.algorithm3.getAllStudentEfficientRatio();
        cout << "getStudentEfficientRatio 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch (int errorCode){
        if(errorCode == 101)
            cout << "getStudentEfficientRatio 101 Arithmetic error test passed" << endl;
    }

    // test for grade divided by 0
    studentRecords[0] = make_pair(1,1);
    studentRecords[1] = make_pair(1,0);
    algorithmTest3.algorithm3.setStudentRecords(studentRecords);
    try{
        algorithmTest3.algorithm3.getAllStudentEfficientRatio();
        cout << "getStudentEfficientRatio 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch (int errorCode){
        if(errorCode == 101)
            cout << "getStudentEfficientRatio 101 Arithmetic error test passed" << endl;
    }
}