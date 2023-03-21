#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>
using namespace std;

struct Node {
	int info;
	Node* pNext;
};
typedef struct Node NODE;
//dinh nghia kieu du lieu danh sach
struct List {
	Node* pHead;
	Node* pTail;
};
typedef struct List LIST;
//khoi tao danh sach
void Init(LIST&);
int IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
int Nhap(LIST&);
void InterchangeSort(LIST&);
void Xuat(LIST);
int DemNode(LIST);

int main() {
	List l;
	Nhap(l);
	InterchangeSort(l);
	Xuat(l);
	return 0;
}

void Init(LIST& l) {
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l) {
	if (l.pHead == NULL) {
		return 0;
	}
	return 1;
}

NODE* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddTail(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;

	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int Nhap(List& l) {
	Init(l);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		Node* p = GetNode(x);
		if (p != NULL)
		{
			AddTail(l, p);
		}
	}
	return 1;
}

void InterchangeSort(LIST& l) {
	for (Node* p = l.pHead; p->pNext != NULL; p = p->pNext) {
		for (Node* q = p->pNext; q != NULL; q = q->pNext) {
			if (p->info > q->info) {
				swap(p->info, q->info);
			}
		}
	}
}

void Xuat(LIST l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}

int DemNode(LIST l) {
	Node* p = l.pHead;
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->pNext;
	}
	return count;
}