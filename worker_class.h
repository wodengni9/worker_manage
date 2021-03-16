#pragma once
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<fstream>
#define filename "emp_infor.txt"
using namespace std;
//ְ��������  
//0.������Ϣ��������ְ����š����ű��
//1.���Ż�ȡ
//2.��Ϣ��ӡ
class worker
{
public:
	
	virtual string get_Bumen() = 0;
	virtual string get_workcontent() = 0;
	virtual void shoe_infor()
	{
		cout << "����:" << this->name << "\t" << "ְ�����:" << this->id << "\t" 
			<< "����:" << get_Bumen() << "\t" << "��������:" << get_workcontent() << endl;
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

//��ְͨ��
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
		return "��ְͨ��";
	}
	virtual string get_workcontent()
	{
		return "��ɾ����·�������";
	}
};

//����
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
		return "����";
	}
	virtual string get_workcontent()
	{
		return "����ϰ��·������񣬲����·������Ա��";
	}
};

//�ϰ�
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
		return "�ϰ�";
	}
	virtual string get_workcontent()
	{
		return "����˾ȫ������";
	}
};

//Ա������Ŀ
int m_number = 0;
//Ա����Ϣ����洢
vector<worker*>worker_array;



//����һ���˵���
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


//��ʼ����Ϣ
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


//�ļ�����
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
	cout << "*********��ӭ����ְ������ϵͳ********" << endl;
	cout << "***********0.�˳�����ϵͳ************" << endl;
	cout << "***********1.��� �� Ա��************" << endl;
	cout << "***********2.��ʾְ����Ϣ************" << endl;
	cout << "***********3.ɾ����ְԱ��************" << endl;
	cout << "***********4.�޸�Ա����Ϣ************" << endl;
	cout << "***********5.����ְ����Ϣ************" << endl;
	cout << "***********6.���ձ������************" << endl;
	cout << "***********7.���ȫ���ĵ�************" << endl;
	cout << "*************************************" << endl;
}


//�˳�����
void menu::Exit()
{
	cout << "ȷ���˳��𣿣�(Y/N)" << endl;
	getchar();
	if ( getchar()== 'Y')
	{
		cout << "�����˳�..." << endl;
		system("pause");
		exit(0);
	}
	else
	{
		cout << "�����ص����˵�..." << endl;
		system("pause");
	}

}


//id����
worker* id_chong(worker* x, int id)//���worker* x�е�id �뺯������ֵid����򷵻�x�ĵ�ַ�����򷵻�NULL
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
//ְ�����С����
void add_worker()
{
	string name0;
	int id0;
	int Bumen_id0;
	cout << "������Ա������" << endl;
	cin >> name0;
	while (true)
	{
		cout << "������Ա��id" << endl;
		cin >> id0;
		if (id0 <= 0)
		{
			cout << "Ҫ��������Ŷ��..." << endl;
			continue;
		}
	    else if (if_id_chong(id0))
		{
			cout << "id�ظ�����һ������..." << endl;
			continue;
		}
		else break;
	}
	while (true)
	{
		cout << "������Ա�����ű��" << endl;
		cout << "1.��ͨԱ��  2.����  3.�ϰ�" << endl;
		cin >> Bumen_id0;
		if (Bumen_id0 <= 0 || Bumen_id0 >= 4)
		{
			cout << "�����������������..." << endl;
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
	m_number++;//Ա��������1

}
//ְ����Ӵ���
void menu::add_worker_Da()
{
	int new_num;
	while (true)
	{
		cout << "����������Ա������Ŀ" << endl;
		cin >> new_num;
		if (new_num <= 0)
		{
			cout << "����������..." << endl;
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
		cout << "�������" << i + 1 << "λԱ����Ϣ..." << endl;
		 add_worker();

		cout << "�������..." << endl;
		getchar(); 
		if (i == 7)
		{
			cout << "ȫ���洢���..." << endl;
			getchar(); getchar();
			break;
		}
		getchar();
		system("cls");
		menu().save_infor();
	}
}


//ֱ�����һ��Ա������id����
void add_worker(string name, int id, int Bumen_id)
{
	if (id <= 0)
	{
		cout << "ְ����Ų�������..." << endl;
		cout << "���ʧ��..." << endl;
		getchar();
		return;
	}
	if (if_id_chong(id))
	{
		cout << "ְ������ظ�..." << endl;
		cout << "���ʧ��..." << endl;
		getchar();
		return;
	}
	if (Bumen_id <= 0 || Bumen_id >= 4)
	{
		cout << "���ű���������..." << endl;
		cout << "���ʧ��..." << endl;
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

//չʾԱ��
void menu::show_worker()
{
	vector<worker*>::iterator it = worker_array.begin();
	if (m_number == 0)
	{
		cout << "��Ա��..." << endl;
		getchar(); getchar();

	}
	else
	{
		for (; it!=worker_array.end(); it++)
		{
			(*it)->shoe_infor();
		}
		cout << "��ӡ���..." << endl;
		getchar(); getchar();
	}
}


//ɾ����ְԱ��
void menu::delete_worker()
{
	if (m_number == 0)
	{
		cout << "��Ա����ɾ..." << endl;
		getchar(); getchar();
		return;
	}
	cout << "��������ְ��Ա�����" << endl;
	int id1;
	cin >> id1;
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id1) != NULL)
		{
			worker_array.erase(it);
			m_number--;
			cout << "��ɾ����ְ����¼..." << endl;
			getchar(); getchar();
			menu().save_infor();
			return;
		}
	}
	cout << "û�ҵ���ְ��..." << endl;
	getchar(); getchar();

}


//�޸�Ա����Ϣ
void menu::mod_wker_infor()
{
	cout << "������Ҫ�޸ĵ�Ա�����" << endl;
	int id1;
	cin >> id1;
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id1) != NULL)
		{
			cout << "�ҵ���ְ������" << endl;
            getchar(); getchar();
			system("cls");
			(*it)->shoe_infor();
			//���ݸ�����Ϣ
			string name0 = (*(*it)).get_name();
			int id0 = (*(*it)).get_id();
			int Bumen_id0 = (*(*it)).get_Bumen_id();
			//ѡ������
			cout << "1.�޸�����  " << "2.�޸�ְ�����  "
				<< "3���޸Ĳ��ű�ţ�1.��ְͨ�� 2.���� 3.�ϰ壩" << endl;
			cout << "���������ѡ��..." << endl;
			int choose;
			cin >> choose;
			if (choose <= 0 || choose >= 4)
			{
				cout << "�������..." << endl;
				cout << "�޸�ʧ��..." << endl;
				getchar(); getchar();
				return;
			}


			switch (choose)
			{
			case 1:
			{
				cout << "������������..." << endl;
				cin >> name0;
			}break;
			case 2:
			{
				while (true)
				{
					cout << "�������µ�ְ�����" << endl;
					cin >> id0;
					getchar();
					if (if_id_chong(id0))
					{
						cout << "ְ������ظ�����һ������..." << endl;
					}
					else break;
				}
			}break;
			case 3:
			{
				while (true)
				{
					cout << "�������µĲ��ű��" << endl;
					cin >> Bumen_id0;
					getchar();
					if (Bumen_id0 <= 0 || Bumen_id0 >= 4)
					{
						cout << "�������..." << endl;
					}
					else break;
				}

			}break;
			}
			worker_array.erase(it);
			add_worker(name0, id0, Bumen_id0);
			cout << "�޸ĳɹ�!!!" << endl;
			menu().save_infor();
			getchar();
			return;
		}
	}
	cout << "û�ҵ���ְ��..." << endl;
	getchar(); getchar();
}


//id��ѯ,����չʾԱ����Ϣ
void menu::find_wker_infor()
{
	cout << "������Ҫ��ѯ��Ա�����" << endl;
	int id1;
	cin >> id1;
	vector<worker*>::iterator it = worker_array.begin();
	for (; it != worker_array.end(); it++)
	{
		if (id_chong(*it, id1) != NULL)
		{
			cout << "�ҵ���ְ������" << endl;
			getchar(); getchar();
			system("cls");
			(*it)->shoe_infor();
			getchar();
			return;
		}
	}
	cout << "û�ҵ���ְ��..." << endl;
	getchar(); getchar();
}

//�º�������������
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
//���ձ������
void menu::sort_by_id()
{
	int choose;
	while (true)
	{
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.��ְ���������  2.��ְ����Ž���" << endl;
		cin >> choose;
		getchar();
		if (choose <= 0 || choose >= 3)
		{
			cout << "�������..." << endl;
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
			cout << "��Ա��..." << endl;
			getchar(); 

		}
		else
		{
			for (; it != worker_array.end(); it++)
			{
				(*it)->shoe_infor();
			}
			cout << "��ӡ���..." << endl;
			getchar(); 
		}
	}break;
	case 2:
	{
		sort(worker_array.begin(), worker_array.end(), cmp_toLo());
		vector<worker*>::iterator it = worker_array.begin();
		if (m_number == 0)
		{
			cout << "��Ա��..." << endl;
			getchar(); 

		}
		else
		{
			for (; it != worker_array.end(); it++)
			{
				(*it)->shoe_infor();
			}
			cout << "��ӡ���..." << endl;
			getchar(); 
		}
	}break;
	}

}

//����ĵ�
void menu::clear_file()
{
	ofstream ofs;
	ofs.open(filename, ios::trunc);
	ofs.close();
	cout << "�ĵ������..." << endl;
	getchar(); getchar();
}