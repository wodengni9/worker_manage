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
    cout << "***********0.�˳�����ϵͳ************" << endl;
	cout << "***********1.��� �� Ա��************" << endl;
	cout << "***********2.��ʾְ����Ϣ************" << endl;
	cout << "***********3.ɾ����ְԱ��************" << endl;
	cout << "***********4.�޸�Ա����Ϣ************" << endl;
	cout << "***********5.����ְ����Ϣ************" << endl;
	cout << "***********6.���ձ������************" << endl;
	cout << "***********7.���ȫ���ĵ�************" << endl;
	*/
	menu().initialize_infor();
	while (true)
	{
		menu().show_menu();
		int choose = 0;
		cout << "��ѡ�����..." << endl;
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


