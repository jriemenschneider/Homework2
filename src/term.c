#include <stdio.h>


putS(char *s){
	volatile char *video = (volatile char*)0xB8000;
	while( *string != 0){
		*video++ = *string++;
	}
}

main(){
	char str[] = "HELLO";
	putS(str);

}
