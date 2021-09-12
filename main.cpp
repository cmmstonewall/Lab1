#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[])
{
		TodoList mylist;
		TodoListInterface*list = &mylist;

		for(int i = 0; i < argc; i++) 
		{
				cout << "argv["<<i<<"]=" << argv[i] << endl;
		}

		if(argc < 2) 
		{
			list->printTodoList();
			return  0;
		}
		
		string firstarg = argv[1];

		if(firstarg =="add")
		{
			cout << "Doing an add" << endl;
			string date = argv[2];
			string task = argv[3];
			cout << "date " <<date<< " task " << task << endl;
			list->add(date, task);
		}

		else if(firstarg == "remove")
		{ 
			cout << "Removing" << endl;
			string task = argv[2];
			cout <<"task " << task << endl;
			bool removed = list->remove(task);
			cout << removed << endl;
		}

		else if(firstarg == "printList")
		{ 
			cout << "Printing List" << endl;
			list->printTodoList();
		}

		else if(firstarg == "printDay")
		{ 
			cout << "Printing " << endl;
			string date = argv[2];
			cout <<"date " << date << endl;
			list->printDaysTasks(date);
		}	

		else
		{
			cout << "Unrecognized Command: " << firstarg << endl;
		}

		list = nullptr;
		return 0;
}