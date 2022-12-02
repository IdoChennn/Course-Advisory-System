#ifndef DETAILEDCONTENTDIALOG3_H
#define DETAILEDCONTENTDIALOG3_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QVector>

namespace Ui {
class detailedcontentdialog3;
}

class detailedcontentdialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit detailedcontentdialog3(QVector<float> Qgraph3,QWidget *parent = nullptr);
    ~detailedcontentdialog3();
    void drawA1();
    void graphResult();

private:
    Ui::detailedcontentdialog3 *ui;
    QVector<float> Qgraph3;
};

#endif // DETAILEDCONTENTDIALOG3_H
