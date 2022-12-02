
#include "../../InputSelection/MultiSelection.cpp"

///
///Testing class for MultiSelection.
///This testing class tests if the algorithm can remove more or more selection successfully
///@author yubo He
///
class MultiSelectionTest {
public:
    /*!< The MultiSelection is going to be test>*/
    MultiSelection multiSelection;

    /// The constructor init the MultiSelection object
    /// \param data original data for course and period selection
    /// \param dataStudent original data for student selection
    /// \param courseSelectionVector contains all unwanted course
    /// \param studentSelectionVector contains all unwanted student
    /// \param periodSelectionVector contains all unwanted period
    MultiSelectionTest(map<string,map<string, CourseMeta>> data,
            vector<string> courseSelectionVector,
            vector<string> periodSelectionVector){
        multiSelection.setData(data);
//        multiSelection.setDataStudent(dataStudent);
        multiSelection.setCourseSelectionVector(courseSelectionVector);
//        multiSelection.setStudentSelectionVector(studentSelectionVector);
        multiSelection.setPeriodSelectionVector(periodSelectionVector);

    }
    ~MultiSelectionTest(){};

    /// help method to compare two map is equal or not
    /// it will compare inner map to make sure all course data will compared
    /// \param expectedAnswer the correct map data
    /// \param actualAnswer the result map data we goe
    /// \return return true if two map equals, else otherwise
    bool key_compare (map<string,map<string, CourseMeta>>expectedAnswer, map<string,map<string, CourseMeta>>actualAnswer) {
        if(expectedAnswer.size() != actualAnswer.size()) return false;
        map<string,map<string, CourseMeta>>::iterator itr;
        for (itr = expectedAnswer.begin(); itr != expectedAnswer.end(); ++itr){
            if(actualAnswer.find(itr->first) == actualAnswer.end()){
                return false;
            }
            else if(itr->second.size() != actualAnswer.find(itr->first)->second.size())
                return false;
        }
        return true;
    }

    /// overload methods, just contains different original data for student selection
    bool key_compare (map<string,map<string, string>>expectedAnswer, map<string,map<string, string>>actualAnswer) {
        if(expectedAnswer.size() != actualAnswer.size()) return false;
        map<string,map<string, string>>::iterator itr;
        for (itr = expectedAnswer.begin(); itr != expectedAnswer.end(); ++itr){

            if(actualAnswer.find(itr->first) == actualAnswer.end()){
                return false;
            }
            else if(itr->second.size() != actualAnswer.find(itr->first)->second.size()) {
                cout << itr->second.size() << endl;
                cout << actualAnswer.find(itr->first)->second.size() << endl;
                return false;
            }
        }
        return true;
    }

    /// help method to evaluate exceptedMap with actual answer
    /// \param expectedMap the correct answer we are looking for
    /// \return if map are same return true, else otherwise
    bool getDataBasedOnSelectionTest(map<string,map<string, CourseMeta>> expectedMap){
        return key_compare(expectedMap, multiSelection.getData());
    }

//    /// overload methods, just contains different original data for student selection
//    bool getDataBasedOnSelectionTest(map<string,map<string, string>> expectedMap){
//        return key_compare(expectedMap, multiSelection.getDataStudent());
//    }


};

int main(){

    CourseMeta c9;
    CourseMeta c8;
    map<string, CourseMeta> firstMap;
    firstMap["9999"] = c9;
    firstMap["8888"] = c8;
    map<string, CourseMeta> secondMap;
    secondMap["9999"] = c9;
    map<string,map<string, CourseMeta>> originMap;
    originMap["2022"] = firstMap;
    originMap["2021"] = firstMap;

    map<string,map<string, CourseMeta>> expectedMap;
    expectedMap["2022"] = firstMap;

    vector<string> courseSelection{"8888"};
    vector<string> periodSelection{"2021"};
    vector<string> studentSelection{"8888"};


    map<string, string> firstMapStudent;
    firstMapStudent["9999"] = "9999";
    firstMapStudent["8888"] = "8888";
    map<string, string> secondMapStudent;
    secondMapStudent["9999"] = "9999";

    map<string,map<string, string>> originMapStudent;
    originMapStudent["2022"] = firstMapStudent;
    originMapStudent["2021"] = firstMapStudent;

    map<string,map<string, string>> expectedMapStudent;
    expectedMapStudent["2022"] = secondMapStudent;
    expectedMapStudent["2021"] = secondMapStudent;



    // All happy test
    MultiSelectionTest multiSelectionTest(originMap, courseSelection, periodSelection);
    multiSelectionTest.multiSelection.getDataBasedOnPeriodSelection();
    if(multiSelectionTest.getDataBasedOnSelectionTest(expectedMap))
        cout << "getDataBasedOnPeriodSelection Happy Test passed" << endl;
    else
        cout << "getDataBasedOnPeriodSelection Happy Test failed" << endl;

    if(multiSelectionTest.multiSelection.getData().size() != 1)
        cout << "getDataBasedOnPeriodSelection Remove unwanted pairs Happy Test failed" << endl;
    else
        cout << "getDataBasedOnPeriodSelection Remove unwanted pairs Happy Test passed" << endl;

    expectedMap["2022"] = secondMap;
    multiSelectionTest.multiSelection.getDataBasedOnCourseSelection();
    if(multiSelectionTest.getDataBasedOnSelectionTest(expectedMap))
        cout << "getDataBasedOnSelectionTest Happy Test passed" << endl;
    else
        cout << "getDataBasedOnSelectionTest Happy Test failed" << endl;

    if(multiSelectionTest.multiSelection.getData()["2022"].size() != 1)
        cout << "getDataBasedOnSelectionTest Remove unwanted pairs Happy Test failed" << endl;
    else
        cout << "getDataBasedOnSelectionTest Remove unwanted pairs Happy Test passed" << endl;

//    multiSelectionTest.multiSelection.getDataBasedOnStudentSelection();
//    if(multiSelectionTest.getDataBasedOnSelectionTest(expectedMapStudent))
//        cout << "getDataBasedOnStudentSelection Happy Test passed" << endl;
//    else
//        cout << "getDataBasedOnStudentSelection Happy Test failed" << endl;
//
//    if(multiSelectionTest.multiSelection.getDataStudent()["2022"].size() != 1)
//        cout << "getDataBasedOnStudentSelection Remove unwanted pairs Happy Test failed" << endl;
//    else
//        cout << "getDataBasedOnStudentSelection Remove unwanted pairs Happy Test passed" << endl;


}