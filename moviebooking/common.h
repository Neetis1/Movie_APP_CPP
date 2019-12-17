#pragma once
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include<set>
#include<algorithm>
#include <stdlib.h>
#include <crtdbg.h>	

#define MAX_SEATS 20;

/* This is for changing the color of the seating arrangemnt depending on 
*  the availability Here, \033 is the ESC character, ASCII 27. It is followed by [, *
*  then zero or more numbers separated by ;, and finally the letter m. *
*  The numbers describe the colour and format to switch to from that point onwards. */
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string reset("\033[0m");
using namespace std;

/*for debugging memory leaks only*/
/*
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif
*/