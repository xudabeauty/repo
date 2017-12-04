//#include <WINSOCK2.H>
//#include <stdio.h>
//#pragma comment(lib,"ws2_32.lib")
//typedef struct
//{
//  DWORD dwPidLen;
//  char pid[28];
//}CMDPIDINFO;
//void main()
//{
// //创建套接字
// WORD myVersionRequest;
// WSADATA wsaData;
// myVersionRequest=MAKEWORD(1,1);
// int err;
// err=WSAStartup(myVersionRequest,&wsaData);
// if (!err)
// {
//  printf("已打开套接字\n");
// } 
// else
// {
//  //进一步绑定套接字
//  printf("嵌套字未打开!");
//  return;
// }
// SOCKET serSocket=socket(AF_INET,SOCK_STREAM,0);//创建了可识别套接字
// //需要绑定的参数
// SOCKADDR_IN addr;
// addr.sin_family=AF_INET;
// addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//ip地址
// addr.sin_port=htons(8980);//绑定端口
//  
// bind(serSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR));//绑定完成
// listen(serSocket,5);//其中第二个参数代表能够接收的最多的连接数
//
// SOCKADDR_IN clientsocket;
// int len=sizeof(SOCKADDR);
//  SOCKET serConn=accept(serSocket,(SOCKADDR*)&clientsocket,&len);//如果这里不是accept而是conection的话。。就会不断的监听
//  //获取文件的长度
//  //char file[128]="D:\\c++primer.pdf";
//  //FILE*f=fopen(file,"r+b");
//  //fseek(f,0,SEEK_END);
//  //long filelength=ftell(f);
//  //fclose(f);
//
//  ////开始接受文件
//  //char buff[102400];  
//  //FILE *pFile; 
//  //char fileName[128]="F:\\c++primer.pdf";
//  //pFile=fopen(fileName,"a+b"); 
_int64 i=0;  
//  //  while(i+1<filelength)  
//  //  {  
//  //      int nRecv=recv(serConn,buff,102400,0);  
//  //        
//  //      fwrite(buff,sizeof(char),nRecv,pFile);  
//  //      i+=nRecv;  
//  //      memset(buff,0,sizeof(char)*102400);  
//  //  }  
//  //  fclose(pFile);  
//  char buff[1024];
//  memset(buff,0,1024);
//  recv(serConn,buff,1024,0);
//
//  CMDPIDINFO *cmdinfo;
//  memset(&cmdinfo,0,sizeof(cmdinfo));//清空结构体
//  cmdinfo=(CMDPIDINFO*)buff;
//  long length=cmdinfo->dwPidLen;
//  printf(cmdinfo->pid);
//  int len1=sizeof(cmdinfo);
//  char databuff[1024];
//  memset(databuff,0,1024);
//  memcpy(databuff,buff+32,100);
//  printf(databuff);
//
// closesocket(serConn);//关闭
// WSACleanup();//释放资源的操作
//}
//  