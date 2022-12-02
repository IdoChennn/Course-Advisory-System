#include "SelectionHeader.h"
///
/// This is the one of the input filter in InputSelection model;
/// It's allowed user to get ride of unwanted data corresponding to certain course(s) in the dataset
///@author Ido chen
///@author Yanwen wang
///@author Mingyu Yu
///
class CourseSelection{
private:
    /// first map(wholeData) contains <Year, CousrsId>
    /// second map(CourseData) contains<CourseId: CourseData>
    /// CourseData is from Models/CourseMeta.cpp, since our CourseData is not complete yet, we use float instead
    map<string,map<string, CourseMeta>> data; /*!< Data contains All needed Course Data > */
    vector<string> selection; /*!< selection contains all unwanted selection >*/
public:

    ///
    ///Empty constructor for creating an courseSelection object without passing parameters
    ///
    CourseSelection(){};

    ///
    ///This is the actual constructor of the CourseSelection class
    ///@param data Contains All needed Course Data
    ///@param selection Contains all unwanted selection
    ///
    CourseSelection(map<string,map<string, CourseMeta>> data, vector<string> selection){
        this->data = data;
        this->selection = selection;
    };

    ///
    ///deconstructor of the class
    ///
    ~CourseSelection(){};

    ///
    /// This method help CourseSelection object removed all unwanted course based on Selection Vector and Origin Data
    ///
    void getDataBasedOnSelection(){
        if(selection.size()!=0) {
            // outer loop the unwanted course id
            for (int i = 0; i < selection.size(); i++) {
                string eraseStr = selection[i];
                // inner loop the actual pair contains <course ID, course Data>
                map < string, map < string, CourseMeta >> ::iterator itr;
                for (itr = data.begin(); itr != data.end(); ++itr) {
                    // removed unwanted data
                    itr->second.erase(eraseStr);
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