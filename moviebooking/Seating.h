#pragma once

#include "common.h"
//********************************************************
//  File Name   : Seating.cpp
//  Author      : Neeti Sharma
//  Desc		: This class creates and initializes
//				  Seating class with functionalities such
//				  as book seat, displaySeats
//*********************************************************

class Seating
{
private:	
	int rows;
	int cols;
	std::unordered_set<int> available_seats;
	//std::unordered_set<int> booked_seats;
	bool update_seats(const std::set<int>& seats);

public:
	Seating(int rows, int cols);
	~Seating();
	void displaySeats();
	bool book_seat(const std::set<int>& seats);
	bool isAnySeatAvailable();
};

