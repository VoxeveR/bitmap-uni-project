#ifndef BITMAPA_H
#define BITMAPA_H

// Klasa abstrakcyjna reprezentuj¹ca bitmapê
template<typename typeA>
class Bitmapa
{
public:
	/*
	* Zwraca d³ugoœæ (liczbê wierszy) bitmapy.
	* @return D³ugoœæ bitmapy.
	*/
	virtual unsigned length() const = 0;
	/*
	* Zwraca szerokoœæ (liczbê kolumn) bitmapy.
	* @return Szerokoœæ bitmapy.
	*/
	virtual unsigned width() const = 0;
	/*
	* Pozwala na dostêp do elementu bitmapy w okreœlonym miejscu.
	* @param x Wspó³rzêdna x (kolumna) elementu.
	* @param y Wspó³rzêdna y (wiersz) elementu.
	* @return Referencja do elementu bitmapy w okreœlonym miejscu.
	 */
	virtual typeA& operator() (unsigned x, unsigned y) = 0;
	/*
	* Pozwala na odczytanie elementu bitmapy w okreœlonym miejscu.
	* @param x Wspó³rzêdna x (kolumna) elementu.
	* @param y Wspó³rzêdna y (wiersz) elementu.
	* @return Kopiê elementu bitmapy w okreœlonym miejscu.
	*/
	virtual typeA operator() (unsigned x, unsigned y) const = 0;
	/*
	* Wirtualny destruktor klasy abstrakcyjnej Bitmapa.
	* Zapewnia poprawne zwolnienie pamiêci przy usuwaniu obiektów pochodnych.
	*/
	virtual ~Bitmapa() {}
};

#endif