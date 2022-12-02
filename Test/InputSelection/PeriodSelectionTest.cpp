#include "../../InputSelection/PeriodSelection.cpp"

///
///Testing class for PeriodSelection.
///This testing class tests if the algorithm can remove Period or years successfully
///
class PeriodSelectionTest{

public:
    /*!< The PeriodSelection is going to be test>*/
    PeriodSelection periodSelection;


    /// The constructor to init the PeriodSelection object
    /// \param Data the origin data
    /// \param selection the unwanted courses
    PeriodSelectionTest(map<string,map<string, CourseMeta>> Data, vector<string> selection){
        periodSelection.setData(Data);
        periodSelection.setSelection(selection);
    }
    /// the deconstruct of the class
    ~PeriodSelectionTest(){};

    /// help method to compare two map is equal or not
    /// it only compare the outer loop key and its size
    /// \param expectedAnswer the correct map data
    /// \param actualAnswer the result map data we goe
    /// \return return true if two map equals, else otherwise
    bool key_compare (map<string,map<string, CourseMeta>>expectedAnswer, map<string,map<string, CourseMeta>>actualAnswer) {
        // return false if the size is different
        if(expectedAnswer.size() != actualAnswer.size()) return false;
        map<string,map<string, CourseMeta>>::iterator itr;
        // if the actualAnswer map key and expectedAnswer map key are different return false
        for (itr = expectedAnswer.begin(); itr != expectedAnswer.end(); ++itr){
            if(actualAnswer.find(itr->first) == actualAnswer.end()){
                return false;
            }
        }
        return true;
    }

    /// help method to evaluate exceptedMap with actual answer
    /// \param expectedMap the correct answer we are looking for
    /// \return if map are same return true, else otherwise
    bool getDataBasedOnSelectionTest(map<string,map<string, CourseMeta>> expectedMap){
        periodSelection.getDataBasedOnSelection();
        return key_compare(expectedMap, periodSelection.getData());
    }


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


    vector<string> selection{"2021"};

    // All happy test
    PeriodSelectionTest periodSelectionTest(originMap, selection);
    if(periodSelectionTest.getDataBasedOnSelectionTest(expectedMap))
        cout << "getDataBasedOnSelection Happy Test passed" << endl;
    else
        cout << "getDataBasedOnSelection Happy Test failed" << endl;

    if(periodSelectionTest.periodSelection.getData().size() != 1)
        cout << "Remove unwanted pairs Happy Test failed" << endl;
    else
        cout << "Remove unwanted pairs Happy Test passed" << endl;


}