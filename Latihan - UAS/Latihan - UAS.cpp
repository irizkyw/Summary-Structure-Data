#include "Globals.h"
using namespace std;

int main()
{
    /** Queue **/
    infoQ databaru;
    ListQ Q;
    adrQ delQ;
    initQ(Q);
    enQ(Q, allocQ(3));
    enQ(Q, allocQ(2));
    enQ(Q, allocQ(1));
    showQ(Q);
    cout << "Deque";
    deQ(Q, delQ);
    cout << "Deleted : " << delQ->info.nomor << endl;
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
}