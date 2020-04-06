#include <stdio.h>
#include<stdlib.h>
#include "c-oop.h"			/*Importing OOP library*/



int main(int argc, char const *argv[])
{
	//struct math m;
	//create_object(&m);
	//printf("%d",m.is_power_of_2(4)); 
	struct math m;
	struct Geometry geom;
	create_object_by_inherit(&geom,&m);
	printf("is power of 2: %d",geom.math_obj.is_power_of_2(7));	
	system("pause");
	return 0;

}
