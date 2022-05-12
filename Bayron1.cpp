// C++ Programming Assignment 1
// Programmed by: Sean Gabriel Bayron



#include<iostream>
#include <math.h>
using namespace std;

// I implemented linked list concepts in my program since arrays were not allowed.
struct Node {
   int data;
   struct Node *next;
};

// called the functions along with its parameters to be used in the main section of the program. 
// their respective codes are written below the main section.
void newnum(struct Node** head_ref, int data); // adds item to linked list
float average(struct Node* head);   // solves for avg
int largest_num(struct Node* head); // finds the largest item
int smallest_num(struct Node* head); // finds the smallest item


int main()
{
    struct Node* head = NULL;
    int num = 1;
    cout <<"\nC++ Programming Assignment 1\n";
    cout <<"Submitted by:  Sean Gabriel Bayron";
    cout <<"\n--------------------------------------------------------------------------------------------------------------------------------------\n";
    cout <<"\n\nThis program will ask the user to input various numbers (positive or negative but not zero) and perform basic statistics on these numbers.\n";

    while(num != 0){
        cout <<"\nInput an integer: ";
        cin >> num;
        newnum(&head, num);
    }
    cout <<"\nLargest = "<<largest_num(head);
    cout <<"\n\nSmallest = "<<smallest_num(head);
    cout <<"\n\nAverage = "<<average(head);
    

    
  return 0;
}


// function that adds item to linked list
void newnum(struct Node** head_ref, int data)
{
    /* allocates node for new item */
    struct Node* new_node = new Node;
  
    /* puts in the data in the node*/
    new_node->data = data;
  
    /* link the old list to the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// function to iteratively find the avg of items in linked list
float average(struct Node* head)
{
    int count = 0; // Initialize variables
    int sum = 0;
    float avg = 0.0;
  
    struct Node* current = head; // Initialize current
    while (current != NULL) {   // while current is not null, 
        count++;                // it will add 1 to count every iteration
        sum += current->data;
        current = current->next;
    }
  
    // calculates the average
    avg = (float) sum / (count-1); // count is minus 1 because the 0 or the last element to be included isn't included for computing the average
  
    return avg;
}

// function to find largest element in linked list
int largest_num(struct Node* head)
{
    int largest = INT_MIN; // initialize variable and set it minimum value of variable to -2147483647 - 1
  
    // Check while head not equal to NULL
    while (head != NULL) {
  
        // If the value of the variable largest_num is less than head->data, assign value of head->data to largest or replace it with the new value
        // else if not, point to next node.
        if (largest < head->data)
            largest = head->data;
        head = head->next;
    }
    return largest;
}
  
// function to find largest element in linked list
int smallest_num(struct Node* head)
{
    int smallest = INT_MAX; // initialize variable and set it maximum value of variable to 2147483647
  
    // Check while head not equal to NULL
    while (head != NULL) {
  
       // If the value of the variable smallest_num is less than head->data, assign value of head->data to largest or replace it with the new value
        // else if not, point to next node.
        if (smallest > head->data)
            smallest = head->data;
  
        head = head->next;
    }
    return smallest;
}