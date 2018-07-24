// 20180216 Random map.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int arr[SIZE_ARR_X][SIZE_ARR_Y];
void gotoxy(int x, int y);
void MakeTree(TreeNode *treeNode);
void MakeConnect(TreeNode *treeNode);
int main()
{
	TreeNode *treeNode = new TreeNode;
	treeNode->SetInfo(Matrix(0, 0, SIZE_ARR_X, SIZE_ARR_Y));
	treeNode->SetParentNode(NULL);
	srand(time(NULL));
	system("mode con:cols=120 lines=60");
	memset(arr, 0, sizeof(arr));

	MakeTree(treeNode);
	while (1)
	{
		MakeConnect(treeNode);
		if (treeNode->GetLeftNode()->GetRoomInfo().width > 0)
			break;
	}
	//treeNode->GetLeftNode()->MakeConnection();

	/*for (int sizey = 0; sizey < SIZE_ARR_Y; sizey += SIZE_ARR_Y / 3)
	{
		for (int sizex = 0; sizex < SIZE_ARR_X; sizex += SIZE_ARR_X / 3)
		{
			int num = rand() % 5;
			int num2 = rand() % 5;
			for (int i = sizey + rand() % 5; i < sizey + SIZE_ARR_Y / 3 - rand() % 5; i++)
			{
				for (int j = sizex + num; j < sizex + SIZE_ARR_X / 3 - num2; j++)
				{
					arr[i][j] = 1;
				}
			}
		}
	}
	*/
	
	for (int i = 0; i < SIZE_ARR_Y; i++)
	{
		for (int j = 0; j < SIZE_ARR_X; j++)
		{
			gotoxy(j, i);
			printf("%d", arr[i][j]);
		}
	}


	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MakeTree(TreeNode *treeNode)
{
	Matrix mat1, mat2;
	
	int direction;
	int num = rand() % 2;
	float num1 = rand() % 20 + 40;
	if (num == 0)
	{
		direction = WIDTH;
		int num2 = (treeNode->GetInfo().width - treeNode->GetInfo().x) * (num1 / 100);
		mat1.width = treeNode->GetInfo().width - num2;
		mat2.x = treeNode->GetInfo().width - num2;
		mat1.x = treeNode->GetInfo().x;
		mat2.width = treeNode->GetInfo().width;
		mat1.y = treeNode->GetInfo().y;
		mat2.y = treeNode->GetInfo().y;
		mat1.height = treeNode->GetInfo().height;
		mat2.height = treeNode->GetInfo().height;
	}
	else
	{
		direction = HEIGHT;
		int num2 = (treeNode->GetInfo().height - treeNode->GetInfo().y) * (num1 / 100);
		mat1.height = treeNode->GetInfo().height - num2;
		mat2.y = treeNode->GetInfo().height - num2;
		mat1.y = treeNode->GetInfo().y;
		mat2.height = treeNode->GetInfo().height;
		mat1.x = treeNode->GetInfo().x;
		mat2.x = treeNode->GetInfo().x;
		mat1.width = treeNode->GetInfo().width;
		mat2.width = treeNode->GetInfo().width;
	}
	//std::cout << treeNode->GetInfo().x << ' '
	//	<< treeNode->GetInfo().y << ' '
	//	<< treeNode->GetInfo().width << ' '
	//	<< treeNode->GetInfo().height << std::endl;
	if (mat1.width - mat1.x < 10  ||
		mat1.height - mat1.y < 10 ||
		mat2.width - mat2.x < 10  ||
		mat2.height - mat2.y < 10)
	{
		int a = rand() % 4 + 1;
		int b = rand() % 4 + 1;
		int c = rand() % 4 + 1;
		int d = rand() % 4 + 1;
		for (int i = treeNode->GetInfo().y + c; i < treeNode->GetInfo().height - d; i++)
		{
			for (int j = treeNode->GetInfo().x + a; j < treeNode->GetInfo().width - b; j++)
			{
				arr[i][j] = 1;
			}
		}
		treeNode->SetRoomInfo(Matrix(treeNode->GetInfo().x + a,
			treeNode->GetInfo().y + c,
			treeNode->GetInfo().width - b,
			treeNode->GetInfo().height - d));
		//if(treeNode->GetParentNode()->GetLeftNode() == treeNode)
		//	treeNode->MakeConnection();
		return;
	}
	treeNode->MakeLeftTree(new TreeNode);
	treeNode->GetLeftNode()->SetInfo(mat1);
	treeNode->GetLeftNode()->SetParentNode(treeNode);
	treeNode->GetLeftNode()->SetDirection(direction);
	MakeTree(treeNode->GetLeftNode());
	treeNode->MakeRightTree(new TreeNode);
	treeNode->GetRightNode()->SetInfo(mat2);
	treeNode->GetRightNode()->SetParentNode(treeNode);
	treeNode->GetRightNode()->SetDirection(direction);
	MakeTree(treeNode->GetRightNode());
	return;
}
void MakeConnect(TreeNode *treeNode)
{
	if (!treeNode->GetLeftNode())
	{
		if (treeNode->GetParentNode()->GetLeftNode() == treeNode)
			treeNode->MakeConnection();
		return;
	}
	else if (treeNode->GetRoomInfo().width > 0)
	{
		if (!treeNode->GetParentNode())
			return;
		if (treeNode->GetParentNode()->GetLeftNode() == treeNode)
			treeNode->MakeConnection();
		return;
	}
	else
	{
		MakeConnect(treeNode->GetLeftNode());
		MakeConnect(treeNode->GetRightNode());
	}
}