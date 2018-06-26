#include "Storable.h"
#include "definedValues.h"
#include <string.h>

Writer & Writer::operator <<(int & data)
{
	fout.write( (char*) &data, szInt);
	return *this;
}

Writer & Writer::operator <<(const int & data)
{
	fout.write( (char*) &data, szInt);
	return *this;
}

Writer & Writer::operator <<(char & data)
{
	fout.write( (char*) &data, szChar);
	return *this;
}

Writer & Writer::operator <<(char *& data)
{
	int len = strlen(data); 
	fout.write((char*)&len,szInt);
	fout.write(data,len);
	return *this;
}

Writer & Writer::operator <<(const char *& data)
{
	int len = strlen(data); 
	fout.write((char*)&len,szInt);
	fout.write(data,len);
	return *this;
}

Writer & Writer::operator <<(bool & data)
{
	fout.write( (char*) &data, szBool);
	return *this;
}

Writer & Writer::operator <<(const bool & data)
{
	fout.write( (char*) &data, szBool);
	return *this;
}

Writer & Writer::operator <<(const vector<char>& vec) 
{
	int len = vec.size();
	fout.write( (char*) &len, szInt );
	for (
		vector<char>::const_iterator it = 
			vec.begin(); 
		it != vec.end(); 
		it++
		)
	{
		char theChar = it[0];
		fout.write( (char*) &theChar, szChar);
	}
	return *this;
}

//******************** Reader ****************************

Reader & Reader::operator >>(int & data)
{
	fin.read( (char*) &data, szInt);
	return *this;
}

Reader & Reader::operator >>(const int & data)
{
	fin.read( (char*) &data, szInt);
	return *this;
}

Reader & Reader::operator >>(char & data)
{
	fin.read( (char*) &data, szChar);
	return *this;
}

Reader & Reader::operator >>(char *& data)
{
	int len;
	fin.read((char *) &len, szInt);
	data = new char[len+1];
	fin.read(data,len);
	data[len]='\0';
	return *this;
}

Reader & Reader::operator >>(bool & data)
{
	fin.read( (char*) &data, szBool);
	return *this;
}

Reader & Reader::operator >>(vector<char>& vec)
{
	char c;
	int len;
	fin.read( (char*) &len, szInt);
	for ( int i = 0; i < len; i++)
	{
		fin.read( (char*) &c, szChar);
		vec.push_back(c);
	}
	return *this;
}
