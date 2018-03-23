#include "stdafx.h"
#include "Director.h"

const ObjectStorage& 
Director::createObjectStorage(ObjectStorageBuilder& builder) const
{
	builder.createObjectStorage();
	return builder.getObjectStorage();
}
