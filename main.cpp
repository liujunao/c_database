#pragma once
#include"title.h"


int main() {
	int i = 0;
	char sex = 2;
	int key = 0;

	//��ʾ��ӭ����
	wellcome_system_ui();
	//��ʾϵͳ������
	main_system_ui();
	while (true)
	{
		printf("���������ѡ��Ĺ�����(����)��");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			display_all_ui();
			print_all_database();
			main_system_ui();
			break;
		case 2:add_information();
			break;
		case 3:find_information();
			break;
		case 4:revise_information();
			break;
		case 5:exit(0);
			break;
		}
	}
	return 0;
}