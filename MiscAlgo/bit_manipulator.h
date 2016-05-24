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

