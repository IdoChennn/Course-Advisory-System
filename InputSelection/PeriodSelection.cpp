#include "SelectionHeader.h"

///
/// This is the one of the input filter in InputSelection model;
/// It allows user to get ride of unwanted data of certain Period(s) or Year(s) from the dataset
///@brief filter input dataset based on period
///@author Ido Chen
///@author Yanwen Wang
///@author Mingyu Yu
///
class PeriodSelection{
private:

    /// first map(wholeData) contains <Year, CousrsId>
    /// second map(CourseData) contains<CourseId: CourseData>
    /// CourseData is from Models/CourseMeta.cpp, since our CourseData is not complete yet, we use float instead

    map<string,map<string, CourseMeta>> data; /*!< holder that contains all needed Course Data > */
    vector<string> selection; /*!< selection contains all unwanted selection >*/
public:
    ///
    ///Empty constructor for creating an PeriodSelection object without passing parameters
    ///
    PeriodSelection(){};

    ///
    ///This is the actual constructor of the periodSelection class
    ///@brief constructor of the class
    ///@param data Contains All needed Course Data
    ///@param selection Contains all unwanted selection
    ///
    PeriodSelection(map<string,map<string, CourseMeta>> data, vector<string> selection){
        this->data = data;
        this->selection = selection;
    };

    ///
    ///deconstruct of the class
    ///
    ~PeriodSelection(){};

    ///
    /// This method help CourseSelection object remove all unwanted course based on period
    ///@brief core of this period data filter
    ///
    void getDataBasedOnSelection(){
        // only remove element if selection vector is not empty
        if(selection.size()!=0) {
            // for each key in the selection vector and make the data remove based on its key
            for(string key: selection){
                data.erase(key);
            }
        }
    }

    ///
    /// setter method to assigns private attribute selection
    /// @param selection new selection vector will assigns
    ///
    void setSelection(vector<string> selection){
        this->selection = selection;
    }

    ///
    /// setter method to assigns private attribute data
    /// @param selection new data map will assigns
    ///
    void setData(map<string,map<string, CourseMeta>> data){
        this->data = data;
    };

    ///
    /// accessor method to get private attribute data map
    /// @return private attribute map data
    ///
    map<string,map<string, CourseMeta>> getData(){
        return data;
    };
};