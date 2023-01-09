#include "Stack.h"

using namespace std;

void initS(Stack& S) {
	S.top = -1;
}
bool isEmptyS(Stack S) {
	return (S.top == -1) ? true : false;
}

bool isFullS(Stack S) {
	return (S.top == nmax) ? true : false;
}
void push(Stack& S, infotypeS data_baru) {
	if (isFullS(S)) cout << "Stack full" << endl;
	else {
		S.top += 1;
		S.info[S.top] = data_baru;
	}
}

infotypeS pop(Stack& S) {
	if (isEmptyS(S)) cout << "Stack kosong" << endl;
	else {
		infotypeS delS;
		delS = S.info[S.top];
		S.top -= 1;

		return delS;
	}
}

int findIndexS(Stack S, infotypeS target) {
	if (isEmptyS(S)) return -1;
	else {
		for (int i = nmax - 1; i > -1; --i) {
			if (S.info[i] == target) return i;
		}
	}
}


void showS(Stack S) {
	if (isEmptyS(S)) cout << "Stack kosong" << endl;
	else {
		cout << "Start Stack : " << endl;
		for (int i = S.top; i > -1; --i) {
			cout << i << " " << S.info[i] << endl;
		}
		cout << "End Stack" << endl << endl;
	}
}