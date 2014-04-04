#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
pthread_t pid_new_job;  
CourseInfo NextCourseInfo;

#define ID_SIZE 48+1 

struct CourseInfo{
    
    char ID[ID_SIZE];
    int Last_Percent;
    CourseInfo()
    {
        memset(ID,0,sizeof(ID));      
        Last_Percent = 0;
    }
};

void *thread_handleSpace(void *args)
{
    printf("\n======= thread_handleSpace Begin =======\n");
    CourseInfo *pCI = (CourseInfo*)args;
    printf("\n======= thread_handleSpace End =======\n");
    pthread_exit(NULL);
}

int main(void)
{
       strcpy(NextCourseInfo.ID ,"121");
    pthread_attr_t attr;
        
    int res ;
    res = pthread_attr_init(&attr);//属性
    if(res != 0)
    {
        printf("exit 1");
        return -1;
    }
    
    res = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);//建立线程的争用范围（PTHREAD_SCOPE_SYSTEM 或 PTHREAD_SCOPE_PROCESS）。 使用 PTHREAD_SCOPE_SYSTEM 时，此线程将与系统中的所有线程进行竞争。使用 PTHREAD_SCOPE_PROCESS 时，此线程将与进程中的其他线程进行竞争
    res += pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(res != 0)
    {
        printf("exit 2");
        return -1;
    }
    
    res = pthread_create(&pid_new_job, NULL, thread_handleSpace, (void *) &NextCourseInfo);//全局的NextCourseInfo,为了防止销毁了该变量（此前在这的sleep 可以不用）
       //    pthread_join(pid_new_job,NULL);//无需此句了。
    pthread_attr_destroy(&attr);
    return 0;
}