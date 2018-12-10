#include "Log.h"
/*
 * @breif       生成固定格的时间串
 * 
 * @param[out]  输出时间串 
 * @param[in]   输出时间串的size
 * 
 * return       true 成功  false  失败
 * 
 */
bool Get_Str_time_for_log ( char * szStrTime, unsigned int iSizeOfStrTime )
{
    bool res = false;
    int index = 0;
    time_t t;
    struct tm * ptm = NULL;
    char * tmpbuf [ 16 ] = { 0 };
    
    if ( iSizeOfStrTime <= strlen ( "yyyy_mm_dd_hh_MM_ss" ) )
    {
        return false;
    }
    else
    {
        memset ( szStrTime, 0x00, iSizeOfStrTime );
    }

    t = time ( NULL );

    if ( ( ptm = gmtime ( & t ) ) != NULL )
    {
        vsnprintf ( szString,iSizeOfStrTime,"%04d_%02d_%02d_%02d_%02d_%02d",
                    ptm->tm_year + 1990 ,ptm->tm_mon,ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
        return true;
    }
    else
    {
        return false;
    }
}


/*
 * @breif            创建目录
 * @param[in]        目录 
 *
 * @return           true 成功 false 失败 
 *
 */
static bool mkdir_for_log(const char * szFilePath);
{
    char DirName[1024] = { 0 };
    if ( szFilePath == NULL )
    {
        return false;
    }
    else
    {
        strcpy(DirName, szFilePath);      
    }
     
    strcpy(_g_log_info.szLogPath,DirName);

    len = strlen(DirName);             

    if('/' != DirName[len-1]) 
    {  
        strcat(DirName, "/"); 
        len++;
    }           
    for(i=1; i<len; i++)      
    {      
        if('/' == DirName[i])      
        {      
            DirName[i] = '\0';      
            if(access(DirName, F_OK) != 0)      
            {      
                if(mkdir(DirName, 0777) == -1)      
                {       
                    return false;       
                }      
            }    
            DirName[i] = '/';      
        }      
    }    
    return true;      
}

bool Init_Log ( const char *szFileName, const char * szFilePath, TLog_Level level, unsigned int size, TLog_Mode mode )
{
    bool res = false;
    char * szDefaultPath = "./";
    char * szDefaultName = "Default";
    char szFullFileName [ 1024 ] = { 0 };
    char szStrTime [ 64 ] = { 0 };

    //create log directory,if failed use default
    if (  ( mkdir_for_log ( szFilePath ) ) )
    {
        strcpy ( _g_log_info.szLogPath, szFilePath );
    }
    else
    {
        mkdir_for_log ( szDefaultPath );
        strcpy ( _g_log_info.szLogPath, szDefaultPath );
    }

    strcat ( szFulleFileName, _g_log_info.szLogPath);
    strcat ( szFulleFileName, "/");

    // open log file , if failed use default
    if ( szFileName == NULL )
    {
        strcat ( szFulleFileName,szFileName);
    }
    else
    {
        strcat ( szFulleFileName,szDefaultName);
    }
    
    if ( Get_Str_time_for_log ( szStrTime, sizeof ( szStrTime ) ) )
    {
        strcat ( szFulleFileName,"_" );
        strcat ( szFulleFileName,szStrTime );
    }

    strcpy ( _g_log_info.szLogName,szFullFileName);

    if ( ( _g_log_info.file_hanlde = fopen ( _g_log_info.szLogName,"ab" ) ) != NULL )
    {
        return false;
    }

    //set loglevel
    if ( level != ERROR_LEVEL && level != WARNING_LEVEL && level != DEBUG_LEVEL ) 
    {
        _g_log_info.level = ERROR_LEVEL;
    }
    else
    {
        _g_log_info.level = level;
    }

    //set size
    _g_log_info.size = size;
    
    //set mode
    if ( _g_log_info.mode != SCK_MODE && _g_long_info.mode != PTHREAD_MODE )
    {
        _g_log_info.mode = PTHREAD_MODE;
    }
    else
    {
        _g_log_info.mode = mode;
    }
    
    //
} 
