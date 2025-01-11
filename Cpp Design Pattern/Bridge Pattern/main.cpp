#include "ImageOS.h"
#include "ImageFormat.h"

int main() {
	ImageOS* pimgos = new ImageOS_Windows();
	ImageFormat* pimg_png = new Image_png(pimgos);

	pimg_png->parsefile("./filename.png");

	delete pimg_png;
	delete pimgos;

	return 0;
}