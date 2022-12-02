//
// Created by Yanwe on 2022-11-06.
//
#include "SelectionHeader.h"
//
class SelectionAbstraction{
private:
    // year: course: courseData
    map<string,map<string, float>> data;
public:
    SelectionAbstraction(){};
    SelectionAbstraction(map<string,map<string, float>> data){
        this->data = data;
    };
    ~SelectionAbstraction(){};

    virtual void getDataBasedOnSelection()=0;

    void setData(map<string,map<string, float>> data){
        this->data = data;
    };
    map<string,map<string, float>> getData(){
        return data;
    };
};