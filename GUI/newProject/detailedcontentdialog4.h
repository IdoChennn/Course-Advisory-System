#ifndef DETAILEDCONTENTDIALOG4_H
#define DETAILEDCONTENTDIALOG4_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QVector>

namespace Ui {
class detailedcontentdialog4;
}

class detailedcontentdialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit detailedcontentdialog4(QVector<QVector<float>> Qgraph4,QWidget *parent = nullptr);
    ~detailedcontentdialog4();
    void drawA1();
    void graphResult();

private:
    Ui::detailedcontentdialog4 *ui;
    QVector<QVector<float>> Qgraph4;

};

#endif // DETAILEDCONTENTDIALOG4_H
