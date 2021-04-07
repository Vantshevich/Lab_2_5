#include "CString.h"

CString::CString()
	:m_nSize(0), m_arrStr(nullptr){}

CString::CString(const char* source)
{
	m_nSize = strlen(source);
	m_arrStr = new char[m_nSize + 1];
	strcpy(m_arrStr, source);
}

CString::CString(const CString& source)
{
	m_nSize = source.size();
	m_arrStr = new char[m_nSize + 1];
	strcpy(m_arrStr, source.c_str());
}

CString::~CString()
{
	if (m_arrStr != nullptr)
	{
		delete [] m_arrStr;
		m_arrStr = nullptr;
	}
}

CString& CString::operator=(const CString& source)
{
	m_nSize = source.size();
	delete [] m_arrStr;
	m_arrStr = new char[m_nSize + 1];
	strcpy(m_arrStr, source.c_str());
}

CString& CString::operator=(const char* source)
{
	m_nSize = strlen(source);
	delete [] m_arrStr;
	m_arrStr = new char[m_nSize + 1];
	strcpy(m_arrStr, source);
}

CString& CString::operator+=(const CString& source)
{
	m_nSize += source.size();
	strcat(m_arrStr, source.c_str());
}

bool CString::operator==(const CString& t) const
{
	int minSize = 0;
	if (m_nSize <= t.size())
		minSize = m_nSize;
	else
		minSize = t.size();
	for (int i = 0; i < minSize; i++)
		if (m_arrStr[i] != t.c_str()[i])
			return 0;
	if (m_nSize != t.size())
		return 0;
	return 1;
}

bool CString::operator!=(const CString& t) const
{
	return !(this->operator==(t));
}

bool CString::operator>(const CString& t) const
{
	int minSize = 0;
	if (m_nSize <= t.size())
		minSize = m_nSize;
	else
		minSize = t.size();
	for (int i = 0; i < minSize; i++)
	{
		if (m_arrStr[i] > t.c_str()[i])
			return 1;
		if (m_arrStr[i] < t.c_str()[i])
			return 0;
	}
	if (m_nSize > t.size())
		return 1;
	return 0;
}

bool CString::operator<(const CString& t) const
{
	int minSize = 0;
	if (m_nSize <= t.size())
		minSize = m_nSize;
	else
		minSize = t.size();
	for (int i = 0; i < minSize; i++)
	{
		if (m_arrStr[i] > t.c_str()[i])
			return 0;
		if (m_arrStr[i] < t.c_str()[i])
			return 1;
	}
	if (m_nSize < t.size())
		return 1;
	return 0;
}

bool CString::operator<=(const CString& t) const
{
	int minSize = 0;
	if (m_nSize <= t.size())
		minSize = m_nSize;
	else
		minSize = t.size();
	for (int i = 0; i < minSize; i++)
	{
		if (m_arrStr[i] > t.c_str()[i])
			return 0;
		if (m_arrStr[i] < t.c_str()[i])
			return 1;
	}
	if (m_nSize <= t.size())
		return 1;
	return 0;
}

bool CString::operator>=(const CString& t) const
{
	int minSize = 0;
	if (m_nSize <= t.size())
		minSize = m_nSize;
	else
		minSize = t.size();
	for (int i = 0; i < minSize; i++)
	{
		if (m_arrStr[i] > t.c_str()[i])
			return 1;
		if (m_arrStr[i] < t.c_str()[i])
			return 0;
	}
	if (m_nSize >= t.size())
		return 1;
	return 0;
}

char& CString::operator[](int position)
{
	return m_arrStr[position];
}

int CString::FindWord(const char* word, int begin) 
{
	if (word == nullptr || begin < 0)
		return -1;
	int wordLength = strlen(word);
	for (int i = begin; i < m_nSize - wordLength; i++)
	{
		int j = 0;
		while (word[j])
		{
			if (word[j] != m_arrStr[i + j])
				break;
			++j;
		}
		if (j == wordLength)
			return i;
	}
	return -1;
}

bool CString::RemoveVord(const char* word, int begin)
{
	if (word == nullptr || begin < 0)
		return false;
	int wordLength = strlen(word);
	for (int i = begin; i < m_nSize - wordLength; i++)
	{
		int j = 0;
		while (word[j])
		{
			if (word[j] != m_arrStr[i + j])
				break;
			++j;
		}
		if (j == wordLength)
		{
			char* part1 = new char[i];
			char* part2 = new char[m_nSize - i - wordLength];
			for (int k = 0; k < i; k++)
				part1[k] = m_arrStr[k];
			for (int k = i + wordLength; k < m_nSize; k++)
				part2[k - i + wordLength] = m_arrStr[k];
			delete [] m_arrStr;
			m_arrStr = strcat(part1, part2);
			m_nSize = strlen(m_arrStr);
			return true;
		}
	}
	return false;
}

bool CString::InsertAfter(const char* marker, const char* source)
{
	if (marker == nullptr)
		return false;
	int markerLength = strlen(marker);
	for (int i = 0; i < m_nSize - markerLength; i++)
	{
		int j = 0;
		while (marker[j])
		{
			if (marker[j] != m_arrStr[i + j])
				break;
			++j;
		}
		if (j == markerLength)
		{
			int sizeSrc = strlen(source);
			char* part1 = new char[i + markerLength + sizeSrc];
			char* part2 = new char[m_nSize - i - markerLength];
			for (int k = 0; k < i + markerLength; k++)
				part1[k] = m_arrStr[k];
			for (int k = 0; k < sizeSrc; k++)
				part1[k + i + markerLength] = source[k];
			for (int k = i + markerLength; k < m_nSize; k++)
				part2[k - i] = m_arrStr[k];
			delete[] m_arrStr;
			m_arrStr = strcat(part1, part2);
			m_nSize = strlen(m_arrStr);
			return true;
		}
	}
	return false;
}

bool CString::exchange(int position1, int length1, int position2, int length2)
{
	if (position1 > position2)
	{
		int z;
		z = position1;
		position1 = position2;
		position2 = z;
		z = length1;
		length1 = length2;
		length2 = z;
	}
	if (position2 - position1 < length1 || position2 + length2 > m_nSize)
		return false;

	char* newStr = new char[m_nSize];
	int index = 0;
	for (int i = 0; i < position1; i++)
		newStr[i] = m_arrStr[i];
	index += position1;
	for (int i = position2; i < position2 + length2; i++)
		newStr[index + i - position2] = m_arrStr[i];
	index += length2;
	for (int i = position1 + length1; i < position2; i++)
		newStr[index + i - length1 - position1] = m_arrStr[i];
	index += position2 - position1 - length1;
	for (int i = position1; i < position1 + length1; i++)
		newStr[index + i - position1] = m_arrStr[i];
	index += length1;
	for (int i = position2 + length2; i < m_nSize; i++)
		newStr[index + i - position2 - length2] = m_arrStr[i];
	delete[] m_arrStr;
	m_arrStr = newStr;

	return true;
}

bool CString::replace(const char* marker, const char* source)
{
	if (marker == nullptr)
		return false;
	int markerLength = strlen(marker);
	for (int i = 0; i < m_nSize - markerLength; i++)
	{
		int j = 0;
		while (marker[j])
		{
			if (marker[j] != m_arrStr[i + j])
				break;
			++j;
		}
		if (j == markerLength)
		{
			int sizeSrc = strlen(source);
			char* part1 = new char[i + sizeSrc];
			char* part2 = new char[m_nSize - i - markerLength];
			for (int k = 0; k < i; k++)
				part1[k] = m_arrStr[k];
			for (int k = 0; k < sizeSrc; k++)
				part1[k + i] = source[k];
			for (int k = i + markerLength; k < m_nSize; k++)
				part2[k - i - markerLength] = m_arrStr[k];
			delete[] m_arrStr;
			m_arrStr = strcat(part1, part2);
			m_nSize = strlen(m_arrStr);
			return true;
		}
	}
	return false;
}

bool CString::IsPalindrom()
{
	for (int i = 0; i < m_nSize / 2; i++)
	{
		if (m_arrStr[i] != m_arrStr[m_nSize - i - 1])
			return false;
	}
	return true;
}

std::istream& CString::operator>>(std::istream& in, CString& str)
{
	
}

int CString::strlen(const char* str)
{
	int length = 0;
	while (str[length++]);
	return length;
}

void CString::strcpy(char* destination, const char* source) 
{
	int i = 0;
	do {
		destination[i] = source[i];
	} while (source[i++]);
}

char* CString::strcat(char* destination, const char* source) 
{
	int dSize = strlen(destination);
	int sSize = strlen(source);

	char* newStr = new char[dSize + sSize + 1];
	for (int i = 0; i < dSize; i++)
		newStr[i] = destination[i];
	for (int i = dSize; i < dSize + sSize; i++)
		newStr[i] = source[i - dSize];
	newStr[dSize + sSize] = '\0';

	delete [] destination;
	destination = newStr;	
	return destination;
}