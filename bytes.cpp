//takes a .txt file as input
//counts the number of bytes in it

#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char* argv[]) { //argc is number of cmd line args and argc is array of pointer containing the args
	if (argc != 2) {
		std::cerr << argv[0] << " test.txt" << "\n";
		return 1;
	}
	std::string filename = argv[1];
	std::ifstream file(filename, std::ios::binary);

	if (!file.is_open()) {
		std::cerr << "erro" << "\n";
		return 1;
	}

	file.seekg(0, std::ios::end);
	int bytes = file.tellg();
	file.close();

	std::cout << "Bytes count for the file is : "<<bytes << std::endl;
	return 0;
}