// Datainput.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include <ctime>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
string all_tags[20] = { "film","ps","ae","games","singing","dance","guitar","basketball","pingpang","computer",
"books","diy","cook","kongfu","english","run","talk","music","writing","speech" };
string sche_time[6] = { "8:00-10:00","10:00-12:00","14:00-16:00","16:00-18:00","18:00-20:00","20:00-22:00" };

int de_no[110];

class Departments
{


private:
	int department_no;
	int de_no_num;               //记录生成部门时的序号 
	int member_limit;
	int tags_num[5];             //记录标签在标签随机库中的位置 
	int sched_num[3];            //记录时间在时间随机库中的位置
	string tags[5];
	string event_schedules[3];

public:
	void inputDepart_no(int i)
	{
		department_no = 10000 + i;
		de_no[i] = department_no;
		de_no_num = i + 1;
	}
	void inputMem_limit(int p)
	{
		srand(p);
		member_limit=rand()%15+1;      
		
	}
	void inputTags(int p)
	{
		srand(p);
		//	int n=rand()%5+1;                 //*每个部门有5个标签

		for (int i = 0; i<5; i++)
		{
			int t = rand() % 20 + 1;        //随机选出20个标签中的一个 
			tags_num[i] = t;
			tags[i] = all_tags[t - 1];
		}
	}
	void inputTime(int p)
	{
		srand(p);
		//	int n=rand()%3+1;           //每个部门有3个活动时间
		for (int i = 0; i<3; i++)
		{
			int t = rand() % 6 + 1;
			sched_num[i] = t;
			event_schedules[i] = sche_time[t - 1];
		}
	}
	void outputDepartment()
	{
		//printf("/t");
		//cout << "\"departments\":" << endl;
		//printf("/t[");
		
		printf("\t\t{\n");
		printf("\t\t\t");
		cout << "\"department_no\":" << '"' << department_no << '"' << ',' << endl;
		printf("\t\t\t");
		cout << "\"de_no_num\":" << de_no_num << ','<<endl;
		printf("\t\t\t");
		cout << "\"member_limit\":" << member_limit << ',' << endl;
		printf("\t\t\t");
		cout << "\"tags\":[";
		for (int i = 0; i < 5; i++)
		{
			if (i < 4)
			{
				cout << '"' << tags[i] << '"' << ',';
			}
			else
			{
				cout<< '"' << tags[i] << '"' << "],"<<endl;
			}
			
		}
		printf("\t\t\t");
		cout << "\"tags_num\":[";
		for (int i = 0; i < 5; i++)
		{
			if (i < 4)
			{
				cout  << tags_num[i] <<',';
			}
			else
			{
				cout << tags_num[i] << "],"<<endl;
			}

		}
		printf("\t\t\t");
		cout << "\"event_schedules\":[";
		for (int i = 0; i < 3; i++)
		{
			if (i < 2)
			{
				cout << '"' << event_schedules[i]<< '"' << ',';
			}
			else
			{
				cout << '"' << event_schedules[i] << '"' << "]," << endl;
			}
		}
		printf("\t\t\t");
		cout << "\"sched_num\":[";
		for (int i = 0; i < 3; i++)
		{
			if (i < 2)
			{
				cout << sched_num[i] << ',';
			}
			else
			{
				cout << sched_num[i]<< "]" << endl;
			}
		}
		

	}
};

class Students {
    private:
		int student_no;
		int de_applications[5];
		int de_app_num[5];           //记录部门申请在部门随机库中的位置
		int tags_num[5];             //记录标签在标签随机库中的位置 
		int sched_num[3];            //记录时间在时间随机库中的位置 
		int t;                       //记录学生标签个数
		int sch;                     //空闲时间个数
		int de_app;                  //申请部门个数
		string tags[5];
		string event_schedules[3];

    public:
		void inputStu_no(int i)
		{
			student_no = 20000 + i;
		}
		void inputTags(int p)
		{
			srand(p);
			t = rand() % 5 + 1;
			for (int i = 0; i < t; i++)
			{
				int temp = rand() % 20 + 1;
				tags_num[i] = temp;
				tags[i] = all_tags[temp - 1];
			}
		}
		void intputSchedules(int p)
		{
			srand(p);
			sch = rand() % 3 + 1;
			for (int i = 0; i < sch; i++)
			{
				int temp = rand() % 6 + 1;
				sched_num[i] = temp;
				event_schedules[i] = sche_time[temp - 1];
			}
		}
		void inputAppliation_de(int n,int p)                         //最多申请5个部门
		{
			srand(p);
			de_app = rand() % 5 + 1;
			for (int i = 0; i < de_app; i++)
			{
				int temp = rand() % n + 1;
				de_app_num[i] = temp;
				de_applications[i] = de_no[temp - 1];        

			}
			
		}
		void output_Students();
};

void Students::output_Students()
{
	printf("\t\t{\n");
	printf("\t\t\t");
	cout << "\"student_no\":" << '"' << student_no << '"' << ',' << endl;
	printf("\t\t\t");
//	cout << "\"tags\":" << member_limit << ',' << endl;
//	printf("\t\t\t");
	cout << "\"tags\":[";
	for (int i = 0; i < t; i++)
	{
		if (i < t-1)
		{
			cout << '"' << tags[i] << '"' << ',';
		}
		else
		{
			cout << '"' << tags[i] << '"' << "]," << endl;
		}

	}
	printf("\t\t\t");
	cout << "\"tags_num\":[";
	for (int i = 0; i < t; i++)
	{
		if (i < t-1)
		{
			cout  << tags_num[i]  << ',';
		}
		else
		{
			cout << tags_num[i] <<  "]," << endl;
		}

	}
	printf("\t\t\t");
	cout << "\"event_schedules\":[";
	for (int i = 0; i < sch; i++)
	{
		if (i < sch-1)
		{
			cout << '"' << event_schedules[i] << '"' << ',';
		}
		else
		{
			cout << '"' << event_schedules[i] << '"' << "]," << endl;
		}
	}
	printf("\t\t\t");
	cout << "\"sched_num\":[";
	for (int i = 0; i < sch; i++)
	{
		if (i < sch-1)
		{
			cout  << sched_num[i]  << ',';
		}
		else
		{
			cout << sched_num[i] <<"]," << endl;
		}
	}
	printf("\t\t\t");
	cout << "\"de_applications\":[";
	for (int i = 0; i < de_app; i++)
	{
		if (i < de_app - 1)
		{
			cout << '"' << de_applications[i]<< '"' << ',';
		}
		else
		{
			cout << '"' <<de_applications[i]<< '"' << "]," << endl;
		}
	}
	printf("\t\t\t");
	cout << "\"de_app_num\":[";
	for (int i = 0; i < de_app; i++)
	{
		if (i < de_app - 1)
		{
			cout  << de_app_num[i] <<  ',';
		}
		else
		{
			cout <<  de_app_num[i]<< "]" << endl;
		}
	}

	
	
}


int main()
{

	Departments d[110];
	Students  s[5010];
	int D, S;
	printf("依次输入学生,部门人数：\n");

	cin >> S >> D;
	char str[30];
	sprintf(str,"s%d-d%d-in.json", S, D);
	freopen(str, "w", stdout);

	printf("{\n");
	printf("\t");
	cout << "\"departments\":" << endl;
	printf("\t[\n");
	for (int i = 0; i < D; i++)
	{
        d[i].inputDepart_no(i);
		d[i].inputMem_limit(i);
	    d[i].inputTags(i);
	    d[i].inputTime(i);
	    d[i].outputDepartment();
		if (i < D - 1) 
		{
            printf("\t\t},\n");
		}
		else
		{
			printf("\t\t}\n");
		}

	}
	printf("\t],\n");
	printf("\t");
	cout << "\"students\":" << endl;
	printf("\t[\n");
	for (int i = 0; i < S; i++)
	{
		s[i].inputStu_no(i);
		s[i].inputTags(i);
		s[i].intputSchedules(i);
		s[i].inputAppliation_de(D,i);
		s[i].output_Students();
		if (i < S - 1)
		{
			printf("\t\t},\n");
		}
		else
		{
			printf("\t\t}\n");
		}
	}
	printf("\t]\n");
	printf("}\n");
	
	fclose(stdout);
	
//	system("pause");
    return 0;
}

