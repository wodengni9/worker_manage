#pragma once
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<fstream>
#define filename "emp_infor.txt"
using namespace std;
//职工抽象父类  
//0.基本信息：姓名、职工编号、部门编号
//1.部门获取
//2.信息打印
class worker
{
public:
	
	virtual string get_Bumen() = 0;
	virtual string get_workcontent() = 0;
	virtual void shoe_infor()
	{
		cout << "姓名:" << this->name << "\t" << "职工编号:" << this->id << "\t" 
			<< "部门:" << get_Bumen() << "\t" << "工作内容:" << get_workcontent() << endl;
	}
	string get_name()
	{
		return this->name;
	}
	int get_id()
	{
		return this->id;
	}
	int get_Bumen_id()
	{
		return Bumen_id;
	}
	void name_mod();
	void id_mod();
	void Bumen_id_mod();
protected:
	string name;
	int id;
	int Bumen_id;

};

//普通职工
class employee:public worker
{
public:
	employee(string name, int id, int Bumen_id)
	{
		this->name = name;
		this->id = id;
		this->Bumen_id = Bumen_id;
	}
	virtual string get_Bumen()
	{
		return "普通职工";
	}
	virtual string get_workcontent()
	{
		return "完成经理下发的任务";
	}
};

//经理
class manager :public worker
{
public:
	manager(string name, int id, int Bumen_id)
	{
		this->name = name;
		this->id = id;
		this->Bumen_id = Bumen_id;
	}
	virtual string get_Bumen()
	{
		return "经理";
	}
	virtual string get_workcontent()
	{
		return "完成老板下发的任务，并且下发任务给员工";
	}
};

//老板
class boss :public worker
{
public:
	boss(string name, int id, int Bumen_id)
	{
		this->name = name;
		this->id = id;
		this->Bumen_id = Bumen_id;
	}
	virtual string get_Bumen()
	{
		return "老板";
	}
	virtual string get_workcontent()
	{
		return "管理公司全部事务";
	}
};

//员工的数目
int m_number = 0;
//员工信息数组存储
vector<worker*>worker_array;



//生成一个菜单类
class menu
{
public:
	void Exit();
	void add_worker_Da();
	void show_worker();
	void delete_worker();
	void mod_wker_infor();
	void find_wker_infor();
	void sort_by_id();
	void clear_all_infor();
	void show_menu();
	void save_infor();
	void initialize_infor();
	void clear_file();
};


//初始化信息
void menu::initialize_infor()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	string name0;
	int id0;
	int Bumen_id0;
	while (ifs >> name0&&ifs>>id0&&ifs>>Bumen_id0)
	{
		switch (Bumen_id0)
		{
		case 1:
		{
			worker* temp = new employee(name0, id0, Bumen_id0);
			worker_array.push_back(temp);
			break;
		}
		case 2:
		{
			worker* temp = new manager(name0, id0, Bumen_id0);
			worker_array.push_back(temp);
			break;
		}
		case 3:
		{
			worker* temp = new boss(name0, id0, Bumen_id0);
			worker_array.push_back(temp);
			break;
		}

		}
		m_number++;
	}
	ifs.close();
}


//文件操做
void menu::save_infor()
{
	ofstream ofs;
	ofs.open(filename, ios::trunc);
	for (vector<worker*>::iterator it = worker_array.begin(); it != worker_array.end(); it++)
	{
		ofs << (*it)->get_name() << "  " << (*it)->get_id() << "  "
			<< (*it)->get_Bumen_id() <<  endl;
	}
	ofs.close();
}

void menu::show_menu()
{
	cout << "*************************************" << endl;
	cout << "*********欢迎来到职工管理系统********" << endl;
	cout << "***********0.退出管理系统************" << endl;
	cout << "***********1.添加 新 员工************" << endl;
	cout << "***********2.显示职工信息************" << endl;
	cout << "***********3.删除离职员工************" << endl;
	cout << "***********4.修改员工信息************" << endl;
	cout << "***********5.查找职工信息************" << endl;
	cout << "***********6.按照编号排序************" << endl;
	cout << "***********7.清空全部文档************" << endl;
	cout << "*************************************" << endl;
}


//退出函数
void menu::Exit()
{
	cout << "确认退出吗？？(Y/N)" << endl;
	getchar();
	if ( getchar()== 'Y')
	{
		cout << "即将退出..." << endl;
		system("pause");
		exit(0);
	}
	else
	{
		cout << "即将回到主菜单..." << endl;
		system("pause");
	}

}


//id查重
worker* id_chong(worker* x, int id)//如果worker* x中的id 与函数参数值id相等则返回x的地址，否则返回NULL
{
	if (x->get_id() == id)
	{
		return x;
	}
	else return NULL;
}
bool if_id_chong(int id)
{
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id)!=NULL)
		{
			return true;
		}
	}
	return false;
}
//职工添加小函数
void add_worker()
{
	string name0;
	int id0;
	int Bumen_id0;
	cout << "请输入员工姓名" << endl;
	cin >> name0;
	while (true)
	{
		cout << "请输入员工id" << endl;
		cin >> id0;
		if (id0 <= 0)
		{
			cout << "要输入正数哦亲..." << endl;
			continue;
		}
	    else if (if_id_chong(id0))
		{
			cout << "id重复，换一个呢亲..." << endl;
			continue;
		}
		else break;
	}
	while (true)
	{
		cout << "请输入员工部门编号" << endl;
		cout << "1.普通员工  2.经理  3.老板" << endl;
		cin >> Bumen_id0;
		if (Bumen_id0 <= 0 || Bumen_id0 >= 4)
		{
			cout << "输入错误，请重新输入..." << endl;
			getchar(); 
			continue;
		}
		else break;
	}
	switch (Bumen_id0)
	{
	case 1:
	{
		employee temp(name0, id0, Bumen_id0);
		worker_array.push_back(new employee(temp));
	}break;
	case 2:
	{
		manager temp(name0, id0, Bumen_id0);
		worker_array.push_back(new manager(temp));
	}break;
	case 3:
	{
		boss temp(name0, id0, Bumen_id0);
		worker_array.push_back(new boss(temp));
	}break;
	}
	m_number++;//员工总数加1

}
//职工添加大函数
void menu::add_worker_Da()
{
	int new_num;
	while (true)
	{
		cout << "请输入新增员工的数目" << endl;
		cin >> new_num;
		if (new_num <= 0)
		{
			cout << "请重新输入..." << endl;
			getchar();
			continue;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < new_num; i++)
	{
		cout << "请输入第" << i + 1 << "位员工信息..." << endl;
		 add_worker();

		cout << "输入完成..." << endl;
		getchar(); 
		if (i == 7)
		{
			cout << "全部存储完毕..." << endl;
			getchar(); getchar();
			break;
		}
		getchar();
		system("cls");
		menu().save_infor();
	}
}


//直接添加一个员工，带id查重
void add_worker(string name, int id, int Bumen_id)
{
	if (id <= 0)
	{
		cout << "职工编号不是正数..." << endl;
		cout << "添加失败..." << endl;
		getchar();
		return;
	}
	if (if_id_chong(id))
	{
		cout << "职工编号重复..." << endl;
		cout << "添加失败..." << endl;
		getchar();
		return;
	}
	if (Bumen_id <= 0 || Bumen_id >= 4)
	{
		cout << "部门编号输入错误..." << endl;
		cout << "添加失败..." << endl;
		getchar();
		return;
	}
	switch (Bumen_id)
	{
	case 1:
	{
		employee temp(name, id, Bumen_id);
		worker_array.push_back(new employee(temp));
	}break;
	case 2:
	{
		manager temp(name, id, Bumen_id);
		worker_array.push_back(new manager(temp));
	}
	break;
	case 3:
	{
		boss temp(name, id, Bumen_id);
		worker_array.push_back(new boss(temp));
	}break;
    }
}

//展示员工
void menu::show_worker()
{
	vector<worker*>::iterator it = worker_array.begin();
	if (m_number == 0)
	{
		cout << "无员工..." << endl;
		getchar(); getchar();

	}
	else
	{
		for (; it!=worker_array.end(); it++)
		{
			(*it)->shoe_infor();
		}
		cout << "打印完毕..." << endl;
		getchar(); getchar();
	}
}


//删除离职员工
void menu::delete_worker()
{
	if (m_number == 0)
	{
		cout << "无员工可删..." << endl;
		getchar(); getchar();
		return;
	}
	cout << "请输入离职的员工编号" << endl;
	int id1;
	cin >> id1;
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id1) != NULL)
		{
			worker_array.erase(it);
			m_number--;
			cout << "已删除该职工记录..." << endl;
			getchar(); getchar();
			menu().save_infor();
			return;
		}
	}
	cout << "没找到该职工..." << endl;
	getchar(); getchar();

}


//修改员工信息
void menu::mod_wker_infor()
{
	cout << "请输入要修改的员工编号" << endl;
	int id1;
	cin >> id1;
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id1) != NULL)
		{
			cout << "找到该职工！！" << endl;
            getchar(); getchar();
			system("cls");
			(*it)->shoe_infor();
			//备份个人信息
			string name0 = (*(*it)).get_name();
			int id0 = (*(*it)).get_id();
			int Bumen_id0 = (*(*it)).get_Bumen_id();
			//选择设置
			cout << "1.修改姓名  " << "2.修改职工编号  "
				<< "3，修改部门编号（1.普通职工 2.经理 3.老板）" << endl;
			cout << "请输入操作选择..." << endl;
			int choose;
			cin >> choose;
			if (choose <= 0 || choose >= 4)
			{
				cout << "输入错误..." << endl;
				cout << "修改失败..." << endl;
				getchar(); getchar();
				return;
			}


			switch (choose)
			{
			case 1:
			{
				cout << "请输入新姓名..." << endl;
				cin >> name0;
			}break;
			case 2:
			{
				while (true)
				{
					cout << "请输入新的职工编号" << endl;
					cin >> id0;
					getchar();
					if (if_id_chong(id0))
					{
						cout << "职工编号重复，换一个呢亲..." << endl;
					}
					else break;
				}
			}break;
			case 3:
			{
				while (true)
				{
					cout << "请输入新的部门编号" << endl;
					cin >> Bumen_id0;
					getchar();
					if (Bumen_id0 <= 0 || Bumen_id0 >= 4)
					{
						cout << "输入错误..." << endl;
					}
					else break;
				}

			}break;
			}
			worker_array.erase(it);
			add_worker(name0, id0, Bumen_id0);
			cout << "修改成功!!!" << endl;
			menu().save_infor();
			getchar();
			return;
		}
	}
	cout << "没找到该职工..." << endl;
	getchar(); getchar();
}


//id查询,并且展示员工信息
void menu::find_wker_infor()
{
	cout << "请输入要查询的员工编号" << endl;
	int id1;
	cin >> id1;
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id1) != NULL)
		{
			cout << "找到该职工！！" << endl;
			getchar(); getchar();
			system("cls");
			(*it)->shoe_infor();
			getchar();
			return;
		}
	}
	cout << "没找到该职工..." << endl;
	getchar(); getchar();
}

//仿函数，用来排序
class cmp_toHi
{
public:
	bool operator()(worker* w1,worker* w2)
	{
		return w1->get_id() < w2->get_id();
	}
};
class cmp_toLo
{
public:
	bool operator()(worker* w1, worker* w2)
	{
		return w1->get_id() > w2->get_id();
	}
};
//按照编号排序
void menu::sort_by_id()
{
	int choose;
	while (true)
	{
		cout << "请选择排序方式:" << endl;
		cout << "1.按职工编号升序  2.按职工编号降序" << endl;
		cin >> choose;
		getchar();
		if (choose <= 0 || choose >= 3)
		{
			cout << "输入错误..." << endl;
			getchar();
		}
		else break;
	}
	system("cls");
	switch (choose)
	{
	case 1:
	{
		sort(worker_array.begin(), worker_array.end(), cmp_toHi());
		vector<worker*>::iterator it = worker_array.begin();
		if (m_number == 0)
		{
			cout << "无员工..." << endl;
			getchar(); 

		}
		else
		{
			for (; it != worker_array.end(); it++)
			{
				(*it)->shoe_infor();
			}
			cout << "打印完毕..." << endl;
			getchar(); 
		}
	}break;
	case 2:
	{
		sort(worker_array.begin(), worker_array.end(), cmp_toLo());
		vector<worker*>::iterator it = worker_array.begin();
		if (m_number == 0)
		{
			cout << "无员工..." << endl;
			getchar(); 

		}
		else
		{
			for (; it != worker_array.end(); it++)
			{
				(*it)->shoe_infor();
			}
			cout << "打印完毕..." << endl;
			getchar(); 
		}
	}break;
	}

}

//清空文档
void menu::clear_file()
{
	ofstream ofs;
	ofs.open(filename, ios::trunc);
	ofs.close();
	cout << "文档已清空..." << endl;
	getchar(); getchar();
}