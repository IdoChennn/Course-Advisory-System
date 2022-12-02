#ifndef ANALYZEDIALOG_H
#define ANALYZEDIALOG_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QVector>

///
///header file for data analyzing window (the one after click start analyze)
///@brief data analyzing window
///@author ido Chen
///@author yanwen Wang
///
namespace Ui {
class AnalyzeDialog;
}

class AnalyzeDialog : public QDialog
{
    Q_OBJECT


public:
    explicit AnalyzeDialog(QVector<QVector<float>> graph1,
                           QVector<float> Qgraph2,
                           QVector<float> Qgraph3,
                           QVector<QVector<float>> Qgraph4,
                           QVector<float> Qgraph5,
                           QVector<float> Qgraph6,
                           QWidget *parent = nullptr);
    ~AnalyzeDialog();
    void drawA1();
    void drawA2();
    void drawA3();
    void drawA4();
    void drawA5();
    void drawA6();
private slots:
    void on_button_1_clicked();



    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();


private:
    Ui::AnalyzeDialog *ui;
    QVector<QVector<float>> graph1;
    QVector<float> Qgraph2;
    QVector<float> Qgraph3;
    QVector<QVector<float>> Qgraph4;
    QVector<float> Qgraph5;
    QVector<float> Qgraph6;

};

#endif // ANALYZEDIALOG_H
