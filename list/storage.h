/*********************************************************************
*
*	Written by: Shubham Jain (bugdivine@gmail.com)
*
**********************************************************************/

typedef struct _list
{
	int *arr;
	int size, count;
} *list;

list Initialize(int s);	// s is the size of list to be declared

int *getElements(list l);

void printList(list l, char separator);

void Resize(list l, int new_size);

int ReadAtHead(list l);

int RemoveAtHead(list l);

int ReadAtTail(list l);

int RemoveAtTail(list l);

void AppendAtHead(list l, int n);

void WriteAtHead(list l, int n);

void AppendAtTail(list l, int n);

void WriteAtTail(list l, int n);