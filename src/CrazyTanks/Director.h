#pragma once
#include "ObjectStorageBuilder.h"

class Director
{
public:
	const ObjectStorage& createObjectStorage(ObjectStorageBuilder& builder) const;
};