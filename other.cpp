#pragma once
#include"title.h"

FILE* fp;
int num = 0;
struct people database[500];
struct people* templ;

//向文本中写入一个结构体内容
void write_a_struct(struct people * temp)
{
	fp = fopen("D:\\database.txt", "a");
	fputs(temp->name, fp);
	fputc(' ', fp);

	fprintf(fp, "%f", temp->run);
	fputc(' ', fp);
	
	fprintf(fp, "%f", temp->walk);
	fputc(' ', fp);

	//fprintf(fp, "\n");
	fclose(fp);
}

//从文本中读取一个结构体内容
int read_a_struct(struct people* temp) {
	int i = 0;
	char ch;
	fp = fopen("D:\\database.txt", "at+");

	//检测每段数据开头能否读取到数据
	ch = fgetc(fp);
	if (ch == EOF)
	{
		return 0;
	}

	//读取name
	while (ch != ' ' && ch != EOF)
	{
		temp->name[i] = ch;
		i++;
		ch = fgetc(fp);
	}temp->name[i] = '\0';

	
	fscanf(fp, "%f", &temp->run);
	fgetc(fp) == ' ';

	fscanf(fp, "%f", &temp->walk);
	fgetc(fp) == ' ';
	
	fclose(fp);
	return 1;
}

//输入信息
struct people* scanf_a_struct(struct people* temp) {

	printf("       请输入姓名(enter确认)：");
	scanf("%s", &temp->name);

	printf("       请输入跑步数据(enter确认)：");
	scanf("%f", &temp->run);

	printf("       请输入步行数据(enter确认)：");
	scanf("%f", &temp->walk);

	return temp;
}

//添加信息
void add_information() {

	struct people* p;
	int key = 2;

	add_information_ui();
	p = scanf_a_struct(&database[num]);
	write_a_struct(&database[num]);
	database[num] = *p;
	num++;
	printf("          信息录入成功！\n");
	printf("       继续录入请按1；返回上一层请按0: ");
	scanf("%d", &key);
	switch (key)
	{
	case 0:main(); break;
	case 1:add_information(); break;
	default:
		break;
	}
}

//打印一个结构体内容
void print_f(struct people* temp) {
	printf("************************************");
	printf("   姓    名： %s", temp->name);
	printf("   跑步数据： %f", temp->run);
	printf("   步行数据： %f\n\n", temp->walk);
}

//获取文件中有多少个数据
int find_database_number() {
	int count = 0;
	char name_t[20];
	fp = fopen("D:\\database.txt", "at+");
	while (fscanf(fp,"%s",&name_t) != EOF)
	{
		++count;
	}
	fclose(fp);
	return count/3;
}

//输出所有数据
void print_all_database() {

	fp = fopen("D:\\database.txt", "at+");

	int key = 2;
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s%f%f", &database[num].name, &database[num].run, &database[num].walk);
		num++;
	}
	fclose(fp);
	num = find_database_number();
	printf("%d", &num);
	for (i = 0; i < num; i++)
	{
		print_f(&database[i]);
	}
	printf("        所有存储信息已输出到屏幕，请查看！\n");
	printf("        返回上一层界面，请输入1； 结束，请输入0:");

	scanf("%d", &key);
	switch (key)
	{
	case 0:exit(0); break;
	case 1:main(); break;
	default:
		break;
	}
}

void find_name(char name_f[20]) {
	int i = 0;
	num = find_database_number();
	fp = fopen("D:\\database.txt", "at+");
	
	for (i = 0; i < num; i++)
	{
		//fscanf(fp, "%s", &database[i].name);
		fscanf(fp, "%s%f%f", &database[i].name, &database[i].run, &database[i].walk);
		if (strcmp(name_f, database[i].name) == 0)
		{
			printf("查找成功！\n");
			print_f(&database[i]);
			return;
		}
	}
	printf("查找失败，无此人！\n");
	fclose(fp);
	return;
}

void find_information() {

	int key = 3;
	find_information_ui();
	scanf("%d", &key);

	switch (key)
	{
	case 2:main(); break;
	case 1:find_name_result(); break;
	default:
		break;
	}
}

void find_name_result() {
	char name[20];
	printf("   请输入你要查找的姓名：");
	scanf("%s", name);
	find_name(name);

	int key = 2;
	printf("    继续查找，请输入0，返回上一层请输入1：");
	scanf("%d", &key);
	switch (key)
	{
	case 0:find_information(); break;
	case 1:main(); break;
	default:
		break;
	}
}

void revise_information() {
	int key = 3;
	revise_information_ui();
	scanf("%d", &key);

	switch (key)
	{
	case 1:revise_information_result(); break;
	case 2:main(); break;
	default:
		break;
	}
}

void revise_information_result() {
	char name[20];
	float run = 0;
	float walk = 0;
	printf("   请输入你要修改数据的姓名：");
	scanf("%s", name);
	find_name(name);
	printf("   请输入你要修改的跑步数据：");
	scanf("%f", &run);
	printf("   请输入你要修改的步行数据");
	scanf("%f", &walk);
	revise_by_name(name, run, walk);

	int key = 2;
	printf("    继续修改，请输入0，返回上一层请输入1：");
	scanf("%d", &key);
	switch (key)
	{
	case 0:revise_information(); break;
	case 1:main(); break;
	default:
		break;
	}
}

void revise_by_name(char name_r[20],float run,float walk) {
	int i = 0;
	num = find_database_number();
	fp = fopen("D:\\database.txt", "at+");
	
	//struct people* templ;

	for (i = 0; i < num; i++)
	{
		fscanf(fp, "%s%f%f", &database[i].name, &database[i].run, &database[i].walk);
		if (strcmp(name_r, database[i].name) == 0)
		{
			database[i].run = run;
			database[i].walk = walk;
			//write_a_struct_again(&database[i]);
			
		}
		write_a_struct_again(&database[i]);
	}
	fclose(fp);

	char tempName[] = "D:\\temp.txt";
	char fpName[] = "D:\\database.txt";

	printf("修改成功！");

	return;
}

void write_a_struct_again(struct people * temp) {
	
	FILE* temp_f;

	temp_f = fopen("D:\\temp.txt", "a");
	fputs(temp->name, temp_f);
	fputc(' ', temp_f);

	fprintf(temp_f, "%f", temp->run);
	fputc(' ', temp_f);

	fprintf(temp_f, "%f", temp->walk);
	fputc(' ', temp_f);

	//fprintf(fp, "\n");
	fclose(temp_f);
}