// bank.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <windows.h>//system

#include <vector>
using namespace std;


//个人账户类型
struct ZhangHu{
	int		id;			//账户编号
	char	name[20];	//账户名
	char	code[20];	//密码
	int		money;		//钱
};

//创建一个动态数组用来保存所有的账户
vector<ZhangHu> zh;


//专门用来接收用户输入的全局变量
int g_select = 0;

//用来标记当前用户的遍历
int g_id = 0;


//欢迎
void welcome();
//处理欢迎界面之后的操作
void welcome_proc();
//管理员登录界面
void manager_login();
//用户登录界面
void users_login();
//退出系统
void tuichu();
//管理员流程处理
void manager_proc();
//用户登录界面
void users_proc();
//查看账户
void checkZH();
//修改账户
void changeZH();
//删除账户
void deleteZH();
//注册用户
void registerZH();	
//用户登录
void yonghulogin();

//用户登录成功后界面
void user_login_in();
//用户登录成功后处理
void user_login_in_proc();

int _tmain(int argc, _TCHAR* argv[])
{
	welcome();
	
	while (1);
	return 0;
}

//管理员流程处理
void manager_proc(){
	printf("<<<<<<<<<<请选择>>>>>>>>>\n");
	scanf("%d", &g_select);
	switch (g_select)
	{
	case 1:		checkZH();	break;
	case 2:		changeZH();		break;
	case 3:		deleteZH();			break;
	default:	manager_login();	break;
	}
}
//用户登录界面
void users_proc(){
	printf("<<<<<<<<<<请选择>>>>>>>>>\n");
	scanf("%d", &g_select);
	switch (g_select)
	{
	case 1:		registerZH();	break;
	case 2:		yonghulogin();		break;
	case 3:		welcome();			break;
	default:	users_login();	break;
	}
}

//管理员登录界面
void manager_login(){
	system("cls");//清除屏幕
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$强哥银行$$$$$$$$$$$$$$$\n");
	printf("  -----------------后台---------------  \n");
	printf("#########################################\n");
	printf(">>>>>> 1 查看账户 <<<<<<<<\n");
	printf(">>>>>> 2 修改账户 <<<<<<<<\n");
	printf(">>>>>> 3 删除账户 <<<<<<<<\n");
	printf(">>>>>> 4 退出   <<<<<<<<\n");

	manager_proc();
}

//用户登录界面
void users_login(){
	system("cls");//清除屏幕
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$强哥银行$$$$$$$$$$$$$$$\n");
	printf("  ----------------客户端---------------  \n");
	printf("#########################################\n");
	printf(">>>>>> 1 新用户注册 <<<<<<<<\n");
	printf(">>>>>> 2 老用户登录 <<<<<<<<\n");
	printf(">>>>>> 3 退出   <<<<<<<<\n");

	users_proc();
}


//退出系统
void tuichu(){
	system("cls");//清除屏幕
	printf("#########################################\n");
	printf("  -----------------再见---------------  \n");
	printf("  $$$$$$$$$$$$感谢使用强哥银行$$$$$$$$$$$$$\n");
	printf("#########################################\n");
	Sleep(2000);//延时
	exit(NULL);//结束进程
}


//处理欢迎界面之后的操作
void welcome_proc(){
	char userName[25];
	char passWord[25];
	int i = 0;
	printf("<<<<<<<<<<请选择>>>>>>>>>\n");
	scanf("%d", &g_select);
	switch (g_select)
	{
	case 1:	
t1:
		printf("请输入账号:");
		scanf("%s", userName);
		if (strcmp(userName, "root") == 0){
			printf("请输入密码:");
			scanf("%s", passWord);
			if (strcmp(passWord, "123456") == 0){//管理员登录验证 通过
				manager_login();
			}
			else{
				printf("管理员登录验证失败!\n");
				Sleep(2000);
				welcome();
			}
		}
		else{
			
			if (i < 3){
				printf("账号错误,请重新输入!\n");
				i++;
				goto t1;
			}
			else{
				printf("您已经输错3次账号了,请滚犊子!\n");
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

//欢迎
void welcome(){
	system("cls");//清除屏幕
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$强哥银行$$$$$$$$$$$$$$$\n");
	printf("#########################################\n");
	printf(">>>>>> 1 管理员 <<<<<<<<\n");
	printf(">>>>>> 2 用户   <<<<<<<<\n");
	printf(">>>>>> 3 退出   <<<<<<<<\n");
	welcome_proc();
}


//查看账户
void checkZH(){
	vector<ZhangHu>::iterator  it;
	if (zh.size() == 0){
		printf("你这个银行一个用户都没有,查看个毛线哦!\n");
		Sleep(2000);
		manager_login();
	}
	else{
		printf("id\t账户名\t密码\t余额\n");
		for (it = zh.begin(); it != zh.end(); it++){
			printf("%d\t%s\t%s\t%d\n", it->id,it->name,it->code,it->money);
		}
	}
}
//修改账户
void changeZH(){

}
//删除账户
void deleteZH(){

}


//注册用户
void registerZH(){
	ZhangHu newZH;

	printf("请输入账户名:");
	scanf("%s", newZH.name);
	printf("请输入密码:");
	scanf("%s", newZH.code);
	printf("请输入启动资金:");
	scanf("%d", &newZH.money);

	newZH.id = zh.size() + 1;
	//把新账户存入动态数组zh中
	zh.push_back(newZH);

	printf("注册账户成功!\n");
	Sleep(1000);
	users_login();
}

//用户登录
void yonghulogin(){
	char name[20];
	char code[20];
	printf("请输入账户名:");
	scanf("%s", name);
	printf("请输入密码:");
	scanf("%s", code);

	//循环遍历整个数组 zh
	vector<ZhangHu>::iterator  it;
	for (it = zh.begin(); it != zh.end(); it++){
		if (strcmp(it->name, name) == 0 &&
			strcmp(it->code, code) == 0){
			printf("登录成功!\n");
			Sleep(2000);
			g_id = it->id;//记录当前用户id
			user_login_in();
		}
	}
	printf("登录失败\n");
	Sleep(1000);
	users_login();
}



//用户登录成功后界面
void user_login_in(){
	system("cls");//清除屏幕
	printf("#########################################\n");
	printf("  $$$$$$$$$$$$$$$强哥银行$$$$$$$$$$$$$$$\n");
	printf("  ----------------%s---------------  \n",zh[g_id-1].name);
	printf("#########################################\n");
	printf(">>>>>> 1 存钱 <<<<<<<<\n");
	printf(">>>>>> 2 取钱 <<<<<<<<\n");
	printf(">>>>>> 3 转账 <<<<<<<<\n");
	printf(">>>>>> 4 查看余额 <<<<<<<<\n");
	printf(">>>>>> 5 退出   <<<<<<<<\n");


	user_login_in_proc();
}
//用户登录成功后处理
void user_login_in_proc(){
	printf("<<<<<<<<<<请选择>>>>>>>>>\n");
	scanf("%d", &g_select);
}