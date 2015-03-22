/**@file  stack_lab.cpp*/
#include <iostream>
using namespace std;

struct STACK
{
	int value;
	STACK *pNext;
};// stack_t, node_t;
//LIST *pHead;
///функция добавления элемента x в заданную позицию pos односвязного списка
int EmptySTACK(STACK **pHead)       /// func  empty 
{
	return *pHead == NULL;
}

void AddSTACK(STACK **pHead, int value)   /// func add
{
	STACK *pNode = new STACK;
	/* printf("%p created\n", node); */

	/* формирование информативной части */
	pNode->value = value;

	/* формирование адресной части */
	pNode->pNext = NULL;

	/* если стек не пуст, то вершина должна указывать на предыдущий элемент */
	if (!EmptySTACK(pHead))
		pNode->pNext = *pHead;
	(*pHead) = pNode;
	cout << "\nЭлемент добавлен в стек...\n\n";
}

void DeleteSTACK(STACK **pHead)                  ///delete stack
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "\nСтек пуст! Удалять нечего!\n" << endl;
	/* Если стек пуст, то удалять ничего не надо */
	if (!EmptySTACK(pHead))
	{
		/* Так как удаляется вершина стека, то адресную часть необходимо скорректировать */
		pNode = *pHead;
		*pHead = (*pHead)->pNext;

		delete pNode;
		/* printf("%p deleted\n", node); */

		pNode = NULL;
		cout << "\nЭлемент удален из стека...\n\n";
	}
}

void PrintSTACK(STACK **pHead)              /// print stack
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "Стек пуст!" << endl;
	else
	{
		cout << "Элементы стека: ";
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
	cout << "Введите количество операций со стеком: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Печать" << endl;
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			AddSTACK(&s, value); break;
		case 2:
			//cout << "Позиция > "; cin >> position;
			DeleteSTACK(&s); break;
		case 3:
			PrintSTACK(&s);
			break;

		}
	}
	system("pause");
}