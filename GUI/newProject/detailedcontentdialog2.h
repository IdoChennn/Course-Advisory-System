#ifndef DETAILEDCONTENTDIALOG2_H
#define DETAILEDCONTENTDIALOG2_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QDialog>


namespace Ui {
class detailedcontentdialog2;
}

class detailedcontentdialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit detailedcontentdialog2(QVector<float> Qgraph2, QWidget *parent = nullptr);
    ~detailedcontentdialog2();
    void drawA1();
    void graphResult();

private:
    Ui::detailedcontentdialog2 *ui;
    QVector<float> Qgraph2;

};

#endif // DETAILEDCONTENTDIALOG2_H
