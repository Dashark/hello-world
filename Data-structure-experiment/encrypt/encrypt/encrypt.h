#ifndef _ _ENCRYPT_H_ _
#define _ _ENCRYPT_H_ _

#include"string.h"
#include"lk_list.h"

class ENCRYPT
{
private:
	String letters;//大小写字母表
	String map;//字母映射表
public:
	ENCRYPT();

	String Encode(const String &str);//返回加密后的文本串
	String Decode(const String &str);//返回解密后的文本串
};

ENCRYPT::ENCRYPT()
{
	letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map = "NgzQTCobmUHelkPdAwxfYIvrsJGnZqtcOBMuhELKpaDWXFyiVRjS";
}

String ENCRYPT::Encode(const String &str)
{
	LinkList<char>MO;//临时线性链表，用于存储加密后的文件串
	for (int i = 0; i < str.Length(); i++)
	{
		int pos;
		for ( pos = 0; pos < 52; pos++)
		{
			if (str[i] == letters[pos])
			{
				MO.Insert(MO.Length() + 1, map[pos]);
				break;
			}
		}
		if (pos == 52)
		{
			MO.Insert(MO.Length() + 1, str[i]);
		}
	}
	String result(MO);//生成加密文本串并返回
	return result;
}

String ENCRYPT::Decode(const String &str)
{
	LinkList<char>MO;//临时线性链表，用于存储加密后的文件串
	for (int i = 0; i < str.Length(); i++)
	{
		int pos;
		for (pos = 0; pos < 52; pos++)
		{
			if (str[i] == map[pos])
			{
				MO.Insert(MO.Length() + 1, letters[pos]);
				break;
			}
		}
		if (pos == 52)
		{
			MO.Insert(MO.Length() + 1, str[i]);
		}
	}
	String result(MO);
	return result;
}

#endif
