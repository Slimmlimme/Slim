#include "stdafx.h"
#include "Director.h"

const Field& Director::createField(FieldBuilder& builder) const
{
	builder.createField();
	return builder.getField();
}
