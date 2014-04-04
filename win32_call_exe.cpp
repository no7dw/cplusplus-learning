int main(){
	char ActiveCmd[200] ={0};
        sprintf(ActiveCmd, "%s %s", argv[1]  , argv[2] );
        printf( "%s\n", ActiveCmd);
         
/** 转换char * ---> TCHAR  **/
        int actcnt = MultiByteToWideChar(CP_ACP, NULL, ActiveCmd, -1, NULL, 0);
        TCHAR * pbuffer = new TCHAR[actcnt + 1];
        memset(pbuffer, 0, sizeof(pbuffer));
        MultiByteToWideChar(CP_ACP, NULL, ActiveCmd, -1, pbuffer, actcnt);
        
        SHELLEXECUTEINFO ShExecInfo = {0};
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        ShExecInfo.hwnd = NULL;
        ShExecInfo.lpVerb = L"open";//多种类别有 "explorer" "print" 等
        ShExecInfo.lpFile = EXE_FILE;//exe 路径    
        ShExecInfo.lpParameters = pbuffer;//参数
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_HIDE;//
        ShExecInfo.hInstApp = NULL;
        ShellExecuteEx(&ShExecInfo);

        printf("waiting... \n ");    
        WaitForSingleObject(ShExecInfo.hProcess, INFINITE);//等待完成   第二个参数是超时时间（毫秒）超时后返回超时代码     
        
        delete pbuffer;

        pbuffer = NULL;
}
