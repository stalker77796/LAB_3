/**@file  stack_lab.cpp*/
#include <iostream>
using namespace std;

struct STACK
{
	int value;
	STACK *pNext;
};// stack_t, node_t;
//LIST *pHead;
///������� ���������� �������� x � �������� ������� pos ������������ ������
int EmptySTACK(STACK **pHead)       /// func  empty 
{
	return *pHead == NULL;
}

void AddSTACK(STACK **pHead, int value)   /// func add
{
	STACK *pNode = new STACK;
	/* printf("%p created\n", node); */

	/* ������������ ������������� ����� */
	pNode->value = value;

	/* ������������ �������� ����� */
	pNode->pNext = NULL;

	/* ���� ���� �� ����, �� ������� ������ ��������� �� ���������� ������� */
	if (!EmptySTACK(pHead))
		pNode->pNext = *pHead;
	(*pHead) = pNode;
	cout << "\n������� �������� � ����...\n\n";
}

void DeleteSTACK(STACK **pHead)                  ///delete stack
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "\n���� ����! ������� ������!\n" << endl;
	/* ���� ���� ����, �� ������� ������ �� ���� */
	if (!EmptySTACK(pHead))
	{
		/* ��� ��� ��������� ������� �����, �� �������� ����� ���������� ��������������� */
		pNode = *pHead;
		*pHead = (*pHead)->pNext;

		delete pNode;
		/* printf("%p deleted\n", node); */

		pNode = NULL;
		cout << "\n������� ������ �� �����...\n\n";
	}
}

void PrintSTACK(STACK **pHead)              /// print stack
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "���� ����!" << endl;
	else
	{
		cout << "�������� �����: ";
		for (pNode = *pHead; pNode != NULL; pNode = pNode->pNext)
			cout << pNode->value << " -> ";
		cout << "\b\b\b   \n";
	}
}

int main()                /// main func
{
	STACK *s = NULL;
	setlocale(LC_ALL, "RUS");
	int value, position, x, n;
	cout << "������� ���������� �������� �� ������: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ������" << endl;
		cout << "\n����� �������� > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "�������� > "; cin >> value;
			AddSTACK(&s, value); break;
		case 2:
			//cout << "������� > "; cin >> position;
			DeleteSTACK(&s); break;
		case 3:
			PrintSTACK(&s);
			break;

		}
	}
	system("pause");
}