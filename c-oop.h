/*header file*/
#include <stdio.h>
#include<stdlib.h>
#include<stdarg.h>
typedef enum
{
	true,false
	/*
	true = 0,
	false = 1
	*/
} bool;
/*function prototype declaration*/
double sum(size_t arg_count,...);
double average(size_t arg_count,...);
double factorial(double num);
double fibonacci(double num);
double gcd(double x,double y);
double sum_of_array(size_t len,int arr[]);
bool is_power_of_2(int num);
/*geometry*/
double area_of_square(double area);
/*this struct will work like our class*/
struct math{
	/*this works like a class variable*/
	int number;
	
	/*pretend these as class methods*/
	double (*sum)(size_t,...);					/*function pointers*/
	double (*average)(size_t,...);
	double (*factorial)(double);
	double (*fibonacci)(double);
	double (*gcd)(double,double);
	double (*sum_of_array) (size_t,int[]);
	bool   (*is_power_of_2) (int);

};
/*
above code is similar to

class math{
	public:
	double sum(size_t,...);
	double average(size_t,...);
	double factorial(double);
	double fibonacci(double);
	double gcd(double,double);
	double sum_of_array (size_t,int[]);
	bool is_power_of_2 (int);

}


*/
/*inheritance*/
struct Geometry{
	struct math math_obj;			/*math struct within for inheritance*/
	double (*area_of_square)(double);

	
};
/*
above code is similar to:

class Geometry(math){
	some data ....
}

*/

struct math create_object(struct math* obj);	/*creates math object*/
struct math create_object_with_number(struct math *obj,int number);	/*creates object with constructor*/
struct Geometry create_object_geometry(struct Geometry *obj);	/*creates geometry object*/
struct Geometry create_object_by_inherit(struct Geometry *geo_obj,struct math *math_obj);	/*create object by inheriting math*/
/*function defintion*/

double sum(size_t arg_count,...){
	/*
	*function parameters = size_t represents only positive integers allowed as length cannot be negative,
	... = takes variable argument
	*/
	va_list valist;
	va_start(valist,arg_count);			/*starts from*/
	double sum = 0;
	for (int i = 0; i < arg_count; ++i)
	{
		sum += va_arg(valist,int);			/*iterating through the argument list*/
	}
	va_end(valist);		
	return sum;
}
double average(size_t arg_count,...){
	/*ccalculates average with taking variable arguments,
	expected parameters = 1) argument count and 2) the numbers
	*/
	va_list valist;
	va_start(valist,arg_count);
	double sum = 0;
	for (int i = 0; i < arg_count; ++i)
	{	
		sum += va_arg(valist,int);
	}
	va_end(valist);
	return sum/arg_count;
}
double factorial(double num){
	/*expected parameters is number and returns factorial for the
	passed argument using recursion*/
	if(num < 2){	/*if num == 0 | 1*/
		return num;
	}
	/*if num = 2,3,4.......n*/
	else{
		/*recursion until num reaches 1*/
		return num * factorial(num - 1);
	}
}

double fibonacci(double num){
	/*fibonacci series,
	expected argument is number of double type
	*/
	if(num < 2){		
		/*if num = 0 | 1*/
		return num;	
	}
	else{
		return fibonacci(num-1) + fibonacci(num-2);
	}
}
double gcd(double x,double y){
	/*euclidean method to find greatest common divisor*/
	while(x != y){
		/*
		if x is greater than y than subtract y from x
		and 
		if y is greater than x, than subtract x from y
		*/
		x > y ?  (x-=y) : (y-=x);		/* (condition) ? true : false */
	}
	return x;
}
double sum_of_array(size_t len,int arr[]){
	/*expected argumenets
	length of array and array
	*/
	double sum = 0;
	/*loop till length of the array*/
	for (size_t i = 0; i < len; ++i)
	{
		sum += arr[i];
	}
	return sum;
}
bool is_power_of_2(int num){
	/*expected argument,
	number of type int
	*/
	return num && !(num & (num-1));
}
struct math create_object(struct math* obj){
	/*similar to instantiation*/
	obj->sum = sum;				
	obj->average = average;
	obj->factorial = factorial;
	obj->fibonacci = fibonacci;
	obj->gcd = gcd;
	obj->sum_of_array = sum_of_array;
	obj->is_power_of_2 = is_power_of_2;
}
struct math create_object_with_number(struct math *obj,int number){
	/*instantiation with constructor | getter*/
	obj->number = number;
	obj->sum = sum;
	obj->average = average;
	obj->factorial = factorial;
	obj->fibonacci = fibonacci;
	obj->gcd = gcd;
	obj->sum_of_array = sum_of_array;
	obj->is_power_of_2 = is_power_of_2;	
}

/*geometry class*/
double area_of_square(double side){
	return side*side;
}
/*
there's a option to instantiate object with inheritance with base class math  or normal instantiaton
*/
struct Geometry create_object_geometry(struct Geometry *obj){
	obj->area_of_square = area_of_square;
	
}
/*create object by inheriting math class,pretending*/
struct Geometry create_object_by_inherit(struct Geometry *geo_obj,struct math *math_obj){
	geo_obj->area_of_square = area_of_square;
	create_object(&geo_obj->math_obj);
}
/*
@sajid shaikh
*/