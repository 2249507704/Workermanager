#include"WorkerManager.h"
//这些函数都是职工管理类下的
WorkerManager::WorkerManager() 
{
	ifstream ifs;
	ifs.open(FINENAME, ios::in);
	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0; //初始化当前人数
		this->m_Emparry = NULL; //初始化员工指针数组
		this->m_Fileisempty = true;

		//关闭文件
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_Emparry = NULL;
		this->m_Fileisempty = true; //文件为空就是true 当文件里加入数据后这个标志变为false

		ifs.close();
		return;
	}

	//3、有文件有数据
	int m_num = this->get_number();
	cout << "当前文件里人数：" << m_num << endl;
	this->m_EmpNum = m_num;	

	//根据职工创建数组
	this->m_Emparry = new Worker * [this->m_EmpNum];

	//初始化职工函数
	this->init_Emp();

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工号：" << this->m_Emparry[i]->m_id << " "
			<< "姓名：" << this->m_Emparry[i]->m_name << " "
			<< "部门编号：" << this->m_Emparry[i]->m_did << endl;
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
//显示菜单函数主体
void WorkerManager::ShowMenu()
{
	cout << "***************************************" << endl;
	cout << "********* 欢迎使用职工管理系统 ********" << endl;
	cout << "*********** 0、退出管理程序 ***********" << endl;
	cout << "*********** 1、增加职工信息 ***********" << endl;
	cout << "*********** 2、显示职工信息 ***********" << endl;
	cout << "*********** 3、删除离职职工 ***********" << endl;
	cout << "*********** 4、修改职工信息 ***********" << endl;
	cout << "*********** 5、查找职工信息 ***********" << endl;
	cout << "*********** 6、按照编号排序 ***********" << endl;
	cout << "*********** 7、清空所有文档 ***********" << endl;
	cout << "***************************************" << endl;
}

//退出程序函数主体
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//保存文件函数
void WorkerManager::save()
{
	ofstream ofs(FINENAME, ios::out);
	//写入数据
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_Emparry[i]->m_id << " "
			<< this->m_Emparry[i]->m_name << " "
			<< this->m_Emparry[i]->m_did << endl;
	}

	//关闭文件
	ofs.close();
}

//统计当前人数
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

//给已有数据初始化
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
		Worker* worker = NULL;  //先让每个指针为空 根据部门去指向派生类

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

		this->m_Emparry[index++] = worker; //每个数据的指针是要放到内部维护的数组中
	}


}


//添加职工函数
void WorkerManager::AddEmploy()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间的大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间 开辟新数组
		Worker ** newSpace = new Worker * [newSize+4];

		//检查是否存在原有数据 如果存在将原有数据存放到新空间内 源空间下的数据在原数组中存放
		if (this->m_Emparry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_Emparry[i];
			}
		}

		//开始输入新数据 因为要批量输入 使用要用for
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int cSelect;

			cout << "请输入第" << i + 1 << "名职工的编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "名职工的姓名" << endl;
			cin >> name;

			cout << "请输入该名职工的职位：" << endl;
			cout << "1---普通员工" << endl;
			cout << "2---经理" << endl;
			cout << "3---老板" << endl;
			cin >> cSelect;

			Worker* worker = NULL;  //要根据创建的不同职位来进行不同的引用 让父类指针为空 用谁指向谁
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
			//将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_Emparry;

		//更新新空间指向
		this->m_Emparry = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新文件标志
		this->m_Fileisempty = false;

		//提示添加成功
		cout << "成功添加了" << addNum << "人" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误！" << endl;
	}

	system("pause");
	system("cls");
}

//显示职工函数
void WorkerManager::show_emp()
{
	//要显示 先判断文件里是否有东西
	if (this->m_EmpNum == 0)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用窗口
			this->m_Emparry[i]->ShowInfor(); //因为最后是把父类指针存在数组里  所以读取数组
		}
	}
	system("pause");
	system("cls");
}

//查找职工函数
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
	return -1; //都找完了没找到 然后返回-1；
}

//删除职工函数
void WorkerManager::delete_emp()
{
	cout << "请输入你要删除的人的编号：" << endl;
	int id;
	cin >> id;

	int ret = isExist(id);
	if (ret != -1)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//数据前移
            this->m_Emparry[ret] = this->m_Emparry[ret + 1];
		}
		this->m_EmpNum--;
		cout << "删除成功！" << endl;
		if (this->m_EmpNum == 0)
		{
			cout << "文件已经为空" << endl;
		}
		//将结果保存到文件中
		this->save();
		 
	}
	else
	{
		cout << "查无此人" << endl;
	}
		

	system("pause");
	system("cls");
}

//修改职工函数
void WorkerManager::Mod_emp()
{
	if (this->m_EmpNum == 0)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "输入你要修改的人的编号：" << endl;
		int id;
		cin >> id;
		int ret = isExist(id);

		if (ret != -1)
		{
			//先把要修改的职工删掉 然后再在原来的地方添加一个
			delete this->m_Emparry[ret];
			int new_id = 0;
			string new_name = "";
			int new_did = 0;
			cout << "请输入新的编号：" << endl;
			cin >> new_id;

			cout << "请输入名字：" << endl;
			cin >> new_name;

			cout << "请输入该名职工的职位：" << endl;
			cout << "1---普通员工" << endl;
			cout << "2---经理" << endl;
			cout << "3---老板" << endl;
			cin >> new_did;
			
			//因为岗位不同 所以要重新输入建立worker
			Worker* worker = NULL; //根据岗位不同 new出来的对象也不同 但是都是父类指针

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
			//要把新录入的这个对象维护到指针数组中
			this->m_Emparry[ret] = worker;

			cout << "修改成功！" << endl;

			this->save();
		}
	}
	
	system("pause");
	system("cls");

}

//查找职工功能
void WorkerManager::find_emp()
{
	//先判断文档里是否有东西
	if (this->m_EmpNum == 0)
	{
		cout << "文件为空！" << endl;
	}
	else
	{
		cout << "输入你要查找的人的id：" << endl;
		int id;
		cin >> id;
		int ret = isExist(id);
		if (ret != -1)
		{
			this->m_Emparry[ret]->ShowInfor();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序
void WorkerManager::sort()
{
	if (this->m_EmpNum == 0)
	{
		cout << "文件为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择用什么方法对编号进行排序：" << endl;
		cout << "1、升序" << endl;
		cout << "2、降序" << endl;

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
		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->show_emp();
	}
}

//清空
void WorkerManager::Cleardat()
{
	cout << "确定要清空吗？" << endl;
	cout << "1、---确定 " << endl;
	cout << "2、---取消 " << endl;

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

				if (this->m_Emparry != NULL) //判断堆区指针
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						//释放堆区的每一个数据
						if (this->m_Emparry != NULL)
						{
							delete[] this->m_Emparry[i];  //先释放里边的每一个元素
						}
					}
					this->m_EmpNum = 0;//把数组里的人数清零
					delete[] this->m_Emparry;//释放整个数组
					this->m_Emparry = NULL;//把这个指针指向空 防止出现野指针
					this->m_Fileisempty = true;

				}

			}
			else
				break;
		}
		else
			cout << "请重新输入" << endl;
	}
	
	
}