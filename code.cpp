//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<math.h>
//#include<fstream>
using namespace std;
//#include"menu_function.h"
#include"worker_class.h"
#include<conio.h>
int main()
{
	/*
    cout << "***********0.退出管理系统************" << endl;
	cout << "***********1.添加 新 员工************" << endl;
	cout << "***********2.显示职工信息************" << endl;
	cout << "***********3.删除离职员工************" << endl;
	cout << "***********4.修改员工信息************" << endl;
	cout << "***********5.查找职工信息************" << endl;
	cout << "***********6.按照编号排序************" << endl;
	cout << "***********7.清空全部文档************" << endl;
	*/
	menu().initialize_infor();
	while (true)
	{
		menu().show_menu();
		int choose = 0;
		cout << "请选择操作..." << endl;
		cin >> choose;
		switch (choose)
		{
		case 0:menu().Exit(); break;
		case 1:menu().add_worker_Da(); break;
		case 2:menu().show_worker(); break;
		case 3:menu().delete_worker(); break;
		case 4:menu().mod_wker_infor(); break;
		case 5:menu().find_wker_infor(); break;
		case 6:menu().sort_by_id(); break;
		case 7:menu().clear_file(); break;
		}
		system("cls");
	}
	
	
	
	system("pause");
	return 0;
}


