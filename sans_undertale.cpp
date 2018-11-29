#include <ctime>
#include <fstream>
#include <iostream>

std::string getLine(std::string file, int line);
int lineCount(std::string file);

int main(int argc, char** argv) {
	srand(time(NULL));

	const std::string SANS = "sa.txt";
	const std::string UNDERTALE = "un.txt";

	if (argc != 2) {
		std::cout << "format: [count]" << std::endl;
		exit(1);
	}

	for (int i = 0; i < std::stoi(argv[1]); i++) {
		std::string sansUndertale = "";
		sansUndertale += getLine(SANS, (rand() % lineCount(SANS)) + 1) + " ";
		sansUndertale += getLine(UNDERTALE, (rand() % lineCount(UNDERTALE)) + 1);
		std::cout << sansUndertale << std::endl;
	}
}

std::string getLine(std::string file, int line) {
	std::ifstream fstream(file);
	std::string l;
	for (int i = 0; i < line; i++) {
		std::getline(fstream, l);
	}
	fstream.close();
	return l;
}

int lineCount(std::string file) {
	int lc = 0;

	std::ifstream fstream(file);
	std::string line;

	while (std::getline(fstream, line)) {
		lc++;
	}

	fstream.close();
	return lc;
}