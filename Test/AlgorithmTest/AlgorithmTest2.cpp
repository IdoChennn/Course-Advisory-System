
#include "../../Algorithm/Algorithm2.cpp"
///
///Tester for algorithm2
///We will test if the algorithm can fetch all students' records for the assigned grade range,
///(e.g. give me all students' data for those who have 90+% mark in the course).
///We will also test if the algorithm can produce the right grade&time rate for the assigned grade range.
///Finally, we will test if the algorithm can produce a grade&time rate for ever grade range at once.
///@author Baishen Jiang
///@author Mingyu Yu
class AlgorithmTest2{
public:
    Algorithm2 algorithm2; /*<create an algorithm2 object for testing>*/

    ///
    ///The constructor for this test class
    ///@param studentRecords all students' records
    ///
    AlgorithmTest2(map<int, pair<int,vector<int>>> studentRecords){
        algorithm2.setStudentRecords(studentRecords);
    }

    ///
    ///Test if the algorithm can fetch all students; records for the assigned grade range
    ///@param expectedAnswer the students record that we expect the algorithm to fetch correctly.
    ///@param range the grade range (eg. 6-> 60%-70%)
    ///
    bool getStudentRecordsWithRangeTest(pair<int, vector<int>> expectedAnswer, int range){
        pair<int, vector<int>> actuallyAnswer = algorithm2.getStudentRecordsWithRange(range);/*<fetch students record for the input grade range>*/

        //test if the result is matched with the expected answer.
        return (actuallyAnswer.first == expectedAnswer.first && actuallyAnswer.second == expectedAnswer.second) ? true : false;
    }

    ///
    ///Test if the algorithm can produce the correct grade&time rate for the assigned grade range.
    ///@param expectedAnswer the expected answer that we wish the algorithm to produce.
    ///@param range the grade range.
    ///
    bool getAverageStudentEffortRateTest(float expectedAnswer, int range){
        return (expectedAnswer == algorithm2.getAverageStudentEffortRate(range)) ? true : false;
    }

    ///
    ///Test if the algorithm can produce the correct grade&time rate for every grade range.
    ///@param expectedAnswer collection of expected answers for all the grade range's grade&time rates
    ///
    bool getAllRangeRateTest(map<int, float> expectedAnswer){
        map<int, float> actualAnswer = algorithm2.getAllRangeRate(); /*<get all the grade&time rates from the getAllRangeRate method>*/
        if(actualAnswer.size() != expectedAnswer.size()) return false;
        map<int, float>::iterator itr;
        //if any of the item in the result provided by getAllRangeRate() method does not match with the expected answer
        //return false; otherwise, return true.
        for (itr = expectedAnswer.begin(); itr != expectedAnswer.end(); ++itr){
            int range = itr->first;
            float rate = itr->second;
            if(actualAnswer.find(range) != actualAnswer.end() && actualAnswer[range] == rate){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }

};

///
///Generating the fake studentRecords for testing
///@return the fake studentRecords
///
map<int, pair<int,vector<int>>> generatorStudentRecords(){
    map<int, pair<int,vector<int>>> studentRecordsTest;
    vector<int> studentTime{ 10, 20, 30 };
    pair<int,vector<int>> studentPairs = make_pair(3, studentTime);
    for(int i = 0; i < 10; i++){
        studentRecordsTest.insert(make_pair(i,studentPairs));
    }
    return studentRecordsTest;
}

///
///generating fake result of all the grade range's grade&time rates.
///@return fake result
///
map<int, float> generatorSampleMap(){
    map<int, float> sampleMap; /*<fake result container>*/
    for(int i = 0 ; i < 10; i++){
        pair<int, float> tempPair = make_pair(i,20);
        sampleMap.insert(tempPair);
    }
    return sampleMap;
}


int main(){
    map<int, pair<int,vector<int>>> studentRecordsTest = generatorStudentRecords(); /*<actually generating the fake student records>*/
    AlgorithmTest2 algorithmTest2(studentRecordsTest);/*<testing object that receives the fake records>*/
    vector<int> studentTime{ 10, 20, 30 };/*<fake result containter>*/
    pair<int, vector<int>> expectedAnswer = make_pair(3, studentTime);/*<initializing expected answer>*/

    // following are tests we would like algorithm2 to pass - happy test.
    if(algorithmTest2.getStudentRecordsWithRangeTest(expectedAnswer,0)){
        cout << "getStudentRecordsWithRange function happy test passed" << endl;
    }
    else{
        cout << "getStudentRecordsWithRange function happy test failed" << endl;
    }

    if(algorithmTest2.getAverageStudentEffortRateTest(20, 9)){
        cout << "getAverageStudentEffortRate function happy test passed" << endl;
    }
    else{
        cout << "getAverageStudentEffortRate function happy test failed" << endl;
    }

    map<int, float> exceptedMap = generatorSampleMap();
    if(algorithmTest2.getAllRangeRateTest(exceptedMap)){
        cout << "getAllRangeRate function happy test passed" << endl;
    }
    else{
        cout << "getAllRangeRate function happy test failed" << endl;
    }


    // following are tests that test if the algorithm can catch errors
    // test for 101 Arithmetic error
    vector<int> studentTime1{ 10, 20, 30 };
    studentRecordsTest[0] = make_pair(0,studentTime1);
    algorithmTest2.algorithm2.setStudentRecords(studentRecordsTest);
    try{
        algorithmTest2.algorithm2.getAverageStudentEffortRate(0);
        cout << "getAverageStudentEffortRate 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch (int errorCode){
        if(errorCode == 101)
            cout << "getAverageStudentEffortRate 101 Arithmetic error test passed" << endl;
    }

    try{
        algorithmTest2.algorithm2.getAllRangeRate();
        cout << "getAllRangeRate 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 101){
            cout << "getAllRangeRate 101 Arithmetic error test passed" << endl;
        }
    }


    // test for 102 value error
    try{
        algorithmTest2.algorithm2.getStudentRecordsWithRange(10);
        cout << "getStudentRecordsWithRange 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102){
            cout << "getStudentRecordsWithRange 102 value error test passed" << endl;
        }
        else{
            cout << "getStudentRecordsWithRange 102 value error test failed, wrong exception catch" << endl;
        }
    }


    vector<int> studentTime2{ 10, 20, 30 };
    studentRecordsTest[0] = make_pair(1,studentTime2);
    algorithmTest2.algorithm2.setStudentRecords(studentRecordsTest);
    try{
        algorithmTest2.algorithm2.getAverageStudentEffortRate(0);
        cout << "getAverageStudentEffortRate 102 value error test failed, no exception catch" << endl;
    }
    catch (int errorCode){
        if(errorCode == 102)
            cout << "getAverageStudentEffortRate 102 value error test passed "<< endl;
    }

    try{
        algorithmTest2.algorithm2.getAllRangeRate();
        cout << "getAllRangeRate 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102){
            cout << "getAllRangeRate 102 value error test passed" << endl;
        }
    }





}