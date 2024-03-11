#ifndef LIBFILE_H
#define LIBFILE_H

#include <iostream>
#include <fstream>
#include <queue>
#include "Exceptions.h"

/*
* Check if file name has its type
* @param file path, file type (default: *.txt)
* @return correct file path
*/
std::string f_check_file_name(std::string file, std::string temp=".txt") {
	if (file.length() <= temp.length()) {
		file += temp;
	}
	else {
		if (file.find(temp) == -1) {
			file += temp;
		}
	}
	return file;
}

/*
* Create a new file if it doesn't exist
* @param file path, file type (default: *.txt)
*/
void f_create_file(std::string path, std::string temp = ".txt") {
	path = f_check_file_name(path, temp);
	std::ifstream fileR(path.c_str(), std::ios::in);
	if (!fileR) {
		std::ofstream fileW(path.c_str(), std::ios::out);
		fileW.close();
	}
	else {
		std::cout << "File " << path << " already exists" << std::endl;
		fileR.close();
	}
}

/*
* Open file
* @param file path, open mode, file type (default: *.txt)
* @return opened file
*/
std::fstream f_open_file(std::string path, char mode, std::string temp = ".txt") {
	path = f_check_file_name(path,temp);
	//std::ios_base::openmode flags = std::ios_base::in;
	std::ios_base::openmode flags;

	switch (mode) {
	case 'r':
		flags = std::ios_base::in;
		break;
	case 'w':
		flags = std::ios_base::out;
		break;
	case 'a':
		flags = std::ios_base::app;
		break;
	default:
		throw FileExceptions::FileInvalidArgument("Invalid file open mode");
	}


	std::fstream file(path.c_str(), flags);

	if (!file.good()) {
		throw FileExceptions::FileRuntimeError("Cannot open the file");
	}

	return file;
}

/*
* Write to file using 1d array
* @param opened file, 1d array, number of columns, separator (optionally)
*/
template<typename type>
inline void f_write_to_file(std::fstream& writeFile, type arr[], unsigned int sizeCol, std::string ending = " ") {
	for (int j = 0; j < sizeCol; j++) {
		writeFile << arr[j] << ending;
	}

	writeFile << std::endl << std::endl;
}

/*
* Write to file using 2d array
* @param opened file, 2d array, number of columns
*/
template<typename type>
inline void f_write_to_file(std::fstream& writeFile, type** arr, unsigned int sizeRow, unsigned int sizeCol) {
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeCol; j++){
			writeFile << arr[i][j] << " ";
		}
		writeFile << std::endl;
	}

	writeFile << std::endl << std::endl;
}

#endif