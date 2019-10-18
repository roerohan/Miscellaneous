#include<stdio.h>
#include<pthread.h>   //currently adding multi-threading support.
#include<stdlib.h>

#define NUM_PROCESSES 10

#define THREAD_ZERO 0
#define THREAD_ONE 1
#define THREAD_TWO 2
#define THREAD_THREE 3
#define THREAD_FOUR 4
#define THREAD_FIVE 5
#define THREAD_SIX 6
#define THREAD_SEVEN 7

typedef struct process {
	char name[5];
	int bust_time;
	int arrival_time;
	int priority;
	int wait_time, turn_around;
	int flag;
}
processes;


//thread argv
typedef struct threadArgv{
    processes process[NUM_PROCESSES][NUM_PROCESSES];
    int value[NUM_PROCESSES];
    pthread_attr_t attr[NUM_PROCESSES];
    void *anything;
}threadArgv;

//Prototypes
void bubble_sort(processes [], int );
//int get_Processes(processes []);
void SJF_P(processes [], int );
void FCFS(processes [], int );
void SJF_P(processes [], int );
void SJF_NP(processes [], int );
void Priority_P(processes [], int );
void Priority_NP(processes [], int );
void RR(processes [], int );

//void *bubble_sort(void *);
void *get_Processes(void *);
//void *SJF_P(void *);
//void *FCFS(void *);
//void *SJF_P(void *);
//void *SJF_NP(void *);
//void *Priority_P(void *);
//void *Priority_NP(void *);
//void *RR( void *);
void  *menu(void *arg);

int main() {

    processes P[NUM_PROCESSES];
    int ch = -999, n;

    //pthread Ids
    pthread_t id[NUM_PROCESSES];

    //thread argv
    threadArgv prosArgument;

    //create attribute
    pthread_attr_init(&(prosArgument.attr[THREAD_ZERO]));

    //
    //pthread_attr_t menuAttr;
    //pthread_attr_init(&menuAttr);


    do {
        pthread_create( &id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
        pthread_join(id[THREAD_ZERO], &ch);

        switch (ch) {

            case 0:
                pthread_attr_init(&(prosArgument.attr[THREAD_ONE]));
                pthread_create(&id[THREAD_ONE], &prosArgument.attr[THREAD_ZERO], get_Processes, &prosArgument);
                pthread_join(id[THREAD_ONE], &n);
                //n = get_Processes(P);
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
                printf("Terminated by user. Bye! :(\n");
                exit(0);
        }
    } while (ch != 7);
    return 0;
}


void *menu(void *arg){

    threadArgv *proStrut = (threadArgv *)arg;

    printf("\n\n SIMULarrival_timeION OF CPU SCHEDULING ALGORITHMS\n");
    printf("\n Options:");
    printf("\n 0. Enter process darrival_timea.");
    printf("\n 1. FCFS");
    printf("\n 2. SJF (Pre-emptive)");
    printf("\n 3. SJF (Non Pre-emptive)");
    printf("\n 4. Priority Scheduling (Pre-emptive)");
    printf("\n 5. Priority Scheduling (Non Pre-emptive)");
    printf("\n 6. Round Robin");
    printf("\n 7. Exit\n Select : ");
    scanf("%d", &(proStrut->value[0]));


    pthread_exit(  proStrut->value[0]);
}



void bubble_sort(processes proc[], int n) {
	processes t;
	int i, j;
	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++) {
			if (proc[j].arrival_time > proc[j + 1].arrival_time) {
				t = proc[j];
				proc[j] = proc[j + 1];
				proc[j + 1] = t;
			}
		}
}




void *get_Processes(void *arg){//processes P[]) {
    threadArgv *proArg = (threadArgv *)arg;
	int i, n;
	printf("\n Enter total no. of processes : ");
	scanf("%d", & n);
	for (i = 0; i < n; i++) {
		printf("\n PROCESS [%d]", i + 1);
		printf(" Enter process name : ");
		scanf("%s", & proArg->process[THREAD_ONE][i].name);
		printf(" Enter burst time : ");
		scanf("%d", & proArg->process[THREAD_ONE][i].bust_time);
		printf(" Enter arrival time : ");
		scanf("%d", & proArg->process[THREAD_ONE][i].arrival_time);
		printf(" Enter priority : ");
		scanf("%d", & proArg->process[THREAD_ONE][i].priority);
	}
	printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d\t%d", proArg->process[THREAD_ONE][i].name, proArg->process[THREAD_ONE][i].bust_time, proArg->process[THREAD_ONE][i].arrival_time, proArg->process[THREAD_ONE][i].priority);
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
	for(i = 0; i < n; i++) {
        printf("\n %s\t%d\t%d", proc[i].name, proc[i].bust_time, proc[i].arrival_time);
    }


	sumw = proc[0].wait_time = 0;
	sumt = proc[0].turn_around = proc[0].bust_time - proc[0].arrival_time;


	for (i = 1; i < n; i++) {
		proc[i].wait_time = (proc[i - 1].bust_time + proc[i - 1].arrival_time + proc[i - 1].wait_time) - proc[i].arrival_time;;
		proc[i].turn_around = (proc[i].wait_time + proc[i].bust_time);
		sumw += proc[i].wait_time;
		sumt += proc[i].turn_around;
	}
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for (i = 0; i < n; i++) {
        printf("\n %s\t%d\t%d\t%d\t%d", proc[i].name, proc[i].bust_time, proc[i].arrival_time, proc[i].wait_time,
               proc[i].turn_around);

    }


	printf("0\t");
	for (i = 1; i <= n; i++) {
		x += proc[i - 1].bust_time;
		printf("%d      ", x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);

	//flush printf buffer
    fflush(stdout);

}

//Shortest Job First - Pre-emptive
void SJF_P(processes P[], int n) {
	int i, t_total = 0, tcurr, b[10], min_at, j, x, min_bust_time;
	int sumw = 0, sumt = 0;
	float avgwt = 0.0, avgta = 0.0;
	processes proc[10], t;


	for (i = 0; i < n; i++) {
		proc[i] = P[i];
		t_total += P[i].bust_time;
	}


	bubble_sort(proc, n);


	for (i = 0; i < n; i++)
		b[i] = proc[i].bust_time;


	i = j = 0;

	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
    //flush printf buffer
    fflush(stdout);
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
            if (proc[j].bust_time > proc[j + 1].bust_time) {
                t = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = t;
            }
        }


    printf("\n\n PROC.\tB.T.\tA.T.");
    fflush(stdout);

    for (i = 0; i < n; i++){
        printf("\n %s\t%d\t%d", proc[i].name, proc[i].bust_time, proc[i].arrival_time);

    }


    sumw = proc[0].wait_time = 0;
    sumt = proc[0].turn_around = proc[0].bust_time - proc[0].arrival_time;


    for (i = 1; i < n; i++) {
        proc[i].wait_time =
                (proc[i - 1].bust_time + proc[i - 1].arrival_time + proc[i - 1].wait_time) - proc[i].arrival_time;;
        proc[i].turn_around = (proc[i].wait_time + proc[i].bust_time);
        sumw += proc[i].wait_time;
        sumt += proc[i].turn_around;
    }
    avgwt = (float) sumw / n;
    avgta = (float) sumt / n;
    printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
    for (i = 0; i < n; i++){
        printf("\n %s\t%d\t%d\t%d\t%d", proc[i].name, proc[i].bust_time, proc[i].arrival_time, proc[i].wait_time,
               proc[i].turn_around);
    }


	printf("0\t");
	for (i = 1; i <= n; i++) {
		x += proc[i - 1].bust_time;
		printf("%d      ", x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);

    //flush printf buffer
    fflush(stdout);
}

// Priority - Preemptive
void Priority_P(processes P[], int n) {
	int i, t_total = 0, tcurr, b[10], j, x, min_pr;
	int sumw = 0, sumt = 0;
	float avgwt = 0.0, avgta = 0.0;
	processes proc[10], t;


	for (i = 0; i < n; i++) {
		proc[i] = P[i];
		t_total += P[i].bust_time;
	}


	bubble_sort(proc, n);


	for (i = 0; i < n; i++)
		b[i] = proc[i].bust_time;


	i = j = 0;

	printf(" %d", tcurr);
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);

    //flush printf buffer
    fflush(stdout);
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
			if (proc[j].priority > proc[j + 1].priority) {
				t = proc[j];
				proc[j] = proc[j + 1];
				proc[j + 1] = t;
			}
		}


	printf("\n\n PROC.\tB.T.\tA.T.");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d", proc[i].name, proc[i].bust_time, proc[i].arrival_time);


	sumw = proc[0].wait_time = 0;
	sumt = proc[0].turn_around = proc[0].bust_time - proc[0].arrival_time;


	for (i = 1; i < n; i++) {
		proc[i].wait_time = (proc[i - 1].bust_time + proc[i - 1].arrival_time + proc[i - 1].wait_time) - proc[i].arrival_time;;
		proc[i].turn_around = (proc[i].wait_time + proc[i].bust_time);
		sumw += proc[i].wait_time;
		sumt += proc[i].turn_around;
	}
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for (i = 0; i < n; i++)
		printf("\n %s\t%d\t%d\t%d\t%d", proc[i].name, proc[i].bust_time, proc[i].arrival_time, proc[i].wait_time, proc[i].turn_around);


	printf("0\t");
	for (i = 1; i <= n; i++) {
		x += proc[i - 1].bust_time;
		printf("%d      ", x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);

    //flush printf buffer
    fflush(stdout);
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
	scanf("%d", &Q);

	for (k = 0;; k++) {
		if (k > n - 1)
			k = 0;
		if (proc1[k].bust_time > 0)
			printf("  %d  %s", tcurr, proc1[k].name);
		t = 0;
		while (t < Q && proc1[k].bust_time > 0) {
			t++;
			tcurr++;
			proc1[k].bust_time--;
		}
		if (proc1[k].bust_time <= 0 && proc1[k].flag != 1) {
			proc1[k].wait_time = tcurr - proc2[k].bust_time - proc1[k].arrival_time;
			proc1[k].turn_around = tcurr - proc1[k].arrival_time;
			pflag++;
			proc1[k].flag = 1;
			sumw += proc1[k].wait_time;
			sumt += proc1[k].turn_around;
		}
		if (pflag == n)
			break;
	}
	printf("  %d", tcurr);
	avgwt = (float) sumw / n;
	avgta = (float) sumt / n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);

    //flush printf buffer
    fflush(stdout);
}


