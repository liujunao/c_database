#pragma once
#include"title.h"


int main() {
	int i = 0;
	char sex = 2;
	int key = 0;

	//显示欢迎界面
	wellcome_system_ui();
	//显示系统主界面
	main_system_ui();
	while (true)
	{
		printf("请输入你的选择的功能项(数字)：");
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