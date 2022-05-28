#include"Music_composser.h"

void MusicNote::beep()
{
	Beep(GetH(),GetL());
}

void Rest::beep()
{
	Beep(GetH(), GetL());
}