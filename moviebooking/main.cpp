#include "Seating.h"
#include "Booking.h"
#include "Movie.h"
#include "Theatre.h"
#include "common.h"

/********************************************//**
 *  Creating Movie Set for to be used for initialization of theatres object
 ***********************************************/
unordered_set <string> mov_set1 = { 
							"Avengers",
							"Black Panther",
							"Venom",
							"Antman",
							"Fantastic Beasts"
					};

unordered_set<string> mov_set2 = {
							"Avengers",
							"Black Panther",
							"Venom",
							"Antman",
							"Tomb Raider",
							"Fantastic Beasts",
							"Frozen 2",
							"The Divergent"
					};

unordered_set<string> mov_set3 = {
							"Avengers",
							"Black Panther",
							"Venom"
					};

unordered_set<string> mov_set4 = {
							"Avengers",
							"Antman",
							"Tomb Raider",
							"Fantastic Beasts",
							"Frozen 2",
							"The Divergent"
					};




int main()
{

	Theatre * t1 = new Theatre("Garuda", "M G Road", mov_set1);
	Theatre * t2 = new Theatre("Pheonix", "Whitefield", mov_set2);
	Theatre * t3 = new Theatre("Gopalan Cinemas", "BTM", mov_set3);
	Theatre * t4 = new Theatre("INOX", "Forum", mov_set4);

	vector <Theatre *> theatre;

	theatre.emplace_back(t1);
	theatre.emplace_back(t2);
	theatre.emplace_back(t3);
	theatre.emplace_back(t4);

	Booking * book_tickets = new Booking(theatre);
	book_tickets->Display_menu();

	delete t1,t2,t3,t4,book_tickets;

	//_CrtDumpMemoryLeaks();
	getchar();
	return 0;
}

