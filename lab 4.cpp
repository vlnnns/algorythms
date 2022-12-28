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
        list.first->next = list.last;
        list.first->prev = list.last;
        list.last = list.first;
    }else{
        TListItem *newItem = new TListItem;
        newItem->value = val;
        newItem->next = list.first;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
    }
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

    int sum = 1;
    while (first_m.first != first_m.last){
        sum *= first_m.first->value;

    }

    if (second_m.first != second_m.last){
        a2 = second_m.first->value;
        second_m.first = second_m.first->next;
        x2 = second_m.first->value;
        second_m.first = second_m.first->next;
        b2 = second_m.first->value;
    }


    pol1 = a1 * (pow(x1, b1));
    pol2 = a2 * (pow(x2, b2));

    result = pol1/pol2;

    cout << "Result: " << result;

    return 0;
}
