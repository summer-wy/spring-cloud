#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int main() {
//	int a[10] = {1,4,6};
//	int* p = a;
//	int j;
//	j = ( * p)++;
//	printf("%d %d %d\n", a[0], j, *p);
//	j = * p++;
//	printf("%d %d %d", a[0], j, *p);
//}

//int main() {
//	int n;
//	scanf("%d", &n);
//	int a[100];
//	int num=0;
//	for (int i = 0; i < n; i++)
//	{
//	scanf("%d", &a[i]);
//	}
//	for (int  i = 0; i < n; i++)
//	{
//		if (a[i] == 2) {
//			num++;
//		}
//	}
//	printf("%d\n", num);
//}

//void change(int *i) {
//	*i= *i / 2;
//}
//int main() {
//	int *i;
//	scanf("%d", &i);
//	change(&i);
//	printf("%d\n", i);
//}
//字符串逆序
//int main() {
//
//	char c[100], d[100];
//	gets(c);
//	int i, j;
//	for (i = strlen(c) - 1, j = 0; i >= 0; i--, j++) {
//		d[j] = c[i];
//	}
//	d[j] = '\0';
//	int result = strcmp(c, d);
//	if (result < 0) {
//		printf("%d\n", -1);
//	}
//	else if (result > 0)
//	{
//		printf("%d\n", 1);
//	}
//	else
//	{
//		printf("%d\n", 0);
//	}
//
//	return 0;
//}
//a的阶乘
//int main() {
//
//	int a, sum = 1;
//	scanf("%d", &a);
//	for (int i = 1; i <= a; i++) {
//		sum = sum * i;
//	}
//	printf("%d\n", sum);
//}

//判断闰年
// int main() {

// 	int year;
// 	scanf("%d", &year);
// 	if (year % 400 = 0 || year % 4 == 0 && year % 100 != 0) {
// 		printf("yes");
// 	}
// 	else
// 	{
// 		printf("no");
// 	}
// 	return 0;

// }

//翻转12321
// int main() {

// 	int a, b, tmp,c;
// 	scanf("%d", &a);
//     b=0;
//     c=a;
// 	while (a != 0)
// 	{
// 		tmp = a % 10;
// 		b = b * 10 + tmp;
// 		a = a / 10;
// 	}
// 	if (c == b) {
// 		printf("yes");
// 	}
// 	else
// 	{
// 		printf("no");
// 	}

// 	return 0;
// }

//上台阶问题
//int f(int i) {
//	if (1==i||2==i)
//	{
//		return i;
//	}
//	return f(i-2) + f(i - 1);
//}
//int main() {
//	int n=0;
//	scanf("%d", &n);
//	int result =f(n);
//	printf("%d", result);
//	return 0;
//}

//结构体的使用
//struct stuent {
//	int num;
//	char name[10];
//	char sex;
//};
//int main() {
//
//	struct stuent s;
//	scanf("%d %s %c", &s.num, s.name, &s.sex);
//	printf("%d %s %c", s.num, s.name, s.sex);
//	return 0;
//}
