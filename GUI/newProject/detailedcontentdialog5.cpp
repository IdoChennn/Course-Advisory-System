#include "detailedcontentdialog5.h"
#include "ui_detailedcontentdialog5.h"


///
/// \param graph5 the vector that contains all the required data
detailedcontentdialog5::detailedcontentdialog5(QVector<float> Qgraph5,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedcontentdialog5)
{
    ui->setupUi(this);
    this->Qgraph5 = Qgraph5;
    drawA1();
    graphResult();
}

detailedcontentdialog5::~detailedcontentdialog5()
{
    delete ui;
}

///
/// The same as Analyzedialog drawA5 method
void detailedcontentdialog5::drawA1(){
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
    chartView->resize(601,481);
    chartView -> setParent(ui->graph);

}

///
/// To dynamic represent graph by using words
void detailedcontentdialog5::graphResult(){
    QString final = "\nDetailed Status:\n";
    QString printable1 = "Assignment Feedback comment's number of hign comment is " + QString::number(Qgraph5[0]) + "\n"
            + "Assignment Feedback comment's average score is " + QString::number(Qgraph5[1]) + "out of 5\n"
            + "Assignment Demonstrate comment's number of hign comment is " + QString::number(Qgraph5[2]) + "\n"
            + "Assignment Demonstrate comment's average score is " + QString::number(Qgraph5[3]) + "out of 5\n"
            + "Assignment ClassDesign comment's number of hign comment is " + QString::number(Qgraph5[4]) + "\n"
            + "Assignment ClassDesign comment's average score is " + QString::number(Qgraph5[5]) + "out of 5\n"
            + "Assignment Return comment's number of hign comment is " + QString::number(Qgraph5[6]) + "\n"
            + "Assignment Return comment's average score is " + QString::number(Qgraph5[7]) + "out of 5\n";
    final += printable1;
    ui->Result->setText(final);
}
