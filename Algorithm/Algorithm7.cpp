#include "config.h"
///
///This is the seventh result generating algorithm
///Unlike give feedback about the instructor in A6, this algorithm focus on feedbacks that students give to the course - course rate
///The arithmetic is: a feedback would contains four evaluation standards - 1. if the student would recommend this course to friends;
///2. if the student would recommend this instructor to friends 3. if the course is impactful to the student's knowledge base
///4. if the course makes the student improved, each of the parts have a mark from 1 to 5
///, and finally we find the average of all four evaluation standards to find course rate
///@brief Find course rate (how student evaluate the course)
///@author Yanwen Wang
///@author Ido Chen
///@author Baishen jiang
///
class Algorithm7 {
private:
    vector<float> recommendCourse; /*<if the student would recommend this course to friends>*/
    vector<float> recommendInstructor;/*<if the student would recommend this instructor to friends>*/
    vector<float> impactfulFromTheCourse;/*<if the course is impactful to the student's knowledge base>*/
    vector<float> improvements;/*<if the course makes the student improved>*/

public:
    ///
    ///empty constructor
    ///
    Algorithm7() {}
    /// the rest of code is pretty much the same as algorithm6
    Algorithm7(vector<float> recommendCourse, vector<float> recommendInstructor, vector<float> impactfulFromTheCourse, vector<float> improvements) {
        this->recommendCourse = recommendCourse;
        this->recommendInstructor = recommendInstructor;
        this->impactfulFromTheCourse = impactfulFromTheCourse;
        this->improvements = improvements;
    }

    ~Algorithm7() {}

    float getHighCommentRate(vector<float> dataset){

        const float HIGHESTRATE = 5.0;
        float result = 0.0;
        float counter = 0.0;
        float threshold = 0.8 * HIGHESTRATE;
        for(float data : dataset){
            if(data >= threshold)
                counter += 1;
        }
        return counter;
    }

    float getDataSetAverage(vector<float> dataset){
        float result = 0.0;
        int size = dataset.size();
        if(size == 0) throw 102;

        for(int i = 0; i < size; i++){
            result += dataset[i];
        }

        return result/size;
    }

    float getOverallFeedbackScore(){
        float result = 0.0;
        result += getDataSetAverage(recommendCourse);
        result += getDataSetAverage(recommendInstructor);
        result += getDataSetAverage(impactfulFromTheCourse);
        result += getDataSetAverage(improvements);
        return result/4.0;
    }

    void setRecommendCourse(vector<float> recommendCourse){
        this->recommendCourse = recommendCourse;
    }
    void setRecommendInstructor(vector<float> recommendInstructor){
        this->recommendInstructor = recommendInstructor;
    }
    void setImpactfulFromTheCourse(vector<float> impactfulFromTheCourse){
        this->impactfulFromTheCourse = impactfulFromTheCourse;
    }
    void setImprovements(vector<float> improvements){
        this->improvements = improvements;
    }


};