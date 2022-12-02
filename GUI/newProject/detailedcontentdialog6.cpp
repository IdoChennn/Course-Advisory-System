#include "detailedcontentdialog6.h"
#include "ui_detailedcontentdialog6.h"

///
/// \param graph6 the vector that contains all the required data
detailedcontentdialog6::detailedcontentdialog6(QVector<float> Qgraph6, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedcontentdialog6)
{
    ui->setupUi(this);
    this->Qgraph6 = Qgraph6;
    drawA1();
    graphResult();

}

detailedcontentdialog6::~detailedcontentdialog6()
{
    delete ui;
}

///
/// The same as Analyzedialog drawA6 method
void detailedcontentdialog6::drawA1(){
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
    chartView->resize(601,481);
    chartView -> setParent(ui->graph);
}

///
/// To dynamic represent graph by using words
void detailedcontentdialog6::graphResult(){
    QString final = "\nDetailed Status:\n";
    QString printable1 = "Recommend Course comment's number of hign comment is " + QString::number(Qgraph6[0]) + "\n"
            + "Recommend Course comment's average score is " + QString::number(Qgraph6[1]) + "out of 5\n"
            + "Recommend Instructor comment's number of hign comment is " + QString::number(Qgraph6[2]) + "\n"
            + "Recommend Instructor comment's average score is " + QString::number(Qgraph6[3]) + "out of 5\n"
            + "Impactful From The Course comment's number of hign comment is " + QString::number(Qgraph6[4]) + "\n"
            + "Impactful From The Course comment's average score is " + QString::number(Qgraph6[5]) + "out of 5\n"
            + "Improvements comment's number of hign comment is " + QString::number(Qgraph6[6]) + "\n"
            + "Improvements comment's average score is " + QString::number(Qgraph6[7]) + "out of 5\n";
    final += printable1;
    ui->Result->setText(final);
}
