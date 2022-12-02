#include "SelectionHeader.h"

///
/// This is the one of the input filter in InputSelection model;
/// It allows user to filter the unwanted data of certain student(s) from the dataset
///@brief student filter
///
class StudentSelection{
private:
    ///
    /// first map(wholeData) contains <Year, CousrsId>
    /// second map(CourseData) contains<CourseId: CourseData>
    /// CourseData is from Models/CourseMeta.cpp, since our CourseData is not complete yet, we use float instead
    ///
    map<string,map<string, string>> data; /*!< Data contains All needed Course Data > */
    vector<string> selection; /*!< selection contains all unwanted selection >*/
public:

    ///
    ///Empty constructor for creating an algorithm1 object without passing parameters
    ///
    StudentSelection(){};

    ///
    ///This is the actual constructor of the CourseSelection class
    ///@brief constructor of the class
    ///@param data Contains All needed Course Data
    ///@param selection Contains all unwanted selection
    ///
    StudentSelection(map<string,map<string, string>> data, vector<string> selection){
        this->data = data;
        this->selection = selection;
    };

    ///
    ///deconstruct of the class
    ///
    ~StudentSelection(){};

    ///
    ///
    ///@brief
    /// @param value unwanted value
    /// @param innerMap the map contains all course data
    /// @return find all keys based on it value, if the value is the unwanted value
    ///
    vector<string> isExistValue(string value, map<string, string> innerMap){
        vector<string> result;
        // loop the course data map
        map <string, string > ::iterator itrInner;
        for (itrInner = innerMap.begin(); itrInner != innerMap.end(); ++itrInner) {
            // push key to result vector if it's value is equal to unwanted value
            if(itrInner->second == value)
                result.push_back(itrInner->first);
        }
        return result;
    }

    ///
    /// This method help CourseSelection object removed all unwanted student based on Selection Vector and Origin Data
    ///@brief core of this student data filter
    ///
    void getDataBasedOnSelection(){
        if(selection.size()!=0) {
            // find all unwanted student id
            for (int i = 0; i < selection.size(); i++) {
                string eraseStr = selection[i]; /*!< current unwanted student id ready to delete>*/
                map <string, map < string, string >>::iterator itr;
                // for loop course data map
                for (itr = data.begin(); itr != data.end(); ++itr) {
                    map<string, string> innerMap = itr->second;
                    // get all keys that contains unwanted value
                    vector<string> eraseKey = isExistValue(eraseStr, innerMap);
                    // loop the key vector and let data map remove them
                    for(string key: eraseKey){
                        itr->second.erase(key);
                    }
                }
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
    void setData(map<string,map<string, string>> data){
        this->data = data;
    };

    ///
    /// accessor method to get private attribute data map
    /// @return private attribute map data
    ///
    map<string,map<string, string>> getData(){
        return data;
    };
};