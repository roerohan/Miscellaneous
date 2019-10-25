#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <stdbool.h>

#define NUM_PROCESSES 10

#define THREAD_ZERO 0
#define THREAD_ONE 1
#define THREAD_TWO 2
#define THREAD_THREE 3
#define THREAD_FOUR 4
#define THREAD_FIVE 5
#define THREAD_SIX 6
#define THREAD_SEVEN 7

#define EXIT 0

// memory locking when accessing a critical sections
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
    processes process[NUM_PROCESSES];
    int number_of_process;
    bool activeThread[NUM_PROCESSES];
    pthread_attr_t attr[NUM_PROCESSES];
    void *anything;
}threadArgv;

//Prototypes
void bubble_sort(processes [], int );
//int get_Processes(processes []);
//void SJF_P(processes [], int );
//void FCFS(processes [], int );
//void SJF_NP(processes [], int );
//void Priority_P(processes [], int );
//void Priority_NP(processes [], int );
void RR(processes [], int );

//void *bubble_sort(void *);
void  *menu(void *arg);         // THREAD_ZERO
void *get_Processes(void *);    // THREAD_ONE
void *FCFS(void *);             // THREAD_TWO
void *SJF_P(void *);            // THREAD_THREE
void *SJF_NP(void *);           // THREAD_FOUR
void *Priority_P(void *);       // THREAD_FIVE
void *Priority_NP(void *);      // THREAD_SIX
//void *RR( void *);

int main() {

    int ch = -999, n;

    //pthread Ids
    pthread_t id[NUM_PROCESSES];

    //thread argv
    threadArgv prosArgument;

    // tagging threads as inactive for a start
    for(int i = 0 ; i < NUM_PROCESSES; i++){
        prosArgument.activeThread[i] = false;
    }

    processes *P = prosArgument.process;

    //create attribute
    pthread_attr_init(&(prosArgument.attr[THREAD_ZERO]));
    pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
    pthread_join(id[THREAD_ZERO], &ch);

    do{
        if (ch == THREAD_ONE) {
            pthread_attr_init(&(prosArgument.attr[THREAD_ONE]));
            prosArgument.activeThread[THREAD_ONE] = true;
            pthread_create(&id[THREAD_ONE], &prosArgument.attr[THREAD_ONE], get_Processes, &prosArgument);
            pthread_join(id[THREAD_ONE], &n);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            pthread_join(id[THREAD_ZERO], &ch);
        }
        if (ch == THREAD_TWO) {
            pthread_attr_init(&(prosArgument.attr[THREAD_TWO]));
            prosArgument.activeThread[THREAD_TWO] = true;
            pthread_create(&id[THREAD_TWO], &prosArgument.attr[THREAD_TWO], FCFS, &prosArgument);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
        }
        if (ch == THREAD_THREE) {
            pthread_attr_init(&(prosArgument.attr[THREAD_THREE]));
            prosArgument.activeThread[THREAD_THREE];
            pthread_create(&id[THREAD_THREE], &prosArgument.attr[THREAD_THREE], SJF_P, &prosArgument);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
        }
        if (ch == THREAD_FOUR) {
            pthread_attr_init( &(prosArgument.attr[THREAD_FOUR]));
            prosArgument.activeThread[THREAD_FOUR];
            pthread_create(&id[THREAD_FOUR], &prosArgument.attr[THREAD_FOUR], SJF_NP, &prosArgument);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
        }
        if (ch == THREAD_FIVE) {
            pthread_attr_init( &(prosArgument.attr[THREAD_FIVE]));
            prosArgument.activeThread[THREAD_FIVE];
            pthread_create(&id[THREAD_FIVE], &prosArgument.attr[THREAD_FIVE], Priority_P, &prosArgument);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
        }
        if (ch == THREAD_SIX) {
            pthread_attr_init( &(prosArgument.attr[THREAD_SIX]));
            prosArgument.activeThread[THREAD_SIX];
            pthread_create(&id[THREAD_SIX], &prosArgument.attr[THREAD_SIX], Priority_NP, &prosArgument);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
        }
        if (ch == THREAD_SEVEN) {
            //we need to collect input in this function, no a good idea to thread it.
            RR(prosArgument.process, n);

            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
        }
        if (ch == EXIT){
            printf("Terminated by user. Bye! :(\n");
            exit(EXIT_SUCCESS);
        }

        // wait for all active threads to terminate
        for(int i = 0 ; i < THREAD_SEVEN; i++){
            if(prosArgument.activeThread[i] == true){

                int retval;
                pthread_join(id[i], &retval);

                if(pthread_equal(id[i], id[THREAD_ZERO]))
                    ch = retval;
                if(pthread_equal(id[i], id[THREAD_ONE]))
                    n = retval;
            }

        }

        // let's handle invalid  input choice
        if( ch < THREAD_ZERO || ch > THREAD_SEVEN ){
            //menu again
            pthread_create(&id[THREAD_ZERO], &prosArgument.attr[THREAD_ZERO], menu, &prosArgument);
            prosArgument.activeThread[THREAD_ZERO] = true;
            pthread_join(id[THREAD_ZERO], &ch);
        }
    }while (ch != EXIT_SUCCESS);
    return 0;
}


void *menu(void *arg){

    threadArgv *process_struct = (threadArgv *)arg;
    int choice;
    printf("\n\n SIMULarrival_timeION OF CPU SCHEDULING ALGORITHMS\n");
    printf("\n Options:");
    printf("\n 1. Enter process darrival_timea.");
    printf("\n 2. FCFS");
    printf("\n 3. SJF (Pre-emptive)");
    printf("\n 4. SJF (Non Pre-emptive)");
    printf("\n 5. Priority Scheduling (Pre-emptive)");
    printf("\n 6. Priority Scheduling (Non Pre-emptive)");
    printf("\n 7. Round Robin");
    printf("\n 0. Exit\n Select : ");
    scanf("%d", &choice);

    //start critical section
    pthread_mutex_lock(&mutex);

    process_struct->activeThread[THREAD_ZERO] = false;

    //end critical section
    pthread_mutex_unlock(&mutex);


    pthread_exit(choice);
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




void *get_Processes(void *arg){
    threadArgv *process_struct= (threadArgv *)arg;
    int i, n;
    printf("\n Enter total no. of processes : ");
    scanf("%d", & n);
    process_struct->number_of_process = n;
    for (i = 0; i < n; i++) {
        printf("\n PROCESS [%d]", i + 1);
        printf(" Enter process name : ");
        scanf("%s", & process_struct->process[i].name);
        printf(" Enter burst time : ");
        scanf("%d", & process_struct->process[i].bust_time);
        printf(" Enter arrival time : ");
        scanf("%d", & process_struct->process[i].arrival_time);
        printf(" Enter priority : ");
        scanf("%d", & process_struct->process[i].priority);
    }
    printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
    for (i = 0; i < n; i++)
        printf("\n %s\t%d\t%d\t%d", process_struct->process[i].name, process_struct->process[i].bust_time, process_struct->process[i].arrival_time, process_struct->process[i].priority);

    //start critical section
    pthread_mutex_lock(&mutex);

    process_struct->activeThread[THREAD_ONE] = false;

    //end critical section
    pthread_mutex_unlock(&mutex);


    pthread_exit(process_struct->number_of_process);
}


// FCFS Algorithm
void *FCFS(void *arg) {   //processes P[], int n)
    threadArgv *process_struct= (threadArgv *)arg;
    processes proc[NUM_PROCESSES];
    int sumw = 0, sumt = 0;
    int x = 0, n = process_struct->number_of_process;
    float avgwt = 0.0, avgta = 0.0;
    int i, j;
    for (i = 0; i < n; i++)
        proc[i] = process_struct->process[i];


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
    process_struct->activeThread[THREAD_TWO] = false;

}

//Shortest Job First - Pre-emptive
void *SJF_P(void *arg){
    threadArgv *process_struct= (threadArgv *)arg;
    int n = process_struct->number_of_process;
    int i, t_total = 0, tcurr, b[10], min_at, j, x, min_bust_time;
    int sumw = 0, sumt = 0;
    float avgwt = 0.0, avgta = 0.0;
    processes proc[10], t;


    for (i = 0; i < n; i++) {
        proc[i] = process_struct->process[i];
        t_total += process_struct->process[i].bust_time;
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

    process_struct->activeThread[THREAD_THREE] = false;
}

//SJF Non Pre-emptive
void *SJF_NP(void *arg){ //} processes P[], int n) {
    threadArgv *Process_struct = (threadArgv *)arg;
    int n = Process_struct->number_of_process;
    processes proc[10];
    processes t;
    int sumw = 0, sumt = 0;
    int x = 0;
    float avgwt = 0.0, avgta = 0.0;
    int i, j;


    for (i = 0; i < n; i++)
        proc[i] = Process_struct->process[i];


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
    Process_struct->activeThread[THREAD_FOUR] = false;
}

// Priority - Preemptive
void *Priority_P(void *arg){ //processes P[], int n) {

    threadArgv *process_struct = (threadArgv*)arg;
    int n = process_struct->number_of_process;
    int i, t_total = 0, tcurr, b[10], j, x, min_pr;
    int sumw = 0, sumt = 0;
    float avgwt = 0.0, avgta = 0.0;
    processes proc[10], t;


    for (i = 0; i < n; i++) {
        proc[i] = process_struct->process[i];
        t_total += process_struct->process[i].bust_time;
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

    process_struct->activeThread[THREAD_FIVE] = false;
}


//Priority Non Pre-emptive
void *Priority_NP(void *arg){   //processes P[], int n) {
    threadArgv *process_struct = (threadArgv*)arg;
    int n = process_struct->number_of_process;
    processes proc[10];
    processes t;
    int sumw = 0, sumt = 0;
    float avgwt = 0.0, avgta = 0.0;
    int i, j;
    int x = 0;


    for (i = 0; i < n; i++)
        proc[i] = process_struct->process[i];


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

    process_struct->activeThread[THREAD_SIX] = false;
}


//Round Robin Schedulinggg
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
        if (proc1[k].bust_time > 0) {
            printf("  %d  %s", tcurr, proc1[k].name);
        }
        fflush(stdout);
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


