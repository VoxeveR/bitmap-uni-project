#ifndef ZEROWANIE_H
#define ZEROWANIE_H

#include "Bitmapa.h"
#include "Przeksztalcenie.h"

class Zerowanie : public Przeksztalcenie {
public:
	/*
	* Zamiana wszystkich elementów bitmapy na kolor bia³y (0) (operacja Zerowania)
	* @param referencja do obiektu Bitmapa
	*/
	void przeksztalc(Bitmapa<bool>& b) {
		for (int i = 0; i < b.length(); i++) {
			for (int j = 0; j < b.width(); j++) {
				b(i, j) = 0;
			}
		}
	}
};

#endif