#include "MQTT.h"
#include <time.h>

int timeInterval = 20;
int index = 1;
time_t  now = 0;
FILE * f = NULL ;

void writeToFile ( const char * imsi, int Len )
{
    time_t t;
    struct tm tt;
    t = time(NULL);
    int devID;
    char fileName[1024] = {0};
    if ( t - now >= timeInterval )
    {
        now = t;
        if ( f != NULL )
        {
           fclose(f);
           system ( "cp ./tmp/* ./data/");
           system ( "rm ./tmp/*");
        }
        localtime_r (&t,&tt);
        memset(fileName, 0x00, 1024);
        sprintf(fileName,"./tmp/IMSI%04d%02d%02d-%02d%02d%02d_9999.txt", tt.tm_year + 1900 ,tt.tm_mon,tt.tm_mday,tt.tm_hour,tt.tm_min,tt.tm_sec);
        f = fopen ( fileName, "a+" );
    }
    if ( imsi != NULL && Len > 0 )
    {
        memcpy(&devID,imsi + 4,4);
        if ( devID == 400 )
        {
            devID = 365;
            memcpy ( imsi + 4, &devID, 4 );
        }
        else if ( devID == 401 )
        {
            devID = 366;
            memcpy ( imsi + 4, &devID, 4 );
        }
        else
        {

            printf ("Error::unkown DEVID [%d]\n",devID);
            devID = 100;
            memcpy ( imsi + 4, &devID, 4 );
        }
        fwrite(imsi,Len,1,f);
        fwrite("\xFF\xFF\xFF",3,1,f);
    }
}

void my_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
    if(message->payloadlen)
    {

        if ( strcmp ( message->topic,"Msg" ) == 0 )
        {
            writeToFile (message->payload,message->payloadlen);
        }
        else
        {
            printf("%s %s\n", message->topic, message->payload);
        }
    }else
    {
        printf("%s (null)\n", message->topic);
    }


    fflush(stdout);
}


void my_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
    //int i;
    //if(!result)
    //{
    //    mosquitto_subscribe(mosq, NULL, "$SYS/#", 2);
    //}
    //else
    //{
    //    fprintf(stderr, "Connect failed\n");
    //}
}

void my_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
    int i;
    printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
    for(i=1; i<qos_count; i++)
    {
        printf(", %d", granted_qos[i]);
    }
    printf("\n");
}

static void my_log_callback(struct mosquitto *mosq, void *userdata, int level, const char *str)
{
    //printf("in %s :: %s\n", __func__,str);
}

void SimpleTest()
{
    char host[] = "192.168.8.200";
    int port = 8883;
    int keepalive = 10000;
    bool clean_session = true;
    struct mosquitto * mosq = NULL;
    struct mosquitto_message *msg;
    mosquitto_lib_init();
    mosq = mosquitto_new(NULL, clean_session, NULL);
    if ( mosq == NULL )
    {
        printf ( "New mosq_str failed!\n" );
        return;
    }
    
    mosquitto_log_callback_set(mosq, my_log_callback);
    mosquitto_connect_callback_set(mosq, my_connect_callback);
    mosquitto_message_callback_set(mosq, my_message_callback);
    mosquitto_subscribe_callback_set(mosq, my_subscribe_callback);

    if ( mosquitto_tls_set ( mosq,"/home/Lession/Tool_C/Tool_C/src/MQTTDeamon/ca/ca.crt",NULL,"/home/Lession/Tool_C/Tool_C/src/MQTTDeamon/ca/client.crt","/home/Lession/Tool_C/Tool_C/src/MQTTDeamon/ca/client.key",NULL) != MOSQ_ERR_SUCCESS )
    {
        fprintf(stdout, "set tls error.\n");
        return ;
    }

    if ( mosquitto_username_pw_set ( mosq, "TestTY", "123456" ) != MOSQ_ERR_SUCCESS )
    {
        fprintf ( stdout, "set pw failed!\n" );
        return ;
    }

    if ( mosquitto_connect(mosq, host, port, keepalive) )
    {
        fprintf(stderr, "Unable to connect.\n");
        return ;
    }

    //mosquitto_loop_stop(mosq,false);
    
    int rc = 0;
    rc = mosquitto_subscribe(mosq, NULL,"ue.data/330301/000000000000000000001",1 );
    rc = mosquitto_subscribe(mosq, NULL,"Msg",1 );


    //while ( true )
    //{
    //    if ( mosquitto_publish ( mosq,NULL,"ue.data/330301/345",6,"123456",0,false) != MOSQ_ERR_SUCCESS )
    //    {
    //        fprintf ( stdout, "pub failed!\n" );
    //    }

    //    fprintf ( stdout, "pub OK!\n" );
    //    sleep(2);

    //}
    mosquitto_loop_forever(mosq, -1, 1);

    //mosquitto_loop_start(mosq);
    //mosquitto_loop_stop(mosq,1);
    

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}
