#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a, int b) { coef = a; exp = b; link = 0; }
private:
	int coef;
	int exp;
	ListNode* link;
	friend class PolyList;
};

class PolyList
{
public:
	void InsertLast(int, int);
	void Add(PolyList&);
	void PrintList();
private:
	ListNode* first = 0;
	ListNode* last = 0;
};

void PolyList::InsertLast(int coef, int exp) {
	ListNode* newNode = new ListNode(coef, exp);
	if (last == 0)
		first = newNode;
	else
		last->link = newNode;
	last = newNode;
}


//exp ����, coef �Y��
void PolyList::Add(PolyList& b)
{
	ListNode* start_a = first, * start_b = b.first;
	bool check;
	while (start_b != 0) {

		check = 1;
		
		start_a = first;
		// �NA�]�L�@�M
		while (start_a != 0) {
			//�p�G B�����ơAA�]���A�N�Y�Ƭۥ[�i�h
			if (start_b->exp == start_a->exp) {
				start_a->coef = start_b->coef + start_a->coef;
				check = 0;
				break;
			}
			start_a = start_a->link;
		}

		
		// �p�GB�����ơAA�S���A�N�i�J�H�U���q
		if (check) {
			start_a = first;
			ListNode* prev = start_a;
			ListNode* newOne = new ListNode(start_b->coef, start_b->exp);
			while (start_a != 0) {
				//�p�G B������ �p�� A�A�N�U�@��
				if (start_b->exp > start_a->exp) {
					if (start_a == first) {
						newOne->link = start_a;
						first = newOne;
					}
					else {
						prev->link = newOne;
						newOne->link = start_a;
					}
					check = 0;
					break;
				}
				prev = start_a;
				start_a = start_a->link;
			}		
		}
		if (check) InsertLast(start_b->coef, start_b->exp);
		start_b = start_b->link; // �qB���}�l�@�����U�~��
	}
	
}

void PolyList::PrintList()
{
	ListNode* start = first;
	for (; start != 0; start = start->link) {
		cout << start->coef << "x^" << start->exp << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	PolyList A, B;
	int times, input, input2;
	for (cin >> times, times /= 2; times > 0; times--) { cin >> input >> input2; A.InsertLast(input, input2); }
	for (cin >> times, times /= 2; times > 0; times--) { cin >> input >> input2; B.InsertLast(input, input2); }
	A.Add(B);
	A.PrintList();
}