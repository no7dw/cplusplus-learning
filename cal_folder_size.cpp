void UTIL_CountFileSize(const char *dir, long &fsize)

{

#ifndef WIN32

    DIR *dp;

    struct dirent *entry;

    struct stat statbuf;

    

    if((dp = opendir(dir)) == NULL)

    {

        fprintf(stderr ,"cannot open dirctory : %s \n", dir);

        return ;

    }

    chdir(dir);//注意这里改变了工作路径

    while((entry = readdir(dp)) != NULL)

    {

        lstat(entry->d_name, &statbuf);

        if(S_ISDIR(statbuf.st_mode))

        {

            if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)

            {

                continue;

            }

            else

            {

                fsize += statbuf.st_size;

                UTIL_CountFileSize(entry->d_name, fsize);

            }

        }

        fsize += statbuf.st_size;

        

    }

    chdir("..");//needed 

    closedir(dp);

#else



    char szFind[MAX_PATH];

    char szFileTemp[MAX_PATH];

    WIN32_FIND_DATA FindFileData;



    strcpy(szFind,dir);

    strcat(szFind,"\\*.*");



    int actcnt = MultiByteToWideChar(CP_ACP, NULL, szFind, -1, NULL, 0);

    TCHAR * pbuffer = new TCHAR[actcnt + 1];

    memset(pbuffer, 0, sizeof(pbuffer));

    MultiByteToWideChar(CP_ACP, NULL, szFind, -1, pbuffer, actcnt);



    HANDLE hFind = ::FindFirstFile(pbuffer ,&FindFileData);

    if(INVALID_HANDLE_VALUE == hFind)   

        return;

   

    while(TRUE)

    {

        if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

        {

            if(FindFileData.cFileName[0]!='.')

            {                                  

                DWORD dwMinSize = WideCharToMultiByte (CP_OEMCP, NULL, FindFileData.cFileName ,-1, NULL, 0, NULL, 0);

                char *cTemp =  new char[dwMinSize + 1];

                memset(cTemp, 0 , sizeof(cTemp));

                WideCharToMultiByte (CP_OEMCP, NULL, FindFileData.cFileName ,-1, cTemp, sizeof(FindFileData.cFileName)/sizeof(FindFileData.cFileName[0]), NULL, 0);

                sprintf(szFileTemp,"%s\\%s", dir, cTemp);                              

                UTIL_CountFileSize(szFileTemp,fsize);                

            }

        }

        else

        {

            fsize += (long) FindFileData.nFileSizeLow;            

        }

        if(!FindNextFile(hFind,&FindFileData))    break;

    }

    FindClose(hFind);



#endif

}
