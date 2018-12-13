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
static bool Get_Str_time_for_log ( char * szStrTime, size_t iSizeOfStrTime )
{
    time_t t;
    struct tm * ptm = NULL;
    
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
        snprintf ( szStrTime,iSizeOfStrTime,"%04d_%02d%02d_%02d%02d%02d",ptm->tm_year + 1990 ,ptm->tm_mon + 1,ptm->tm_mday,ptm->tm_hour + 8 ,ptm->tm_min,ptm->tm_sec);
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * @breif   获取当前文件size 若超过最大size则创建新文件
 *
 * return   true 成功 false 失败
 */
static bool create_new_file ()
{ 
    //获取当前文件size 若超过最大size则创建新文件
    char szFullFileName [1024] = {0};
    char szStrTime [ 64 ] = { 0 };
    long cnt=ftell(_g_log_info.file_handle); 
    if ( cnt >= _g_log_info.size * 1024 * 1024 )
    {
        
        Get_Str_time_for_log ( szStrTime, sizeof (szStrTime) );
        strcpy ( szFullFileName, _g_log_info.szLogPath );
        strcat ( szFullFileName, "/" );
        strcat ( szFullFileName, _g_log_info.szLogName );
        strcat ( szFullFileName, "_" );
        strcat ( szFullFileName, szStrTime );
        strcat ( szFullFileName, ".log" );

        pthread_mutex_lock ( &_g_log_info.lock );
        fclose ( _g_log_info.file_handle );
        if ( ( _g_log_info.file_handle = fopen ( szFullFileName,"ab" ) ) != NULL )
        {
            pthread_mutex_unlock ( &_g_log_info.lock );
            return true;
        }
        else
        {
            pthread_mutex_unlock ( &_g_log_info.lock );
            return false;
        }

    }
    return true;
}

/*
 * @breif            创建目录
 * @param[in]        目录 
 *
 * @return           true 成功 false 失败 
 *
 */
static bool mkdir_for_log(const char * szFilePath)
{
    char DirName[1024] = { 0 };
    int i = 0;
    if ( szFilePath == NULL )
    {
        return false;
    }
    else
    {
        strcpy(DirName, szFilePath);      
    }
     
    strcpy(_g_log_info.szLogPath,DirName);

    int len = strlen(DirName);             

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
 
bool Init_log(const char *szFileName, const char * szFilePath,TLog_Level level,unsigned int size,TLog_Mode mode)
{
#ifdef LYW_CODE_LOG_ON
    char szDefaultPath[] = "./";
    char szDefaultName[] = "Default";
    char szFullFileName [ 1024 ] = { 0 };
    char szStrTime [ 64 ] = { 0 };
    _g_p_log_info = & _g_log_info;
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

    strcat ( szFullFileName, _g_log_info.szLogPath);
    strcat ( szFullFileName, "/");

    // open log file , if failed use default
    if ( szFileName != NULL )
    {
        strcpy ( _g_log_info.szLogName,szFileName);
        strcat ( szFullFileName,szFileName);
    }
    else
    {
        strcpy ( _g_log_info.szLogName,szDefaultName);
        strcat ( szFullFileName,szDefaultName);
    }
    
    if ( Get_Str_time_for_log ( szStrTime, sizeof ( szStrTime ) ) )
    {
        strcat ( szFullFileName,"_" );
        strcat ( szFullFileName,szStrTime );
    }
    strcat ( szFullFileName,".log");
    if ( ( _g_log_info.file_handle = fopen ( szFullFileName,"ab" ) ) == NULL )
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
    if ( _g_log_info.mode != SCK_MODE && _g_log_info.mode != PTHREAD_MODE )
    {
        _g_log_info.mode = PTHREAD_MODE;
    }
    else
    {
        _g_log_info.mode = mode;
    }

    if ( _g_log_info.mode == SCK_MODE )
    {
        printf ( "Not Support it! Waiting Finished!\n" );
        _g_log_info.mode = PTHREAD_MODE;
    }

    if ( _g_log_info.mode == SCK_MODE )
    {
        //add start logic here
    }

    //init pthread_mutex
    pthread_mutex_init ( &_g_log_info.lock,NULL );
#endif
    return true;
} 


void user_error_log ( const char * szFormat,...)
{
    
#ifdef LYW_CODE_LOG_ON
    struct timeval tv;
    struct timezone tz;
    char strtime[64] = {0};
    if ( _g_log_info.level >= ERROR_LEVEL )
    {
        gettimeofday ( &tv, &tz );
        Get_Str_time_for_log ( strtime ,sizeof(strtime));
        va_list ap;
        va_start ( ap, szFormat );
        pthread_mutex_lock ( &_g_log_info.lock );
        fprintf ( _g_log_info.file_handle,"[ERROR][%s %ld%ld][%d]::",strtime,tv.tv_sec,tv.tv_usec,getpid());
        vfprintf ( _g_log_info.file_handle,szFormat, ap );
        fprintf ( _g_log_info.file_handle,"\n");
        pthread_mutex_unlock ( &_g_log_info.lock );
        va_end(ap);
        create_new_file ();
    }
#endif

}
void user_warning_log ( const char * szFormat,...)
{

#ifdef LYW_CODE_LOG_ON
    struct timeval tv;
    struct timezone tz;
    char strtime[64] = {0};
    if ( _g_log_info.level >= WARNING_LEVEL )
    {
        gettimeofday ( &tv, &tz );
        Get_Str_time_for_log ( strtime ,sizeof(strtime));
        va_list ap;
        va_start ( ap, szFormat );
        pthread_mutex_lock ( &_g_log_info.lock );
        fprintf ( _g_log_info.file_handle,"[WARNING][%s %ld%ld][%d]::",strtime,tv.tv_sec,tv.tv_usec,getpid());
        vfprintf ( _g_log_info.file_handle,szFormat, ap );
        fprintf ( _g_log_info.file_handle,"\n");
        pthread_mutex_unlock ( &_g_log_info.lock );
        va_end(ap);
        create_new_file ();
    }
#endif

}
void user_debug_log ( const char * szFormat,...)
{

#ifdef LYW_CODE_LOG_ON
    struct timeval tv;
    struct timezone tz;
    char strtime[64] = {0};
    if ( _g_log_info.level >= WARNING_LEVEL )
    {
        gettimeofday ( &tv, &tz );
        Get_Str_time_for_log ( strtime,sizeof(strtime));
        va_list ap;
        va_start ( ap, szFormat );
        pthread_mutex_lock ( &_g_log_info.lock );
        fprintf ( _g_log_info.file_handle,"[DEBUG][%s %ld%ld][%d]::",strtime,tv.tv_sec,tv.tv_usec,getpid());
        vfprintf ( _g_log_info.file_handle,szFormat, ap );
        fprintf ( _g_log_info.file_handle,"\n");
        pthread_mutex_unlock ( &_g_log_info.lock );
        va_end(ap);
        create_new_file ();
    }
#endif
}
