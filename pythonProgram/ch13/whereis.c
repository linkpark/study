#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

char filename[256][256];
int len = 0;

int whereis(char* path, int depth,char str[],int l)
{
    DIR *d; /*声明一个句柄*/

    struct dirent *file; /*readdir函数的返回值就存放在这个结构体中*/

    struct stat sb;

    if(!(d = opendir(path)))
    {
        printf("error\n");

        return -1;
    }

    while((file = readdir(d)) != NULL)
    {
        /*把当前目录.，上一级目录..及隐藏文件都去掉，避免死循环遍历目录*/

        if(strncmp(file->d_name, ".",1) == 0 )
           continue;

        /*判断该文件是否是目录，及是否已搜索了三层，这里我定义只搜索了三层目录*/

        if(stat(file->d_name, &sb) >= 0 && S_ISDIR(sb.st_mode) && depth <= 3)
        {

            whereis(file->d_name, depth+1,str,l);
        }
        
        int size=strlen(file->d_name);
 
        if(strcmp(file->d_name+(size-l),str)!=0) 
           continue;
        strcpy(filename[len++], file->d_name); /*保存匹配到的文件名*/
    }

    closedir(d);
    return 0;
}

int main()
{
   int depth = 1;
   char str[50];
   printf("请输入要匹配的后缀名：\n");
   gets(str);
   int l=strlen(str);
 
   whereis("./", depth,str,l);
   
   printf("匹配的文件有:\n");
   int i;
   for(i = 0; i < len; i++)
   {   
       printf("%s\t", filename[i]);
   }
   printf("\n");
   return 0;
}
