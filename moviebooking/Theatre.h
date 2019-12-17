#pragma once
#include "common.h"
#include "Seating.h"

//********************************************************
//  File Name   : Theatre.cpp
//  Author      : Neeti Sharma
//  Desc		: This class creates and initializes
//				  Theatre class contaning Seating class 
//				  object with functionalities such as
//				  book seat, find theatre based on movie name
//*********************************************************

class Theatre
{
	string theaterName;
	string location;
	unordered_set <string> movie_n;
	Seating * S;

public:
	Theatre();
	Theatre (string theaterName, string location , unordered_set<string> movie_n);
	~Theatre();
	
	void displaySeats();
	string getTheatreName();
	bool findTheatre(string movie_name);
	bool bookSeats(const std::set<int>& seats);

	//unordered_set<string> findtheatrnames(string movie_name);
	//void findTheatre(string movie_name);
	//unordered_set<string> findtiming(string movie_name);

};



