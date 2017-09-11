#include "stdafx.h" //if using visualStudio, Pre-Compiled headerfile option is not used. 
using namespace std;
void start_menu();    //function to display a welcome message and existing commands
void get_syntax(int); //function to provide the syntax of existing commands
int main()
{	
	//Adding a welcome screen when picoCLI starts
	//the function is called start_menu()
	start_menu();
	cmdEngine *engine = new cmdEngine;
	engine->start_cmdEngine(); //starts the command Line Engine
	delete engine;
	return 0;
}
void start_menu()
{	
	int ch = 0;
	cout << "\n picoCLI v2.0" << endl;

	cout << "\n About : picoCLI is a simple Command Line Interpreter" << endl;

	cout << "\n The following commands are currently supported" << endl;

	cout << "\n 1. read - Read from a previously generated file" << endl;
	cout << " 2. write - Create a new file or append an existing file" << endl;
	cout << " 3. do - Schedule a command to be executed later" << endl;
	cout << " 4. -q - Quit picoCLI" << endl;

	cout << "\n To get the syntax of any command enter (1-4)";
	cout << "\n By default Command Engine will be initialized" << endl;

	cout << "\n Enter your choice : "; cin >> ch;

	do
	{
		switch(ch)
		{
			case 1:	get_syntax(1);
					break;

			case 2:	get_syntax(2);
					break;

			case 3:	get_syntax(3);
					break;

			case 4:	get_syntax(4);
					break;
		}
		cout << "\n Enter your choice : "; cin >> ch;
	}while(ch >= 1 && ch <= 4);
}
void get_syntax(int ch)
{
	if(ch == 1)
	{
		cout << "\n Syntax : read file [filename.txt]" << endl;

		cout << "\n Example : read file [readme.txt]" << endl;

		cout << "\n readme.txt's content will be displayed on the console" << endl;
	}
	else if(ch == 2)
	{
		cout << "\n Syntax : write file [filename.txt] <user input here>" << endl;

		cout << "\n Example : write file [readme.txt] <This is a readme file>" << endl;

		cout << "\n \"This is a readme file\" will be appended to readme.txt" << endl;
		cout << " If the file doesn't exists a new file will be created" << endl;

		cout << "\n NOTE : <user input here> parameter is optional" << endl;
	}
	else if(ch == 3)
	{
		cout << "\n Syntax : do [any valid command here] <time in seconds>" << endl;

		cout << "\n Example : do [read file [readme.txt]] <30>" << endl;

		cout << "\n readme.txt file will be read after 30 seconds" << endl;

		cout << "\n NOTE : This command can be nested" << endl;

		cout << "\n Example : do [do [ read file [readme.txt]] <10>] <20>" << endl;
	}
	else
	{
		cout << "\n Syntax : -q" << endl;

		cout << "\n Example : -q" << endl;

		cout << "\n Quit picoCLI" << endl;
	}
}