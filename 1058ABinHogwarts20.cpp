// 1058ABinHogwarts20.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
struct node {
	int Galleon, Sickle, Knut;
}A,B,C;
int main()
{
	scanf("%d.%d.%d %d.%d.%d", &A.Galleon, &A.Sickle, &A.Knut, &B.Galleon, &B.Sickle, &B.Knut);
	int Galleon = A.Galleon + B.Galleon;
	int Sickle= A.Sickle + B.Sickle;
	int Knut= A.Knut + B.Knut;

	C.Knut = Knut% 29;
	C.Sickle = (Sickle + Knut / 29) % 17;
	C.Galleon = Galleon + (Sickle + Knut / 29) / 17;
	printf("%d.%d.%d",C.Galleon,C.Sickle,C.Knut);
	
    return 0;
}

