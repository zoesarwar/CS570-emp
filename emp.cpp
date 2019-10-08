/*
 * Members: Patrick Perrine, Zoe Sarwar
 * Red ID's: 820486635, 820523074
 * Class Accounts: cssc0801, cssc0802
 * CS 570 Operating Systems, Summer 2019
 * Assignment #3, EMP
 * Filename: emp.cpp
 * Purpose: The driver program for emp executable
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <fstream>

using namespace std;

sem_t sem_flag;
sig_atomic_t sig_flag;

int timer;
int interval;
int alarms;

pthread_t threads[3];

void signal_catcher(int sighand){
    int cancel;
    cancel = pthread_cancel(threads[0]);
    cancel = pthread_cancel(threads[1]);
    cancel = pthread_cancel(threads[2]);
    exit(0);
    cout << "Program finished" << endl;
}

void progDone() {
    signal(SIGTERM, signal_catcher);
    raise(SIGTERM);
}

//Thread for managing and printing wall clock time
void *wall_clock() {
	time_t currTime;
	struct tm *info;
	char HMS[64];
	time(&currTime);
	info = localtime(&currTime);
	strftime(HMS, 64, "Current time: %X\n", info);
	cout << HMS;
}

//Thread for managing timer and signaling threads to terminate
void *countdown_timer(void*) {
    sleep(timer);
    cout << "Went to sleep after " << timer << " seconds." << endl;
    void progDone();
    return 0;
}

//Thread for managing and printing the alarm
void *alarm_warning(void*){
    sleep(alarms);
    cout << "ALARM!" << endl;
    return 0;
}

//Thread for printing interval
void *interval_printer(void*) {
    while(1){
        wall_clock();
        sleep(interval);
    }
}


//Main function for parsing input and creating threads
int main(int argc, char *argv[]) {

	//Initialize and fill parameters
	if(argc == 1) {
        timer = 17;
        interval = 1;
		alarms = 32;
	}
	else if(argc == 4) {
        timer = atoi(argv[1]);
        interval = atoi(argv[2]);
		alarms = atoi(argv[3]);
	}
	else {
		cout << "Invalid number of parameters" << endl;
		return 1;
	}

	//Check if second parameter is valid
	if(interval != 1 && interval != 60) {
		cout << "Invalid interval parameter" << endl;
		return 1;
	}

    
	//Initialize semaphore and signal variables
	sem_init(&sem_flag, 0, timer);

	int id[] = {0, 1, 2, 3}; //Process ID array
	
	//Initialize and run threads
	pthread_t wall_clock_thread;
	pthread_t countdown_timer_thread;
    pthread_t alarm_warning_thread;
    pthread_t interval_printer_thread;
	
	pthread_create(&countdown_timer_thread, NULL, countdown_timer, (void*) &id[1]);
    pthread_create(&alarm_warning_thread, NULL, alarm_warning, (void*) &id[2]);
    pthread_create(&interval_printer_thread, NULL, interval_printer, (void*) &id[3]);

	pthread_join(countdown_timer_thread, NULL);

	//Free and destroy variables
	sem_close(&sem_flag);
    
	//Finish program successfully
	cout << "Program finished" << endl;
	return 0;
}

