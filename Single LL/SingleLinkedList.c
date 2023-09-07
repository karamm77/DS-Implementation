#include<stdio.h>
#include<stdlib.h>
#include "STD_TYPES.h"

struct Node
{
	sint32 data;
	struct Node* Next;
}; 

void InsertAtEnd(struct Node*head);
struct Node* InsertAtBeginning(struct Node*head);
void Displaylist(struct Node*head);
struct Node* CreateList(void);
uint8 CountNodes(struct Node*head);
struct Node* InsertAfteAnyNode(struct Node*head,uint8 pos);
struct Node* DeleteFromBeginning(struct Node*head);
void DeleteFromEnd(struct Node*head);
struct Node* DeleteFromSpecificPos(struct Node*head,uint8 pos);
sint8 SearchVal(struct Node*head,sint32 Data);
struct Node* ReverseList(struct Node* head); 


int main(void)
{
    struct Node* head = NULL;
    head = CreateList();
    printf("\n");
    Displaylist(head);
    
     head = InsertAtBeginning(head); // Update the head pointer
    Displaylist(head);
	printf("\n");
	uint8 count = CountNodes(head);
	printf("%d\n",count);
	printf("\n");
	sint8 position = SearchVal(head,10);
	printf("in %d\n",position);
	printf("\n");
	head = DeleteFromSpecificPos(head,4);
	Displaylist(head);
	printf("\n");
	head = InsertAfteAnyNode(head,4);
	Displaylist(head); 
	printf("\n");
	printf("After reverse\n");
	head= ReverseList(head);
		Displaylist(head);

	
    
    // Rest of your code...

    return 0;
	
} 
uint8 CountNodes(struct Node*head)
{
	uint8 count = 0;
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		struct Node* temp = head;
		
		while(temp != NULL)
		{

			count++;
			temp = temp -> Next;
		}
	}
	
	
	return count;
}
void Displaylist(struct Node*head)
{
	

	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct Node*temp = head;

		while(temp != NULL)
		{
			printf("%d\t",temp -> data);
			temp = temp -> Next;
		}
		printf("\n");
	}
}

void InsertAtEnd(struct Node*head)
{
	struct Node*NewNode,*temp;
	temp = head;
	
	/*	Dynamic allocate memory for the data	*/
	NewNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the data: ");
	scanf("%d",&NewNode -> data);
	
	
	
	while(temp -> Next != NULL)
	{
		temp = temp -> Next; /* Reaching the last node */
	}
	temp -> Next  = NewNode;	/*	Updating the add val of itoa*/
	NewNode -> Next = NULL;
}
struct Node* InsertAtBeginning(struct Node* head)
{
	sint32 Val;
	if(head == NULL)
	{
		printf("Please enter first Ndoe element: ");
		scanf("%d", &Val);
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		if (newNode == NULL) {
			printf("Memory allocation failed\n");
			return head; // Return the original head
		}

		newNode->data = Val;
		

		// Set the new node as the head
		newNode->Next = NULL;
		head = newNode;
		
	}
	else
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the data: ");
		scanf("%d", &NewNode->data);

		NewNode->Next = head; /* Make the new node point to the first node before insertion */

		head = NewNode; /* Update the reference */
	}

    return head;
}


struct Node* CreateList(void)
{
	uint32 NodeNumber,i;
	sint32 Val;
	struct Node* head = NULL;
	
	printf("Please enter no of nodes: ");
	scanf("%d",&NodeNumber);
	head = InsertAtBeginning(head);
	
	for(i=1;i<NodeNumber;i++)
	{
	
		InsertAtEnd(head);
	}
	
	return head;
}
struct Node* InsertAfteAnyNode(struct Node*head,uint8 pos)
{
	uint8 NoOfNodes,i = 1;
	NoOfNodes = CountNodes(head);
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else if(pos == 1)
	{
		InsertAtBeginning(head);
	}
	else
	{
		if(pos > NoOfNodes)
		{
			printf("Pos is invalid");
		}
		else
		{
			struct Node* temp = head;
			while(i < pos)
			{
				temp = temp -> Next;
				i++;
			}
			struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
			printf("Enter the data: ");
			scanf("%d",&NewNode -> data);
			
			NewNode -> Next = temp -> Next;
			temp -> Next = NewNode;
			
		}
	}
	return head;
}
struct Node* DeleteFromBeginning(struct Node*head)
{
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		struct Node* temp = head;
		head = head -> Next;
		free(temp);
		
	}
	return head;
}

void DeleteFromEnd(struct Node*head)
{
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		struct Node* temp = head;
		struct Node* PrevNode = head;
		while(temp -> Next != NULL)
		{
			PrevNode = temp; /* Equaling the second Node to the first one when the temp reaches the last node, this pointer will then points to the node before it*/
			temp = temp -> Next;
		}
		PrevNode -> Next = NULL;
		free(temp);
	}
}
struct Node* DeleteFromSpecificPos(struct Node*head,uint8 pos)
{
	uint8 NoOfNodes,i = 1;
	NoOfNodes = CountNodes(head);
	if(pos == 1)
	{
		DeleteFromBeginning(head);
	}
	else if(pos > NoOfNodes)
	{
		printf("Invalid pos");
	}
	else
	{
		struct Node* temp = head;
		struct Node* PrevNode = head;
		
		while(i < pos)
		{
			PrevNode = temp;
			temp = temp -> Next;
			i++;
		}
	
		PrevNode -> Next = temp -> Next;
		free(temp);
	}
	return head;
}

sint8 SearchVal(struct Node*head,sint32 Data)
{
	sint8 pos = 1;
	if(head == NULL)
	{
		printf("No list");
		pos = -1;
		return pos ;
	}
	else
	{
		struct Node* temp = head;
		while((temp != NULL) && (temp -> data != Data))
		{
			temp = temp -> Next;
			pos++;
		}
		if(temp == NULL)
		{
			pos = -1;
		}
		else
		{
			/* Nothing */
		}
	}
	return pos;
}
struct Node* ReverseList(struct Node* head)
{
	struct Node*PrevNode,*CurrentNode,*NextNode;
	PrevNode = NULL;
	CurrentNode = head;
	NextNode = head;
	if(head =NULL)
	{
		printf("List is Empty");
	}
	else
	{	
		while(NextNode != NULL)
		{
			NextNode = NextNode->Next;
			CurrentNode->Next = PrevNode;
			PrevNode = CurrentNode;
			CurrentNode = NextNode;
		}
		head = PrevNode;
		
	}
	

	return head;
}