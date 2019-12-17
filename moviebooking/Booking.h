#pragma once
#include "Theatre.h"
#include "Movie.h"
#include "Seating.h"

//********************************************************
//  File Name   : Booking.cpp
//  Author      : Neeti Sharma
//  Desc		: This class creates and initializes
//				  Booking class containing the objects of
//				  class Movie and Theatre with functionalities
//				  such Display_menu , displaySeats
//*********************************************************

class Booking
{
	//Movie * M;
	vector <Theatre *> T;
	vector <string> theatre_name;

public:
	Booking(const vector<Theatre *>& T_in);
	~Booking();
	unordered_set<string> DisplayTheatre(string movie_n);
	void Display_menu();
	void displayTheatreSeats(Theatre * th);
	void printTicket(string name, string mov, string theatre_selected, set<int> seating_selected);
};

