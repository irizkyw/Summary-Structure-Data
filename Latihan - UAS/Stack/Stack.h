#include <iostream>

typedef char infotypeS;

typedef struct Stack* adrS;

const int nmax = 5;

struct Stack {
	infotypeS info[nmax];
	int top;
};

void initS(Stack& S);
bool isEmptyS(Stack S);
bool isFullS(Stack S);
void push(Stack& S, infotypeS data_baru);
infotypeS pop(Stack& S);
int findIndexS(Stack S, infotypeS target);

void showS(Stack S);