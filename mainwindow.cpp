

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QStringListModel>
#include <QPrinter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    report = new LimeReport::ReportEngine(this);
        QString strKey("admin/");
        settings = new QSettings("/home/client112/Documents/mbr/Querybuilder_sendGeneratorRep/config.ini",QSettings::IniFormat);


            m_db = QSqlDatabase::addDatabase("QPSQL","DBconnection");
            m_db.setHostName(settings->value(strKey + "Hostname", "r").toString());
            m_db.setDatabaseName(settings->value(strKey + "DataBaseName", "r").toString());
            m_db.setUserName(settings->value(strKey + "UserName", "r").toString());
            m_db.setPassword(settings->value(strKey + "Password", "r").toString());
            if (!m_db.open()){
                QMessageBox ::information(this,"No Database","Not Cannect Databease");
                return;
            }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ///run pgadmin
      QString program = "java"; //"/home/client112/Desktop/launchpgadmin.sh";//"/home/client112/DbVisualizer/dbvisgui.sh";
      QStringList argoman;
      argoman<<"-jar";
      argoman<<"/home/client112/Documents/mbr/Querybuilder_sendGeneratorRep/SQLeoVQB.2019.01.rc1/SQLeoVQB.jar";
      QProcess * myprocess = new QProcess(qApp);
      myprocess ->execute(program,argoman);
      myprocess->waitForFinished();
      ///end
      /// run disigner
      QFile file ("/home/client112/test.sql");

      if(!file.open(QIODevice::ReadOnly)){

            QMessageBox ::information(this,"No Database",file.errorString());
      }
      QTextStream in(&file);
     QString str= in .readAll();
     QSqlQueryModel* customersModel = new QSqlQueryModel();
     customersModel->setQuery(str, m_db);
     report->dataManager()->addModel("Test",customersModel,true);
     //report->loadFromFile(":/change_item_from_script.lrxml");
     report->designReport();
}
