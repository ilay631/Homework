#include <iostream>
#include <string>
#include <filesystem>
using namespace std;


struct Command {
	string command;
	string name;

	Command() : command(""), name("") {}
	Command(string _com) : command(_com), name("") {}
};


bool isCommandCorrect(string command) {

}


Command createCommand(string _com) {
	Command newCommand = Command{};

	return newCommand;
}


void showHelp() {

}


void changePath(string* path) {

}


bool isPathCorrect(string path) {

}


void showDirs(string path) {

}


void showFiles(string path) {

}


void createNewDir(string path, string name) {

}


void deleteDir(string path, string name) {

}


void createNewFile(string path, string name) {

}


void deleteFile(string path, string name) {

}


void openFile(string path, string name) {

}


int main() {
	string path;
	cout << "Input path " << endl;
	cin >> path;
	// Проверка на корректность пути

	bool isWorking = true;
	string raw_com;
	while (isWorking) {
		cout << "Enter your command (for help enter h)" << endl;
		cin >> raw_com;
		if (isCommandCorrect(raw_com)) {
			Command com = createCommand(raw_com);
			string command = com.command;
			// Проверка на корректность команды

			if (command == "q" || command == "quit")
				isWorking = false;
			else if (command == "h" || command == "help")
				showHelp();
			else if (command == "cd" || command == "change directory")
				changePath(&path);
			else if (command == "dir" || command == "show directories")
				showDirs(path);
			else if (command == "sf" || command == "show files")
				showFiles(path);
			else if (command == "crd" || command == "create directory")
				createNewDir(path, com.name);
			else if (command == "dd" || command == "delete directory")
				deleteDir(path, com.name);
			else if (command == "cf" || command == "create file")
				createNewFile(path, com.name);
			else if (command == "df" || command == "delete file")
				deleteFile(path, com.name);
			else if (command == "of" || command == "open file")
				openFile(path, com.name);
		}
	}
	
	return 0;
}