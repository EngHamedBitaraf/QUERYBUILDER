
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <LimeReport>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSettings>

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

private:
    Ui::MainWindow *ui;
    ///object Limereport
    LimeReport::ReportEngine *report;
    QSqlDatabase m_db;
    QSettings *settings;
};
#endif // MAINWINDOW_H
