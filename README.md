# CommandGUI

The **CommandGUI** is a simple graphical command executor, which is based on a Unix-like environment.


## Environment

It's better to start with Linux or a virtualized machine that can get Linux up and running. Also, C++ compiler tools, Boost, and Qt 5 are required to compile and run.

## Files

- **Source code files:** main.cpp, command.cpp, and mainwindow.cpp
- **Header files:** command.h and mainwindow.h
- **Project file:** CommandGUI.pro

## Compile and Run

- **Compile:** You can use `qmake`, and then `make` to get build files, and then run by typing `./CommandGUI`;
- **Run:** You can type a command like `ls`, `date`, `pwd`, etc. Then, you can click the **"execute"** button or just press your **Enter key** to execute your command. History executed command will be listed in "History: " box, and you can doubleclicked any of the record to see what the command was and what the corresponding result was.

