#include"WorkerManager.h"
//��Щ��������ְ���������µ�
WorkerManager::WorkerManager() 
{
	ifstream ifs;
	ifs.open(FINENAME, ios::in);
	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0; //��ʼ����ǰ����
		this->m_Emparry = NULL; //��ʼ��Ա��ָ������
		this->m_Fileisempty = true;

		//�ر��ļ�
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_Emparry = NULL;
		this->m_Fileisempty = true; //�ļ�Ϊ�վ���true ���ļ���������ݺ������־��Ϊfalse

		ifs.close();
		return;
	}

	//3�����ļ�������
	int m_num = this->get_number();
	cout << "��ǰ�ļ���������" << m_num << endl;
	this->m_EmpNum = m_num;	

	//����ְ����������
	this->m_Emparry = new Worker * [this->m_EmpNum];

	//��ʼ��ְ������
	this->init_Emp();

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ���ţ�" << this->m_Emparry[i]->m_id << " "
			<< "������" << this->m_Emparry[i]->m_name << " "
			<< "���ű�ţ�" << this->m_Emparry[i]->m_did << endl;
	}


}

WorkerManager::~WorkerManager()
{
	if (this->m_Emparry != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_Emparry[i] != NULL)
			{
				delete this->m_Emparry[i];
				this->m_Emparry[i] = NULL;
			}
		}
		delete[] this->m_Emparry; 
		this->m_Emparry = NULL;
	}
}
//��ʾ�˵���������
void WorkerManager::ShowMenu()
{
	cout << "***************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ ********" << endl;
	cout << "*********** 0���˳�������� ***********" << endl;
	cout << "*********** 1������ְ����Ϣ ***********" << endl;
	cout << "*********** 2����ʾְ����Ϣ ***********" << endl;
	cout << "*********** 3��ɾ����ְְ�� ***********" << endl;
	cout << "*********** 4���޸�ְ����Ϣ ***********" << endl;
	cout << "*********** 5������ְ����Ϣ ***********" << endl;
	cout << "*********** 6�����ձ������ ***********" << endl;
	cout << "*********** 7����������ĵ� ***********" << endl;
	cout << "***************************************" << endl;
}

//�˳�����������
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//�����ļ�����
void WorkerManager::save()
{
	ofstream ofs(FINENAME, ios::out);
	//д������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_Emparry[i]->m_id << " "
			<< this->m_Emparry[i]->m_name << " "
			<< this->m_Emparry[i]->m_did << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ�Ƶ�ǰ����
int WorkerManager::get_number()
{
	ifstream ifs;

	ifs.open(FINENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();

	return num;
}

//���������ݳ�ʼ��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FINENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;  //����ÿ��ָ��Ϊ�� ���ݲ���ȥָ��������

		if (did == 1)
		{
			worker = new Employer(id, name, did);
		}
		else if (did == 2)
		{
			worker = new manager(id, name, did);
		}
		else
			worker = new Boss(id, name, did);

		this->m_Emparry[index++] = worker; //ÿ�����ݵ�ָ����Ҫ�ŵ��ڲ�ά����������
	}


}


//���ְ������
void WorkerManager::AddEmploy()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ� ����������
		Worker ** newSpace = new Worker * [newSize+4];

		//����Ƿ����ԭ������ ������ڽ�ԭ�����ݴ�ŵ��¿ռ��� Դ�ռ��µ�������ԭ�����д��
		if (this->m_Emparry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_Emparry[i];
			}
		}

		//��ʼ���������� ��ΪҪ�������� ʹ��Ҫ��for
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int cSelect;

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "���������ְ����ְλ��" << endl;
			cout << "1---��ͨԱ��" << endl;
			cout << "2---����" << endl;
			cout << "3---�ϰ�" << endl;
			cin >> cSelect;

			Worker* worker = NULL;  //Ҫ���ݴ����Ĳ�ְͬλ�����в�ͬ������ �ø���ָ��Ϊ�� ��˭ָ��˭
			switch (cSelect)
			{
			case 1:
				worker = new Employer(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:

				break;
			}
			//��������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_Emparry;

		//�����¿ռ�ָ��
		this->m_Emparry = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�����ļ���־
		this->m_Fileisempty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ������" << addNum << "��" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

//��ʾְ������
void WorkerManager::show_emp()
{
	//Ҫ��ʾ ���ж��ļ����Ƿ��ж���
	if (this->m_EmpNum == 0)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ô���
			this->m_Emparry[i]->ShowInfor(); //��Ϊ����ǰѸ���ָ�����������  ���Զ�ȡ����
		}
	}
	system("pause");
	system("cls");
}

//����ְ������
int WorkerManager::isExist(int id)
{
	
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_Emparry[i]->m_id == id)
		{
			return i;
			break;
		}
	}
	return -1; //��������û�ҵ� Ȼ�󷵻�-1��
}

//ɾ��ְ������
void WorkerManager::delete_emp()
{
	cout << "��������Ҫɾ�����˵ı�ţ�" << endl;
	int id;
	cin >> id;

	int ret = isExist(id);
	if (ret != -1)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//����ǰ��
            this->m_Emparry[ret] = this->m_Emparry[ret + 1];
		}
		this->m_EmpNum--;
		cout << "ɾ���ɹ���" << endl;
		if (this->m_EmpNum == 0)
		{
			cout << "�ļ��Ѿ�Ϊ��" << endl;
		}
		//��������浽�ļ���
		this->save();
		 
	}
	else
	{
		cout << "���޴���" << endl;
	}
		

	system("pause");
	system("cls");
}

//�޸�ְ������
void WorkerManager::Mod_emp()
{
	if (this->m_EmpNum == 0)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ��˵ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = isExist(id);

		if (ret != -1)
		{
			//�Ȱ�Ҫ�޸ĵ�ְ��ɾ�� Ȼ������ԭ���ĵط����һ��
			delete this->m_Emparry[ret];
			int new_id = 0;
			string new_name = "";
			int new_did = 0;
			cout << "�������µı�ţ�" << endl;
			cin >> new_id;

			cout << "���������֣�" << endl;
			cin >> new_name;

			cout << "���������ְ����ְλ��" << endl;
			cout << "1---��ͨԱ��" << endl;
			cout << "2---����" << endl;
			cout << "3---�ϰ�" << endl;
			cin >> new_did;
			
			//��Ϊ��λ��ͬ ����Ҫ�������뽨��worker
			Worker* worker = NULL; //���ݸ�λ��ͬ new�����Ķ���Ҳ��ͬ ���Ƕ��Ǹ���ָ��

			switch (new_did)
			{
			case 1:
				worker = new Employer(new_id, new_name, new_did);
				break;
			case 2:
				worker = new manager(new_id, new_name, new_did);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_did);
				break;
			default:
				break;
			}
			//Ҫ����¼����������ά����ָ��������
			this->m_Emparry[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			this->save();
		}
	}
	
	system("pause");
	system("cls");

}

//����ְ������
void WorkerManager::find_emp()
{
	//���ж��ĵ����Ƿ��ж���
	if (this->m_EmpNum == 0)
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵ��˵�id��" << endl;
		int id;
		cin >> id;
		int ret = isExist(id);
		if (ret != -1)
		{
			this->m_Emparry[ret]->ShowInfor();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����
void WorkerManager::sort()
{
	if (this->m_EmpNum == 0)
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ����ʲô�����Ա�Ž�������" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;

		int m_way = 0;
		cin >> m_way;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int max = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (m_way == 1)
				{
					if (m_Emparry[max]->m_id > m_Emparry[j]->m_id)
					{
						max = j;
					}
				}
				else
					if (m_Emparry[max]->m_id < m_Emparry[j]->m_id)
					{
						max = j;
					}
			}
			if (i != max)
			{
				Worker* t = m_Emparry[max];
				m_Emparry[max] = m_Emparry[i];
				m_Emparry[i] = t;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->show_emp();
	}
}

//���
void WorkerManager::Cleardat()
{
	cout << "ȷ��Ҫ�����" << endl;
	cout << "1��---ȷ�� " << endl;
	cout << "2��---ȡ�� " << endl;

	int scele = 0;
	while (1)
	{
		cin >> scele;
		if (scele == 1 || scele == 2)
		{
			if (scele == 1)
			{
				ofstream ofs(FINENAME, ios::trunc);
				ofs.close();

				if (this->m_Emparry != NULL) //�ж϶���ָ��
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						//�ͷŶ�����ÿһ������
						if (this->m_Emparry != NULL)
						{
							delete[] this->m_Emparry[i];  //���ͷ���ߵ�ÿһ��Ԫ��
						}
					}
					this->m_EmpNum = 0;//�����������������
					delete[] this->m_Emparry;//�ͷ���������
					this->m_Emparry = NULL;//�����ָ��ָ��� ��ֹ����Ұָ��
					this->m_Fileisempty = true;

				}

			}
			else
				break;
		}
		else
			cout << "����������" << endl;
	}
	
	
}