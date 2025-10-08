//Codes
//1. Find GCD (HCF) and LCM of two numbers
#include <stdio.h>

// Function to find GCD using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find LCM using the relationship LCM * GCD = a * b
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("GCD (HCF) of %d and %d = %d\n", num1, num2, gcd(num1, num2));
    printf("LCM of %d and %d = %d\n", num1, num2, lcm(num1, num2));
    
    return 0;
}

//2. Check Whether a Number is Prime
#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1)
        return 0; // Not prime
    if (n == 2)
        return 1; // Prime
    if (n % 2 == 0)
        return 0; // Even numbers >2 are not prime
    
    int i;
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0; // Divisible by i, not prime
    }
    return 1; // Prime
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
    
    return 0;
}

//3. Find Factorial Using Recursion and Iteration
#include <stdio.h>

// Function to calculate factorial using recursion
long long factorialRecursion(int n) {
    if (n == 0 || n == 1)
        return 1; // Base case
    return n * factorialRecursion(n - 1);
}

// Function to calculate factorial using iteration
long long factorialIteration(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d using recursion = %lld\n", num, factorialRecursion(num));
        printf("Factorial of %d using iteration = %lld\n", num, factorialIteration(num));
    }
    
    return 0;
}

//4. Find Sum of Digits of a Number
#include <stdio.h>

// Function to find sum of digits using recursion
int sumDigitsRecursion(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigitsRecursion(n / 10);
}

// Function to find sum of digits using iteration
int sumDigitsIteration(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int num;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Please enter a non-negative number.\n");
    } else {
        printf("Sum of digits of %d using recursion = %d\n", num, sumDigitsRecursion(num));
        printf("Sum of digits of %d using iteration = %d\n", num, sumDigitsIteration(num));
    }
    
    return 0;
}


//5. Check if a Number is an Armstrong Number
#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, remainder, n = 0;
    double result = 0.0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    temp = num;

    // Find number of digits
    while (temp != 0) {
        temp /= 10;
        ++n;
    }

    temp = num;

    // Calculate sum of powers of digits
    while (temp != 0) {
        remainder = temp % 10;
        result += pow(remainder, n);
        temp /= 10;
    }

    // Check if number is Armstrong
    if ((int)result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
//6. Check if Two Strings Are Anagrams
#include <stdio.h>
#include <string.h>

#define MAX 256

int areAnagrams(char str1[], char str2[]) {
    int count1[MAX] = {0}, count2[MAX] = {0};
    
    for (int i = 0; str1[i]; i++) count1[(int)str1[i]]++;
    for (int i = 0; str2[i]; i++) count2[(int)str2[i]]++;
    
    for (int i = 0; i < MAX; i++)
        if (count1[i] != count2[i])
            return 0;
    return 1;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) printf("Strings are anagrams.\n");
    else printf("Strings are not anagrams.\n");
    return 0;
}


//7. First Non-Repeating Character in a String
#include <stdio.h>
#include <string.h>

#define MAX 256

int main() {
    char str[100];
    int count[MAX] = {0};

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i]; i++) count[(int)str[i]]++;
    for (int i = 0; str[i]; i++)
        if (count[(int)str[i]] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            break;
        }
    return 0;
}

//8. Remove Duplicates from an Array
#include <stdio.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n], i, j, k;

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--;
            } else j++;
        }
    }

    printf("Array after removing duplicates: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}


//9. Find the Second Largest Number in an Array
#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n], largest = INT_MIN, second = INT_MIN;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) printf("No second largest element.\n");
    else printf("Second largest element = %d\n", second);

    return 0;
}

//10. Find All Pairs with a Given Sum
#include <stdio.h>

int main() {
    int n, sum;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &sum);

    printf("Pairs with sum %d:\n", sum);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum)
                printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }
    return 0;
}




//11. Check Balanced Parentheses
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX], stack[MAX];
    int top = -1;
    int balanced = 1;

    printf("Enter expression: ");
    scanf("%s", str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') stack[++top] = '(';
        else if (str[i] == ')') {
            if (top == -1) { balanced = 0; break; }
            else top--;
        }
    }

    if (balanced && top == -1) printf("Parentheses are balanced.\n");
    else printf("Parentheses are not balanced.\n");

    return 0;
}

//12. Reverse a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

struct Node* reverseIterative(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* reverseRecursive(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    struct Node *head = NULL, *temp;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    printf("Original list: ");
    printList(head);

    head = reverseIterative(head);
    printf("Reversed list (Iterative): ");
    printList(head);

    head = reverseRecursive(head);
    printf("Reversed list (Recursive): ");
    printList(head);

    return 0;
}


//13. Find the Middle Node of a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

struct Node* middleNode(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    struct Node *head = NULL, *temp;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    printList(head);

    struct Node* mid = middleNode(head);
    printf("Middle node value: %d\n", mid->data);

    return 0;
}


//14. Merge Two Sorted Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;

    // Example: creating sorted lists
    list1 = createNode(1); list1->next = createNode(3); list1->next->next = createNode(5);
    list2 = createNode(2); list2->next = createNode(4); list2->next->next = createNode(6);

    printf("List 1: "); printList(list1);
    printf("List 2: "); printList(list2);

    struct Node* merged = mergeLists(list1, list2);
    printf("Merged List: "); printList(merged);

    return 0;
}


//15. Implement a Queue Using Two Stacks

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], stack2[MAX], top1 = -1, top2 = -1;

void push(int stack[], int *top, int val) { stack[++(*top)] = val; }
int pop(int stack[], int *top) { return stack[(*top)--]; }

void enqueue(int val) { push(stack1, &top1, val); }

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1) push(stack2, &top2, pop(stack1, &top1));
    }
    if (top2 == -1) {
        printf("Queue is empty!\n"); return -1;
    }
    return pop(stack2, &top2);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    enqueue(40);
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    return 0;
}
