
unsigned int x_pos = 0, y_pos = 0;
void puts(char *s){
	volatile char *terminalBuffer= 0xB8000;
        while(*s != 0){
		if(x_pos>=79 || *s == '\n'){
                        x_pos = 0;
                        terminalBuffer += 160; //wanted to use y_pos, but it didn't work due to continue printing!
                }
		else if(/*it now needs to scroll*/){
			memcpy(terminalBuffer, terminalBuffer + 160, 80);//copies 1st line to the previous line and so on
			//n=80 bc it needs to copy all the characters from the previous line up one line, etc.
		}
		else{
			terminalBuffer[y_pos*80+x_pos] = *s;
			x_pos = x_pos+2;
		}
		s++;
		//need to write to terminalBuffer like its an array and increment x and y 
                
		}

}
int memcpy(char *s1, char *s2, int n){
	int i;
	for(i=0; i < n; i++){
		*(s1 + i) = *(s2 + i);
	}
}
int main() {
	char str[] = "Hello \nmy \nname\nis\nJaimie\nRose\nRiemenschneider\nand\nthis\nproject\nis\ndue\ntomorrow.";//needs to have somethin gto do with stdin if I manage to make my own scanf
	puts(str);
}


