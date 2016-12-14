#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <time.h>
#include <keyvalue.h>
#include <fcntl.h>
void My_thread1(int dev)
{
    
    char data[1024];
    int tid;
    int a;
    for(i = 0; i < 10; i++)
    {
        memset(data, 0, 1024);
        a = rand();
        sprintf(data,"%d",a);
        tid = kv_set(dev,i,strlen(data),data);
        fprintf(stderr,"thread1\t%d\t%d\t%d\t%s\n",tid,i,strlen(data),data);
    }
    pthread_exit(0);
}
void My_thread1(int dev)
{
    
    char data[1024];
    int tid;
    int a;
    for(i = 0; i < 10; i++)
    {
        memset(data, 0, 1024);
        a = rand();
        sprintf(data,"%d",a);
        tid = kv_set(dev,i,strlen(data),data);
        fprintf(stderr,"thread2\t%d\t%d\t%d\t%s\n",tid,i,strlen(data),data);
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int i=0,number_of_threads = 1, number_of_keys=1024, number_of_transactions = 65536; 
    int a;
    char b;
    int tid;
    __u64 size;
    char data[1024];
    int devfd;
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s number_of_keys number_of_transactions\n",argv[0]);
        exit(1);
    }
    number_of_keys = atoi(argv[1]);
    number_of_transactions = atoi(argv[2]);
    devfd = open("/dev/keyvalue",O_RDWR);
    if(devfd < 0)
    {
        fprintf(stderr, "Device open failed");
        exit(1);
    }
    srand((int)time(NULL)+(int)getpid());
    // Initializing the keys
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,(void *)My_thread1,&devfd);
    pthread_create(&thread2,NULL,(void *)My_thread2,&devfd);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    close(devfd);
    return 0;
}

