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

class CircularList {
public:

    CircularList(){
        last = 0;
    }

    void InsertFirst(int x) {
        ListNode* temp = new ListNode(x);
        if (last == 0) {
            last = temp;
            last->link = last;
        }
        else {
            ListNode* start = last->link;
            temp->link = start;
            last->link = temp;
        }
            
    }
    void InsertLast(int x) {
        ListNode* temp = new ListNode(x);
        if (last == 0) {
            last = temp;
            last->link = last;
        }
        else {
            ListNode* start = last->link;
            temp->link = start;
            last->link = temp;
            last = temp;
        }
    }
    int DeleteFirst() {
        int x = last->link->data;
        ListNode* tempStart = last->link->link;
        last->link = tempStart;
        return x;
    }
    int DeleteLast() {
        ListNode* temp = last;
        while (temp->link != last) {
            temp = temp->link;
        }
        int x = last->data;     
        temp->link = last->link;
        last = temp;
        return x;
    }
    void PrintList() {
        ListNode* start = last->link;
        while (start != last) {
            cout << start->data << " ";
            start = start->link;
        }
        cout << last->data << endl;
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