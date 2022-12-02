#include "UtilityHeader.h"
#include "../Algorithm/AlgorithmConfig.h"

///
/// This class gets all fetch all data from input selection and transform
/// them into graph acceptable data
///@brief graph data maker
///@author Yanwen Wang
///@author Ido Chen
///
class DataLoader {

private:
    CourseMeta data; /*!< container for graph acceptable data > */
public:

    ///
    ///Empty constructor for creating an FileLoader object without passing parameters
    ///
    DataLoader(){};

    ///
    /// This class gets all fetch all data from input selection and transform them into graph acceptable data
    ///@brief constructor for graph data maker
    ///@param data container for graph acceptable data
    ///
    DataLoader(CourseMeta data){
        this->data = data;
    }
    ~DataLoader(){};

    // each assignment<average completion time, average mark, rate>
    ///
    ///This method fetch all data from input file and place the data into a large vector for later algorithm1 graph making
    ///@brief input file data grouper
    ///@return dataset needed by graph and format-acceptable by graph
    ///
    vector<vector<float>> algorithm1Graph(){
        int numOfStudent = 0;
        vector<vector<float>> result;
        Algorithm1 algorithm1;
        vector<vector<float>> grade;
        vector<vector<float>> time;

        Student student = data.getStudent();
        map<int, StudentRecord> curStudent = student.getStudentData();
        vector<float> curAssignGradeList1;
        vector<float> curAssignGradeList2;
        vector<float> curAssignGradeList3;
        vector<float> curAssignGradeList4;
        vector<float> curTimeSpentList1;
        vector<float> curTimeSpentList2;
        vector<float> curTimeSpentList3;
        vector<float> curTimeSpentList4;
        for (auto const& x : curStudent){
            numOfStudent += 1;
            StudentRecord curRec = x.second;
            // grade timeSpent
            map<float, float> curAssignment= curRec.getAssignmentRecord();
            int count = 1;
            for (auto const& t : curAssignment){
                float curAssignGrade = t.first;
                float curTimeSpent = t.second;
                switch (count) {
                    case 1:
                        curAssignGradeList1.push_back(curAssignGrade);
                        curTimeSpentList1.push_back(curTimeSpent);
                        break;
                    case 2:
                        curAssignGradeList2.push_back(curAssignGrade);
                        curTimeSpentList2.push_back(curTimeSpent);
                        break;
                    case 3:
                        curAssignGradeList3.push_back(curAssignGrade);
                        curTimeSpentList3.push_back(curTimeSpent);
                        break;
                    case 4:
                        curAssignGradeList4.push_back(curAssignGrade);
                        curTimeSpentList4.push_back(curTimeSpent);
                        break;
                }
                count += 1;
            }
        }
        grade.push_back(curAssignGradeList1);
        grade.push_back(curAssignGradeList2);
        grade.push_back(curAssignGradeList3);
        grade.push_back(curAssignGradeList4);
        time.push_back(curTimeSpentList1);
        time.push_back(curTimeSpentList2);
        time.push_back(curTimeSpentList3);
        time.push_back(curTimeSpentList4);
//        cout << grade.size();

        for(int i = 0 ; i < 4; i++){
            vector<float> tempVector1;
            algorithm1.setAssignTime(10);
            algorithm1.setSize(numOfStudent);

            algorithm1.setCompletionTime(time[i]);
            algorithm1.setMark(grade[i]);
            algorithm1.setCompletionTime(time[i]);
            algorithm1.setMark(grade[i]);

            tempVector1.push_back(algorithm1.getAverageCompletionTime());
            tempVector1.push_back(algorithm1.getAverageMark());
            tempVector1.push_back(algorithm1.getDegreeOfDifficulty());
            result.push_back(tempVector1);
        }
        return result;
    }

    ///
    ///This method fetch all data from input file and place the data into a large vector for later algorithm3 graph making
    ///@brief input file data grouper
    ///@return dataset needed by graph and format-acceptable by graph
    ///
    vector<int> algorithm3Graph(){
        // student id <grade,time used>
        map<int, pair<float, float>> inputs;
        Student student = data.getStudent();
        map<int, StudentRecord> record = student.getStudentData();
        for (auto const& t : record){
            StudentRecord studentRecord = t.second;
            float grade = studentRecord.getOverallGrade();
            float time = studentRecord.getTotalHoursSpent();
            inputs.insert(pair<int, pair<float, float>>(t.first, make_pair(grade, time)));
        }
        Algorithm3 algorithm3(inputs);
        return algorithm3.getAllStudentEfficientRatio();
    }



    ///
    ///This method fetch all data from input file and place the data into a large vector for later algorithm4 graph making
    ///@brief input file data grouper
    ///@return dataset needed by graph and format-acceptable by graph
    ///
    vector<float> algorithm4Graph(){
        vector<float> result;
        vector<float> studentGrades;
        vector<float> studentAttendances;
        vector<float> studentStudyHours;
        Student student = data.getStudent();
        map<int, StudentRecord> record = student.getStudentData();
        for (auto const& t : record){
            StudentRecord studentRecord = t.second;
            float grade = studentRecord.getOverallGrade();
            float time = studentRecord.getTotalHoursSpent();
            studentGrades.push_back(grade);
            studentStudyHours.push_back(time);
            studentAttendances.push_back(0.0);
        }

        Course course = data.getCourse();
//        cout << course.getFirstQuartGrade()[4] << endl;
//        cout << course.getSecondQuartGrade()[4] << endl;
//        cout << course.getThirdQuartGrade()[4] << endl;
//        cout << course.getFourthQuartGrade()[4] << endl;
        float attendance = 0.0;
        attendance += course.getFirstQuartGrade()[4];
        attendance += course.getSecondQuartGrade()[4];
        attendance += course.getThirdQuartGrade()[4];
        attendance += course.getFourthQuartGrade()[4];
        studentAttendances[0] = attendance;


        Algorithm4 algorithm4(studentGrades, studentAttendances, studentStudyHours);
        float averageGrade = algorithm4.getAverageGrade();
        float averageAttendance = algorithm4.getAverageAttendance();
        float averageHours = algorithm4.getAverageStudyHours();
        float utilRate = algorithm4.getLectureUtilizationRates();
        result.push_back(averageGrade);
        result.push_back(averageAttendance);
        result.push_back(averageHours);
        result.push_back(utilRate);
        return result;
    }

    ///
    ///This method fetch all data from input file and place the data into a large vector for later algorithm5 graph making
    ///@brief input file data grouper
    ///@return dataset needed by graph and format-acceptable by graph
    ///
    vector<vector<float>> algorithm5Graph(){
        Course course = data.getCourse();
        vector<vector<float>> result;
        vector<pair<float, float>> quizAttendance;
        vector<pair<float, float>> officeHourAttendance;
        vector<pair<float, float>> lectureAttendance;

        vector<float> firstQuartData = course.getFirstQuartGrade();
        vector<float> secondQuartData = course.getSecondQuartGrade();
        vector<float> thirdQuartData = course.getThirdQuartGrade();
        vector<float> fourthQuartData = course.getFourthQuartGrade();

        quizAttendance.push_back(make_pair(firstQuartData[0], firstQuartData[1]));
        quizAttendance.push_back(make_pair(secondQuartData[0], secondQuartData[1]));
        quizAttendance.push_back(make_pair(thirdQuartData[0], thirdQuartData[1]));
        quizAttendance.push_back(make_pair(fourthQuartData[0], fourthQuartData[1]));

        officeHourAttendance.push_back(make_pair(firstQuartData[2], firstQuartData[3]));
        officeHourAttendance.push_back(make_pair(secondQuartData[2], secondQuartData[3]));
        officeHourAttendance.push_back(make_pair(thirdQuartData[2], thirdQuartData[3]));
        officeHourAttendance.push_back(make_pair(fourthQuartData[2], fourthQuartData[3]));

        lectureAttendance.push_back(make_pair(firstQuartData[4], firstQuartData[5]));
        lectureAttendance.push_back(make_pair(secondQuartData[4], secondQuartData[5]));
        lectureAttendance.push_back(make_pair(thirdQuartData[4], thirdQuartData[5]));
        lectureAttendance.push_back(make_pair(fourthQuartData[4], fourthQuartData[5]));

        Algorithm5 algorithm5(quizAttendance, officeHourAttendance, lectureAttendance);

        vector<float> quizAttendanceRate = algorithm5.getAttendanceRate(quizAttendance);
        vector<float> officeHourAttendanceRate = algorithm5.getAttendanceRate(officeHourAttendance);
        vector<float> lectureAttendanceRate = algorithm5.getAttendanceRate(lectureAttendance);
        vector<float> overAllRate;
        for(int i = 0; i < quizAttendanceRate.size(); i++){
            float currOverall = (quizAttendanceRate[i] + officeHourAttendanceRate[i] + lectureAttendanceRate[i])/3;
            overAllRate.push_back(currOverall);
        }

        vector<float> allAttendanceRateChange = algorithm5.getAttendanceRateChange(overAllRate);

        firstQuartData.push_back(overAllRate[0]);
        firstQuartData.push_back(0);
        secondQuartData.push_back(overAllRate[1]);
        secondQuartData.push_back(allAttendanceRateChange[1]);
        thirdQuartData.push_back(overAllRate[2]);
        thirdQuartData.push_back(allAttendanceRateChange[2]);
        fourthQuartData.push_back(overAllRate[3]);
        fourthQuartData.push_back(allAttendanceRateChange[3]);
        result.push_back(firstQuartData);
        result.push_back(secondQuartData);
        result.push_back(thirdQuartData);
        result.push_back(fourthQuartData);

        return result;
    }

    ///
    ///This method fetch all data from input file and place the data into a large vector for later algorithm6 graph making
    ///@brief input file data grouper
    ///@return dataset needed by graph and format-acceptable by graph
    ///
    vector<float> algorithm6Graph(){
        vector<float> result;

        StudentFeedback studentFeedback = data.getStudentFeedback();
        vector<float> assignmentClassDesign = studentFeedback.getAssignmentClassDesign();
        vector<float> assignmentFeedback = studentFeedback.getAssignmentFeedback();
        vector<float> assignmentReturn = studentFeedback.getAssignmentReturn();
        vector<float> assignmentDemonstrate = studentFeedback.getAssignmentDemonstrate();

        Algorithm6 algorithm6(assignmentFeedback, assignmentDemonstrate, assignmentClassDesign, assignmentReturn);
        result.push_back(algorithm6.getHighCommentRate(assignmentFeedback));
        result.push_back(algorithm6.getDataSetAverage(assignmentFeedback));

        result.push_back(algorithm6.getHighCommentRate(assignmentDemonstrate));
        result.push_back(algorithm6.getDataSetAverage(assignmentDemonstrate));

        result.push_back(algorithm6.getHighCommentRate(assignmentClassDesign));
        result.push_back(algorithm6.getDataSetAverage(assignmentClassDesign));

        result.push_back(algorithm6.getHighCommentRate(assignmentReturn));
        result.push_back(algorithm6.getDataSetAverage(assignmentReturn));


        return result;

    }

    ///
    ///This method fetch all data from input file and place the data into a large vector for later algorithm7 graph making
    ///@brief input file data grouper
    ///@return dataset needed by graph and format-acceptable by graph
    ///
    vector<float> algorithm7Graph(){
        vector<float> result;

        StudentRecommend studentRecommend = data.getStudentRecommend();
        vector<float> recommendCourse = studentRecommend.getRecommendCourse();
        vector<float> recommendInstructor = studentRecommend.getRecommendInstructor();
        vector<float> impactfulFromTheCourse = studentRecommend.getImpactFul();
        vector<float> improvements = studentRecommend.getImprovements();

        Algorithm6 algorithm7(recommendCourse, recommendInstructor, impactfulFromTheCourse, improvements);
        result.push_back(algorithm7.getHighCommentRate(recommendCourse));
        result.push_back(algorithm7.getDataSetAverage(recommendCourse));

        result.push_back(algorithm7.getHighCommentRate(recommendInstructor));
        result.push_back(algorithm7.getDataSetAverage(recommendInstructor));

        result.push_back(algorithm7.getHighCommentRate(impactfulFromTheCourse));
        result.push_back(algorithm7.getDataSetAverage(impactfulFromTheCourse));

        result.push_back(algorithm7.getHighCommentRate(improvements));
        result.push_back(algorithm7.getDataSetAverage(improvements));


        return result;

    }
};