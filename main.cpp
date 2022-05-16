#include "Headers\Questions.h"
#include <allegro.h>
#include <winalleg.h>
#include <windows.h>
#include <MMSystem.h>
#include <string.h>    
#include <stdlib.h> 
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void init();
void deinit();

int main() {
	init();
	bool musicOn = true; 
	PlaySound(TEXT("Music\\Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	int timer = clock();
	while((timer/1000) < 15 && !keypressed()){
		textprintf(screen, font, 200,10, palette_color[15],"Welcome to the Quiz!!!");
		textprintf(screen, font, 1,30, palette_color[15],"The instructions are simple, you have to select an option from the next menu");
		textprintf(screen, font, 1,45, palette_color[15],"if your selection needs more information, you'll have to select another option.");
		textprintf(screen, font, 1,60, palette_color[15],"After that, a question and its answers will appear, you have to click on the one");
		textprintf(screen, font, 1,75, palette_color[15],"you think it's right, you have 10 seconds, while you take the this, your score");
		textprintf(screen, font, 1,90, palette_color[15],"will be shown like 0/10. Good luck!");
		if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_M])
			if (musicOn){
				musicOn = false;
				PlaySound(NULL,0,0);
			} else{
				musicOn = true;
				PlaySound(TEXT("Music\\Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
			}
		timer = clock();
	}
	clear_bitmap(screen);
	
	Questions *question = new Questions();
	
	char opt1[50],opt2[50],opt3[50];
	int opt, selec, i;
	strcpy(opt1,"Quiz about the entire text");
	strcpy(opt2,"Quiz about a particular unit");
	strcpy(opt3,"Quiz about a particular chapter");
	
	while(!key[KEY_ESC]){
		textprintf(screen, font, 50,20, palette_color[15],"Now you have to choose the type of the quiz:"); 
	
		if(mouse_x > 49 && mouse_x < text_length(font, opt1)+50 && mouse_y > 39 && mouse_y < text_height(font)+40){
			textprintf(screen, font, 50,40, palette_color[1],opt1); 
			if(mouse_b & 1){
				opt = 1;
				selec = 0;
				break;
			}
		} else
			textprintf(screen, font, 50,40, palette_color[15],opt1); 
				
		if(mouse_x > 49 && mouse_x < text_length(font, opt2)+50 && mouse_y > 54 && mouse_y < text_height(font)+55){
			textprintf(screen, font, 50,55, palette_color[1],opt2); 
			if(mouse_b & 1){
				opt = 2;
				break;
			}
		} else
			textprintf(screen, font, 50,55, palette_color[15],opt2); 
				
		if(mouse_x > 49 && mouse_x < text_length(font, opt3)+50 && mouse_y > 69 && mouse_y < text_height(font)+70){
				textprintf(screen, font, 50,70, palette_color[1],opt3); 
				if(mouse_b & 1){
					opt = 3;
					break;
				}
			} else
				textprintf(screen, font, 50,70, palette_color[15],opt3); 
				
		if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_M])
			if (musicOn){
				musicOn = false;
				PlaySound(NULL,0,0);
			} else{
				musicOn = true;
				PlaySound(TEXT("Music\\Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
			}
	}
	
	clear_bitmap(screen);
	
	i = 0;
	if(opt == 2)
		while(1){
			textprintf(screen, font, 50,20, palette_color[15],"Select the unit of the quiz:"); 
			if(mouse_x > 49 && mouse_x < text_length(font, "Unit  ")+50 && mouse_y > ((i*15)+39) && mouse_y < text_height(font)+((i*15)+40)){
				textprintf(screen, font, 50,((i*15)+40), palette_color[1],"Unit %d",(i+1)); 
				if(mouse_b & 1){
					selec = (i+1);
					break;
				}
			} else
				textprintf(screen, font, 50,((i*15)+40), palette_color[15],"Unit %d",(i+1)); 
			i++;
			if(i == 4)
				i = 0;
				
			if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_M])
				if (musicOn){
					musicOn = false;
					PlaySound(NULL,0,0);
				} else{
					musicOn = true;
					PlaySound(TEXT("Music\\Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				}
		}
				
	i = 0;
	if(opt == 3)
		while(1){
			textprintf(screen, font, 50,20, palette_color[15],"Select the chapter of the quiz:"); 
			if(mouse_x > 49 && mouse_x < text_length(font, "Chapter   ")+50 && mouse_y > ((i*15)+39) && mouse_y < text_height(font)+(40+(i*15))){
				textprintf(screen, font, 50,((i*15)+40), palette_color[1],"Chapter %d",(i+1)); 
				if(mouse_b & 1){
					selec = (i+1);
					break;
				}
			} else
				textprintf(screen, font, 50,((i*15)+40), palette_color[15],"Chapter %d",(i+1)); 
			i++;
			if(i == 22)
				i = 0;
				
			if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_M])
				if (musicOn){
					musicOn = false;
					PlaySound(NULL,0,0);
				} else{
					musicOn = true;
					PlaySound(TEXT("Music\\Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				}
		}

	clear_bitmap(screen);
	
	Sleep(1000);
	
	if(opt == 1)
		question->getSortQuestion(1,0);
	else if (opt == 2)
		question->getSortQuestion(2,selec);
	else 
		question->getSortQuestion(3, selec);
		
	timer = 0;
	timer = clock();
	timer = clock();
	for(int x=0;x<question->getnumberOfQ();x++){
		
		question->getQuestion(opt,x,selec);

		time_t time1, time2;
		time(&time1);
		while (difftime(time2, time1) < 11 && !question->getExitFlag()) {
			
			time(&time2);
			float t = difftime(time2, time1);
			if(t == 2)
				question->countDown(1);
			else if (t == 3)
				question->countDown(2);
			else if (t == 4)
				question->countDown(3);
			else if (t == 5)
				question->countDown(4);
			else if (t == 6)
				question->countDown(5);
			else if (t == 7)
				question->countDown(6);
			else if (t == 8)
				question->countDown(7);
			else if (t == 9)
				question->countDown(8);
			else if (t == 10)
				question->countDown(9);
			else if (t == 11)
				question->countDown(10);
			question->printQuestion();
			if(key[KEY_ESC]){
				x = 1500;
				break;
			}
			
			if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_M])
				if (musicOn){
					musicOn = false;
					PlaySound(NULL,0,0);
				} else{
					musicOn = true;
					PlaySound(TEXT("Music\\Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				}
		}
		question->setExitFlag();
		Sleep(1000);
		clear_bitmap(screen);
	}
	Sleep(1000);
	clear_bitmap(screen);
	while(!key[KEY_ESC]){
		textprintf(screen, font, 1,40, palette_color[10],"Your total score was %d/%d",question->getrighAns(),question->getnumberOfQ());
		textprintf(screen, font, 1,20, palette_color[10],"Press the esc for exit");
	}
	
	deinit();
	allegro_exit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	install_mouse();
	/* add other initializations here */
	show_mouse(screen);
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
