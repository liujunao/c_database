#pragma once
#include"title.h"

FILE* fp;
int num = 0;
struct people database[500];
struct people* templ;

//���ı���д��һ���ṹ������
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

//���ı��ж�ȡһ���ṹ������
int read_a_struct(struct people* temp) {
	int i = 0;
	char ch;
	fp = fopen("D:\\database.txt", "at+");

	//���ÿ�����ݿ�ͷ�ܷ��ȡ������
	ch = fgetc(fp);
	if (ch == EOF)
	{
		return 0;
	}

	//��ȡname
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

//������Ϣ
struct people* scanf_a_struct(struct people* temp) {

	printf("       ����������(enterȷ��)��");
	scanf("%s", &temp->name);

	printf("       �������ܲ�����(enterȷ��)��");
	scanf("%f", &temp->run);

	printf("       �����벽������(enterȷ��)��");
	scanf("%f", &temp->walk);

	return temp;
}

//�����Ϣ
void add_information() {

	struct people* p;
	int key = 2;

	add_information_ui();
	p = scanf_a_struct(&database[num]);
	write_a_struct(&database[num]);
	database[num] = *p;
	num++;
	printf("          ��Ϣ¼��ɹ���\n");
	printf("       ����¼���밴1��������һ���밴0: ");
	scanf("%d", &key);
	switch (key)
	{
	case 0:main(); break;
	case 1:add_information(); break;
	default:
		break;
	}
}

//��ӡһ���ṹ������
void print_f(struct people* temp) {
	printf("************************************");
	printf("   ��    ���� %s", temp->name);
	printf("   �ܲ����ݣ� %f", temp->run);
	printf("   �������ݣ� %f\n\n", temp->walk);
}

//��ȡ�ļ����ж��ٸ�����
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

//�����������
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
	printf("        ���д洢��Ϣ���������Ļ����鿴��\n");
	printf("        ������һ����棬������1�� ������������0:");

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
			printf("���ҳɹ���\n");
			print_f(&database[i]);
			return;
		}
	}
	printf("����ʧ�ܣ��޴��ˣ�\n");
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
	printf("   ��������Ҫ���ҵ�������");
	scanf("%s", name);
	find_name(name);

	int key = 2;
	printf("    �������ң�������0��������һ��������1��");
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
	printf("   ��������Ҫ�޸����ݵ�������");
	scanf("%s", name);
	find_name(name);
	printf("   ��������Ҫ�޸ĵ��ܲ����ݣ�");
	scanf("%f", &run);
	printf("   ��������Ҫ�޸ĵĲ�������");
	scanf("%f", &walk);
	revise_by_name(name, run, walk);

	int key = 2;
	printf("    �����޸ģ�������0��������һ��������1��");
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

	printf("�޸ĳɹ���");

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