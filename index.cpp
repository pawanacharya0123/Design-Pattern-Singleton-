#include<iostream>
using namespace std;

#include"Logger.cpp"

int main(){
	Logger* logger1= Logger::createLogger();
	logger1->log("this is from USER ONE");
	
	Logger* logger2= Logger::createLogger();
	logger2->log("this is from USER TWO");
	
	Logger* logger3= Logger::createLogger();
	logger3->log("this is from USER THREE");
}
