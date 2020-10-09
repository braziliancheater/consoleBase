// simple base for your clicker or client on cpp / based on a console application

// first things first i dont recommend using a terminal as a cheat, its ugly and hard to use
// i recommend going thru imgui examples! it should not be that hard. and its easy to implement smht there.

// includes to make the program function
#include <Windows.h>
#include <iostream>

// our header
#include "main.hpp"
// and the xor header
#include "xor.hpp"

int main()
{
    // this changes the console window to our random string variable
    SetConsoleTitleA(random_string(10).c_str());

    // this should ensure that the user cant pause our terminal when selecting text
    void* hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(hConsoleOutput, ENABLE_EXTENDED_FLAGS);

	// simple checker to see if minecraft is open before continuing.
	// LWJGL should be 90% of all minecraft classes, you can take a look at process hacker if this didnt work.
	
	// if you get errors here run = RELEASE | x64
	while (!FindWindow(xor ("LWJGL"), nullptr))
	{
		logo();
		printf("\n");
		printf("	minecraft process was not found\n");
		printf("	exiting");
		Sleep(3000);
		exit(-1);
		// if minecraft is not found it will display that message and exit with code -1
	}

	// makes the color of the console 15 see http://winapi.freetechsecrets.com/win32/WIN32SetConsoleTextAttribute.htm for a list of colors!
	SetConsoleTextAttribute(hConsoleOutput, 15);
	
	// this calls for our logo variable at our header
	logo();

	// this will run the "deleteExe" void at our header. which is inside of a while, so its constantly running.
	// the "deleteExe" will run on as long as the program is open, so we can use it to click, look in memory and much more.
	// in this example i will use it to selfdelete the program.
	deleteExe();

}
// if you are making a clicker pls dont use post/send message or shit like that, its detectable af and its shit.