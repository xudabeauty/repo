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
// //�����׽���
// WORD myVersionRequest;
// WSADATA wsaData;
// myVersionRequest=MAKEWORD(1,1);
// int err;
// err=WSAStartup(myVersionRequest,&wsaData);
// if (!err)
// {
//  printf("�Ѵ��׽���\n");
// } 
// else
// {
//  //��һ�����׽���
//  printf("Ƕ����δ��!");
//  return;
// }
// SOCKET serSocket=socket(AF_INET,SOCK_STREAM,0);//�����˿�ʶ���׽���
// //��Ҫ�󶨵Ĳ���
// SOCKADDR_IN addr;
// addr.sin_family=AF_INET;
// addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//ip��ַ
// addr.sin_port=htons(8980);//�󶨶˿�
//  
// bind(serSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR));//�����
// listen(serSocket,5);//���еڶ������������ܹ����յ�����������
//
// SOCKADDR_IN clientsocket;
// int len=sizeof(SOCKADDR);
//  SOCKET serConn=accept(serSocket,(SOCKADDR*)&clientsocket,&len);//������ﲻ��accept����conection�Ļ������ͻ᲻�ϵļ���
//  //��ȡ�ļ��ĳ���
//  //char file[128]="D:\\c++primer.pdf";
//  //FILE*f=fopen(file,"r+b");
//  //fseek(f,0,SEEK_END);
//  //long filelength=ftell(f);
//  //fclose(f);
//
//  ////��ʼ�����ļ�
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
//  memset(&cmdinfo,0,sizeof(cmdinfo));//��սṹ��
//  cmdinfo=(CMDPIDINFO*)buff;
//  long length=cmdinfo->dwPidLen;
//  printf(cmdinfo->pid);
//  int len1=sizeof(cmdinfo);
//  char databuff[1024];
//  memset(databuff,0,1024);
//  memcpy(databuff,buff+32,100);
//  printf(databuff);
//
// closesocket(serConn);//�ر�
// WSACleanup();//�ͷ���Դ�Ĳ���
//}
//  