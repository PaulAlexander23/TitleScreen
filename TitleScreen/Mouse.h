#pragma once

#include "stdafx.h"

class CMouse
{
public:
	CMouse();

	~CMouse();

	int GetX();
	int GetY();
	void UpdateXY();

private:
	int x;
	int y;

};

