#include "detailedcontentdialog.h"
#include "ui_detailedcontentdialog.h"
#include "analyzedialog.h"
#include "mainwindow.h"
#include <QDebug>

///
/// \param graph1 the vector that contains all the required data
detailedContentDialog::detailedContentDialog(QVector<QVector<float>> graph1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedContentDialog)
{
    ui->setupUi(this);
    this->graph1 = graph1;
    drawA1();
    graphResult();


}

///
/// To dynamic represent graph by using words
void detailedContentDialog::graphResult(){
    QString final = "\nDetailed Status:\n";
    int count = 0;
    for(int i = 0; i < graph1.size(); i++){
        for(int j = 0; j < graph1[i].size(); j++){
            QString convertNumber = QString::number(i+1);
            QString convertfloat = QString::number(graph1[i][j]);
            QString printable;
            if(count % 3 == 0){
                 printable = "The Assignment "+ convertNumber + "average completion time is " + convertfloat + "\n";
            }
            else if(count % 3 == 1){
                printable = "The Assignment " + convertNumber + " average grade is " + convertfloat + "\n";
            }
            else if(count % 3 == 2){
                printable = "The Assignment " + convertNumber + " difficulty rate is " + convertfloat + "\n";
            }

            //ui->Result->setText(printable);
            final = final + printable;
            count += 1;
        }
    }
     ui->Result->setText(final);
}

///
/// The same as Analyzedialog drawA1 method
void detailedContentDialog::drawA1(){

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
    chartView->resize(601,481);
    chartView -> setParent(ui->graph);




}


detailedContentDialog::~detailedContentDialog()
{
    delete ui;
}

