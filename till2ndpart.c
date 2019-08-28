#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000

char alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l',
'm','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};


typedef struct node
{
	char symbol[3];
	int frequency;
	struct node *next;
	struct node *left;
	struct node *right;
}node;



void frequency(int a[],char ch[])
{
	int i,j;

	i=0;
	while(ch[i]!='\0')
	{
		if(ch[i]>='a')
		{
			char x=ch[i]-'a';
			a[x]++;
		}

		else
		{
			char x=ch[i]-'0';
			a[x+26]++;
		}

		i++;
	}

	// for(i=0;i<36;i++)
	// {
	// 	printf("%c=%d ",alpha[i],a[i]);
	// }

}

node* createNode(int a[],int i)
{
	node* newnode;
	newnode=(node*)malloc(sizeof(node));

	newnode->frequency=a[i];
	newnode->symbol[0]=alpha[i];
	newnode->symbol[1]='\0';

	newnode->left=newnode->right=NULL;
	newnode->next=NULL;

	return newnode;
}

node* insert(node *head , node *p)
{
	node *q;

	if(head==NULL || head->frequency >= p->frequency)
	{
		p->next = head;
		head = p;
	}

	else
	{
		q=head;

		while(q->next!=NULL && q->next->frequency < p->frequency)
		{
			q = q->next;
		}

		p->next = q->next;
		q->next = p;
	}

	return head;
}

node* createSuper(node **head, int i)
{
	node *p;
	p = (node*)malloc(sizeof(node));
	*head;

	p->frequency = (*head)->frequency + (*head)->next->frequency;
	p->next = NULL;
	p->left = *head;
	p->right = (*head)->next;

	p->symbol[0] = 'N';

	if(i<10)
	{
		p->symbol[1] = (char)(i + '0');
		p->symbol[2] = '\0';
	}

	if(i>9)
	{
		p->symbol[1] = (char)(i/10 + '0');
		p->symbol[2] = (char)(i%10 + '0');
		p->symbol[3] = '\0';
	}


	

	*head = (*head)->next->next;

	return p;
}

void display(node *head)
{
	node *p;
	p = head;

	while(p!=NULL)
	{
		printf("%c%c%c = %d \n",p->symbol[0],p->symbol[1],p->symbol[2],p->frequency);
		p = p->next;
	}
}

void preorder(node *head)
{
	if(head!=NULL)
	{
		printf("%c%c%c  ",head->symbol[0],head->symbol[1],head->symbol[2]);
		preorder(head->left);
		preorder(head->right);
	}

	//head = head->next; 
}

int main()
{
	int a[37] = {0},i;
	char s[max];
	node *p,*head=NULL;

	scanf("%s",s);
	frequency(a,s);

	for(i=0;i<36;i++)
	{
		p = createNode( a , i);
		head = insert(head , p);
	}

	for(i=0;i<35;i++)
	{
		p = createSuper(&head , i+1);
		head = insert(head , p);
	}

	//display(head);
	preorder(head);

	return 0;
}
