#include <stdio.h>

unsigned int x=0, y=0;
void putS(char *s){
	char *terminalBuffer = 0xB8000;
	while(*s != 0){
		terminalBuffer++ = *s++;/*always continue going down the string char by char until you run out of chars*/
		/*if(s== '\n'){
			row++;
			column = 0; ? will do more research but basically what I want QEMU to do.
		}*/
	}
}

int main(){
	char str[] = "HELLO";
	/*scanf("%s", &str); will use this after I prove I can print to the screen*/
	putS(str);

}
