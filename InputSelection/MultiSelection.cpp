#include "config.h"
#include "SelectionHeader.h"

///
/// This is the aLL input filters in InputSelection model;
/// It allows user to get ride of one or more the unwanted selections at one time;
///@author Yanwen Wang
///@author Ido Chen
///@author Mingyu Yu
///
class MultiSelection{
private:
    /// data and dataStudent is reference to original data
    /// each selection vector contains all the unwanted selection
    /// each selection object helps us to filter the element
    map<string,map<string, CourseMeta>> data;/*!< Holder of original dataset >*/
    vector<string> courseSelectionVector;/*!< holder of unwanted course contained in  original dataset>*/
    vector<string> periodSelectionVector;/*!< holder of unwanted period contained in original dataset>*/
    CourseSelection courseSelection;/*!< Course selection object that will help us filter unwanted course from original dataset>*/
    PeriodSelection periodSelection;/*!< period selection object that will help us filter unwanted period from original dataset>*/


public:

    ///
    ///Empty constructor for creating an MultiSelection object without passing parameters
    ///
    MultiSelection(){};

    ///
    /// @param data origin data for period and course selection
    /// @param dataStudent origin data from student selection
    /// @param courseSelectionVector vector contains all unwanted course
    /// @param studentSelectionVector vector contains all unwanted student
    /// @param periodSelectionVector vector contains all unwanted period or years
    MultiSelection(map<string,map<string, CourseMeta>> data,
                   vector<string> courseSelectionVector,
                   vector<string> periodSelectionVector){
        this->data = data;
        this->courseSelectionVector = courseSelectionVector;
        this->periodSelectionVector = periodSelectionVector;
//        this->studentSelectionVector = studentSelectionVector;
    };

    ///
    ///deconstruct of the class
    ///
    ~MultiSelection(){};

    ///
    /// remove all unwanted course based on periodSelectionVector
    ///
    void getDataBasedOnPeriodSelection(){
        this->periodSelection.setData(data);
        this->periodSelection.setSelection(periodSelectionVector);
        periodSelection.getDataBasedOnSelection();
        setData(periodSelection.getData());
    }
    ///
    /// remove all unwanted course based on courseSelectionVector
    ///
    void getDataBasedOnCourseSelection(){
        this->courseSelection.setData(data);
        this->courseSelection.setSelection(courseSelectionVector);
        courseSelection.getDataBasedOnSelection();
        setData(courseSelection.getData());
    }

//    ///
//    /// remove all unwanted course based on studentSelectionVector
//    ///
//    void getDataBasedOnStudentSelection(){
//        this->studentSelection.setData(dataStudent);
//        this->studentSelection.setSelection(studentSelectionVector);
//        studentSelection.getDataBasedOnSelection();
//        setDataStudent(studentSelection.getData());
//    }

    ///
    /// setter method to assigns private attribute data
    /// @param selection new data map will assigns
    ///
    void setData(map<string,map<string, CourseMeta>> data){
        this->data = data;
    };

//    ///
//    /// setter method to assigns private attribute dataStudent
//    /// @param selection new data map will assigns
//    ///
//    void setDataStudent(map<string,map<string, string>> data){
//        this->dataStudent = data;
//    };

    ///
    /// setter method to assigns private attribute courseSelectionVector
    /// @param newVector new vector map will assigns/
    ///
    void setCourseSelectionVector (vector<string> newVector){
        courseSelectionVector = newVector;
    }

//    ///
//    /// setter method to assigns private attribute studentSelectionVector
//    /// @param newVector new vector map will assigns
//    ///
//    void setStudentSelectionVector (vector<string> newVector){
//        studentSelectionVector = newVector;
//    }

    ///
    /// setter method to assigns private attribute periodSelectionVector
    /// @param newVector new vector map will assigns
    ///
    void setPeriodSelectionVector (vector<string> newVector){
        periodSelectionVector = newVector;
    }

    ///
    /// accessor method to get private attribute data map
    /// @return private attribute map data
    ///
    map<string,map<string, CourseMeta>> getData(){
        return data;
    };

//    ///
//    /// accessor method to get private attribute dataStudent map
//    /// @return private attribute map dataStudent
//    ///
//    map<string,map<string, string>> getDataStudent(){
//        return dataStudent;
//    };
};