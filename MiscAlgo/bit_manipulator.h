#pragma once

/* .....................Basic getter setter ...................... */

template<typename T>
bool getBit(const T& val, int i)
{
	return (val & 1 << i) != 0;
}

// Set bit to 1
template<typename T>
void setBit(T& val, int i)
{
	val = val | 1 << i;
}

// Set bit to 0
template<typename T>
void clearBit(T& val, int i)
{
	val = val & ~(1 << i);
}

// Clear all MSB until i (inclusive)
template<typename T>
void clearMSBsUntil(T& val, int i)
{
	val = val & ~(~0 << i);
}

// Clear all LSB until i (inclusive)
template<typename T>
void clearLSBsUntil(T& val, int i)
{
	val = val & (~0 << (i+1));
}

// set bit to 'bit'
template<typename T>
void updateBit(T& val, int i, const T& bit)
{
	val = val & ~(1 << i) | bit << i;
}

/* ..................... insertBetween ...................... */

int insertBetween(int m, int n, int j, int i)
{
	int mask = ~((~0) << (j - i + 1));
	m = m & mask;
	m = m << i;
	mask = ~(mask << i);
	n = n & mask;
	return m | n;
}

void printBin(double num)
{
	if (num <= 0 || num >= 1)
		cout << "ERROR" << endl;
	else
	{
		string digits;
		double temp = num;
		int wholeNum;
		for (int i = 0; i<32; i++)
		{
			wholeNum = (int)(temp * 2);
			digits.append(to_string(wholeNum));
			temp = (temp * 2) - wholeNum;
			if (temp == 0)
				break;
		}
		if (temp != 0)
			cout << "ERROR" << endl;
		else
			cout << digits << endl;
	}
}

/* ................. scrren print line ................*/

#include <bitset>

void drawLine(unsigned char screen[], int width, int x1, int x2, int y)
{
	unsigned char mask1 = ~0;
	mask1 = mask1 >> (x1 % 8);

	unsigned char mask2 = ~0;
	mask2 = mask2 << (8 - (x2 % 8));

	bitset<8> a(mask1);
	bitset<8> b(mask2);

	int startb = y*(width / 8) + (x1 / 8);
	int endb = y*(width / 8) + (x2 / 8);

	if (startb == endb)
	{
		screen[startb] = screen[startb] | (mask1 & mask2);
	}
	else
	{
		screen[startb] = screen[startb] | mask1;
		screen[endb] = screen[endb] | mask2;
		for (int i = startb + 1; i<endb; i++)
		{
			screen[i] = 0b11111111;
		}
	}
}
