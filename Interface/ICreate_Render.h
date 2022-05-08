#ifndef ICREATE_RENDER_H_
#define ICREATE_RENDER_H_

class IRender;

class ICreate_Render
{
public:
	IRender* create() { return createRender(); }

protected:
	virtual IRender* createRender() = 0;
};

#endif // !ICREATE_RENDER_H_

