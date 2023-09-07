#include <stdlib.h>
#include <stdio.h>
#include "STD_TYPES.h"

struct Node
{
	sint32 data;
	struct Node* Next;
};


struct Node* CreateStack(struct Node* Top);
struct Node* PushToStack(struct Node* Top);
struct Node* PopFromStack(struct Node* Top);
void PEEKFromStack(struct Node* Top);
void DiplayStack(struct Node* Top);
int main()
{
	struct Node* Top = NULL;
	Top=CreateStack(Top);
	DiplayStack(Top);
	
	Top = PushToStack(Top);
	Top = PushToStack(Top);
	Top = PushToStack(Top);
	Top = PushToStack(Top);
	
	DiplayStack(Top);
	
	PEEKFromStack(Top);
	Top = PopFromStack(Top);
	DiplayStack(Top);

	
	
}

struct Node* CreateStack(struct Node* Top)
{
	//struct Node* Top = NULL;
	Top = PushToStack(Top); /* The firat Node */
}
struct Node* PushToStack(struct Node* Top)
{
	sint32 data;
	if(Top == NULL)
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the data you want to push: ");
		scanf("%d",&data);
		NewNode -> data = data;
		NewNode -> Next = NULL;
		
		Top = NewNode;
	}
	else
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the data you want to push: ");
		scanf("%d",&data);
		NewNode -> data = data;
		NewNode -> Next = Top;
		
		Top = NewNode;
	}
	return Top;
}
struct Node* PopFromStack(struct Node* Top)
{
	if(Top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		struct Node* temp = Top;
		Top = Top -> Next;
		free(temp);
	}
	return Top;
}
void PEEKFromStack(struct Node* Top)
{
	if(Top == NULL)
	{
		printf("Stack is Empty\n");
	}
	
	printf("Top data is: %d\n",Top->data);
}

void DiplayStack(struct Node* Top)
{
	if(Top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		struct Node* temp = Top;
		while(temp != NULL)
		{
			printf("%d\t",temp -> data);
			temp = temp -> Next;
		}
		printf("\n");
	}
}