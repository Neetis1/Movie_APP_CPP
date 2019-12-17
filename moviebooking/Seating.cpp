#include "Seating.h"


/********************************************//**
 * contructor to initialize Seating class 
 * with number of rows and columns given 
 ***********************************************/
Seating::Seating(int rows, int cols) : rows(rows), cols(cols)
{
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			string row, col;
			row = std::to_string(i);
			col = std::to_string(j);
			int num = stoi(row + col);
			available_seats.emplace(num);
		}
	}
}


Seating::~Seating()
{
}

/********************************************//**
 *  Function to display seating arrangment of 
 *  Theatre selected, This class show the seating 
 arragement in the following manner ::
Seat avaialblity(A or B) followed by row number and col number 
example : A11 means row : 1 col : 1 A(seat available)
example : B12 means row : 1 col : 2 B(seat Booked)

 ***********************************************/
void Seating::displaySeats()
{
	cout << "\n\n\n\n\t\t\t\t--------------------------------" << endl;
	cout << "\t\t\t\t--------------------------------\n\n" << endl;
	for (int i = 1; i <= rows; ++i)
	{
		cout << "\t\t\t\t";
		for (int j = 1; j <= cols; ++j)
		{
			string row, col;
			row = std::to_string(i);
			col = std::to_string(j);
			int num = stoi(row + col);

			if (available_seats.find(num) != available_seats.end())
			{
				
				cout <<green << "A-" << reset <<num << " ";
			}
			else
			{
				
				cout << red << "B-" <<reset << num << " ";
			}
		}
		cout << endl;
	}
	cout << "\n\n\t\t\t\t--------------------------------" << endl;
	cout << "\t\t\t\t--------------------------------" << endl;
}

/********************************************//**
 *  Function to remove the seat booked from the 
 *  set of avaialble seats
 ***********************************************/
bool Seating::update_seats(const std::set<int>& seats)
{
	for (auto seat : seats)
	{
		available_seats.erase(seat);
	}
	return true;
}

/********************************************//**
 *  function to book the seat based on the set 
 *  of sent from the booking class
 ***********************************************/
bool Seating::book_seat(const std::set<int>& seats)
{
	if (seats.empty())
	{
		cout << "Please enter some seat number";
		return false;
	}
	for (auto seat : seats)
	{
		if (available_seats.find(seat) == available_seats.end())
		{
			cout << "\t\t\t\t" << seat << " is already booked or out of range. Please enter seats that start with letter A(Available) in range" << endl;
			return false;
		}
	}
	return update_seats(seats);
}

/********************************************//**
 *  Function returns false if the available seat is empty
 ***********************************************/
bool Seating::isAnySeatAvailable()
{
	if (available_seats.empty())
	{
		return false;
	}
	return true;
}