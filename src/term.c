
unsigned int x_pos = 0, y_pos = 0;
volatile char *terminalBuffer = 0xB8000;//declared this outside method so it multiple puts calls wouldn't overwrite the previous input
void puts(char *s){ 
        while(*s != 0){
		if(x_pos>=160){//wraps the text to next line bc of char we need to use160 instead of 80
			x_pos = 0;
			terminalBuffer+= 160;
			s++;
		}
		else if(*s == '\n'){//goes to the newline when \n is typed
			x_pos = 0;
                        terminalBuffer += 160;
			s++;
		}
		else{
			terminalBuffer[y_pos*80+x_pos] = *s;
			x_pos = x_pos+2;//gets it to next position in memory to print char
			s++;
		}
                if(terminalBuffer>=0xB8FA0){//end of the page!!!!
			terminalBuffer = 0xB8000;
                        volatile char *source = (0xB8000+160);//one line down(what you copy into terminalBuffer which is stationed at the previous line)
                        while(terminalBuffer<(0xB8F00)){//point in memory at beginning of 25th "line" of text on screen AKA the line you need to scroll up on so you can keep writing
                                memcpy(terminalBuffer , source, 80);//copies 1st line to the previous line and so on
				*terminalBuffer++= *source++;//goes to the next line so it can continue copying
                                }
                }}
}



int memcpy(char *s1, char *s2, int n){
	int i;
	for(i=0; i <= n; i++){
		*(s1 + i) = *(s2 + i);//copies character by character the lower line into the upper line(n=80 because 80 characters in a line)
	}
}

int main() {
	char s[]= "multiple puts calls does not overwrite previous work and also the text can wrap itself around when it reaches the length of the screen. I can further prove this point by entering a line of a book here: Here is Edward Bear, coming down the stairs now, bump, bump, bump, in the back of his head, behind Christopher Robin.";
	puts(s);//tested wrapping text on screen
	char str[] = "Hello \nmy \nname\nis\nJaimie\nRose\nRiemenschneider\nand\nthis\nproject\nis\ndue\nTuesday\na\nb\nc\nd\ne\nf\ng\nh\nH\nj\nk\nl\nn\nm\no\np\nq\nr\ns\nIT WORKS"; 
	puts(str);//tested multiple calls, next line, and scrolling
}


