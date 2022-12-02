#include "analyzedialog.h"
#include "ui_analyzedialog.h"
#include "detailedcontentdialog.h"
#include "detailedcontentdialog2.h"
#include "detailedcontentdialog3.h"
#include "detailedcontentdialog4.h"
#include "detailedcontentdialog5.h"
#include "detailedcontentdialog6.h"
#include<QDebug>

///
/// This is the constructor of the analyzing window. This constructor will store all graph data passed from the main window
/// \param graph1 graph for result calculated by algorithm1
/// \param Qgraph2 graph for result calculated by algorithm3
/// \param Qgraph3 graph for result calculated by algorithm4
/// \param Qgraph4 graph for result calculated by algorithm5
/// \param Qgraph5 graph for result calculated by algorithm6
/// \param Qgraph6 graph for result calculated by algorithm7
/// \param parent window object
///
AnalyzeDialog::AnalyzeDialog(QVector<QVector<float>> graph1,QVector<float> Qgraph2,
                             QVector<float> Qgraph3,
                             QVector<QVector<float>> Qgraph4,
                             QVector<float> Qgraph5,
                             QVector<float> Qgraph6,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalyzeDialog)
{
    this->graph1 = graph1;
    this->Qgraph2 = Qgraph2;
    this->Qgraph3 = Qgraph3;
    this->Qgraph4 = Qgraph4;
    this->Qgraph5 = Qgraph5;
    this->Qgraph6 = Qgraph6;

    ui->setupUi(this);
    ui->button_1->setCursor(Qt::PointingHandCursor);
    ui->button_2->setCursor(Qt::PointingHandCursor);
    ui->button_3->setCursor(Qt::PointingHandCursor);
    ui->button_4->setCursor(Qt::PointingHandCursor);
    ui->button_5->setCursor(Qt::PointingHandCursor);
    ui->button_6->setCursor(Qt::PointingHandCursor);

    drawA1();
    drawA2();
    drawA3();
    drawA4();
    drawA5();
    drawA6();

}
///
///Drawer for algorithm 1 graph pre-view
///
void AnalyzeDialog::drawA1(){

    // each assignment<average completion time, average mark, rate>

    QBarSet *set0 = new QBarSet("AvgCompTime");
    QBarSet *set1 = new QBarSet("AvgGrade");
    QBarSet *set2 = new QBarSet("DifficultyRate");

    int count = 0;
    for(int i = 0; i < graph1.size(); i++){
        for(int j = 0; j < graph1[i].size(); j++){
            if(count % 3 == 0){
                *set0 << graph1[i][j];
            }
            else if(count % 3 == 1){
                *set1 << graph1[i][j];
            }
            else if(count % 3 == 2){
                *set2 << graph1[i][j];
            }

            count += 1;
        }
    }

    QBarSeries *series = new QBarSeries();
    series -> append(set0);
    series -> append(set1);
    series -> append(set2);

    QChart *chart = new QChart();
    chart -> addSeries(series);
    chart -> setTitle("Assignment Difficulty");
    chart -> setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Assignment1" << "Assignment2" << "Assignment3" << "Assignment4";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis -> append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->resize(361,261);
    chartView -> setParent(ui->widget);
    ui->button_1->raise();

}

///
///Drawer for algorithm 3 graph pre-view
///
void AnalyzeDialog::drawA2(){



    QLineSeries *series = new QLineSeries();

    for(int i = 0; i < Qgraph2.size(); i++){
        series -> append(i,Qgraph2[i]);
    }

    QChart *chart = new QChart();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Student Efficience Rate");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(361,261);
    chartView -> setParent(ui->widget_2);
    ui->button_2->raise();
}

///
///Drawer for algorithm 4 graph pre-view
///
void AnalyzeDialog::drawA3(){

    QBarSet *set0 = new QBarSet("LectureElement");

    *set0 << Qgraph3[0]<< Qgraph3[1]*10<< Qgraph3[2]<< Qgraph3[3]*100;


    QBarSeries *series = new QBarSeries();
    series -> append(set0);


    QChart *chart = new QChart();
    chart -> addSeries(series);
    chart -> setTitle("Lecture Utilization Rate");
    chart -> setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "AvgGrade" << "AvgAttendance" <<"AvgHrs" << "utilRate";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis -> append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->resize(361,261);
    chartView -> setParent(ui->widget_3);
    ui->button_3->raise();



}

///
///Drawer for algorithm 5 graph pre-view
///
void AnalyzeDialog::drawA4(){

    QBarSet *set0 = new QBarSet("QuizAtucalAttended");
    QBarSet *set1 = new QBarSet("QuizExpectAttended");
    QBarSet *set2 = new QBarSet("OfficeHrsAtucalAttended");
    QBarSet *set3 = new QBarSet("OfficeHrsExpectAttended");
    QBarSet *set4 = new QBarSet("LectureAtucalAttended");
    QBarSet *set5 = new QBarSet("LectureExpectAttended");
    QBarSet *set6 = new QBarSet("OverALlAttendRate");
    QBarSet *set7 = new QBarSet("OverALlAttendRateChanged");



    QBarSeries *series = new QBarSeries();
    series -> append(set0);
    series -> append(set1);
    series -> append(set2);
    series -> append(set3);
    series -> append(set4);
    series -> append(set5);
    series -> append(set6);
    series -> append(set7);

    int count = 0;
    for(int i = 0; i < Qgraph4.size(); i++){
        for(int j = 0; j < Qgraph4[i].size(); j++){
            if(count % 8 == 0){
                *set0 << Qgraph4[i][j];
            }
            else if(count % 8 == 1){
                *set1 << Qgraph4[i][j];
            }
            else if(count % 8 == 2){
                *set2 << Qgraph4[i][j];
            }
            else if(count % 8 == 3){
                *set3 << Qgraph4[i][j];
            }
            else if(count % 8 == 4){
                *set4 << Qgraph4[i][j];
            }
            else if(count % 8 == 5){
                *set5 << Qgraph4[i][j];
            }
            else if(count % 8 == 6){
                *set6 << Qgraph4[i][j] * 100;
            }
            else if(count % 8 == 7){
                *set7 << Qgraph4[i][j] * 100;
            }
            count += 1;
        }
    }

    QChart *chart = new QChart();
    chart -> addSeries(series);
    chart -> setTitle("Four Quarts Attendance");
    chart -> setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "FirstQuart" << "SecondQuart" <<"ThirdQuart" << "FourthQuart";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis -> append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->resize(361,261);
    chartView -> setParent(ui->widget_4);
    ui->button_4->raise();

}

///
///Drawer for algorithm 6 graph pre-view
///
void AnalyzeDialog::drawA5(){

    QBarSet *set0 = new QBarSet("HighComment");
    QBarSet *set1 = new QBarSet("OverAllScore");



    *set0 <<Qgraph5[0]<< Qgraph5[2] << Qgraph5[4] << Qgraph5[6];
    *set1 <<Qgraph5[1]<< Qgraph5[3] << Qgraph5[5] << Qgraph5[7];


    QBarSeries *series = new QBarSeries();
    series -> append(set0);
    series -> append(set1);


    QChart *chart = new QChart();
    chart -> addSeries(series);
    chart -> setTitle("Student Feedback About Course");
    chart -> setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "assignmentFeedback" << "assignmentDemonstrate" <<"assignmentClassDesign" <<"assignmentReturn";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis -> append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->resize(361,261);
    chartView -> setParent(ui->widget_5);
    ui->button_5->raise();

}

///
///Drawer for algorithm 7 graph pre-view
///
void AnalyzeDialog::drawA6(){

    QBarSet *set0 = new QBarSet("HighComment");
    QBarSet *set1 = new QBarSet("OverAllScore");



    *set0 <<Qgraph6[0]<< Qgraph6[2] << Qgraph6[4] << Qgraph6[6];
    *set1 <<Qgraph6[1]<< Qgraph6[3] << Qgraph6[5] << Qgraph6[7];


    QBarSeries *series = new QBarSeries();
    series -> append(set0);
    series -> append(set1);


    QChart *chart = new QChart();
    chart -> addSeries(series);
    chart -> setTitle("Student Recommend About Instructor");
    chart -> setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "recommendCourse" << "recommendInstructor" <<"impactfulFromTheCourse" <<"improvements";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis -> append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->resize(361,261);
    chartView -> setParent(ui->widget_6);
    ui->button_6->raise();

}


///
///destructor of the class
///
AnalyzeDialog::~AnalyzeDialog()
{
    delete ui;
}

///
///This is detailed content window trigger for graph1
///
void AnalyzeDialog::on_button_1_clicked()
{


    detailedContentDialog detailedContent(graph1);

    detailedContent.setModal(true);
    detailedContent.exec();


}

///
///This is detailed content window trigger for graph2
///
void AnalyzeDialog::on_button_2_clicked()
{
    detailedcontentdialog2 detailedContent2(Qgraph2);

    detailedContent2.setModal(true);
    detailedContent2.exec();
}

///
///This is detailed content window trigger for graph3
///
void AnalyzeDialog::on_button_3_clicked()
{
    detailedcontentdialog3 detailedContent3(Qgraph3);
    detailedContent3.setModal(true);
    detailedContent3.exec();
}

///
///This is detailed content window trigger for graph4
///
void AnalyzeDialog::on_button_4_clicked()
{
    detailedcontentdialog4 detailedContent4(Qgraph4);
    detailedContent4.setModal(true);
    detailedContent4.exec();

}

///
///This is detailed content window trigger for graph5
///
void AnalyzeDialog::on_button_5_clicked()
{
    detailedcontentdialog5 detailedContent5(Qgraph5);
    detailedContent5.setModal(true);
    detailedContent5.exec();
}

///
///This is detailed content window trigger for graph6
///
void AnalyzeDialog::on_button_6_clicked()
{
    detailedcontentdialog6 detailedContent6(Qgraph6);
    detailedContent6.setModal(true);
    detailedContent6.exec();
}

