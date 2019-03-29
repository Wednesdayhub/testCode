//#include<stdio.h>

//void main(void)
//{
    //unsigned char a[]={0x2F,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    //unsigned char a[]={0x2F,0x31,0x02,0x4C,0x40,0x00,0xB0,0x40,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0x7F,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x3E,0x00,0x00};
    /*unsigned char a[20]={0x04,0x95,0x04,0x00};
    unsigned char buffer,len,i;
    buffer = 0;
    len = sizeof(a);
    printf("len is %d\n",len);
    for(i=0;i<len;i++)
    {
      buffer = a[i]+buffer;
    }
    printf("buffer is %x\n",buffer);*/


    /*printf("short int min=%hd\n",(short int)1<<(8*sizeof(short int)-1));
    printf("short int max=%hd\n",~((short int)1<<(8*sizeof(short int)-1)));
    printf("unsigned short int min=%hu\n",(unsigned short int)0);
    printf("unsigned short int max=%hu\n",(unsigned short int)~0);*/
   /* enum DAY
    {
          MON=1, TUE, WED, THU, FRI, SAT, SUN
    };
    enum DAY a;
    enum DAY b;
    int c = 0;
    a = TUE;
    printf("one %d\n",a);
    a = 10;
    printf("two %d\n",a);
    a = SAT;
    printf("three %d\n",a);
    b = SAT;
    printf("four %d\n",b);
    c = SAT;
    printf("five %d\n",c);
    c = a;
    printf("six %d\n",c); //保留疑问
    return 0;
    */
    #include <stdio.h>
    #include <stdlib.h>
    #include "cJSON.h"
    //extern cJSON *cJSON_GetArrayItem(cJSON *array,int item);

void printJson(cJSON * root)//以递归的方式打印json的最内层键值对
{
    for(int i=0; i<cJSON_GetArraySize(root); i++)   //遍历最外层json键值对
    {
        cJSON * item = cJSON_GetArrayItem(root,i);
        if(cJSON_Object == item->type)      //如果对应键的值仍为cJSON_Object就递归调用printJson
            printJson(item);
        else                                //值不为json对象就直接打印出键和值
        {
            printf("%s->", item->string);
            printf("%s\n", cJSON_Print(item));
        }
    }
}

int main()
{
    char * jsonStr = "{\"semantic\":{\"slots\":{\"name\":\"张三\"}}, \"rc\":0, \"operation\":\"CALL\", \"service\":\"telephone\", \"text\":\"打电话给张三\"}";
    cJSON * root = NULL;
    cJSON * item = NULL;//cjson对象

    root = cJSON_Parse(jsonStr);
    if (!root)
    {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
    }
    else
    {
        printf("%s\n", "有格式的方式打印Json:");
        printf("%s\n\n", cJSON_Print(root));
        printf("%s\n", "无格式方式打印json：");
        printf("%s\n\n", cJSON_PrintUnformatted(root));

        printf("%s\n", "一步一步的获取name 键值对:");
        printf("%s\n", "获取semantic下的cjson对象:");
        item = cJSON_GetObjectItem(root, "semantic");//
        printf("%s\n", cJSON_Print(item));
        printf("%s\n", "获取slots下的cjson对象");
        item = cJSON_GetObjectItem(item, "slots");
        printf("%s\n", cJSON_Print(item));
        printf("%s\n", "获取name下的cjson对象");
        item = cJSON_GetObjectItem(item, "name");
        printf("%s\n", cJSON_Print(item));

        printf("%s:", item->string);   //看一下cjson对象的结构体中这两个成员的意思
        printf("%s\n", item->valuestring);


        printf("\n%s\n", "打印json所有最内层键值对:");
        printJson(root);
    }
    return 0;
}
//}main fun

