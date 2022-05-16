#include <allegro.h> 
#include "Headers\Questions.h"
#include <fstream>
#include <time.h> 
#include <string.h>  
#include <iostream>
#include <algorithm> 
#include <vector> 
using namespace std;

Questions::Questions(){
	this->exitFlag = false;
	this->righAns = 0;
}

void Questions::getSortQuestion(int opt, int part){
	srand(time(NULL));
	orderOfQ.clear();
	int numberOfQ;
	if(opt == 1)
		this->numberOfQ = 220;
	else if(opt == 2){
		switch(part){
			case 1:
			case 4:
				this->numberOfQ = 60;
				break;
			case 2:
			case 3:
				this->numberOfQ = 50;
				break;
		}
	} else 
		this->numberOfQ = 10;
		
		
	for (int i=0; i<this->numberOfQ; i++) 
   		orderOfQ.push_back(i);
   	random_shuffle(orderOfQ.begin(),orderOfQ.end());
}

void Questions::getQuestion(int opt, int n, int sel){
	if(opt == 1)
		Questions::fromAll(n);
	else if(opt == 2)
		Questions::fromUnit(sel,n);
	else 
		Questions::fromChapter(sel,n);
		
}

void Questions::fromUnit(int unit, int nQuestion){
	char fromFile[50], unitTo[2];
	strcpy(fromFile,"Text files\\Part 0");
	sprintf(unitTo,"%d",unit);
	strcat(fromFile,unitTo);
	strcat(fromFile,".txt");

	file.open(fromFile, ios::in);
	if(!file) {
		cout<<endl<<"Can't open file."<<endl;
		exit(0);
	}

	ran = orderOfQ.at(nQuestion) * 7;
	for(x=0;x<=ran;x++){
		file.getline(selQ,150);
	}
	file.getline(this->ans1,80); 
	file.getline(this->ans2,80); 
	file.getline(this->ans3,80); 
	file.getline(this->ans4,80); 
	file.getline(this->right,80);
	file.close();
	strcpy(ques, selQ);
}

void Questions::fromChapter(int chapter, int nQuestion){
	char fromFile[50], chapterTo[2];
	if(chapter < 10)
		strcpy(fromFile,"Text files\\Quiz 0");
	else
		strcpy(fromFile,"Text files\\Quiz ");
	sprintf(chapterTo,"%d",chapter);
	strcat(fromFile,chapterTo);
	strcat(fromFile,".txt");
	
	file.open(fromFile, ios::in);
	if(!file) {
		cout<<endl<<"Can't open file."<<endl;
		exit(0);
	}
	ran = orderOfQ.at(nQuestion) * 7;
	for(x=0;x<=ran;x++){
		file.getline(selQ,150);
	}
	file.getline(this->ans1,150); 
	file.getline(this->ans2,80); 
	file.getline(this->ans3,80); 
	file.getline(this->ans4,80); 
	file.getline(this->right,80);
	file.close();
	strcpy(ques, selQ);
}

void Questions::fromAll(int nQuestion){
	srand(time(NULL));
	char fromFile[50], chapterTo[2];
	strcpy(fromFile,"Text files\\All.txt");
	
	file.open(fromFile, ios::in);
	if(!file) {
		cout<<endl<<"Can't open file."<<endl;
		exit(0);
	}
	
	ran = orderOfQ.at(nQuestion) * 7;
	for(x=0;x<=ran;x++){
		file.getline(selQ,150);
	}
	file.getline(ans1,80); 
	file.getline(ans2,80); 
	file.getline(ans3,80); 
	file.getline(ans4,80); 
	file.getline(right,80);
	file.close();
	strcpy(ques, selQ);
}

void Questions::printQuestion(){
	if (strlen(this->ques)<=80)
			textprintf(screen, font, 1,11, palette_color[15],this->ques); 
		else{
			char aux1[80];
			strcpy(aux1, "");
			strncat(aux1,ques,79);
			aux1[80] = '\0';
			textprintf(screen, font, 1,11, palette_color[15],aux1);
			char aux2[70];
			strcpy(aux2, "");			
			strcat(aux2,ques+79);			
			aux2[70] = '\0';			
			textprintf(screen, font, 1,21, palette_color[15],aux2);  
		}
				 
		if(mouse_x > 0 && mouse_x < text_length(font, ans1)+1 && mouse_y > 39 && mouse_y < text_height(font)+39){
			textprintf(screen, font, 1,40, palette_color[1],this->ans1); 
			if(mouse_b & 1){
				if(strcmp(right,ans1) == 0){
					textprintf(screen, font, 1,140, palette_color[9],"Right Answer!!");
					this->righAns++;
				}
				else
					textprintf(screen, font, 1,140, palette_color[9],"The rigth answer was: %s",right);
				this->exitFlag = true;
			}
				
		} else
			textprintf(screen, font, 1,40, palette_color[15],ans1); 
			
		if(mouse_x > 0 && mouse_x < text_length(font, ans2)+1 && mouse_y > 59 && mouse_y < text_height(font)+59){
			textprintf(screen, font, 1,60, palette_color[1],ans2);  
			if(mouse_b & 1){
				if(strcmp(right,ans2) == 0){
					textprintf(screen, font, 1,140, palette_color[9],"Right Answer!!");
					this->righAns++;
				}
				else
					textprintf(screen, font, 1,140, palette_color[9],"The rigth answer was: %s",right);
				this->exitFlag = true;
			}
		} else
			textprintf(screen, font, 1,60, palette_color[15],ans2);  
			
		if(mouse_x > 0 && mouse_x < text_length(font, ans3)+1 && mouse_y > 79 && mouse_y < text_height(font)+79){
			textprintf(screen, font, 1,80, palette_color[1],ans3); 
			if(mouse_b & 1){
				if(strcmp(right,ans3) == 0){
					textprintf(screen, font, 1,140, palette_color[9],"Right Answer!!");
					this->righAns++;
				}
				else
					textprintf(screen, font, 1,140, palette_color[9],"The rigth answer was: %s",right);
				this->exitFlag = true;
			}
		} else
			textprintf(screen, font, 1,80, palette_color[15],ans3); 
			
		if(mouse_x > 0 && mouse_x < text_length(font, ans4)+1 && mouse_y > 99 && mouse_y < text_height(font)+99){
			textprintf(screen, font, 1,100, palette_color[1],ans4); 
			if(mouse_b & 1){
				if(strcmp(right,ans4) == 0){
					textprintf(screen, font, 1,140, palette_color[9],"Right Answer!!");
					this->righAns++;
				}
				else
					textprintf(screen, font, 1,140, palette_color[9],"The rigth answer was: %s",right);
				this->exitFlag = true;
			}
		} else
			textprintf(screen, font, 1,100, palette_color[15],ans4);
			
		textprintf(screen, font, 1,120, palette_color[15],"Score: %d/%d",this->righAns,this->numberOfQ);
		
}

void Questions::countDown(int t){
	if(t == 1)
		this->count = load_bitmap("Sprites\\10.bmp",NULL);
	else if (t == 2)
		this->count = load_bitmap("Sprites\\09.bmp",NULL);
	else if (t == 3)
		this->count = load_bitmap("Sprites\\08.bmp",NULL);
	else if (t == 4)
		this->count = load_bitmap("Sprites\\07.bmp",NULL);
	else if (t == 5)
		this->count = load_bitmap("Sprites\\06.bmp",NULL);
	else if (t == 6)
		this->count = load_bitmap("Sprites\\05.bmp",NULL);
	else if (t == 7)
		this->count = load_bitmap("Sprites\\04.bmp",NULL);
	else if (t == 8)
		this->count = load_bitmap("Sprites\\03.bmp",NULL);
	else if (t == 9)
		this->count = load_bitmap("Sprites\\02.bmp",NULL);
	else if (t == 10)
		this->count = load_bitmap("Sprites\\01.bmp",NULL);
		
	draw_sprite(screen,count,200,200);
}

bool Questions::getExitFlag(){
	return this->exitFlag;
}

void Questions::setExitFlag(){
	this->exitFlag = false;;
}

int Questions::getnumberOfQ(){
	return this->numberOfQ;
}

int Questions::getrighAns(){
	return this->righAns;
}
