#include <iostream>
#include <vector>
#include "../../Algorithm/Algorithm1.cpp"

///
///This is the tester class for the first algorithm.
///@Author Baishen Jiang
///@Author Mingyu Yu
class Algorithm1Test {
    public:
        Algorithm1 algorithm1; /*!< an instance of algorithm that is going to be tested */

        ///
        ///Constructor for algorithm1Test
        ///@param size the number of students doing the assignment
        ///@param completionTime the container for all students' assignment completion time
        ///@param time time assigned for finishing the assignment
        ///@param mark the container for all students' assignment mark
        ///
        Algorithm1Test (int size, vector<float> completionTime, int assignTime, vector<float> mark){
            algorithm1.setSize(size);
            algorithm1.setCompletionTime(completionTime);
            algorithm1.setAssignTime(assignTime);
            algorithm1.setMark(mark);
        }
        ///
        ///Tester for correctness of completion time standard deviation
        ///@param expectedAnswer the pre-calculated value that expects the generated value to be the same.
        ///@return ture if the  same; false if not the same
        ///
        bool printStdDeviationOfCompletionTime(float expectedAnswer){
            return expectedAnswer != algorithm1.getStdDeviationOfAVGCompletionTime() ? false : true;

        }

        ///
        ///Tester for correctness of assignment mark standard deviation
        ///@param expectedAnswer the pre-calculated value that expects the generated value to be the same.
        ///@return ture if the  same; false if not the same
        ///
        bool printStdDeviationOfMark(float expectedAnswer){
            return expectedAnswer != algorithm1.getStdDeviationOfAVGMark() ? false : true;
        }

        ///
        ///Testing if completion time vector has the same size as he assignment mark vector
        ///@param expectedAnswer the pre-calculated value that expects the generated value to be the same.
        ///@return ture if the  same; false if not the same
        ///
        bool isEquallySizeTest(bool exceptedAnswer){
            return algorithm1.isAllVectorSizeEqually() == exceptedAnswer ? true : false;
        }

        ///
        ///Testing if the algorithm can produce the correct average completion time.
        ///@param expectedAnswer the pre-calculated value that expects the generated value to be the same.
        ///@return ture if the  same; false if not the same
        ///
        bool averageCompletionTimeTest(float exceptedAnswer){
            return abs(exceptedAnswer - algorithm1.getAverageCompletionTime()) < 0.1 ? true : false;

        }

        ///
        ///Testing if the algorithm can produce the correct average assignment mark
        ///@param expectedAnswer the pre-calculated value that expects the generated value to be the same.
        ///@return ture if the  same; false if not the same
        ///
        bool averageMarkTest(float exceptedAnswer){
            return abs(exceptedAnswer - algorithm1.getAverageMark()) < 0.1 ? true : false;

        }

        ///
        ///Testing if the algorithm can produce the correct degree of assignment difficulty
        ///@param expectedAnswer the pre-calculated value that expects the generated value to be the same.
        ///@return ture if the  same; false if not the same
        ///
        bool degreeOfDifficultyTest(float exceptedAnswer){

            return abs(exceptedAnswer - algorithm1.getDegreeOfDifficulty()) < 0.1 ? true : false;
        }

         //algorithm for calculating difficult degree without outliers is still in development.
//        float degreeOfDifficultyTestNoOutliers(){
//            return algorithm1.getDegreeOfDifficultyNoOutliers();
//        }

};

int main(){

        //input testing student data
        int size = 3; /*!< set the number of students doing assignment in test case to be three */
        vector<float> completionTime{10,20,30}; /*!< set the fake completion times for each of the three student */
        int assignedTime = 10; /*!< set the fake assign time */
        vector<float> mark{100,100,100}; /*!< set the fake mark for three students */

        //Creating tester object
        Algorithm1Test t1(size, completionTime, assignedTime, mark);

        //The following test are all happy test that we expect the algorithm can pass.
        if(t1.isEquallySizeTest(true)){
            cout << "Equally Size Function Happy Test passed" << endl;
        }
        else{
            cout << "Equally Size Function Happy Test failed" << endl;
        }
        if(t1.averageCompletionTimeTest(20)){
            cout << "Average Completion Time Function Happy Test passed" << endl;
        }
        else{
            cout << "Average Completion Time Function Happy Test passed failed" << endl;
        }
        if(t1.averageMarkTest(1)){
            cout << "Average Mark Function Happy Test passed" << endl;
        }
        else{
            cout << "Average Mark Function Happy Test failed" << endl;
        }
        if(t1.printStdDeviationOfCompletionTime(8)){
            cout << "Standard Deviation of average completion time - Happy Test passed" << endl;
        }
        else{
            cout << "Standard Deviation of average completion time - Happy Test failed" << endl;
        }

        if(t1.printStdDeviationOfMark(0)){
            cout << "Standard Deviation of average mark - Happy Test passed" << endl;
        }
        else{
            cout << "Standard Deviation of average mark - Happy Test failed" << endl;
        }
        if(t1.degreeOfDifficultyTest(0.5)){
            cout << "Degree Of Difficulty Happy Test passed" << endl;
        }
        else{
            cout << "Degree Of Difficulty Happy Test failed" << endl;
        }
        //driver code for testing difficulty degree without outliers
//        if (t1.degreeOfDifficultyTestNoOutliers())
//        {
//            /* code */
//        }




        // The following test will test if the algorithm can catch and throw the intended error for testing cases.
        // test for isEquallySize exception catch
        t1.algorithm1.setSize(4);
        if(t1.isEquallySizeTest(false)){
            cout << "Equally Size Function Error Test passed" << endl;
        }
        else{
            cout << "Equally Size Function Error Test failed" << endl;
        }

        // test for averageCompletionTime function and averageMark function error
        t1.algorithm1.setSize(3);
        completionTime[0] = 30;
        mark[0] = 99;
        t1.algorithm1.setCompletionTime(completionTime);
        if(!t1.averageCompletionTimeTest(20)){
            cout << "averageCompletionTimeErrorTest passed" << endl;
        }
        else{
            cout << "averageCompletionTimeErrorTest failed" << endl;
        }
        if(t1.averageMarkTest(1)){
            cout << "averageMarkFunctionErrorTest passed" << endl;
        }
        else{
            cout << "averageMarkFunctionErrorTest failed" << endl;
        }

        // test for 101 Arithmetic error in constructor
        try{
            Algorithm1 algorithm2(0,completionTime, assignedTime, mark);
            cout << "Catch 101 Arithmetic error in constructor failed, no exception catch" << endl;
        }
        catch(int errorCode){
            if(errorCode == 101)
                cout << "Catch 101 Arithmetic error in constructor passed" << endl;
        }

        // test for 101 Arithmetic error in other method
        // test for 102 Value error in other method
        t1.algorithm1.setSize(0);
        try{
            t1.algorithm1.getAverageMark();
            cout << "Catch 101 Arithmetic error in getAverageMark failed, no exception catch" << endl;
        }
        catch(int errorCode){
            if(errorCode == 101)
                cout << "Catch 101 Arithmetic error in getAverageMark passed" << endl;
        }

        t1.algorithm1.setSize(2);
        try{
            t1.algorithm1.getAverageMark();
            cout << "Catch 102 Value error in getAverageMark failed, no exception catch" << endl;
        }
        catch(int errorCode){
            if(errorCode == 102)
                cout << "Catch 102 Value error in getAverageMark passed" << endl;
        }

        t1.algorithm1.setSize(0);
        try{
            t1.algorithm1.getAverageCompletionTime();
            cout << "Catch 101 Arithmetic error in getAverageCompletionTime failed, no exception catch" << endl;
        }
        catch(int errorCode){
            if(errorCode == 101)
                cout << "Catch 101 Arithmetic error in getAverageCompletionTime passed" << endl;
        }

        t1.algorithm1.setSize(1);
        try{
            t1.algorithm1.getAverageCompletionTime();
            cout << "Catch 102 Value error in getAverageCompletionTime failed, no exception catch" << endl;
        }
        catch(int errorCode){
            if(errorCode == 102)
                cout << "Catch 102 Value error in getAverageCompletionTime passed" << endl;
        }

        t1.algorithm1.setSize(3);
        vector<float> errorCompletionTime{ 0, 0, 0 };
        t1.algorithm1.setCompletionTime(errorCompletionTime);
        try{
            t1.algorithm1.getDegreeOfDifficulty();
            cout << "Catch 101 Arithmetic error in getDegreeOfDifficulty failed, no exception find" << endl;
        }
        catch(int errorCode){
            if(errorCode == 101)
                cout << "Catch 101 Arithmetic error in getDegreeOfDifficulty passed" << endl;
        }

}
