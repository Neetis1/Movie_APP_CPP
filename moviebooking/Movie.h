#pragma once
#include "common.h"

//********************************************************
//  File Name   : SMovieTheater.cpp
//  Author      : Neeti Sharma
//  Desc		: This class creates and initializes
//				  movie class with several attributes
//*********************************************************

struct Movie
{
	string movie_name;
	string movie_desciption;
	string user_review;
	float user_rating;
    float Imdb_rating;
	unordered_set<string> crew_members;

	Movie(string name, string desc, string user_rev, float uRating, float imdbR, const unordered_set<string>& crew)
	{
		movie_name = name;
		movie_desciption = desc;
		user_review = user_rev;
		user_rating = uRating;
		Imdb_rating = imdbR;
		crew_members = crew;
	}
};
