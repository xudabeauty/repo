//
//#include <iostream>
//#include <windows.h>
//#include <string>
//using namespace std;
//
////bool cmdControl(char *lpszCpu, int len/*=128*/)  
//bool cmdControl(char * command, std::string &output)  
//{     
//    output="";
//    const long MAX_COMMAND_SIZE = 1000; // ��������������С     
//    //char szFetCmd[] = "wmic cpu get processorid"; // ��ȡCPU���к�������    
//    //char szFetCmd[] = "ipconfig"; // ��ȡCPU���к�������    
//    //const string strEnSearch = "ProcessorId"; // CPU���кŵ�ǰ����Ϣ  
//
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
//    if (!result)  
//    {  
//        goto END;  
//    }  
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
//    result = CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);  
//    if (!result)  
//    {  
//        goto END;  
//    }  
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
//    if (!result)  
//    {  
//        goto END;  
//    }  
//
//
//    output=lpBuffer;
//    
//    result = TRUE;  
//
//END:  
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
//int _stdcall WinMain(
//    HINSTANCE hInstance,
//    HINSTANCE hPrevInstance,
//    LPTSTR lpCmdLine,
//    int nCmdShow
//    )
//{
//    
//    AllocConsole();//Ϊ���̴���һ���µĿ���̨
//    HANDLE hOutputHandle=GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨������
//    DWORD nRet=0;
//    TCHAR buf[100]={0};//��������ַ��Ļ�����
//    lstrcpy(buf,TEXT("Hello"));
//    WriteConsole(hOutputHandle,buf,lstrlen(buf),&nRet,NULL);
//    WriteConsole(hOutputHandle,"\n",2,&nRet,NULL);
//    HANDLE hRutputHandle=GetStdHandle(STD_INPUT_HANDLE);//��ÿ���̨������
//    ReadConsole(hRutputHandle, buf, sizeof(buf), &nRet, NULL);
//    system("pause");
//
//
//    char command[]="ipconfig";
//    std::string result="";
//    cmdControl(command, result);
//
//
//  
//
//    FreeConsole();
//
//    cout<<"CMD��� ��"<<result<<endl;
//    system("pause");
//    return 0;
//}
// if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
//    {  
//        do  
//        {  
//            //�����Ŀ¼,����֮  
//            //�������,�����б�  
//            if((fileinfo.attrib &  _A_SUBDIR))  
//            {  
//                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
//                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
//            }  
//            else  
//            {  
//                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
//            }  
//        }while(_findnext(hFile, &fileinfo)  == 0);  
//        _findclose(hFile);  
//    }  
//}  

#include<Windows.h>
#include<string>
#include<stdlib.h>
#include <fstream>
#include<stdio.h>
#include<io.h>
#include<vector>
#include<iostream>
using namespace std;
DWORD TotalLineCount;
vector<string> filenames;
void getFiles( string path, vector<string>& files )  
{  
    //�ļ����  
    long   hFile   =   0;  
    //�ļ���Ϣ  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            //�����Ŀ¼,����֮  
            //�������,�����б�  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
            }  
            else  
            {  
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}  
void countLine(string path)
{
	long hFile;
	struct _finddata_t fileinfo;
	string p;
	hFile=_findfirst(p.assign(path).append("\\*").c_str(),&fileinfo);
	if(hFile!=-1)
	{
		while (_findnext(hFile,&fileinfo)==0)
		
		{
			string subfile=p.assign(path).append("\\").append(fileinfo.name);
			if(fileinfo.attrib&_A_SUBDIR)
			{
				 if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  				
				 countLine(subfile);
			}else
			{
				
				filenames.push_back(subfile);		
			}


		}
	}
	_findclose(hFile);
}
int main()
{
	
	string path1="C:\\Users\\xudab\\Desktop\\SecRtcControlRemote\\SecRtcControlRemote\\include";
	string path2="C:\\Users\\xudab\\Desktop\\SecRtcControlRemote\\SecRtcControlRemote\\src";
	
	countLine(path1);
	countLine(path2);
	vector <string>::iterator it;
	for(it=filenames.begin();it!=filenames.end();it++)
	{
		string file=*it;
		ifstream ReadFile(file);
		string temp;
		while (ReadFile)
		{
			getline(ReadFile,temp);
			TotalLineCount++;
		}
		ReadFile.close();
	}
	printf("�ļ�������%ld",TotalLineCount);
	system("pause");
	

}