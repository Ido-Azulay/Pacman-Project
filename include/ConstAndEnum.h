#pragma once

const char PACMAN	   = 'a';
const char GHOST	   = '&';
const char DOOR		   = 'D';
const char WALL		   = '#';
const char COOKIE      = '*';
const char KEY         = '%';
const char RANDGHOST =   '^';
const char ORANGEGHOST = '~';
const char LIFE_GIFT =   '3';
const char TIME_GIFT =   '$';
const char FREEZE_GIFT = '!';
const char SUPER_GIFT =  '@';

const char HELP = '?';
const char PLAY = '>';
const char EXIT = 'x';
const char BACK = '<';

enum Menu_Textures
{
	t_Backround,
	t_helpBackround,
	t_Help,
	t_Exit,
	t_Play,
	t_Back,
	t_Win,
	t_Loose,
	t_Total
};


const float SPRITE_SIZE = 50.f;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGT = 900;