#include <stdio.h>
#include "codebase.h"
#include "flowchart.h"

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("     DSA MINI PROJECT MENU\n");
        printf("==============================\n");
        printf("1. Find GCD and LCM\n");
        printf("2. Check Prime Number\n");
        printf("3. Factorial (Recursion & Iteration)\n");
        printf("4. Sum of Digits (Recursion & Iteration)\n");
        printf("5. Check Armstrong Number\n");
        printf("6. Check if Two Strings are Anagrams\n");
        printf("7. Find First Non-Repeating Character\n");
        printf("8. Remove Duplicates from Array\n");
        printf("9. Find Second Largest in Array\n");
        printf("10. Find All Pairs with Given Sum\n");
        printf("11. Check Balanced Parentheses\n");
        printf("12. Reverse a Linked List\n");
        printf("13. Find Middle Node of Linked List\n");
        printf("14. Merge Two Sorted Linked Lists\n");
        printf("15. Implement Queue Using Two Stacks\n");
        printf("0. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting program... Goodbye!\n");
            break;
        }

        printf("\n--- OUTPUT ---\n");

        switch (choice) {
            case 1: findGcdLcm(); break;
            case 2: checkPrime(); break;
            case 3: findFactorial(); break;
            case 4: sumOfDigits(); break;
            case 5: checkArmstrong(); break;
            case 6: checkAnagram(); break;
            case 7: firstNonRepeatingChar(); break;
            case 8: removeDuplicates(); break;
            case 9: secondLargest(); break;
            case 10: findPairsWithSum(); break;
            case 11: checkBalancedParentheses(); break;
            case 12: reverseLinkedList(); break;
            case 13: findMiddleNode(); break;
            case 14: mergeSortedLists(); break;
            case 15: queueUsingStacks(); break;
            default: printf("Invalid choice! Please try again.\n");
        }

        printf("\n--- FLOWCHART ---\n");
        displayFlowchart(choice);
    }

    return 0;
}
