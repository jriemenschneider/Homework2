
unsigned int x_pos = 0, y_pos = 0;
volatile char *terminalBuffer = 0xB8000;
void puts(char *s){ 
	int lineCount = 0;
        while(*s != 0){
		if(x_pos>=160){//wraps the text to next line
			x_pos = 0;
			terminalBuffer += 160;
			lineCount++;
		}
		else if(*s == '\n'){//goes to the newline when \n is typed
			x_pos = 0;
                        terminalBuffer += 160;
                        lineCount++;
			s++;
		}
		else{
			terminalBuffer[y_pos*80+x_pos] = *s;
			x_pos = x_pos+2;
			s++;
		}
		//need to write to terminalBuffer like its an array and increment x and y 
                if(lineCount >= 25){
                        terminalBuffer = 0xB8000;
                        while(terminalBuffer<(0xB8000+(160*24))){
                                memcpy(terminalBuffer, (terminalBuffer + 160), 80);//copies 1st line to the previous line and so on
                                terminalBuffer += 160;//goes to the next line so it can continue copying
                        }
                }

		}

}

int memcpy(char *s1, char *s2, int n){
	int i;
	for(i=0; i <= n; i++){
		*(s1 + i) = *(s2 + i);
	}
}

int main() {
	char str[] = "Hello \nmy \nname\nis\nJaimie\nRose\nRiemenschneider\nand\nthis\nproject\nis\ndue\ntomorrow\na\nb\nc\nd\ne\nf\ng\nh\ni\nj\nk\nl\nn\nm\no\np\nq\nr\ns\nz";
	puts(str);
	char s[]= "multiple puts calls does not overwrite previous work and also the text can wrap itself around when it reaches the length of the screen.";
	puts(s);
}


