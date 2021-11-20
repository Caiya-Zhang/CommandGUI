/**-----------------------
* CS3307 Individual Assignment
* 
* Author: Caiya Zhang
* Student No.: 251111335
* Date: Oct 3rd, 2021
* Description: header file for class "mainwindow"
*
* Reference: https://wiki.qt.io/How_to_Use_QPushButton
-------------------------*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "command.h"
#include <QFrame>
#include <QLabel>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QListWidgetItem>




/**
* CLass name: mainwindow
* member_functions@handleButton: execute input command and display output
*                 @handleHistory: re-show selected history record
* member_variable@history_vector: store history records
* member_widgets@mainwindow: include labels, text edits, line edits, push buttons and list widgets
*/ 
class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private slots:
        void handleButton();
        void handleHistory();

    private:
    	//variable and widgets declaration
        QPushButton *execute_button;
        QLineEdit *line_edit;
        QLabel *command_label;
        
        QGridLayout *layout;
        
        QTextEdit *output_edit;
        QLabel *output_label;
        
        QLabel *exit_code;
        
        QListWidget *history_list;
        QLabel *history_label;
        QListWidgetItem *history_item;
        std::vector<command*> history_vector;
        
        QFrame *line;
        
};

#endif //MAINWINDOW_H
