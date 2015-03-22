/** @file LIST.cpp */
#include <iostream>
using namespace std;

struct LIST
{
	int data; /// Dannye 
	LIST *pNext;  /// Ykazatel  
};
LIST *pHead;
//������� ���������� �������� x � �������� ������� pos ������������ ������
void AddLIST(int value, int position)         ///add list func
{
	LIST *pNode = new LIST;
	pNode->data = value;
	if (position <= 1 || pHead == NULL)
	{
		pNode->pNext = pHead;
		pHead = pNode;
	}
	else
	{
		LIST *pA = pHead;
		for (int i = 1; i < position - 1; i++)
		{
			if (pA->pNext != NULL)
				pA = pA->pNext;
		}
		pNode->pNext = pA->pNext;
		pA->pNext = pNode;
	}
	cout << "\n������� �������� � ������...\n\n";
}
//�������� �������� � �������� ������� 
int DeleteLIST(int position)                 ///delete list func
{
	if (pHead == NULL) { cout << "\n������ ����! ������� ������!\n\n"; return 0; }
	LIST *pA = pHead, *pB;
	int i = 0;
	while (pA != NULL)
	{
		pA = pA->pNext;
		i++;
	}
	if (position > i || position < 1)
	{
		cout << endl << "����� ������� � ������ ���!" << endl << endl;
	}//�������� �� ���-� �������        
	else
	{
		if (position == 1)
		{
			pA = pHead->pNext;//���� ��-� ������
			pHead = pA;
		}
		if (position > 1)
		{
			i = 1;//���� ��-� �� ������
			pA = pHead;
			while (i != position - 1)
			{
				i++;
				pA = pA->pNext;
			}
			pB = pA->pNext;
			pA->pNext = pB->pNext;//��������
			delete pB;
		}
		cout << "\n������� ������ �� ������...\n\n";
	}
}
// ��������������� ������� ��� ������ ������
void PrintLIST()                     /// output list print func
{
	if (pHead == NULL) cout << "������ ����!\n";
	else
	{
		LIST *pA = pHead;
		cout << "�������� ������: ";
		while (pA != NULL)
		{
			//cout << pA -> data <<' ';
			//pA = pA -> pNext;
			cout << pA->data << " -> ";

			pA = pA->pNext;
		}
		cout << "\b\b\b  \n";
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int value, position, x, n;
	cout << "������� ���������� �������� �� �������: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3 ������ ������ " << endl;
		cout << "\n����� �������� > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "�������� > "; cin >> value;
			cout << "������� > "; cin >> position;
			AddLIST(value, position); break;
		case 2:
			cout << "������� > "; cin >> position;
			DeleteLIST(position); break;
		case 3:
			cout << "������ ������ "; PrintLIST();
			break;
		}
	}
	system("pause");
}
