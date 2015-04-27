/*********************************************************************
*
*	Written by: Shubham Jain (bugdivine@gmail.com)
*
**********************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _list
{
	int *arr;
	int size, count;
	int head, tail;
} *list;

list Initialize(int s)	// s is the size of list to be declared
{
	list l = (list)malloc(sizeof(list));

	l->arr = (int *)malloc(s*sizeof(int));
	l->size = s;
	l->count = 0;

	return l;
}

int *getElements(list l)
{
	int i = 0;
	int *arr1 = (int *)malloc(l->count*sizeof(int));
	while (i<l->count)
	{
		arr1[i] = l->arr[(i+l->head)%l->size];
		i++;
	}
	return arr1;
}

void printList(list l, char separator)
{
	int i = 0;
	while (i<l->count)
	{
		cout << l->arr[(i+l->head)%l->size] << separator;
		i++;
	}
	return;
}

void Resize(list l, int new_size)
{
	int *arr1 = (int *)malloc((new_size)*sizeof(int));

	int i = 0;
	while (i < l->count)
	{
		arr1[i] = l->arr[(l->head+i)%l->size];
		i++;
	}

	free(l->arr);
	l->arr = arr1;
	l->head = 0;
	l->tail = l->count;
	l->size = new_size;
	return;
}

int ReadAtHead(list l)
{
	if (l->count == 0)
	{
		cout << "Nothing to read!!!" << endl;
		return -1;
	}
	return l->arr[l->head];
}

int RemoveAtHead(list l)
{
	if (l->count == 0)
	{
		cout << "Nothing to delete!!!" << endl;
		return -1;
	}
	else
	{
		int n = l->arr[l->head];
		l->head = (l->head+1)%l->size;

		l->count -= 1;

		return n;
	}
}

int ReadAtTail(list l)
{
	if (l->count == 0)
	{
		cout << "Nothing to read!!!" << endl;
		return -1;
	}

	if (l->tail != 0)
		return l->arr[l->tail-1];
	else
		return l->arr[l->size-1];
}

int RemoveAtTail(list l)
{
	if (l->count == 0)
	{
		cout << "Nothing to delete!!!" << endl;
		return -1;
	}
	else
	{
		l->tail -= 1;
		if (l->tail == -1)
		{
			l->tail += l->size;
		}

		int n = l->arr[l->tail];
		l->count -= 1;
		return n;
	}
}

void AppendAtHead(list l, int n)
{
	if (l->count == l->size)
	{
		Resize(l, l->size+1);
		AppendAtHead(l, n);
		return;
	}
	else
	{
		l->head -= 1;
		if (l->head == -1)
		{
			l->head += l->size;
		}
		l->arr[l->head] = n;

		l->count += 1;

		return;
	}
}

void WriteAtHead(list l, int n)
{
	if (l->count == 0)
	{
		cout << "No element to overwrite!!! Appending..." << endl;
		AppendAtHead(l, n);
		return;
	}
	l->arr[l->head] = n;
	return;
}

void AppendAtTail(list l, int n)
{
	if (l->count == l->size)
	{
		Resize(l, l->size+1);
		AppendAtTail(l, n);
		return;
	}
	else
	{
		l->arr[l->tail] = n;
		l->tail = (l->tail+1)%l->size;

		l->count += 1;
		return;
	}
}

void WriteAtTail(list l, int n)
{
	if (l->count == 0)
	{
		cout << "No element to overwrite!!! Appending..." << endl;
		AppendAtTail(l, n);
		return;
	}
	if (l->tail != 0)
		l->arr[l->tail-1] = n;
	else
		l->arr[l->size-1] = n;
	return;
}

int main()
{
	int choice = 0;
	list l = Initialize(0);
	while (choice != 11)
	{
		cout << "Select one of the following options:" << endl;
		cout << "1. Print all the list elements" << endl;
		cout << "2. Resize" << endl;
		cout << "3. Read the element at head" << endl;
		cout << "4. Remove the element at head" << endl;
		cout << "5. Read the element at tail" << endl;
		cout << "6. Remove the element at tail" << endl;
		cout << "7. Overwrite the element at head" << endl;
		cout << "8. Append an element at head" << endl;
		cout << "9. Overwrite the element at tail" << endl;
		cout << "10. Append an element at tail" << endl;
		cout << "11. Exit" << endl;

		cout << "> ";
		cin >> choice;

		if (choice<=0 || choice>11)
		{
			cout << "Invalid option!!! Select again..." << endl;
			continue;
		}
		if (choice == 1)
		{
			printList(l, ' ');
			cout << endl;
		}
		else if (choice == 2)
		{
			int n;
			cout << "Enter new size:";
			cin >> n;
			Resize(l, n);
		}
		else if (choice == 3)
		{
			int n = ReadAtHead(l);
			if (n != -1)
				cout << n << endl;
		}
		else if (choice == 4)
		{
			int n = RemoveAtHead(l);
			if (n != -1)
				cout << n << endl;
		}
		else if (choice == 5)
		{
			int n = ReadAtTail(l);
			if (n != -1)
				cout << n << endl;
		}
		else if (choice == 6)
		{
			int n = RemoveAtTail(l);
			if (n != -1)
				cout << n << endl;
		}
		else if (choice == 7)
		{
			int n;
			cout << "Enter the new element: ";
			cin >> n;
			WriteAtHead(l, n);
		}
		else if (choice == 8)
		{
			int n;
			cout << "Enter the new element: ";
			cin >> n;
			AppendAtHead(l, n);
		}
		else if (choice == 9)
		{
			int n;
			cout << "Enter the new element: ";
			cin >> n;
			WriteAtTail(l, n);
		}
		else if (choice == 10)
		{
			int n;
			cout << "Enter the new element: ";
			cin >> n;
			AppendAtTail(l, n);
		}
		else if (choice == 11)
		{
			cout << "Bye! Exiting..." << endl;
			break;
		}
	}
}