/*
* ��˾��ְ����Ϊ����:��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ�����ڲ������Ʊ�š�
�Լ� ��λְ��
//��ͨԱ��ְ��:��ɾ�����������
����ְ��:����ϰ彻�������񣬲��·������Ա��
�ϰ�ְ��:����˾��������


����ϵͳ����Ҫʵ�ֵĹ�������:
�˳��������:�˳���ǰ����ϵͳ
����ְ����Ϣ:ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�ְ����ϢΪ:ְ����š����������ű��
��ʾְ����Ϣ:��ʾ��˾�ڲ�����ְ������Ϣ
ɾ����ְְ��:���ձ��ɾ��ָ����ְ��
�޸�ְ����Ϣ:���ձ���޸�ְ��������Ϣ
����ְ����Ϣ:����ְ���ı�Ż���ְ�����������в�����ص���Ա��Ϣ
���ձ������:����ְ����ţ�������������������û�ָ��
��������ĵ�:����ļ��м�¼������ְ����Ϣ�����ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ)

*/
#include"WorkerManager.h"
//#include"Worker.h"
//#include"employer.h"
//#include"manager.h"
//#include"Boss.h"
//
//void test01()
//{
//	Worker* wk = new Employer(1, "����", 2);
//	wk->ShowInfor();
//	delete wk;
//
//	wk = new manager(2, "����", 3);
//	wk->ShowInfor();
//	delete wk;
//
//	wk = new Boss(3, "����", 4);
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
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0://�˳��������
				wm.ExitSystem();
				break;
			case 1://����ְ����Ϣ
				wm.AddEmploy();
				break;
			case 2://��ʾְ����Ϣ
				wm.show_emp();
				break;
			case 3://ɾ����ְְ��
				wm.delete_emp();
				break;
			case 4://�޸�ְ����Ϣ
				wm.Mod_emp();
				break;
			case 5://����ְ����Ϣ
				wm.find_emp();
				break;
			case 6://���ձ������
				wm.sort();
				break;
			case 7://��������ĵ�
				break;
		default:
			system("cls"); //�����������ݵĻ�ֱ���������
			break;
		}
	}


	system("pause");
	return 0;
}