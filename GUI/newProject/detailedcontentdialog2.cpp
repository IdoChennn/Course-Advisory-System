#include "detailedcontentdialog2.h"
#include "ui_detailedcontentdialog2.h"

///
/// \param graph2 the vector that contains all the required data
detailedcontentdialog2::detailedcontentdialog2(QVector<float> Qgraph2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedcontentdialog2)
{
    ui->setupUi(this);
    this->Qgraph2 = Qgraph2;
    drawA1();
    graphResult();
}

detailedcontentdialog2::~detailedcontentdialog2()
{
    delete ui;
}

///
/// The same as Analyzedialog drawA2 method
void detailedcontentdialog2::drawA1(){
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
    chartView->resize(601,481);
    chartView -> setParent(ui->graph);

}
///
/// To dynamic represent graph by using words
void detailedcontentdialog2::graphResult(){
    QString final = "\nDetailed Status:\n";
    QString printable = "";
    for(int i = 0; i < Qgraph2.size(); i++){
        printable = "The number of studnet has"+ QString::number(i*10) +" Study Efficience Rate is "+QString::number(Qgraph2[i]) +"\n";
        final += printable;
    }
    ui->Result->setText(final);
}
