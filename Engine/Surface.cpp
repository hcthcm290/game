#include "Surface.h"
#include "ChiliWin.h"
#include <fstream>
#include <assert.h>

Surface::Surface(int width, int height)
	:
	width(width),
	height(height)
{
	this->pPixels = new Color[width * height];
}

Surface::Surface(const Surface& a)
	:
	width(a.width),
	height(a.height)
{
	this->pPixels = new Color[width * height];
	for (int i = 0; i < width * height; i++)
	{
		this->pPixels[i] = a.pPixels[i];
	}
}

Surface::Surface(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	width = bmInfoHeader.biWidth;
	height = bmInfoHeader.biHeight;
	this->pPixels = new Color[width * height];
	const int padding = (4 - (width * 3) % 4) % 4;

	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, Color(file.get(), file.get(), file.get()));
		}
		file.seekg(padding, std::ios::cur);
	}

}

Surface::~Surface()
{
	delete[] this->pPixels;
}

Surface& Surface::operator=(const Surface& a)
{
	this->~Surface();
	this->width = a.width;
	this->height = a.height;
	this->pPixels = new Color[width * height];
	for (int i = 0; i < width * height; i++)
	{
		this->pPixels[i] = a.pPixels[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	this->pPixels[width * y + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	return this->pPixels[y * width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

RectI Surface::GetRect() const
{
	return RectI(0,width,0,height);
}
