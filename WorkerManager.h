#pragma once //��ֹͷ�ļ��ظ����� ͷ�ļ��ź�������
#include<iostream>
#include"Worker.h"
#include"Boss.h"
#include"employer.h"
#include"manager.h"
#include<fstream>
#define FINENAME "empfile.txt"

using namespace std;

//������
class WorkerManager 
{
public:
	//���캯��
	WorkerManager();

	//��ʾ�˵�
	void ShowMenu();
	//�˳�������
	void ExitSystem();

	//����ְ����Ϣ
	void AddEmploy();

	//�����ļ�
	void save();
	
	//��ǰ����
	int get_number(); 

	//��ʼ��Ա���ĺ���
	void init_Emp();

	//��ʾְ������
	void show_emp();

	//ɾ��ְ������
	void delete_emp();

	//����ְ������
	int isExist(int id);

	//�޸�ְ������
	void Mod_emp();

	//����ְ������
	void find_emp();

	//������
	void sort();

	//�������
	void Cleardat();

	//��������
	~WorkerManager();

	int m_EmpNum; //��ǰ�ж��ٸ�Ա��
	Worker** m_Emparry; //Ա�������ָ��
	bool m_Fileisempty; //��־�ļ��Ƿ�Ϊ��

	

};