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
    printf("six %d\n",c); //��������
    return 0;
    */
    #include <stdio.h>
    #include <stdlib.h>
    #include "cJSON.h"
    //extern cJSON *cJSON_GetArrayItem(cJSON *array,int item);

void printJson(cJSON * root)//�Եݹ�ķ�ʽ��ӡjson�����ڲ��ֵ��
{
    for(int i=0; i<cJSON_GetArraySize(root); i++)   //���������json��ֵ��
    {
        cJSON * item = cJSON_GetArrayItem(root,i);
        if(cJSON_Object == item->type)      //�����Ӧ����ֵ��ΪcJSON_Object�͵ݹ����printJson
            printJson(item);
        else                                //ֵ��Ϊjson�����ֱ�Ӵ�ӡ������ֵ
        {
            printf("%s->", item->string);
            printf("%s\n", cJSON_Print(item));
        }
    }
}

int main()
{
    char * jsonStr = "{\"semantic\":{\"slots\":{\"name\":\"����\"}}, \"rc\":0, \"operation\":\"CALL\", \"service\":\"telephone\", \"text\":\"��绰������\"}";
    cJSON * root = NULL;
    cJSON * item = NULL;//cjson����

    root = cJSON_Parse(jsonStr);
    if (!root)
    {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
    }
    else
    {
        printf("%s\n", "�и�ʽ�ķ�ʽ��ӡJson:");
        printf("%s\n\n", cJSON_Print(root));
        printf("%s\n", "�޸�ʽ��ʽ��ӡjson��");
        printf("%s\n\n", cJSON_PrintUnformatted(root));

        printf("%s\n", "һ��һ���Ļ�ȡname ��ֵ��:");
        printf("%s\n", "��ȡsemantic�µ�cjson����:");
        item = cJSON_GetObjectItem(root, "semantic");//
        printf("%s\n", cJSON_Print(item));
        printf("%s\n", "��ȡslots�µ�cjson����");
        item = cJSON_GetObjectItem(item, "slots");
        printf("%s\n", cJSON_Print(item));
        printf("%s\n", "��ȡname�µ�cjson����");
        item = cJSON_GetObjectItem(item, "name");
        printf("%s\n", cJSON_Print(item));

        printf("%s:", item->string);   //��һ��cjson����Ľṹ������������Ա����˼
        printf("%s\n", item->valuestring);


        printf("\n%s\n", "��ӡjson�������ڲ��ֵ��:");
        printJson(root);
    }
    return 0;
}
//}main fun

