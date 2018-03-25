#include "ObjectStorageBuilder.h"
#ifndef H_DIRECTOR
#define H_DIRECTOR

class Director
{
public:
	const ObjectStorage& createObjectStorage(ObjectStorageBuilder& builder) const;
};
#endif // !H_DIRECTOR