#ifndef ZLOZENIEPRZEKSZTALCEN_H
#define ZLOZENIEPRZEKSZTALCEN_H

#include "Bitmapa.h"
#include "Przeksztalcenie.h"
#include <queue>

class ZlozeniePrzeksztalcen : public Przeksztalcenie {
private:
	std::queue<Przeksztalcenie*> transformacje;
public:

	/*
	* Wykonanie przekszta³ceñ na obiekcie bitmapy
	* @param referencja do obiektu klasy Bitmapa
	*/
	void przeksztalc(Bitmapa<bool>& b) {
		int tSize = transformacje.size();
		for (int i = 0; i < tSize; i++) {
			transformacje.front()->przeksztalc(b);
			transformacje.pop();
		}
	}

	/*
	* Dodanie przekszta³cenia do kolejki
	* @param wskaŸnik do obiektu klasy Przekszta³cenie
	*/
	void dodajPrzeksztalcenie(Przeksztalcenie* p) {
		transformacje.push(p);
	}
};

#endif