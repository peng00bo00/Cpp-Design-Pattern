#include "Medicine.h"

void M_asplcrp::Accept(Visitor* pvisitor) {
	pvisitor->Visit_aspl(this);
}

void M_fftdnhsp::Accept(Visitor* pvisitor) {
	pvisitor->Visit_fftdnhsp(this);
}

void M_dlx::Accept(Visitor* pvisitor) {
	pvisitor->Visit_dlx(this);
}