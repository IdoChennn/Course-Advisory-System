#ifndef DETAILEDCONTENTDIALOG6_H
#define DETAILEDCONTENTDIALOG6_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QDialog>

namespace Ui {
class detailedcontentdialog6;
}

class detailedcontentdialog6 : public QDialog
{
    Q_OBJECT

public:
    explicit detailedcontentdialog6(QVector<float> Qgraph6,QWidget *parent = nullptr);
    ~detailedcontentdialog6();
    void drawA1();
    void graphResult();

private:
    Ui::detailedcontentdialog6 *ui;
    QVector<float> Qgraph6;
};

#endif // DETAILEDCONTENTDIALOG6_H
