
/*
#define N 5
//动态录入成绩
int main()
{
	double score[N];
	int i; //循环变量
	//使用循环变量操作数组时，注意一个循环只做一件事
	for(i=0;i<N;i++)//将成绩放到数组中
	{
		 printf("请输入第%d门成绩: ",i+1);
		 scanf("%lf",&score[i]);
	}
	for(i=0;i<N;i++)//输出成绩
	{
         printf("第%d门成绩是：%.2lf\n",i+1,score[i]);
	}
}
*/


//使用控制台编写一个小游戏分别实现以下功能：新增数据、修改数据、查询数据、数据排序  增删改除
//游戏规则：游戏一共进行10天，每天结算好感度，一旦有三个或以上的嫔妃好感度低于60，则发生暴乱，游戏结束
//char name[8];用来存放用户输入的姓名
//char name[6][8];嫔妃姓名数组，最多容纳6个字符串，每个字符串的最大长度为8个英文字符（4个汉字）


#include <stdio.h>


int main()
{
	int i;
	int count = 5;  //当前未打入冷宫的嫔妃个数
	//使用字符数组表示字符串  姓名
	char emperorname[20];
    int choice;     //皇帝的选择1-4之间
	char names[6][8] = {"貂蝉", "杨玉环", "西施", "昭君" , "东施"};    //用二维数组表示嫔妃的姓名
	char levelnames[5][8] = {"贵人" ,"嫔妃" ,"贵妃" ,"皇贵妃" ,"皇后"}; 
	int levels[6] = {1,2,0,0,0,-1};//存放每位妃子的级别，每个数组元素对应每个妃子的当前级别
    int loves[6] = {100,100,100,100,100,-1};  //对应每个妃子的好感度，初始值都为100
    
	printf("测试代码，查看当前嫔妃的状态\n");
	printf("姓名\t级别\t好感度\n");
	for(i=0;i < count;i++)
	{
		printf("%s\t%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);
	}


	printf("请输入当前皇帝名号：");
	scanf("%s",emperorname);  //录入字符串时，不需要&符号
	printf("欢迎%s,万岁万岁万万岁\n",emperorname); 

	printf("1、皇帝下旨选妃： \t\t (增加功能)\n");
    printf("2、翻盘宠幸：\t\t(修改状态功能)\n");
    printf("3、打入冷宫：\t\t(删除功能)\n");
    printf("4、略略略\n");
	printf("陛下请选择：");

	scanf("%d",&choice);
	switch(choice)
	{
	case 1: printf(1、皇帝下旨选妃： \t\t (增加功能)\n");
			break;
	case 2: printf("2、翻盘宠幸：\t\t(修改状态功能)\n");
		    break;
	case 3: printf("3、打入冷宫：\t\t(删除功能)\n");
            break;
	case 4: printf("4、略略略\n");
		    break;
    default: printf("请再次确认\n");
	}

}




















