// bank.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <windows.h>//system

#include <vector>
using namespace std;


//�����˻�����
struct ZhangHu{
	int		id;			//�˻����
	char	name[20];	//�˻���
	char	code[20];	//����
	int		money;		//Ǯ
};

//����һ����̬���������������е��˻�
vector<ZhangHu> zh;


//ר�����������û������ȫ�ֱ���
int g_select = 0;

//������ǵ�ǰ�û��ı���
int g_id = 0;


//��ӭ
void welcome();
//����ӭ����֮��Ĳ���
void welcome_proc();
//����Ա��¼����
void manager_login();
//�û���¼����
void users_login();
//�˳�ϵͳ
void tuichu();
//����Ա���̴���
void manager_proc();
//�û���¼����
void users_proc();
//�鿴�˻�
void checkZH();
//�޸��˻�
void changeZH();
//ɾ���˻�
void deleteZH();
//ע���û�
void registerZH();	
//�û���¼
void yonghulogin();

//�û���¼�ɹ������
void user_login_in();
//�û���¼�ɹ�����
void user_login_in_proc();

int _tmain(int argc, _TCHAR* argv[])
{
	welcome();
	
	while (1);
	return 0;
}

//����Ա���̴���
void manager_proc(){
	printf("<<<<<<<<<<��ѡ��>>>>>>>>>\n");
	scanf("%d", &g_select);
	switch (g_select)
	{
	case 1:		checkZH();	break;
	case 2:		changeZH();		break;
	case 3:		deleteZH();			break;
	default:	manager_login();	break;
	}
}
//�û���¼����
void users_proc(){
	printf("<<<<<<<<<<��ѡ��>>>>>>>>>\n");
	scanf("%d", &g_select);
	switch (g_select)
	{
	case 1:		registerZH();	break;
	case 2:		yonghulogin();		break;
	case 3:		welcome();			break;
	default:	users_login();	break;
	}
}

//����Ա��¼����
void manager_login(){
	system("cls");//�����Ļ
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$ǿ������$$$$$$$$$$$$$$$\n");
	printf("  -----------------��̨---------------  \n");
	printf("#########################################\n");
	printf(">>>>>> 1 �鿴�˻� <<<<<<<<\n");
	printf(">>>>>> 2 �޸��˻� <<<<<<<<\n");
	printf(">>>>>> 3 ɾ���˻� <<<<<<<<\n");
	printf(">>>>>> 4 �˳�   <<<<<<<<\n");

	manager_proc();
}

//�û���¼����
void users_login(){
	system("cls");//�����Ļ
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$ǿ������$$$$$$$$$$$$$$$\n");
	printf("  ----------------�ͻ���---------------  \n");
	printf("#########################################\n");
	printf(">>>>>> 1 ���û�ע�� <<<<<<<<\n");
	printf(">>>>>> 2 ���û���¼ <<<<<<<<\n");
	printf(">>>>>> 3 �˳�   <<<<<<<<\n");

	users_proc();
}


//�˳�ϵͳ
void tuichu(){
	system("cls");//�����Ļ
	printf("#########################################\n");
	printf("  -----------------�ټ�---------------  \n");
	printf("  $$$$$$$$$$$$��лʹ��ǿ������$$$$$$$$$$$$$\n");
	printf("#########################################\n");
	Sleep(2000);//��ʱ
	exit(NULL);//��������
}


//����ӭ����֮��Ĳ���
void welcome_proc(){
	char userName[25];
	char passWord[25];
	int i = 0;
	printf("<<<<<<<<<<��ѡ��>>>>>>>>>\n");
	scanf("%d", &g_select);
	switch (g_select)
	{
	case 1:	
t1:
		printf("�������˺�:");
		scanf("%s", userName);
		if (strcmp(userName, "root") == 0){
			printf("����������:");
			scanf("%s", passWord);
			if (strcmp(passWord, "123456") == 0){//����Ա��¼��֤ ͨ��
				manager_login();
			}
			else{
				printf("����Ա��¼��֤ʧ��!\n");
				Sleep(2000);
				welcome();
			}
		}
		else{
			
			if (i < 3){
				printf("�˺Ŵ���,����������!\n");
				i++;
				goto t1;
			}
			else{
				printf("���Ѿ����3���˺���,�������!\n");
				Sleep(2000);
				welcome();
			}
		}
		
		break;
	case 2:		users_login();		break;
	case 3:		tuichu();			break;
	default:	welcome();			break;
	}
}

//��ӭ
void welcome(){
	system("cls");//�����Ļ
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$ǿ������$$$$$$$$$$$$$$$\n");
	printf("#########################################\n");
	printf(">>>>>> 1 ����Ա <<<<<<<<\n");
	printf(">>>>>> 2 �û�   <<<<<<<<\n");
	printf(">>>>>> 3 �˳�   <<<<<<<<\n");
	welcome_proc();
}


//�鿴�˻�
void checkZH(){
	vector<ZhangHu>::iterator  it;
	if (zh.size() == 0){
		printf("���������һ���û���û��,�鿴��ë��Ŷ!\n");
		Sleep(2000);
		manager_login();
	}
	else{
		printf("id\t�˻���\t����\t���\n");
		for (it = zh.begin(); it != zh.end(); it++){
			printf("%d\t%s\t%s\t%d\n", it->id,it->name,it->code,it->money);
		}
	}
}
//�޸��˻�
void changeZH(){

}
//ɾ���˻�
void deleteZH(){

}


//ע���û�
void registerZH(){
	ZhangHu newZH;

	printf("�������˻���:");
	scanf("%s", newZH.name);
	printf("����������:");
	scanf("%s", newZH.code);
	printf("�����������ʽ�:");
	scanf("%d", &newZH.money);

	newZH.id = zh.size() + 1;
	//�����˻����붯̬����zh��
	zh.push_back(newZH);

	printf("ע���˻��ɹ�!\n");
	Sleep(1000);
	users_login();
}

//�û���¼
void yonghulogin(){
	char name[20];
	char code[20];
	printf("�������˻���:");
	scanf("%s", name);
	printf("����������:");
	scanf("%s", code);

	//ѭ�������������� zh
	vector<ZhangHu>::iterator  it;
	for (it = zh.begin(); it != zh.end(); it++){
		if (strcmp(it->name, name) == 0 &&
			strcmp(it->code, code) == 0){
			printf("��¼�ɹ�!\n");
			Sleep(2000);
			g_id = it->id;//��¼��ǰ�û�id
			user_login_in();
		}
	}
	printf("��¼ʧ��\n");
	Sleep(1000);
	users_login();
}



//�û���¼�ɹ������
void user_login_in(){
	system("cls");//�����Ļ
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$ǿ������$$$$$$$$$$$$$$$\n");
	printf("  ----------------%s---------------  \n",zh[g_id-1].name);
	printf("#########################################\n");
	printf(">>>>>> 1 ��Ǯ <<<<<<<<\n");
	printf(">>>>>> 2 ȡǮ <<<<<<<<\n");
	printf(">>>>>> 3 ת�� <<<<<<<<\n");
	printf(">>>>>> 4 �鿴��� <<<<<<<<\n");
	printf(">>>>>> 5 �˳�   <<<<<<<<\n");


	user_login_in_proc();
}
//�û���¼�ɹ�����
void user_login_in_proc(){
	printf("<<<<<<<<<<��ѡ��>>>>>>>>>\n");
	scanf("%d", &g_select);
}