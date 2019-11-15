#include "FC.h"

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
		for (int i = 0; i < this->size; i++) {
			
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
			delete[] films;
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
	Film * film = new Film(fTitle, fDirector, fYear, fDuration);
	for (int i = 0; i < size; i++)
	{
		if (this->films[i].getFilmTitle() == fTitle && this->films[i].getFilmDirector() == fDirector) {
			return false;
		}
	}
	int oldSize = size;
	this->size = this->size + 1;
	noOfFilms = noOfFilms + 1;
	Film* temp = new Film[oldSize];
	for (int i = 0; i < oldSize; i++) {
		temp[i] = films[i];
	}
	delete[] films;
	films = new Film[size];
	for (int i = 0; i < oldSize; i++) {
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
		if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector) {
			//deleting actors

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

bool FC::addActor(const string fTitle, const string fDirector, const string aName, const string aBirthPlace, const unsigned int aBirthYear)
{
	for (int i = 0; i < size; i++) {
		//
		
		if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector)
		{
			Actor newActor(aName, aBirthPlace, aBirthYear);
			
			return films[i].addFilmActor(newActor);

		}

	}		
	//
			
			return false;
		
	
}

bool FC::removeActors(const string fTitle, const string fDirector)
{
	for (int i = 0; i < size; i++) {
		if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector) {
			return films[i].removeFilmActors(fTitle, fDirector);
		}
	}
	return false;
}

unsigned int FC::calculateAverageDuration() const
{
	unsigned int sum = 0;
	if (films) {
		for (int i = 0; i < size; i++)
		{
			sum += films[i].getFilmDuration();
		}
		return sum / size;
	}
	else {
		return 0;
	}
	
}
