 


unsigned int x_pos = 0, y_pos = 0;
void puts(char *s){
	char *terminalBuffer = 0xB8000;
        int k;
        for(k=0; k<10; k++){
                terminalBuffer[y_pos*80+x_pos] = s;//need to increment x and y
                }

} 
int main() {
	char str = 'K';
	puts(str);
	/*char *terminalBuffer = 0xB8000;
        int k;
        for(k=0; k<10; k++){
                terminalBuffer[y_pos*80+x_pos] = 'k';//need to increment x and y
                }*/


}

