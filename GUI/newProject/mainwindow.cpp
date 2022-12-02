#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector"
#include <QStringList>
#include "analyzedialog.h"
#include <QDebug>
#include "../../Utility/config.h"

///
///Constructor of the main window class
/// \param window object
///
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui -> comboBox -> addItem("--Select course--");
    ui -> comboBox_2 -> addItem("--Select assignment--");
    ui -> comboBox_3 -> addItem("--Select student--");
    ui ->startAnalyzebut -> setCursor(Qt::PointingHandCursor);



}

///
///destructor of the class
///
MainWindow::~MainWindow()
{
    delete ui;
}




vector<string> years; /*!< filter the input file based on years > */
vector<string> courses; /*!< filter the input file based on course > */
map<string,map<string, CourseMeta>> dataMap; /*!< data container for transformed data for graph > */

//since qt does not accept vector, we need to convert it into qstring list.
QStringList yearsQSL; /*!< filter the input file based on years > */
QStringList coursesQSL; /*!< filter the input file based on course > */
QStringList studentsQSL = {"a-h","i-p","q-z","ALL"}; /*!< data container for transformed data for graph > */

///
///open file browser trigger button
///
void MainWindow::on_fileOpen_triggered()
{

       //refresh file button
    QString filepath = QFileDialog::getOpenFileName(this, "Open a file", "C://");
    string path = filepath.toUtf8().constData();
    FileLoader fileLoader(path);
    dataMap = fileLoader.getData();

    int counter = 0;
    for (auto i = dataMap.begin(); i != dataMap.end(); i++){
        years.push_back(i->first);
        counter += 1;
        for (auto k = i->second.begin(); k != i->second.end(); k++){
            if(courses.size() == 0 || counter <= 1){
                courses.push_back(k->first);
            }
            else{
                break;
            }
        }
    }
    QFile file(filepath);
    QFileInfo fileInfo(file.fileName());
    QString filename(fileInfo.fileName());
    ui ->fileConfirmed->setText(filename);

    qDebug() << filename;

}



///
///Fetch selected data stored in input file
///
void MainWindow::on_actionrefresh_file_triggered()
{

    for(size_t i = 0; i < years.size(); i++){
        yearsQSL.insert(i, QString::fromUtf8(years[i].c_str()));
    }
    for(size_t i = 0; i < courses.size(); i++){
        coursesQSL.insert(i, QString::fromUtf8(courses[i].c_str()));
    }


    ui -> comboBox -> addItems(yearsQSL);
    ui -> comboBox_2 -> addItems(coursesQSL);
    ui -> comboBox_3 -> addItems(studentsQSL);
}

///
///start analyzing button. all algorithm calculation will be done upon click this button
///
void MainWindow::on_startAnalyzebut_clicked()
{   QString comboBoxValue;

    //ui->comboBox ->itemData(ui->comboBox->currentIndex());
    int currentYearIndex = ui->comboBox->currentIndex();
    int currentCourseIndex = ui->comboBox_2->currentIndex();

    CourseMeta courseMeta = dataMap[years[currentYearIndex-1]][courses[currentCourseIndex-1]];
    DataLoader dataLoader(courseMeta);

    vector<vector<float>> graph1 = dataLoader.algorithm1Graph();
    QVector<QVector<float>> Qgraph1;
    for(size_t i = 0; i < graph1.size(); i++){
        QVector<float> temp =  QVector<float>(graph1[i].begin(), graph1[i].end());
        Qgraph1.append(temp);
    }

    vector<int> graph2 = dataLoader.algorithm3Graph();
    QVector<float> Qgraph2 = QVector<float>(graph2.begin(), graph2.end());

    vector<float> graph3 = dataLoader.algorithm4Graph();
    QVector<float> Qgraph3 = QVector<float>(graph3.begin(), graph3.end());

    vector<vector<float>> graph4 = dataLoader.algorithm5Graph();
    QVector<QVector<float>> Qgraph4;
    for(size_t i = 0; i < graph4.size(); i++){
        QVector<float> temp =  QVector<float>(graph4[i].begin(), graph4[i].end());
        Qgraph4.append(temp);
    }

    vector<float> graph5 = dataLoader.algorithm6Graph();
    QVector<float> Qgraph5 = QVector<float>(graph5.begin(), graph5.end());

    vector<float> graph6 = dataLoader.algorithm7Graph();
    QVector<float> Qgraph6 = QVector<float>(graph6.begin(), graph6.end());

    AnalyzeDialog AnalyzeDialogWindow(Qgraph1, Qgraph2, Qgraph3, Qgraph4, Qgraph5, Qgraph6);
    AnalyzeDialogWindow.setModal(true);
    AnalyzeDialogWindow.exec();
}
