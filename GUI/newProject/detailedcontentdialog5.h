#ifndef DETAILEDCONTENTDIALOG5_H
#define DETAILEDCONTENTDIALOG5_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QDialog>

namespace Ui {
class detailedcontentdialog5;
}

class detailedcontentdialog5 : public QDialog
{
    Q_OBJECT

public:
    explicit detailedcontentdialog5(QVector<float> Qgraph5, QWidget *parent = nullptr);
    ~detailedcontentdialog5();

    void drawA1();
    void graphResult();

private:
    Ui::detailedcontentdialog5 *ui;
    QVector<float> Qgraph5;
};

#endif // DETAILEDCONTENTDIALOG5_H
