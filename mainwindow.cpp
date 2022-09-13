#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <Qfile>
#include <fstream>
#include <QTextStream>
#include <string>
#include <QDateTime>
#include <QtCharts>
#include<QtCharts/QChart>
#include<QtCharts/QChartView>
#include<QtCharts/QLineSeries>
#include<QtCharts/QValueAxis>


#include "lifter.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix ("C:/Users/chris/Desktop/Programming/SummerProjects/GUIworkoutlog2/dumbell.png");
    ui->logoLabel1->setPixmap(pix);
    displayUserRoutine();

    recordHistory();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//general tab push button. allows user to select their function
void MainWindow::on_pushButton_clicked()
{
  userSelectFunction();

}


//if index is changed to a search function, set the textedit to read only.
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    string userEx = ui->exerciseInput->text().toStdString();
    string userWeight = ui->setInput->text().toStdString();

    if(index == 2){
        ui->setInput->setText("");
        ui->setInput->setReadOnly(true);
    }
    else if(index == 3){
        ui->setInput->setReadOnly(true);
        ui->setInput->setText("");
    }
    else{
        ui->setInput->setReadOnly(false);
    }
}

//TODO:
void MainWindow::userSelectFunction(){
    Lifter p;

    string userEx = ui->exerciseInput->text().toStdString();
    string userSets = ui->setInput->text().toStdString();

    //If selected to index 0, take users inputs and call "enterExercise" function.
    if (ui->comboBox->currentIndex() == 0){

        p.enterExercise(userEx, userSets);

        ui->outputEdit->setPlainText(ui->exerciseInput->text());
        ui->outputEdit->append("has been added.");
        ui->outputEdit->append("\n");
        ui->outputEdit->append(ui->setInput->text());
        ui->outputEdit->append("Sets x Reps.");

    }

    //If selected index 1, take user date, call "enterRecord" function and display info.
    if (ui->comboBox->currentIndex() == 1){

        p.enterRecord(userEx,userSets);


        ui->outputEdit->setPlainText(ui->exerciseInput->text());
        ui->outputEdit->append("PR Added.");
        ui->outputEdit->append("\n");
        ui->outputEdit->append(ui->setInput->text());
        ui->outputEdit->append("LBS");
        ui->outputEdit->append("\n");

        //using QDateTime to display the time of entered record.
        QDateTime aTime = QDateTime::currentDateTime();
        QString bTime = aTime.toString("MM.dd.yyyy");

        ui->outputEdit->append(bTime);
    }

    //If selected index 2, take user information and call "searchEx" function and display
    if (ui->comboBox->currentIndex() == 2){
        //creating a QString variable that turns a std::string result from searchEx() into a QString
        QString searchResults = QString::fromStdString(p.searchEx(userEx));
        ui->outputEdit->setPlainText("Sets Required:");
        ui->outputEdit->append(searchResults);

    }

    if (ui->comboBox->currentIndex() == 3){
        //creating a QString variable that turns an integer result from searchRecord() into a QString
        QString searchResults = QString::number(p.searchRecord(userEx));
        ui->outputEdit->setPlainText("Your Record:");
        ui->outputEdit->append(searchResults);
        ui->outputEdit->append("LBS");

    }

}

//iterating through routine txt file and displaying on textEdit.
void MainWindow::displayUserRoutine(){
   ui->routineEdit->setPlainText("Your Routine:");
   ui->routineEdit->append("");
   QFile inFile("testroutine.txt");
   if(!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
       qDebug() << "Failed to open file:" << inFile.fileName() << "Error:" << inFile.errorString();

   QTextStream in(&inFile);
   while(!in.atEnd()){
       QString line = in.readLine();

       ui->routineEdit->append(line);
   }

   inFile.close();
}

//iterating through record txt file and displaying all results of past records
void MainWindow::recordHistory(){
    ui->recordEdit->setPlainText("Your Records:");
    ui->recordEdit->append("");
    QFile inFile1("liftrecords.txt");
    if(!inFile1.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Failed to open file:" << inFile1.fileName() << "Error:" << inFile1.errorString();

    QTextStream in(&inFile1);
    while(!in.atEnd()){
        QString line = in.readLine();

        ui->recordEdit->append(line);
    }

    inFile1.close();
}

//fix chart display full
//Iterate through records txt file (x)
//Use Parse function to find each instance of searched ex.
//find record value and convert to an integer.
//find date of record
//append both values to the chart
void MainWindow::displayPrChart(string ex){
      QLineSeries *series = new QLineSeries();

      ifstream fin;
      string data;
      int recordValues = 0;
      int recordTime = 0;

      vector<string> parseEx = parseString(ex); //parse function to parse users search if larger 1 word
      fin.open("liftrecords.txt");

      if (fin.good()){

          //iterating through records txt file
          while (getline(fin, data)){
              vector<string> tokens = parseString(data); //parsing the contents of each line in file
              for (string::size_type i = 0; i < tokens.size(); i++) {
                  if ((tokens[i] == ex) && (tokens.size() > 1)) {
                      recordValues = stoi(tokens[i + 2]); //turning record value into an integer
                      recordTime = stoi(tokens[i + 7]);  //turning time value into an integer from txt file
                      series->append(recordValues, recordTime); //appending these values onto the visual chart


                  }
                  else if (tokens.size() > 2) {  //search for any token above 1 token (ex. tricep extensions)
                      for (string::size_type h = 0; i < parseEx.size(); i++) { //nested loop to compare search ex and actual exs
                          if ((tokens[i] == parseEx[h]) && (tokens[i + 1] == parseEx[h + 1]) && (tokens.size() > 2)) { //if user search is > 1 word and matches txt
                              recordValues = stoi(tokens[i + 3]);  //turning record value into an integer
                              recordTime = stoi(tokens[i + 8]);    //turning time value into an integer from txt file
                              series->append(recordValues, recordTime);  //appending these values onto the visual chart

                          }


                      }
                  }
              }
          }

      }


      //creating chart and setting it inside horizontal
      QChart *chart = new QChart();
      chart->legend()->hide();
      chart->addSeries(series);
      chart->createDefaultAxes();
      chart->setTitle("Progression Chart");



      QFont font;
      font.setPixelSize(18);
      chart->setTitleFont(font);

      QPen pen(QRgb(0x000000));
      pen.setWidth(5);
      series->setPen(pen);
      chart->setAnimationOptions(QChart::AllAnimations);

      QChartView *chartView = new QChartView(chart);
      chartView->setRenderHint(QPainter::Antialiasing);
      chartView->setParent(ui->frame);

      QVBoxLayout *layout = new QVBoxLayout(ui->frame);
      layout->addWidget(chartView);

      fin.close();


}






//When users searches chart progression, button will call chart function
void MainWindow::on_chartButton_clicked()
{
    string chartSearch = (ui->chartInput->text()).toStdString();
    displayPrChart(chartSearch);
}

