#include <iostream>
#include "cJSON.h"
#include<fstream>
#include <string>
using namespace std;

typedef struct  
{  
	char * department_no;
	int de_no_num;               
	int member_limit;
	int tags_num[5];             
	int sched_num[3];            
	char * tags[5];
	char * event_schedules[3]; 
	int follow_num;//报该部门的人数 
}Departments; 

typedef struct  
{  
	char * student_no;
	int de_app_num[5];    
	int tags_num[5];             
	int sched_num[3];     
	char * de_applications[5];      
	char * tags[5];        
	char * event_schedules[3];
}Students; 


//parse a struct array  
int cJSON_to_struct_array(const char *text, Departments worker[], Students stu[])  
{  
    cJSON *json,*arrayItem,*item,*object,*departments,*department,*students,*student;  
    int i;  
    int d_count;
	int s_count; 
  
    json=cJSON_Parse(text);  
    if (!json)  
    {  
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());  
    }  
    else  
    {  
    	//解析部门信息 
        departments=cJSON_GetObjectItem(json,"departments");  
        if(departments!=NULL)  
        {  
            int size=cJSON_GetArraySize(departments);  
            d_count = size;
            printf("cJSON_GetArraySize: size=%d\n",size);  
  
            for(i=0;i<size;i++)  
            {  
                printf("i=%d\n",i);  
                department=cJSON_GetArrayItem(departments,i);  
                worker[i].follow_num = 0;
  
                item=cJSON_GetObjectItem(department,"department_no");  
                if(item!=NULL)  
                {  
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                    worker[i].department_no=item->valuestring;
                    cout<<worker[i].department_no<<endl;
                    //memcpy(worker[i].department_no,item->valuestring,strlen(item->valuestring));
                }  
  
                item=cJSON_GetObjectItem(department,"de_no_num");  
                if(item!=NULL)  
                {  
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valueint=%d\n",item->type,item->string,item->valueint);  
                    worker[i].de_no_num=item->valueint;  
                } 
  
                item=cJSON_GetObjectItem(department,"member_limit");  
                if(item!=NULL)  
                {  
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valueint=%d\n",item->type,item->string,item->valueint);  
                    worker[i].member_limit=item->valueint;
                }  
  
                item=cJSON_GetObjectItem(department,"tags_num");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *tags_num = cJSON_GetArrayItem(item, j);  
                        if ( NULL != tags_num )  
                            printf ("%d ", tags_num->valueint); 
							worker[i].tags_num[j]=tags_num->valueint; 
                    }  
                    cout<<endl;
                }   
  
                item=cJSON_GetObjectItem(department,"sched_num");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *sched_num = cJSON_GetArrayItem(item, j);  
                        if ( NULL != sched_num )  
                            printf ("%d ", sched_num->valueint); 
							worker[i].sched_num[j]=sched_num->valueint; 
                    }  
                    cout<<endl;
                } 
  
                item=cJSON_GetObjectItem(department,"tags");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *tags = cJSON_GetArrayItem(item, j);  
                        if ( NULL != tags )  
                        {
//                        	cout<<tags->valuestring<<"  ";
		                    worker[i].tags[j]=tags->valuestring;
		                    cout<<worker[i].tags[j]<<"  ";
                        }
                    }  
                    cout<<endl;
                } 
  
                item=cJSON_GetObjectItem(department,"event_schedules");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *event_schedules = cJSON_GetArrayItem(item, j);  
                        if ( NULL != event_schedules )  
                        {
//                        	cout<<tags->valuestring<<"  ";
		                    worker[i].event_schedules[j]=event_schedules->valuestring;
		                    cout<<worker[i].event_schedules[j]<<"  ";
                        }
                    }  
                    cout<<endl;
                } 
            }  
        }  
        
    	//解析学生信息 
        students=cJSON_GetObjectItem(json,"students");  
        if(students!=NULL)  
        {  
            int size=cJSON_GetArraySize(students);  
            s_count = size;
            printf("cJSON_GetArraySize: size=%d\n",size);  
  
            for(i=0;i<size;i++)  
            {  
                printf("i=%d\n",i);  
                student=cJSON_GetArrayItem(students,i);  
  
                item=cJSON_GetObjectItem(student,"student_no");  
                if(item!=NULL)  
                {  
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                    stu[i].student_no=item->valuestring;
                    cout<<stu[i].student_no<<endl;
                    //memcpy(worker[i].department_no,item->valuestring,strlen(item->valuestring));
                }  
  
                item=cJSON_GetObjectItem(student,"de_app_num");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *de_app_num = cJSON_GetArrayItem(item, j);  
                        if ( NULL != de_app_num )  
                            printf ("%d ", de_app_num->valueint); 
							stu[i].de_app_num[j]=de_app_num->valueint; 
                    }  
                    cout<<endl;
                }
  
                item=cJSON_GetObjectItem(student,"tags_num");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *tags_num = cJSON_GetArrayItem(item, j);  
                        if ( NULL != tags_num )  
                            printf ("%d ", tags_num->valueint); 
							stu[i].tags_num[j]=tags_num->valueint; 
                    }  
                    cout<<endl;
                }   
  
                item=cJSON_GetObjectItem(student,"sched_num");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *sched_num = cJSON_GetArrayItem(item, j);  
                        if ( NULL != sched_num )  
                            printf ("%d ", sched_num->valueint); 
							stu[i].sched_num[j]=sched_num->valueint; 
                    }  
                    cout<<endl;
                } 
  
                item=cJSON_GetObjectItem(student,"de_applications");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *de_applications = cJSON_GetArrayItem(item, j);  
                        if ( NULL != de_applications )  
                        {
//                        	cout<<tags->valuestring<<"  ";
		                    stu[i].de_applications[j]=de_applications->valuestring;
		                    cout<<stu[i].de_applications[j]<<"  ";
                        }
                    }  
                    cout<<endl;
                } 
  
                item=cJSON_GetObjectItem(student,"tags");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *tags = cJSON_GetArrayItem(item, j);  
                        if ( NULL != tags )  
                        {
//                        	cout<<tags->valuestring<<"  ";
		                    stu[i].tags[j]=tags->valuestring;
		                    cout<<stu[i].tags[j]<<"  ";
                        }
                    }  
                    cout<<endl;
                } 
  
                item=cJSON_GetObjectItem(student,"event_schedules");  
                if(item!=NULL)  
                {
                    printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=",item->type,item->string);  
                	int j = 0;  
                    int jcount = cJSON_GetArraySize(item);  
                    for (; j < jcount; ++j)  
                    {  
                        cJSON *event_schedules = cJSON_GetArrayItem(item, j);  
                        if ( NULL != event_schedules )  
                        {
//                        	cout<<tags->valuestring<<"  ";
		                    stu[i].event_schedules[j]=event_schedules->valuestring;
		                    cout<<stu[i].event_schedules[j]<<"  ";
                        }
                    }  
                    cout<<endl;
                } 
            }  
        }
    
    	//统计个部门的意向人数 
	    for(i=0; i<d_count; i++)
		{
	    	for(int j=0; j<s_count; j++)
			{
	    		for(int k=0; k<5; k++){
	    			if(stu[j].de_app_num[k] == (i+1))
					{
	    				worker[i].follow_num++;
	    			}
	    		}
	    	}
	    }
        
        //对热门/冷门部门排序 
        for(i=0; i<d_count; i++){
        	for(int j=i+1; j<d_count; j++)
			{
        		if(worker[i].follow_num < worker[j].follow_num)
				{
        			Departments temp = worker[i];
        			worker[i] = worker[j];
        			worker[j] = temp;
        		}
        	}
        }
        
        //进行匹配 
        int pp[50][1000][2] = {{{0}}};
        for(i=0; i<d_count; i++)
		{
        	for(int j=0; j<s_count; j++)
			{
	    		for(int k=0; k<5; k++)
				{
	    			if(stu[j].de_app_num[k] == (i+1))
					{
	    				for(int m=0; m<5; m++)
						{
	    					for(int n=0; n<5; n++)
							{
	    						if(worker[i].tags_num[m] == stu[j].tags_num[n])
								{
	    							pp[i][j][0] = pp[i][j][0] + 2;
	    						}
	    					}
	    				}
	    				for(int m=0; m<3; m++)
						{
	    					for(int n=0; n<3; n++)
							{
	    						if(worker[i].sched_num[m] == stu[j].sched_num[n])
								{
	    							pp[i][j][0] = pp[i][j][0] + 3;
	    						}
	    					}
	    				}
	    			}
	    		}
        	}
        }
		
		//进行筛选
		 for(i=0; i<d_count; i++)
		 {
		 	int j = 0;
    		for(int k=0; k<s_count; k++)
			{
    			if(pp[i][k][1] != 1 && pp[i][k][0] > 0 )
				{
    				int t = k;
    				for(int m=k+1; m<s_count; m++)
					{
    					if(pp[i][m][1] != 1 && pp[i][k][0] > 0 )
						{
    						if(pp[i][k][0] < pp[i][m][0])
							{
    							t = m;
    						}
    					}
    				}
    				pp[i][t][1] = 1;
    				j++;
    			}
    			if(j == worker[i].member_limit)
				{
    				break;
    			}
    		}
			cout<<endl;
		 }
        
        //统计适配分数 
        for(i=0; i<d_count; i++)
		{
        	for(int j=0; j<s_count; j++)
			{
        		cout<<pp[i][j][0]<<":"<<pp[i][j][1]<<" // ";
			}
			cout<<endl;
		}
  
//        for(i=0;i<d_count;i++)  
//        {
//        	cout<<"department_no:"<<worker[i].department_no<<endl
//        		<<"follow_num:"<<worker[i].follow_num<<endl
//        		<<"de_no_num:"<<worker[i].de_no_num<<endl
//        		<<"member_limit:"<<worker[i].member_limit<<endl
//        		<<"tags_num:";
//        		for(int j=0; j<5; j++){
//        			cout<<worker[i].tags_num[j]<<",";
//        		}
//        		cout<<endl<<"tags:";
//        		for(int j=0; j<5; j++){
//        			cout<<"'"<<worker[i].tags[j]<<"',";
//        		}
//        		cout<<endl<<"sched_num:";
//        		for(int j=0; j<3; j++){
//        			cout<<worker[i].sched_num[j]<<",";
//        		}
//        		cout<<endl<<"event_schedules:";
//        		for(int j=0; j<3; j++){
//        			cout<<"'"<<worker[i].event_schedules[j]<<"',";
//        		}
//        		cout<<endl;
//        }  
//  
//        for(i=0;i<s_count;i++)  
//        {
//        	cout<<"student_no:"<<stu[i].student_no<<endl
//				<<"de_app_num:";
//        		for(int j=0; j<5; j++){
//        			cout<<stu[i].de_app_num[j]<<",";
//        		}
//        		cout<<endl<<"de_applications:";
//        		for(int j=0; j<5; j++){
//        			cout<<stu[i].de_applications[j]<<",";
//        		}
//        		cout<<endl<<"tags_num:";
//        		for(int j=0; j<5; j++){
//        			cout<<stu[i].tags_num[j]<<",";
//        		}
//        		cout<<endl<<"tags:";
//        		for(int j=0; j<5; j++){
//        			cout<<"'"<<stu[i].tags[j]<<"',";
//        		}
//        		cout<<endl<<"sched_num:";
//        		for(int j=0; j<3; j++){
//        			cout<<stu[i].sched_num[j]<<",";
//        		}
//        		cout<<endl<<"event_schedules:";
//        		for(int j=0; j<3; j++){
//        			cout<<"'"<<stu[i].event_schedules[j]<<"',";
//        		}
//        		cout<<endl;
//        } 
  
        cJSON_Delete(json);  
    }  
    
    
    return 0;  
}  

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	

	ifstream in("s300-d20-in.json"); 

/*	int S, D;
	cin >> S >> D;
	char str[30];
	sprintf(str, "s%d-d%d-out.json", S, D);
	freopen(str, "w", stdout);*/

    istreambuf_iterator<char> beg(in), end; 
    string str(beg, end); 
    //cout<<str<<endl;
    const char* p = str.data();
    //cout<<p<<endl;
	
    Departments worker[20]={{0}};  
    Students stu[20]={{0}};
    cJSON_to_struct_array(p, worker, stu);  
    
	//fclose(stdout);
	return 0;
}

