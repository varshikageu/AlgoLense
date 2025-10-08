//Codes
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 1. GCD & LCM
void findGcdLcm() {
    int a, b, temp, gcd, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int n1 = a, n2 = b;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    lcm = (n1 * n2) / gcd;
    printf("GCD = %d, LCM = %d\n", gcd, lcm);
}

// 2. Prime Number Check
void checkPrime() {
    int n, i, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n <= 1) {
        printf("Not Prime\n");
        return;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Prime\n");
    else
        printf("Not Prime\n");
}

// 3. Factorial
void findFactorial() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    printf("Factorial = %lld\n", fact);
}

// 4. Sum of Digits
void sumOfDigits() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("Sum of digits = %d\n", sum);
}

// 5. Armstrong Number
void checkArmstrong() {
    int n, temp, digit, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }
    if (sum == n)
        printf("Armstrong Number\n");
    else
        printf("Not Armstrong\n");
}

// 6. Anagram Check
void checkAnagram() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    if (strlen(s1) != strlen(s2)) {
        printf("Not Anagram\n");
        return;
    }

    int freq[256] = {0};
    for (int i = 0; s1[i]; i++) {
        freq[s1[i]]++;
        freq[s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("Not Anagram\n");
            return;
        }
    }
    printf("Anagram Strings\n");
}

// 7. First Non-Repeating Character
void firstNonRepeatingChar() {
    char s[200];
    printf("Enter string: ");
    scanf("%s", s);
    int freq[256] = {0};
    for (int i = 0; s[i]; i++)
        freq[(unsigned char)s[i]]++;

    for (int i = 0; s[i]; i++) {
        if (freq[(unsigned char)s[i]] == 1) {
            printf("First non-repeating character: %c\n", s[i]);
            return;
        }
    }
    printf("No non-repeating character found\n");
}

// 8. Remove Duplicates from Array
void removeDuplicates() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j]) break;
        if (i == j) printf("%d ", arr[i]);
    }
    printf("\n");
}

// 9. Second Largest Number
void secondLargest() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int first = -1e9, second = -1e9;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == -1e9)
        printf("No second largest element\n");
    else
        printf("Second largest element = %d\n", second);
}

// 10. All Pairs with Given Sum
void findPairsWithSum() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Pairs with sum %d:\n", target);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target)
                printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }
}

// 11. Balanced Parentheses
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return (top == -1) ? '\0' : stack[top--]; }

void checkBalancedParentheses() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);
    top = -1;

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(')
            push('(');
        else if (exp[i] == ')') {
            if (top == -1) {
                printf("Not Balanced\n");
                return;
            }
            pop();
        }
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}

// 12. Reverse Linked List
struct Node {
    int data;
    struct Node* next;
};

void reverseLinkedList() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("Reversed list: ");
    while (prev != NULL) {
        printf("%d ", prev->data);
        prev = prev->next;
    }
    printf("\n");
}

// 13. Find Middle Node of Linked List
void findMiddleNode() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle node = %d\n", slow->data);
}

// 14. Merge Two Sorted Linked Lists
void mergeSortedLists() {
    struct Node *head1 = NULL, *head2 = NULL, *temp;
    int n1, n2, val;

    printf("Enter number of nodes in List1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = head1;
        head1 = temp;
    }

    printf("Enter number of nodes in List2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = head2;
        head2 = temp;
    }

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = (head1) ? head1 : head2;

    printf("Merged list: ");
    temp = dummy.next;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 15. Queue using Two Stacks
#define SIZE 100
int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
void push2(int x) { stack2[++top2] = x; }
int pop1() { return (top1 == -1) ? -1 : stack1[top1--]; }
int pop2() { return (top2 == -1) ? -1 : stack2[top2--]; }

void queueUsingStacks() {
    int choice, x;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit Queue Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push1(x);
                break;
            case 2:
                if (top2 == -1) {
                    while (top1 != -1)
                        push2(pop1());
                }
                if (top2 == -1)
                    printf("Queue Empty\n");
                else
                    printf("Dequeued: %d\n", pop2());
                break;
            case 3:
                printf("Queue elements: ");
                for (int i = top2; i >= 0; i--) printf("%d ", stack2[i]);
                for (int i = 0; i <= top1; i++) printf("%d ", stack1[i]);
                printf("\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

