/*
drvDataLogger.h
*/

#include <fstream>      // std::ofstream

#include "asynPortDriver.h"

#define data0Str	    "DATA0" 
#define data1Str	    "DATA1"	
#define data2Str	    "DATA2"	
#define data3Str	    "DATA3"	
#define data4Str	    "DATA4"	
#define data5Str	    "DATA5"	
#define data6Str	    "DATA6"	
#define data7Str	    "DATA7"	
#define data8Str	    "DATA8"	
#define data9Str	    "DATA9"	
#define runStateStr	    "RUN_STATE"
#define runStatusStr	"RUN_STATUS"
#define triggerStr	    "TRIGGER"
#define trigCntStr	    "TRIG_CNT"
#define filepathStr	    "FILEPATH"
#define filenameStr	    "FILENAME"
#define commentStr	    "COMMENT"
#define messageStr	    "MESSAGE"

class drvDataLogger : public asynPortDriver {
public:
    drvDataLogger(const char* port, int npvs);
    virtual asynStatus writeOctet(asynUser *pasynUser, const char *value, size_t maxChars, size_t *nActual);
    virtual asynStatus writeInt32(asynUser* pasynUser, epicsInt32 value);
    virtual asynStatus writeFloat64(asynUser* pasynUser, epicsFloat64 value);
    ~drvDataLogger() {delete [] data_;}

protected:
    int data0;
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
    int data6;
    int data7;
    int data8;
    int data9;
    static const int N_DATA_MAX = 10; // Max number of sampled PVs
    int runState;
    int runStatus;
    int trigger;
    int trigCnt;
    int filepath;
    int filename;
    int comment;
    int message;
    #define FIRST_COMMAND data0
    #define LAST_COMMAND message
    #define N_PARAMS ((int)(&LAST_COMMAND - &FIRST_COMMAND + 1))

private:
    asynUser *pasynUser;
    void _openFile();
    void _closeFile();
    void _writeData();
    int npvs_;
    double *data_;
    int running_;
    std::ofstream outfile_;
    epicsTimeStamp timeStamp_;
    char timeString_[80];
    char filepath_[128];
    char comment_[128];
    int triggerCount_;
};

