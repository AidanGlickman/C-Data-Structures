#include <stdio.h>
#include <string.h>

#define fFreeze 32
#define fBoil 212

double f_to_c(double f){
	return (f - 32) * (5.0/9.0);
}
	
int main(){
	int i;
	printf("%10s%10s\n", "Fahrenheit", "Celsius");
	for(i=fFreeze; i<=fBoil; i += 10){
		printf("%10i%10.1f\n", i, f_to_c(i));
	}
}
		
