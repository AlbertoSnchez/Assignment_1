#ifndef Questions_h
#define Questions_h
#include <allegro.h>   
#include <fstream> 
#include <algorithm> 
#include <vector> 
using namespace std;

class Questions {    
public:
	int x, ran, par1, par2, numberOfQ, righAns;
	char selQ[150], ques[150];
	char ans1[80],ans2[80],ans3[80],ans4[80],right[80];
	bool exitFlag;
	fstream file;
	vector<int> orderOfQ;
	BITMAP *count;
	
    Questions();
    
    void getSortQuestion(int opt, int part);
    void getQuestion(int opt, int part, int sel);
    void fromUnit(int unit, int nQuestion);
    void fromChapter(int chapter, int nQuestion);
    void fromAll(int nQuestion);
	void printQuestion();
	void countDown(int t);
	bool getExitFlag();    
	void setExitFlag();
	int getnumberOfQ();
	int getrighAns();
};

#endif
