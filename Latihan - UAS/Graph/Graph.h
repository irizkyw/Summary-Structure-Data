#include <iostream>

#include "../Queue/Queue.h"
#include "../Stack/Stack.h"

typedef char infoG;

typedef struct NodeG* adrG;
typedef struct EdgeG* adrGEdge;

struct NodeG {
	infoG info;
	adrG next;
	adrGEdge edge;
};

struct EdgeG {
	infoG dist;
	adrGEdge edge_next;
};

typedef struct {
	adrG head;
	adrG tail;
} QueueG;

void initG(adrG& G);
adrG allocNodeG(infoG data_baru);
void addG(adrG& G, adrG dwData);
bool isConnected(adrG G, infoG start, infoG end);
adrG findG(adrG G, infoG target);
void addEdge(adrG& G, infoG target, infoG to);
void printG(adrG& G);