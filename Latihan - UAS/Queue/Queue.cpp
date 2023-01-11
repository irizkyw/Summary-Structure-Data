#include <iostream>
#include "Queue.h"

using namespace std;

void initQ(ListQ& Q) {
	Q.head = NULL;
}

adrQ allocQ(infoQ databaru) {
	adrQ alloc = new Queue;
	alloc->info = databaru;
	alloc->next = NULL;

	return alloc;
}

void enQ(ListQ& Q, adrQ data_baru) {
	if (Q.head == NULL) {
		Q.head = data_baru;
	}
	else {
		data_baru->next = Q.head;
		Q.head = data_baru;
	}
}

void deQ(ListQ& Q, adrQ& del) {
	if (Q.head == NULL) cout << "Queue Kosong!!" << endl;
	else if (Q.head->next == NULL) {
		del = Q.head;
	}
	else {
		del = Q.head;
		Q.head = Q.head->next;
		del->next = NULL;
	}
}


void showQ(ListQ Q) {
	if (Q.head == NULL) cout << "Queue Kosong!!" << endl;
	else {
		adrQ current = Q.head;
		cout << "Queue : ";
		while (current != NULL) {
			cout << current->info << " ";
			current = current->next;
		}
	}
	cout << endl;
}