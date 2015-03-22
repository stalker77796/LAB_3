/** @file LIST.cpp */
#include <iostream>
using namespace std;

struct LIST
{
	int data; /// Dannye 
	LIST *pNext;  /// Ykazatel  
};
LIST *pHead;
//функция добавления элемента x в заданную позицию pos односвязного списка
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
	cout << "\nЭлемент добавлен в список...\n\n";
}
//удаление элемента с заданной позиции 
int DeleteLIST(int position)                 ///delete list func
{
	if (pHead == NULL) { cout << "\nСписок пуст! Удалять нечего!\n\n"; return 0; }
	LIST *pA = pHead, *pB;
	int i = 0;
	while (pA != NULL)
	{
		pA = pA->pNext;
		i++;
	}
	if (position > i || position < 1)
	{
		cout << endl << "Такой позиции в списке нет!" << endl << endl;
	}//проверка на сущ-е позиции        
	else
	{
		if (position == 1)
		{
			pA = pHead->pNext;//если эл-т первый
			pHead = pA;
		}
		if (position > 1)
		{
			i = 1;//если эл-т не первый
			pA = pHead;
			while (i != position - 1)
			{
				i++;
				pA = pA->pNext;
			}
			pB = pA->pNext;
			pA->pNext = pB->pNext;//сдвигаем
			delete pB;
		}
		cout << "\nЭлемент удален из списка...\n\n";
	}
}
// вспомогательная функция для вывода списка
void PrintLIST()                     /// output list print func
{
	if (pHead == NULL) cout << "Список пуст!\n";
	else
	{
		LIST *pA = pHead;
		cout << "Элементы списка: ";
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
	cout << "Введите количество операций со списком: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3 Печать списка " << endl;
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			cout << "Позиция > "; cin >> position;
			AddLIST(value, position); break;
		case 2:
			cout << "Позиция > "; cin >> position;
			DeleteLIST(position); break;
		case 3:
			cout << "Печать списка "; PrintLIST();
			break;
		}
	}
	system("pause");
}
