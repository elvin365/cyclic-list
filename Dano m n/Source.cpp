#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
};
Node* push(Node* head, int data)
{
	Node* a = (Node*)malloc(sizeof(Node));
	a->data = data;
	a->next = head;
	return a;
}
Node* pop(Node* head)
{
	if (!head)
		return NULL;
	Node* k = head;
	head = head->next;
	Node* f = k;
	while (f->next != k)
		f = f->next;
	free(k);
	f->next = head;
	return head;
}
void TheEnd(Node* a)
{
	
	Node* k = a;
	while (k->next!=NULL)
	{
		k = k->next;
	}
	k->next = a;
}

int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	scanf("%d", &m);
	scanf("%d", &n);
	Node *a = NULL;

	for (i = 0; i < n; i++)
		a = push(a, i);
	TheEnd(a); // круг
	while (a->next != a) {
		for (m = 0; m < 5; m++)//
		{
			a = a->next;
		}
		//printf("\n%d\n", a->data);
		a= pop(a);
	}
	printf("%d", a->data);
	_getch();
		return 0;
}
