#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a job
typedef struct {
    int id;       // Job ID
    int deadline; // Job deadline
    int profit;   // Job profit
} Job;

// Comparison function for sorting jobs in descending order of profit
int compareJobs(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

// Function to find the maximum profit job sequence
void jobSequencing(Job jobs[], int n) {
    // Sort jobs in descending order of profit
    qsort(jobs, n, sizeof(Job), compareJobs);

    // Find the maximum deadline to determine the schedule size
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Array to store the schedule (-1 indicates slot is free)
    int schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }

    // Array to keep track of total profit
    int totalProfit = 0;

    // Schedule the jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for the current job (starting from its deadline)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the result
    printf("Selected jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            printf("J%d ", schedule[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // Example job set
    Job jobs[] = {{1, 2, 50}, {2, 1, 15}, {3, 2, 10}, {4, 1, 25}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Call the job sequencing function
    jobSequencing(jobs, n);

    return 0;
}