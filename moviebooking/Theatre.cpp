#include "Theatre.h"


using namespace std;

Theatre::Theatre()
{
}

/********************************************//**
 *  constructor of class Theatre to initialize 
 *  Seating arrangement for every theatre object that is created
 ***********************************************/
Theatre::Theatre(string theaterName, string location,unordered_set<string> tim) : theaterName(theaterName),location(location),movie_n(tim)
{
	S = new Seating(5,4);
}

/********************************************//**
 * destructor for Theatre class deletes Seating object pointer
 ***********************************************/

Theatre::~Theatre()
{
	delete S;
}

/********************************************//**
 *  Function to return theatrename
 ***********************************************/
string Theatre::getTheatreName()
{
	return theaterName;
}

/********************************************//**
 *  Function calls Seater classes dispaly function
 ***********************************************/
void Theatre::displaySeats()
{
	S->displaySeats();
}

/********************************************//**
 *   Function returns true if seats are booked else return  false
 ***********************************************/
bool Theatre::bookSeats(const std::set<int>& seats)
{	
	if (S->book_seat(seats))
		return true;
	else
		return false;
}

/********************************************//**
 *  Function to find Theatres based on the movie name
 ***********************************************/
bool Theatre::findTheatre(string movie_name)
{
	if ( movie_n.find(movie_name) != movie_n.end())
		return true;
	else
		return false;
}

/* ///commenting as of now TBD add theatre timings
unordered_set<string> Theatre:: findtiming(string movie_name)
{
	unordered_set<string> emptys;
	return time.find(movie_name) != time.end() ? time[movie_name] : emptys;
}
*/
