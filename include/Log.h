#ifndef LYW_CODE_LOG
#define LYW_CODE_LOG
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <sys/time.h>
#include <sys/types.h>

typedef enum _Log_Level
{
    ERROR_LEVEL,
    WARNING_LEVEL,
    DEBUG_LEVEL

} TLog_Level;


typedef enum _Log_Mode
{
    SCK_MODE,
    PTHREAD_MODE
} TLog_Mode;

typedef struct _Log_Info
{    
    FILE * file_handle; 
    pthread_mutex_t lock;
    TLog_Level level;
    TLog_Mode mode;
    unsigned int size;
    char szLogPath[64];
    char szLogName[128];
    int port;
    char ip[64];

} TLog_Info;

typedef TLog_Info * PLog_Info;

TLog_Info _g_log_info;
PLog_Info _g_p_log_info;

/*
 * @breif       生成固定格的时间串
 *
 * @param[out]  输出时间串 
 * @param[in]   输出时间串的size
 *
 * return       true 成功  false  失败
 */
//static bool Get_Str_time_for_log ( char * szStrTime, size_t iSizeOfStrTime );


/*
 * @breif            创建目录
 * @param[in]        目录 
 *
 * @return           true 成功 false 失败 
 */
//static bool mkdir_for_log(const char * szFilePath);

bool Init_log(const char *szFileName, const char * szFilePath,TLog_Level level,unsigned int size,TLog_Mode mode);

void user_error_log ( const char * szFormat,...);
void user_warning_log ( const char * szFormat,...);
void user_debug_log ( const char * szFormat,...);

//bool Free_Log();

#endif

#define Init_Log(FileName,FilePath,level,size,mode) \
    Init_log(FileName, FilePath, level,size,mode);
        
#define UserError(...) user_error_log ( __VA_ARGS__ );
#define UserWarning(...) user_warning_log ( __VA_ARGS__ );
#define UserDebug(...) user_debug_log ( __VA_ARGS__ );

#define UserError_ASC()
#define UserWarning_ASC()
#define UserDebug_ASC()

