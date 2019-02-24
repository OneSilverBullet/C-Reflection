#pragma once
#include "Item.h"

class FileItem : public Item {
public:
	FileItem();
	~FileItem();

	virtual void Print() override;
};