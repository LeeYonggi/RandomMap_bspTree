#pragma once


struct Matrix
{
	float x, y, width, height;
	Matrix(float _x, float _y, float _width, float _height)
	{
		x = _x, y = _y, width = _width, height = _height; 
	}
	Matrix() { }
	~Matrix() { }
};

enum DIRECTION
{
	WIDTH,
	HEIGHT
};

class TreeNode
{
private:
	TreeNode *leftNode;
	TreeNode *rightNode;
	TreeNode *parentNode;
	Matrix info;
	Matrix roominfo;
	int direction;
	bool connect;

public:
	void MakeLeftTree(TreeNode *sub)
	{
		if (this->leftNode != NULL)
			this->leftNode = NULL;
		this->leftNode = sub;
	}
	void MakeRightTree(TreeNode *sub)
	{
		if (this->rightNode != NULL)
			this->rightNode = NULL;
		this->rightNode = sub;
	}
	void MakeConnection();
	void SetInfo(Matrix sub) { info = sub; }
	void SetParentNode(TreeNode *sub) { parentNode = sub; }
	void SetDirection(int dir) { direction = dir; }
	void SetRoomInfo(Matrix sub) { roominfo = sub; }
	int GetDirection() { return direction; }
	bool GetConnect() { return connect; }
	Matrix GetRoomInfo() { return roominfo; }
	Matrix GetInfo() { return info; }
	TreeNode *GetParentNode() { return parentNode; }
	TreeNode *GetLeftNode() { return leftNode; }
	TreeNode *GetRightNode() { return rightNode; }
	TreeNode() 
	{
		connect = false;
		leftNode = nullptr;
		rightNode = nullptr;
		parentNode = nullptr;
	}
};