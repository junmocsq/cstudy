#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void s_fopen();
void s_freopen();
void s_tmpfile();
void s_buffer();
void s_remove();
void s_printf();
void s_seek();
int main(void)
{
    s_fopen();
    s_freopen();
    s_tmpfile();
    // s_buffer();
    s_remove();
    s_printf();
    s_seek();
    return 0;
}
#define N 100
void s_fopen()
{
    FILE *f1, *f2;
    if ((f1 = fopen("fff1.txt", "r")) == NULL)
    {
        printf("open read file failed!\n");
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen("fff2.txt", "w")) == NULL)
    {
        printf("open write file failed!\n");
        exit(EXIT_FAILURE);
    }

    char temp[N];
    while (!feof(f1))
    {
        fgets(temp, N, f1);
        // printf("--%s",temp);
        fputs(temp, f2);
    }
    fclose(f1);
    fclose(f2);
}

void s_freopen()
{
    FILE *f1, *f2;
    printf("该文本重定向到 stdout\n");
    if ((f1 = freopen("foo.txt", "w", stdout)) == NULL)
    {
        printf("reopen write file failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("1.该文本重定向到 file.txt\n");
    printf("2.该文本重定向到 file.txt\n");
    printf("3.该文本重定向到 file.txt\n");
    fclose(f1);
    fflush(f1); //将输出缓冲区清空
    freopen("/dev/tty", "w", stdout);

    if ((f2 = freopen("foo.txt", "r", stdin)) == NULL)
    {
        printf("reopen write file failed!\n");
        exit(EXIT_FAILURE);
    }
    char temp[N];
    puts(fgets(temp, N, f2));
    puts(fgets(temp, N, f2));
    puts(fgets(temp, N, f2));
    // putchar(getchar());
    // fflush(NULL);
    fclose(f2);

    // 恢复
    fflush(f2); //将输出缓冲区清空
    freopen("/dev/tty", "r", stdin);
}
void s_tmpfile(){
    FILE *f;
    if((f=tmpfile())==NULL){ // wb+
        printf("create temporary file failed!\n");
        exit(EXIT_FAILURE);
    }
    fputs("testabc",f);
    fseek(f,0L,SEEK_SET);
    char temp[N];
    puts(fgets(temp, N, f));
    fclose(f);

    char filename[L_tmpnam];
    tmpnam(filename);
    printf("tempfile:%s\n",filename);
}

void s_buffer(){
     FILE *f1;
    if ((f1 = fopen("fff.txt", "w+")) == NULL)
    {
        printf("open read file failed!\n");
        exit(EXIT_FAILURE);
    }
    char buffer[10];
    setvbuf(f1,buffer,_IOFBF,10); // 修改缓冲区大小为10
    char temp[N];
    while(fgets(temp,N,stdin)!=NULL){
        fputs(temp,f1);
        // fseek(f1,0,SEEK_SET);
        // fflush(f1);
        // printf("----\n");
        // puts(fgets(temp,N,f1));
    }
    fclose(f1);
}


void s_remove(){
    FILE *f = fopen("test.txt", "w+");
    fputs("ttttt",f);
    fclose(f);
    rename("test.txt","test-1.txt");
    remove("test-1.txt");
}

void s_printf()
{
    printf("test111\n");
    fprintf(stdout,"test stdout:%d %d\n",1,2);
    FILE *f = fopen("test.txt", "w+");
    fprintf(f,"test stdout:%d %d\n",1,2);
    fclose(f);
    f = fopen("test.txt", "r");
    char temp[N];
    
    fprintf(stdout,"%s",fgets(temp,N,f));
    fclose(f);
}

void s_seek(){
    FILE *f = fopen("test.txt", "wb+");
    for(int i=0; i<10;i++){
        fprintf(f,"test stdout:%d %d\n",1,2);
    }
    printf("ftell: %ld\n",ftell(f));
    fseek(f,ftell(f)+100000,SEEK_SET);
    for(int i=0; i<10;i++){
        fprintf(f,"test stdout:%d %d\n",1,2);
    }
    fclose(f);
    remove("test.txt");
}