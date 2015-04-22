/*
* Author:	Keith Bush
*			UALR
*
* Date:		February 24, 2015 (Completed)
*
* File:		Definitions.h (Hmwk.1.Solution)
*
* Purpose:	This is a standard type redefinitions header that allows
*           for flexibility in programming should design parameters change.
*           Ideally, every SDL2 specific type would be renamed allowing
*           the code to be decoupled from any specific Media Library.
*/

#pragma once

// Basic Types
typedef unsigned long long int uint64;
typedef unsigned int uint32;
typedef unsigned short int uint16;
typedef float float32;
typedef double float64;
typedef struct GAME_VEC {
	float32 x;
	float32 y;
} GAME_VEC;

// Event Types
enum GAME_EVENT { GAME_NA, GAME_UP, GAME_DOWN, GAME_LEFT, GAME_RIGHT, GAME_W, GAME_A, GAME_S, GAME_D, GAME_SPACE };

// Constants
const float32 PI = 3.14159f;
