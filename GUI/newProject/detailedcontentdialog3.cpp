#include "detailedcontentdialog3.h"
#include "ui_detailedcontentdialog3.h"

///
/// \param graph3 the vector that contains all the required data
detailedcontentdialog3::detailedcontentdialog3(QVector<float> Qgraph3, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedcontentdialog3)
{
    ui->setupUi(this);
    this->Qgraph3 = Qgraph3;
    drawA1();
    graphResult();

}


detailedcontentdialog3::~detailedcontentdialog3()
{
    delete ui;
}

/// The same as Analyzedialog drawA3 method
void detailedcontentdialog3::drawA1(){
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
    chartView->resize(601,481);
    chartView -> setParent(ui->graph3);
}


///
/// To dynamic represent graph by using words
void detailedcontentdialog3::graphResult(){
    QString final = "\nDetailed Status:\n";
    QString printable1 = "Course Average Grade is" + QString::number(Qgraph3[0]) + "\n"
            + "Course Average Attendance is "+QString::number(Qgraph3[1]) + "out of 8\n"
            + "Course Student Average Study Hours is " +QString::number(Qgraph3[2]) + "\n"
            + "Course Lecture Utilization Rate is " + QString::number(Qgraph3[3]);
    final += printable1;
    ui->Result->setText(final);
}
