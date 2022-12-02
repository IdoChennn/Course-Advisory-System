#include "detailedcontentdialog4.h"
#include "ui_detailedcontentdialog4.h"

///
/// \param graph4 the vector that contains all the required data
detailedcontentdialog4::detailedcontentdialog4(QVector<QVector<float>> Qgraph4,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedcontentdialog4)
{
    ui->setupUi(this);
    this->Qgraph4 = Qgraph4;
    drawA1();
    graphResult();
}

detailedcontentdialog4::~detailedcontentdialog4()
{
    delete ui;
}

///
/// The same as Analyzedialog drawA4 method
void detailedcontentdialog4::drawA1(){

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
    chartView->resize(1041,811);
    chartView -> setParent(ui->graph);
}

///
/// To dynamic represent graph by using words
void detailedcontentdialog4::graphResult(){
    QString final = "Detailed Status:\n";
    QString printable1 = "";
    ui->Result->setText(final);
    int count = 0;
    for(int i = 0; i < Qgraph4.size(); i++){
        final += "Quart" +QString::number(i+1)+ "detailed information: \n";
        for(int j = 0; j < Qgraph4[i].size(); j++){
            if(count % 8 == 0){
                printable1 = "Quiz Atucal Attended: "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 1){
                printable1 = "Quiz Expect Attended: "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 2){
                printable1 = "Office Hours Atucal Attended: "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 3){
                printable1 = "Office Hours Expected Attended: "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 4){
                printable1 = "Lecture Atucal Attended: "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 5){
                printable1 = "Lecture Expected Attended: "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 6){
                printable1 = "OverALl Attend Rate : "+QString::number(Qgraph4[i][j])+"\n";
            }
            else if(count % 8 == 7){
                printable1 = "OverALl Attend Rate Changed: "+QString::number(Qgraph4[i][j])+"\n";
            }
            count += 1;
            final += printable1;
        }

    }
    ui->Result->setText(final);
}
