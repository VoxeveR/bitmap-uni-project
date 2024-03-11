#ifndef EROZJA_H
#define EROZJA_H

#include "Bitmapa.h"
#include "Przeksztalcenie.h"
#include <queue>

class Erozja : public Przeksztalcenie {
public:
	/*
	* Zamiana pikseli brzegowych na bia³e (operacja Erozji)
	* @param referencja do obiektu Bitmapa
	*/
	void przeksztalc(Bitmapa<bool>& b) {

		std::queue<std::pair<int, int>> q;
		bool czyBrzegowy = false;
		int qSize = 0;

		for (int i = 0; i < b.length(); i++) {
			for (int j = 0; j < b.width(); j++) {
				if (b(i, j) == 1) {

					if (i > 0) {
						if (b(i - 1, j) == 0)
							czyBrzegowy = true;
					}

					if (j > 0) {
						if (b(i, j - 1) == 0)
							czyBrzegowy = true;
					}

					if (i < b.length() - 1) {
						if (b(i + 1, j) == 0)
							czyBrzegowy = true;
					}

					if (j < i < b.length() - 1) {
						if (b(i, j + 1) == 0)
							czyBrzegowy = true;
					}

					if (czyBrzegowy)
						q.push(std::make_pair(i, j));

					czyBrzegowy = false;
				}
			}
		}

		qSize = q.size();

		for (int i = 0; i < qSize; i++) {
			b(q.front().first, q.front().second) = 0;
			q.pop();
		}


	}
};

#endif