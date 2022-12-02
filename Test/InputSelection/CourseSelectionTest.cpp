//
// Created by Yanwen on 2022-11-06.
//
#include "../../InputSelection/CourseSelection.cpp"

///
///Testing class for CourseSelection.
///This testing class tests if the algorithm can remove course successfully
///@author Yuebo He
///
class CourseSelectionTest{

public:

    CourseSelection courseSelection; /*!< The CourseSelection is going to be test>*/

    /// The constructor to init the CourseSelectionTest object
    /// \param Data the origin data
    /// \param selection the unwanted courses
    CourseSelectionTest(map<string,map<string, CourseMeta>> Data, vector<string> selection){
        courseSelection.setData(Data);
        courseSelection.setSelection(selection);
    }

    ///
    /// the deconstruct of the object
    ///
    ~CourseSelectionTest(){};


    /// help method to compare two map is equal or not
    /// it will compare inner map to make sure all course data will compared
    /// \param expectedAnswer the correct map data
    /// \param actualAnswer the result map data we goe
    /// \return return true if two map equals, else otherwise
    bool key_compare (map<string,map<string, CourseMeta>>expectedAnswer, map<string,map<string, CourseMeta>>actualAnswer) {

        // return false if the size is different
        if(expectedAnswer.size() != actualAnswer.size()) return false;
        map<string,map<string, CourseMeta>>::iterator itr;
        // if the actualAnswer map key and expectedAnswer map key are different return false
        // else if the inner map size are different return false
        for (itr = expectedAnswer.begin(); itr != expectedAnswer.end(); ++itr){
            if(actualAnswer.find(itr->first) == actualAnswer.end()){
                return false;
            }
            else if(itr->second.size() != actualAnswer.find(itr->first)->second.size())
                return false;
        }
        return true;
    }

    /// help method to evaluate exceptedMap with actual answer
    /// \param expectedMap the correct answer we are looking for
    /// \return if map are same return true, else otherwise
    bool getDataBasedOnSelectionTest(map<string,map<string, CourseMeta>> expectedMap){
        courseSelection.getDataBasedOnSelection();
        return key_compare(expectedMap, courseSelection.getData());
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
    expectedMap["2022"] = secondMap;
    expectedMap["2021"] = secondMap;

    vector<string> selection{"8888"};

    // All happy test
    CourseSelectionTest courseSelectionTest(originMap, selection);
    if(courseSelectionTest.getDataBasedOnSelectionTest(expectedMap))
        cout << "getDataBasedOnSelection Happy Test passed" << endl;
    else
        cout << "getDataBasedOnSelection Happy Test failed" << endl;

    if(courseSelectionTest.courseSelection.getData()["2022"].size() != 1)
        cout << "Remove unwanted pairs Happy Test failed" << endl;
    else
        cout << "Remove unwanted pairs Happy Test passed" << endl;

}