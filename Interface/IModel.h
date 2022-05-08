#ifndef IMODEL_H_
#define IMODEL_H_

class IModel
{
public:
	virtual void SetOrgin(float _x, float _y, float _z) = 0;
	virtual void move(float _x, float _y, float _z) = 0;
	virtual void rotate(float _x, float _y, float _z) = 0;
	virtual IMesh* Get_Mesh() { return nullptr; }
};
#endif // !IMODEL_H_
