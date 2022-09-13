#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QtCharts/QChart>
#include<QtCharts/QChartView>
#include<QtCharts/QLineSeries>
#include<QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_chartButton_clicked();

private:
    Ui::MainWindow *ui;
    void userSelectFunction();
    void displayUserRoutine();
    void recordHistory();
    void displayPrChart(std::string ex);
};

#endif // MAINWINDOW_H
