#include "Globals.h"
using namespace std;

int main()
{
    /** Queue **/
    infoQ databaru;
    ListQ Q;
    adrQ delQ;
    initQ(Q);
    enQ(Q, allocQ('C'));
    enQ(Q, allocQ('B'));
    enQ(Q, allocQ('A'));
    showQ(Q);
    cout << "Deque";
    deQ(Q, delQ);
    cout << "Deleted : " << delQ->info << endl;
    showQ(Q);
    /**End Queue**/
    cout << "\n --------------------- \n";
    /** Stack **/
    Stack S;
    initS(S);
    push(S, 'A');
    push(S, 'B');
    push(S, 'C');
    push(S, 'D');
    push(S, 'E');
    showS(S);
    Stack temp;
    int posC = findIndexS(S,'C');
    cout << "Pop C : Posisi pada "<< posC << endl;
    int push_i;
    int temp_i = 0;
    int pop_i = S.top;

    initS(temp);
    while (pop_i >= posC) {
        infotypeS delS = pop(S);
        push(temp, delS);
        pop_i--;
        temp_i++;
    }

    infotypeS delS = pop(temp);
    if (delS == 'C') cout << "C terhapus" << endl;

    while (S.top <= temp_i - 1) {
        infotypeS delS = pop(temp);
        push(S, delS);
    }
    showS(S);
    /** End Stack**/
    /** Graph **/
    adrG Graph, startBFS;
    initG(Graph);
    startBFS = allocNodeG('A');
    addG(Graph, startBFS);
    addG(Graph, allocNodeG('B'));
    addG(Graph, allocNodeG('C'));
    addG(Graph, allocNodeG('D'));
    addG(Graph, allocNodeG('E'));
    addG(Graph, allocNodeG('F'));
    addEdge(Graph, 'A', 'B');
    addEdge(Graph, 'B', 'C');
    addEdge(Graph, 'C', 'E');
    addEdge(Graph, 'D', 'E');
    addEdge(Graph, 'E', 'F');
    addEdge(Graph, 'G', 'D');
    printG(Graph);
    /** End Graph **/
    cout << "\n --------------------- \n";

    /** Tree**/
    AdrNodeT root;
    initT(root);
    int data[13] = { 14,5,3,9,29,17,6,23,10,15,21,8,26 };
    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
        insertNodeT(root, allocNodeT(data[i]));
        cout << data[i] << " ";
    }

    cout << "\n\nPre - Order\t:";
    preOrder(root);
    cout << "\nIn - Order\t:";
    inOrder(root);
    cout << "\nPost - Order\t:";
    postOrder(root);
    /** End Tree**/
}