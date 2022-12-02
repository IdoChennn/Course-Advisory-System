///
///@file ModelHeader.h
///This interface file provides all necessary data structure required by the program
///@brief module interface
///
///

///
///@dir group39/Models
///This module outlines, create and instantiate all necessary data type/structure required by the program
///@brief data structure creation module
///
///
#ifndef GROUP39_MODELHEADER_H
#define GROUP39_MODELHEADER_H

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <cstdlib>
#include <numeric>

////
////This class defines data structure related to student record. A student record object contains everything about a student,
///such as grades from various sources and hours spent on course.
///@brief one of data structure of the program- student record
///@author Ido Chen
////@author Yanwen Wang
////@author Yubo He
////
class StudentRecord{

private:
    int studentID; /*!< student identification number > */
    std::string studentName; /*!< name of the student > */
    std::vector<float> quizMark; /*!< student quiz mark> */
    std::vector<float> exmMark; /*!< student exam mark > */
    std::map<float, float> assignmentRecord; /*!< student assignments' mark (container of a student's all assignment grade) > */
    float totalHoursSpent; /*!< total amount of time spent by student on the course > */
    float overallGrade; /*!< student's course grade > */
public:

    StudentRecord();
    StudentRecord(int studentID, std::string studentName, std::vector<float> quizMark,
                  std::vector<float> exmMark, std::map<float, float> assignmentRecord,
                  float totalHoursSpent, float overallGrade);

    void setStudentId(int studentID);
    void setStudentName(std::string studentName);
    void setQuizMark(std::vector<float> quizMark);
    void setExmMark(std::vector<float> exmMark);
    void setAssignmentRecord(std::map<float,float> assignmentRecord);
    void setTotalHoursSpent(float totalHoursSpent);
    void setOverallGrade(float overallGrade);

    int getStudentId();
    std::string getStudentName();
    std::vector<float> getQuizMark();
    std::vector<float> getExmMark();
    std::map<float,float> getAssignmentRecord();
    float getTotalHoursSpent();
    float getOverallGrade();
    ~StudentRecord();
};

///
///This class defines data structure related to student. A student object wraps up all student record object.
///In other words, a student object is a container of student records objects
///@brief one of data structure of the program- student (studentRecords object container)
///@author Ido Chen
///@author Yanwen Wang
///@author Yubo He
///
class Student{
private:
    std::map<int, StudentRecord> studentData; /*!< container of studentRecords > */
public:
    Student();
    Student(std::map<int, StudentRecord> studentData);
    ~Student();
    void setStudent(std::map<int, StudentRecord> studentData);
    std::map<int, StudentRecord> getStudentData();
};

///
///This class defines data structure related to course. A Course object contains everything about a course,
///such as grades, assignment, assignment assigning time etc.
///@brief one of data structure of the program- course
///@author Ido Chen
////@author Yanwen Wang
////@author Yubo He
///
class Course{

private:
    int numberOfStudent; /*!< number of students in the course > */
    float courseAverage; /*!< average mark of the course> */
    std::vector<float> assignmentAssignTime, /*!< time assigned to students to complete the course work > */
    assignmentGrade, /*!< assignment mark > */
    exmGrade, /*!< exam mark > */  quizGrade, /*!< quiz mark > */
    firstQuartData, /*!< course information during first 1/4 of the term> */
    SecondQuartData, /*!< course information during second 1/4 of the term > */
    ThirdQuartData, /*!< course information during third 1/4 of the term> */
    FourthQuartData; /*!< course information during fourth 1/4 of the term> */

public:
    Course();
    Course(int numberOfStudent,float courseAverage,
           std::vector<float> assignmentAssignTime,
           std::vector<float> assignmentGrade,std::vector<float> exmGrade,
           std::vector<float> quizGrade,std::vector<float> firstQuartData,
           std::vector<float> SecondQuartData,std::vector<float> ThirdQuartData,
           std::vector<float> FourthQuartData);

    void setNumberOfStudent(int numberOfStudent);
    void setCourseAverage(float courseAverage);
    void setAssignmentAssignTime(std::vector<float> assignmentAssignTime);
    void setAssignmentGrade(std::vector<float> assignmentGrade);
    void setExmGrade(std::vector<float> exmGrade);
    void setQuizGrade(std::vector<float> quizGrade);
    void setFirstQuartData(std::vector<float> firstQuartData);
    void setSecondQuartData(std::vector<float> SecondQuartData);
    void setThirdQuartData(std::vector<float> ThirdQuartData);
    void setFourthQuartData(std::vector<float> FourthQuartData);

    int getNumberOfStudent();
    float getCourseAverage();
    std::vector<float> getAssignmentAssignTime();
    std::vector<float> getAssigmentGrade();
    std::vector<float> getExmGrade();
    std::vector<float> getQuizGrade();
    std::vector<float> getFirstQuartGrade();
    std::vector<float> getSecondQuartGrade();
    std::vector<float> getThirdQuartGrade();
    std::vector<float> getFourthQuartGrade();
    ~Course();
};

///
///This class defines studentFeedback data structure of the program.
///A studentFeedback object contains information of students' evaluation about the instructor from four standards
///assignmentFeedback, assignmentDemonstrate(clarity),assignmentReturn,classDesign
///@brief one of data structure of the program- StudentFeedback
///@author Ido Chen
///@author Yanwen Wang
///@author Yubo He
///
class StudentFeedback{
private:
    std::vector<float> assignmentFeedback, /*!< students' evaluation about the instructor in terms of the assignment feedback instructor gives to the student > */
    assignmentDemonstrate, /*!< students' evaluation about the instructor in terms of the clarity of the given assignment criteria.> */
    assignmentReturn,/*!< students' evaluation about the instructor in terms of assignment return time> */
    classDesign;/*!< students' evaluation about the instructor in terms of the overall design of the class structure > */
public:
    StudentFeedback();
    StudentFeedback(std::vector<float> assignmentFeedback,std::vector<float> assignmentDemonstrate,
                    std::vector<float> assignmentReturn,std::vector<float> classDesign);

    void setAssignmentFeedback(std::vector<float> assignmentFeedback);
    void setAssignmentDemonstrate(std::vector<float> assignmentDemonstrate);
    void setAssignmentReturn(std::vector<float> assignmentReturn);
    void setAssignmentClassDesign(std::vector<float> classDesign);

    std::vector<float> getAssignmentFeedback();
    std::vector<float> getAssignmentDemonstrate();
    std::vector<float> getAssignmentReturn();
    std::vector<float> getAssignmentClassDesign();


    ~StudentFeedback();
};

///
///This class defines studentRecommend data structure of the program.
///A studentFeedback object contains information of students' evaluation about the course
///@brief one of data structure of the program- StudentRecommend
///@author Ido Chen
///@author Yanwen Wang
///@author Yubo He
///
class StudentRecommend{
private:
    std::vector<float> recommendCourse,recommendInstructor,impactful,improvements;
   
public:
    StudentRecommend();
    StudentRecommend(std::vector<float> recommendCourse,std::vector<float> recommendInstructor,
                     std::vector<float> impactful,std::vector<float> improvements);

    void setRecommendCourse(std::vector<float> recommendCourse);
    void setRecommendInstructor(std::vector<float> recommendInstructor);
    void setImpactful(std::vector<float> impactful);
    void setImprovements(std::vector<float> improvements);

    std::vector<float> getRecommendCourse();
    std::vector<float> getRecommendInstructor();
    std::vector<float> getImpactFul();
    std::vector<float> getImprovements();
    ~StudentRecommend();

};

///
///This class defines meta information of a course.
///A CourseMeta object contains meta information about a course, such as number of students, course object itself, and feedback about the course.
///@brief one of data structure of the program- CourseMeta
///@author Ido Chen
///@author Yanwen Wang
///@author Yubo He
///
class CourseMeta{
 private:
     Student student; /*!< student object> */
     Course course;/*!< course object > */
     StudentFeedback studentFeedback;/*!< student evaluation about instructor> */
     StudentRecommend studentRecommend;/*!< student evaluation about the course > */
public:

    CourseMeta();
    ~CourseMeta();
    CourseMeta(Student student,Course course,StudentFeedback studentFeedback,StudentRecommend studentRecommend);
    void setStudent(Student student);
    void setCourse(Course course);
    void setStudentFeedback(StudentFeedback studentFeedback);
    void setStudentRecommend(StudentRecommend studentRecommend);
    Student getStudent();
    Course getCourse();
    StudentFeedback getStudentFeedback();
    StudentRecommend getStudentRecommend();
};
#endif //GROUP39_MODELHEADER_H
