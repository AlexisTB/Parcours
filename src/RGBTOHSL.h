#ifndef RGBTOHSL_H
#define RGBTOHSL_H

#include <ADJDS311.h>
#include <Wire.h>

class RGB
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;

	RGB(unsigned char r, unsigned char g, unsigned char b)
	{
		R = r;
		G = g;
		B = b;
	}

	bool Equals(RGB rgb)
	{
		return (R == rgb.R) && (G == rgb.G) && (B == rgb.B);
	}
};

class HSL
{
public:
	int H;
	float S;
	float L;

	HSL(int h, float s, float l)
	{
		H = h;
		S = s;
		L = l;
	}

	bool Equals(HSL hsl)
	{
		return (H == hsl.H) && (S == hsl.S) && (L == hsl.L);
	}
};

static float Min(float a, float b) {
	return a <= b ? a : b;
}

static float Max(float a, float b) {
	return a >= b ? a : b;
}

static HSL RGBToHSL(RGB rgb) {
	HSL hsl = HSL(0, 0, 0);

	float r = (rgb.R / 255.0f); //255
	float g = (rgb.G / 255.0f);
	float b = (rgb.B / 255.0f);

	float min = Min(Min(r, g), b);
	float max = Max(Max(r, g), b);
	float delta = max - min;

	hsl.L = (max + min) / 2;

	if (delta == 0)
	{
		hsl.H = 0;
		hsl.S = 0.0f;
	}
	else
	{
		hsl.S = (hsl.L <= 0.5) ? (delta / (max + min)) : (delta / (2 - max - min));

		float hue;

		if (r == max)
		{
			hue = ((g - b) / 6) / delta;
		}
		else if (g == max)
		{
			hue = (1.0f / 3) + ((b - r) / 6) / delta;
		}
		else
		{
			hue = (2.0f / 3) + ((r - g) / 6) / delta;
		}

		if (hue < 0)
			hue += 1;
		if (hue > 1)
			hue -= 1;

		hsl.H = (int)(hue * 360);
	}

	return hsl;
}

#endif

