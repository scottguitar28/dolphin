// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef VERTEXHANDLER_POSITION_H
#define VERTEXHANDLER_POSITION_H

#include "Common.h"
#include "Utils.h"


// ==============================================================================
// Direct
// ==============================================================================

template<class T>
inline void LOADERDECL _ReadPos8Mem(int iAddress, TVtxAttr* pVtxAttr)
{
	varray->SetPosX(((float)(T)Memory_Read_U8(iAddress)) * posScale);
	varray->SetPosY(((float)(T)Memory_Read_U8(iAddress+1)) * posScale);
	if (pVtxAttr->PosElements)
		varray->SetPosZ(((float)(T)Memory_Read_U8(iAddress+2)) * posScale);
	else
		varray->SetPosZ(1.0);
}
template<class T>
inline void LOADERDECL _ReadPos16Mem(int iAddress, TVtxAttr* pVtxAttr)
{
	varray->SetPosX(((float)(T)Memory_Read_U16(iAddress)) * posScale);
	varray->SetPosY(((float)(T)Memory_Read_U16(iAddress+2)) * posScale);
	if (pVtxAttr->PosElements)
		varray->SetPosZ(((float)(T)Memory_Read_U16(iAddress+4)) * posScale);
	else
		varray->SetPosZ(1.0);
}

void LOADERDECL _ReadPosFloatMem(int iAddress, TVtxAttr* pVtxAttr)
{
	u32 uTemp;
	uTemp = Memory_Read_U32(iAddress  ); 
	varray->SetPosX(*(float*)&uTemp);
	uTemp = Memory_Read_U32(iAddress+4); 
	varray->SetPosY(*(float*)&uTemp);
	if (pVtxAttr->PosElements)
	{
		uTemp = Memory_Read_U32(iAddress+8);
		varray->SetPosZ(*(float*)&uTemp);
	}
	else
		varray->SetPosZ(1.0);	
}

void LOADERDECL Pos_ReadDirect_UByte(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	varray->SetPosX((float)DataReadU8() * posScale);
	varray->SetPosY((float)DataReadU8() * posScale);

	if (pVtxAttr->PosElements)
		varray->SetPosZ((float)DataReadU8() * posScale);
	else
		varray->SetPosZ(1.0);
}

void LOADERDECL Pos_ReadDirect_Byte(const void* _p)
{	
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	varray->SetPosX((float)(s8)DataReadU8() * posScale);
	varray->SetPosY((float)(s8)DataReadU8() * posScale);

	if (pVtxAttr->PosElements)
		varray->SetPosZ((float)(s8)DataReadU8() * posScale);
	else
		varray->SetPosZ(1.0);
}

void LOADERDECL Pos_ReadDirect_UShort(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;

	varray->SetPosX((float)DataReadU16() * posScale);
	varray->SetPosY((float)DataReadU16() * posScale);

	if (pVtxAttr->PosElements)
		varray->SetPosZ((float)DataReadU16() * posScale);
	else
		varray->SetPosZ(1.0);
}

void LOADERDECL Pos_ReadDirect_Short(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;

	varray->SetPosX((float)(s16)DataReadU16() * posScale);
	varray->SetPosY((float)(s16)DataReadU16() * posScale);

	if (pVtxAttr->PosElements)
		varray->SetPosZ((float)(s16)DataReadU16() * posScale);
	else
		varray->SetPosZ(1.0);
}

void LOADERDECL Pos_ReadDirect_Float(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;

	varray->SetPosX(DataReadF32()); 
	varray->SetPosY(DataReadF32());

	if (pVtxAttr->PosElements)
		varray->SetPosZ(DataReadF32());
	else
		varray->SetPosZ(1.0);
}

// ==============================================================================
// Index 8
// ==============================================================================

void LOADERDECL Pos_ReadIndex8_UByte(const void* _p) 
{ 
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u8 Index = DataReadU8();
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos8Mem<u8>(iAddress, pVtxAttr);
}
void LOADERDECL Pos_ReadIndex8_Byte(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u8 Index = DataReadU8();
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos8Mem<s8>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex8_UShort(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u8 Index = DataReadU8();
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos16Mem<u16>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex8_Short(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u8 Index = DataReadU8();
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos16Mem<s16>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex8_Float(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u8 Index = DataReadU8();
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPosFloatMem(iAddress, pVtxAttr);
}

// ==============================================================================
// Index 16
// ==============================================================================

void LOADERDECL Pos_ReadIndex16_UByte(const void* _p){
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u16 Index = DataReadU16(); 
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos8Mem<u8>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex16_Byte(const void* _p){
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u16 Index = DataReadU16(); 
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos8Mem<s8>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex16_UShort(const void* _p){
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u16 Index = DataReadU16(); 
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos16Mem<u16>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex16_Short(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u16 Index = DataReadU16(); 
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPos16Mem<s16>(iAddress, pVtxAttr);
}

void LOADERDECL Pos_ReadIndex16_Float(const void* _p)
{
	TVtxAttr* pVtxAttr = (TVtxAttr*)_p;
	u16 Index = DataReadU16(); 
	u32 iAddress = arraybases[ARRAY_POSITION] + (Index * arraystrides[ARRAY_POSITION]);
	_ReadPosFloatMem(iAddress, pVtxAttr);
}

#endif