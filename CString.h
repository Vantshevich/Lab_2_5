#pragma once
#include <iostream>

class CString
{
public:
	CString();

	CString(const char* source);

	CString(const CString &source);

	~CString();


	CString& operator = (const CString& source);
	CString& operator = (const char* source);
	CString& operator += (const CString& source);

	bool operator == (const CString& t) const;
	bool operator != (const CString& t) const;
	bool operator > (const CString& t) const;
	bool operator < (const CString& t) const;
	bool operator <= (const CString& t) const;
	bool operator >= (const CString& t) const;

	char& operator [] (int position);

	int size() const { return m_nSize; };

	const char* c_str() const { return m_arrStr; }

	int FindWord(const char* word, int begin = 0);

	bool RemoveVord(const char* word, int begin = 0);

	bool InsertAfter(const char* marker, const char* source);

	bool exchange(int position1, int length1, int position2, int length2);

	bool replace(const char* marker, const char* source);

	bool IsPalindrom();

	std::istream& operator>> (std::istream& in, CString& str);
private:
	
	char* m_arrStr;

	int m_nSize;

	int strlen(const char* str);				
	void strcpy(char* destination, const char* source);
	char* strcat(char* destination, const char* source);
};


