#include<iostream> 
#include<string> 

using namespace std; 

enum LogLevel{LogLevelInfo, LogLevelDebug, LogLevelWarn, LogLevelError, LogLevelFatal};

enum LogFormat{LogFormatText, LogFormatJson};

class Logger {
    static Logger* instance; 

protected: 
        LogLevel level;  
        static LogFormat format; 
        
        Logger(){
            level = LogLevelInfo;
        }

public: 
    static Logger* getInstance(); 

    static void setFormat(LogFormat f) {
        format = f;
    }

    void setLogLevel(LogLevel logLevel) {
        level = logLevel;
    }

    virtual void log(string message) {
        cout<<level<<" "<<message<<"\n"; 
    }
};

class JsonLogger: public Logger{
    protected: 
    //  Should make Logger friend only then it can call JsonLogger() which is protected
    friend class Logger; 

        JsonLogger() {}
    public: 
        void log(string message) {
            cout<<"{\"level:\" "<<level<<", \"message:\" "<<message<<" }\n";                 
        }
};

Logger *Logger::instance = 0;
LogFormat Logger::format = LogFormatText; 

Logger *Logger::getInstance() {
        if (instance == NULL) {
            if (format == LogFormatJson) {
                return new JsonLogger();
            } 
            return new Logger(); 
        }

        return instance; 
    }


int main() {
    Logger::getInstance()->log("app starting");
    
    Logger* logger = Logger::getInstance(); 
    logger->setLogLevel(LogLevelFatal);
    logger->log("app crashed");

    Logger::setFormat(LogFormatJson);
    Logger::getInstance()->log("app recovered");

    Logger* jsonLogger = Logger::getInstance();
    jsonLogger->log("app running");

    return 0;
}
