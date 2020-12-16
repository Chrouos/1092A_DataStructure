#include <iostream>
using namespace std;

class ListNode
{
public:
    ListNode(int a) { data = a; link = 0; }
private:
    int data;
    ListNode* link;
    friend class CircularList;
};

class CircularList
{
public:
    CircularList() {
        last = 0;
    }

    void InsertFirst(int x) {
        ListNode* newOne = new ListNode(x);
        if (last == 0) {
            last = newOne;
            last->link = last;
        }
        else {
            ListNode* temp = last->link;
            last->link = newOne;
            newOne->link = temp;
        }
    }
    void InsertLast(int x) {
        ListNode* newOne = new ListNode(x);
        if (last == 0) {
            last = newOne;
            last->link = last;
        }
        else {
            ListNode* temp_f = last->link;
            last->link = newOne;
            newOne->link = temp_f;
            last = newOne;
        }
    }
    int DeleteFirst() {
        ListNode* temp_f = last->link->link;
        int num = last->link->data;
        last->link = temp_f;
        return num;
    }
    int DeleteLast() {
        ListNode* temp_f = last->link;
        ListNode* temp_l = last;
        while (temp_l->link != last) {
            temp_l = temp_l->link;
        }
        int num = last->data;
        last = temp_l;
        temp_l->link = temp_f;
        return num;
       
    }
    void PrintList() {

        ListNode* start = last->link;
        for (; start != last ; start = start->link) {
            cout << start->data << " ";
        }
        cout << last->data;

    }

private:
    ListNode* last;
};

int main(int argc, char* argv[])
{
    CircularList list;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; list.InsertFirst(input); }
    for (cin >> times; times > 0; times--) list.DeleteFirst();
    for (cin >> times; times > 0; times--) { cin >> input; list.InsertLast(input); }
    for (cin >> times; times > 0; times--) list.DeleteLast();
    list.PrintList();
}