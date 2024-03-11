#ifndef DYLATACJA_H
#define DYLATACJA_H

#include "Bitmapa.h"
#include "Przeksztalcenie.h"
#include <queue>

class Dylatacja : public Przeksztalcenie {
public:
	/*
	* Zamiana kolorów bitmapy (operacja Dylatacji)
	* @param referencja do obiektu Bitmapa
	*/
	void przeksztalc(Bitmapa<bool>& b) {
		std::queue<std::pair<int, int>> q;
		int qSize = 0;

		for (int i = 0; i < b.length(); i++) {
			for (int j = 0; j < b.width(); j++) {
				if (b(i, j) == 0) {

					if (i > 0) {
						if (b(i - 1, j) == 1) {
							q.push(std::make_pair(i, j));
							continue;
						}
					}

					if (j > 0) {
						if (b(i, j - 1) == 1) {
							q.push(std::make_pair(i, j));
							continue;
						}
					}

					if (i < b.length() - 1) {
						if (b(i + 1, j) == 1) {
							q.push(std::make_pair(i, j));
							continue;
						}
					}

					if (j < b.length() - 1) {
						if (b(i, j + 1) == 1) {
							q.push(std::make_pair(i, j));
						}
					}
				}
			}
		}

		qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			b(q.front().first, q.front().second) = 1;
			q.pop();
		}
	}
};

#endif