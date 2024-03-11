#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <fstream>
#include <string>

/*
 * @brief Przestrzeñ nazw FileExceptions zawiera wyj¹tki zwi¹zane z plikami.
 *
 * Przestrzeñ nazw zawiera klasy reprezentuj¹ce wyj¹tki zwi¹zane z operacjami na plikach.
 * Klasa FileInvalidArgument dziedziczy po std::invalid_argument i reprezentuje b³¹d zwi¹zany z nieprawid³owymi argumentami.
 * Klasa FileRuntimeError dziedziczy po std::runtime_error i reprezentuje b³¹d zwi¹zany z czasem wykonania.
 */
namespace FileExceptions {

	class FileInvalidArgument : public std::invalid_argument {
	public:
		FileInvalidArgument(std::string msg) : std::invalid_argument(msg.c_str()) {}
	};

	class FileRuntimeError : public std::runtime_error {
	public:
		FileRuntimeError(std::string msg) : std::runtime_error(msg.c_str()) {}
	};
}

/*
 * @brief Przestrzeñ nazw ArrayExceptions zawiera wyj¹tek zwi¹zany z tablicami.
 *
 * Przestrzeñ nazw zawiera klasê reprezentuj¹c¹ wyj¹tek zwi¹zanego z alokacj¹ pamiêci dla tablicy.
 * Klasa BadAllocError dziedziczy po std::bad_alloc i reprezentuje b³¹d zwi¹zany z nieudan¹ alokacj¹ pamiêci.
 */
namespace ArrayExceptions {
	class BadAllocError : public std::bad_alloc {
	public:
		BadAllocError() : std::bad_alloc() {};
	};
}

/*
 * @brief Przestrzeñ nazw BitmapExceptions zawiera wyj¹tki zwi¹zane z bitmapami.
 *
 * Przestrzeñ nazw zawiera klasy reprezentuj¹ce wyj¹tki zwi¹zane z operacjami na bitmapach.
 * Klasa BitmapRuntimeError dziedziczy po std::runtime_error i reprezentuje b³¹d zwi¹zany z czasem wykonania.
 * Klasa BitmapInvalidArgument dziedziczy po std::invalid_argument i reprezentuje b³¹d zwi¹zany z nieprawid³owymi argumentami.
 */
namespace BitmapExceptions {
	class BitmapRuntimeError : public std::runtime_error {
	public:
		BitmapRuntimeError(std::string msg) : std::runtime_error(msg.c_str()) {}
	};

	class BitmapInvalidArgument : public std::invalid_argument {
	public:
		BitmapInvalidArgument(std::string msg) : std::invalid_argument(msg.c_str()) {}
	};
}

#endif