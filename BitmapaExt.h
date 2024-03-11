#ifndef BITMAPAEXT_H
#define BITMAPAEXT_H

#include "Bitmapa.h"
#include <fstream>
#include <exception>
#include "libArray.h"
#include "libFile.h"
#include "Exceptions.h"

template<typename typeA>
class BitmapaExt : public Bitmapa<typeA>
{
private:
	unsigned int wid;
	unsigned int len;
	typeA** map;
public:
	BitmapaExt(unsigned int l = 0, unsigned int w = 0) : len(l), wid(w) {

		try {
			map = f_create_2d_array<typeA>(len, wid);
		}
		catch (std::exception& e) {
			std::cerr << e.what();
			system("PAUSE");
			exit(0);
		}

		f_fill_with_zero<typeA>(map, len, wid);
	}
	
	~BitmapaExt() {
		for (int i = 0; i < this->len; i++)
			delete[] map[i];

		delete[] map;
	};

	/*
	* Zwraca d³ugoœæ tablicy
	*/
	unsigned length() const {
		return len;
	}

	/*
	* Zwraca szerokoœæ tablicy
	*/
	unsigned width() const {
		return wid;
	}

	/*
	* Przeci¹¿enie operatora nawiasów - zwraca element tablicy o podanych indeksach
	* @param numer wiersza, numer kolumny
	*/
	typeA& operator() (unsigned x, unsigned y) {
		if (x < this->len and y < this->wid)
			return map[x][y];

		throw BitmapExceptions::BitmapInvalidArgument("Argument out of range");
		//system("PAUSE");
		//exit(0);
	}

	/*
	* Przeci¹¿enie operatora nawiasów - zwraca element tablicy o podanych indeksach
	* @param numer wiersza, numer kolumny
	*/
	typeA operator() (unsigned x, unsigned y) const {
		if (x < this->len and y < this->wid)
			return map[x][y];

		throw BitmapExceptions::BitmapInvalidArgument("Argument out of range");
		//system("PAUSE");
		//exit(0);
	}

	/*
	* Generuje plik bitmapy w formacie *.ppm
	* @param œcie¿ka do pliku, zgoda na automatyczne otwarcie pliku (domyœlnie: true)
	*/
	void generujPlik(std::string path, bool autoOpen = true) {
		path = f_check_file_name(path, ".ppm");
		std::fstream img;
		try{
			img = f_open_file(path, 'w', ".ppm");
		}catch(std::exception& e){
			std::cerr << e.what();
			system("PAUSE");
			exit(0);
		}
		
		int r = 0, g = 0, b = 0;

		img << "P3" << std::endl;
		img << this->wid << " " << this->len << std::endl;
		img << "255" << std::endl;

		for (int x = 0; x < this->len; x++) {
			for (int y = 0; y < this->wid; y++) {
				if (this->map[x][y]) r = g = b = 0;
				else r = g = b = 255;
				
				img << r << " " << g << " " << b;
				img << "\t";
			}
			img << std::endl;
		}

		img.close();

		if (autoOpen) {
			std::string command = "start " + path;
			system(command.c_str());
		}
	}

	/*
	* Funkcja zaprzyjaŸniona - przeci¹¿enie operatora <<
	* @param strumieñ wyjœciowy, referencja do obiektu BitmapaExt
	*/
	template<typename typeA>
	friend std::ostream& operator <<(std::ostream& s, const BitmapaExt<typeA>& b);
	
};

template<typename typeA>
std::ostream& operator <<(std::ostream& s, const BitmapaExt<typeA>& b)
{
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < b.width(); j++) {
			s << b(i, j) << " ";
		}
		s << std::endl;
	}
	return s;
}

#endif