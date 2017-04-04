// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//Made By Callum Buchanan
//
//IMPRTANT LIBRARY GOODIES

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#define NOMINMAX		//this allows max() function to be used while windows.h is included
#include <windows.h>
#include <string>
#include <algorithm>
#include <vector> 
#include <cstdlib>		//for exit();
#include <sstream>
#include <limits>
#include <windows.media.h>		//libraries for music
#pragma comment (lib, "winmm.lib")		//librarires for music

using namespace std;

void ShowMenu()			//Menu display contents
{
	cout << " ____________________________________________ " << endl;
	cout << "/___________________________________________/|" << endl;
	cout << "|				            ||" << endl;
	cout << "|				            ||" << endl;
	cout << "| ----Press 1 for questions and answers---- ||" << endl;
	cout << "| ------Press 2 to seach for a word-------- ||" << endl;
	cout << "| ----------Press 3 to sort array---------- ||" << endl;
	cout << "| -------Press 4 to copy binary file------- ||" << endl;
	cout << "| --Press 5 for binary search of an array-- ||" << endl;
	cout << "| ---Press 6 to create questions object---- ||" << endl;
	cout << "| ------Press 7 to change background------- ||" << endl;
	cout << "| ------Press 8 to access calculator------- ||" << endl;
	cout << "| ---------Press 9 to play music----------- ||" << endl;
	cout << "| ---------Press 10 to stop music---------- ||" << endl;
	cout << "| -------------Press 11 to exit-------------||" << endl;
	cout << "|				            ||" << endl;
	cout << "|___________________________________________|/" << endl;
	cout << "" << endl;
}


int myfunction(int* i, int* j)		//pointers for 2d array sort
{ 
	return (*i>*j); 
}

class QuestionObject {
public:
	string questions;
	string answers;
};
bool quit = false;

int main()
{
	string line;
	bool found;
	while (!quit)		//if quit bool is not false run through the menu options
	{
		quit = false; //set quit to false 
		int loop;
		ShowMenu();		//initialize menu options display
		cout << "Please enter a number:";
		cin >> loop;	//user input for switch decleration

		if (cin.fail())		//if user input is incorrect
		{
			cin.clear();	//clear user input
			cin.ignore(cin.rdbuf()->in_avail());	//ignores user input
			cout << "Incorrect input!" << endl;
			bool quit = false;	//set quit bool to false and loop back to menu options
		}
		else
		{
			switch (loop)	//switch the main functions of the program
			{
			case 1:
			{
				ifstream myFile("questions.txt");		//open file	
				cout << "hi" << endl;
				if (!myFile)		// Prints an error if file is unable to be opened
				{
					cerr << "Text file could not be opened for reading!" << endl;
				}

				if (myFile.is_open())		//displays questions.text line by line
				{
					while (getline(myFile, line))		//loop displays every line of the file while it is open
					{
						cout << "" << '\n';
						cout << line << '\n';
						cout << "" << '\n';
					}
				}
				myFile.close();			//close file
			}
			break;

			case 2:		//Searches for a word inside question.txt based on user inputs and displays every line that contains the word//
			{
				ifstream myFile("questions.txt");		//open file
				cout << "" << endl;
				cout << "Enter a word:" << endl;
				string word;
				cin >> word;
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				while (myFile)
				{
					std::string strInput;
					getline(myFile, strInput);

					if (strInput.find(word) != std::string::npos)		// searches lines from a file and then prints
					{
						std::cout << "" << endl;
						std::cout << strInput << endl;
						std::cout << "" << endl;
					}
					else
					{
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
					}
				}
				myFile.close();			//close file
			}
			break;

			case 3:		//Sorts 2d array
			{
				cout << endl;
				int arr2[4][2];			//initialize 2d array
				int i, j;

				for (i = 0; i < 4; i++)			//nested for loops generate random numbers for 2d array
				{
					for (j = 0; j < 2; j++)
					{
						arr2[i][j] = rand() % 10;
					}
				}

				cout << "This is a 2D array: " << endl;
				cout << endl;

				for (i = 0; i < 4; i++)		//outputs 2d array
				{
					for (j = 0; j < 2; j++)
					{
						cout << arr2[i][j] << "\t";
					}
					cout << endl;
					cout << "" << endl;
				}

				cout << endl;
				qsort((void*)arr2, 8, sizeof(int), (int(*)(const void*, const void*))myfunction);	//qsort 2d array	
				cout << "Sorted 2d array: " << endl;
				cout << endl;

				for (i = 0; i < 4; i++)			//for-loop  displays sorted array contents
				{
					for (j = 0; j < 2; j++)
					{
						cout << arr2[i][j] << "\t";
					}
					cout << endl;
					cout << "" << endl;
				}

				cout << endl;
			}
			break;

			case 4:		//Read and Write binary file using random access algorithm//
			{
				streampos size;
				char * memblock;
				ifstream file("in.bin", ios::in | ios::binary | ios::ate);		//Reads and opens "in.bin" file

				if (file.is_open())
				{
					size = file.tellg();
					memblock = new char[size];
					file.seekg(0, ios::beg);
					file.read(memblock, size);		//assigns bin file to memory block
					cout << "" << endl;
					cout << "The bin file has been copied to memory" << endl;
					cout << "" << endl;
					ofstream myFile("out.bin", ios::out | ios::binary | ios::ate);		//writes a new file: "out.bin"
					myFile.write(memblock, size);	//writes stored data to "out.bin"
					file.close();					//closes file
					cout << "The bin file has been copied and written to a new bin file" << endl;
					cout << "" << endl;
				}
				else
				{
					cout << "Unable to open file" << endl;
				}
				delete[] memblock;					//clears memblock to prevent memory leak
			}
			break;

			case 5:									//Binary search sorted array
			{
				int arr1[] = { 8,9,3,4,5,32,7,11,1 };
				sort(begin(arr1), end(arr1));		//sort array
				int ind;

				for (ind = 0; ind < 9; ind++)		//output sorted array
				{
					cout << arr1[ind] << "\t";
				}

				int user_i;
				vector<int> vector(arr1, arr1 + 9);		//convert array to vector
				sort(vector.begin(), vector.end());		//sort vector
				cout << "" << endl;
				cout << "Enter a number to search: " << endl;
				cin >> user_i;
				found = binary_search(vector.begin(), vector.end(), user_i); //set bool to search instance

				if (found)	 //if search is successful
				{
					cout << "Found " << user_i << endl;
				}
				else		 //ignore input and clears input variable
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Did not find!" << endl;
				}
			}
			break;

			case 6:
			{
				QuestionObject object1;
				string qArr[20];
				ifstream myFile("questions.txt");

				for (int i = 0; i < 20; i++)	//array for text-file-object intergration
				{
					getline(myFile, qArr[i]);
				}

				object1.questions = qArr[0];
				object1.answers = qArr[1];
				string test = object1.questions;
				string test2 = object1.answers;
				cout << "Question object created" << endl;
				cout << test << endl;
				cout << test2 << endl;
			}
			break;

			case 7:		//change background color
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
			}
			break;

			case 8: //Calculator
			{
				double num1;
				double num2;
				double ans;
				string calculation;

				cout << "Enter a number" << endl;
				cin >> num1;
				if (cin.fail())		//Catch input error
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Not a number" << endl;
					break;
				}

				cout << "Enter second number" << endl;
				cin >> num2;
				if (cin.fail())		//Catch input error
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Not a number" << endl;
					break;
				}

				cout << "Enter operator" << endl;
				cin >> calculation;
				cout << "" << endl;

				if (calculation == "+")
				{
					ans = num1 + num2;
					cout << num1 << " + " << num2 << " = " << ans << endl;
				}

				else if (calculation == "-")
				{
					ans = num1 - num2;
					cout << num1 << " - " << num2 << " = " << ans << endl;
				}

				else if (calculation == "/")
				{
					if (num2 == 0)
					{
						cout << "Can't divide by zero" << endl;
					}
					else
					{
						ans = num1 / num2;
						cout << num1 << " / " << num2 << " = " << ans << endl;
					}
				}

				else if (calculation == "*")
				{
					ans = num1 * num2;
					cout << num1 << " x " << num2 << " = " << ans << endl;
				}
				else
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Not an operator" << endl;	
				}
			}
			break;

			case 9: 
			{
				PlaySound(TEXT("APM_Adobe_Going Home_v3.wav"), NULL, SND_LOOP | SND_ASYNC);		//Play and loop music
				cout << endl;
				cout << "Music playing" << endl;
			}
			break;

			case 10:
			{
				PlaySound(NULL, 0, 0); //stop music
				cout << endl;
				cout << "Music stopped" << endl;
			}
			break;

			case 11:
			{
				quit = true;
				exit(0);
			}
			break;
			}
		}
	}
	return 0;
}				//end of main


