// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	BitLen = len;
	MemLen = len / (sizeof(TELEM) * 8) + (len % (sizeof(TELEM) * 8) != 0);
	pMem = new TELEM(MemLen);
	for(int i = 0; i < MemLen;i++) pMem[i] = '0';
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM(MemLen);

	for(int i = 0 ; i < MemLen; i++) pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return pMem[n];

}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	pMem[n] = '1';
}

void TBitField::ClrBit(const int n) // очистить бит
{
	pMem[n] = '0';
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM(MemLen);

	for(int i = 0 ; i < MemLen; i++) pMem[i] = bf.pMem[i];
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
	if((BitLen == bf.BitLen) && (MemLen == bf.MemLen) ){
		for(int i = 0 ; i < MemLen; i++){
			if(pMem[i] != bf.pMem[i]) return 0;
		}
	}
	else return 0;
	return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
	return *this;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
	return *this;
}

TBitField TBitField::operator~(void) // отрицание
{
	return *this;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
	for(int i = 0; i < bf.BitLen;i++){
		istr >> bf.pMem[i];
	}
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
	for(int i = 0; i < bf.BitLen;i++){
		ostr << bf.pMem[i];
	}
}