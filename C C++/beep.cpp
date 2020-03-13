#include <iostream>
#include <windows.h> //for Beep()
#include <conio.h> //for _getch()
using namespace std;

int main(int argc, char *argv[]){    
	/*--- Musical Notes of Increasing Pitches ---*/ 
	double pitch[9] = {0,523.3,587.3,659.3,698.5,784.0,880.0,932.3,987.8};
	int music[39] = {5,3,3,0,0,0,4,2,2,0,0,0,1,2,3,4,5,5,5,0,0,0,5,3,3,0,0,0,4,2,2,0,0,0,1,3,5,5,1};
    /*--- play the music defined in music[] automatically ---*/    
	
	for(int t = 0;t < 39;t++){
		if(!music[t])
			Sleep(400); // sleep for a while without making any sound
		else
			Beep(pitch[music[t]],400); // Beep for a musicial note
	}
	
	char note;
	while((note = getch()) != '\n'){
		if(note == 'z' || note == 'Z')
			Beep(pitch[1],100);
		else if(note == 'x' || note == 'X')
			Beep(pitch[1],300);
		else if(note == 'c' || note == 'C')
			Sleep(700);
		//do the same def.
		else
			break;
	}
	return 0; 
}
