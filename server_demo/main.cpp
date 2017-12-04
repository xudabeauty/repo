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
//    const long MAX_COMMAND_SIZE = 1000; // 命令行输出缓冲大小     
//    //char szFetCmd[] = "wmic cpu get processorid"; // 获取CPU序列号命令行    
//    //char szFetCmd[] = "ipconfig"; // 获取CPU序列号命令行    
//    //const string strEnSearch = "ProcessorId"; // CPU序列号的前导信息  
//
//    BOOL   result = FALSE;  
//    HANDLE hReadPipe = NULL; //读取管道  
//    HANDLE hWritePipe = NULL; //写入管道      
//    PROCESS_INFORMATION pi;   //进程信息      
//    STARTUPINFO         si;   //控制命令行窗口信息  
//    SECURITY_ATTRIBUTES pipeAttributes;   //安全属性  
//
//    char            *lpBuffer=new char[MAX_COMMAND_SIZE + 1] (); // 放置命令行结果的输出缓冲区  
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
//    //1.0 创建管道  
//    result = CreatePipe(&hReadPipe, &hWritePipe, &pipeAttributes, 0);  
//    if (!result)  
//    {  
//        goto END;  
//    }  
//
//    //2.0 设置命令行窗口的信息为指定的读写管道  
//    GetStartupInfo(&si);  
//    si.hStdError = hWritePipe;  
//    si.hStdOutput = hWritePipe;  
//    //si.hStdInput=hWritePipe;
//    si.wShowWindow = SW_HIDE; //隐藏命令行窗口  
//    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;  
//
//    //3.0 创建获取命令行的进程  
//    result = CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);  
//    if (!result)  
//    {  
//        goto END;  
//    }  
//
//    //4.0 读取返回的数据  
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
//    //关闭所有的句柄  
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
//    AllocConsole();//为进程创造一个新的控制台
//    HANDLE hOutputHandle=GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台输出句柄
//    DWORD nRet=0;
//    TCHAR buf[100]={0};//用来输出字符的缓冲区
//    lstrcpy(buf,TEXT("Hello"));
//    WriteConsole(hOutputHandle,buf,lstrlen(buf),&nRet,NULL);
//    WriteConsole(hOutputHandle,"\n",2,&nRet,NULL);
//    HANDLE hRutputHandle=GetStdHandle(STD_INPUT_HANDLE);//获得控制台输出句柄
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
//    cout<<"CMD结果 ："<<result<<endl;
//    system("pause");
//    return 0;
//}
// if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
//    {  
//        do  
//        {  
//            //如果是目录,迭代之  
//            //如果不是,加入列表  
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
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            //如果是目录,迭代之  
            //如果不是,加入列表  
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
	printf("文件总行数%ld",TotalLineCount);
	system("pause");
	

}