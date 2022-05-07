

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include <QStringListModel>
#include <QPrinter>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    report = new LimeReport::ReportEngine(this);
    QString strKey("admin/");
    settings = new QSettings("/home/client112/Documents/mbr/Querybuilder_sendGeneratorRep/config.ini",QSettings::IniFormat);

        QMessageBox info;
        m_db = QSqlDatabase::addDatabase("QPSQL","PostgresConnection");
        m_db.setHostName(settings->value(strKey + "Hostname", "r").toString());
        m_db.setDatabaseName(settings->value(strKey + "DataBaseName", "r").toString());
        m_db.setUserName(settings->value(strKey + "UserName", "r").toString());
        m_db.setPassword(settings->value(strKey + "Password", "r").toString());
        if (!m_db.open()){
            info.setIcon(QMessageBox::Critical);
            info.setWindowTitle("Error");
            info.setText("file can't be less than 600 bytes!");
            info.exec();
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
      name_dialogl = new Dialog_name();
      name_dialogl->show();
      /// run disigner
      if (name_dialogl->exec()){
          QString path ="/home/client112/test.sql";
          QMessageBox info;
          QFile file(path);
          if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
              info.setIcon(QMessageBox::Critical);
              info.setWindowTitle("Error");
              info.setText("file can't be less than 600 bytes!");
              info.exec();
             return;
            }
          QTextStream in(&file);
         QString str= in .readAll();
         QSqlQueryModel* customersModel = new QSqlQueryModel();
         customersModel->setQuery(str, m_db);
         report->dataManager()->addModel(name_dialogl->name,customersModel,true);
         report->loadFromFile(":/FORM.lrxml");
         report->designReport();
      }
}
