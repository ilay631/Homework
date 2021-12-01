#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = std::filesystem;


string getCom(string raw_com) {
	string com("");
	for (int i = 0; i < raw_com.length(); i++) {
		if (raw_com[i] == ' ')
			break;
		com += raw_com[i];
	}
	return com;
}


string getName(string raw_com) {
	string name("");
	bool isSpace = false;
	for (int i = 0; i < raw_com.length(); i++) {
		if (raw_com[i] == ' ')
			isSpace = true;
		else if (isSpace)
			name += raw_com[i];
	}
	return name;
}


void showHelp() {
	cout << "h / help - information about commands" << endl;
	cout << "q / quit - completion of work" << endl;
	cout << "cd - change path" << endl;
	cout << "dir - show all directories" << endl;
	cout << "sf <name> - show all files" << endl;
	cout << "crd <name> - create new directory" << endl;
	cout << "dd <name> - delete specified directory" << endl;
	cout << "cf <name> - create new file" << endl;
	cout << "df <name> - delete specified file" << endl;
	cout << "of <name> - show specified file" << endl;
	cout << endl;
}


void changePath(fs::path *curPath, string newPath) {
	if (fs::exists(newPath) && fs::is_directory(newPath))
		*curPath = fs::path(newPath);
}


void showDirs(string _path) {
	fs::directory_iterator begin(_path);
	fs::directory_iterator end;
	for (; begin != end; ++begin) {
		if (begin->is_directory())
			cout << begin->path() << endl;
	}
	cout << endl;
}


void showFiles(string _path) {
	fs::directory_iterator begin(_path);
	fs::directory_iterator end;
	for (; begin != end; ++begin) {
		if (begin->is_regular_file())
			cout << begin->path() << endl;
	}
	cout << endl;
}


void createNewDir(fs::path _path, string name) {
	if (name.find_first_of("/\\:*?\"<>|") == -1)
		fs::create_directory(_path / name);
}


void deleteDir(fs::path _path, string name) {
	fs::remove_all(_path / name);
}


void createNewFile(fs::path _path, string name) {
	_path /= name;
	ofstream out(_path.generic_string());
	out.close();
}


void deleteFile(fs::path _path, string name) {
	_path /= name;
	if (name != "")
		remove(_path.generic_string().c_str());
}


void openFile(fs::path _path, string name) {
	_path /= name;
	ifstream in(_path.generic_string());
	if (in)
		cout << in.rdbuf();
}


int main() {
	fs::path curPath = fs::current_path();

	bool isWorking = true;
	string raw_com;
	while (isWorking) {
		cout << curPath.generic_string() << endl;
		getline(cin, raw_com);
		string command = getCom(raw_com);
		string name = getName(raw_com);

		if (command == "q" || command == "quit")
			isWorking = false;
		else if (command == "h" || command == "help")
			showHelp();
		else if (command == "cd")
			changePath(&curPath, name);
		else if (command == "dir")
			showDirs(curPath.generic_string());
		else if (command == "sf")
			showFiles(curPath.generic_string());
		else if (command == "crd")
			createNewDir(curPath, name);
		else if (command == "dd")
			deleteDir(curPath, name);
		else if (command == "cf")
			createNewFile(curPath, name);
		else if (command == "df")
			deleteFile(curPath, name);
		else if (command == "of")
			openFile(curPath, name);
	}
	
	return 0;
}