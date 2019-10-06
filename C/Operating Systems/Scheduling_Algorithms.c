#include<stdio.h>

#include<stdlib.h>


typedef struct process {
	char name[5];
	int bt;
	int at;
	int prt;
	int wt, ta;
	int flag;
}
processes;

void bubble_sort(processes proc[], int n) {
	processes t;
	int i, j;
	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++) {
			if (proc[j].at > proc[j + 1].at) {
				t = proc[j];
				proc[j] = proc[j + 1];
				proc[j + 1] = t;
			}
		}
}

int get_Processes(processes P[]) {
	int i, n;
	printf("\n Enter total no. of processes : ");
	scanf("%d", & n);
	for (i = 0; i < n; i++) {
		printf("\n PROCESS [%d]", i + 1);
		printf(" Enter process name : ");
		scanf("%s", & P[i].name);
		printf(" Enter burst time : ");
		scanf("%d", & P[i].bt);
		printf(" Enter arrival time : ");
		scanf("%d", & P[i].at);
		printf(" Enter priority : ");
		scanf("%d", & P[i].prt);
	}
	printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d\t%d", P[i].name, P[i].bt, P[i].at, P[i].prt);
	return n;
}


// FCFS Algorithm
void FCFS(processes P[], int n) {
	processes proc[10];
	int sumw = 0, sumt = 0;
	int x = 0;
	float avgwt = 0.0, avgta = 0.0;
	int i, j;
	for (i = 0; i < n; i++)
		proc[i] = P[i];


	bubble_sort(proc, n);


	printf("\n\n PROC.\tB.T.\tA.T.");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d", proc[i].name, proc[i].bt, proc[i].at);


	sumw = proc[0].wt = 0;
	sumt = proc[0].ta = proc[0].bt - proc[0].at;


	for (i = 1; i < n; i++) {
		proc[i].wt = (proc[i - 1].bt + proc[i - 1].at + proc[i - 1].wt) - proc[i].at;;
		proc[i].ta = (proc[i].wt + proc[i].bt);
		sumw += proc[i].wt;
		sumt += proc[i].ta;
	}
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d\t%d\t%d", proc[i].name, proc[i].bt, proc[i].at, proc[i].wt, proc[i].ta);


	printf("0\t");
	for (i = 1; i <= n; i++) {
		x += proc[i - 1].bt;
		printf("%d      ", x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}

//Shortest Job First - Pre-emptive
void SJF_P(processes P[], int n) {
	int i, t_total = 0, tcurr, b[10], min_at, j, x, min_bt;
	int sumw = 0, sumt = 0;
	float avgwt = 0.0, avgta = 0.0;
	processes proc[10], t;


	for (i = 0; i < n; i++) {
		proc[i] = P[i];
		t_total += P[i].bt;
	}


	bubble_sort(proc, n);


	for (i = 0; i < n; i++)
		b[i] = proc[i].bt;


	i = j = 0;

	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}

//SJF Non Pre-emptive
void SJF_NP(processes P[], int n) {
	processes proc[10];
	processes t;
	int sumw = 0, sumt = 0;
	int x = 0;
	float avgwt = 0.0, avgta = 0.0;
	int i, j;


	for (i = 0; i < n; i++)
		proc[i] = P[i];


	bubble_sort(proc, n);


	for (i = 2; i < n; i++)
		for (j = 1; j < n - i + 1; j++) {
			if (proc[j].bt > proc[j + 1].bt) {
				t = proc[j];
				proc[j] = proc[j + 1];
				proc[j + 1] = t;
			}
		}


	printf("\n\n PROC.\tB.T.\tA.T.");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d", proc[i].name, proc[i].bt, proc[i].at);


	sumw = proc[0].wt = 0;
	sumt = proc[0].ta = proc[0].bt - proc[0].at;


	for (i = 1; i < n; i++) {
		proc[i].wt = (proc[i - 1].bt + proc[i - 1].at + proc[i - 1].wt) - proc[i].at;;
		proc[i].ta = (proc[i].wt + proc[i].bt);
		sumw += proc[i].wt;
		sumt += proc[i].ta;
	}
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d\t%d\t%d", proc[i].name, proc[i].bt, proc[i].at, proc[i].wt, proc[i].ta);


	printf("0\t");
	for (i = 1; i <= n; i++) {
		x += proc[i - 1].bt;
		printf("%d      ", x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}

// Priority - Preemptive
void Priority_P(processes P[], int n) {
	int i, t_total = 0, tcurr, b[10], j, x, min_pr;
	int sumw = 0, sumt = 0;
	float avgwt = 0.0, avgta = 0.0;
	processes proc[10], t;


	for (i = 0; i < n; i++) {
		proc[i] = P[i];
		t_total += P[i].bt;
	}


	bubble_sort(proc, n);


	for (i = 0; i < n; i++)
		b[i] = proc[i].bt;


	i = j = 0;

	printf(" %d", tcurr);
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}


//Priority Non Pre-emptive
void Priority_NP(processes P[], int n) {
	processes proc[10];
	processes t;
	int sumw = 0, sumt = 0;
	float avgwt = 0.0, avgta = 0.0;
	int i, j;
	int x = 0;


	for (i = 0; i < n; i++)
		proc[i] = P[i];


	bubble_sort(proc, n);


	for (i = 2; i < n; i++)
		for (j = 1; j < n - i + 1; j++) {
			if (proc[j].prt > proc[j + 1].prt) {
				t = proc[j];
				proc[j] = proc[j + 1];
				proc[j + 1] = t;
			}
		}


	printf("\n\n PROC.\tB.T.\tA.T.");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d", proc[i].name, proc[i].bt, proc[i].at);


	sumw = proc[0].wt = 0;
	sumt = proc[0].ta = proc[0].bt - proc[0].at;


	for (i = 1; i < n; i++) {
		proc[i].wt = (proc[i - 1].bt + proc[i - 1].at + proc[i - 1].wt) - proc[i].at;;
		proc[i].ta = (proc[i].wt + proc[i].bt);
		sumw += proc[i].wt;
		sumt += proc[i].ta;
	}
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d\t%d\t%d", proc[i].name, proc[i].bt, proc[i].at, proc[i].wt, proc[i].ta);


	printf("0\t");
	for (i = 1; i <= n; i++) {
		x += proc[i - 1].bt;
		printf("%d      ", x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}


//Round Robin Scheduling
void RR(processes P[], int n) {
	int pflag = 0, t, tcurr = 0, k, i, Q = 0;
	int sumw = 0, sumt = 0;
	float avgwt = 0.0, avgta = 0.0;
	processes proc1[10], proc2[10];


	for (i = 0; i < n; i++)
		proc1[i] = P[i];


	bubble_sort(proc1, n);

	for (i = 0; i < n; i++)
		proc2[i] = proc1[i];

	printf("\n Enter quantum time : ");
	scanf("%d", & Q);

	for (k = 0;; k++) {
		if (k > n - 1)
			k = 0;
		if (proc1[k].bt > 0)
			printf("  %d  %s", tcurr, proc1[k].name);
		t = 0;
		while (t < Q && proc1[k].bt > 0) {
			t++;
			tcurr++;
			proc1[k].bt--;
		}
		if (proc1[k].bt <= 0 && proc1[k].flag != 1) {
			proc1[k].wt = tcurr - proc2[k].bt - proc1[k].at;
			proc1[k].ta = tcurr - proc1[k].at;
			pflag++;
			proc1[k].flag = 1;
			sumw += proc1[k].wt;
			sumt += proc1[k].ta;
		}
		if (pflag == n)
			break;
	}
	printf("  %d", tcurr);
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}

int main() {

	processes P[10];
	int ch, n;
	do {
		printf("\n\n SIMULATION OF CPU SCHEDULING ALGORITHMS\n");
		printf("\n Options:");
		printf("\n 0. Enter process data.");
		printf("\n 1. FCFS");
		printf("\n 2. SJF (Pre-emptive)");
		printf("\n 3. SJF (Non Pre-emptive)");
		printf("\n 4. Priority Scheduling (Pre-emptive)");
		printf("\n 5. Priority Scheduling (Non Pre-emptive)");
		printf("\n 6. Round Robin");
		printf("\n 7. Exit\n Select : ");
		scanf("%d", & ch);
		switch (ch) {
			case 0:
				n = get_Processes(P);
				break;
			case 1:
				FCFS(P, n);
				break;
			case 2:
				SJF_P(P, n);
				break;
			case 3:
				SJF_NP(P, n);
				break;
			case 4:
				Priority_P(P, n);
				break;
			case 5:
				Priority_NP(P, n);
				break;
			case 6:
				RR(P, n);
				break;
			case 7:
				exit(0);
		}
	} while (ch != 7);
	return 0;
}
