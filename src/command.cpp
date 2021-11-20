/**-----------------------
* CS3307 Individual Assignment
* 
* Author: Caiya Zhang
* Student No.: 251111335
* Date: Oct 3rd, 2021
* Description: code file for class "command"
*
* Reference: https://www.boost.org/doc/libs/1_65_1/doc/html/process.html
-------------------------*/

#include "command.h"


/**
	Function name: command
	Description: initialize all member data, and assign them default data
	Params@m_text: usually be the inpput command
*/
command::command(std::string m_text){
    text = m_text;
    result = "";
    return_code = 0;
}


/**
	Function name: ~command
	Description: destructor function
*/
command::~command(){
    //delete useless text, result, return_code;
}


/**
	Function name: get_text
	Description: get and store text string
	Params: NULL
	Return: text
*/
std::string command::get_text(){
    return text;
}


/**
	Function name: get_result
	Description: get and store result string
	Params: NULL
	Return: result
*/
std::string command::get_result(){
    return result;
}


/**
	Function name: get_return_code
	Description: get and store return code number(0, 1, or -1)
	Params: NULL
	Return: return_code
*/
int command::get_return_code(){
    return return_code;
}


/**
	Function name: set_text
	Description: set input command as command::text string
	Params: m_text
	Return: NULL
*/
void command::set_text(std::string m_text){
    text = m_text;

}


/**
	Function name: set_text
	Description: classify valid and invalid command, execute the command, and store return code
	Params: NULL
	Return: NULL
*/
void command::execute(){
    try{
        //valid command
        //start a program with Boost.Process
        boost::process::ipstream pipe_stream;
        boost::process::child c(text, (boost::process::std_out & boost::process::std_err) > pipe_stream);
	
        std::string line;

        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()){
            result += line + "\n";
        }
        c.wait();
        return_code = c.exit_code();
        
    }catch(const boost::process::process_error& exeException){
        //invalid command
        result = exeException.what();
        return_code = -1;
    }
}
