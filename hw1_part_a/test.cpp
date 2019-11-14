
//WILL NOT SUBMITTED
#include "SimpleFilm.h" 
#include "SimpleFC.h" 

void displayAllFilms(FC& fc) {
	Film* allFilms;
	unsigned int noOfFilms = fc.getFilms(allFilms);

	cout << "No of films: " << noOfFilms << endl;
	for (unsigned int i = 0; i < noOfFilms; i++) cout << allFilms[i];

	if (allFilms != NULL) delete[] allFilms;
}

int main() {
	FC fc;

	fc.addFilm("Midnight Cowboy", "John Schlesinger", 1969, 113);
	if (fc.addFilm("Annie Hall", "Woody Allen", 1977, 93))
		cout << "Successful insertion of Annie Hall, 1977, "
		<< "Woody Allen, 93 min" << endl;
	else
		cout << "Unsuccessful insertion of Annie Hall, 1977, "
		<< "Woody Allen, 93 min" << endl;
	fc.addFilm("Full Metal Jacket", "Stanley Kubrick", 1987, 116);
	fc.addFilm("Good Will Hunting", "Gus Van Sant", 1997, 126);
	fc.addFilm("Requiem for a Dream", "Darren Aronofsky", 2000, 101);
	fc.addFilm("The Diving Bell and the Butterfly", "Julian Schnabel",
		2007, 112);
	if (fc.removeFilm("Zelig", "Woody Allen"))
		cout << "Successful deletion of Zelig, Woody Allen" << endl;
	else
		cout << "Unsuccessful deletion of Zelig, Woody Allen" << endl;
	displayAllFilms(fc);

	return 0;
}

//output
//Successful insertion of Annie Hall, 1977, Woody Allen, 93 min
//Unsuccessful deletion of Zelig, Woody Allen
//No of films : 6
//Midnight Cowboy, 1969, John Schlesinger, 113 min
//Annie Hall, 1977, Woody Allen, 96 min
//Full Metal Jacket, 1987, Stanley Kubrick, 116 min
//Good Will Hunting, 1997, Gus Van Sant, 126 min
//Requiem for a Dream, 2000, Darren Aronofsky, 101 min
//The Diving Bell and the Butterfly, 2007, Julian Schnabel, 112 min