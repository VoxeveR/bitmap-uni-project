#ifndef INWERSJA_H
#define INWERSJA_H

#include "Bitmapa.h"
#include "Przeksztalcenie.h"

class Inwersja : public Przeksztalcenie {
public:

	/*
	* Zamiana kolorów bitmapy (operacja Inwersji)
	* @param referencja do obiektu Bitmapa
	*/
	void przeksztalc(Bitmapa<bool>& b) {
		for (int i = 0; i < b.length(); i++) {
			for (int j = 0; j < b.width(); j++) {
				if (b(i, j) == 0) b(i, j) = 1;
				else b(i, j) = 0;
			}
		}
	}
};

#endif