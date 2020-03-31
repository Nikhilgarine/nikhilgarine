#include<stdio.h>
#include<string.h>
struct process_Struct 
{
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
}
temp_Struct;


void faculty_Queue(int no_of_process)
 {

    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct faculty_Process[no_of_process];

    for(count = 0; count < no_of_process; count++) {
        printf("enter details[%d]", count+1);
        puts("");
        printf("P name:");
        scanf("%s", faculty_Process[count].process_name);

        printf("Arr time :");
        scanf("%d", &faculty_Process[count].arrival_time);

        printf("burst time:");
        scanf("%d", &faculty_Process[count].burst_time);
        puts("");
    }
    printf("enter quantam time : ");
    scanf("%d",&quantum_time);

    for(count = 0; count < no_of_process; count++) {
        for(int x = count +1; x < count; x++){
            if(faculty_Process[count].arrival_time > faculty_Process[x].arrival_time) {
                temp_Struct = faculty_Process[count];
                faculty_Process[count] = faculty_Process[x];
                faculty_Process[x] = temp_Struct;
            }
        }
    }

    for(count = 0; count < no_of_process; count++) {
        faculty_Process[count].remaining = faculty_Process[count].burst_time;
        faculty_Process[count].completion_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;

    
    int flag, x, n, z, waiting_time = 0;
    do {
        for(count = 0; count < no_of_process; count++){
            if(total_time >= faculty_Process[count].arrival_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == count) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++; 
                    round_robin[queue] == count;
                }
            }
        }

        if(queue == 0) {
            n = 0;
        }
        if(faculty_Process[n].remaining == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(faculty_Process[n].remaining > 0) {
                if(faculty_Process[n].remaining < quantum_time){
                    total_time += faculty_Process[n].remaining;
                    faculty_Process[n].remaining = 0;
                }else {
                    total_time += quantum_time;
                    faculty_Process[n].remaining -= quantum_time;
                }
                faculty_Process[n].completion_time = total_time;
            }
            n++;
        }
        flag = 0;
        
        for(count = 0; count < no_of_process; count++) {
            if(faculty_Process[count].remaining > 0) {
                flag++;
            }
        }
    }while(flag != 0);


    printf("\n|\tProcess Name\t  |\tArrival Time\t  |\tBurst Time\t |\tCompletion Time  \t|\n");

    for(count = 0; count < no_of_process; count++){
        waiting_time = faculty_Process[count].completion_time - faculty_Process[count].burst_time - faculty_Process[count].arrival_time;

        printf("%s",faculty_Process[count].process_name);
printf("%d",faculty_Process[count].arrival_time);
printf("%d",faculty_Process[count].burst_time);
printf("%d",faculty_Process[count].completion_time);
	}

}


void student_Queue(int no_of_process) {

    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct student_Process[no_of_process];

    for(count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", student_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &student_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &student_Process[count].burst_time);
    }
    printf("Quantam time : ");
    scanf("%d", &quantum_time);

    for(count = 0; count < no_of_process; count++) {
        for(int x = count +1; x < count; x++){
            if(student_Process[count].arrival_time > student_Process[x].arrival_time) {
                temp_Struct = student_Process[count];
                student_Process[count] = student_Process[x];
                student_Process[x] = temp_Struct;
            }
        }
    }

    for(count = 0; count < no_of_process; count++) {
        student_Process[count].remaining = student_Process[count].burst_time;
        student_Process[count].completion_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
}


int main(int argc, char const *argv[]) {
    int select_queue, no_of_process;

    puts("select your category");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);

    switch(select_queue) {
        case 1 :
                printf("enter number of processes ");
                scanf("%d", &no_of_process);
                
                faculty_Queue(no_of_process);
                
                break;

        case 2 :
                printf("enter number of processes ");
                scanf("%d", &no_of_process);

                student_Queue(no_of_process);
                
                break;

        default : 
                printf("choose correct option");
    }

    return 0;
}

