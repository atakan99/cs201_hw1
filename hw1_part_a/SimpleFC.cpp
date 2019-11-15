
#include "SimpleFC.h"


FC::FC()
{
	
	size = 0;
	noOfFilms = 0;
	films = new Film[size];
}

FC::FC(const FC& fcToCopy) 
{
	(*this).size = fcToCopy.size;
	noOfFilms = fcToCopy.noOfFilms;
	if ((*this).size > 0) {
		films = new Film[size];
		for (int i = 0; i <this->size; i++) {
			cout << "a";
			this->films[i] = fcToCopy.films[i];
		}
	}
	else {
		films = NULL;
	}
}

FC::~FC()
{
	if (films) {
		delete[] films;
	}
}

void FC::operator=(const FC& right)
{
	noOfFilms = right.noOfFilms;
	if (&right != this) {
		if (size != right.size) {
			delete [] films;
		}
		size = right.size;
		if (size > 0) {
			films = new Film[size];
		}
		else {
			films = NULL;
		}
	}
	for (int i = 0; i < size; i++) {
		films[i] = right.films[i];
	}
}

bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
{
	Film* film = new Film(fTitle, fDirector, fYear, fDuration);
	for (int i = 0; i < size; i++)
	{
		if (this->films[i].getTitle() == fTitle && this->films[i].getDirector() == fDirector){
			return false;
		}
	}
	int oldSize = size;
	size++;
	noOfFilms++;
	Film* temp = new Film[oldSize];
	for (int i = 0; i < oldSize; i++) {
		temp[i] = films[i];
	}
	delete[] films;
	films = new Film[size];
	for (int i = 0; i< oldSize; i++) {
		films[i] = temp[i];
	}
	films[oldSize] = *film;
	delete[] temp;
	delete film;
	return true;	
}

bool FC::removeFilm(const string fTitle, const string fDirector)
{
	for (int i = 0; i < size; i++) {
		if (films[i].getTitle() == fTitle && films[i].getDirector() == fDirector) {
			//films[i].~Film();

			Film* temp = new Film[size - 1];
			for (int j = i; j < size - 1; j++) {
				temp[j] = films[j + 1];
			}
			for (int j = 0; j < i; j++) {
				temp[j] = films[j];
			}
			delete[] films;
			size--;
			noOfFilms--;
			films = new Film[size];
			for (int j = 0; j < size; j++) {
				films[j] = temp[j];
			}
			delete[] temp;
			return true;
		}
	}

	return false;
}

unsigned int FC::getFilms(Film*& allFilms) const
{
	allFilms = new Film[size];
	for (int i = 0; i < size; i++) {
		allFilms[i] = films[i];
	}
	return noOfFilms;
}
