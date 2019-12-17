#include "Booking.h"

/********************************************//**
 *  constructor of Booking class
 ***********************************************/
Booking::Booking(const vector<Theatre *> & theatre)
{
	T = theatre;
}

Booking::~Booking()
{

}

/********************************************//**
 *  Function to Dispaly Theatres based on the movie name
 ***********************************************/
unordered_set<string> Booking::DisplayTheatre(string movie_n)
{
	unordered_set<string> th;

	for (auto i : T)
	{
		if (i->findTheatre(movie_n))
		{
			th.emplace(i->getTheatreName());
		}
	}
	return th;
}

/********************************************//**
 Function calls theatre classes display functions
 ***********************************************/
void Booking::displayTheatreSeats(Theatre * t)
{
	t->displaySeats();
}
/********************************************//**
 *  Function to print the Ticket
 ***********************************************/
void Booking::printTicket(string name, string mov, string theatre_selected, set<int> seating_selected)
{
	system("CLS");
	cout << "\t\t\t\tHi !!! " << name << " we have booked the seats requested by you" << endl;
	cout << "\t\t\t\tHere is your ticket Please show the same at Cinemax" << endl << endl;

	cout << "\t\t\t\t----------------" << endl;
	cout << "\t\t\t\t----------------" << endl;
	cout << "\t\t\t\t NAME : "  <<name << endl;
	cout << "\t\t\t\t MOVIE : " << mov <<  endl;
	cout << "\t\t\t\t THEATRE : " << theatre_selected  << endl;
	for (auto i : seating_selected)
	{
		cout << "\t\t\t\t SEATNO : " << i << endl;
	}
	cout << "\t\t\t\t----------------" << endl;
	cout << "\t\t\t\t----------------" << endl;

}

/********************************************//**
 *  Function to Display menu and take inputs from
 *  user 
 ***********************************************/
void Booking::Display_menu()
{
	string mov, theatre_selected,name,number;
	int num_of_seats, seat;
	unordered_set<string> theatres_avialable;
	Theatre * theatre_book_seat = nullptr;
	char seating_loop , theatre_loop, movie_loop;

	do
	{
		system("CLS");
		cout << "\n\n\n";
		cout << "\t\t\t\t@@@@@@   Movie Booking System  @@@@@@\n";
		cout << "\t\t\t\t======================================\n";
		cout << "\t\t\t\tSelect a movie and Enter the movie name you want to watch press ctrl-c to exit" << endl;
		cout << "\t\t\t\t--->  Avengers" << endl;
		cout << "\t\t\t\t--->  Black Panther" << endl;
		cout << "\t\t\t\t--->  Venom" << endl;
		cout << "\t\t\t\t--->  Antman" << endl;
		cout << "\t\t\t\t--->  Tomb Raider" << endl;
		cout << "\t\t\t\t--->  Fantastic Beasts" << endl;
		cout << "\t\t\t\t--->  Frozen 2" << endl;
		cout << "\t\t\t\t--->  The Divergent" << endl<<endl<<endl;
		cout << "\t\t\t\tEnter a movie name from above list\n\n";

		getline(cin,mov);
		do
		{
			theatre_loop = 'N';
			theatres_avialable = DisplayTheatre(mov);
			if (theatres_avialable.empty())
			{
				cout << "\t\t\t\tMovie you requesting for is not playing at any of the theatres in the city" << endl << endl << endl;
				break;
			}
			
			system("CLS");
			cout << "\n\n\n\n";
			for (auto i : theatres_avialable)
			{
				cout <<"\t\t\t\t"<< i << endl;
			}
			cout << "\t\t\t\tSelect and enter a theatre name from the list" << endl<<endl;

			getline(cin, theatre_selected);
			for (auto i : T)
			{
				if (i->getTheatreName() == theatre_selected)
					theatre_book_seat = i;
			}

			if (theatre_book_seat == nullptr)
			{
				cout << "\t\t\t\tSorry !!! you have entered incorrect theatrename :) please chooose another theatre" << endl << endl;
				continue;
			}
			do 
			{
				system("CLS");
				set<int>seating_selected;
				seating_loop = 'N';
				theatre_book_seat->displaySeats();

				cout << "\n\n\t\t\t\tSelect the number of seats you wanto buy " << endl<<endl;
				(cin >> num_of_seats).ignore();
				if (num_of_seats > 20 || num_of_seats < 1)
				{
					cout << "\t\t\t\tMAXIMUM seats ::   20 per theatre !!!"<<endl;
					cout << "\t\t\t\tMinimum seats ::   1 per theatre !!!" << endl;
					cout<<"\t\t\t\tPlease book again" << endl;
					continue;
				}
				cout<<"\t\t\t\tSelect Seat number in format rowcol " << endl;
				cout << "\t\t\t\tWhere(A) signifies available seats and (B)is booked  " << endl;
				for (int j = 1; j <= num_of_seats; j++)
				{
					cout << "NO"<< j<<":";
					(cin >> seat).ignore();
					if(seat)
					seating_selected.emplace(seat);
				}
				if (!seating_selected.empty())
				{
					if (theatre_book_seat->bookSeats(seating_selected))
					{
						// TBD print ticket 
						cout << "\n\n\t\t\t\tPlease Enter your name" << endl;
						getline(cin, name);
						printTicket(name, mov, theatre_selected, seating_selected);
					}
				}
				cout << "\n\n\t\t\t\tDo you want to book another Seat in the same theatre (Y/N) " << endl;
				(cin >> seating_loop).ignore();
			} while (seating_loop == 'Y');

			cout << "\n\n\t\t\t\tDo you want to change the theatre for same movie(Y/N)" << endl;
			(cin >> theatre_loop).ignore();
		} while (theatre_loop == 'Y');

		cout << "\n\n\t\t\t\tDo you want to book another movie (Y/N)" << endl;
		(cin >> movie_loop).ignore();
	} while (movie_loop == 'Y');
}
