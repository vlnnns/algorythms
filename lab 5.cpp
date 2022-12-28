#include <iostream>
#include <cmath>

using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};

struct TList{
    TListItem *first, *last;
};

TList initList(){
    TList e;
    e.first = NULL;
    e.last = NULL;
    return e;
};

void addListItem(TList &list, int val){
    if(list.first == NULL){
        list.first = new TListItem;
        list.first->value = val;
        list.first->next = NULL;
        list.first->prev = NULL;
        list.last = list.first;
    }else{
        TListItem *newItem = new TListItem;
        newItem->value = val;
        newItem->next = NULL;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
    }
}

struct TListIterator{
    TListItem *pointer;
};

TListIterator initTListIterator(){
    TListIterator tmp;
    tmp.pointer = NULL;
    return tmp;
}

int isValid(TListIterator it){
    return it.pointer != NULL;
}

void moveNext(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->next;
    }
}

void movePrev(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->prev;
    }
}

int getValue(const TListIterator &it){
    if(isValid(it)){
        return it.pointer->value;
    }
    return 0;
}

void setValue(const TListIterator &it, int newValue){
    if(isValid(it)){
        it.pointer->value = newValue;
    }
}

TListIterator getBegin(TList l){
    TListIterator tmp;
    tmp.pointer = l.first;
    return tmp;
}
TListIterator getEnd(TList l){
    TListIterator tmp;
    tmp.pointer = l.last;
    return tmp;
}

int main() {
    TList first_m = initList();
    TList second_m = initList();
    int y1, y2;
    int a1 = 0, x1 = 0, b1 = 0, a2 = 0, x2 = 0, b2 = 0;
    float pol1, pol2, result;

    cout << "Enter elements of first polinomial: ";
    for(int i = 0; i<3; i++){
        cin >> y1;
        addListItem(first_m, y1);
    }
    cout << "Enter elements of second polinomial: ";
    for(int i = 0; i<3; i++){
        cin >> y2;
        addListItem(second_m, y2);
    }

    TListIterator it1  = getBegin(first_m);
    TListIterator it2  = getBegin(second_m);

    if (isValid(it1)){
        a1 = getValue(it1);
        moveNext(it1);
        x1 = getValue(it1);
        moveNext(it1);
        b1 = getValue(it1);
    }

    if (isValid(it2)){
        a2 = getValue(it2);
        moveNext(it2);
        x2 = getValue(it2);
        moveNext(it2);
        b2 = getValue(it2);
    }


    pol1 = a1 * (pow(x1, b1));
    pol2 = a2 * (pow(x2, b2));

    result = pol1/pol2;

    cout << "Result: " << result;

    return 0;
}
