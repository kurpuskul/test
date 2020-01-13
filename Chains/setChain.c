#include <stdio.h>

#define SAW 4
#define MAXSIZE 65536
#define MAXLEN 256

struct detail {
 int id;
 int l;
 int w;
 int num;
 int init;
 int rot;
};

unsigned int chain_mem[MAXSIZE];
unsigned int chain_cur;

struct chain {
 unsigned int len;
 unsigned int size_0;
 unsigned int size_n;
};

struct detail list[] = {
	{1, 450, 600, 5, 5, 1},
	{2, 750, 480, 5, 5, 1},
	{3, 350, 90, 5, 5, 1},
	{4, 440, 610, 5, 5, 1},
	{5, 900, 680, 5, 5, 1},
	{6, 670, 250, 5, 5, 1},
	{7, 690, 790, 5, 5, 1},
	{8, 890, 340, 5, 5, 1},
	{9, 586, 520, 5, 5, 1},
	{10, 456, 180, 5, 5, 1},
	{11, 987, 960, 5, 5, 1},
	{12, 150, 670, 5, 5, 1},
	{13, 890, 290, 5, 5, 1},
	{14, 990, 810, 5, 5, 1},
	{15, 980, 680, 5, 5, 1},
	{16, 970, 390, 5, 5, 1},
	{17, 960, 380, 5, 5, 1},
	{18, 950, 370, 5, 5, 1},
	{19, 940, 360, 5, 5, 1},
	{20, 830, 560, 5, 5, 1},
	{21, 820, 550, 5, 5, 1},
	{22, 810, 540, 5, 5, 1}
};


void setchain(int *, struct chain *);
struct chain chains[MAXSIZE];

int main(){
	int sizes[MAXSIZE];
	int i;
	for (i = 0; i < 22; i++) {
		sizes[i] = list[i].l;	
	}
	sizes[i] = 0;
	setchain(sizes, chains);
	for(int j = 0; chains[j].len != 1634; j++){
		printf("%d. %d\t%d + %d\n", j, chains[j].len, chain_mem[chains[j].size_0], chain_mem[chains[j].size_0+1]);
	}
	return 0;
}

void setchain(int *sizes, struct chain *chains) {
	chain_cur = 0;
	for(int i = 0; sizes[i] !=0; i++) {
		if(sizes[i+1] != 0) {
			struct chain ch;
			int len = sizes[i] + sizes[i+1] + SAW;
			ch.len = len;
			ch.size_0 = chain_cur;
			ch.size_n = 2;
			chain_mem[chain_cur] = sizes[i];
			chain_mem[chain_cur+1] = sizes[i+1];
			chain_cur+=2;
			chains[i] = ch;	
		}
	}
}
