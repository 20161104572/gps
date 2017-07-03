#include <stdio.h>

int main(int argc, const char * argv[]) {
    char sp1[80];
    char sp2[80];
    char latitude[11];//纬度
    char longitude[11];//经度
    char time[8];//时间
    char date[8];//日期
    char latitude_direction[3];//纬度方向
    char longitude_direction[3];//经度方向
    char altitude[6];//海拔
    char rate[8];//速率
    char satellites[3];//卫星颗数
    char course[6];//航向
    double speed;
    int i;
    int math,math1,math2;
    FILE *fp;
    FILE *fr;
    fp=fopen("//Users//a20161104572//Desktop//gps//GPS170510.log","r");
    fr=fopen("//Users//a20161104572//Desktop//gps//aaa.csv","w");
    
    if (fp == NULL)
    {
        printf("打开文件错误!\n");
    }
    else
    {
        fprintf(fr," 日期 , 时间 , 纬度方向, 纬度／度 , 经度方向, 经度／度 , 航向／度 ，海拔／米 ,速度/km/h , 卫星颗数／颗\n");
    }
    
    while(fscanf(fp,"%s%s",sp1,sp2)!=EOF)
    {
        i=0;
        while(sp1[i+55]!=',')
        {
            date[i]=sp1[i+55];
            i++;
        }
        date[2]='\0';
        fprintf(fr,"20%s年",date);
                
                i=0;
                while(sp1[i+55]!=',')
                {
                    date[i]=sp1[i+53];
                    i++;
                }
                date[2]='\0';
                fprintf(fr,"%s月",date);
                        
                        i=0;
                        while(sp1[i+51]!=',')
                        {
                            date[i]=sp1[i+51];
                            i++;
                        }
                        date[2]='\0';
                        fprintf(fr,"%s日,",date);
                        
                        i=0;
                        while(sp1[i+7]!=',')
                        {
                            time[i]=sp1[i+7];
                            i++;
                        }
                        math1=10*(time[0]-'0');
                        math2=1*(time[1]-'0');
                        math=math1+math2+8;
                        fprintf(fr,"%d时",math);
                                
                                i=0;
                                while(sp1[i+9]!=',')
                                {
                                    time[i]=sp1[i+9];
                                    i++;
                                }
                                math1=10*(time[0]-'0');
                                math2=1*(time[1]-'0');
                                math=math1+math2;
                                time[2]='\0';
                                fprintf(fr,"%d分",math);
                                        
                                        i=0;
                                        while(sp1[i+11]!=',')
                                        {
                                            time[i]=sp1[i+11];
                                            i++;
                                        }
                                        math1=10*(time[0]-'0');
                                        math2=1*(time[1]-'0');
                                        math=math1+math2;
                                        time[2]='\0';
                                        fprintf(fr,"%d秒，  ",math);
                                        
                                        i=0;
                                        while(sp1[i+16]!=',')
                                        {
                                            latitude[i]=sp1[i+16];
                                            i++;
                                        }
                                        latitude[10]='\0';
                                        fprintf(fr," %s, ",latitude);
                                        //纬度
                                        i=0;
                                        while(sp1[i+25]!=',')
                                        {
                                            latitude_direction[i]=sp1[i+25];
                                            i++;
                                        }
                                        latitude_direction[2]='\0';
                                        fprintf(fr,"%s, ",latitude_direction);
                                        //纬度方向
                                        i=0;
                                        while(sp1[i+27]!=',')
                                        {
                                            longitude[i]=sp1[i+27];
                                            i++;
                                        }
                                        longitude[10]='\0';
                                        fprintf(fr," %s, ",longitude);
                                        //经度
                                        i=0;
                                        while(sp1[i+37]!=',')
                                        {
                                            longitude_direction[i]=sp1[i+37];
                                            i++;
                                        }
                                        longitude_direction[2]='\0';
                                        fprintf(fr,"%s, ",longitude_direction);
                                        //经度方向
                                        i=0;
                                        while(sp1[i+45]!=',')
                                        {
                                            course[i]=sp1[i+45];
                                            i++;
                                        }
                                        course[5]='\0';
                                        fprintf(fr,"%s, ",course);
                                        //航向
                                        i=0;
                                        while(sp2[i+43]!=',')
                                        {
                                            altitude[i]=sp2[i+43];
                                            i++;
                                        }
                                        altitude[5]='\0';
                                        fprintf(fr,"%s, ",altitude);
                                        //海拔
                                        i=0;
                                        while(sp1[i+39]!=',')
                                        {
                                            rate[i]=sp1[i+39];
                                            i++;
                                        }
                                        speed=atoi(rate);
                                        speed=speed*1.852;
                                        fprintf(fr,"%.2lf, ",speed);
                                        //速度
                                        i=0;
                                        while(sp2[i+39]!=',')
                                        {
                                            satellites[i]=sp2[i+39];
                                            i++;
                                        }
                                        satellites[2]='\0';
                                        fprintf(fr,"%s\n",satellites);
                                        //卫星颗数
                                        }
                                        fclose(fp);
                                        fclose(fr);
                                        fp=NULL;
    
                                        return 0;
                                        }
