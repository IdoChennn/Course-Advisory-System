
#include "../../InputSelection/StudentSelection.cpp"
///
///Testing class for StudentSelection.
///This testing class tests if the algorithm can remove Student successfully
///@author yubo He
///
class StudentSelectionTest {
public:

    /*!< The StudentSelection is going to be test>*/
    StudentSelection studentSelection;

    /// The constructor to init the StudentSelection object
    /// \param Data the origin data
    /// \param selection the unwanted courses
    StudentSelectionTest(map<string,map<string, string>> Data, vector<string> selection){
        studentSelection.setData(Data);
        studentSelection.setSelection(selection);
    }

    /// the deconstruct of the class
    ~StudentSelectionTest(){};

    /// help method to compare two map is equal or not
    /// it will compare inner map to make sure all course data will compared
    /// \param expectedAnswer the correct map data
    /// \param actualAnswer the result map data we goe
    /// \return return true if two map equals, else otherwise
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
    bool getDataBasedOnSelectionTest(map<string,map<string, string>> expectedMap){
        studentSelection.getDataBasedOnSelection();
        map<string,map<string, string>> data = studentSelection.getData();

        return key_compare(expectedMap, studentSelection.getData());
    }


};

int main(){

    map<string, string> firstMap;
    firstMap["9999"] = "9999";
    firstMap["8888"] = "8888";
    map<string, string> secondMap;
    secondMap["9999"] = "9999";

    map<string,map<string, string>> originMap;
    originMap["2022"] = firstMap;
    originMap["2021"] = firstMap;

    map<string,map<string, string>> expectedMap;
    expectedMap["2022"] = secondMap;
    expectedMap["2021"] = secondMap;

    vector<string> selection{"8888"};

    // All happy test
    StudentSelectionTest studentSelectionTest(originMap, selection);
    if(studentSelectionTest.getDataBasedOnSelectionTest(expectedMap))
        cout << "getDataBasedOnSelection Happy Test passed" << endl;
    else
        cout << "getDataBasedOnSelection Happy Test failed" << endl;

    if(studentSelectionTest.studentSelection.getData()["2022"].size() != 1)
        cout << "Remove unwanted pairs Happy Test failed" << endl;
    else
        cout << "Remove unwanted pairs Happy Test passed" << endl;

}