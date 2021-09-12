#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
		vector <string> tasks;
		TodoList() {
				cout << "In Constructor" << endl;
				ifstream infile ("TODOList.txt");
				string line;
				if (infile.is_open())
				{
						while ( getline (infile,line) )
						{
							cout << line << '\n';
							tasks.push_back(line);
						}
						infile.close();
				}
		}
		virtual ~TodoList() {
				cout << "In Destructor" << endl;
				ofstream outfile;
				outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
				for (int i = 0; i < tasks.size(); i++){
					cout << tasks[i] << '\n';
					outfile << tasks[i] << endl;
				} 
				outfile.close();
		}
		 
		virtual void add(string _duedate, string _task)
		{
				cout << "In add " << _duedate << " " << _task << endl;
				tasks.push_back(_duedate+" "+_task);
		}
		
		 /*    
		 *   Removes an item from the todo list with the specified task name    
		 *    
		 *   Returns 1 if it removes an item, 0 otherwise    */    
		virtual int remove(string _task)
		{
				cout << "In remove ";
				int i=0, len = _task.length();
				stack <int> remove;

				for(string itask:tasks){
					//Find the _task in itask instance
					int pos = itask.find(_task);
					// check for _task is at the end of itask
					if(pos != string::npos && pos + len == itask.length()){
					remove.push(i);		
					}
					++i;
				}

				if(remove.size() == 0) return 0;
				while(remove.size()){
					tasks.erase(tasks.begin()+remove.top());
					remove.pop();
				}
				return 1;
								
		}

		/*    
		*   Prints out the full todo list to the console    
		*/    
		virtual void printTodoList()
		{
				cout << "In list" << endl;
				for(string task:tasks){
					cout << task << endl;
				}
		}    
		/*    
		*   Prints out all items of a todo list with a particular due date (specified by _duedate)    
		*/    
		virtual void printDaysTasks(string _date)
		{
				cout << "In daytasks" << endl;
				for(string task:tasks){
					//Find the _task in itask instance
					int pos = task.find(_date+" ");
					// check for _task is at the end of itask
					if(pos == 0){
					cout << task << endl;		
					}
				}				
		}
		
		};
		
		#endif