#ifndef DETAILEDCONTENTDIALOG_H
#define DETAILEDCONTENTDIALOG_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QDialog>

namespace Ui {
class detailedContentDialog;
}

class detailedContentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit detailedContentDialog(QVector<QVector<float>> graph1,QWidget *parent = nullptr);
    Ui::detailedContentDialog *ui;
    ~detailedContentDialog();

    void drawA1();
    void graphResult();

private:
    QVector<QVector<float>> graph1;
};

#endif // DETAILEDCONTENTDIALOG_H
