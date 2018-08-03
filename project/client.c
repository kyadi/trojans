#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void str_echo(int s)
    {
        char buf[1024],buf1[1024];
        char colon = ';';
        int i;
        S :puts("Enter the job...");
        gets(buf);
       
        //sending data to server
        
        send(s,buf,1024,0); 

        if (strchr(buf,colon)==NULL){

        //receiving data from server
        recv(s,buf1,1024,0);
        puts("Message from Server...");
        printf("%s\n",buf1);
         goto S;
     }
        else{
        char * token = strtok(buf,";");
        char *store[1024];
        for(i=0;(token != NULL); (token = strtok(NULL,";"))){
                //Pointer array to store the individual jobs
            store[i]=token;
            i++;  
        }
            store[i]=NULL;
            for (i=0;store[i]!=NULL;i++){
                recv(s,buf1,1024,0);
        puts("Message from Server...");
        printf("%s\n",buf1);
         

        }
        goto S;
    }


}
  
int main()
{
    int ls, cs;
    struct sockaddr_in cli;
    puts("I am Client...");
/*creating socket*/
    ls=socket(AF_INET,SOCK_STREAM,0);
    puts("Socket Created Successfully...");
/*socket address structure*/
    cli.sin_family=AF_INET;
    cli.sin_addr.s_addr=inet_addr("127.0.0.1");
    cli.sin_port=htons(5000);
 /*connecting to server*/
    connect(ls,(struct sockaddr*)&cli,sizeof(cli));
    puts("Connected to Server...");

    str_echo(ls);

    puts("\nthank you for using wts.......");
    close(ls);
    str_echo(cs);
    close(ls);
return 0;
}