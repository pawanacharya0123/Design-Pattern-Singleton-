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
	if(Logger::counter==0)
		loggerInstance= new Logger();
	return loggerInstance;	
}
