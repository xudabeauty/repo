//#include<windows.h>
//#include<stdio.h>
//#include<iostream>
//#include<string>
//using namespace std;
//	 char readBuff[4096]={0};
//  char writeBuff[256]={0};
//	HANDLE  hReadPipeCmd=NULL;
//	HANDLE hWritePipeCmd=NULL;
//	HANDLE hWritePipeShell=NULL;
//	HANDLE hReadPipeShell=NULL;
//	HANDLE hProcessHandle;
//void initPipe()
//{
//
//
//      SECURITY_ATTRIBUTES sa = {0};
//      STARTUPINFO         si = {0};
//      PROCESS_INFORMATION pi = {0};
//
//      sa.nLength = sizeof(sa);
//      sa.lpSecurityDescriptor = NULL;
//      sa.bInheritHandle = TRUE;
//      //�����ܵ�
//      CreatePipe(&hReadPipeCmd,&hWritePipeCmd,&sa,0);
//      CreatePipe(&hReadPipeShell,&hWritePipeShell,&sa,0);
//
//      GetStartupInfo(&si);
//      si.cb = sizeof(STARTUPINFO);
//      //si.wShowWindow = SW_HIDE;
//     si.dwFlags = STARTF_USESTDHANDLES;
//      si.hStdInput = hReadPipeShell;
//      si.hStdOutput = si.hStdError = hWritePipeCmd;
//      //�ҵ�cmd�ľ���·��
//
//      wchar_t strShellPath[256]={0};
//      GetSystemDirectory(strShellPath, 256);
//      DWORD dwnum= WideCharToMultiByte(CP_ACP, 0, strShellPath, -1, NULL, 0, NULL, NULL);
//      char * cmdPath=new char[dwnum];
//      WideCharToMultiByte(CP_ACP, 0, strShellPath, -1, cmdPath, dwnum, NULL, NULL);
//      strcat(cmdPath,"\\cmd.exe");
//
//      DWORD mwnum=MultiByteToWideChar(CP_OEMCP,NULL,cmdPath,-1,NULL,0);
//      wchar_t *w_cmdPath=new wchar_t[mwnum];
//      MultiByteToWideChar(CP_OEMCP,NULL,cmdPath,-1,w_cmdPath,mwnum);
//
//      //����cmd����
//      BOOL ret=CreateProcess( TEXT("C://Windows//system32//cmd.exe"),NULL, NULL, NULL,FALSE,CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
//      if (!ret)
//      {
//          CloseHandle(hWritePipeCmd);
//          CloseHandle(hReadPipeShell);
//          return;
//      }
//      hProcessHandle = pi.hProcess;
//}
//
//void initShell()
//{
//     DWORD dwByteWritten;
//
//     WriteFile(hWritePipeShell,writeBuff,strlen(writeBuff),&dwByteWritten,0);//д�ܵ�
//     printf("д���ֽ���:%d\n",dwByteWritten);
//     memset(writeBuff,0,256);
//
//     //Sleep(1000);
//
//     unsigned long   BytesRead = 0;
//     DWORD TotalBytesAvail;
//
//     //���ܵ����Ƿ�������
//     while (PeekNamedPipe(hReadPipeCmd,readBuff, sizeof(readBuff), &BytesRead, &TotalBytesAvail, NULL))
//     {
//         if (TotalBytesAvail <= 0)
//             Sleep(600);
//         else
//         {
//             memset(readBuff, 0, sizeof(readBuff));
//
//             if(BytesRead==TotalBytesAvail)
//             {
//                 ReadFile(hReadPipeCmd, readBuff, TotalBytesAvail+100, &BytesRead, NULL);
//                 break;
//             }
//         }
//     }
//}
//
//
//
//
//bool  cmdControl(char * command, std::string &output)
//{
//    output="";
//    const long MAX_COMMAND_SIZE = 1000; // ��������������С
//    BOOL   result = FALSE;
//    HANDLE hReadPipe = NULL; //��ȡ�ܵ�
//    HANDLE hWritePipe = NULL; //д��ܵ�
//    PROCESS_INFORMATION pi;   //������Ϣ
//    STARTUPINFO         si;   //���������д�����Ϣ
//    SECURITY_ATTRIBUTES pipeAttributes;   //��ȫ����
//
//    char            *lpBuffer=new char[MAX_COMMAND_SIZE + 1] (); // ���������н�������������
//    string          strBuffer;
//    unsigned long   count = 0;
//    long            ipos = 0;
//
//    memset(&pi, 0, sizeof(pi));
//    memset(&si, 0, sizeof(si));
//    memset(&pipeAttributes, 0, sizeof(pipeAttributes));
//
//    pi.hProcess = NULL;
//    pi.hThread = NULL;
//    si.cb = sizeof(STARTUPINFO);
//    pipeAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
//    pipeAttributes.lpSecurityDescriptor = NULL;
//    pipeAttributes.bInheritHandle = TRUE;
//
//    //1.0 �����ܵ�
//    result = CreatePipe(&hReadPipe, &hWritePipe, &pipeAttributes, 0);
//
//    //2.0 ���������д��ڵ���ϢΪָ���Ķ�д�ܵ�
//    GetStartupInfo(&si);
//    si.hStdError = hWritePipe;
//    si.hStdOutput = hWritePipe;
//    //si.hStdInput=hWritePipe;
//    si.wShowWindow = SW_HIDE; //���������д���
//    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
//
//    //3.0 ������ȡ�����еĽ���
//
//    wchar_t comm[48]=L"C:\\Windows\\system32\\cmd.exe";
//    result = CreateProcess(NULL, comm, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
//
//    //4.0 ��ȡ���ص�����
//    WaitForSingleObject(pi.hProcess, 500/*INFINITE*/);
//    result = ReadFile(hReadPipe, lpBuffer, MAX_COMMAND_SIZE, &count, 0);
//    if (count>MAX_COMMAND_SIZE)
//    {
//        delete[]lpBuffer;
//        lpBuffer=new char[count+1]();
//        int lpBuffer_size=count;
//        result = ReadFile(hReadPipe, lpBuffer, lpBuffer_size, &count, 0);
//    }
//
//    output=lpBuffer;
//    result = TRUE;
//    //�ر����еľ��
//    CloseHandle(hWritePipe);
//    CloseHandle(hReadPipe);
//    CloseHandle(pi.hProcess);
//    CloseHandle(pi.hThread);
//    delete[]lpBuffer;
//    return(result);
//}
//
//
//int main()
//{
//	initPipe();
//	initShell();
//}
