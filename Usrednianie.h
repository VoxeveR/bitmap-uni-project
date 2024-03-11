#ifndef USREDNIANIE_H
#define USREDNIANIE_H

#include "Bitmapa.h"
#include "Przeksztalcenie.h"

class Usrednianie : public Przeksztalcenie {
public:
	/*
	* Usrednianie bitmapy (zamiana koloru kazdego piksela w zaleznosci od s¹siadów)
	* @param referencja do obiektu Bitmapa
	*/
	void przeksztalc(Bitmapa<bool>& b) {
		std::queue<std::pair<int, int>> q;
		int qSize = 0, numOfElem = 0;

		for (int i = 0; i < b.length(); i++) {
			for (int j = 0; j < b.width(); j++) {
				if (i > 0) {
					if (b(i - 1, j) == !b(i, j))
						numOfElem++;
				}

				if (j > 0) {
					if (b(i, j - 1) == !b(i, j))
						numOfElem++;
				}

				if (i < b.length() - 1) {
					if (b(i + 1, j) == !b(i, j))
						numOfElem++;
				}

				if (j < i < b.length() - 1) {
					if (b(i, j + 1) == !b(i, j))
						numOfElem++;
				}

				if (numOfElem > 2)
					q.push(std::make_pair(i, j));

				numOfElem = 0;
			}
		}

		qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			b(q.front().first, q.front().second) = !b(q.front().first, q.front().second);
			q.pop();
		}
	}
};

#endif