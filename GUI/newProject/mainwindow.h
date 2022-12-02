#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QApplication>
///
///This is the home window of the program. It loads input file and transform data stored in input file into graph readable data
///@brief home window
///@author Ido Chen
///@author Yanwen Wang
///
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

    Ui::MainWindow *ui;
public:

    explicit MainWindow(QWidget *parent = nullptr);


//    void setFlag(QString flag);
//    QString getFlag();
    ~MainWindow();

private slots:

    void on_fileOpen_triggered();

//    void on_pushButton_clicked();

    void on_actionrefresh_file_triggered();

    void on_startAnalyzebut_clicked();



private:

};
#endif // MAINWINDOW_H
