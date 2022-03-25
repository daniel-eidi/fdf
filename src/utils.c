#include "../includes/fdf.h"

int mod(float x)
{
	if(x)
		return(x);
	return(x * -1);
}

int max(float x, float y)
{
	if(x >= y)
		return(x);
	return(y);
}
int min(float x, float y)
{
	if(x >= y)
		return(y);
	return(x);
}