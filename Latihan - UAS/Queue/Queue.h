struct infoQ {
	int nomor;
};

typedef struct Queue* adrQ;

struct Queue {
	infoQ info;
	adrQ next;
};

struct ListQ {
	adrQ head;
};
/** First in, first out**/
void initQ(ListQ& Q);
adrQ allocQ(int databaru);
void enQ(ListQ& Q, adrQ data_baru);
void deQ(ListQ& Q, adrQ& del);

void showQ(ListQ Q);