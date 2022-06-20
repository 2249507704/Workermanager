/*
* 公司中职工分为三类:普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工所在部门名称编号、
以及 岗位职责
//普通员工职责:完成经理交给的任务
经理职责:完成老板交给的任务，并下发任务给员工
老板职责:管理公司所有事务


管理系统中需要实现的功能如下:
退出管理程序:退出当前管理系统
增加职工信息:实现批量添加职工功能，将信息录入到文件中，职工信息为:职工编号、姓名、部门编号
显示职工信息:显示公司内部所有职工的信息
删除离职职工:按照编号删除指定的职工
修改职工信息:按照编号修改职工个人信息
查找职工信息:按照职工的编号或者职工的姓名进行查找相关的人员信息
按照编号排序:按照职工编号，进行排序，排序规则由用户指定
清空所有文档:清空文件中记录的所有职工信息（清空前需要再次确认，防止误删)

*/
#include"WorkerManager.h"
//#include"Worker.h"
//#include"employer.h"
//#include"manager.h"
//#include"Boss.h"
//
//void test01()
//{
//	Worker* wk = new Employer(1, "赵六", 2);
//	wk->ShowInfor();
//	delete wk;
//
//	wk = new manager(2, "李四", 3);
//	wk->ShowInfor();
//	delete wk;
//
//	wk = new Boss(3, "王八", 4);
//	wk->ShowInfor();
//	delete wk;
//}
int main()
{
	//test01();
	WorkerManager wm;
	int choice = 0;
	while (1)
	{
		wm.ShowMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0://退出管理程序
				wm.ExitSystem();
				break;
			case 1://增加职工信息
				wm.AddEmploy();
				break;
			case 2://显示职工信息
				wm.show_emp();
				break;
			case 3://删除离职职工
				wm.delete_emp();
				break;
			case 4://修改职工信息
				wm.Mod_emp();
				break;
			case 5://查找职工信息
				wm.find_emp();
				break;
			case 6://按照编号排序
				wm.sort();
				break;
			case 7://清空所有文档
				break;
		default:
			system("cls"); //输入其他数据的话直接情况返回
			break;
		}
	}


	system("pause");
	return 0;
}