#include "Bitmapa.h"
#include "BitmapaExt.h"
#include "Dylatacja.h"
#include "Erozja.h"
#include "Exceptions.h"
#include "Inwersja.h"
#include "Przeksztalcenie.h"
#include "Usrednianie.h"
#include "Zerowanie.h"
#include "ZlozeniePrzeksztalcen.h"
#include <exception>

int main() {	
	try {
		BitmapaExt<bool> aa(5, 5);
		aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;
		std::cout << aa << "\n"; Usrednianie u;
		Dylatacja d;
		ZlozeniePrzeksztalcen z; z.dodajPrzeksztalcenie(&u); z.dodajPrzeksztalcenie(&d);
		z.przeksztalc(aa);
		std::cout << aa << "\n";

		//Wymaga programu otwieraj¹cego pliki w formacie ppm, np. Gimp
		//Wprowadzenie 0 daje mo¿liwoœæ wy³¹czenia automatycznego otwierania pliku ppm (windows only)
		aa.generujPlik("result"/*,0*/);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
		system("PAUSE");
		exit(0);
	}

	return 0;
}