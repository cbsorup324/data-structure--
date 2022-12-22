#include<stdio.h>
#include <stdlib.h>
typedef struct Node
{

	int data;
	int power;
	struct Node * next;
}Node;
Node * getNode(int data, int power)
{
	Node * ref = (Node * ) malloc(sizeof(Node));
	if (ref == NULL)
	{
		return NULL;
	}
	ref->data = data;
	ref->power = power;
	ref->next = NULL;
	return ref;
}

void updateRecord(Node * ref, int data, int power)
{
	ref->data = data;
	ref->power = power;
}
typedef struct AddPolynomial
{

	struct Node * head;
}AddPolynomial;
AddPolynomial * getAddPolynomial()
{

	AddPolynomial * ref = (AddPolynomial * ) malloc(sizeof(AddPolynomial));
	if (ref == NULL)
	{ 
		return NULL;
	}
	ref->head = NULL;
	return ref;
}
void display(AddPolynomial * ref)
{
	if (ref->head == NULL)
	{
		printf("Empty Polynomial ");
	}
	printf(" ");
	Node * temp = ref->head;
	while (temp != NULL)
	{
		if (temp != ref->head)
		{
			printf(" + %d", temp->data);
		}
		else
		{
			printf("%d",temp->data);
		}
		if (temp->power != 0)
		{
			printf("x^%d", temp->power);
		}
		temp = temp->next;
	}
	printf("\n");
}
void addNode(AddPolynomial * ref, int data, int power)
{
	if (ref->head == NULL)
	{
		ref->head = getNode(data, power);
	}
	else
	{
		Node * node = NULL;
		Node * temp = ref->head;
		Node * location = NULL;
		while (temp != NULL && 
               temp->power >= power)
		{
			location = temp;
			temp = temp->next;
		}
		if (location != NULL && 
            location->power == power)
		{

			location->data = location->data + data;
		}
		else
		{
			node = getNode(data, power);
			if (location == NULL)
			{
				node->next = ref->head;
				ref->head = node;
			}
			else
			{
				node->next = location->next;
				location->next = node;
			}
		}
	}
}

Node * addTwoPolynomials(AddPolynomial * ref, 
                         AddPolynomial * other)
{
	Node * result = NULL;
	Node * tail = NULL;
	Node * node = NULL;
	Node * first = ref->head;
	Node * second = other->head;
	// Execute loop until when polynomial are exist
	// And add two polynomial. 
	// Process takes O(n) time.
	while (first != NULL || second != NULL)
	{
		// Create node with default value
		node = getNode(0, 0);
		if (result == NULL)
		{
			// When first resultant node
			result = node;
		}
		if (first != NULL && second != NULL)
		{
			if (first->power == second->power)
			{
				// When the polynomial node power are same
				updateRecord(node, first->data + second->data, 
                             first->power);
				first = first->next;
				second = second->next;
			}
			else if (first->power > second->power)
			{
				// When first polynomial power are larger
				updateRecord(node, first->data, first->power);
				first = first->next;
			}
			else
			{
				// When second polynomial power are larger
				updateRecord(node, second->data, second->power);
				second = second->next;
			}
		}
		else if (first != NULL)
		{
			// When first polynomial are not empty 
			// Update the current node information
			updateRecord(node, first->data, first->power);
			first = first->next;
		}
		else
		{
			// When second polynomial are not empty 
			updateRecord(node, second->data, second->power);
			second = second->next;
		}
		if (tail == NULL)
		{
			tail = node;
		}
		else
		{
			// Add new node at end of resultant polynomial
			tail->next = node;
			tail = node;
		}
	}
	// return first node
	return result;
}
int main()
{
	AddPolynomial * poly1 = getAddPolynomial();
	AddPolynomial * poly2 = getAddPolynomial();
	AddPolynomial * result = getAddPolynomial();
	// Add node in polynomial poly1
	addNode(poly1, 9, 3);
	addNode(poly1, 4, 2);
	addNode(poly1, 3, 0);
	addNode(poly1, 7, 1);
	addNode(poly1, 3, 4);
	// Add node in polynomial poly2
	addNode(poly2, 7, 3);
	addNode(poly2, 4, 0);
	addNode(poly2, 6, 1);
	addNode(poly2, 1, 2);
	// Display Polynomial nodes
	printf("\n Polynomial A\n");
	display(poly1);
	printf(" Polynomial B\n");
	display(poly2);
	result->head = addTwoPolynomials(poly1, poly2);
	// Display calculated result
	printf(" Result\n");
	display(result);
}