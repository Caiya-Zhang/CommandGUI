/**-----------------------
* CS3307 Individual Assignment
* 
* Author: Caiya Zhang
* Student No.: 251111335
* Date: Oct 3rd, 2021
* Description: code file for class "mainwindow"
*
* Reference: https://wiki.qt.io/How_to_Use_QPushButton
-------------------------*/

#include "mainwindow.h"


/**
	Description: instanciate widget objects,
	             set widget attributes,
	             and add widgets to the window
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    
    //window frame
    setWindowTitle("CommandGUI");
    setWindowFlags(Qt::Dialog);
    setFixedSize(500, 900);
    
    //use grid layout
    layout = new QGridLayout();
    this -> setCentralWidget(new QWidget());
    this -> centralWidget() -> setLayout(layout);
    
    //command box                                        
    command_label = new QLabel("Command: ");
    line_edit = new QLineEdit();
    command_label -> setBuddy(line_edit);
    
    //execute button
    execute_button = new QPushButton("Execute", this); //Create the button, make "this" the parent   
    
    //users can click "execute" button or just press Enter key to execute command
    connect(execute_button, &QPushButton::clicked, this, &MainWindow::handleButton); //Connect button signal to execute function
    connect(line_edit, SIGNAL(returnPressed()), execute_button, SLOT(click()), Qt::UniqueConnection); //Connect button signal to the Enter key
    
    //output box
    output_label = new QLabel("Output: ");
    output_edit = new QTextEdit();
    output_label -> setBuddy(line_edit);
    output_edit -> setReadOnly(true);
    output_edit -> setLineWrapMode(QTextEdit::NoWrap); 

    //exit code
    exit_code = new QLabel("Exit code: ");

    //history box
    history_label = new QLabel("History: ");
    history_list = new QListWidget();
    history_item = new QListWidgetItem();
    history_label -> setBuddy(history_list);
    history_list -> setViewMode(QListView::ListMode);
    
    //users can doubleclicked one history record and see the corresponding output
    //history_list -> setSlectionMode(QAbstractionItemView::SingleSlection);
    connect(history_list, &QListWidget::itemDoubleClicked, this, &MainWindow::handleHistory);//Connect history item to the execute function
    
    //add a split line
    line = new QFrame();
    line -> setFrameShape(QFrame::HLine);

    //add widgets to the window
    layout -> addWidget(command_label, 0, 0);
    layout -> addWidget(line_edit, 0, 1); 
    layout -> addWidget(execute_button, 0, 2);

    layout -> addWidget(output_label, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
    layout -> addWidget(output_edit, 1, 1, 1, 2); //stretch
    
    layout -> addWidget(line, 2, 1, 1, 2);
    
    layout -> addWidget(exit_code, 3, 0);

    layout -> addWidget(history_label, 4, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
    layout -> addWidget(history_list, 4, 1, 1, 2); //stretch
    
    //set spacing
    layout -> setHorizontalSpacing(20);
    layout -> setVerticalSpacing(20);
    layout -> setContentsMargins(20, 25, 30, 30);
}



/**
	Function name: handleButton
	Description: get input command, store it in string type and add it inyo history record;
	             call the execute function, display the result and return code
	Params: NULL
	Return: NULL
*/ 
void MainWindow::handleButton(){
    //set command output
    std::string command_str = line_edit -> text().toStdString();
    command* user_command = new command(command_str);
    user_command -> execute();
    output_edit -> setText(QString::fromStdString(user_command -> get_result()));

    //set exit code
    std::string exit_str = "Exit code: " + std::to_string(user_command -> get_return_code());
    exit_code -> setText(QString::fromStdString(exit_str));
    
    
    //store commands in history list
    	//user_command -> get_text()
    std::string list_str = command_str + "(" + std::to_string(user_command -> get_return_code()) + ")";
    history_list -> addItem(QString::fromStdString(list_str));
    history_vector.push_back(user_command); //add at the end
    
    //int idx = history_list -> currentRow());

}



/**
	Function name: handleHistory
	Description: display selected command and corresponding output
	Params: NULL
	Return: NULL
*/
void MainWindow::handleHistory(){
    //get selected item in history list
    std::string current_str = history_list -> currentItem() -> text().toStdString();
    
    //concatenate exit code
    int cat_pos = current_str.find("(");
    std::string command_str = current_str.substr(0, cat_pos);
    
    //re-execute the command
    command* current_command = new command(command_str);
    current_command -> execute();
    
    //show selected command in the line
    line_edit -> setText(QString::fromStdString(command_str));
    
    //show corresponding output
    output_edit -> setText(QString::fromStdString(current_command -> get_result()));

    //re-set exit code
    std::string exit_str = "Exit code: " + std::to_string(current_command -> get_return_code());
    exit_code -> setText(QString::fromStdString(exit_str));
     
}


 

