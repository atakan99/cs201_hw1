#include "Film.h"


Film::Film(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration)
{
	title = fTitle;
	director = fDirector;
	year = fYear;
	duration = fDuration;
	noOfActors = 0;
	size = 0;
	actors = new Actor[size];
}

Film::Film(const Film& fToCopy)
{
	title = fToCopy.getFilmTitle();
	director = fToCopy.getFilmDirector();
	year = fToCopy.getFilmYear();
	duration = fToCopy.getFilmDuration();
	noOfActors = fToCopy.noOfActors;
	size = fToCopy.size;
	delete[] actors;
	actors = new Actor[size];
	for (int i = 0; i < size; i++) {
		actors[i] = fToCopy.actors[i];
	}
}

Film::~Film()
{
	delete[] actors;
}

void Film::operator=(const Film& right)
{
	title = right.getFilmTitle();
	director = right.getFilmDirector();
	year = right.getFilmYear();
	duration = right.getFilmDuration();
	noOfActors = right.noOfActors;
	size = right.size;
	delete[] actors;
	actors = new Actor[size];
	for (int i = 0; i < size; i++) {
		actors[i] = right.actors[i];
	}
}

string Film::getFilmTitle() const
{
	return title;
}

string Film::getFilmDirector() const
{
	return director;
}

unsigned int Film::getFilmYear() const
{
	return year;
}

unsigned int Film::getFilmDuration() const
{
	return duration;
}

Actor Film::getActor(int i) {
	return actors[i];
}

Actor& Film::setActor(int i)
{
	return actors[i];
}

unsigned int Film::getnoOfActors()
{
	return noOfActors;
}

unsigned int& Film::setnoOfActors()
{
	return noOfActors;
}

unsigned int Film::getActorSize()
{
	return size;
}

unsigned int& Film::setActorSize()
{
	return size;
}

bool Film::addFilmActor(Actor& a)
{
	for (int j = 0; j < size; j++) {
		if (actors[j].getName() == a.getName())
		{
			return false;
			//debug purposes delete
		}
	}
	
	int oldSize = size;
	this->size = this->size + 1;
	noOfActors = noOfActors + 1;
	Actor* temp = new Actor[oldSize];
	for (int i = 0; i < oldSize; i++) {
		temp[i] = actors[i];
	}
	delete[] actors;
	actors = new Actor[size];
	for (int i = 0; i < oldSize; i++) {
		actors[i] = temp[i];
	}
	actors[oldSize] = a;
	delete[] temp;
	return true;
}	

	


bool Film::removeFilmActors(const string fTitle, const string fDirector)
{
	if (actors) {
		size = 0;
		noOfActors = 0;
		delete[] actors;
		actors = new Actor[size];
		return true;
	}
	else {
		return false;
	}
}

//calculate age of actors declare a year
unsigned int Film::calculateAverageActorAge() const
{
	unsigned int  sum = 0;
	for (int i = 0; i < noOfActors; i++) {
		sum += getFilmYear() - actors[i].getBirthYear();
	}
	if (sum > 0 && noOfActors > 0) {
		return sum / noOfActors;
	}
	else {
		return 0;
	}
}

ostream& operator<<(ostream& out, const Film& f)
{
	out << f.getFilmTitle() << ", " << f.getFilmDirector() << ", " << f.getFilmYear() << ", " << f.getFilmDuration() << " min" << endl;
	for (int i = 0; i < f.size; i++) {
		out << f.actors[i];
	}
	return out;
}
