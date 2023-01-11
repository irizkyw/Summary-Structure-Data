#include "Graph.h"

using namespace std;

void initG(adrG& G) {
	G = nullptr;
}

adrG allocNodeG(infoG data_baru) {
	adrG alloc = new NodeG;
	alloc->info = data_baru;
	alloc->next = nullptr;
	alloc->edge = nullptr;
	return alloc;
}
adrGEdge allocEdgeG(infoG data_baru) {
	adrGEdge alloc = new EdgeG;
	alloc->dist = data_baru;
	alloc->edge_next = nullptr;
	return alloc;
}
void addG(adrG& G, adrG dwData) {
	if (G == nullptr) {
		G = dwData;
	}
	else {
		adrG current = G;
		while (current->next != nullptr) current = current->next;
		current->next = dwData;
	}
}
bool isConnected(adrG G, infoG start, infoG end) {
	if (G == nullptr) return false;
	
	adrG current = G;
	while (current != nullptr) {
		adrGEdge child = current->edge;
		if (current->info = start) {
			while (child != nullptr) {
				if (child->dist == end) return true;
				child = child->edge_next;
			}
		}
		current = current->next;
	}
}
adrG findG(adrG G, infoG target) {
	if (G == nullptr) cout << "Graph Kosong!!" << endl;
	else {
		adrG current = G;
		while (current != NULL) {
			if (current->info == target) return current;
			current = current->next;
		}
	}
}
void addEdge(adrG& G, infoG x_target, infoG y_target) {
	if (G == nullptr) cout << "Graph Kosong" << endl;
	else {
		adrG x = findG(G, x_target);
		adrG y = findG(G, y_target);

		if (x != nullptr && y != nullptr) {
			adrGEdge dwEdge = allocEdgeG(y->info);
			dwEdge->edge_next = NULL;

			if (x->edge == nullptr) {
				x->edge = dwEdge;
			}
			else {
				dwEdge->edge_next = x->edge;
				x->edge = dwEdge;
			}
		}
	}
}
void printG(adrG& G) {
	if (G == nullptr) cout << "Graph Kosong" << endl;
	else {
		adrG current = G;
		while (current != nullptr) {
			adrGEdge child = current->edge;
			cout << current->info << " : ";
			while (child != NULL) {
				cout << child->dist << " ";
				child = child->edge_next;
			}
			cout << endl;
			current = current->next;
		}
	}
}