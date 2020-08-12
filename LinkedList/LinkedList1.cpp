// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

Node* removeDuplicates(Node *root);

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}// } Driver Code Ends


/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to remove duplicates from the linked list
// root: root of the linked list
#include<bits/stdc++.h>
using namespace std;
Node * removeDuplicates( Node *head) {
    map<int,int>m;
    Node* temp=head;
    while(temp){
        m[temp->data]++;
        temp=temp->next;
    }
    temp=head;
    Node* prev=NULL;
    while(temp){
        if(m[temp->data]>0){
            m[temp->data]=0;
        }
        else{
            int data=temp->data;
            temp=temp->next;
            while(temp && data==temp->data)
               temp=temp->next;
            prev->next=temp;
            continue;
        }
        prev=temp;
        if(temp)
            temp=temp->next;
    }
    return head;
}
