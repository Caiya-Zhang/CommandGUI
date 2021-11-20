/**-----------------------
* CS3307 Individual Assignment
* 
* Author: Caiya Zhang
* Student No.: 251111335
* Date: Oct 3rd, 2021
* Description: header file for class "command"
*
* Reference: https://www.boost.org/doc/libs/1_65_1/doc/html/process.html
-------------------------*/

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <boost/process.hpp>
#include <boost/process/child.hpp>
#include <boost/process/exception.hpp>


/**
* CLass name: command
* member_variables@text: should usually be the input command
*                 @result: should be the output by executing input command
*                 @return_code: should be 0 for valid command, and -1 for invalid command
* member_functions@command: constructor function for this class
*                 @~command: destructor function
*                 @execute: execute inout command and generate output text
*                 @gettters
*                 @setters
*/
class command{
    private: 
    //data members declared as private
        std::string text;
        std::string result;
        int return_code;

    public:
        command(std::string); 
        ~command(); //destructor
        void execute(); 
        
        std::string get_text();
        std::string get_result();
        int get_return_code();
        
        void set_text(std::string);

};


#endif //COMMAND_H

