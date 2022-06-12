#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;

class Logger{
	static int counter;
	static Logger* loggerInstance;
	Logger();  
	public:
		void log(string msg);
		static Logger* createLogger();
};

int Logger::counter=0;
Logger*  Logger::loggerInstance= NULL;

Logger::Logger(){
	cout<<"New instance of LOGGER is created! & No. of instances "<<++counter<<endl;
}
void Logger::log(string msg){
	cout<<msg<<endl;
}
Logger* Logger::createLogger(){
	pthread_mutex_lock(&lock); //mutex_lock
	
	if(Logger::counter==0)
		loggerInstance= new Logger();
		
	pthread_mutex_unlock(&lock); //mutex_unlock
	
	return loggerInstance;	
} 


void *userOneLogs(void *arg){
	Logger* logger1= Logger::createLogger();
	logger1->log("this is from USER ONE");
	return 0;
} 
void *userTwoLogs(void *arg){
	Logger* logger2= Logger::createLogger();
	logger2->log("this is from USER TWO");
	return 0;
} 

int main(){
	pthread_t t1, t2;
	
	// Create two threads (both run func)
	pthread_create(&t1, NULL ,userOneLogs, NULL);
	pthread_create(&t2, NULL ,userTwoLogs, NULL);
	
	// Wait for the threads to end.
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
