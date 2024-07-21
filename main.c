#include<stdio.h>
//#include<conio.h> // Not needed for standard compilation
//#include<stdlib.h> // Not needed in this program
void main() {
   int n, a[10], b[10], t[10], w[10], g[10], i, m; // Corrected variable declarations
   float att = 0, awt = 0; // Initialize average waiting time and average turnaround time
   //clrscr(); // Commented out since clrscr() is not a standard function
   for (i = 0; i < 10; i++) {
       a[i] = 0;
       b[i] = 0;
       w[i] = 0;
       g[i] = 0; // Initialize arrays
   }
   printf("Enter the number of processes: ");
   scanf("%d", &n);
   printf("Enter the burst times:\n");
   for (i = 0; i < n; i++)
       scanf("%d", &b[i]);
   printf("Enter the arrival times:\n");
   for (i = 0; i < n; i++)
       scanf("%d", &a[i]);
   g[0] = 0;
   for (i = 0; i < n; i++)
       g[i + 1] = g[i] + b[i]; // Calculate completion times
   for (i = 0; i < n; i++) {
       w[i] = g[i] - a[i]; // Calculate waiting times
       t[i] = g[i + 1] - a[i]; // Calculate turnaround times
       awt = awt + w[i]; // Sum of waiting times
       att = att + t[i]; // Sum of turnaround times
   }
   awt = awt / n; // Calculate average waiting time
   att = att / n; // Calculate average turnaround time
   printf("\n\tProcess\t\tWaiting Time\tTurnaround Time\n");
   for (i = 0; i < n; i++) {
       printf("\tP%d\t\t%d\t\t%d\n", i, w[i], t[i]);
   }
   printf("The average waiting time is %.2f\n", awt);
   printf("The average turnaround time is %.2f\n", att);
   //getch(); // Commented out getch() since it's not a standard function
}