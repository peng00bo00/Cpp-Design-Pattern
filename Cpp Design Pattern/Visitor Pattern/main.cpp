#include "Medicine.h"

int main() {
	Visitor_SFRY visitor_sf;

	M_asplcrp mdc_asplcrp;
	M_fftdnhsp mdc_fftdnhsp;
	M_dlx mdc_dlx;

	mdc_asplcrp.Accept(&visitor_sf);
	mdc_fftdnhsp.Accept(&visitor_sf);
	mdc_dlx.Accept(&visitor_sf);

	Visitor_QYRY visitor_qy;
	mdc_asplcrp.Accept(&visitor_qy);
	mdc_fftdnhsp.Accept(&visitor_qy);
	mdc_dlx.Accept(&visitor_qy);

	return 0;
}