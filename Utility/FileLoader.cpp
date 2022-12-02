#include "UtilityHeader.h"

///
///This class loads file from user selected file in file browser
///@brief load and read files
///@author Ido Chen
///@author YanwenWang
///
class FileLoader {

private:
    string fileName;
    map<string,map<string, CourseMeta>> data; /*!< container that stores all refined data required by the program > */

public:

    ///
    ///Empty constructor for creating an FileLoader object without passing parameters
    ///
    FileLoader(){}

    ///
    ///Constructor of the class. This file loader class loads input file from user and transform the raw dataset to
    ///program's desired objects, such as Course object, student object, student feedback object etc.
    ///@brief file loader and program objects builder
    ///@param fileName name of input file
    ///
    ///
    FileLoader(string fileName){
        this->fileName = fileName;
        loadFileToData(fileName);
    }

    ///
    ///This method calculates course grade for single student
    ///@brief course grade calculator
    ///@param quizMark student quiz mark
    ///@param exam student exam mark
    ///@param assignment student assignment mark
    ///@return student final course grade
    ///
    float calculateOverAllGrade(vector<float> quizMark, vector<float> exam, vector<float> assignment){
        float result = 0.0;

        for(float grade: quizMark){
            result += grade/100 *QUIZRITIO;
        }

        for(float grade: exam){
            result += grade/100 *EXMRITIO;
        }

        for(float grade: assignment){
            result += grade/100 *ASSIGNMENTRITIO;
        }
        return result;
    }

    ///
    ///This method initializes studentRecord object and pass data to the object
    ///@brief studentRecord object initializer
    ///@param row every single row of input csv file
    ///@return studentRecord object that stores information about single student
    ///
    StudentRecord figureStudentRecord(vector<string> row){
        int id = stoi(row[2]);
        string fullName = row[3] + " " + row[4];
        vector<float> quizMark{stof(row[8]), stof(row[9]), stof(row[10]), stof(row[11])};
        vector<float> exam{stof(row[6]), stof(row[7])};
        vector<float> assignmentMark{stof(row[28]), stof(row[29]), stof(row[30]), stof(row[31])};
        map<float, float> assignmentRecord ={
                {stof(row[28]), stof(row[32])},
                {stof(row[29]), stof(row[33])},
                {stof(row[30]), stof(row[34])},
                {stof(row[31]), stof(row[35])}
        };
        float totalHoursSpent = stof(row[5]);
        float overAllGrade = calculateOverAllGrade(quizMark, exam, assignmentMark);
        StudentRecord studentRecord(id, fullName, quizMark, exam, assignmentRecord, totalHoursSpent, overAllGrade);
        return studentRecord;
    }

    ///
    ///This method initializes course object and insert required data to the object
    ///@brief course object initializer
    ///@param row a row in the input csv file
    ///@param origin course object
    ///@return course object that stores all information about the course
    ///
    Course loadCourseMeta(Course origin, vector<string> row){
        int numberOfStudent = origin.getNumberOfStudent();
        if(numberOfStudent < 0)
            numberOfStudent = 0;
        numberOfStudent += 1;
        origin.setNumberOfStudent(numberOfStudent);
//        cout << numberOfStudent << endl;

        float courseAverage = origin.getCourseAverage();
        // quiz1_mark -> 8 quiz2_mark -> 9 quiz3_mark -> 10 quiz4_mark -> 11
        vector<float> quizMark{stof(row[8]), stof(row[9]), stof(row[10]), stof(row[11])};
        // midterm_mark -> 6 final_mark -> 7
        vector<float> exam{stof(row[6]),stof(row[7])};
        // assignment1_mark -> 28 assignment2_mark -> 29 assignment3_mark -> 30 assignment4_mark -> 31
        vector<float> assignment{stof(row[28]),stof(row[29]),stof(row[30]),stof(row[31])};
        courseAverage += calculateOverAllGrade(quizMark, exam, assignment);
        courseAverage = courseAverage / numberOfStudent;
        origin.setCourseAverage(courseAverage);

        vector<float> assignmentAssignTime = origin.getAssignmentAssignTime();
        if(assignmentAssignTime.size() < 4){
            assignmentAssignTime.push_back(stof(row[36]));
            assignmentAssignTime.push_back(stof(row[37]));
            assignmentAssignTime.push_back(stof(row[38]));
            assignmentAssignTime.push_back(stof(row[39]));
            origin.setAssignmentAssignTime(assignmentAssignTime);
        }


        vector<float> assignmentGrade = origin.getAssigmentGrade();
        if(assignmentGrade.size() < 4){
            assignmentGrade.push_back(stof(row[28]));
            assignmentGrade.push_back(stof(row[29]));
            assignmentGrade.push_back(stof(row[30]));
            assignmentGrade.push_back(stof(row[31]));
        }
        else{
            assignmentGrade[0] = (assignmentGrade[0]*(numberOfStudent-1)+stof(row[28]))/numberOfStudent;
            assignmentGrade[1] = (assignmentGrade[1]*(numberOfStudent-1)+stof(row[29]))/numberOfStudent;
            assignmentGrade[2] = (assignmentGrade[2]*(numberOfStudent-1)+stof(row[30]))/numberOfStudent;
            assignmentGrade[3] = (assignmentGrade[3]*(numberOfStudent-1)+stof(row[31]))/numberOfStudent;
        }
        origin.setAssignmentGrade(assignmentGrade);

        vector<float> examGrade = origin.getExmGrade();
        if(examGrade.size() < 2){
            examGrade.push_back(stof(row[6]));
            examGrade.push_back(stof(row[7]));
        }
        else{
            examGrade[0] = (examGrade[0]+stof(row[6]))/numberOfStudent;
            examGrade[1] = (examGrade[1]+stof(row[7]))/numberOfStudent;
        }
        origin.setExmGrade(examGrade);

        vector<float> quizGrade = origin.getQuizGrade();
        if(quizGrade.size() < 4){
            quizGrade.push_back(stof(row[8]));
            quizGrade.push_back(stof(row[9]));
            quizGrade.push_back(stof(row[10]));
            quizGrade.push_back(stof(row[11]));
        }
        else{
            quizGrade[0] = (quizGrade[0]*(numberOfStudent-1)+stof(row[8]))/numberOfStudent;
            quizGrade[0] = (quizGrade[1]*(numberOfStudent-1)+stof(row[9]))/numberOfStudent;
            quizGrade[0] = (quizGrade[2]*(numberOfStudent-1)+stof(row[10]))/numberOfStudent;
            quizGrade[0] = (quizGrade[3]*(numberOfStudent-1)+stof(row[11]))/numberOfStudent;
        }
        origin.setQuizGrade(quizGrade);

        //quiz attendance and student number, office hour attendance and overall hour(10), lecture attendance and student number(2)
        vector<float> firstQuartData = origin.getFirstQuartGrade();
        // quiz1_mark -> 8 quiz2_mark -> 9 quiz3_mark -> 10 quiz4_mark -> 11
        // office1_attendance -> 12 office2_attendance -> 13 office3_attendance -> 14 office4_attendance -> 15
        // lecture1_attendance -> 16 lecture2_attendance -> 17 lecture3_attendance -> 18 lecture4_attendance -> 19
        // not attending quiz1
        if(firstQuartData.size() < 6){
            for(int i = 0; i < 6; i++)
                firstQuartData.push_back(0.0);
        }
        if(row[8] == "0.0") firstQuartData[0] += 0.0;
        else firstQuartData[0] += 1.0;
        firstQuartData[1] = firstQuartData[0];
        firstQuartData[2] += stof(row[12]);
        firstQuartData[3] += 10.0;
        firstQuartData[4] += stof(row[16]);
        firstQuartData[5] += 2.0;
        origin.setFirstQuartData(firstQuartData);


        vector<float> secondQuartData = origin.getSecondQuartGrade();
        if(secondQuartData.size() < 6){
            for(int i = 0; i < 6; i++)
                secondQuartData.push_back(0.0);
        }
        if(row[9] == "0.0") secondQuartData[0] += 0.0;
        else secondQuartData[0] += 1.0;
        secondQuartData[1] = secondQuartData[0];
        secondQuartData[2] += stof(row[13]);
        secondQuartData[3] += 10.0;
        secondQuartData[4] += stof(row[17]);
        secondQuartData[5] += 2.0;
        origin.setSecondQuartData(secondQuartData);

        vector<float> thirdQuartData = origin.getThirdQuartGrade();
        if(thirdQuartData.size() < 6){
            for(int i = 0; i < 6; i++)
                thirdQuartData.push_back(0.0);
        }
        if(row[10] == "0.0") thirdQuartData[0] += 0.0;
        else thirdQuartData[0] += 1.0;
        thirdQuartData[1] = thirdQuartData[0];
        thirdQuartData[2] += stof(row[14]);
        thirdQuartData[3] += 10.0;
        thirdQuartData[4] += stof(row[18]);
        thirdQuartData[5] += 2.0;
        origin.setThirdQuartData(thirdQuartData);


        vector<float> fourthQuartData = origin.getFourthQuartGrade();
        if(fourthQuartData.size() < 6){
            for(int i = 0; i < 6; i++)
                fourthQuartData.push_back(0.0);
        }
        if(row[11] == "0.0") fourthQuartData[0] += 0.0;
        else fourthQuartData[0] += 1.0;
        fourthQuartData[1] = fourthQuartData[0];
        fourthQuartData[2] += stof(row[15]);
        fourthQuartData[3] += 10.0;
        fourthQuartData[4] += stof(row[19]);
        fourthQuartData[5] += 2.0;
        origin.setFourthQuartData(fourthQuartData);

        return origin;
    }

    ///
    ///This method initializes student feedback object and pass required data to the object
    ///@brief studentFeedback object initializer
    ///@param origin the empty studentfeedback object that is going to be filed
    ///@param assignmentFeedback students' evaluation about the instructor in terms of the assignment feedback instructor gives to the student
    ///@param assignmentDemonstrate students' evaluation about the instructor in terms of the clarity of the given assignment criteria.
    ///@param assignmentReturn students' evaluation about the instructor in terms of assignment return time
    ///@param classDesign students' evaluation about the instructor in terms of the overall design of the class structure
    ///@return filled studentfeedback object
    ///
    StudentFeedback loadStudentFeedback(StudentFeedback origin, float assignmentFeedback, float assignmentDemonstrate, float assignmentReturn, float classDesign){
        vector<float> assignmentFeedbackList = origin.getAssignmentFeedback();
        assignmentFeedbackList.push_back(assignmentFeedback);
        origin.setAssignmentFeedback(assignmentFeedbackList);

        vector<float> assignmentDemonstrateList = origin.getAssignmentDemonstrate();
        assignmentDemonstrateList.push_back(assignmentDemonstrate);
        origin.setAssignmentDemonstrate(assignmentDemonstrateList);

        vector<float> assignmentReturnList = origin.getAssignmentReturn();
        assignmentReturnList.push_back(assignmentReturn);
        origin.setAssignmentReturn(assignmentReturnList);

        vector<float> classDesignList = origin.getAssignmentClassDesign();
        classDesignList.push_back(classDesign);
        origin.setAssignmentClassDesign(classDesignList);
        return origin;
    }

    ///
    ///This method initializes student recommend object and pass required data to the object
    ///@brief studentRecommend object initializer
    ///@param origin the empty studentRecommend object that is going to be filed
    ///@param recommendCourse students' evaluation about the course in terms of whether the student would like recommend the course to friends
    ///@param recommendInstructor students' evaluation about the course in terms of whether the student would like recommend the instructor to friends
    ///@param impactful students' evaluation about the course in terms of whether the student feel the course is impactful to his/her study or life
    ///@param improvements students' evaluation about the course in terms of whether the student feel the course can improve his/her skills
    ///@return filled studentfeedback object
    ///
    StudentRecommend loadStudentRecommend(StudentRecommend origin, float recommendCourse, float recommendInstructor, float impactful, float improvements){
        vector<float> recommendCourseList = origin.getRecommendCourse();
        recommendCourseList.push_back(recommendCourse);
        origin.setRecommendCourse(recommendCourseList);

        vector<float> recommendInstructorList = origin.getRecommendInstructor();
        recommendInstructorList.push_back(recommendInstructor);
        origin.setRecommendInstructor(recommendInstructorList);

        vector<float> impactfulList = origin.getImpactFul();
        impactfulList.push_back(impactful);
        origin.setImpactful(impactfulList);

        vector<float> improvementsList = origin.getImprovements();
        improvementsList.push_back(improvements);
        origin.setImprovements(improvementsList);
        return origin;
    }

    ///
    ///Core utility of this class. This method loads and reads the input csv file line by line,
    ///passing necessary data to each object initializer alone side.
    ///@brief file loader gear
    ///@param fileName name of the file stored in the same directory as in source file
    ///
    void loadFileToData(string fileName){
        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file (fileName, ios::in);
        if(file.is_open()){
            while(getline(file, line)){
                row.clear();
                stringstream str(line);
                while(getline(str, word, ',')){
                    // empty element or blank cell
                    if(word == "")
                        word = "0.0";
                    row.push_back(word);
                }
                // skip the header
                if(row[0] == "course")
                    continue;
                // found the current year
                if(data.find(row[1]) != data.end()){
                    map<string, CourseMeta> courseData = data[row[1]];

                    // found the current course
                    if(courseData.find(row[0]) != courseData.end()){
                        CourseMeta courseMeta = courseData[row[0]];
                        // student meta
                        Student student = courseMeta.getStudent();
                        map<int, StudentRecord> studentData = student.getStudentData();
                        StudentRecord studentRecord = figureStudentRecord(row);
                        studentData.insert({stoi(row[2]), studentRecord});
                        student.setStudent(studentData);

                        // course detail
                        Course courseDetail = courseMeta.getCourse();
                        Course newCourse = loadCourseMeta(courseDetail, row);

                        // student feedback 20-21-22-23
                        StudentFeedback studentFeedback = courseMeta.getStudentFeedback();
                        StudentFeedback newFeedback = loadStudentFeedback(studentFeedback, stof(row[20]), stof(row[21]), stof(row[22]), stof(row[23]));

                        // student recommend
                        // recommend_course -> 24 recommend_instructor -> 25 inpactful -> 26 imporvements -> 27
                        StudentRecommend studentRecommend = courseMeta.getStudentRecommend();
                        StudentRecommend newRecommend = loadStudentRecommend(studentRecommend, stof(row[24]), stof(row[25]), stof(row[26]), stof(row[27]));



                        data[row[1]][row[0]].setStudent(student);
                        data[row[1]][row[0]].setStudentFeedback(newFeedback);
                        data[row[1]][row[0]].setStudentRecommend(newRecommend);
                        data[row[1]][row[0]].setCourse(newCourse);
                    }
                    // not found the course, the created the current course
                    else{
                        map<int, StudentRecord> studentData;
                        StudentRecord studentRecord = figureStudentRecord(row);
                        studentData.insert({stoi(row[2]), studentRecord});
                        Student student(studentData);
                        Course course;
                        StudentFeedback studentFeedback;
                        StudentRecommend studentRecommend;
                        CourseMeta courseMeta(student, course, studentFeedback, studentRecommend);

                        data[row[1]].insert({row[0], courseMeta});
                    }

                }
                // not found, then create the current year map
                else{
                    // courseData is the large loop
                    map<string, CourseMeta> courseData;
                    data.insert({row[1], courseData});
                }
                //Details of file reading algorithm
                // row is current line value
                // course -> 0 year -> 1 id -> 2
                // first_name -> 3 last_name -> 4 total_hour_spent -> 5
                // midterm_mark -> 6 final_mark -> 7
                // quiz1_mark -> 8 quiz2_mark -> 9 quiz3_mark -> 10 quiz4_mark -> 11
                // office1_attendance -> 12 office2_attendance -> 13 office3_attendance -> 14 office4_attendance -> 15
                // lecture1_attendance -> 16 lecture2_attendance -> 17 lecture3_attendance -> 18 lecture4_attendance -> 19
                // assignment_feeback -> 20 assignment_demonstrate -> 21 assignment_return -> 22 class_design -> 23
                // recommend_course -> 24 recommend_instructor -> 25 inpactful -> 26 imporvements -> 27
                // assignment1_mark -> 28 assignment2_mark -> 29 assignment3_mark -> 30 assignment4_mark -> 31
                // assignment1_time_spent -> 32 assignment2_time_spent -> 33 assignment3_time_spent -> 34 assignment4_time_spent -> 35
                // assignment1_time_assigned -> 36 assignment2_time_assigned -> 37 assignment3_time_assigned -> 38 assignment4_time_assigned -> 39
                content.push_back(row);
            }

        }
        else
            cout<<"Could not open the file\n";

    }
    ///
    ///getter method for private attribute data
    ///@brief getter
    ///@return the refined data container that stores program's all required data
    ///
    map<string,map<string, CourseMeta>> getData(){
        return data;
    }


};
