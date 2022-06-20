#pragma once //防止头文件重复包含 头文件放函数声明
#include<iostream>
#include"Worker.h"
#include"Boss.h"
#include"employer.h"
#include"manager.h"
#include<fstream>
#define FINENAME "empfile.txt"

using namespace std;

//管理类
class WorkerManager 
{
public:
	//构造函数
	WorkerManager();

	//显示菜单
	void ShowMenu();
	//退出程序函数
	void ExitSystem();

	//增加职工信息
	void AddEmploy();

	//保存文件
	void save();
	
	//当前人数
	int get_number(); 

	//初始化员工的函数
	void init_Emp();

	//显示职工函数
	void show_emp();

	//删除职工函数
	void delete_emp();

	//查找职工函数
	int isExist(int id);

	//修改职工函数
	void Mod_emp();

	//查找职工功能
	void find_emp();

	//排序函数
	void sort();

	//清空数据
	void Cleardat();

	//析构函数
	~WorkerManager();

	int m_EmpNum; //当前有多少个员工
	Worker** m_Emparry; //员工数组的指针
	bool m_Fileisempty; //标志文件是否为空

	

};