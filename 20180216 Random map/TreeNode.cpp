#include "stdafx.h"

void TreeNode::MakeConnection()
{
	if (roominfo.x < NULL)
		return;
	float num = 50;
	if (direction == WIDTH)
	{
		int initY = roominfo.y * (num / 100) + roominfo.height * (num / 100);
		int initX = roominfo.width;
		for (int i = initX; arr[initY][i] != 1; i++)
		{
			if (i > 59)
				break;
			arr[initY][i] = 2;
		}
	}
	if (direction == HEIGHT)
	{
		int initX = roominfo.x * (num / 100) + roominfo.width * (num / 100);
		int initY = roominfo.height;
		/*for (int i = initY + 1; arr[i][initX] != 1; i++)
		{
			arr[i][initX] = 2;
		}*/
		int i = initY;
		while (1)
		{
			if (arr[i][initX] == 1 || i > 59)
				break;
			arr[i][initX] = 2;
			i++;
		}
	}
	connect = true;
	if (!parentNode->GetParentNode())
		return;
	parentNode->SetRoomInfo(parentNode->GetRightNode()->GetRoomInfo());
	if (parentNode != parentNode->parentNode->GetLeftNode())
		return;
	else
	{
		parentNode->MakeConnection();
	}
}
