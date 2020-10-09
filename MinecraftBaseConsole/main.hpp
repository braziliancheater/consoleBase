#pragma once
// our header! 

#include <string>
#include <random>
#include <tchar.h>
#include <strsafe.h>

// special thanks to stackOverflow for this one
std::string random_string(const int len) {
	// our alpha numeric string
	const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}
	// this should return our random string
	// which we use as a windowtittle!
	// you can use this for many other things tho
	return str;
}

// this is super unnecessary but looks cool i guess? you can remove this if you want
void logo() {
	printf("\n\n");
	printf("	 _                   _ _ _             \n");
	printf("	| |__  _ __ __ _ ___(_) (_) __ _ _ __  \n");
	printf("	| '_ \\| '__/ _` |_  / | | |/ _` | '_ \\ \n");
	printf("	| |_) | | | (_| |/ /| | | | (_| | | | |\n");
	printf("	|_.__/|_|  \\__,_/___|_|_|_|\\__,_|_| |_|\n");
	printf("\n");
}

// straight from stackOverflow
// this just defines a cmd command in this case to autoDelete itself
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

// our void which handles the call.
void dele()
{
	TCHAR szModuleName[MAX_PATH];
	TCHAR szCmd[2 * MAX_PATH];
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	GetModuleFileName(NULL, szModuleName, MAX_PATH);

	StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);

	CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}

// the void we called at our main.cpp
void deleteExe()
{
	// first thing it prints this text to make the user aware.
	// its outside the while loop so it doesnt repeat itself forever.
	printf(" press 'DELETE' to selfdestruct");

	// we start our loop
	while (true) {
		// if the delete key gets pressed.
		if (GetAsyncKeyState(VK_DELETE)) {
			// execute the dele() void up there ^^
			dele();
			// and then exit the console application
			exit(0);
		}
	}
}