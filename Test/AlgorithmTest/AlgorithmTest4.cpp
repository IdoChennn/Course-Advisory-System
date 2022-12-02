#include "../../Algorithm/Algorithm4.cpp"
///
///Tester class for algorithm4
///This class tests if algorithm 4 can produce the correct average grade.
///This class tests if algorithm 4 can produce the correct average attendance.
///This class tests if algorithm 4 can produce the correct average study hours.
///@author Baishen Jiang
///@author Mingyu Yu
///

class AlgorithmTest4 {
public:
    Algorithm4 algorithm4; /*<object that is going to be tested>*/

    ///
    ///constructor of the class
    ///@param studentGrades student grades
    ///@param studentAttendances student attendances
    ///@param studentStudyHours hours spent by students to study the course
    ///
    AlgorithmTest4(vector<float> studentGrades, vector<float> studentAttendances,vector<float> studentStudyHours){
        algorithm4.setStudentGrades(studentGrades);
        algorithm4.setStudentAttendances(studentAttendances);
        algorithm4.setStudentStudyHours(studentStudyHours);
    }
    ///
    ///deconstructor of the testing class
    ///
    ~AlgorithmTest4(){}

    ///
    ///Tester for calculating correct average grade.
    ///@param expectedAnswer expected average grade calculated by the algorithm
    ///@return ture if match the expected answer; false otherwise
    ///
    bool getAverageGradeTest(float expectedAnswer){
        return abs(expectedAnswer - algorithm4.getAverageGrade()) < 0.01 ? true : false;
    }

    ///
    ///Tester for calculating correct average attendance.
    ///@param expectedAnswer expected average attendance calculated by the algorithm
    ///@return ture if match the expected answer; false otherwise
    ///
    bool getAverageAttendanceTest(float expectedAnswer){
        return abs(expectedAnswer - algorithm4.getAverageAttendance()) < 0.01 ? true : false;
    }

    ///
    ///Tester for calculating correct average study hours.
    ///@param expectedAnswer expected average study hours calculated by the algorithm
    ///@return ture if match the expected answer; false otherwise
    ///
    bool getAverageStudyHoursTest(float expectedAnswer){
        return abs(expectedAnswer - algorithm4.getAverageStudyHours()) < 0.01 ? true : false;
    }

    ///
    ///Tester for testing the core part of the algorithm - calculating the student lecture utilization rate with given attributes.
    ///@param expectedAnswer expected student lecture utilization calculated by the algorithm
    ///@return ture if match the expected answer; false otherwise
    ///
    bool getLectureUtilizationRatesTest(float expectedAnswer){
        return abs(expectedAnswer - algorithm4.getLectureUtilizationRates()) < 0.01 ? true : false;
    }

};

//driver code of the test class
int main(){

    //fake student data for testing.
    vector<float> grade{80,90,100}; /*<fake grade data>*/
    vector<float> attendance{100,100,100}; /*<fake attendance data>*/
    vector<float> hours{100,100,100}; /*<fake hours data>*/

    AlgorithmTest4 algorithmTest4(grade, attendance, hours);

    //following are tests that we wish the algorithm to pass - happy test
    float exceptedGrade = 90.0;
    if(algorithmTest4.getAverageGradeTest(exceptedGrade)){
        cout << "getAverageGrade function happy test passed" << endl;
    }
    else
        cout << "getAverageGrade function happy test failed" << endl;

    float exceptedAttendance = 100.0;
    if(algorithmTest4.getAverageAttendanceTest(exceptedAttendance)){
        cout << "getAverageAttendance function happy test passed" << endl;
    }
    else
        cout << "getAverageAttendance function happy test failed" << endl;


    float exceptedHours = 100.0;
    if(algorithmTest4.getAverageStudyHoursTest(exceptedHours)){
        cout << "getAverageStudyHours function happy test passed" << endl;
    }
    else
        cout << "getAverageStudyHours function happy test failed" << endl;

    float exceptedRatio = 0.9;
    if(algorithmTest4.getLectureUtilizationRatesTest(exceptedRatio)){
        cout << "getLectureUtilizationRates function happy test passed" << endl;
    }
    else
        cout << "getLectureUtilizationRates function happy test failed" << endl;

    // all exception test

    //following are tests that we expect the algorithm can catch errors and throw it with proper message.
    // test for 102 value error in constructor
    grade.push_back(99);
    try {
        Algorithm4 algorithm4Temp(grade, attendance, hours);
        cout << "Algorithm4 constructor 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "Algorithm constructor 102 value error test passed" << endl;
    }
    vector<float> gradeEmpty;
    vector<float> attendanceEmpty;
    vector<float> hoursEmpty;
    try{
        Algorithm4 algorithm4Temp(gradeEmpty, attendance, hours);
        cout << "Algorithm4 constructor 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "Algorithm constructor 102 value error test passed" << endl;
    }

    // test for 102 value error in getAverageGrade()
    // empty vector case
    algorithmTest4.algorithm4.setStudentGrades(gradeEmpty);
    try{
        algorithmTest4.algorithm4.getAverageGrade();
        cout << "getAverageGrade 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getAverageGrade 102 value error test passed" << endl;
    }
    // different size case
    algorithmTest4.algorithm4.setStudentGrades(grade);
    try{
        algorithmTest4.algorithm4.getAverageGrade();
        cout << "getAverageGrade 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getAverageGrade 102 value error test passed" << endl;
    }

    // test for 102 value error in getAverageAttendance()
    // empty vector case
    algorithmTest4.algorithm4.setStudentAttendances(attendanceEmpty);
    try{
        algorithmTest4.algorithm4.getAverageAttendance();
        cout << "getAverageAttendance 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getAverageAttendance 102 value error test passed" << endl;
    }
    // different size case
    attendance.push_back(100);
    algorithmTest4.algorithm4.setStudentAttendances(attendance);
    try{
        algorithmTest4.algorithm4.getAverageAttendance();
        cout << "getAverageAttendance 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getAverageAttendance 102 value error test passed" << endl;
    }


    // test for 102 value error in getAverageStudyHours()
    // empty vector case
    algorithmTest4.algorithm4.setStudentStudyHours(hoursEmpty);
    try{
        algorithmTest4.algorithm4.getAverageStudyHours();
        cout << "getAverageStudyHours 102 value error test failed, no exception catch" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getAverageStudyHours 102 value error test passed" << endl;
    }
    // different size case
    hours.push_back(100);

    algorithmTest4.algorithm4.setStudentStudyHours(hours);
    try{
        algorithmTest4.algorithm4.getAverageStudyHours();
        cout << "getAverageStudyHours 102 value error test passed" << endl;
    }
    catch(int errorCode){
        if(errorCode == 102)
            cout << "getAverageStudyHours 102 value error test failed" << endl;
    }


    // test for 101 Arithmetic error in getLectureUtilizationRates()
    vector<float> attendanceZero{0,0,0,0};
    vector<float> hoursZero{0,0,0,0};
    algorithmTest4.algorithm4.setStudentAttendances(attendanceZero);
    algorithmTest4.algorithm4.setStudentStudyHours(hoursZero);
    try{
        algorithmTest4.algorithm4.getLectureUtilizationRates();
        cout << "getLectureUtilizationRates 101 Arithmetic error test failed, no exception catch" << endl;
    }
    catch (int errorCode){
        if(errorCode == 101)
        cout << "getLectureUtilizationRates 101 Arithmetic error test passed" << endl;
    }
}
// end of test