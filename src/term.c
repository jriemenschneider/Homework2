
unsigned int x_pos = 0, y_pos = 0;
void puts(char *s){
	volatile char *terminalBuffer= 0xB8000;
        while(*s != 0){
		if(x_pos>=79 || *s == '\n'){
                        x_pos = 0;
                        terminalBuffer += 160;
                        //y_pos= y_pos+160;//goes down like Y
			
                }
		else{
		terminalBuffer[y_pos*80+x_pos] = *s;//terminal buffer is na array and the index you right to is the location you want(which is in []) !!! so it's an array of shorts bc those are each two bytes long!)
		x_pos = x_pos+2;
		}
		s++;
		//need to write to terminalBuffer like its an array and increment x and y 
                
		}

} 
int main() {
	char str[] = "Hello\nI'm tired.";
	puts(str);
}

