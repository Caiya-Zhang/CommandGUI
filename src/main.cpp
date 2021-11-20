/**-----------------------
* CS3307 Individual Assignment
* 
* Author: Caiya Zhang
* Student No.: 251111335
* Date: Oct 3rd, 2021
* Description: code file containing the main function
*
* Reference: https://wiki.qt.io/How_to_Use_QPushButton
-------------------------*/

#include "mainwindow.h"

/**
	Function name: main
	Description: call and create main window
	Params: no input in command line is needed
	Return: execute commandGUI
*/
int main(int argc, char *argv[]){

  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();
  return app.exec();
  
}


