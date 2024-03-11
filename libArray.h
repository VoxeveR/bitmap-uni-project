#ifndef LIBARRAY_H
#define LIBARRAY_H

#include <iostream>

/*
* Function creating an array
* @param array of values, row size, column size
* @return dynamically allocated one-dimensional array
*/
template<typename type>
inline type** f_create_2d_array(unsigned int rows, unsigned int columns) {
	type** arr;

	try {
		arr = new type * [rows];
		for (unsigned int i = 0; i < rows; i++) {
			arr[i] = new type [columns];
		}
	}
	catch (std::bad_alloc) {
		std::cerr << "Array cannot be created" << std::endl;
		std::cin.ignore();
		exit(0);
	}

	return arr;
}

/*
* Function creating an array
* @param array of values, size of the array
* @return dynamically allocated one-dimensional array
*/
template<typename type>
inline type* f_create_array(type* arr, unsigned int n) {

	try {
		arr = new type[n];
	}
	catch (std::bad_alloc) {
		std::cerr << "Array cannot be created" << std::endl;
		std::cin.ignore();
		exit(0);
	}
	return arr;
}

/*
* Function for displaying a dynamically allocated one-dimensional array
* @param array of values, size of the array, separator
*/
template<typename T>
inline void print_array(T* arr, unsigned int rows, std::string seprarator=" ") {
	for (int i = 0; i < rows; i++) {
		std::cout << arr[i] << seprarator;
	}
	std::cout << std::endl;
}

/*
* Function for displaying a dynamically allocated one-dimensional array
* @param array of values, size of the array, separator
*/
template<typename T>
inline void print_array(T** arr, unsigned int rows, unsigned int cols, std::string seprarator = " ") {
	for (int i = 0; i < rows; i++) {
		for (int j=0; j<cols; j++){
			std::cout << arr[i][j] << seprarator;
		}
		std::cout << std::endl;
	}
}

/*
* Function for copying a dynamically allocated one-dimensional array
* @param source array, destination array, size of the array
*/
template<typename type>
inline void f_copy_array(type* arr, type* newArr, unsigned int newCol) {
	for (int i = 0; i < newCol; i++) {
		newArr[i] = arr[i];
	}
}

/*
* Function for filling 2d array with value zero
* @param empty array, row size, column size
*/
template<typename type>
inline void f_fill_with_zero(type** arr, unsigned int rows, unsigned int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = 0;
		}
	}
}

#endif