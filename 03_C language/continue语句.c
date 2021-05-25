//continue语句的作用：跳过本次循环，继续下次循环。while循环中是跳到循环条件里，for循环中跳到更新循环变量里（特殊）

//循环输入5个玩家的年龄，统计年龄为负的录入次数   
//如果录入正确，则跳过；输入错误则计数器+1


#include <stdio.h>
main()
{
	int age;
	int i;
	int count=0;
	for(i=0;i<5;i++)
	{
		printf("请输入玩家年龄：");
		scanf("%d",&age);
		if(age>=0)
			continue;   //跳过正确的情况
	    count++;        //替代else count++语句
	}
	printf("输入错误的次数为：%d\n",count);
}

循环次数确定的情况下，通常采用for循环；循环次数不确定的情况时，通常采用while和do-while循环