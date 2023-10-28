extern "C" {
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
#include "lua/lstate.h"
#include "lua/ldo.h"
}

#include <iostream>

typedef unsigned int uint;

typedef struct instr {
	uint OP = 0;
	uint A = 0;
	uint B = 0;
	uint C = 0;
	uint Bx = 0;
	uint sBx = 0;
} instr;

typedef unsigned char byte;
typedef unsigned char code;
typedef unsigned int uint;
typedef unsigned long long undefined8;
typedef unsigned long long undefined4;
typedef unsigned long long undefined;

typedef signed char sbyte;

typedef unsigned long long ulonglong;

typedef long long longlong;

uint opmodeMap[38] = {
	0,
	1,
	0,
	0,
	0,

	1,
	0,

	1,
	0,
	0,

	0,

	0,

	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,

	0,

	2,

	0,
	0,
	0,

	0,
	0,

	0,
	0,
	0,

	2,

	2,

	0,

	0,

	0,
	1,

	0
};

int* m = (int*)malloc(sizeof(int) * 200);
int unaff_EBP = (int)(m)+sizeof(int) * 150;

int sBxConversion(int n) {
	return 131071 + (n - 4) / 8;
}

namespace Alpha {
	void d6bd3(instr *inst, uint param_1, uint param_2) { // GETGLOBAL 5
		char* pcVar1;
		int iVar2;
		code* pcVar3;
		char cVar4;
		uint uVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		byte bVar10;
		//int unaff_EBP;
		int iVar11;
		uint uVar12;
		undefined8* puVar13;

		uVar5 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar5;
		uVar12 = uVar5 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar12;
		sVar6 = (sbyte)uVar12;
		uVar5 = (*(uint*)(unaff_EBP + -0x44) ^
			*(uint*)(unaff_EBP + -0x44) << ((char)uVar5 + 6U & 0x1e | 1)) +
			(0x254fd2caU >> sVar6 | 0x254fd2ca << 0x20 - sVar6) + 0x5d8817b7;
		bVar7 = (char)*(undefined4*)(unaff_EBP + -0xc) * -6 & 0x1eU | 1;
		uVar5 = (uVar5 << bVar7 | uVar5 >> 0x20 - bVar7) ^ (uVar5 >> sVar6 | uVar5 << 0x20 - sVar6) ^
			uVar5;
		uVar5 = uVar5 << 0x13 ^ uVar5;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar5 = (uVar5 - (uVar5 << (bVar10 * -8 & 0x1e | 1))) + 0xaba4dbde;
		bVar8 = bVar10 - 0xf & 0x1e | 1;
		bVar9 = bVar10 - 2 & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar5 = ((uVar5 << bVar8 | uVar5 >> 0x20 - bVar8) ^ (uVar5 >> bVar9 | uVar5 << 0x20 - bVar9) ^
			uVar5) + (0x5e9067f5U >> bVar7 | 0x5e9067f5 << 0x20 - bVar7);
		bVar7 = (bVar10 ^ 0xf5) & 0x1e | 1;
		bVar10 = (bVar10 ^ 8) & 0x1e | 1;
		uVar5 = (uVar5 << bVar7 | uVar5 >> 0x20 - bVar7) ^ (uVar5 >> bVar10 | uVar5 << 0x20 - bVar10) ^
			uVar5;
		uVar5 = uVar5 << 0x13 ^ uVar5;
		uVar5 = 0x3201cc8b - (uVar5 >> 0x12 ^ uVar5);
		puVar13 = (undefined8*)((uVar5 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		iVar11 = (uVar5 & 0x3ffff);
		//pcVar1 = *(char**)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//cVar4 = (char)pcVar1;

		inst->OP = 5;
		inst->A = (uVar5 >> 0x12 & 0xff);
		inst->Bx = iVar11;
	}

	void d67f6(instr* inst, uint param_1, uint param_2) { // LOADK 1
		code* pcVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		int iVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		undefined8* puVar9;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar6;
		bVar3 = (byte)iVar6 & 0x1e | 1;
		uVar8 = (param_2 << 0x14 | param_2 >> 0xc) ^
			(*(uint*)(unaff_EBP + -0x44) >> 0x12 | *(uint*)(unaff_EBP + -0x44) << 0xe) ^
			*(uint*)(unaff_EBP + -0x44);
		*(uint*)(unaff_EBP + -4) = uVar8;
		bVar4 = ((byte)(0x19 >> bVar3) | (byte)(0x19 << 0x20 - bVar3)) & 0x1e | 1;
		bVar5 = (byte)((iVar6 * -3 & 7U) << 2) | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar8 >> bVar4 | uVar8 << 0x20 - bVar4;
		bVar3 = ((byte)(0x18 >> bVar3) | (byte)(0x18 << 0x20 - bVar3)) & 0x1e | 1;
		uVar8 = *(uint*)(unaff_EBP + -0x1c) ^
			(*(uint*)(unaff_EBP + -4) >> bVar3 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar3) ^
			*(uint*)(unaff_EBP + -4);
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar8 = ~(uVar8 << bVar5 | uVar8 >> 0x20 - bVar5);
		bVar3 = cVar2 + 0xfU & 0x1e | 1;
		uVar8 = ((uVar8 - (uVar8 << (-cVar2 - 3U & 0x1e | 1))) * -0x7f ^ 0x480f9d95) * 0x1000001;
		bVar4 = cVar2 - 10U & 0x1e | 1;
		uVar8 = (uVar8 >> bVar3 | uVar8 << 0x20 - bVar3) ^ (uVar8 >> bVar4 | uVar8 << 0x20 - bVar4) ^
			uVar8;
		uVar8 = (uVar8 >> 0x11 | uVar8 << 0xf) ^ (uVar8 >> 0xb | uVar8 << 0x15) ^ uVar8;
		uVar7 = uVar8 * 0x4783b8e3;
		uVar7 = uVar7 >> 5 ^ (uVar7 >> 0x19 | uVar8 * -0x3e238e80) ^ uVar7;
		iVar6 = *(int*)(unaff_EBP + -0x5c);
		puVar9 = (undefined8*)((uVar7 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		uVar8 = uVar7 >> 0x12 & 0xff;

		inst->OP = 1;
		inst->A = uVar8;
		inst->Bx = (uVar7 & 0x3ffff);

		//std::cout << "LOADK " << uVar8 << " " << (uVar7 & 0x3ffff) * 0x10 << std::endl;
	}

	void d4075(instr* inst, uint param_1, uint param_2) { // CALL 28
		byte* pbVar1;
		//ushort* puVar2;
		undefined4* puVar3;
		undefined uVar4;
		undefined4 uVar5;
		short sVar6;
		char cVar7;
		byte bVar8;
		char cVar9;
		char** ppcVar10;
		char* pcVar11;
		byte bVar12;
		int* piVar13;
		int* extraout_ECX;
		char cVar14;
		//undefined2 uVar15;
		uint uVar16;
		int* piVar17;
		int* unaff_EBX;
		//undefined2* puVar18;
		//int unaff_EBP;
		int* piVar19;
		undefined* puVar20;
		undefined* puVar21;
		undefined4* puVar22;
		int iVar23;
		//undefined2 in_SS;
		bool bVar24;
		//float10 extraout_ST0;
		undefined8 uVar25;
		//undefined2 in_stack_00000074;
		undefined4* puStack32;
		int iStack28;
		short sStack24;
		int* piStack12;
		int* piVar26;
		int* piStack4;

		uVar16 = param_2 >> 0x13 ^ *(uint*)(unaff_EBP + -0x44);
		iVar23 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar8 = (byte)iVar23;
		bVar12 = bVar8 & 0x1e | 1;
		uVar16 = (0x6d4c36c8 << bVar12 | 0x6d4c36c8U >> 0x20 - bVar12) ^
			uVar16 - (uVar16 << (bVar8 * '\x02' & 0x1e | 1));
		bVar12 = bVar8 * -10 & 0x1e | 1;
		uVar16 = (uVar16 << bVar12 | uVar16 >> 0x20 - bVar12) ^
			(uVar16 >> bVar12 | uVar16 << 0x20 - bVar12) ^ uVar16;
		puVar21 = *(undefined**)(unaff_EBP + -0x5c);
		iVar23 = ((uVar16 << 0x18 | uVar16 >> 8) ^ (uVar16 << 0x12 | uVar16 >> 0xe) ^ uVar16) +
			iVar23 * -0x34a09016 + -0x667800b0;
		uVar16 = ((iVar23 << (bVar8 + 0xc & 0x1e | 1)) + iVar23) * 0xdbc6c33;
		piVar19 = (int*)((uVar16 >> 0x11 & 0x1ff) - 1);

		inst->OP = 28;
		inst->A = (uVar16 >> 9 & 0xff);
		inst->B = (uVar16 & 0x1ff);
		inst->C = (uVar16 >> 0x11 & 0x1ff);
	}

	void df113(instr* inst, uint param_1, uint param_2) { // RET 30
		byte cVar1;
		char* pcVar2;
		sbyte sVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint iVar7;
		//int unaff_EBP;
		uint uVar8;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar6 = uVar8 & 0x1e | 1;
		sVar3 = (sbyte)uVar6;
		*(uint*)(unaff_EBP + -0xc) = uVar6;
		bVar4 = ((byte)(0x1e << sVar3) | (byte)(0x1e >> 0x20 - sVar3)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar5 = ((byte)(5 << bVar5) | (byte)(5 >> 0x20 - bVar5)) & 0x1e | 1;
		cVar1 = (char)uVar8;
		iVar7 = ((param_2 >> bVar4 | param_2 << 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar5 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -0x44)) * 0x5096706f;
		iVar7 = iVar7 - (iVar7 << (9U - cVar1 & 0x1e | 1));
		uVar6 = iVar7 * 0x2000001;
		uVar6 = ~((uVar6 >> 0x19 | iVar7 * 0x80) ^ (uVar6 >> 0x16 | iVar7 * 0x400) ^ uVar6);
		uVar6 = (uVar6 << 9 | uVar6 >> 0x17) ^ (uVar6 << 4 | uVar6 >> 0x1c) ^ uVar6;
		uVar6 = (uVar6 >> 0xd | uVar6 << 0x13) ^ (uVar6 << 3 | uVar6 >> 0x1d) ^ uVar6;
		uVar6 = uVar6 >> (-cVar1 - 10U & 0x1e | 1) ^ uVar6;
		bVar4 = (byte) * (uint*)(unaff_EBP + -0xc);
		bVar5 = bVar4 & 0x1f;
		bVar4 = bVar4 & 0x1f;
		iVar7 = (((uVar6 << 0x1e | uVar6 >> 2) ^ (uVar6 << 2 | uVar6 >> 0x1e) ^ uVar6) -
			(0x11c7fc00U >> bVar5 | 0x11c7fc00 << 0x20 - bVar5)) + 0x90cf80a;
		uVar6 = (0x31cbc7dcU >> bVar4 | 0x31cbc7dc << 0x20 - bVar4) + 0xee73dfec +
			(iVar7 - (iVar7 << (cVar1 + 0xbU & 0x1e | 1)));
		uVar6 = uVar6 >> 0x11 ^ uVar6;
		bVar4 = (byte) * (uint*)(unaff_EBP + -0xc);
		bVar5 = bVar4 & 0x1f;
		bVar5 = ((byte)(0x17 << bVar5) | (byte)(0x17 >> 0x20 - bVar5)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar6 >> bVar5 | uVar6 << 0x20 - bVar5;
		bVar4 = bVar4 & 0x1f;
		bVar5 = ((byte)(3 << bVar4) | (byte)(3 >> 0x20 - bVar4)) & 0x1e | 1;
		uVar6 = ~(*(uint*)(unaff_EBP + -0xc) ^ (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^ uVar6);
		// *(undefined*)(unaff_EBP + -0x11) =
			// *(undefined*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0x14);
		// pcVar2 = *(char**)(unaff_EBP + -0x5c);
		uVar8 = uVar6 >> 10 & 0x1ff;


		inst->OP = 30;
		inst->A = (uVar6 >> 0x13 & 0xff);
		inst->B = uVar8;
	}

	void d5626(instr* inst, uint param_1, uint param_2) { // CLOSURE 36
		uint* puVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;

		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar8;
		uVar7 = ((param_2 - iVar8) + -0x1415a810) * 0x3146dba9;
		bVar5 = (byte)iVar8;
		bVar3 = (bVar5 ^ 10) & 0x1e | 1;
		bVar4 = bVar5 & 0x1e | 1;
		bVar5 = (bVar5 ^ 0xfb) & 0x1e | 1;
		uVar7 = (uVar7 >> bVar3 | uVar7 << 0x20 - bVar3) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7;
		*(uint*)(unaff_EBP + -0xc) = (*(uint*)(unaff_EBP + -0xc) ^ 0xc) & 0x1e | 1;
		bVar5 = ((byte)(0x1c >> bVar4) | (byte)(0x1c << 0x20 - bVar4)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar7 << bVar5 | uVar7 >> 0x20 - bVar5;
		bVar5 = ((byte)(0x1b >> bVar4) | (byte)(0x1b << 0x20 - bVar4)) & 0x1e | 1;
		uVar7 = *(uint*)(unaff_EBP + -4) ^ (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^ uVar7;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar7 = uVar7 << bVar5 | uVar7 >> 0x20 - bVar5;
		*(uint*)(unaff_EBP + -0xc) = (uVar7 >> 0x15 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		puVar1 = (uint*)(*(int*)(unaff_EBP + -0x60) + 0x14);

		inst->OP = 36;
		inst->A = uVar7 >> 0x15 & 0xff;
		inst->Bx = uVar7 & 0x3ffff;
	}

	void d0800(instr* inst, uint param_1, uint param_2) { // CLOSURE 36
		int iVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		uint* puVar5;
		//int unaff_EBP;
		uint uVar6;
		uint uVar7;

		iVar1 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x4c) = iVar1;
		bVar2 = (byte)iVar1 & 0x1e | 1;
		bVar3 = ((byte)(0x16 << bVar2) | (byte)(0x16 >> 0x20 - bVar2)) & 0x1e | 1;
		bVar4 = ((byte)(7 << bVar2) | (byte)(7 >> 0x20 - bVar2)) & 0x1e | 1;
		uVar6 = ((param_2 >> bVar3 | param_2 << 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar4 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x44)) +
			(0x6d13280b - (0x581e97a9U >> bVar2 | 0x581e97a9 << 0x20 - bVar2));
		uVar6 = (uVar6 >> 0x18 | uVar6 * 0x100) * 0x8001 + 0x9fe4159f;
		uVar6 = ((uVar6 >> 0x11 | uVar6 * 0x8000) ^ (uVar6 * 4 | uVar6 >> 0x1e) ^ uVar6) * 0x31292bef +
			0x2d6a67ca;
		bVar2 = (byte) * (undefined4*)(unaff_EBP + -0x4c);
		bVar3 = (bVar2 ^ 0xf3) & 0x1e | 1;
		uVar6 = (uVar6 * 0x800 ^ uVar6 ^ 0xf14fffe) * 0x6c756097;
		bVar4 = (bVar2 ^ 8) & 0x1e | 1;
		uVar6 = (uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^ (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^
			uVar6;
		bVar2 = bVar2 + 5 & 0x1e | 1;
		uVar7 = (uVar6 << 0xc | uVar6 >> 0x14) ^ (uVar6 >> 7 | uVar6 << 0x19);
		*(uint*)(unaff_EBP + -0x44) = uVar7;
		uVar7 = uVar7 ^ uVar6;
		uVar6 = uVar7 >> bVar2 | uVar7 << 0x20 - bVar2;
		puVar5 = (uint*)(*(int*)(unaff_EBP + -0x60) + 0x14);
		*(uint*)(unaff_EBP + -0x44) = (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);

		inst->OP = 36;
		inst->A = uVar6 & 0xff;
		inst->Bx = (uVar6 >> 0xe);
	}

	void d4f85(instr* inst, uint param_1, uint param_2) { // CLOSURE 36
		undefined4 uVar1;
		uint* puVar2;
		char* pcVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;

		param_2 = ~param_2;
		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar9 = uVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar9;
		sVar4 = (sbyte)uVar9;
		uVar9 = ((param_2 >> 0x1c | param_2 << 4) ^ (param_2 >> 0x12 | param_2 << 0xe) ^ param_2) +
			0x1fc97cff;
		bVar5 = ((byte)(0x11 << sVar4) | (byte)(0x11 >> 0x20 - sVar4)) & 0x1e | 1;
		uVar9 = (uVar9 * 0x20000000 | uVar9 >> 3) ^ (uVar9 >> 6 | uVar9 * 0x4000000) ^ uVar9;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar9 = ~(uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) * 0x41;
		bVar5 = ((byte)(0x1c << bVar6) | (byte)(0x1c >> 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(5 << bVar6) | (byte)(5 >> 0x20 - bVar6)) & 0x1e | 1;
		uVar9 = (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^ (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^
			uVar9;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = bVar5 & 0x1f;
		bVar5 = bVar5 & 0x1f;
		uVar9 = (uVar9 >> 0xd ^ uVar9) - (0x5593fc80 << bVar6 | 0x5593fc80U >> 0x20 - bVar6);
		uVar1 = *(undefined4*)(unaff_EBP + -0xc);
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		bVar6 = (byte)uVar1;
		bVar5 = ((byte)(2 << bVar5) | (byte)(2 >> 0x20 - bVar5)) & 0x1e | 1;
		bVar7 = (bVar6 ^ 8) & 0x1e | 1;
		bVar8 = bVar6 * -0xe & 0x1e | 1;
		puVar2 = (uint*)(unaff_EBP + -0xc);
		*puVar2 = *puVar2 << bVar8 | *puVar2 >> 0x20 - bVar8;
		bVar6 = bVar6 * '\x05' & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -0xc) ^ (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ uVar9;
		uVar9 = *(uint*)(unaff_EBP + -0xc) << bVar7 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar7;
		uVar9 = ~((uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) + 0xb2b169fc);
		*(uint*)(unaff_EBP + -0xc) = (uVar9 >> 4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		puVar2 = (uint*)(*(int*)(unaff_EBP + -0x60) + 0x14);

		inst->OP = 36;
		inst->A = (uVar9 >> 4 & 0xff);
		inst->Bx = (uVar9 >> 0xc & 0x3ffff);
	}

	void d7d2e(instr* inst, uint param_1, uint param_2) { // MOVE 0
		int iVar1;
		sbyte sVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint uVar7;
		//int unaff_EBP;
		uint uVar8;

		uVar8 = *(uint*)(unaff_EBP + -0x44);
		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar8 = (uVar8 >> 0x1d | uVar8 << 3) ^ (uVar8 << 0x13 | uVar8 >> 0xd) ^ uVar8;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar6 = uVar7 & 0x1e | 1;
		sVar2 = (sbyte)uVar6;
		*(uint*)(unaff_EBP + -4) = uVar6;
		bVar3 = ((byte)(8 << sVar2) | (byte)(8 >> 0x20 - sVar2)) & 0x1e | 1;
		uVar8 = (uVar8 << (((byte)uVar7 ^ 10) & 0x1e | 1)) + uVar8;
		uVar8 = uVar8 >> bVar3 | uVar8 << 0x20 - bVar3;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar8 = (uVar8 << 0x1a | uVar8 >> 6) ^ (uVar8 >> 0x15 | uVar8 << 0xb) ^ uVar8;
		bVar4 = 0xcU - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar8 = (0x5a6e2ce4 << bVar3 | 0x5a6e2ce4U >> 0x20 - bVar3) ^ uVar8 << 0xc ^ uVar8;
		uVar8 = uVar8 >> bVar4 | uVar8 << 0x20 - bVar4;
		uVar8 = uVar8 << ((char)*(undefined4*)(unaff_EBP + -0xc) + 6U & 0x1e | 1) ^ uVar8;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar3 = bVar4 & 0x1f;
		bVar4 = bVar4 & 0x1f;
		*(uint*)(unaff_EBP + -0x1c) = uVar8;
		bVar5 = ((byte)(0x15 >> bVar3) | (byte)(0x15 << 0x20 - bVar3)) & 0x1e | 1;
		bVar4 = ((byte)(0x16 >> bVar4) | (byte)(0x16 << 0x20 - bVar4)) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar3 = ((byte)(0xe >> bVar3) | (byte)(0xe << 0x20 - bVar3)) & 0x1e | 1;
		uVar8 = (uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x1c) << bVar3 | *(uint*)(unaff_EBP + -0x1c) >> 0x20 - bVar3) ^
			*(uint*)(unaff_EBP + -0x1c);
		uVar8 = uVar8 >> bVar4 | uVar8 << 0x20 - bVar4;
		uVar8 = (uVar8 << 0x14 | uVar8 >> 0xc) ^ (uVar8 >> 4 | uVar8 << 0x1c) ^ uVar8;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar8 = uVar8 << (-(char)*(undefined4*)(unaff_EBP + -0xc) - 0x10U & 0x1e | 1) ^ uVar8;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar8 = uVar8 - (uVar8 << (((byte)(0x12 >> bVar3) | (byte)(0x12 << 0x20 - bVar3)) & 0x1e | 1));
		uVar8 = ~(uVar8 >> 0x1c | uVar8 * 0x10) * 0x6d5c4b6d;
		uVar8 = uVar8 >> 1 ^ uVar8;
		uVar6 = uVar8 >> 0x16 & 0x1ff;
		uVar8 = uVar8 >> 0xe & 0xff;
		//*(undefined8*)(iVar1 + uVar8 * 0x10) = *(undefined8*)(iVar1 + uVar6 * 0x10);
		//*(undefined4*)(iVar1 + 8 + uVar8 * 0x10) = *(undefined4*)(iVar1 + 8 + uVar6 * 0x10);
		//*(undefined4*)(iVar1 + 0xc + uVar8 * 0x10) = *(undefined4*)(iVar1 + 0xc + uVar6 * 0x10);
		//*(undefined**)(unaff_EBP + -8) = &DAT_00467240;
		*(int*)(unaff_EBP + -0xc) = *(int*)(unaff_EBP + -8) + *(int*)(unaff_EBP + 0xc);
		//uVar8 = *(int*)(unaff_EBP + 8) - *(int*)(unaff_EBP + -0xc);

		inst->OP = 0;
		inst->A = uVar8;
		inst->B = uVar6;
	}

	void d3174(instr* inst, uint param_1, uint param_2) { // CLOSURE 36
		uint* puVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;

		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)((-iVar7 & 3U) << 3) | 1;
		bVar4 = (byte)iVar7;
		bVar3 = bVar4 * -2 & 0x1e | 1;
		uVar5 = (((param_2 << bVar2 | param_2 >> 0x20 - bVar2) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar3 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar3) ^
			*(uint*)(unaff_EBP + -0x44)) - iVar7) + 0x86e3c455;
		uVar6 = (uVar5 ^ 0x39157400) << 2;
		uVar5 = uVar5 >> 0x1e | uVar6;
		uVar5 = (uVar5 << 0xf | uVar6 >> 0x11) ^ (uVar5 << 2 | uVar6 >> 0x1e) ^ uVar5;
		bVar2 = bVar4 - 7 & 0x1e | 1;
		uVar5 = (uVar5 << 0x1a | uVar5 >> 6) ^ (uVar5 >> 6 | uVar5 << 0x1a) ^ uVar5;
		uVar6 = ~(uVar5 - (uVar5 << (bVar4 * '\a' & 0x1e | 1)));
		uVar6 = uVar6 - (uVar6 << (bVar4 - 2 & 0x1e | 1));
		uVar6 = uVar6 >> 0x19 | uVar6 * 0x80;
		uVar6 = uVar6 << bVar2 | uVar6 >> 0x20 - bVar2;
		uVar6 = uVar6 * -0x70000000 | uVar6 * -7 >> 4;
		uVar6 = (uVar6 << (-bVar4 - 0xe & 0x1e | 1)) + uVar6;
		bVar2 = -((char)(iVar7 << 4) - bVar4) & 0x1e | 1;
		bVar3 = bVar4 * '\n' & 0x1e | 1;
		uVar6 = (uVar6 << bVar2 | uVar6 >> 0x20 - bVar2) ^ (uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^
			uVar6;
		bVar4 = bVar4 & 0x1e | 1;
		bVar2 = ((byte)(5 >> bVar4) | (byte)(5 << 0x20 - bVar4)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar6 >> bVar2 | uVar6 << 0x20 - bVar2;
		bVar4 = ((byte)(3 >> bVar4) | (byte)(3 << 0x20 - bVar4)) & 0x1e | 1;
		uVar6 = *(uint*)(unaff_EBP + -0xc) ^ (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^ uVar6;
		*(uint*)(unaff_EBP + -0xc) = (uVar6 >> 6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		puVar1 = (uint*)(*(int*)(unaff_EBP + -0x60) + 0x14);

		inst->OP = 36;
		inst->A = (uVar6 >> 6 & 0xff);
		inst->Bx = (uVar6 >> 0xe);
	}

	// OP_MOVE 0 : A B 
	void d4d65(instr* inst, uint param_1, uint param_2) {

		byte bVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;

		bVar4 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar1 = (bVar4 ^ 8) & 0x1e | 1;
		bVar2 = (bVar4 ^ 4) & 0x1e | 1;
		bVar3 = bVar4 & 0x1e | 1;
		uVar5 = ~(((param_2 << bVar1 | param_2 >> 0x20 - bVar1) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar2 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar2)
			^ *(uint*)(unaff_EBP + -0x44)) * 5);
		uVar5 = (uVar5 >> 2 | uVar5 << 0x1e) + (0x7d76e0c6 << bVar3 | 0x7d76e0c6U >> 0x20 - bVar3);
		uVar5 = uVar5 >> 0x12 | uVar5 * 0x4000;
		uVar5 = uVar5 - (uVar5 << (bVar4 * -7 & 0x1e | 1));
		uVar5 = (uVar5 * 0x1000000 | uVar5 >> 8) ^ (uVar5 * 0x200 | uVar5 >> 0x17) ^ uVar5;
		bVar1 = bVar4 * -10 & 0x1e | 1;
		uVar5 = uVar5 >> 1 | (uint)((uVar5 & 1) != 0) << 0x1f;
		bVar4 = bVar4 * -6 & 0x1e | 1;
		uVar5 = (uVar5 << bVar1 | uVar5 >> 0x20 - bVar1) ^ (uVar5 >> bVar4 | uVar5 << 0x20 - bVar4) ^
			uVar5;
		*(uint*)(unaff_EBP + -0xc) = uVar5;
		//return CONCAT44((uVar5 >> 2 & 0x1ff) * 2, *(uint*)(unaff_EBP + -0xc) >> 0x14);

		inst->OP = 0;
		inst->A = uVar5 >> 0x14;
		inst->B = (uVar5 >> 2 & 0x1ff);
	}


	// OP_MOVE 0 : A B 
	void d6692(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		byte bVar2;
		byte bVar3;
		uint uVar4;
		uint uVar5;
		//int unaff_EBP;
		int iVar6;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar4 = iVar6 * 0x51828a3f ^ param_2 * 9;
		uVar4 = (uVar4 * -0x6000000 | uVar4 * -0x2a156183 >> 7) + 0x4a494f7;
		uVar4 = (uVar4 * 0x4000000 ^ uVar4) + 0x26700da9;
		uVar4 = (uVar4 >> 10 | uVar4 * 0x400000) ^ (uVar4 * 0x20 | uVar4 >> 0x1b) ^ uVar4;
		bVar2 = (byte)iVar6;
		bVar3 = bVar2 & 0x1e | 1;
		uVar4 = uVar4 * 0x7a840585 >> 5 | uVar4 * 0x28000000;
		uVar4 = uVar4 << (bVar2 * -0xf & 0x1e | 1) ^ uVar4;
		uVar4 = uVar4 >> (((byte)(5 >> bVar3) | (byte)(5 << 0x20 - bVar3)) & 0x1e | 1) ^ uVar4 ^ 0xbce8c15
			;
		uVar4 = (uVar4 << 0x1a | uVar4 >> 6) ^ (uVar4 << 0xc | uVar4 >> 0x14) ^ uVar4;
		uVar4 = (uVar4 << 0x16 ^ uVar4) + 0x4d8665cc;
		uVar5 = uVar4 >> 0x12 & 0x1ff;
		iVar6 = *(int*)(unaff_EBP + -0x5c);
		uVar4 = uVar4 & 0xff;

		inst->OP = 0;
		inst->A = uVar4;
		inst->B = uVar5;
	}



	// OP_LOADK 1 : A Bx 
	void d05f1(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		code* pcVar2;
		sbyte sVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		undefined8* puVar8;
		//int unaff_EBP;
		uint uVar9;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar5 = (byte)uVar9;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		param_2 = (param_2 << (0xd - bVar5 & 0x1e | 1)) + param_2;
		uVar7 = param_2 * 0x3ef1fc53;
		uVar7 = ((param_2 * 0x78fe2980 | uVar7 >> 0x19) ^ (param_2 * -0x4380eb4 | uVar7 >> 0x1e) ^ uVar7)
			* 0x21;
		uVar7 = uVar7 << (0xc - bVar5 & 0x1e | 1) ^ uVar7;
		uVar9 = uVar9 & 0x1e | 1;
		sVar3 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar4 = (bVar5 ^ 0xc) & 0x1e | 1;
		uVar7 = ((uVar7 << (((byte)(0x16 >> sVar3) | (byte)(0x16 << 0x20 - sVar3)) & 0x1e | 1)) + uVar7) *
			-0x1ffff;
		bVar5 = bVar5 + 7 & 0x1e | 1;
		bVar6 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 10) & 0x1e | 1;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7;
		uVar7 = uVar7 >> bVar5 | uVar7 << 0x20 - bVar5;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar9 = ~(uVar7 >> (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xf7) & 0x1e | 1) ^ uVar7) *
			0x29f04a4f + *(int*)(unaff_EBP + -0xc) * 0x23437528;
		uVar7 = uVar9 >> 6;
		uVar9 = (uVar9 * 0x4000000 | uVar7) >> 5 | uVar7 << 0x1b;
		bVar4 = ((byte)(0x14 << bVar5) | (byte)(0x14 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar7 = *(uint*)(unaff_EBP + -0xc);
		*(uint*)(unaff_EBP + -0xc) = ~uVar7 & 0x1e | 1;
		bVar6 = ((byte)uVar7 ^ 0xfd) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar7 = (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^ (uVar9 >> bVar5 | uVar9 << 0x20 - bVar5);
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar7 = uVar7 ^ uVar9;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar7 = ~(uVar7 << bVar4 | uVar7 >> 0x20 - bVar4);
		uVar9 = uVar7 >> 0x13 & 0xff;
		puVar8 = (undefined8*)((uVar7 >> 1 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//*(undefined8*)(iVar1 + uVar9 * 0x10) = *puVar8;
		//*(undefined4*)(iVar1 + 8 + uVar9 * 0x10) = *(undefined4*)(puVar8 + 1);
		//*(undefined4*)(iVar1 + 0xc + uVar9 * 0x10) = *(undefined4*)((int)puVar8 + 0xc);
		//pcVar2 = (code*)swi(1);
		//(*pcVar2)();
		//return;

		inst->OP = 1;
		inst->A = uVar7 >> 0x13 & 0xff;
		inst->Bx = (uVar7 >> 1 & 0x3ffff);
	}

	// OP_LOADK 1 : A Bx 
	void d92d1(instr* inst, uint param_1, uint param_2) {



		inst->OP = 1;
		inst->A = 0;
		inst->Bx = 0;
	}

	// OP_LOADK 1 : A Bx 
	void dd2f2(instr* inst, uint param_1, uint param_2) {

		double dVar1;
		int iVar2;
		undefined4 uVar3;
		char cVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		sbyte sVar8;
		uint uVar9;
		uint uVar10;
		double* pdVar11;
		//uint unaff_EBP;
		uint uVar12;
		uint uVar13;

		uVar13 = *(uint*)(unaff_EBP - 0x44);
		uVar12 = (param_1 - *(int*)(unaff_EBP - 100)) + -8 >> 2;
		cVar4 = (char)uVar12;
		*(uint*)(unaff_EBP - 0xc) = uVar12;
		bVar5 = -cVar4 - 0xfU & 0x1e | 1;
		bVar6 = 0xdU - cVar4 & 0x1e | 1;
		bVar7 = (char)(uVar12 << 4) - cVar4 & 0x1eU | 1;
		uVar13 = ((param_2 >> bVar5 | param_2 << 0x20 - bVar5) ^
			(uVar13 << bVar6 | uVar13 >> 0x20 - bVar6) ^ *(uint*)(unaff_EBP - 0x44)) * -3;
		uVar10 = uVar13 >> bVar7 | uVar13 << 0x20 - bVar7;
		uVar10 = (uVar10 << 0x17 | uVar10 >> 9) ^ (uVar10 << 2 | uVar10 >> 0x1e) ^ uVar10;
		uVar13 = uVar10 >> 0x15;
		uVar10 = uVar10 << 0xb;
		uVar9 = uVar13 | uVar10;
		uVar9 = (uVar13 << 0x1c | uVar9 >> 4) ^ (uVar9 << 7 | uVar10 >> 0x19) ^ uVar9;
		bVar5 = cVar4 * '\v' & 0x1eU | 1;
		bVar6 = cVar4 * -7 & 0x1eU | 1;
		uVar10 = (((uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^ (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^
			uVar9) - uVar12) + 0x1efa9189;
		bVar5 = ((byte) * (undefined4*)(unaff_EBP - 0xc) ^ 0xfb) & 0x1e | 1;
		uVar13 = (uVar12 ^ 6) & 0x1e | 1;
		*(uint*)(unaff_EBP - 4) = uVar13;
		sVar8 = (sbyte)uVar13;
		uVar13 = ~((uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^ (uVar10 << sVar8 | uVar10 >> 0x20 - sVar8)
			^ uVar10);
		uVar13 = (uVar13 << 0x14 | uVar13 >> 0xc) ^ (uVar13 << 9 | uVar13 >> 0x17) ^ uVar13 ^ 0x7746e230;
		bVar5 = (byte) * (undefined4*)(unaff_EBP - 0xc);
		bVar6 = bVar5 * '\x04' & 0x1e | 1;
		uVar13 = (uVar13 << sVar8) + uVar13;
		uVar13 = uVar13 >> 0x14 | uVar13 * 0x1000;
		bVar7 = bVar5 & 0x1e | 1;
		uVar13 = (uVar13 << bVar6 | uVar13 >> 0x20 - bVar6) +
			(0x2101d3bd << bVar7 | 0x2101d3bdU >> 0x20 - bVar7);
		bVar5 = 0xc - bVar5 & 0x1e | 1;
		bVar6 = 0xbU - (char)*(undefined4*)(unaff_EBP - 0xc) & 0x1e | 1;
		uVar13 = ((uVar13 << bVar5 | uVar13 >> 0x20 - bVar5) ^ (uVar13 << bVar6 | uVar13 >> 0x20 - bVar6)
			^ uVar13) * -0x1fff;
		*(uint*)(unaff_EBP - 0xc) = uVar13;
		pdVar11 = (double*)((uVar13 >> 0xd & 0x3ffff) * 0x10 + *(int*)(unaff_EBP - 0x6c));
		//uVar13 = *(uint*)(unaff_EBP - 0xc) >> 5 & 0xff;
		//iVar2 = *(int*)(unaff_EBP - 0x5c);
		//dVar1 = *pdVar11;

		inst->OP = 1;
		inst->A = uVar13 >> 5 & 0xff;
		inst->Bx = (uVar13 >> 0xd & 0x3ffff);
	}

	// OP_GETUPVAL 4 : A B 
	void dc7de(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		int iVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		uint uVar6;
		//int unaff_EBP;

		iVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar2;
		bVar3 = (byte)iVar2 & 0x1e | 1;
		bVar4 = ((byte)(7 << bVar3) | (byte)(7 >> 0x20 - bVar3)) & 0x1e | 1;
		uVar5 = *(int*)(unaff_EBP + -0x44) -
			(*(int*)(unaff_EBP + -0x44) <<
				(((byte)(0x1c >> bVar3) | (byte)(0x1c << 0x20 - bVar3)) & 0x1e | 1));
		*(uint*)(unaff_EBP + -0x44) =
			(uVar5 << bVar4 | uVar5 >> 0x20 - bVar4) + (*(uint*)(unaff_EBP + -0xc) ^ 0x41818048);
		uVar5 = ~(*(int*)(unaff_EBP + -0x44) -
			(*(int*)(unaff_EBP + -0x44) <<
				(((byte)(9 << bVar3) | (byte)(9 >> 0x20 - bVar3)) & 0x1e | 1)));
		iVar2 = *(int*)(unaff_EBP + -0x5c);
		uVar6 = uVar5 & 0xff;
		//puVar1 = *(undefined8**)
			//(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar5 >> 0x15 & 0x1ff) * 0x10) + 4);
		//*(undefined8*)(iVar2 + uVar6 * 0x10) = *puVar1;
		//*(undefined4*)(iVar2 + 8 + uVar6 * 0x10) = *(undefined4*)(puVar1 + 1);
		//*(undefined4*)(iVar2 + 0xc + uVar6 * 0x10) = *(undefined4*)((int)puVar1 + 0xc);

		inst->OP = 4;
		inst->A = uVar6;
		inst->B = uVar5 >> 0x15 & 0x1ff;
	}


	// OP_GETUPVAL 4 : A B 
	void de0bf(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		//uint unaff_EBP;
		int iVar5;
		uint uVar6;
		//float10 fVar7;

		iVar5 = (param_1 - *(int*)(unaff_EBP - 100)) + -8 >> 2;
		bVar3 = (byte)iVar5;
		*(int*)(unaff_EBP - 0xc) = iVar5;
		bVar2 = bVar3 & 0x1e | 1;
		param_2 = (param_2 >> 0xb | param_2 << 0x15) ^ (param_2 << 7 | param_2 >> 0x19) ^ param_2;
		bVar2 = ((byte)(0x1b << bVar2) | (byte)(0x1b >> 0x20 - bVar2)) & 0x1e | 1;
		bVar3 = (bVar3 ^ 0xc) & 0x1e | 1;
		bVar4 = ((byte) * (undefined4*)(unaff_EBP - 0xc) ^ 0xf9) & 0x1e | 1;
		uVar6 = ~((param_2 >> bVar3 | param_2 << 0x20 - bVar3) ^
			(param_2 >> bVar4 | param_2 << 0x20 - bVar4) ^ param_2);
		uVar6 = uVar6 >> bVar2 | uVar6 << 0x20 - bVar2;
		iVar5 = *(int*)(unaff_EBP - 0xb0);
		uVar6 = (uVar6 << (((byte) * (undefined4*)(unaff_EBP - 0xc) ^ 0xf7) & 0x1e | 1)) + uVar6;
		*(uint*)(unaff_EBP - 0xc) = uVar6;
		//puVar1 = *(undefined8**)(*(int*)(iVar5 + 0x18 + (uVar6 >> 0x11 & 0x1ff) * 0x10) + 4);
		//uVar6 = *(uint*)(unaff_EBP - 0xc) >> 9 & 0xff;
		//iVar5 = *(int*)(unaff_EBP - 0x5c);

		inst->OP = 4;
		inst->A = uVar6 >> 9 & 0xff;
		inst->B = (uVar6 >> 0x11 & 0x1ff);
	}


	// OP_GETGLOBAL 5 : A Bx 
	void d0985(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		int iVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		//int unaff_EBP;
		uint uVar6;
		uint uVar7;
		int iVar8;
		undefined8* puVar9;

		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar5 = (byte)iVar8;
		bVar4 = bVar5 & 0x1e | 1;
		bVar5 = (bVar5 ^ 0xf3) & 0x1e | 1;
		uVar6 = (0x58015308U >> bVar4 | 0x58015308 << 0x20 - bVar4) + ~(param_2 + iVar8 * -0x54d02a7f);
		uVar6 = (uVar6 * 0x100000 | uVar6 >> 0xc) ^ (uVar6 >> 6 | uVar6 * 0x4000000) ^ uVar6;
		uVar6 = ~(uVar6 * 0x1b8ca000 | uVar6 * 0x7be0dc65 >> 0x13) -
			(0x1cd324fa << bVar4 | 0x1cd324faU >> 0x20 - bVar4) ^ 0x43582e07;
		uVar7 = uVar6 >> 0xf ^ uVar6;
		*(uint*)(unaff_EBP + -0xc) =
			(uVar6 >> 0x11 | uVar7 << 0xf) ^ (uVar7 << 3 | uVar6 >> 0x1d) ^ uVar7;
		uVar6 = *(uint*)(unaff_EBP + -0xc) << bVar5 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar5;
		puVar9 = (undefined8*)((uVar6 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		iVar8 = (uVar6 & 0x3ffff) * 0x10;
		//pcVar1 = *(char**)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//cVar3 = (char)pcVar1;

		inst->OP = 5;
		inst->A = (uVar6 >> 0x12 & 0xff);
		inst->Bx = (uVar6 & 0x3ffff);
	}


	// OP_GETGLOBAL 5 : A Bx 
	void d15f0(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		uint uVar2;
		byte bVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		//int unaff_EBP;

		uVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar2;
		uVar8 = uVar2 & 0x1e | 1;
		bVar3 = (char)uVar2 + 6U & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar8;
		sVar4 = (sbyte)uVar8;
		uVar2 = (0x314b2fe9 << sVar4 | 0x314b2fe9U >> 0x20 - sVar4) + ~*(uint*)(unaff_EBP + -0x44);
		uVar2 = uVar2 << bVar3 | uVar2 >> 0x20 - bVar3;
		bVar5 = ((byte)(0x16 >> sVar4) | (byte)(0x16 << 0x20 - sVar4)) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar3 = ((byte)(4 >> bVar3) | (byte)(4 << 0x20 - bVar3)) & 0x1e | 1;
		uVar2 = (uVar2 >> bVar5 | uVar2 << 0x20 - bVar5) ^ (uVar2 >> bVar3 | uVar2 << 0x20 - bVar3) ^
			uVar2;
		uVar2 = uVar2 >> 0x18 | uVar2 << 8;
		bVar6 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 2) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar7 = -bVar5 - 0xe & 0x1e | 1;
		uVar2 = ~(((uVar2 >> bVar6 | uVar2 << 0x20 - bVar6) ^ (uVar2 >> bVar3 | uVar2 << 0x20 - bVar3) ^
			uVar2) * -0x3ff);
		bVar3 = 0xb - bVar5 & 0x1e | 1;
		uVar2 = ((uVar2 >> bVar7 | uVar2 << 0x20 - bVar7) ^ (uVar2 << bVar3 | uVar2 >> 0x20 - bVar3) ^
			uVar2) * 0x317e6d2b;
		bVar3 = (bVar5 ^ 0xf3) & 0x1e | 1;
		bVar5 = (bVar5 ^ 8) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar2 << bVar3 | uVar2 >> 0x20 - bVar3;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar2 = *(uint*)(unaff_EBP + -0xc) ^ (uVar2 << bVar5 | uVar2 >> 0x20 - bVar5) ^ uVar2;

		inst->OP = 5;
		inst->A = uVar2 & 0xff;
		inst->Bx = (uVar2 >> 8 & 0x3ffff);
	}


	// OP_GETGLOBAL 5 : A Bx 
	void d4275(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		int iVar2;
		char cVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;
		uint uVar10;

		uVar10 = *(uint*)(unaff_EBP + -0x44);
		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar9 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar10 = (uVar8 * 2 + 0x47fff560 +
			((uVar10 << 0x1c | uVar10 >> 4) ^ (uVar10 >> 0x15 | uVar10 << 0xb) ^ uVar10) * -0xff) *
			-0x1f;
		sVar5 = (sbyte)uVar9;
		bVar6 = ((byte)(0x15 << sVar5) | (byte)(0x15 >> 0x20 - sVar5)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar7 = ((byte)(0xb << bVar7) | (byte)(0xb >> 0x20 - bVar7)) & 0x1e | 1;
		uVar10 = (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^
			uVar10;
		iVar2 = *(int*)(unaff_EBP + -0xa8);
		//*(undefined4*)(unaff_EBP + -0x408) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x3fc) = 8;
		//*(undefined4*)(*(int*)(iVar2 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//pcVar4 = (char*)func_0x00535c5b((uVar10 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar10 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c),
		//	uVar1);

		inst->OP = 5;
		inst->A = uVar10 >> 0x12 & 0xff;
		inst->Bx = (uVar10 & 0x3ffff);
	}


	// OP_GETGLOBAL 5 : A Bx 
	void d5001(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		int iVar6;
		//int unaff_EBP;
		uint uVar7;
		int iVar8;
		undefined8* puVar9;
		uint uVar10;

		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar10 = param_2 * 0x5283068d + 0xc59d758d;
		*(uint*)(unaff_EBP + -4) = (uVar7 ^ 0xfffffff9) & 0x1e | 1;
		bVar3 = (byte)((uVar7 * -3 & 7) << 2) | 1;
		bVar4 = (char)uVar7 * '\v' & 0x1eU | 1;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0xc) * '\x05' & 0x1eU | 1;
		uVar10 = (uVar10 << bVar3 | uVar10 >> 0x20 - bVar3) ^ (uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^
			uVar10;
		iVar6 = *(int*)(unaff_EBP + -0xc);
		uVar7 = uVar10 >> bVar4 | uVar10 << 0x20 - bVar4;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		iVar8 = (uVar7 >> bVar3 | uVar7 << 0x20 - bVar3) + 0xfcb0b447;
		cVar2 = (char)iVar6;
		uVar10 = (iVar8 << (cVar2 - 9U & 0x1e | 1)) + iVar8;
		uVar10 = uVar10 * 0x80 ^ uVar10;
		uVar7 = uVar10 << 0x16;
		uVar10 = uVar10 >> 10 | uVar7;
		uVar10 = (uVar7 >> 0x1b | uVar10 << 5) ^ (uVar10 << 1 | (uint)((int)uVar10 < 0)) ^ uVar10;
		uVar10 = uVar10 >> (cVar2 * '\t' & 0x1eU | 1) ^ uVar10;
		bVar3 = cVar2 - 0xcU & 0x1e | 1;
		bVar4 = cVar2 - 10U & 0x1e | 1;
		uVar10 = (uVar10 >> bVar3 | uVar10 << 0x20 - bVar3) ^ (uVar10 >> bVar4 | uVar10 << 0x20 - bVar4) ^
			uVar10;
		*(uint*)(unaff_EBP + -0xc) =
			(uVar10 << 0x14 | uVar10 >> 0xc) ^ (uVar10 >> 0x14 | uVar10 << 0xc) ^ uVar10;
		uVar10 = (*(int*)(unaff_EBP + -0xc) - (*(int*)(unaff_EBP + -0xc) << (cVar2 - 0xbU & 0x1e | 1)) ^
			iVar6 * 0x22d5bb09) + 0xa766848b;
		uVar7 = uVar10 >> 0x12;
		//pcVar1 = *(char**)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//puVar9 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//iVar6 = ((uVar10 * 0x4000 | uVar7) >> 8 & 0x3ffff) * 0x10;

		inst->OP = 5;
		inst->A = uVar7 & 0xff;
		inst->Bx = (uVar10 * 0x4000 | uVar7) >> 8 & 0x3ffff;
	}

	// OP_GETGLOBAL 5 : A Bx 
	void d86c5(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		int iVar2;
		undefined4 uVar3;
		char cVar4;
		uint uVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		int unaff_EBX;
		//uint unaff_EBP;
		int iVar10;
		undefined8* puVar11;
		undefined4 in_XCR0;
		undefined4 in_register_00000604;
		undefined4 uStack00000004;

		uVar5 = (param_1 - *(int*)(unaff_EBP - 100)) + -8 >> 2;
		param_2 = param_2 << 8 ^ param_2;
		*(uint*)(unaff_EBP - 0xc) = uVar5;
		uVar5 = uVar5 & 0x1e | 1;
		sVar6 = (sbyte)uVar5;
		*(uint*)(unaff_EBP - 4) = uVar5;
		bVar7 = ((byte)(0x18 << sVar6) | (byte)(0x18 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP - 4) & 0x1f;
		bVar8 = ((byte)(5 << bVar8) | (byte)(5 >> 0x20 - bVar8)) & 0x1e | 1;
		param_2 = (param_2 << bVar7 | param_2 >> 0x20 - bVar7) ^
			(param_2 >> bVar8 | param_2 << 0x20 - bVar8) ^ param_2;
		bVar7 = (byte) * (undefined4*)(unaff_EBP - 4);
		bVar8 = bVar7 & 0x1f;
		bVar7 = bVar7 & 0x1f;
		bVar8 = ((byte)(6 << bVar8) | (byte)(6 >> 0x20 - bVar8)) & 0x1e | 1;
		uVar5 = (0x14 << bVar7 | 0x14U >> 0x20 - bVar7) & 0x1e | 1;
		*(uint*)(unaff_EBP - 0x1c) = uVar5;
		sVar6 = (sbyte)uVar5;
		uVar5 = ((param_2 << bVar8 | param_2 >> 0x20 - bVar8) ^
			(param_2 >> sVar6 | param_2 << 0x20 - sVar6) ^ param_2) * -0x435b48c7 + 0x68736f56;
		iVar10 = ((uVar5 * 0x2000000 | uVar5 >> 7) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^ uVar5) *
			0x1766a775;
		uVar5 = iVar10 - (iVar10 << (-(char)*(undefined4*)(unaff_EBP - 0xc) - 7U & 0x1e | 1));
		bVar7 = (byte) * (undefined4*)(unaff_EBP - 4);
		bVar9 = ((byte)(0x12 << (bVar7 & 0x1f)) | (byte)(0x12 >> 0x20 - (bVar7 & 0x1f))) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP - 0x1c) & 0x1f;
		uVar5 = (((uVar5 << bVar9 | uVar5 >> 0x20 - bVar9) ^ (uVar5 << bVar8 | uVar5 >> 0x20 - bVar8) ^
			uVar5) * 0x4f787721 - (0x4d7cebf << (bVar7 & 0x1f) | 0x4d7cebfU >> 0x20 - (bVar7 & 0x1f))
			) + 0x2d817f64;
		bVar8 = (byte)((-*(int*)(unaff_EBP - 0xc) & 3U) << 3) | 1;
		uVar5 = (uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^
			(uVar5 << (bVar7 & 0x1f) | uVar5 >> 0x20 - (bVar7 & 0x1f)) ^ uVar5;
		bVar8 = (byte) * (undefined4*)(unaff_EBP - 0xc);
		bVar7 = bVar8 + 0xd & 0x1e | 1;
		bVar9 = bVar8 - 3 & 0x1e | 1;
		uVar5 = (uVar5 << bVar7 | uVar5 >> 0x20 - bVar7) ^ (uVar5 >> bVar9 | uVar5 << 0x20 - bVar9) ^
			uVar5;
		uVar5 = uVar5 >> (bVar8 * '\f' & 0x1e | 1) ^ uVar5;
		uVar5 = uVar5 - (uVar5 << ((bVar8 ^ 0xc) & 0x1e | 1));
		//puVar11 = (undefined8*)((uVar5 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP - 0x5c));
		iVar10 = (uVar5 & 0x3ffff) * 0x10;
		//pcVar1 = *(char**)(*(int*)(unaff_EBP - 0xb0) + 0xc);

		inst->OP = 5;
		inst->A = (uVar5 >> 0x12 & 0xff);
		inst->Bx = (uVar5 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void de270(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		byte bVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		uint uVar6;
		//int unaff_EBP;
		int iVar7;
		undefined8* puVar8;

		bVar2 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		uVar6 = (uint)(param_2 * 0x393c3c81) >> (bVar2 - 0xe & 0x1e | 1) ^ param_2 * 0x393c3c81;
		bVar5 = bVar2 & 0x1e | 1;
		uVar6 = (uVar6 << 0x1d | uVar6 >> 3) ^ (uVar6 >> 0x1c | uVar6 << 4) ^ uVar6;
		bVar5 = ((byte)(9 << bVar5) | (byte)(9 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar6 = (uVar6 << 0xb ^ uVar6) + 0x59de5921;
		uVar6 = uVar6 >> bVar5 | uVar6 << 0x20 - bVar5;
		uVar6 = uVar6 << (bVar2 + 4 & 0x1e | 1) ^ uVar6;
		//puVar8 = (undefined8*)((uVar6 >> 1 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		iVar7 = (uVar6 >> 9 & 0x3ffff) * 0x10;
		//pcVar4 = *(char**)(*(int*)(unaff_EBP + -0xb0) + 0xc);

		inst->OP = 5;
		inst->A = (uVar6 >> 1 & 0xff);
		inst->Bx = (uVar6 >> 9 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void de905(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		int iVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		//int unaff_EBP;
		uint uVar8;
		undefined8* puVar9;

		iVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar3;
		bVar5 = (byte)iVar3 & 0x1e | 1;
		bVar6 = ((byte)(0x1e >> bVar5) | (byte)(0x1e << 0x20 - bVar5)) & 0x1e | 1;
		bVar7 = ((byte)(0x10 >> bVar5) | (byte)(0x10 << 0x20 - bVar5)) & 0x1e | 1;
		uVar8 = (param_2 << bVar6 | param_2 >> 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar7 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar8 = uVar8 << 0x15 ^ uVar8;
		uVar8 = (uVar8 >> 0x1e | uVar8 << 2) ^ (uVar8 >> 0x1c | uVar8 << 4) ^ uVar8;
		uVar8 = ((uVar8 - (uVar8 << (((byte)(0x12 << bVar5) | (byte)(0x12 >> 0x20 - bVar5)) & 0x1e | 1)))
			* 0x80001 ^ *(uint*)(unaff_EBP + -0xc) ^ 0x12a7b01) * 5;
		//puVar9 = (undefined8*)((uVar8 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//iVar3 = (uVar8 & 0x3ffff) * 0x10;
		//pcVar4 = *(char**)(*(int*)(unaff_EBP + -0xb0) + 0xc);

		inst->OP = 5;
		inst->A = (uVar8 >> 0x12 & 0xff);
		inst->Bx = (uVar8 & 0x3ffff);
	}

	// OP_GETTABLE 6 : A B C
	void d0ddc(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		uint iVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;

		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		param_2 = (param_2 >> 0x1d | param_2 << 3) ^ (param_2 << 1 | (uint)((int)param_2 < 0)) ^ param_2;
		*(int*)(unaff_EBP + -0xc) = iVar10;
		bVar7 = (byte)iVar10;
		uVar9 = ~(param_2 << 0x10 ^ param_2) * 0x1331e8d9;
		bVar5 = 0xf - bVar7 & 0x1e | 1;
		bVar6 = bVar7 & 0x1e | 1;
		bVar7 = -bVar7 - 2 & 0x1e | 1;
		uVar9 = (uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) ^ (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^
			uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar7 = ((byte)(10 >> bVar6) | (byte)(10 << 0x20 - bVar6)) & 0x1e | 1;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		bVar5 = ((byte)(3 >> bVar6) | (byte)(3 << 0x20 - bVar6)) & 0x1e | 1;
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		uVar9 = ~(((uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			(*(uint*)(unaff_EBP + -4) >> bVar5 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -4)) * 0x200001);
		uVar9 = (uVar9 >> 0x1b | uVar9 << 5) * 0xbc5bd19;
		uVar8 = ~((uVar9 << (-(char)*(undefined4*)(unaff_EBP + -0xc) - 0xbU & 0x1e | 1) ^ uVar9) *
			0x1821b011 + *(int*)(unaff_EBP + -0xc) * -0x6b216ca7);
		uVar9 = uVar8 >> 4;
		//*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		iVar3 = ((uVar9 & 0x3fe0) >> 5);
		//pcVar4 = (char*)func_0x0053d476(iVar3, ((uVar8 << 0x1c | uVar9) >> 0x17 & 0xff) * 0x10 + iVar10,
			//*(undefined4*)(unaff_EBP + -0xb8));
		//*(undefined4*)(unaff_EBP + -0x5c) = *(undefined4*)(iVar1 + 0x14);
		//cVar2 = (char)pcVar4;


		//std::cout << iVar3 << std::endl;

		inst->OP = 6;
		inst->A = ((uVar8 << 0x1c | uVar9) >> 0x17 & 0xff);
		inst->B = (uVar9 & 0x7fc000) >> 0xe; // TODO
		inst->C = iVar3;
	}

	// OP_GETTABLE 6 : A B C
	void d19b4(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		int iVar3;
		int iVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;

		iVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar3;
		bVar5 = (byte)iVar3 & 0x1e | 1;
		uVar9 = (0x32d79126 << bVar5 | 0x32d79126U >> 0x20 - bVar5) ^ *(uint*)(unaff_EBP + -0x44);
		uVar9 = (uVar9 >> 0xe | uVar9 << 0x12) ^ (uVar9 >> 9 | uVar9 << 0x17) ^ uVar9;
		uVar9 = (0x31eed594U >> bVar5 | 0x31eed594 << 0x20 - bVar5) ^ uVar9 >> 0x12 ^ uVar9;
		uVar9 = ~(uVar9 - (uVar9 << ((char)*(undefined4*)(unaff_EBP + -0xc) + 0xcU & 0x1e | 1)));
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar6 = cVar2 - 9U & 0x1e | 1;
		bVar7 = cVar2 + 4U & 0x1e | 1;
		iVar3 = *(int*)(unaff_EBP + -0xa8);
		uVar9 = (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^ (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			uVar9;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = ((uVar9 >> 0x15 | uVar9 << 0xb) ^ (uVar9 << 7 | uVar9 >> 0x19) ^ uVar9) -
			(0x2eb59b66 << bVar5 | 0x2eb59b66U >> 0x20 - bVar5);
		iVar4 = *(int*)(unaff_EBP + -0xc);
		//*(undefined4*)(*(int*)(iVar3 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		uVar8 = ((uVar9 >> 0x13 ^ uVar9) - iVar4) + 0x348d3301;
		uVar9 = uVar8 >> 8;
		iVar4 = (uVar9 & 0x1ff);
		//__initterm((uVar8 >> 0x11 & 0x1ff) * 0x10 + iVar1, iVar4, (uVar8 & 0xff) * 0x10 + iVar1,
			//*(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar8 & 0xff);
		inst->B = (uVar8 >> 0x11 & 0x1ff);
		inst->C = iVar4;
	}

	// OP_GETTABLE 6 : A B C
	void d2bff(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		uint uVar3;
		int iVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		//int unaff_EBP;

		uVar7 = (param_2 << 6 | param_2 >> 0x1a) ^
			(*(uint*)(unaff_EBP + -0x44) << 2 | *(uint*)(unaff_EBP + -0x44) >> 0x1e) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar3 = uVar7 >> 7;
		uVar7 = uVar3 | uVar7 << 0x19;
		uVar7 = ((uVar7 >> 0xe | uVar3 << 0x12) ^ (uVar7 >> 6 | uVar3 << 0x1a) ^ uVar7) * 0x2ec7cc2f;
		cVar2 = (char)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar5 = 6U - cVar2 & 0x1e | 1;
		bVar6 = 5U - cVar2 & 0x1e | 1;
		uVar7 = (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7;
		uVar3 = uVar7 >> (cVar2 * -5 & 0x1eU | 1);
		*(uint*)(unaff_EBP + -0xc) = uVar3;
		uVar3 = uVar3 ^ uVar7;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		uVar7 = uVar3 >> 8;
		if ((uVar7 & 0x100) == 0) {
			iVar4 = (uVar7 & 0x1ff) * 0x10 + iVar1;
		}
		else {
			iVar4 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//func_0x0046f1b5((uVar3 >> 0x11 & 0x1ff) * 0x10 + iVar1, iVar4, (uVar3 & 0xff) * 0x10 + iVar1,
		//	*(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar3 & 0xff);
		inst->B = (uVar3 >> 0x11 & 0x1ff); // TODO
		inst->C = (uVar7 & 0x1ff);
	}

	// OP_GETTABLE 6 : A B C
	void dd31d(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		char cVar2;
		uint uVar3;
		int iVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;

		*(uint*)(unaff_EBP + -0x44) = param_2 ^ 0x66857fa8;
		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar10;
		cVar2 = (char)iVar10;
		uVar9 = (param_2 ^ 0x66857fa8) << (cVar2 * '\b' & 0x1eU | 1) ^ *(uint*)(unaff_EBP + -0x44);
		uVar9 = (uVar9 >> 0x16 | uVar9 << 10) ^ (uVar9 >> 10 | uVar9 << 0x16) ^ uVar9;
		uVar9 = (uVar9 << (cVar2 + 10U & 0x1e | 1)) + uVar9;
		uVar3 = *(uint*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar9 = (((uVar9 * 0x200000 | uVar9 >> 0xb) + 0xd39f8284) * -3 ^ 0x1b5d53e6) * 0x20000001;
		*(uint*)(unaff_EBP + -4) = uVar3;
		sVar5 = (sbyte)uVar3;
		bVar6 = ((byte)(2 << sVar5) | (byte)(2 >> 0x20 - sVar5)) & 0x1e | 1;
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar7 = cVar2 + 0xbU & 0x1e | 1;
		bVar8 = cVar2 + 9U & 0x1e | 1;
		uVar9 = (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^ (uVar9 >> bVar8 | uVar9 << 0x20 - bVar8) ^
			uVar9;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar3 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) +
			(0x5a8499fU >> bVar7 | 0x5a8499f << 0x20 - bVar7);
		bVar7 = (char)*(int*)(unaff_EBP + -0xc) - 0x10U & 0x1e | 1;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		uVar3 = *(int*)(unaff_EBP + -0xc) + 0x4e9ef2 + (uVar3 >> 7 ^ uVar3);
		uVar3 = (uVar3 >> bVar7 | uVar3 << 0x20 - bVar7) + 0xa840e2ef;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		if ((uVar3 & 0x100) == 0) {
			iVar4 = (uVar3 & 0x1ff) * 0x10 + iVar10;
		}
		else {
			iVar4 = (uVar3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//func_0x005227c7(iVar4, (uVar3 >> 0x12 & 0xff) * 0x10 + iVar10, *(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar3 >> 0x12 & 0xff);
		inst->B = (uVar3 >> 9 & 0x1ff);
		inst->C = (uVar3 & 0x1ff);
	}

	// OP_SETTABLE 9 : A B C
	void d6411(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		int* piVar2;
		byte bVar3;
		int iVar4;
		sbyte sVar5;
		byte bVar6;
		uint uVar7;
		//ushort uVar8;
		//int unaff_EBP;
		uint uVar9;
		//undefined2 in_SS;
		int iStack12;
		int iStack8;
		undefined4 uStack4;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar3 = (byte)uVar9;
		param_2 = param_2 << ((bVar3 ^ 2) & 0x1e | 1) ^ param_2;
		uVar7 = uVar9 & 0x1e | 1;
		sVar5 = (sbyte)uVar7;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		param_2 = param_2 >> (((byte)(8 << sVar5) | (byte)(8 >> 0x20 - sVar5)) & 0x1e | 1) ^ param_2;
		param_2 = param_2 >> (bVar3 + 7 & 0x1e | 1) ^ param_2;
		bVar6 = bVar3 + 10 & 0x1e | 1;
		uVar7 = param_2 * -0x1f;
		uVar7 = (param_2 * 0x40000000 | uVar7 >> 2) ^ (param_2 * -0x1f0 | uVar7 >> 0x1c) ^ uVar7;
		uVar7 = uVar7 >> bVar6 | uVar7 << 0x20 - bVar6;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		iVar4 = (uVar9 - (uVar7 << 0xd | uVar7 >> 0x13)) + 0x5f5054f;
		uVar7 = (iVar4 << (bVar3 + 0xb & 0x1e | 1)) + iVar4;
		uVar7 = (uVar7 >> 0x1b | uVar7 * 0x20) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^ uVar7;
		uVar7 = uVar7 >> 0x10 ^ uVar7;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		iVar4 = (uVar7 << (((byte)(6 >> bVar3) | (byte)(6 << 0x20 - bVar3)) & 0x1e | 1)) + uVar7;
		uVar9 = (iVar4 * -0x54000000 | (uint)(iVar4 * 0x61afdc2b) >> 6) * 0x4001;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		uVar7 = uVar9 >> 6;
		uint orig1 = (uVar7 & 0x1ff);
		if ((uVar7 & 0x100) == 0) {
			iStack8 = iVar1 + (uVar7 & 0x1ff) * 0x10;
		}
		else {
			iStack8 = *(int*)(unaff_EBP + -0x6c) + (uVar7 & 0xff) * 0x10;
		}
		uVar7 = uVar9 >> 0xf;
		if ((uVar7 & 0x100) == 0) {
			iStack12 = iVar1 + (uVar7 & 0x1ff) * 0x10;
		}
		else {
			iStack12 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uStack4 = *(undefined4*)(unaff_EBP + -0xb8);
		//uVar8 = (short)&iStack12 - 4;
		//piVar2 = (int*)segment(in_SS, uVar8);
		//*piVar2 = (uVar9 >> 0x18) * 0x10 + iVar1;

		inst->OP = 9;
		inst->A = (uVar9 >> 0x18);
		inst->C = orig1;
		inst->B = (uVar7 & 0x1ff);
	}

	// OP_SETTABLE 9 : A B C
	void d71e4(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		int* piVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		//ushort uVar9;
		//int unaff_EBP;
		int iVar10;
		//undefined2 in_SS;
		int iStack12;
		int iStack8;
		undefined4 uStack4;

		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar10;
		bVar6 = (byte)iVar10;
		uVar7 = param_2 * 0x4000 ^ param_2 * 0x1000001;
		bVar4 = (bVar6 ^ 0xf5) & 0x1e | 1;
		bVar5 = bVar6 & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xfb) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) =
			(uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^ uVar7;
		bVar6 = ((byte)(0x17 << bVar5) | (byte)(0x17 >> 0x20 - bVar5)) & 0x1e | 1;
		bVar4 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 4U & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -4) >> bVar6 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar6;
		bVar6 = ((byte)(6 << bVar5) | (byte)(6 >> 0x20 - bVar5)) & 0x1e | 1;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		uVar7 = *(uint*)(unaff_EBP + -0xc) ^
			(*(uint*)(unaff_EBP + -4) >> bVar6 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -4);
		uVar8 = ~(uVar7 >> bVar4 | uVar7 << 0x20 - bVar4);
		uVar8 = (uVar8 << 0x1e | uVar8 >> 2) ^ (uVar8 >> 0xd | uVar8 << 0x13) ^ uVar8;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		uVar7 = uVar8 >> 0x17;
		uint first = uVar7;
		if ((uVar7 & 0x100) == 0) {
			iStack8 = iVar10 + uVar7 * 0x10;
		}
		else {
			iStack8 = *(int*)(unaff_EBP + -0x6c) + (uVar7 & 0xff) * 0x10;
		}
		uVar7 = uVar8 >> 6;
		if ((uVar7 & 0x100) == 0) {
			iStack12 = iVar10 + (uVar7 & 0x1ff) * 0x10;
		}
		else {
			iStack12 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uStack4 = *(undefined4*)(unaff_EBP + -0xb8);
		//uVar9 = (short)&iStack12 - 4;
		//piVar2 = (int*)segment(in_SS, uVar9);
		//*piVar2 = (uVar8 >> 0xf & 0xff) * 0x10 + iVar10;

		inst->OP = 9;
		inst->A = (uVar8 >> 0xf & 0xff);
		inst->B = (uVar7 & 0x1ff);
		inst->C = first;
	}

	// OP_SETTABLE 9 : A B C
	void d958f(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char* pcVar2;
		int* piVar3;
		char cVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		//ushort uVar9;
		//int unaff_EBP;
		uint uVar10;
		int iVar11;
		//undefined2 in_SS;
		int iStack12;
		int iStack8;
		undefined4 uStack4;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar7 = (byte)iVar11;
		bVar5 = bVar7 - 6 & 0x1e | 1;
		bVar6 = (bVar7 ^ 0xf3) & 0x1e | 1;
		uVar10 = (iVar11 + param_2) * 0x6196626d + 0xa934ff05;
		*(uint*)(unaff_EBP + -0xc) = uVar10 << bVar5 | uVar10 >> 0x20 - bVar5;
		bVar7 = bVar7 - 5 & 0x1e | 1;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -0xc) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^ uVar10;
		uVar8 = (*(uint*)(unaff_EBP + -0xc) << bVar6 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar6) +
			(-0x22b98484 - iVar11);
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		uVar10 = uVar8 >> 8;
		uint first = (uVar10 & 0x1ff);
		if ((uVar10 & 0x100) == 0) {
			iStack8 = iVar1 + (uVar10 & 0x1ff) * 0x10;
		}
		else {
			iStack8 = *(int*)(unaff_EBP + -0x6c) + (uVar10 & 0xff) * 0x10;
		}
		uVar10 = uVar8 >> 0x11;
		if ((uVar10 & 0x100) == 0) {
			iStack12 = iVar1 + (uVar10 & 0x1ff) * 0x10;
		}
		else {
			iStack12 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uStack4 = *(undefined4*)(unaff_EBP + -0xb8);
		//uVar9 = (short)&iStack12 - 4;
		//piVar3 = (int*)segment(in_SS, uVar9);
		//*piVar3 = (uVar8 & 0xff) * 0x10 + iVar1;

		inst->OP = 9;
		inst->A = (uVar8 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = first;
	}


	// OP_SETTABLE 9 : A B C
	void da966(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		int* piVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		uint uVar9;
		//ushort uVar10;
		//int unaff_EBP;
		int iVar11;
		//undefined2 in_SS;
		int iStack12;
		int iStack8;
		undefined4 uStack4;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar11;
		bVar6 = (byte)iVar11;
		bVar4 = (bVar6 ^ 0xe) & 0x1e | 1;
		bVar5 = bVar6 & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xf9) & 0x1e | 1;
		uVar7 = (param_2 << bVar4 | param_2 >> 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar6 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = (uVar7 >> 0x19 | uVar7 << 7) ^ (uVar7 >> 1 | (uint)((uVar7 & 1) != 0) << 0x1f) ^ uVar7;
		uVar7 = (uVar7 >> 0x16 | uVar7 << 10) ^ (uVar7 >> 0x13 | uVar7 << 0xd) ^ uVar7;
		bVar6 = (byte)((*(int*)(unaff_EBP + -0xc) * -3 & 7U) << 2) | 1;
		uVar7 = (((uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7) - *(int*)(unaff_EBP + -0xc)) + 0x9b40ac9;
		uVar7 = ~(uVar7 * 0x1000 ^ uVar7);
		bVar6 = (byte) * (uint*)(unaff_EBP + -0xc);
		uVar7 = uVar7 - (uVar7 << (((byte)(0x10 << bVar5) | (byte)(0x10 >> 0x20 - bVar5)) & 0x1e | 1));
		iVar11 = (uVar7 << ((bVar6 ^ 2) & 0x1e | 1) ^ uVar7) * 0x4b364585;
		uVar7 = (iVar11 << ((bVar6 ^ 10) & 0x1e | 1)) + iVar11;
		uVar7 = (uVar7 >> 0x1a | uVar7 * 0x40) ^ (uVar7 * 0x800000 | uVar7 >> 9) ^ uVar7;
		uVar7 = (uVar7 >> 0x1d | uVar7 << 3) ^ (uVar7 << 0x14 | uVar7 >> 0xc) ^ uVar7;
		uVar8 = (uVar7 >> 5 | uVar7 << 0x1b) - (*(uint*)(unaff_EBP + -0xc) ^ 0x2db8d3ba);
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		uVar7 = uVar8 >> 4;
		uVar8 = uVar8 * 0x10000000;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		if ((uVar7 & 0x100) == 0) {
			iStack8 = (uVar7 & 0x1ff) * 0x10 + iVar11;
		}
		else {
			iStack8 = *(int*)(unaff_EBP + -0x6c) + (uVar7 & 0xff) * 0x10;
		}
		uVar9 = (uVar7 | uVar8) >> 0x15;
		if ((uVar8 & 0x20000000) == 0) {
			iStack12 = iVar11 + (uVar9 & 0x1ff) * 0x10;
		}
		else {
			iStack12 = (uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uStack4 = *(undefined4*)(unaff_EBP + -0xb8);
		//uVar10 = (short)&iStack12 - 4;
		//piVar2 = (int*)segment(in_SS, uVar10);
		//*piVar2 = ((uVar7 & 0x1fe000) >> 0xd) * 0x10 + iVar11;

		inst->OP = 9;
		inst->A = (uVar7 & 0x1fe000) >> 0xd;
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar7 & 0x1ff);
	}


	// OP_NEWTABLE 10 : A B C
	void d11f5(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		int iVar2;
		undefined4 uVar3;
		undefined4 uVar4;
		int iVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;

		bVar8 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar6 = bVar8 - 10 & 0x1e | 1;
		bVar7 = bVar8 + 1 & 0x1e | 1;
		bVar8 = bVar8 & 0x1e | 1;
		uVar9 = (param_2 >> bVar6 | param_2 << 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44) ^ 0x7bc6ef1a;
		uVar9 = uVar9 << (((byte)(0x1d << bVar8) | (byte)(0x1d >> 0x20 - bVar8)) & 0x1e | 1) ^ uVar9;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		*(int*)(unaff_EBP + -0xc) = *(int*)(unaff_EBP + -0xc) + uVar9 * -0x8000000;
		*(int*)(unaff_EBP + -0xc) =
			(*(int*)(unaff_EBP + -0xc) -
				(*(int*)(unaff_EBP + -0xc) <<
					(((byte)(0xb >> bVar8) | (byte)(0xb << 0x20 - bVar8)) & 0x1e | 1))) + -0x63aa15b7;

		uVar9 = *(uint*)(unaff_EBP + -0xc);

		inst->OP = 10;
		inst->A = uVar9 & 0xff;
		inst->B = uVar9 >> 0x11 & 0x1ff;
		inst->C = uVar9 >> 0x8 & 0x1ff; // TODO
	}

	// OP_NEWTABLE 10 : A B C
	void d6a43(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		byte bVar2;
		int iVar3;
		byte bVar4;
		uint uVar5;
		uint uVar6;
		//int unaff_EBP;
		int iVar7;
		uint uVar8;
		uint uVar9;
		int* piVar10;

		bVar2 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar4 = bVar2 & 0x1e | 1;
		iVar7 = ((param_2 << 0x1e | param_2 >> 2) ^
			(*(uint*)(unaff_EBP + -0x44) >> 6 | *(uint*)(unaff_EBP + -0x44) << 0x1a) ^
			*(uint*)(unaff_EBP + -0x44)) * 0x75c81e01 -
			(0x24073c73 << bVar4 | 0x24073c73U >> 0x20 - bVar4);
		uVar6 = (iVar7 << (((byte)(0x1d << bVar4) | (byte)(0x1d >> 0x20 - bVar4)) & 0x1e | 1)) + iVar7;
		uVar6 = uVar6 >> ((bVar2 ^ 10) & 0x1e | 1) ^ uVar6;
		uVar5 = uVar6 << 10;
		uVar8 = uVar5 >> 0x16;
		uVar9 = uVar8 & 0x1ff;
		uint ror = (uVar6 >> 0x16 | uVar5);
		piVar10 = (int*)((ror >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//uVar5 = uVar9 >> 3 & 0x1f;

		//std::cout << uVar6 << std::endl;

		inst->OP = 10;
		inst->A = ((uVar6 >> 0x16 | uVar5) >> 9 & 0xff);
		inst->B = ror & 0x1ff; // TODO
		inst->C = uVar9;
	}


	// OP_SUB 13 : A B C
	void da360(instr* inst, uint param_1, uint param_2) {

		undefined8 uVar1;
		char* pcVar2;
		uint* puVar3;
		int iVar4;
		char cVar5;
		byte bVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		byte bVar10;
		uint uVar11;
		uint uVar12;
		char* pcVar13;
		uint uVar14;
		undefined8* puVar15;
		//int unaff_EBP;

		uVar11 = *(uint*)(unaff_EBP + -0x44);
		uVar14 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar11 = (uVar11 >> 0x18 | uVar11 << 8) ^ (uVar11 >> 10 | uVar11 << 0x16) ^ uVar11;
		*(uint*)(unaff_EBP + -0xc) = uVar14;
		uVar12 = uVar11 * 0x10001;
		bVar6 = (char)uVar14 * -9 & 0x1eU | 1;
		uVar12 = (uVar12 >> 0x1b | uVar11 * 0x200020) ^ (uVar11 * 0x4000000 | uVar12 >> 6) ^ uVar12;
		uVar11 = uVar14 & 0x1e | 1;
		sVar7 = (sbyte)uVar11;
		*(uint*)(unaff_EBP + -4) = uVar11;
		bVar8 = ((byte)(0xe >> sVar7) | (byte)(0xe << 0x20 - sVar7)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar12 >> bVar8 | uVar12 << 0x20 - bVar8;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(5 >> bVar8) | (byte)(5 << 0x20 - bVar8)) & 0x1e | 1;
		uVar11 = (*(uint*)(unaff_EBP + -0x1c) ^ (uVar12 >> bVar8 | uVar12 << 0x20 - bVar8) ^ uVar12) +
			0xf0da7d74;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = (byte) * (int*)(unaff_EBP + -0xc);
		*(uint*)(unaff_EBP + -0x1c) =
			(uVar11 << bVar6 | uVar11 >> 0x20 - bVar6) + *(int*)(unaff_EBP + -0xc) * -0x83660d9;
		bVar6 = bVar9 + 0xf & 0x1e | 1;
		uVar11 = *(uint*)(unaff_EBP + -0x1c);
		bVar9 = (bVar9 ^ 0xf9) & 0x1e | 1;
		bVar8 = ((byte)(0xd << bVar8) | (byte)(0xd >> 0x20 - bVar8)) & 0x1e | 1;
		bVar10 = (char)*(undefined4*)(unaff_EBP + -0xc) + 5U & 0x1e | 1;
		uVar11 = (uVar11 >> bVar6 | uVar11 << 0x20 - bVar6) ^ (uVar11 >> bVar10 | uVar11 << 0x20 - bVar10)
			^ *(uint*)(unaff_EBP + -0x1c);
		uVar11 = uVar11 >> bVar9 | uVar11 << 0x20 - bVar9;
		uVar11 = uVar11 >> 0x19 | uVar11 << 7;
		uVar11 = uVar11 << bVar8 | uVar11 >> 0x20 - bVar8;
		uVar11 = (uVar11 >> 0x1d | uVar11 << 3) ^ (uVar11 << 6 | uVar11 >> 0x1a) ^ uVar11;
		uVar11 = ((uVar11 >> 0x14 | uVar11 << 0xc) ^ (uVar11 >> 0xb | uVar11 << 0x15) ^ uVar11) *
			0x7ca44677;
		uVar11 = uVar11 >> 0xe ^ uVar11 >> 0x14 ^ uVar11;
		cVar5 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar8 = -cVar5 - 0x10U & 0x1e | 1;
		uVar12 = uVar11 << bVar8 | uVar11 >> 0x20 - bVar8;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		bVar8 = -cVar5 - 2U & 0x1e | 1;
		uVar11 = uVar12 ^ (uVar11 << bVar8 | uVar11 >> 0x20 - bVar8) ^ uVar11;
		pcVar2 = *(char**)(unaff_EBP + -0x5c);
		uVar12 = uVar11 >> 9;
		*(char**)(unaff_EBP + -4) = pcVar2 + (uVar11 >> 0x12 & 0xff) * 0x10;
		if ((uVar12 & 0x100) == 0) {
			puVar15 = (undefined8*)(pcVar2 + (uVar12 & 0x1ff) * 0x10);
		}
		else {
			puVar15 = (undefined8*)((uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		if ((uVar11 & 0x100) == 0) {
			pcVar13 = pcVar2 + (uVar11 & 0x1ff) * 0x10;
		}
		else {
			pcVar13 = (char*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 13;
		inst->A = (uVar11 >> 0x12 & 0xff);
		inst->B = (uVar12 & 0x1ff);
		inst->C = (uVar11 & 0x1ff);
	}


	// OP_MUL 14 : A B C
	void d176f(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		undefined8* puVar6;
		uint uVar7;
		int iVar8;
		//int unaff_EBP;
		double* pdVar9;
		undefined8 uVar10;
		double dVar11;

		uVar5 = ((param_2 << 0x17 | param_2 >> 9) ^ (param_2 >> 1 | (uint)((param_2 & 1) != 0) << 0x1f) ^
			param_2) + 0x1eb95bf6;
		bVar4 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar2 = 0xb - bVar4 & 0x1e | 1;
		uVar5 = uVar5 * 0x8000 ^ uVar5;
		bVar3 = (bVar4 ^ 0xfb) & 0x1e | 1;
		bVar4 = ~bVar4 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar5 << bVar3 | uVar5 >> 0x20 - bVar3;
		iVar8 = *(int*)(unaff_EBP + -0x5c);
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -0xc) ^ (uVar5 >> bVar4 | uVar5 << 0x20 - bVar4) ^ uVar5 ^ 0x3581f437;
		uVar7 = ((*(uint*)(unaff_EBP + -0xc) << bVar2 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar2) ^
			0x67005ff8) + 0x3653060d;
		uVar5 = uVar7 >> 0x14;
		pdVar9 = (double*)((uVar7 >> 0xc & 0xff) * 0x10 + iVar8);
		uint A = uVar7;
		if ((uVar5 & 0x100) == 0) {
			puVar6 = (undefined8*)((uVar5 & 0x1ff) * 0x10 + iVar8);
		}
		else {
			puVar6 = (undefined8*)((uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uVar7 = uVar7 >> 3;
		if ((uVar7 & 0x100) == 0) {
			iVar8 = (uVar7 & 0x1ff) * 0x10 + iVar8;
		}
		else {
			iVar8 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 14;
		inst->A = (A >> 0xc & 0xff);
		inst->B = (uVar5 & 0x1ff);
		inst->C = (uVar7 & 0x1ff);
	}


	// OP_MUL 14 : A B C
	void d5235(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint uVar2;
		int iVar3;
		uint* puVar4;
		char cVar5;
		char* pcVar6;
		uint uVar7;
		char* pcVar8;
		//int unaff_EBP;
		undefined8* puVar9;
		uint* puVar10;

		uVar7 = ~param_2 << 0xf | ~param_2 >> 0x11;
		uVar7 = (uVar7 << (sbyte)((((param_1 - *(int*)(unaff_EBP + -100)) - 8U ^ 8) & 0x78 | 4) >> 2)) +
			uVar7;
		uVar7 = (uVar7 * 0x1000 | uVar7 >> 0x14) * 0x59463b91 + 0x70a43fc5;
		uVar7 = uVar7 * 8 | uVar7 >> 0x1d;
		uVar7 = uVar7 << 7 ^ uVar7;
		pcVar6 = *(char**)(unaff_EBP + -0x5c);
		puVar10 = (uint*)(pcVar6 + (uVar7 >> 0x12 & 0xff) * 0x10);
		uint A = uVar7;
		if ((uVar7 & 0x100) == 0) {
			puVar9 = (undefined8*)(pcVar6 + (uVar7 & 0x1ff) * 0x10);
		}
		else {
			puVar9 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uVar7 = uVar7 >> 9;
		if ((uVar7 & 0x100) == 0) {
			pcVar8 = pcVar6 + (uVar7 & 0x1ff) * 0x10;
		}
		else {
			pcVar8 = (char*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 14;
		inst->A = (A >> 0x12 & 0xff);
		inst->B = (A & 0x1ff);
		inst->C = (uVar7 & 0x1ff);
	}


	// OP_MUL 14 : A B C
	void de7b8(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint uVar2;
		uint* puVar3;
		char cVar4;
		uint uVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		char* pcVar10;
		uint uVar11;
		undefined8* puVar12;
		//int unaff_EBP;
		uint* puVar13;

		uVar5 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar5;
		uVar5 = uVar5 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar5;
		sVar7 = (sbyte)uVar5;
		uVar5 = param_2 << (((byte)(5 >> sVar7) | (byte)(5 << 0x20 - sVar7)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar5 = (uVar5 << 0x1b | uVar5 >> 5) ^ (uVar5 << 0x13 | uVar5 >> 0xd) ^ uVar5;
		bVar8 = ((byte)(0x15 << sVar7) | (byte)(0x15 >> 0x20 - sVar7)) & 0x1e | 1;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(5 << bVar9) | (byte)(5 >> 0x20 - bVar9)) & 0x1e | 1;
		uVar5 = (uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^ (uVar5 << bVar9 | uVar5 >> 0x20 - bVar9) ^
			uVar5;
		iVar1 = *(int*)(unaff_EBP + -0xc);
		uVar5 = (uVar5 >> 0x12 ^ iVar1 * 0x4e454dc ^ uVar5) + iVar1 * 0x6af8c2ce;
		uVar5 = ~((uVar5 * 0x8000 | uVar5 >> 0x11) ^ (uVar5 >> 7 | uVar5 * 0x2000000) ^ uVar5);
		bVar9 = 0xdU - (char)iVar1 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar5 << bVar9 | uVar5 >> 0x20 - bVar9;
		bVar9 = 7U - (char)iVar1 & 0x1e | 1;
		uVar5 = *(uint*)(unaff_EBP + -0xc) ^ (uVar5 << bVar9 | uVar5 >> 0x20 - bVar9) ^ uVar5;
		pcVar6 = *(char**)(unaff_EBP + -0x5c);
		puVar13 = (uint*)(pcVar6 + (uVar5 >> 10 & 0xff) * 0x10);
		uint A = uVar5;
		uVar11 = uVar5 >> 1;
		if ((uVar11 & 0x100) == 0) {
			puVar12 = (undefined8*)(pcVar6 + (uVar11 & 0x1ff) * 0x10);
		}
		else {
			puVar12 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uVar5 = uVar5 >> 0x12;
		if ((uVar5 & 0x100) == 0) {
			pcVar10 = pcVar6 + (uVar5 & 0x1ff) * 0x10;
		}
		else {
			pcVar10 = (char*)((uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 14;
		inst->A = (A >> 10 & 0xff);
		inst->B = (uVar11 & 0x1ff);
		inst->C = (uVar5 & 0x1ff);
	}

	// OP_LEN 20 : A B 
	void df59f(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		undefined4 uVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		int iVar6;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar4 = (byte)iVar6;
		*(int*)(unaff_EBP + -0xc) = iVar6;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar5 = param_2 + iVar6 * -0x48aec89;
		uVar5 = ~(uVar5 * 0x400000 ^ uVar5);
		uVar5 = uVar5 >> (-bVar4 - 0xb & 0x1e | 1) ^ uVar5;
		uVar5 = (uVar5 << 0x18 | uVar5 >> 8) ^ (uVar5 >> 7 | uVar5 << 0x19) ^ uVar5;
		bVar3 = bVar4 & 0x1e | 1;
		uVar5 = uVar5 - (uVar5 << ((bVar4 ^ 0xe) & 0x1e | 1));
		*(uint*)(unaff_EBP + -4) = uVar5;
		bVar4 = ((byte)(0x1d << bVar3) | (byte)(0x1d >> 0x20 - bVar3)) & 0x1e | 1;
		bVar3 = ((byte)(0x13 << bVar3) | (byte)(0x13 >> 0x20 - bVar3)) & 0x1e | 1;
		uVar2 = *(undefined4*)(unaff_EBP + -0xc);
		uVar5 = (uVar5 << bVar4 | uVar5 >> 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -4) << bVar3 | *(uint*)(unaff_EBP + -4) >> 0x20 - bVar3) ^
			*(uint*)(unaff_EBP + -4);
		uVar5 = (uVar5 >> 0xe | uVar5 << 0x12) ^ (uVar5 >> 10 | uVar5 << 0x16) ^ uVar5;
		iVar6 = *(int*)(unaff_EBP + -0xa8);
		//*(undefined4*)(*(int*)(iVar6 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//func_0x0052090c(((uVar5 << (((byte)uVar2 ^ 2) & 0x1e | 1) ^ uVar5) * 0x7870c1d7 >> 0x11 & 0x1ff) *
			//0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 20;
		inst->A = ((uVar5 << (((byte)uVar2 ^ 2) & 0x1e | 1) ^ uVar5) * 0x7870c1d7 >> 9 & 0xff);
		inst->B = ((uVar5 << (((byte)uVar2 ^ 2) & 0x1e | 1) ^ uVar5) * 0x7870c1d7 >> 0x11 & 0x1ff);
	}

	// OP_CONCAT 21 : A B C
	void d8bad(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4 uVar2;
		char* pcVar3;
		char cVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		//int unaff_EBP;
		uint uVar9;
		uint uVar10;

		uVar8 = param_2 * 0xcf61773;
		uVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		uVar9 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar9;
		sVar5 = (sbyte)uVar9;
		uVar8 = ((uVar8 >> 0xe | param_2 * 0x5dcc0000) ^ (param_2 * 0x19ec2ee6 | (uint)((int)uVar8 < 0)) ^
			uVar8) + (0x69e3505cU >> sVar5 | 0x69e3505c << 0x20 - sVar5);
		uVar8 = (uVar8 * 0x20 | uVar8 >> 0x1b) ^ (uVar8 >> 2 | uVar8 * 0x40000000) ^ uVar8;
		bVar6 = 6U - (char)uVar10 & 0x1e | 1;
		uVar8 = uVar8 * 0x2000080 ^ uVar8 * 0x40001;
		uVar8 = uVar8 >> bVar6 | uVar8 << 0x20 - bVar6;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = bVar7 & 0x1f;
		bVar7 = bVar7 & 0x1f;
		bVar7 = ((byte)(0x1c << bVar7) | (byte)(0x1c >> 0x20 - bVar7)) & 0x1e | 1;
		uVar8 = uVar8 >> (((byte)(0x10 << bVar6) | (byte)(0x10 >> 0x20 - bVar6)) & 0x1e | 1) ^ uVar8 ^
			*(uint*)(unaff_EBP + -0xc) ^ 0x2edf2efb;
		uVar8 = uVar8 << bVar7 | uVar8 >> 0x20 - bVar7;
		uVar8 = uVar8 << 0xc ^ uVar8;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		cVar4 = (char)*(uint*)(unaff_EBP + -0xc);
		uVar8 = (uVar8 - (uVar8 << (((byte)(0x12 >> bVar6) | (byte)(0x12 << 0x20 - bVar6)) & 0x1e | 1))) *
			0x101;
		bVar6 = -cVar4 - 0xdU & 0x1e | 1;
		bVar7 = 2U - cVar4 & 0x1e | 1;
		uVar8 = (uVar8 << bVar6 | uVar8 >> 0x20 - bVar6) ^ (uVar8 >> bVar7 | uVar8 << 0x20 - bVar7) ^
			uVar8;
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		uVar2 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar8 = uVar8 >> (cVar4 * '\x03' & 0x1eU | 1) ^ uVar8 ^ 0x5f7d093d;
		uint buVar8 = uVar8;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar9 = uVar8 & 0x1ff;
		//*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//func_0x0052bdc3(uVar8 >> 9 & 0x1ff, uVar2);
		//func_0x0044d8b3();
		//iVar1 = *(int*)(iVar1 + 0x14);
		uVar8 = *(uint*)(unaff_EBP + -0xc) >> 0x12 & 0xff;

		inst->OP = 21;
		inst->A = uVar8;
		inst->B = uVar9;
		inst->C = buVar8 >> 9 & 0x1ff;
	}

	// OP_JMP 22 : sBx  
	void d0134(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		sbyte sVar4;
		byte bVar5;
		int iVar6;
		uint* puVar7;
		uint* puVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x50) = iVar6;
		bVar3 = (char)iVar6 + 5U & 0x1e | 1;
		uVar9 = (param_2 >> 9 | param_2 << 0x17) ^ *(int*)(unaff_EBP + -0x50) * 0x734bf7fb;
		uVar10 = uVar9 << bVar3 | uVar9 >> 0x20 - bVar3;
		uVar9 = *(uint*)(unaff_EBP + -0x50) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x44) = uVar9;
		uVar10 = (uVar10 << 0x12 | uVar10 >> 0xe) ^ (uVar10 >> 0x11 | uVar10 << 0xf) ^ uVar10;
		sVar4 = (sbyte)uVar9;
		bVar5 = ((byte)(0x16 << sVar4) | (byte)(0x16 >> 0x20 - sVar4)) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0x44) & 0x1f;
		bVar3 = ((byte)(7 << bVar3) | (byte)(7 >> 0x20 - bVar3)) & 0x1e | 1;
		uVar10 = (uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^ (uVar10 << bVar3 | uVar10 >> 0x20 - bVar3) ^
			uVar10;
		uVar10 = uVar10 >> (((byte) * (undefined4*)(unaff_EBP + -0x50) ^ 2) & 0x1e | 1) ^ uVar10;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0x44) & 0x1f;
		uVar10 = uVar10 - (uVar10 << (((byte)(0x19 >> bVar3) | (byte)(0x19 << 0x20 - bVar3)) & 0x1e | 1));
		uVar10 = uVar10 * 0x80000 ^ uVar10;
		cVar1 = (char)*(undefined4*)(unaff_EBP + -0x50);
		bVar3 = cVar1 + 0xfU & 0x1e | 1;
		bVar5 = cVar1 - 0xeU & 0x1e | 1;
		uVar10 = (uVar10 >> bVar3 | uVar10 << 0x20 - bVar3) ^ (uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^
			uVar10;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0x44) & 0x1f;
		uVar10 = uVar10 >> (((byte)(6 >> bVar3) | (byte)(6 << 0x20 - bVar3)) & 0x1e | 1) ^ uVar10;
		cVar1 = (char)*(undefined4*)(unaff_EBP + -0x50);
		uVar10 = uVar10 << (-cVar1 - 6U & 0x1e | 1) ^ uVar10;
		uVar10 = (uVar10 << 0xb | uVar10 >> 0x15) ^ (uVar10 >> 8 | uVar10 << 0x18) ^ uVar10;
		//puVar7 = (uint*)(*(int*)(unaff_EBP + -0x24) +
		//	((uVar10 << (cVar1 * '\b' & 0x1eU | 1) ^ uVar10) & 0x3ffffff) * 8 + -0xffffff4);

		int theJmp = ((uVar10 << (cVar1 * '\b' & 0x1eU | 1) ^ uVar10) & 0x3ffffff) * 8 + -0xffffff4;

		inst->OP = 22;
		inst->sBx = sBxConversion(theJmp);
	}

	// OP_JMP 22 : sBx  
	void dcd4f(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		int iVar6;
		uint* puVar7;
		uint* puVar8;
		//int unaff_EBP;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x50) = iVar6;
		bVar4 = (char)iVar6 - 0x10U & 0x1e | 1;
		param_2 = (param_2 >> 0x17 | param_2 << 9) ^ (param_2 << 5 | param_2 >> 0x1b) ^ param_2;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0x50) - 0xfU & 0x1e | 1;
		param_2 = (param_2 << bVar4 | param_2 >> 0x20 - bVar4) ^
			(param_2 << bVar5 | param_2 >> 0x20 - bVar5) ^ param_2;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -0x50) & 0x1e | 1;
		iVar6 = (param_2 >> 0xc | param_2 << 0x14) * 0x3949eb69;
		bVar5 = ((byte)(0x14 << bVar4) | (byte)(0x14 >> 0x20 - bVar4)) & 0x1e | 1;
		bVar4 = ((byte)(0x15 >> bVar4) | (byte)(0x15 << 0x20 - bVar4)) & 0x1e | 1;
		uVar2 = (iVar6 << ((char)*(undefined4*)(unaff_EBP + -0x50) * -8 & 0x1eU | 1)) + iVar6;
		uVar2 = (uVar2 << bVar5 | uVar2 >> 0x20 - bVar5) + 0xda593f00;
		uVar2 = (uVar2 << bVar4 | uVar2 >> 0x20 - bVar4) * 0x85f9b51;
		//puVar7 = (uint*)(((uVar2 >> 4 ^ uVar2 >> 5 ^ uVar2) & 0x3ffffff) * 8 + -0xffffff4 +
		//	*(int*)(unaff_EBP + -0x24));

		inst->OP = 22;
		inst->sBx = sBxConversion(((uVar2 >> 4 ^ uVar2 >> 5 ^ uVar2) & 0x3ffffff) * 8 + -0xffffff4);
	}

	// OP_JMP 22 : sBx  
	void ddb27(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		sbyte sVar3;
		byte bVar4;
		uint* puVar5;
		uint* puVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;

		param_2 = param_2 << 9 ^ param_2;
		uVar7 = param_2 << 0x14 ^ param_2;
		sVar3 = (sbyte)(((param_1 - *(int*)(unaff_EBP + -100)) - 8U & 0x78 | 4) >> 2);
		uVar8 = uVar7 * 0x11;
		bVar4 = ((byte)(0xd >> sVar3) | (byte)(0xd << 0x20 - sVar3)) & 0x1e | 1;
		uVar8 = (uVar8 >> 0x15 | uVar7 * 0x8800) ^ (param_2 * 0x110000 | uVar8 >> 0x10) ^ uVar8;
		uVar8 = uVar8 >> 0x19 | uVar8 << 7;
		//puVar5 = (uint*)(*(int*)(unaff_EBP + -0x24) + -0xffffff4 +
		//	((uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) >> 1 & 0x3ffffff) * 8);

		inst->OP = 22;
		inst->sBx = sBxConversion(-0xffffff4 +
			((uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) >> 1 & 0x3ffffff) * 8);
	}

	// OP_JMP 22 : sBx  
	void df553(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		sbyte sVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint* puVar8;
		uint* puVar9;
		//int unaff_EBP;
		int iVar10;

		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0x50) = uVar7;
		uVar7 = uVar7 & 0x1e | 1;
		sVar3 = (sbyte)uVar7;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar7 = param_2 * 0x11 -
			(param_2 * 0x11 << (((byte)(0xf << sVar3) | (byte)(0xf >> 0x20 - sVar3)) & 0x1e | 1));
		uVar7 = (uVar7 * 0x100000 ^ uVar7) + *(int*)(unaff_EBP + -0x50) * 0x17f8253e;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar4 = ((byte)(0xc << bVar6) | (byte)(0xc >> 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar5 = ((byte)(3 << bVar6) | (byte)(3 >> 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0x50);
		iVar10 = ((uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7) * 0x7a170451;
		bVar4 = bVar6 + 4 & 0x1e | 1;
		iVar10 = iVar10 - (iVar10 << ((bVar6 ^ 8) & 0x1e | 1));
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar7 = (iVar10 << (((byte)(0x1d >> bVar6) | (byte)(0x1d << 0x20 - bVar6)) & 0x1e | 1)) + iVar10;
		uVar7 = ~(uVar7 << bVar4 | uVar7 >> 0x20 - bVar4);
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar6 = ((byte)(0xd >> bVar6) | (byte)(0xd << 0x20 - bVar6)) & 0x1e | 1;
		uVar7 = (uVar7 << ((char)*(undefined4*)(unaff_EBP + -0x50) * -10 & 0x1eU | 1)) + uVar7;
		uVar7 = uVar7 << bVar6 | uVar7 >> 0x20 - bVar6;
		//puVar8 = (uint*)(*(int*)(unaff_EBP + -0x24) +
		//	(((uVar7 >> 0x1b | uVar7 << 5) ^ (uVar7 << 5 | uVar7 >> 0x1b) ^ uVar7) *
		//		-0x18f379b & 0x3ffffff) * 8 + -0xffffff4);

		int yeah = (((uVar7 >> 0x1b | uVar7 << 5) ^ (uVar7 << 5 | uVar7 >> 0x1b) ^ uVar7) *
			-0x18f379b & 0x3ffffff) * 8 + -0xffffff4;

		inst->OP = 22;
		inst->sBx = sBxConversion(yeah);
	}

	// OP_JMP 22 : sBx  
	void dfdb9(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		sbyte sVar5;
		byte bVar6;
		int iVar7;
		uint* puVar8;
		uint* puVar9;
		uint uVar10;
		//int unaff_EBP;
		uint uVar11;

		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x50) = iVar7;
		cVar1 = (char)*(uint*)(unaff_EBP + -0x50);
		bVar3 = -cVar1 - 0xdU & 0x1e | 1;
		uVar10 = (param_2 - iVar7) * 0x2001 + 0xaa19eeba;
		bVar4 = 3U - cVar1 & 0x1e | 1;
		uVar10 = (uVar10 << bVar3 | uVar10 >> 0x20 - bVar3) ^ (uVar10 << bVar4 | uVar10 >> 0x20 - bVar4) ^
			uVar10;
		uVar11 = *(uint*)(unaff_EBP + -0x50) & 0x1e | 1;
		uVar10 = uVar10 << (cVar1 * '\x03' & 0x1eU | 1) ^ uVar10;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		sVar5 = (sbyte)uVar11;
		bVar3 = ((byte)(9 >> sVar5) | (byte)(9 << 0x20 - sVar5)) & 0x1e | 1;
		uVar10 = (uVar10 >> 5 ^ uVar10 ^ 0x7312ff6c) * -0x1f;
		uVar10 = (uVar10 >> bVar3 | uVar10 << 0x20 - bVar3) * 0x4000001;
		uVar10 = uVar10 >> (1U - (char)*(undefined4*)(unaff_EBP + -0x50) & 0x1e | 1) ^ uVar10;
		uVar10 = uVar10 >> 0xb | uVar10 << 0x15;
		uVar10 = uVar10 * 0x65fc2200 ^ uVar10 * 0x3cb2fe11;
		bVar4 = ((byte)(0x1b << sVar5) | (byte)(0x1b >> 0x20 - sVar5)) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar6 = ((byte)(3 << bVar3) | (byte)(3 >> 0x20 - bVar3)) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar11 = ((uVar10 << bVar4 | uVar10 >> 0x20 - bVar4) ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6)
			^ uVar10) - (0x73496cd4 << bVar3 | 0x73496cd4U >> 0x20 - bVar3);
		uVar10 = uVar11 * 0x800;
		//puVar8 = (uint*)(*(int*)(unaff_EBP + -0x24) +
		//	((uVar10 >> 0x12 ^ (uVar10 | uVar11 >> 0x15)) * 0x396ca835 >> 5 & 0x3ffffff) * 8
		//	+ -0xffffff4);

		int lol = ((uVar10 >> 0x12 ^ (uVar10 | uVar11 >> 0x15)) * 0x396ca835 >> 5 & 0x3ffffff) * 8
			+ -0xffffff4;

		inst->OP = 22;
		inst->sBx = sBxConversion(lol);
	}

	// OP_CALL 28 : A B C
	void d05cd(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		uint uVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		//int unaff_EBP;

		uVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0x4c) = uVar3;
		uVar3 = uVar3 & 0x1e | 1;
		sVar4 = (sbyte)uVar3;
		uVar8 = (0x1c13ae2a << sVar4 | 0x1c13ae2aU >> 0x20 - sVar4) + ~*(uint*)(unaff_EBP + -0x44);
		*(uint*)(unaff_EBP + -0x24) = uVar3;
		*(uint*)(unaff_EBP + -0x44) = uVar8;
		bVar5 = ((byte)(0x1b >> sVar4) | (byte)(0x1b << 0x20 - sVar4)) & 0x1e | 1;
		bVar6 = ((byte)(0x19 >> sVar4) | (byte)(0x19 << 0x20 - sVar4)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x24) & 0x1f;
		bVar7 = ((byte)(3 >> bVar7) | (byte)(3 << 0x20 - bVar7)) & 0x1e | 1;
		uVar3 = (uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar3 = uVar3 >> bVar6 | uVar3 << 0x20 - bVar6;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x4c);
		uVar3 = ((uVar3 >> 0x1a | uVar3 << 6) ^ (uVar3 >> 3 | uVar3 << 0x1d) ^ uVar3) + 0xeaa1dd68;
		bVar5 = 0xe - bVar7 & 0x1e | 1;
		bVar6 = -bVar7 - 10 & 0x1e | 1;
		iVar1 = ((uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^ (uVar3 << bVar6 | uVar3 >> 0x20 - bVar6) ^
			uVar3) * -0x3ffffff;
		uVar8 = (iVar1 << ((bVar7 ^ 4) & 0x1e | 1)) + iVar1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x24) & 0x1f;
		bVar5 = ((byte)(0x1b << bVar7) | (byte)(0x1b >> 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x24) & 0x1f;
		bVar7 = ((byte)(0xd << bVar7) | (byte)(0xd >> 0x20 - bVar7)) & 0x1e | 1;
		uVar8 = (uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^ (uVar8 >> bVar7 | uVar8 << 0x20 - bVar7) ^
			uVar8;
		uVar3 = uVar8 * -0x7ffffff;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x24) & 0x1f;
		uVar3 = (((uVar3 >> 0xe | uVar8 * 0x40000) ^ (uVar3 >> 7 | uVar8 * 0x2000000) ^ uVar3) -
			*(int*)(unaff_EBP + -0x4c)) + 0x9978a544;
		*(uint*)(unaff_EBP + -0x44) = uVar3;
		bVar5 = ((byte)(0x13 << bVar7) | (byte)(0x13 >> 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x24) & 0x1f;
		bVar7 = ((byte)(1 << bVar7) | (byte)(1 >> 0x20 - bVar7)) & 0x1e | 1;
		cVar2 = (char)*(int*)(unaff_EBP + -0x4c);
		uVar3 = (uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar7 = cVar2 * '\f' & 0x1eU | 1;
		uVar3 = uVar3 >> 0xb ^ uVar3;
		bVar5 = cVar2 * '\x05' & 0x1eU | 1;
		uVar3 = (uVar3 >> bVar7 | uVar3 << 0x20 - bVar7) ^ (uVar3 >> bVar5 | uVar3 << 0x20 - bVar5) ^
			uVar3;
		bVar7 = -((char)(*(int*)(unaff_EBP + -0x4c) << 4) - cVar2) & 0x1eU | 1;
		bVar5 = cVar2 * '\a' & 0x1eU | 1;
		uVar8 = ((uVar3 << bVar7 | uVar3 >> 0x20 - bVar7) ^ (uVar3 >> bVar5 | uVar3 << 0x20 - bVar5) ^
			uVar3 ^ 0x1e01ddb3) + 0x736509f3;
		*(uint*)(unaff_EBP + -0x44) = (uVar8 >> 0x16 & 0x1ff) - 1;
		uVar3 = uVar8 >> 5 & 0x1ff;
		//if (uVar3 != 0) {
		//	*(uint*)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		uVar3 * 0x10 + (uVar8 >> 0xe & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}

		inst->OP = 28;
		inst->A = (uVar8 >> 0xe & 0xff);
		inst->B = uVar3;
		inst->C = uVar8 >> 0x16 & 0x1ff;
	}

	// OP_CALL 28 : A B C
	void d5207(instr* inst, uint param_1, uint param_2) {

		undefined* puVar1;
		undefined uVar2;
		char cVar3;
		undefined* puVar4;
		code* pcVar5;
		char cVar6;
		byte bVar7;
		//ushort uVar8;
		char* pcVar10;
		int* piVar11;
		uint* puVar12;
		uint* puVar13;
		byte bVar14;
		byte bVar15;
		char cVar17;
		uint uVar16;
		int* extraout_ECX;
		//undefined2 uVar18;
		int iVar19;
		uint uVar20;
		char cVar22;
		int iVar21;
		uint unaff_EBX;
		int iVar23;
		//int unaff_EBP;
		undefined4* puVar24;
		char* pcVar25;
		int in_FS_OFFSET;
		byte in_AF;
		byte in_TF;
		byte in_IF;
		byte in_NT;
		byte in_AC;
		byte in_VIF;
		byte in_VIP;
		byte in_ID;
		//undefined6 uVar26;
		char* unaff_retaddr;
		uint* in_stack_0000006c;
		uint* in_stack_00000070;
		char* in_stack_00000074;
		byte* in_stack_00000078;
		uint* in_stack_0000007c;
		undefined4* in_stack_00000080;
		int* in_stack_00000084;
		char* in_stack_00000088;
		char* in_stack_0000008c;
		uint* in_stack_00000090;
		char* in_stack_00000094;
		byte* in_stack_00000098;
		uint* in_stack_0000009c;
		undefined* in_stack_000000a0;
		int* in_stack_000000a4;
		char* in_stack_000000a8;
		char* in_stack_000000ac;
		uint* in_stack_000000b0;
		undefined4* puStack28;
		int iStack24;
		int iStack12;
		char* pcVar9;

		uVar20 = ~(param_2 << 0x1d | param_2 >> 3);
		uVar20 = uVar20 << 0x11 | uVar20 >> 0xf;
		*(uint*)(unaff_EBP + -0x44) = uVar20;
		bVar7 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar14 = bVar7 & 0x1e | 1;
		bVar15 = ((byte)(8 >> bVar14) | (byte)(8 << 0x20 - bVar14)) & 0x1e | 1;
		bVar14 = ((byte)(6 >> bVar14) | (byte)(6 << 0x20 - bVar14)) & 0x1e | 1;
		uVar20 = (uVar20 >> bVar15 | uVar20 << 0x20 - bVar15) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar14 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar14)
			^ *(uint*)(unaff_EBP + -0x44);
		uVar20 = uVar20 << bVar14 | uVar20 >> 0x20 - bVar14;
		uVar20 = uVar20 * 0x134e0000 ^ uVar20 * 0x431209a7;
		uVar20 = (uVar20 << (0xc - bVar7 & 0x1e | 1) ^ uVar20) * -0x2e2bef63;
		bVar14 = bVar7 * -0xe & 0x1e | 1;
		bVar15 = bVar7 * -3 & 0x1e | 1;
		uVar20 = (uVar20 >> bVar14 | uVar20 << 0x20 - bVar14) ^
			(uVar20 >> bVar15 | uVar20 << 0x20 - bVar15) ^ uVar20;
		uVar20 = (uVar20 << (bVar7 * '\x06' & 0x1e | 1)) + uVar20 ^ 0x7b450ec5;
		uVar16 = uVar20 >> 0x16 ^ uVar20;
		uVar16 = (uVar16 << 0x18 | uVar16 >> 8) ^ (uVar16 << 0x10 | uVar20 >> 0x10) ^ uVar16;
		uVar20 = uVar16 >> 0x16;
		uVar16 = uVar20 | uVar16 << 10;
		uVar16 = (uVar20 << 0x1d | uVar16 >> 3) ^ (uVar16 >> 7 | uVar20 << 0x19) ^ uVar16;
		puVar4 = *(undefined**)(unaff_EBP + -0x5c);
		uVar16 = uVar16 >> 5 ^ (uVar16 << 1 | (uint)((int)uVar16 < 0)) ^ uVar16;
		pcVar25 = (char*)((uVar16 & 0x1ff) - 1);
		uVar20 = uVar16 >> 0x11 & 0x1ff;
		//if (uVar20 != 0) {
		//	*(undefined**)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		puVar4 + uVar20 * 0x10 + (uVar16 >> 9 & 0xff) * 0x10;
		//}

		inst->OP = 28;
		inst->A = (uVar16 >> 9 & 0xff);
		inst->B = uVar20;
		inst->C = uVar16 & 0x1ff;
	}

	// OP_CALL 28 : A B C
	void d6ad1(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		byte bVar2;
		int iVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		//int unaff_EBP;
		uint uVar7;
		int iVar8;

		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)iVar8;
		bVar4 = bVar2 & 0x1e | 1;
		uVar7 = ((param_2 + 0xda640b17U) * 0x400000 ^ param_2 + 0xda640b17U) * 0x4001 -
			(0x3fdbe76b << bVar4 | 0x3fdbe76bU >> 0x20 - bVar4);
		bVar4 = bVar2 * '\n' & 0x1e | 1;
		bVar5 = bVar2 * -10 & 0x1e | 1;
		iVar3 = ~((uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^
			uVar7) * 0x2001;
		uVar6 = (iVar3 << (-bVar2 - 5 & 0x1e | 1)) + iVar3;
		uVar7 = uVar6 >> 0xf;
		uVar6 = uVar6 * 0x20000 | uVar7;
		uVar6 = (uVar7 << 0x15 | uVar6 >> 0xb) ^ (uVar6 << 1 | (uint)((int)uVar6 < 0)) ^ uVar6;
		uVar6 = (uVar6 << 0x13 | uVar6 >> 0xd) ^ (uVar6 << 3 | uVar6 >> 0x1d) ^ iVar8 * 0x2b68cf7c ^ uVar6
			;
		uVar6 = (uVar6 >> 10 | uVar6 << 0x16) ^ (uVar6 << 7 | uVar6 >> 0x19) ^ uVar6;
		uVar7 = uVar6 >> 9 & 0x1ff;
		//if (uVar7 != 0) {
		//	*(uint*)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		uVar7 * 0x10 + (uVar6 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//iVar3 = func_0x00530aa2((uVar6 & 0x1ff) - 1);

		inst->OP = 28;
		inst->A = (uVar6 >> 0x12 & 0xff);
		inst->B = uVar7;
		inst->C = (uVar6 & 0x1ff);
	}

	// OP_CALL 28 : A B C
	void d9016(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;

		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar1 = (char)iVar7;
		uVar5 = param_2 >> ((char)(iVar7 << 4) - cVar1 & 0x1eU | 1) ^ *(uint*)(unaff_EBP + -0x44);
		bVar2 = cVar1 + 0xfU & 0x1e | 1;
		bVar3 = cVar1 + 0xcU & 0x1e | 1;
		bVar4 = 6U - cVar1 & 0x1e | 1;
		uVar6 = (((uVar5 << bVar2 | uVar5 >> 0x20 - bVar2) ^ (uVar5 << bVar3 | uVar5 >> 0x20 - bVar3) ^
			uVar5) - iVar7) + 0x5b597df4;
		uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ uVar6;
		uVar5 = uVar6 << bVar4 | uVar6 >> 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0xc) = uVar5;
		bVar2 = 5U - cVar1 & 0x1e | 1;
		uVar6 = uVar5 ^ (uVar6 >> bVar2 | uVar6 << 0x20 - bVar2) ^ uVar6;
		*(uint*)(unaff_EBP + -0xc) = (uVar6 >> 8 & 0x1ff) - 1;
		uVar5 = uVar6 >> 0x11 & 0x1ff;
		//if (uVar5 != 0) {
		//	*(uint*)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		uVar5 * 0x10 + (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}

		inst->OP = 28;
		inst->A = (uVar6 & 0xff);
		inst->B = uVar5;
		inst->C = (uVar6 >> 8 & 0x1ff);
	}

	// OP_CALL 28 : A B C
	void d9773(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		uint uVar3;
		int iVar4;
		byte bVar5;
		byte bVar6;
		char unaff_BH;
		//int unaff_EBP;
		uint uVar7;
		int iVar8;

		*(int*)(unaff_EBP + -0x44) = param_2 * -0xfff;
		cVar2 = (char)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		uVar3 = (param_2 * 0x800000 ^ *(uint*)(unaff_EBP + -0x44)) * -0xfffffff;
		bVar5 = cVar2 + 5U & 0x1e | 1;
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		bVar6 = cVar2 - 4U & 0x1e | 1;
		uVar7 = ~((uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^ (uVar3 << bVar6 | uVar3 >> 0x20 - bVar6) ^
			uVar3);
		iVar8 = (uVar7 >> 6 & 0x1ff) - 1;
		uVar3 = uVar7 >> 0xf & 0x1ff;
		//if (uVar3 != 0) {
		//	*(uint*)(iVar1 + 0x10) = uVar3 * 0x10 + (uVar7 >> 0x18) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}

		inst->OP = 28;
		inst->A = (uVar7 >> 0x18);
		inst->B = uVar3;
		inst->C = (uVar7 >> 6 & 0x1ff);
	}

	// OP_CALL 28 : A B C
	void d9cc4(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		sbyte sVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;
		//undefined6 uVar9;
		undefined4 unaff_retaddr;

		uVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar2;
		*(uint*)(unaff_EBP + -0x44) = param_2 ^ uVar2 ^ 0x9615a3e;
		uVar2 = uVar2 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar2;
		sVar3 = (sbyte)uVar2;
		uVar2 = *(int*)(unaff_EBP + -0x44) <<
			(((byte)(0xe << sVar3) | (byte)(0xe >> 0x20 - sVar3)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = uVar2 * 0x323b6285;
		uVar7 = (uVar2 * -0x5ec00000 | uVar7 >> 10) ^ (uVar7 >> 4 | uVar2 * 0x50000000) ^ uVar7;
		bVar4 = ((byte)(0x16 >> sVar3) | (byte)(0x16 << 0x20 - sVar3)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(9 >> bVar6) | (byte)(9 << 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			(0xf315b15U >> bVar6 | 0xf315b15 << 0x20 - bVar6) ^ uVar7;
		cVar1 = (char)*(int*)(unaff_EBP + -0xc);
		bVar6 = cVar1 + 5U & 0x1e | 1;
		uVar7 = uVar7 - (uVar7 << (cVar1 * -9 & 0x1eU | 1));
		iVar8 = ~(uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) + *(int*)(unaff_EBP + -0xc) * -0x53c0c2c7 +
			0xdd0da7b;
		*(int*)(unaff_EBP + -0x1c) = iVar8;
		uVar2 = (iVar8 << (cVar1 * '\b' & 0x1eU | 1)) + *(int*)(unaff_EBP + -0x1c);
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = bVar4 & 0x1f;
		bVar4 = bVar4 & 0x1f;
		bVar5 = ((byte)(3 >> bVar6) | (byte)(3 << 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = ((byte)(0x17 >> bVar4) | (byte)(0x17 << 0x20 - bVar4)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar2 >> bVar6 | uVar2 << 0x20 - bVar6;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(0x12 >> bVar6) | (byte)(0x12 << 0x20 - bVar6)) & 0x1e | 1;
		uVar2 = *(uint*)(unaff_EBP + -0x1c) ^ (uVar2 >> bVar6 | uVar2 << 0x20 - bVar6) ^ uVar2;
		uVar2 = uVar2 << 0x1e | uVar2 >> 2;
		uVar2 = (uVar2 << bVar5 | uVar2 >> 0x20 - bVar5) + (-0x72fe6fcd - *(int*)(unaff_EBP + -0xc));
		iVar8 = (uVar2 >> 9 & 0x1ff) - 1;
		//*(int*)(unaff_EBP + -0x1c) = iVar8;
		//if ((uVar2 & 0x1ff) != 0) {
		//	*(uint*)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		(uVar2 & 0x1ff) * 0x10 + (uVar2 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}

		inst->OP = 28;
		inst->A = (uVar2 >> 0x12 & 0xff);
		inst->B = uVar2 & 0x1ff;
		inst->C = (uVar2 >> 9 & 0x1ff);
	}


	// OP_CALL 28 : A B C
	void db621(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		byte bVar2;
		uint uVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;

		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)iVar8;
		uVar7 = (param_2 * -0x1f << ((bVar2 ^ 0xe) & 0x1e | 1) ^ param_2 * -0x1f) * 0x10001 + 0x7d4a57c2;
		uVar7 = ((uVar7 * 0x2000000 | uVar7 >> 7) ^ (uVar7 * 0x40 | uVar7 >> 0x1a) ^ uVar7) * -0xb1425ad;
		bVar4 = 8 - bVar2 & 0x1e | 1;
		bVar5 = -bVar2 - 7 & 0x1e | 1;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^
			uVar7;
		bVar4 = (byte)((iVar8 * -3 & 7U) << 2) | 1;
		bVar5 = bVar2 * '\t' & 0x1e | 1;
		bVar6 = bVar2 + 7 & 0x1e | 1;
		uVar7 = ((uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^
			uVar7) * 0x40000001;
		bVar4 = bVar2 - 5 & 0x1e | 1;
		uVar7 = ((uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^ (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^
			uVar7) * 0x5dc697ff;
		uVar7 = uVar7 >> ((bVar2 ^ 10) & 0x1e | 1) ^ uVar7;
		uVar3 = uVar7 >> 0x14 & 0x1ff;
		//if (uVar3 != 0) {
		//	*(uint*)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		uVar3 * 0x10 + (uVar7 >> 3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//iVar8 = func_0x00527ce7((uVar7 >> 0xb & 0x1ff) - 1);

		inst->OP = 28;
		inst->A = (uVar7 >> 3 & 0xff);
		inst->B = uVar3;
		inst->C = (uVar7 >> 0xb & 0x1ff);
	}

	// OP_CALL 28 : A B C
	void dc2cf(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;

		uVar5 = (param_2 << 9 | param_2 >> 0x17) ^ 0xe71cdcbe;
		*(uint*)(unaff_EBP + -0x44) = uVar5;
		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar2 = (char)iVar7;
		uVar5 = uVar5 >> (cVar2 - 5U & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44);
		uVar5 = (uVar5 >> 0x17 | uVar5 << 9) ^ (uVar5 >> 0xb | uVar5 << 0x15) ^ uVar5;
		uVar5 = uVar5 << (cVar2 - 0xbU & 0x1e | 1) ^ uVar5 ^ 0x1afb6f99;
		bVar3 = cVar2 - 0x10U & 0x1e | 1;
		uVar5 = (uVar5 >> 5 | uVar5 << 0x1b) ^ (uVar5 << 4 | uVar5 >> 0x1c) ^ uVar5;
		bVar4 = cVar2 + 0xeU & 0x1e | 1;
		uVar5 = (uVar5 << bVar3 | uVar5 >> 0x20 - bVar3) ^ (uVar5 >> bVar4 | uVar5 << 0x20 - bVar4) ^
			uVar5;
		uVar6 = ((uVar5 >> 0x13 ^ uVar5) - iVar7) + 0x2c18286;
		uVar5 = uVar6 >> 0xd & 0x1ff;
		//if (uVar5 != 0) {
		//	*(uint*)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		uVar5 * 0x10 + (uVar6 >> 0x16 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		//}
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//iVar7 = func_0x00526d51((uVar6 & 0x1ff) - 1);

		inst->OP = 28;
		inst->A = (uVar6 >> 0x16 & 0xff);
		inst->B = uVar5;
		inst->C = (uVar6 & 0x1ff);
	}


	// OP_RETURN 30 : A B 
	void d822d(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		uint uVar9;

		uVar7 = (param_2 >> 0x1a | param_2 << 6) + 0xeb02a345 ^ 0x26f5d5c1;
		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar7 = uVar7 >> 0x12 | uVar7 << 0xe;
		bVar6 = (byte)uVar9;
		*(uint*)(unaff_EBP + -0x44) = uVar7;
		bVar4 = (char)(uVar9 << 4) - bVar6 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		bVar5 = bVar6 * '\x03' & 0x1e | 1;
		uVar8 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar5 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = (uVar9 ^ 4) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar7;
		bVar6 = bVar6 & 0x1e | 1;
		uVar7 = uVar8 + 0x9f060fcd + (uVar8 << (sbyte)uVar7) ^ 0x34205914;
		uVar7 = uVar7 << (((byte)(0xd << bVar6) | (byte)(0xd >> 0x20 - bVar6)) & 0x1e | 1) ^ uVar7;
		uVar7 = ~((uVar7 << 0x1a | uVar7 >> 6) ^ (uVar7 << 0x11 | uVar7 >> 0xf) ^
			(0x4cbc1eda << bVar6 | 0x4cbc1edaU >> 0x20 - bVar6) ^ uVar7);
		uVar7 = uVar7 << 0x10 ^ uVar7;
		uVar7 = (uVar7 << (((byte)(0x1d << bVar6) | (byte)(0x1d >> 0x20 - bVar6)) & 0x1e | 1)) + uVar7;
		bVar4 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 2) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		uVar7 = (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^
			uVar7;
		//*(undefined*)(unaff_EBP + -0x11) = *(undefined*)(*(int*)(iVar1 + 0x1c) + 0x14);
		//pcVar3 = *(char**)(unaff_EBP + -0x5c);
		uVar8 = uVar7 >> 8 & 0x1ff;
		//if (uVar8 != 0) {
		//	*(char**)(iVar1 + 0x10) = pcVar3 + uVar8 * 0x10 + -0x10 + (uVar7 & 0xff) * 0x10;
		//	pcVar3 = *(char**)(unaff_EBP + -0x5c);
		//}

		inst->OP = 30;
		inst->A = (uVar7 & 0xff);
		inst->B = uVar8;
	}

	// OP_RETURN 30 : A B 
	void df62e(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		int iVar6;
		uint uVar7;
		//int unaff_EBP;
		uint uVar8;

		bVar5 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar3 = -bVar5 - 0xf & 0x1e | 1;
		uVar8 = (~*(uint*)(unaff_EBP + -0x44) << bVar3 | ~*(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar3) +
			0xbc08cdd1;
		bVar3 = 10 - bVar5 & 0x1e | 1;
		bVar4 = bVar5 * -10 & 0x1e | 1;
		uVar8 = uVar8 << bVar4 | uVar8 >> 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0x44) = uVar8 << bVar3 | uVar8 >> 0x20 - bVar3;
		bVar3 = bVar5 & 0x1e | 1;
		uVar8 = *(uint*)(unaff_EBP + -0x44) >>
			(((byte)(7 << bVar3) | (byte)(7 >> 0x20 - bVar3)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar8 = uVar8 << 2 | uVar8 >> 0x1e;
		iVar6 = uVar8 - (uVar8 << ((bVar5 ^ 0xf1) & 0x1e | 1));
		uVar8 = ~((iVar6 << (((byte)(0x12 >> bVar3) | (byte)(0x12 << 0x20 - bVar3)) & 0x1e | 1)) + iVar6);
		uVar8 = uVar8 - (uVar8 << (bVar5 - 6 & 0x1e | 1));
		bVar3 = bVar5 - 0xf & 0x1e | 1;
		bVar5 = bVar5 + 9 & 0x1e | 1;
		uVar8 = ((uVar8 >> bVar3 | uVar8 << 0x20 - bVar3) ^ (uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^
			uVar8) + 0xdefc568f;
		//*(undefined*)(unaff_EBP + -0x11) =
		//	*(undefined*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0x14);
		//pcVar2 = *(char**)(unaff_EBP + -0x5c);
		uVar7 = uVar8 >> 8 & 0x1ff;
		if (uVar7 != 0) {
		//	*(char**)(*(int*)(unaff_EBP + -0xa8) + 0x10) =
		//		pcVar2 + uVar7 * 0x10 + -0x10 + (uVar8 & 0xff) * 0x10;
		//	pcVar2 = *(char**)(unaff_EBP + -0x5c);
		}

		inst->OP = 30;
		inst->A = (uVar8 & 0xff);
		inst->B = uVar7;
	}

	// OP_FORLOOP 31 : A sBx 
	void d0ecb(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		bool bVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		//int unaff_EBP;
		uint uVar9;
		double* pdVar10;
		double dVar11;
		//double in_XMM3_Qa;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar8 = param_2 ^ uVar9 ^ 0x789202b1;
		bVar5 = (byte)uVar9 & 0x1e | 1;
		uVar9 = uVar8 * -0xab103c0;
		uVar8 = uVar8 * 0x1bd53bf1 >> 0x1a | uVar9;
		uVar8 = (uVar9 >> 0x16 | uVar8 << 10) ^ (uVar8 << 6 | uVar9 >> 0x1a) ^ uVar8;
		uVar9 = uVar8 * 0x337b2c00 ^ uVar8 * -0x3a732135;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar6 = ((byte)(0x15 << bVar5) | (byte)(0x15 >> 0x20 - bVar5)) & 0x1e | 1;
		iVar1 = *(int*)(unaff_EBP + -0xc);
		bVar7 = ((byte)(5 << bVar5) | (byte)(5 >> 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = (byte)iVar1;
		uVar9 = ((uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -4) >> bVar7 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -4)) * 0x44c660e7;
		bVar6 = bVar5 * '\v' & 0x1e | 1;
		bVar7 = bVar5 * '\x05' & 0x1e | 1;
		uVar9 = ((uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^ (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^
			uVar9) + 0xe0eb52b3;
		bVar6 = (char)(iVar1 << 4) - bVar5 & 0x1e | 1;
		bVar5 = (bVar5 ^ 8) & 0x1e | 1;
		bVar7 = (byte)((iVar1 * -3 & 7U) << 2) | 1;
		uVar9 = ((uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^ (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			uVar9 ^ 0x5743c5c7) * 0x5932375;
		uVar9 = (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) + (0x70da4805 - *(int*)(unaff_EBP + -0xc));
		uVar9 = (uVar9 * 0x8000 | uVar9 >> 0x11) ^ (uVar9 >> 10 | uVar9 * 0x400000) ^ uVar9;
		uVar9 = (uVar9 >> 0x17 | uVar9 << 9) ^ (uVar9 >> 9 | uVar9 << 0x17) ^ uVar9;
		pdVar10 = (double*)((uVar9 >> 5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//dVar11 = pdVar10[4] + *pdVar10;
		//if (pdVar10[4] <= in_XMM3_Qa) {
		//	bVar2 = dVar11 < pdVar10[2];
		//}
		//else {
		//	bVar2 = pdVar10[2] < dVar11;
		//}
		//if (!bVar2) {
			//iVar1 = *(int*)(unaff_EBP + -0x24);
			//*pdVar10 = dVar11;
			//*(uint*)(unaff_EBP + -0x50) = iVar1 + -0xffff4 + (uVar9 >> 0xd & 0x3ffff) * 8;
		//}

		inst->OP = 31;
		inst->A = (uVar9 >> 5 & 0xff);
		inst->sBx = (uVar9 >> 0xd & 0x3ffff);
	}

	// OP_FORLOOP 31 : A sBx 
	void d3d7f(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		bool bVar2;
		char cVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;
		uint uVar10;
		double* pdVar11;
		double dVar12;
		double in_XMM3_Qa;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar10 = ~((param_2 << 0x16 | param_2 >> 10) ^ (param_2 << 9 | param_2 >> 0x17) ^ param_2);
		uVar9 = uVar9 & 0x1e | 1;
		sVar5 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		uVar9 = ~((uVar10 << 0x13 | uVar10 >> 0xd) ^ (uVar10 >> 0xf | uVar10 << 0x11) ^ uVar10);
		bVar6 = ((byte)(0xb << sVar5) | (byte)(0xb >> 0x20 - sVar5)) & 0x1e | 1;
		uVar9 = uVar9 << bVar6 | uVar9 >> 0x20 - bVar6;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = bVar8 & 0x1f;
		bVar8 = bVar8 & 0x1f;
		bVar7 = ((byte)(0xe >> bVar6) | (byte)(0xe << 0x20 - bVar6)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar9;
		bVar8 = ((byte)(8 >> bVar8) | (byte)(8 << 0x20 - bVar8)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(3 >> bVar6) | (byte)(3 << 0x20 - bVar6)) & 0x1e | 1;
		uVar9 = (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			(*(uint*)(unaff_EBP + -0x1c) >> bVar6 | *(uint*)(unaff_EBP + -0x1c) << 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -0x1c);
		cVar3 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar9 = (uVar9 >> bVar8 | uVar9 << 0x20 - bVar8) + 0xecdaca92;
		uVar9 = uVar9 >> (cVar3 * '\t' & 0x1eU | 1) ^ uVar9;
		uVar9 = (uVar9 << (cVar3 + 8U & 0x1e | 1)) + uVar9;
		uVar9 = ~((uVar9 >> 8 | uVar9 * 0x1000000) ^ (uVar9 >> 6 | uVar9 * 0x4000000) ^ uVar9);
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = bVar8 & 0x1f;
		uVar9 = (uVar9 << (bVar8 & 0x1f)) + uVar9;
		uVar9 = ((0xffe7cd6 << bVar6 | 0xffe7cd6U >> 0x20 - bVar6) +
			~((uVar9 >> 0x10 ^ uVar9) * 0x3b605b4d)) * 0x65dae65b;
		//pdVar11 = (double*)((uVar9 >> 0x14 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		/*
		dVar12 = pdVar11[4] + *pdVar11;
		if (pdVar11[4] <= in_XMM3_Qa) {
			bVar2 = dVar12 < pdVar11[2];
		}
		else {
			bVar2 = pdVar11[2] < dVar12;
		}
		pcVar4 = (char*)(uint)!bVar2;
		if (pcVar4 != (char*)0x0) {
			iVar1 = *(int*)(unaff_EBP + -0x24);
			*pdVar11 = dVar12;
			*(undefined4*)((int)pdVar11 + 0xc) = 4;
			*(double*)(unaff_EBP + -0x10) = dVar12;
			pcVar4 = (char*)(iVar1 + (uVar9 & 0x3ffff) * 8 + -0xffff4);
			*pcVar4 = *pcVar4 + (char)pcVar4;
			*pcVar4 = *pcVar4 + (char)pcVar4;
		}
		*/

		inst->OP = 31;
		inst->A = uVar9 >> 0x14 & 0xff;
		inst->sBx = (uVar9 & 0x3ffff);
	}

	// OP_FORLOOP 31 : A sBx 
	void d90dd(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		bool bVar2;
		char cVar3;
		byte bVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		double* pdVar8;
		int unaff_EBX;
		//int unaff_EBP;
		uint uVar9;
		uint uVar10;
		int iVar11;
		char* pcVar12;
		uint uVar13;
		double dVar14;
		double in_XMM3_Qa;

		uVar13 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar7 = (byte)uVar13;
		*(uint*)(unaff_EBP + -0xc) = uVar13;
		bVar4 = (bVar7 ^ 0xf9) & 0x1e | 1;
		uVar9 = uVar13 * 0x39608393 + param_2;
		uVar10 = ~(uVar9 >> bVar4 | uVar9 << 0x20 - bVar4);
		uVar9 = uVar13 & 0x1e | 1;
		sVar5 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		uVar10 = (uVar10 << (((byte)(9 >> sVar5) | (byte)(9 << 0x20 - sVar5)) & 0x1e | 1)) + uVar10;
		uVar10 = (uVar10 * 0x20000 | uVar10 >> 0xf) ^ (uVar10 * 0x8000 | uVar10 >> 0x11) ^ uVar10;
		bVar4 = -bVar7 - 4 & 0x1e | 1;
		uVar9 = ~((uVar10 >> 0x1e | uVar10 << 2) ^ (uVar10 << 0xe | uVar10 >> 0x12) ^ uVar10);
		iVar11 = uVar9 - (uVar9 << ((bVar7 ^ 0xf9) & 0x1e | 1));
		bVar6 = bVar7 + 0xd & 0x1e | 1;
		uVar9 = (iVar11 - (iVar11 << (bVar7 * '\b' & 0x1e | 1))) + 0x31b9b782;
		bVar7 = (char)*(undefined4*)(unaff_EBP + -0xc) + 7U & 0x1e | 1;
		uVar9 = (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^ (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^
			uVar9;
		uVar9 = uVar9 << bVar4 | uVar9 >> 0x20 - bVar4;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar9 = (uVar9 << (((byte)(0xc >> bVar7) | (byte)(0xc << 0x20 - bVar7)) & 0x1e | 1)) + uVar9;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar7 = bVar4 & 0x1f;
		bVar4 = bVar4 & 0x1f;
		bVar4 = ((byte)(6 << bVar4) | (byte)(6 >> 0x20 - bVar4)) & 0x1e | 1;
		uVar9 = (uVar9 >> 0x16 | uVar9 * 0x400) ^ (uVar9 >> 0xc | uVar9 * 0x100000) ^ uVar9;
		uVar10 = ~uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar7 = ((byte)(0xc << bVar7) | (byte)(0xc >> 0x20 - bVar7)) & 0x1e | 1;
		uVar9 = (uVar10 << bVar4 | uVar10 >> 0x20 - bVar4) + (0x7b003da2 - *(int*)(unaff_EBP + -0xc));
		uVar9 = uVar9 >> 0x12 | uVar9 * 0x4000;
		pcVar12 = (char*)(uVar9 << bVar7 | uVar9 >> 0x20 - bVar7);
		pdVar8 = (double*)(((uint)pcVar12 >> 0x18) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		/*
		dVar14 = pdVar8[4] + *pdVar8;
		if (pdVar8[4] <= in_XMM3_Qa) {
			bVar2 = dVar14 < pdVar8[2];
		}
		else {
			bVar2 = pdVar8[2] < dVar14;
		}
		iVar11 = *(int*)(unaff_EBP + -0x50);
		if (!bVar2) {
			iVar11 = *(int*)(unaff_EBP + -0x24);
			*pdVar8 = dVar14;
			*(undefined4*)((int)pdVar8 + 0xc) = 4;
			*(double*)(unaff_EBP + -0x10) = dVar14;
			pcVar12 = (char*)(iVar11 + ((uint)pcVar12 & 0x3ffff) * 8 + -0xffff4);
		}
		*/

		inst->OP = 31;
		inst->A = (uint)pcVar12 >> 0x18;
		inst->sBx = (uint)pcVar12 & 0x3ffff;
	}

	// OP_FORPREP 32 : A sBx 
	void d0541(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		int iVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		int* unaff_EBX;
		//int unaff_EBP;
		uint uVar8;
		undefined8 in_XMM0_Qa;

		iVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x4c) = iVar2;
		bVar4 = (byte)iVar2 & 0x1e | 1;
		bVar5 = ((byte)(0x18 >> bVar4) | (byte)(0x18 << 0x20 - bVar4)) & 0x1e | 1;
		bVar6 = ((byte)(9 >> bVar4) | (byte)(9 << 0x20 - bVar4)) & 0x1e | 1;
		uVar8 = ~((param_2 << bVar5 | param_2 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar6 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -0x44) ^ 0x7dc0d138);
		uVar7 = uVar8 << 0x15 ^ uVar8;
		uVar7 = (uVar7 >> 0x1c | uVar7 << 4) ^ (uVar7 >> 0x15 | uVar8 << 0xb) ^ uVar7;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0x4c) - 3U & 0x1e | 1;
		uVar7 = (uVar7 << (((byte)(4 >> bVar4) | (byte)(4 << 0x20 - bVar4)) & 0x1e | 1)) + uVar7;
		uVar7 = uVar7 << bVar5 | uVar7 >> 0x20 - bVar5;
		bVar4 = -(char)*(undefined4*)(unaff_EBP + -0x4c) - 0xcU & 0x1e | 1;
		bVar5 = -(char)*(undefined4*)(unaff_EBP + -0x4c) - 5U & 0x1e | 1;
		uVar7 = ((uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7) + 0x9cddd70c;
		//pcVar3 = *(char**)(*(int*)(unaff_EBP + -0xa8) + 0x1c);
		//iVar2 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);

		inst->OP = 32;
		inst->A = (uVar7 & 0xff);
		inst->sBx = uVar7 >> 8 & 0x3ffff;
	}

	// OP_FORPREP 32 : A sBx 
	void d6255(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		int iVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		int unaff_EBX;
		//int unaff_EBP;

		iVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar3;
		bVar5 = (byte)iVar3 & 0x1e | 1;
		bVar6 = ((byte)(0x13 >> bVar5) | (byte)(0x13 << 0x20 - bVar5)) & 0x1e | 1;
		uVar7 = (0x518ab569 << bVar5 | 0x518ab569U >> 0x20 - bVar5) ^ *(uint*)(unaff_EBP + -0x44);
		bVar5 = ((byte)(2 >> bVar5) | (byte)(2 << 0x20 - bVar5)) & 0x1e | 1;
		uVar7 = (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7;
		uVar7 = (uVar7 >> 0x14 | uVar7 << 0xc) * -0x7ffff;
		uVar7 = uVar7 << bVar5 ^ uVar7;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0xc) - 0xdU & 0x1e | 1;
		uVar7 = (uVar7 >> 0x16 | uVar7 << 10) ^ (uVar7 << 0xd | uVar7 >> 0x13) ^ uVar7;
		uVar1 = *(undefined4*)(unaff_EBP + -0x50);
		uint yep = (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5);
		iVar3 = (yep >> 5 & 0xff) * 0x10 +
			*(int*)(unaff_EBP + -0x5c);

		inst->OP = 32;
		inst->A = (yep >> 5 & 0xff);
		inst->sBx = (yep >> 0xd & 0x3ffff);
	}

	// OP_FORPREP 32 : A sBx 
	void d8ee2(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		char cVar2;
		sbyte sVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;

		uVar5 = param_2 >> 0x16 ^ *(uint*)(unaff_EBP + -0x44);
		uVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar5 = (uVar5 << 0x16 | *(uint*)(unaff_EBP + -0x44) >> 10) ^ (uVar5 >> 2 | uVar5 << 0x1e) ^
			uVar5;
		*(uint*)(unaff_EBP + -0xc) = uVar6;
		uVar6 = uVar6 & 0x1e | 1;
		sVar3 = (sbyte)uVar6;
		*(uint*)(unaff_EBP + -4) = uVar6;
		bVar4 = ((byte)(6 >> sVar3) | (byte)(6 << 0x20 - sVar3)) & 0x1e | 1;
		uVar5 = uVar5 * 0x8df0000 ^ uVar5 * 0x7b408df;
		uVar5 = ~(((uVar5 << (((byte)(0xf >> sVar3) | (byte)(0xf << 0x20 - sVar3)) & 0x1e | 1)) + uVar5 ^
			*(int*)(unaff_EBP + -0xc) + 0x27f5ac4aU) * 0x8001);
		uVar5 = uVar5 >> bVar4 | uVar5 << 0x20 - bVar4;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar5 = uVar5 - (uVar5 << (((byte)(0x12 << bVar4) | (byte)(0x12 >> 0x20 - bVar4)) & 0x1e | 1));
		*(uint*)(unaff_EBP + -0xc) = uVar5;
		iVar7 = (uVar5 >> 0x16 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);

		inst->OP = 32;
		inst->A = (uVar5 >> 0x16 & 0xff);
		inst->sBx = uVar5 & 0x3ffff;
	}

	// OP_FORPREP 32 : A sBx 
	void da88e(instr* inst, uint param_1, int param_2) {

		char* pcVar1;
		byte bVar2;
		char cVar3;
		byte bVar4;
		//int unaff_EBP;
		uint uVar5;
		int iVar6;

		uVar5 = -param_2;
		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)iVar6;
		uVar5 = (uVar5 >> 0x1b | param_2 * -0x20) ^ (param_2 * -0x800000 | uVar5 >> 9) ^ uVar5;
		bVar4 = bVar2 & 0x1e | 1;
		uVar5 = (uVar5 << (((byte)(0x1c << bVar4) | (byte)(0x1c >> 0x20 - bVar4)) & 0x1e | 1)) + uVar5;
		uVar5 = uVar5 * 0x100000 | uVar5 >> 0xc;
		uVar5 = uVar5 >> 0x11 ^ uVar5 ^ 0x453cfa2f;
		uVar5 = ((uVar5 << 0x1e | uVar5 >> 2) ^ (uVar5 >> 0xf | uVar5 << 0x11) ^ uVar5) * -0xf +
			0x570e5a42 + iVar6;
		uVar5 = uVar5 << ((bVar2 ^ 0xf1) & 0x1e | 1) ^ uVar5;
		uVar5 = (uVar5 >> 0x18 | uVar5 << 8) ^ (uVar5 >> 8 | uVar5 << 0x18) ^ uVar5;
		uint decd = ~(uVar5 << 2 ^ (uVar5 << 0x1a | uVar5 >> 6) ^ uVar5);
		iVar6 = (decd >> 0x14 & 0xff) * 0x10 +
			*(int*)(unaff_EBP + -0x5c);

		inst->OP = 32;
		inst->A = (decd >> 0x14 & 0xff);
		inst->sBx = decd >> 0x2 & 0x3ffff;
	}

	// OP_TFORLOOP 33 : A C 
	void d2d58(instr* inst, uint param_1, uint param_2) {

		undefined4* puVar1;
		uint* puVar2;
		char cVar3;
		uint uVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		undefined8* puVar9;
		char* pcVar10;
		int iVar11;
		//int unaff_EBP;
		uint uVar12;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar12 = param_1 + -8 >> 2;
		cVar3 = (char)uVar12;
		*(uint*)(unaff_EBP + -4) = uVar12;
		param_2 = param_2 << (cVar3 * -0x10 & 0x1eU | 1) ^ param_2;
		param_2 = param_2 >> 0x14 ^ param_2;
		uVar4 = (param_2 << (cVar3 - 9U & 0x1e | 1) ^ param_2) * 0x72177087;
		uVar8 = uVar12 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar8;
		uVar4 = (uVar4 >> (0xfU - cVar3 & 0x1e | 1) ^ uVar4) + uVar12 * -0x3048943e;
		sVar5 = (sbyte)uVar8;
		uVar8 = ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 5 | uVar4 * 0x8000000) ^ uVar4) -
			(0x31a53094U >> sVar5 | 0x31a53094 << 0x20 - sVar5) ^ uVar12 + 0x62da81ac;
		bVar6 = ((byte)(0x18 >> sVar5) | (byte)(0x18 << 0x20 - sVar5)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar7 = ((byte)(1 >> bVar7) | (byte)(1 << 0x20 - bVar7)) & 0x1e | 1;
		uVar8 = (uVar8 << bVar6 | uVar8 >> 0x20 - bVar6) ^ (uVar8 << bVar7 | uVar8 >> 0x20 - bVar7) ^
			uVar8;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar8 = (uVar8 << 0x1a | uVar8 >> 6) ^ (uVar8 << 10 | uVar8 >> 0x16) ^ uVar8;
		uVar4 = (0xe << bVar7 | 0xeU >> 0x20 - bVar7) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x54) = uVar4;
		uVar4 = ~(uVar8 << (sbyte)uVar4 ^ uVar8);
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar4 = (uVar4 << 0x17 | uVar4 >> 9) ^ (uVar4 >> 5 | uVar4 << 0x1b) ^ uVar4;
		bVar6 = ((byte)(0x11 << bVar7) | (byte)(0x11 >> 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x54) & 0x1f;
		uVar4 = (uVar4 << bVar6 | uVar4 >> 0x20 - bVar6) ^ (uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^
			uVar4;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		iVar11 = (uVar4 << (((byte)(0xf << bVar7) | (byte)(0xf >> 0x20 - bVar7)) & 0x1e | 1)) + uVar4;
		uVar4 = iVar11 * -0xf;
		uVar4 = (iVar11 * -0x3c00000 | uVar4 >> 10) ^ (uVar4 >> 5 | iVar11 * -0x78000000) ^ uVar4;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = (bVar7 ^ 0xc) & 0x1e | 1;
		bVar7 = ~bVar7 & 0x1e | 1;
		uVar4 = (uVar4 << bVar6 | uVar4 >> 0x20 - bVar6) ^ (uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^
			uVar4;
		uVar8 = uVar4 >> 0x12 & 0xff;
		/*
		puVar9 = (undefined8*)(uVar8 * 0x10 + *(int*)(unaff_EBP + -0x5c));
		puVar9[10] = puVar9[4];
		*(undefined4*)(puVar9 + 0xb) = *(undefined4*)(puVar9 + 5);
		*(undefined4*)((int)puVar9 + 0x5c) = *(undefined4*)((int)puVar9 + 0x2c);
		puVar9[8] = puVar9[2];
		*(undefined4*)(puVar9 + 9) = *(undefined4*)(puVar9 + 3);
		*(undefined4*)((int)puVar9 + 0x4c) = *(undefined4*)((int)puVar9 + 0x1c);
		puVar9[6] = *puVar9;
		*(undefined4*)(puVar9 + 7) = *(undefined4*)(puVar9 + 1);
		iVar11 = *(int*)(unaff_EBP + -0xa8);
		*(undefined4*)((int)puVar9 + 0x3c) = *(undefined4*)((int)puVar9 + 0xc);
		*(undefined8**)(iVar11 + 0x10) = puVar9 + 0xc;
		*(undefined4*)(*(int*)(iVar11 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//func_0x0045b73f(puVar9 + 6, uVar4 & 0x1ff);
		*/

		inst->OP = 33;
		inst->A = uVar8;
		inst->C = uVar4 & 0x1ff;
	}

	// OP_TFORLOOP 33 : A C 
	void d34cb(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char** ppcVar2;
		char* pcVar3;
		char cVar4;
		uint uVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		int uVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar11 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar11;
		uVar5 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar5;
		param_2 = param_2 << ((char)uVar11 - 4U & 0x1e | 1) ^ param_2;
		sVar6 = (sbyte)uVar5;
		bVar7 = ((byte)(0x19 << sVar6) | (byte)(0x19 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte)((-uVar11 & 1) << 4) | 1;
		bVar9 = (char)*(undefined4*)(unaff_EBP + -4) * '\x05' & 0x1eU | 1;
		uVar5 = ((param_2 >> bVar8 | param_2 << 0x20 - bVar8) ^
			(param_2 << bVar9 | param_2 >> 0x20 - bVar9) ^ param_2) + 0x2c546d5c;
		uVar5 = (uVar5 << bVar7 | uVar5 >> 0x20 - bVar7) ^ *(int*)(unaff_EBP + -4) + 0x165146fcU;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar5 = (uVar5 << (((byte)(9 << bVar7) | (byte)(9 >> 0x20 - bVar7)) & 0x1e | 1)) + uVar5;
		bVar7 = 7U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		bVar8 = 3U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		uVar5 = (uVar5 << bVar7 | uVar5 >> 0x20 - bVar7) ^ (uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^
			uVar5;
		uVar5 = (uVar5 >> 0x1d | uVar5 << 3) ^ (uVar5 >> 0x10 | uVar5 << 0x10) ^ uVar5;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar8 = (bVar7 ^ 0xf5) & 0x1e | 1;
		bVar7 = (bVar7 ^ 0xfb) & 0x1e | 1;
		uVar5 = (uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^ (uVar5 << bVar7 | uVar5 >> 0x20 - bVar7) ^
			uVar5;
		/*
		puVar10 = (undefined8*)((uVar5 >> 0x13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		puVar10[10] = puVar10[4];
		*(undefined4*)(puVar10 + 0xb) = *(undefined4*)(puVar10 + 5);
		*(undefined4*)((int)puVar10 + 0x5c) = *(undefined4*)((int)puVar10 + 0x2c);
		puVar10[8] = puVar10[2];
		*(undefined4*)(puVar10 + 9) = *(undefined4*)(puVar10 + 3);
		*(undefined4*)((int)puVar10 + 0x4c) = *(undefined4*)((int)puVar10 + 0x1c);
		puVar10[6] = *puVar10;
		*(undefined4*)(puVar10 + 7) = *(undefined4*)(puVar10 + 1);
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		*(undefined4*)((int)puVar10 + 0x3c) = *(undefined4*)((int)puVar10 + 0xc);
		*(undefined8**)(iVar1 + 0x10) = puVar10 + 0xc;
		*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		func_0x00458c8f(puVar10 + 6, uVar5 >> 1 & 0x1ff);
		*/

		inst->OP = 33;
		inst->A = (uVar5 >> 0x13 & 0xff);
		inst->C = uVar5 >> 1 & 0x1ff;
	}

	// OP_CLOSURE 36 : A Bx 
	void d2709(instr* inst, int param_1, int param_2) {

		char cVar1;
		uint* puVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		uVar8 = param_2 << 1 | (uint)(param_2 < 0);
		*(uint*)(unaff_EBP + -0x44) = uVar8;
		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar6 = (byte)iVar9;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		bVar3 = 0xf - bVar6 & 0x1e | 1;
		bVar4 = bVar6 + 10 & 0x1e | 1;
		bVar5 = bVar6 + 6 & 0x1e | 1;
		uVar8 = ((uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar5 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -0x44)) + 0x9a03f6a1;
		*(uint*)(unaff_EBP + -4) =
			(uVar8 >> 0x13 | uVar8 * 0x2000) ^ (uVar8 * 0x2000 | uVar8 >> 0x13) ^ uVar8;
		bVar6 = bVar6 & 0x1e | 1;
		uVar8 = *(uint*)(unaff_EBP + -4);
		bVar6 = ((byte)(0xc >> bVar6) | (byte)(0xc << 0x20 - bVar6)) & 0x1e | 1;
		uVar8 = (uVar8 >> 0x18 | uVar8 << 8) ^ (uVar8 >> 4 | uVar8 << 0x1c) ^ uVar8;
		uVar8 = uVar8 << bVar6 | uVar8 >> 0x20 - bVar6;
		cVar1 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar8 = (uVar8 << bVar3 | uVar8 >> 0x20 - bVar3) * 0x400001;
		bVar6 = cVar1 + 9U & 0x1e | 1;
		bVar3 = cVar1 + 1U & 0x1e | 1;
		uVar8 = (uVar8 >> bVar6 | uVar8 << 0x20 - bVar6) ^ (uVar8 << bVar3 | uVar8 >> 0x20 - bVar3) ^
			uVar8;
		/*
		*(uint*)(unaff_EBP + -0xc) = (uVar8 >> 0x17 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		puVar2 = (uint*)(*(int*)(unaff_EBP + -0x60) + 0x14);
		if (_DAT_10675940 == 0x111111) {
			uVar7 = *puVar2 - (int)puVar2;
			*(uint*)(unaff_EBP + -0x8c) = uVar7;
		}
		else if (_DAT_10675940 == 0x222222) {
			uVar7 = *puVar2 ^ (uint)puVar2;
			*(uint*)(unaff_EBP + -0x8c) = uVar7;
		}
		else if (_DAT_10675940 == 0x333333) {
			uVar7 = *puVar2 + (int)puVar2;
			*(uint*)(unaff_EBP + -0x8c) = uVar7;
		}
		else if (_DAT_10675940 == 0x444444) {
			uVar7 = (int)puVar2 - *puVar2;
			*(uint*)(unaff_EBP + -0x8c) = uVar7;
		}
		else {
			uVar7 = *(uint*)(unaff_EBP + -0x8c);
		}
		*(uint*)(unaff_EBP + -4) = (uint) * (byte*)(*(int*)(uVar7 + (uVar8 >> 5 & 0x3ffff) * 4) + 0x52);
		* */

		inst->OP = 36;
		inst->A = (uVar8 >> 0x17 & 0xff);
		inst->Bx = (uVar8 >> 5 & 0x3ffff);
	}

	// OP_SELF 11 : A B C
	void dbc27(instr* inst, int param_1, int param_2) {

		undefined4 uVar1;
		char* pcVar2;
		undefined4 uVar3;
		undefined4 uVar4;
		char cVar5;
		int iVar6;
		undefined8* puVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		//int unaff_EBP;
		uint uVar11;
		undefined8* puVar12;
		undefined8* puVar13;
		char* unaff_retaddr;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar6;
		bVar8 = (byte)iVar6 & 0x1e | 1;
		uVar10 = param_2 - (0xa846321U >> bVar8 | 0xa846321 << 0x20 - bVar8);
		*(uint*)(unaff_EBP + -0x44) = uVar10;
		uVar10 = ((uVar10 * 0x10000 | uVar10 >> 0x10) ^
			(*(uint*)(unaff_EBP + -0x44) >> 2 | *(uint*)(unaff_EBP + -0x44) << 0x1e) ^
			*(uint*)(unaff_EBP + -0x44)) + 0xd743147e;
		uVar11 = (uVar10 << (((byte)(3 >> bVar8) | (byte)(3 << 0x20 - bVar8)) & 0x1e | 1) ^ uVar10) +
			0xa512bd48;
		uVar10 = uVar11 >> 8;
		bVar8 = ((byte)(0x10 >> bVar8) | (byte)(0x10 << 0x20 - bVar8)) & 0x1e | 1;
		uVar10 = uVar10 << 0xe ^ (uVar11 * 0x1000000 | uVar10);
		cVar5 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar10 = (uVar10 >> bVar8 | uVar10 << 0x20 - bVar8) * 0x5e78ea69;
		bVar8 = 8U - cVar5 & 0x1e | 1;
		bVar9 = -cVar5 - 2U & 0x1e | 1;
		uVar10 = (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) ^ (uVar10 << bVar9 | uVar10 >> 0x20 - bVar9) ^
			uVar10;
		bVar8 = -cVar5 - 0xbU & 0x1e | 1;
		bVar9 = 2U - cVar5 & 0x1e | 1;
		uVar10 = (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) ^ (uVar10 << bVar9 | uVar10 >> 0x20 - bVar9) ^
			uVar10;
		uVar10 = ~((uVar10 >> 0x1c | uVar10 << 4) ^ (uVar10 << 1 | (uint)((int)uVar10 < 0)) ^ uVar10);
		uVar10 = (uVar10 << 0x17 | uVar10 >> 9) ^ (uVar10 >> 3 | uVar10 << 0x1d) ^ uVar10;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		//puVar13 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//uVar1 = *(undefined4*)((int)puVar13 + 4);
		//uVar3 = *(undefined4*)(puVar13 + 1);
		//uVar4 = *(undefined4*)((int)puVar13 + 0xc);
		//puVar12 = (undefined8*)((uVar10 >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 11;
		inst->A = (uVar10 >> 9 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = *(uint*)(unaff_EBP + -0xc) >> 0x11;
	}

	// OP_LOADBOOL 2 : A B C
	void d3619(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		uint uVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		int uVar8;
		//int unaff_EBP;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0x50) = uVar8;
		param_2 = (param_2 >> 0x1e | param_2 << 2) ^ (param_2 >> 9 | param_2 << 0x17) ^ param_2;
		uVar3 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar3;
		sVar5 = (sbyte)uVar3;
		bVar6 = (byte)((-uVar8 & 7) << 2) | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar3 = ((param_2 -
			(param_2 << (((byte)(0x13 << sVar5) | (byte)(0x13 >> 0x20 - sVar5)) & 0x1e | 1))) -
			(0x72db05c1 << bVar7 | 0x72db05c1U >> 0x20 - bVar7)) * 0x15ab3e87 ^ 0x38db9952;
		bVar7 = (byte) * (int*)(unaff_EBP + -0x50);
		uVar3 = (uVar3 << bVar6 | uVar3 >> 0x20 - bVar6) + *(int*)(unaff_EBP + -0x50) * 0xb9f476c;
		uVar3 = uVar3 >> ((bVar7 ^ 8) & 0x1e | 1) ^ uVar3;
		uVar3 = (uVar3 << 0xe | uVar3 >> 0x12) ^ (uVar3 << 3 | uVar3 >> 0x1d) ^ uVar3;
		uVar3 = (uVar3 << 0x19 | uVar3 >> 7) ^ (uVar3 >> 5 | uVar3 << 0x1b) ^ uVar3;
		uVar3 = uVar3 << (-bVar7 - 7 & 0x1e | 1) ^ uVar3;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar6 = ((byte)(0xc << bVar7) | (byte)(0xc >> 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar7 = ((byte)(2 << bVar7) | (byte)(2 >> 0x20 - bVar7)) & 0x1e | 1;
		uVar3 = (uVar3 >> bVar6 | uVar3 << 0x20 - bVar6) ^ (uVar3 >> bVar7 | uVar3 << 0x20 - bVar7) ^
			uVar3;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar3 = (uVar3 << 8 | uVar3 >> 0x18) * 0x2056a1b1;
		*(uint*)(unaff_EBP + -0x50) = uVar3;
		//pcVar4 = (char*)(uVar3 >> 0x16 & 0x1ff);
		//*(char**)(iVar1 + (uVar3 & 0xff) * 0x10) = pcVar4;
		//*(undefined4*)(iVar1 + 0xc + (uVar3 & 0xff) * 0x10) = 1;

		inst->OP = 2;
		inst->A = (uVar3 & 0xff);
		inst->B = (uVar3 >> 0x16 & 0x1ff);
		inst->C = (uVar3 & 0x3fe000) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void d5fa6(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		uint* puVar9;
		uint* puVar10;
		//int unaff_EBP;
		uint uVar11;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		bVar4 = 10U - (char)uVar8 & 0x1e | 1;
		uVar11 = param_2 * -0x6a849e71 + 0x532dac07U ^ 0x44dbe123;
		uVar8 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar8;
		sVar5 = (sbyte)uVar8;
		bVar6 = ((byte)(8 << sVar5) | (byte)(8 >> 0x20 - sVar5)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) =
			(uVar11 << 9 | uVar11 >> 0x17) ^ (uVar11 << 3 | uVar11 >> 0x1d) ^
			0x628c7e6U - *(int*)(unaff_EBP + -0xc) ^ uVar11;
		uVar8 = (*(uint*)(unaff_EBP + -0x1c) >> bVar6 | *(uint*)(unaff_EBP + -0x1c) << 0x20 - bVar6) +
			0xa10c6334;
		uVar8 = uVar8 << bVar4 | uVar8 >> 0x20 - bVar4;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar4 = bVar6 & 0x1f;
		bVar4 = ((byte)(0x17 << bVar4) | (byte)(0x17 >> 0x20 - bVar4)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar8 << bVar4 | uVar8 >> 0x20 - bVar4;
		bVar6 = bVar6 & 0x1f;
		bVar4 = ((byte)(0x10 << bVar6) | (byte)(0x10 >> 0x20 - bVar6)) & 0x1e | 1;
		uVar8 = *(uint*)(unaff_EBP + -4) ^ (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^ uVar8;
		bVar4 = (byte) * (int*)(unaff_EBP + -0xc);
		bVar6 = (bVar4 ^ 8) & 0x1e | 1;
		bVar4 = bVar4 * '\x0e' & 0x1e | 1;
		bVar7 = (byte)((-*(int*)(unaff_EBP + -0xc) & 7U) << 2) | 1;
		*(uint*)(unaff_EBP + -0x50) = uVar8 >> bVar4 | uVar8 << 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0x50) =
			*(uint*)(unaff_EBP + -0x50) ^ (uVar8 << bVar7 | uVar8 >> 0x20 - bVar7);
		uVar8 = *(uint*)(unaff_EBP + -0x50) ^ uVar8;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar8 = uVar8 >> bVar6 | uVar8 << 0x20 - bVar6;
		*(uint*)(unaff_EBP + -0x50) = uVar8;
		//*(uint*)(iVar1 + (uVar8 & 0xff) * 0x10) = uVar8 >> 8 & 0x1ff;
		//*(undefined4*)(iVar1 + 0xc + (uVar8 & 0xff) * 0x10) = 1;
		//puVar9 = (uint*)((-(uint)((*(uint*)(unaff_EBP + -0x50) & 0x7fc00000) != 0) & 8) + 4 +
		//	*(int*)(unaff_EBP + -0x4c));

		inst->OP = 2;
		inst->A = (uVar8 & 0xff);
		inst->B = uVar8 >> 8 & 0x1ff;
		inst->C = (*(uint*)(unaff_EBP + -0x50) & 0x7fc00000) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void d735b(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		char* pcVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint* puVar8;
		uint* puVar9;
		uint uVar10;
		int iVar11;
		//int unaff_EBP;

		uVar7 = *(uint*)(unaff_EBP + -0x44) ^ 0x201e2f19;
		uVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		uVar7 = (uVar7 << 0x15 | uVar7 >> 0xb) ^ (uVar7 << 0xc | uVar7 >> 0x14) ^ uVar7;
		uVar2 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar2;
		sVar4 = (sbyte)uVar2;
		bVar5 = ((byte)(3 >> sVar4) | (byte)(3 << 0x20 - sVar4)) & 0x1e | 1;
		bVar6 = 2U - (char)uVar10 & 0x1e | 1;
		uVar7 = (uVar7 >> 0xe | uVar7 << 0x12) ^ (uVar7 << 9 | uVar7 >> 0x17) ^ uVar7;
		uVar2 = uVar7 >> bVar6 | uVar7 << 0x20 - bVar6;
		uVar2 = ((uVar2 >> bVar5 | uVar2 << 0x20 - bVar5) * 0x50a57db9 + 0x36f1fb75) * -3;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(0x1e >> bVar5) | (byte)(0x1e << 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(0x1a >> bVar5) | (byte)(0x1a << 0x20 - bVar5)) & 0x1e | 1;
		uVar2 = (uVar2 << bVar6 | uVar2 >> 0x20 - bVar6) ^ (uVar2 << bVar5 | uVar2 >> 0x20 - bVar5) ^
			uVar2;
		uVar7 = uVar2 << 0x17 ^ uVar2;
		uVar7 = (uVar7 >> 0x17 | uVar2 << 9) ^ (uVar7 >> 0xc | uVar2 << 0x14) ^ uVar7;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = (byte) * (int*)(unaff_EBP + -0xc);
		uVar2 = ((uVar7 >> 4 ^ uVar7) + *(int*)(unaff_EBP + -0xc) * 0x16ca94fb) -
			(0x4f78b15f << bVar5 | 0x4f78b15fU >> 0x20 - bVar5);
		iVar11 = (uVar2 << (-bVar6 - 2 & 0x1e | 1) ^ uVar2) + 0xbae5abc;
		uVar2 = (iVar11 << ((bVar6 ^ 6) & 0x1e | 1)) + iVar11;
		uVar7 = ~(uVar2 >> ((bVar6 ^ 0xe) & 0x1e | 1) ^ uVar2);
		uVar2 = uVar7 >> 9 & 0xff;
		//puVar8 = (uint*)(uVar2 * 2);
		//iVar11 = *(int*)(unaff_EBP + -0x5c);
		//*(uint*)(iVar11 + uVar2 * 0x10) = uVar7 >> 0x15 & 0x1ff;
		//*(undefined4*)(iVar11 + 0xc + uVar2 * 0x10) = 1;
		//if ((uVar7 & 0x1ff) != 0) {

		inst->OP = 2;
		inst->A = uVar2;
		inst->B = uVar7 >> 0x15 & 0x1ff;
		inst->C = (uVar7 & 0x1ff) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void d7f13(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		uint uVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint* puVar9;
		uint* puVar10;
		//int unaff_EBP;
		uint uVar11;

		uVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar11 = ~(*(int*)(unaff_EBP + -0x44) << 0xc ^ *(uint*)(unaff_EBP + -0x44));
		*(uint*)(unaff_EBP + -0xc) = uVar3;
		uVar3 = uVar3 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar3;
		sVar5 = (sbyte)uVar3;
		bVar6 = ((byte)(0x11 >> sVar5) | (byte)(0x11 << 0x20 - sVar5)) & 0x1e | 1;
		uVar3 = uVar11 >> bVar6 | uVar11 << 0x20 - bVar6;
		bVar7 = ((byte)(0x1e << sVar5) | (byte)(0x1e >> 0x20 - sVar5)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(7 << bVar6) | (byte)(7 >> 0x20 - bVar6)) & 0x1e | 1;
		bVar8 = 0xdU - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar3 = (~((uVar3 >> bVar7 | uVar3 << 0x20 - bVar7) ^ (uVar3 << bVar6 | uVar3 >> 0x20 - bVar6) ^
			uVar3) * -0x3ffff - *(int*)(unaff_EBP + -0xc)) + 0xe01335ab;
		uVar3 = (uVar3 >> bVar8 | uVar3 << 0x20 - bVar8) + 0x89477e2;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0x15 << bVar6) | (byte)(0x15 >> 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(10 << bVar6) | (byte)(10 >> 0x20 - bVar6)) & 0x1e | 1;
		uVar3 = (uVar3 >> bVar7 | uVar3 << 0x20 - bVar7) ^ (uVar3 << bVar6 | uVar3 >> 0x20 - bVar6) ^
			uVar3;
		uVar11 = uVar3 >> 0x16 | uVar3 << 10;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar7 = (bVar6 ^ 0xe) & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xf3) & 0x1e | 1;
		uVar11 = (uVar11 << bVar7 | uVar11 >> 0x20 - bVar7) ^ (uVar11 >> bVar6 | uVar11 << 0x20 - bVar6) ^
			uVar11;
		uVar3 = uVar11 >> 9 & 0xff;
		puVar9 = (uint*)(uVar3 * 2);
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		//*(uint*)(iVar1 + uVar3 * 0x10) = uVar11 >> 0x11 & 0x1ff;
		//*(undefined4*)(iVar1 + 0xc + uVar3 * 0x10) = 1;
		//if ((uVar11 & 0x1ff) != 0) {
		//	puVar9 = (uint*)(*(int*)(unaff_EBP + -0x24) + 0xc);
		//}

		inst->OP = 2;
		inst->A = uVar3;
		inst->B = uVar11 >> 0x11 & 0x1ff;
		inst->C = (uVar11 & 0x1ff) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void da0b0(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint* puVar6;
		uint* puVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;

		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar5 = (byte)iVar10;
		bVar3 = bVar5 & 0x1e | 1;
		bVar4 = (bVar5 ^ 0xf5) & 0x1e | 1;
		uVar8 = ((0x2d566fd7U >> bVar3 | 0x2d566fd7 << 0x20 - bVar3) ^ iVar10 * 0x566882d1 ^
			*(uint*)(unaff_EBP + -0x44)) * 0x5a2a9c11 + 0x3bf47f6a;
		bVar3 = ~bVar5 & 0x1e | 1;
		uVar8 = (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^ (uVar8 >> bVar3 | uVar8 << 0x20 - bVar3) ^
			uVar8;
		uVar8 = (uVar8 >> 0x16 | uVar8 << 10) ^ (uVar8 >> 0xd | uVar8 << 0x13) ^ uVar8;
		bVar5 = bVar5 * -0xb & 0x1e | 1;
		uVar9 = uVar8 << bVar5 | uVar8 >> 0x20 - bVar5;
		uVar8 = uVar9 << 1;
		uVar9 = uVar8 | (int)uVar9 < 0;
		uVar9 = (uVar8 >> 0x14 | uVar9 << 0xc) ^ (uVar9 << 4 | uVar8 >> 0x1c) ^ uVar9;
		uVar8 = uVar9 >> 0x12 & 0xff;
		puVar6 = (uint*)(uVar8 * 2);
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		//*(uint*)(iVar10 + uVar8 * 0x10) = uVar9 >> 9 & 0x1ff;
		//*(undefined4*)(iVar10 + 0xc + uVar8 * 0x10) = 1;
		//if ((uVar9 & 0x1ff) != 0) {
		//	puVar6 = (uint*)(*(int*)(unaff_EBP + -0x24) + 0xc);
		//}

		inst->OP = 2;
		inst->A = uVar8;
		inst->B = uVar9 >> 9 & 0x1ff;
		inst->C = (uVar9 & 0x1ff) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void dbad2(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint* puVar7;
		uint* puVar8;
		int iVar9;
		//int unaff_EBP;
		uint uVar10;
		int iVar11;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		iVar11 = *(int*)(unaff_EBP + -0x44) + iVar9 * -0x468c522f;
		uVar10 = (iVar11 << ((byte)iVar9 * -0x10 & 0x1e | 1)) + iVar11;
		bVar3 = (byte)iVar9 & 0x1e | 1;
		uVar10 = uVar10 >> (((byte)(9 >> bVar3) | (byte)(9 << 0x20 - bVar3)) & 0x1e | 1) ^ uVar10;
		uVar6 = uVar10 >> 6;
		uVar10 = uVar10 << 0x1a | uVar6;
		uVar10 = (uVar6 << 0x17 | uVar10 >> 9) ^ (uVar10 >> 0xd | uVar6 << 0x13) ^ uVar10;
		uVar10 = uVar10 << (((byte)(0x13 >> bVar3) | (byte)(0x13 << 0x20 - bVar3)) & 0x1e | 1) ^ uVar10;
		bVar4 = 8U - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		bVar5 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 4U & 0x1e | 1;
		uVar10 = ((((uVar10 << bVar4 | uVar10 >> 0x20 - bVar4) ^
			(uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^ uVar10) - *(int*)(unaff_EBP + -0xc)) -
			(0x7296f22c << bVar3 | 0x7296f22cU >> 0x20 - bVar3)) + 0x54b7b49c ^
			*(uint*)(unaff_EBP + -0xc) ^ 0x8f365b7;
		uVar10 = uVar10 >> 2 ^ uVar10 >> 3 ^ uVar10;
		uVar6 = uVar10 >> 0x14 & 0xff;
		puVar7 = (uint*)(uVar6 * 2);
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		//*(uint*)(iVar9 + uVar6 * 0x10) = uVar10 >> 2 & 0x1ff;
		//*(undefined4*)(iVar9 + 0xc + uVar6 * 0x10) = 1;
		//if ((uVar10 & 0xff800) != 0) {
		//	puVar7 = (uint*)(*(int*)(unaff_EBP + -0x24) + 0xc);
		//}

		inst->OP = 2;
		inst->A = uVar6;
		inst->B = uVar10 >> 2 & 0x1ff;
		inst->C = (uVar10 & 0xff800) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void de49f(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		byte bVar2;
		char cVar3;
		char* pcVar4;
		uint uVar5;
		uint* puVar6;
		uint* puVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)iVar9;
		uVar8 = param_2 << ((bVar2 ^ 8) & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44);
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar8 = ((uVar8 << 0xb | uVar8 >> 0x15) ^ (uVar8 >> 5 | uVar8 << 0x1b) ^ uVar8) + 0x8f603936 ^
			0x52f9fdff;
		uVar8 = (iVar9 * 0x20cb1b2 + (uVar8 >> (1 - bVar2 & 0x1e | 1) ^ uVar8) + 0x32b646a0) * 9;
		uVar5 = uVar8 >> 9 & 0xff;
		//puVar6 = (uint*)(uVar5 * 2);
		//*(uint*)(iVar1 + uVar5 * 0x10) = uVar8 & 0x1ff;
		//*(undefined4*)(iVar1 + 0xc + uVar5 * 0x10) = 1;
		//if ((uVar8 & 0x3fe0000) != 0) {
		//	puVar6 = (uint*)(*(int*)(unaff_EBP + -0x24) + 0xc);
		//}

		inst->OP = 2;
		inst->A = uVar5;
		inst->B = uVar8 & 0x1ff;
		inst->C = (uVar8 & 0x3fe0000) != 0 ? 1 : 0;
	}

	// OP_LOADBOOL 2 : A B C
	void deb58(instr* inst, uint param_1, uint param_2) {

		byte bVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		uint* puVar6;
		uint* puVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;

		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar1 = (byte)iVar10;
		bVar4 = bVar1 * '\b' & 0x1e | 1;
		uVar8 = param_2 << bVar4 | param_2 >> 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0x44) = uVar8;
		bVar4 = (byte)((-iVar10 & 1U) << 4) | 1;
		bVar5 = bVar1 * '\x03' & 0x1e | 1;
		uVar8 = (uVar8 >> bVar4 | uVar8 << 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar5 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar5) ^
			iVar10 + 0x4cfbf09U ^ *(uint*)(unaff_EBP + -0x44);
		uVar8 = ~(uVar8 >> 0x1a | uVar8 << 6);
		uVar8 = (uVar8 >> 0x11 | uVar8 << 0xf) ^ (uVar8 >> 8 | uVar8 << 0x18) ^ uVar8;
		bVar4 = (bVar1 ^ 8) & 0x1e | 1;
		uVar8 = uVar8 >> (bVar1 + 2 & 0x1e | 1) ^ uVar8;
		uVar8 = (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^ 0x702631e8;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = (uVar8 << (bVar1 * -4 & 0x1e | 1) ^ uVar8) * 0x62c51711;
		uVar8 = uVar9 >> 4 & 0xff;
		//puVar6 = (uint*)(uVar8 * 2);
		//*(uint*)(iVar10 + uVar8 * 0x10) = uVar9 >> 0xc & 0x1ff;
		//*(undefined4*)(iVar10 + 0xc + uVar8 * 0x10) = 1;
		//if ((uVar9 & 0x3fe00000) == 0) {
		//	puVar6 = *(uint**)(unaff_EBP + -0x50);
		//}

		inst->OP = 2;
		inst->A = uVar8;
		inst->B = uVar9 >> 0xc & 0x1ff;
		inst->C = (uVar9 & 0x3fe00000) != 0 ? 1 : 0;
	}

	// OP_LOADNIL 3 : A B 
	void d5e7f(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		byte bVar2;
		byte bVar3;
		byte bVar4;
		sbyte sVar5;
		int iVar6;
		//int unaff_EBP;
		uint uVar7;
		uint uVar8;

		uVar7 = ~*(uint*)(unaff_EBP + -0x44);
		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar6;
		bVar4 = (byte)iVar6;
		bVar2 = (bVar4 ^ 0xf9) & 0x1e | 1;
		bVar3 = (bVar4 ^ 0xfd) & 0x1e | 1;
		uVar7 = (uVar7 >> bVar2 | uVar7 << 0x20 - bVar2) ^ (uVar7 >> bVar3 | uVar7 << 0x20 - bVar3) ^
			uVar7;
		bVar4 = bVar4 * -7 & 0x1e | 1;
		uVar8 = iVar6 * 9 & 0x1eU | 1;
		*(uint*)(unaff_EBP + -4) = uVar8;
		sVar5 = (sbyte)uVar8;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 >> sVar5 | uVar7 << 0x20 - sVar5) ^
			uVar7;
		uVar7 = (uVar7 << 0x1b | uVar7 >> 5) ^ (uVar7 << 4 | uVar7 >> 0x1c) ^ uVar7;
		uVar7 = uVar7 >> (0xfU - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1) ^ uVar7;
		*(uint*)(unaff_EBP + -0x1c) = uVar7;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		bVar3 = ((byte)(0x1b << bVar4) | (byte)(0x1b >> 0x20 - bVar4)) & 0x1e | 1;
		bVar4 = ((byte)(0xd << bVar4) | (byte)(0xd >> 0x20 - bVar4)) & 0x1e | 1;
		bVar2 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar7 = (uVar7 >> bVar3 | uVar7 << 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x1c) >> bVar4 | *(uint*)(unaff_EBP + -0x1c) << 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x1c);
		bVar3 = bVar2 * '\v' & 0x1e | 1;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar7 = (uVar7 >> bVar3 | uVar7 << 0x20 - bVar3) ^ (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^
			uVar7;
		uVar7 = uVar7 << 0x1c | uVar7 >> 4;
		iVar6 = *(int*)(unaff_EBP + -0x5c);
		uVar7 = uVar7 - (uVar7 << ((bVar2 ^ 0xf3) & 0x1e | 1));
		uVar7 = ((uVar7 >> 0x11 | uVar7 * 0x8000) ^ (uVar7 * 0x20 | uVar7 >> 0x1b) ^ uVar7) + 0x79563f22;
		uVar7 = (uVar7 * 0x100000 | uVar7 >> 0xc) ^ uVar7 >> 3 ^ uVar7;
		//uVar8 = (uVar7 >> 9 & 0x1ff) * 0x10 + iVar6;

		inst->OP = 3;
		inst->A = (uVar7 >> 0x14 & 0xff);
		inst->B = (uVar7 >> 9 & 0x1ff);
	}

	// OP_LOADNIL 3 : A B 
	void d6442(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		code* pcVar2;
		byte bVar3;
		uint uVar4;
		byte bVar5;
		//int unaff_EBP;
		int iVar6;
		uint uVar7;

		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar4 = uVar7 ^ param_2 ^ 0x3f669060;
		bVar3 = (byte)uVar7;
		uVar4 = uVar4 << 7 ^ uVar4;
		uVar4 = uVar4 >> (bVar3 * '\f' & 0x1e | 1) ^ uVar4;
		bVar5 = bVar3 & 0x1e | 1;
		uVar4 = (uVar4 << ((bVar3 ^ 6) & 0x1e | 1)) + uVar4;
		iVar6 = (uVar4 >> 0x15 | uVar4 * 0x800) * 0x10001;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar4 = ((iVar6 << (((byte)(10 << bVar5) | (byte)(10 >> 0x20 - bVar5)) & 0x1e | 1)) + iVar6) *
			0x17b912ed + (0x2628376bU >> bVar5 | 0x2628376b << 0x20 - bVar5);
		uVar4 = (uVar4 * 0x400000 | uVar4 >> 10) ^ (uVar4 * 0x20 | uVar4 >> 0x1b) ^ uVar4;
		uVar4 = (uVar4 >> 0x18 | uVar4 << 8) ^ uVar4 >> 4 ^ uVar4;
		uVar7 = (uVar4 >> 0xc & 0x1ff) * 0x10 + iVar1;
		//do {
		//	*(undefined4*)(uVar7 + 0xc) = 0;
		//	uVar7 = uVar7 - 0x10;
		//} while ((uVar4 >> 4 & 0xff) * 0x10 + iVar1 <= uVar7);

		inst->OP = 3;
		inst->A = (uVar4 >> 4 & 0xff);
		inst->B = (uVar4 >> 0xc & 0x1ff);
	}

	// OP_LOADNIL 3 : A B 
	void dad24(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		char* pcVar6;
		int iVar7;
		//int unaff_EBP;
		uint uVar8;

		uVar8 = *(uint*)(unaff_EBP + -0x44);
		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar7;
		bVar5 = (byte)iVar7;
		bVar3 = (bVar5 ^ 8) & 0x1e | 1;
		bVar4 = (bVar5 ^ 0xfd) & 0x1e | 1;
		uVar8 = (uVar8 >> bVar3 | uVar8 << 0x20 - bVar3) ^ (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^
			uVar8;
		bVar5 = bVar5 & 0x1e | 1;
		uVar8 = (uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^ (uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^
			uVar8;
		uVar8 = ((uVar8 >> 0x1c | uVar8 << 4) ^ (uVar8 << 6 | uVar8 >> 0x1a) ^ uVar8) * 0x7f1bd9d9 +
			(0x5ef42691U >> bVar5 | 0x5ef42691 << 0x20 - bVar5);
		bVar3 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xf1) & 0x1e | 1;
		uVar8 = uVar8 * 0x1000000 ^ uVar8;
		uVar8 = (uVar8 >> bVar3 | uVar8 << 0x20 - bVar3) ^ (uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^
			uVar8;
		bVar5 = (byte)((*(int*)(unaff_EBP + -0xc) * -3 & 7U) << 2) | 1;
		cVar1 = (char)*(int*)(unaff_EBP + -0xc);
		bVar3 = cVar1 * '\x05' & 0x1eU | 1;
		uVar8 = (uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^ (uVar8 >> bVar3 | uVar8 << 0x20 - bVar3) ^
			uVar8;
		bVar5 = -cVar1 - 0xeU & 0x1e | 1;
		bVar3 = -cVar1 - 6U & 0x1e | 1;
		uVar8 = ((uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^ (uVar8 << bVar3 | uVar8 >> 0x20 - bVar3) ^
			uVar8) * 0x2081ceaf;
		//pcVar2 = (char*)((uVar8 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//pcVar6 = (char*)((uVar8 >> 9 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 3;
		inst->A = (uVar8 >> 0x12 & 0xff);
		inst->B = (uVar8 >> 9 & 0x1ff);
	}

	// OP_LOADNIL 3 : A B 
	void dbae9(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		char* pcVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;

		uVar6 = (param_2 >> 2 | param_2 << 0x1e) * 0x77025679;
		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar3 = (byte)((-iVar7 & 3U) << 3) | 1;
		bVar4 = (byte)iVar7 * -7 & 0x1e | 1;
		uVar6 = (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^ (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
			uVar6;
		uVar6 = ((uVar6 << 0x1e | uVar6 >> 2) ^ (uVar6 >> 4 | uVar6 << 0x1c) ^ uVar6) * 0x56460b57 ^
			iVar7 + 0x563a576aU;
		bVar3 = (byte)iVar7 & 0x1e | 1;
		uVar6 = (((uVar6 >> 0x16 | uVar6 << 10) + (-0x37f19b46 - iVar7) ^ 0x4f9da3f) * 0x4000001 -
			(0x36dcff2f << bVar3 | 0x36dcff2fU >> 0x20 - bVar3)) + 0x8514da58;
		//pcVar2 = (char*)((uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//pcVar5 = (char*)((uVar6 >> 8 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 3;
		inst->A = (uVar6 & 0xff);
		inst->B = (uVar6 >> 8 & 0x1ff);
	}

	// OP_LOADNIL 3 : A B 
	void dded8(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		char* pcVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar8 = param_2 + 0x641c01d3 + iVar9;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		uVar2 = uVar8 * 0x4000;
		uVar8 = uVar8 >> 0x12 | uVar2;
		uVar2 = ((uVar8 << 0xd | uVar2 >> 0x13) ^ (uVar8 << 0x11 | uVar2 >> 0xf) ^ uVar8) + 0x21d7ffd7 +
			iVar9;
		bVar4 = (char)iVar9 * -10 & 0x1eU | 1;
		uVar2 = ~(uVar2 >> 0x19 ^ uVar2);
		uVar2 = uVar2 >> 0xc | uVar2 << 0x14;
		bVar5 = (char)iVar9 * '\x02' & 0x1eU | 1;
		uVar2 = (uVar2 >> bVar4 | uVar2 << 0x20 - bVar4) ^ (uVar2 << bVar5 | uVar2 >> 0x20 - bVar5) ^
			uVar2;
		cVar1 = (char)*(int*)(unaff_EBP + -0xc);
		uVar2 = (uVar2 << 0x18 | uVar2 >> 8) ^ (uVar2 << 0x14 | uVar2 >> 0xc) ^ uVar2;
		bVar4 = 8U - cVar1 & 0x1e | 1;
		bVar5 = -cVar1 - 4U & 0x1e | 1;
		bVar6 = (byte)((*(int*)(unaff_EBP + -0xc) * -3 & 7U) << 2) | 1;
		uVar2 = (uVar2 << bVar4 | uVar2 >> 0x20 - bVar4) ^ (uVar2 >> bVar5 | uVar2 << 0x20 - bVar5) ^
			uVar2;
		uVar2 = uVar2 >> 10 | uVar2 << 0x16;
		uVar2 = uVar2 >> bVar6 | uVar2 << 0x20 - bVar6;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar2 = (uVar2 << ((bVar4 ^ 0xf9) & 0x1e | 1)) + uVar2;
		bVar5 = bVar4 + 9 & 0x1e | 1;
		bVar4 = bVar4 - 4 & 0x1e | 1;
		uVar2 = (uVar2 << bVar5 | uVar2 >> 0x20 - bVar5) ^ (uVar2 << bVar4 | uVar2 >> 0x20 - bVar4) ^
			uVar2;
		uVar2 = (uVar2 << 2 | uVar2 >> 0x1e) ^ uVar2 >> 1 ^ uVar2;
		//pcVar3 = (char*)((uVar2 >> 0xb & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//pcVar7 = (char*)((uVar2 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 3;
		inst->A = (uVar2 >> 0xb & 0xff);
		inst->B = (uVar2 & 0x1ff);
	}

	// OP_LOADNIL 3 : A B 
	void df546(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		char* pcVar7;
		//int unaff_EBP;
		int iVar8;

		uVar6 = param_2 >> 0xc ^ *(uint*)(unaff_EBP + -0x44);
		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar8;
		bVar4 = (byte)iVar8;
		bVar3 = bVar4 & 0x1e | 1;
		uVar6 = uVar6 << (((byte)(0x1c >> bVar3) | (byte)(0x1c << 0x20 - bVar3)) & 0x1e | 1) ^ uVar6;
		uVar6 = uVar6 << 9 | uVar6 >> 0x17;
		bVar3 = -bVar4 - 0xc & 0x1e | 1;
		bVar4 = 10 - bVar4 & 0x1e | 1;
		uVar6 = (uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^ (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
			uVar6;
		uVar6 = uVar6 >> 5 ^ uVar6;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar6 = (uVar6 << 0x14 | uVar6 >> 0xc) ^ (uVar6 << 10 | uVar6 >> 0x16) ^ uVar6 ^ 0x7de78761;
		bVar3 = (bVar4 ^ 10) & 0x1e | 1;
		bVar5 = 1 - bVar4 & 0x1e | 1;
		bVar4 = (bVar4 ^ 0xf7) & 0x1e | 1;
		uVar6 = (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^ (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^
			uVar6;
		iVar8 = (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) * 0x100001;
		uVar6 = (iVar8 << (-(char)*(undefined4*)(unaff_EBP + -0xc) - 5U & 0x1e | 1)) + iVar8;
		//pcVar2 = (char*)((uVar6 >> 3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//pcVar7 = (char*)((uVar6 >> 0x14 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 3;
		inst->A = (uVar6 >> 3 & 0xff);
		inst->B = (uVar6 >> 0x14 & 0x1ff);
	}

	// OP_LOADNIL 3 : A B 
	void dfe4d(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		char cVar2;
		char* pcVar3;
		uint uVar4;
		char* pcVar5;
		//int unaff_EBP;
		int unaff_EDI;

		uVar4 = ~((~(((param_2 >> 0xd | param_2 << 0x13) ^ (param_2 >> 4 | param_2 << 0x1c) ^ param_2 ^
			0x1f965207) + 0x68e8a48e) -
			((*(int*)(unaff_EBP + -0x50) - *(int*)(unaff_EBP + -100)) + -8 >> 2)) + 0x24126458);
		uVar1 = uVar4 * -0x73886e65 >> 0x13;
		uVar4 = uVar4 * -0xdcca000 | uVar1;
		uVar4 = (uVar1 << 0x18 | uVar4 >> 8) ^ uVar4 << 5 ^ uVar4;
		//pcVar3 = (char*)((uVar4 >> 0xf & 0xff) * 0x10 + unaff_EDI);
		//pcVar5 = (char*)((uVar4 >> 0x17) * 0x10 + unaff_EDI);

		inst->OP = 3;
		inst->A = (uVar4 >> 0xf & 0xff);
		inst->B = (uVar4 >> 0x17);
	}

	// OP_GETUPVAL 4 : A B 
	void d2245(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char* pcVar2;
		byte bVar3;
		uint uVar4;
		char cVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;
		int iVar11;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar10 = (param_2 << 0xd | param_2 >> 0x13) ^
			(*(uint*)(unaff_EBP + -0x44) << 10 | *(uint*)(unaff_EBP + -0x44) >> 0x16) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar3 = (byte)iVar11;
		bVar6 = bVar3 - 3 & 0x1e | 1;
		uVar10 = (uVar10 << (7 - bVar3 & 0x1e | 1)) + uVar10 + 0xbfec9317 + iVar11;
		bVar7 = bVar3 - 2 & 0x1e | 1;
		bVar8 = bVar3 * '\x06' & 0x1e | 1;
		uVar10 = ((uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7)
			^ uVar10) + 0x3498864a + iVar11;
		bVar6 = bVar3 * '\x05' & 0x1e | 1;
		uVar10 = (uVar10 >> bVar8 | uVar10 << 0x20 - bVar8) ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^
			uVar10;
		uVar10 = uVar10 >> 9 | uVar10 << 0x17;
		uVar10 = ((uVar10 << ((bVar3 ^ 0xf1) & 0x1e | 1)) + 0x626a82bb + uVar10) * 0x628ecbd1;
		uVar10 = uVar10 >> (5 - bVar3 & 0x1e | 1) ^ uVar10;
		uVar9 = ((uVar10 >> 0x10 | uVar10 << 0x10) ^ (uVar10 >> 5 | uVar10 << 0x1b) ^ uVar10) + 0x79555543
			+ iVar11;
		uVar10 = uVar9 >> 0x11;
		uVar4 = uVar10 & 0xff;
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 +
		//		((uVar9 * 0x8000 | uVar10) >> 8 & 0x1ff) * 0x10) + 4);

		inst->OP = 4;
		inst->A = uVar4;
		inst->B = (uVar9 * 0x8000 | uVar10) >> 8 & 0x1ff;
	}

	// OP_GETUPVAL 4 : A B 
	void d236a(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char* pcVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		bVar5 = (byte)iVar9;
		bVar4 = bVar5 & 0x1e | 1;
		uVar7 = param_2 << (((byte)(2 << bVar4) | (byte)(2 >> 0x20 - bVar4)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = (uVar7 >> 0x18 | uVar7 << 8) ^ (uVar7 >> 1 | (uint)((uVar7 & 1) != 0) << 0x1f) ^ uVar7;
		uVar7 = (uVar7 << 0x16 | uVar7 >> 10) ^ (uVar7 << 0xe | uVar7 >> 0x12) ^ uVar7;
		bVar5 = bVar5 - 5 & 0x1e | 1;
		bVar6 = (char)*(undefined4*)(unaff_EBP + -0xc) + 3U & 0x1e | 1;
		uVar7 = ((uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^
			(0x1aab999c << bVar4 | 0x1aab999cU >> 0x20 - bVar4) ^ uVar7 ^ 0x9ddc8079) + 0xb0c40a8c;
		bVar5 = (byte) * (uint*)(unaff_EBP + -0xc);
		uVar7 = (0x465fda12U >> bVar4 | 0x465fda12 << 0x20 - bVar4) ^ (uVar7 * 0x10000 | uVar7 >> 0x10) ^
			(uVar7 * 0x800 | uVar7 >> 0x15) ^ uVar7;
		uVar7 = uVar7 >> ((bVar5 ^ 0xf1) & 0x1e | 1) ^ uVar7 ^ *(uint*)(unaff_EBP + -0xc) ^ 0x7c62fadc;
		uVar7 = uVar7 - (uVar7 << ((bVar5 ^ 0xfd) & 0x1e | 1));
		uVar7 = (uVar7 >> 0x19 | uVar7 * 0x80) ^ uVar7 >> 8 ^ uVar7;
		uVar7 = (uVar7 << 0x10 ^ uVar7) * -0x7ff;
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar8 = uVar7 & 0xff;
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar7 >> 8 & 0x1ff) * 0x10) + 4);

		inst->OP = 4;
		inst->A = uVar8;
		inst->B = (uVar7 >> 8 & 0x1ff);
	}

	// OP_GETUPVAL 4 : A B 
	void d23d5(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined8* puVar2;
		char* pcVar3;
		char cVar4;
		uint uVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		//int unaff_EBP;

		uVar5 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar5;
		uVar5 = uVar5 & 0x1e | 1;
		sVar6 = (sbyte)uVar5;
		bVar7 = ((byte)(0x15 >> sVar6) | (byte)(0x15 << 0x20 - sVar6)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar5;
		bVar8 = ((byte)(5 >> sVar6) | (byte)(5 << 0x20 - sVar6)) & 0x1e | 1;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(1 >> bVar9) | (byte)(1 << 0x20 - bVar9)) & 0x1e | 1;
		uVar5 = (param_2 << bVar7 | param_2 >> 0x20 - bVar7) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar9 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar9) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar5 = uVar5 >> bVar8 | uVar5 << 0x20 - bVar8;
		uVar5 = uVar5 >> 0xc ^ uVar5;
		uVar5 = (uVar5 - (uVar5 << ((char)*(undefined4*)(unaff_EBP + -0xc) * '\x03' & 0x1eU | 1))) +
			0xf7a6b456;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0xf >> bVar9) | (byte)(0xf << 0x20 - bVar9)) & 0x1e | 1;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(8 >> bVar9) | (byte)(8 << 0x20 - bVar9)) & 0x1e | 1;
		uVar5 = (uVar5 >> bVar7 | uVar5 << 0x20 - bVar7) ^ (uVar5 >> bVar9 | uVar5 << 0x20 - bVar9) ^
			uVar5;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(10 << bVar9) | (byte)(10 >> 0x20 - bVar9)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar5 << bVar9 | uVar5 >> 0x20 - bVar9;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(5 << bVar9) | (byte)(5 >> 0x20 - bVar9)) & 0x1e | 1;
		uVar5 = *(uint*)(unaff_EBP + -0xc) ^ (uVar5 << bVar9 | uVar5 >> 0x20 - bVar9) ^ uVar5;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = uVar5 & 0xff;
		//puVar2 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar5 >> 8 & 0x1ff) * 0x10) + 4);

		inst->OP = 4;
		inst->A = uVar10;
		inst->B = (uVar5 >> 8 & 0x1ff);
	}

	// OP_GETUPVAL 4 : A B 
	void d2e98(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char* pcVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;

		uVar6 = ~param_2 >> 10;
		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0x44) = ~param_2 << 0x16 | uVar6;
		uVar6 = uVar6 << 0xd ^ *(uint*)(unaff_EBP + -0x44) ^ 0x33c7be2d;
		*(int*)(unaff_EBP + -0xc) = iVar8;
		cVar3 = (char)iVar8;
		bVar4 = cVar3 * -7 & 0x1eU | 1;
		bVar5 = cVar3 * -6 & 0x1eU | 1;
		uVar6 = (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^ (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^
			uVar6;
		bVar4 = cVar3 - 8U & 0x1e | 1;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar5 = cVar3 + 3U & 0x1e | 1;
		uVar6 = (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^ (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^
			uVar6;
		uVar7 = ~(uVar6 << (cVar3 * -10 & 0x1eU | 1) ^ uVar6);
		uVar6 = uVar7 * -0x1fffffff;
		uVar6 = (uVar7 * 0x8000 | uVar6 >> 0x11) ^ (uVar7 * 0x80 | uVar6 >> 0x19) ^ uVar6;
		uVar6 = (uVar6 >> 0x14 | uVar6 << 0xc) ^ (uVar6 >> 4 | uVar6 << 0x1c) ^ uVar6;
		//*(uint*)(unaff_EBP + -0xc) = uVar6;
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar6 & 0x1ff) * 0x10) + 4);

		inst->OP = 4;
		inst->A = uVar6 >> 0x15 & 0xff;
		inst->B = (uVar6 & 0x1ff);
	}

	// OP_GETUPVAL 4 : A B 
	void d4af3(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char* pcVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		sbyte sVar6;
		byte bVar7;
		uint uVar8;
		//int unaff_EBP;
		uint uVar9;
		int iVar10;

		uVar9 = *(uint*)(unaff_EBP + -0x44);
		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		bVar4 = (char)uVar8 + 8U & 0x1e | 1;
		bVar5 = (char)uVar8 - 2U & 0x1e | 1;
		uVar9 = (uVar9 << bVar4 | uVar9 >> 0x20 - bVar4) ^ (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^
			uVar9;
		uVar9 = uVar9 >> 0x19 | uVar9 << 7;
		uVar8 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar8;
		sVar6 = (sbyte)uVar8;
		uVar9 = (uVar9 << (((byte)(0x16 >> sVar6) | (byte)(0x16 << 0x20 - sVar6)) & 0x1e | 1)) + uVar9;
		iVar10 = (~((uVar9 >> 0x1b | uVar9 * 0x20) ^ (uVar9 * 0x100 | uVar9 >> 0x18) ^ uVar9) -
			(*(uint*)(unaff_EBP + -0xc) ^ 0x4ef0919b)) -
			(0x51360f7a << sVar6 | 0x51360f7aU >> 0x20 - sVar6);
		uVar9 = (iVar10 << ((char)*(uint*)(unaff_EBP + -0xc) - 9U & 0x1e | 1)) + iVar10;
		bVar4 = (byte) * (int*)(unaff_EBP + -0xc);
		bVar5 = (bVar4 ^ 0xfb) & 0x1e | 1;
		bVar7 = (bVar4 ^ 2) & 0x1e | 1;
		bVar4 = bVar4 - 0xf & 0x1e | 1;
		uVar9 = (~((uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) ^ (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			uVar9) - *(int*)(unaff_EBP + -0xc)) + 0x22a2ffff;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0xc) + 0xdU & 0x1e | 1;
		uVar9 = (uVar9 >> bVar4 | uVar9 << 0x20 - bVar4) ^ (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^
			uVar9;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = (uVar9 >> 0x1e | uVar9 << 2) ^ (uVar9 >> 0xf | uVar9 << 0x11) ^ uVar9;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar9 = (((uVar9 << 10 | uVar9 >> 0x16) ^ (uVar9 << 7 | uVar9 >> 0x19) ^ uVar9) -
			*(int*)(unaff_EBP + -0xc)) + 0x1d99e987;
		uVar9 = uVar9 >> (((byte)(6 << bVar4) | (byte)(6 >> 0x20 - bVar4)) & 0x1e | 1) ^ uVar9;
		uVar9 = (uVar9 << 0x13 | uVar9 >> 0xd) ^ (uVar9 >> 0xd | uVar9 << 0x13) ^ uVar9;
		uVar8 = uVar9 >> 0x18;
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar9 >> 0xf & 0x1ff) * 0x10) + 4);

		inst->OP = 4;
		inst->A = uVar8;
		inst->B = (uVar9 >> 0xf & 0x1ff);
	}

	// OP_GETUPVAL 4 : A B 
	void d8556(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char* pcVar2;
		char cVar3;
		int iVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;

		uVar9 = param_2 >> 0x10 ^ *(uint*)(unaff_EBP + -0x44);
		iVar4 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar4;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar5 = (byte)iVar4 & 0x1e | 1;
		bVar6 = ((byte)(0x18 >> bVar5) | (byte)(0x18 << 0x20 - bVar5)) & 0x1e | 1;
		bVar7 = ((byte)(7 >> bVar5) | (byte)(7 << 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar9 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -4) << bVar7 | *(uint*)(unaff_EBP + -4) >> 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -4);
		bVar6 = -bVar5 - 8 & 0x1e | 1;
		uVar9 = uVar9 << ((bVar5 ^ 0xf3) & 0x1e | 1) ^ uVar9;
		iVar4 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = uVar9 >> 0x1a ^ uVar9;
		bVar5 = bVar5 - 4 & 0x1e | 1;
		uVar9 = (uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) ^ *(int*)(unaff_EBP + -0xc) * 0x38ab3790 ^
			0xc53559b1;
		uVar9 = (uVar9 << 7 | uVar9 >> 0x19) * 0x1be0072d;
		uVar9 = uVar9 >> bVar6 | uVar9 << 0x20 - bVar6;
		uVar8 = uVar9 * 0x295a622b;
		uVar8 = (uVar8 >> 7 | uVar9 * 0x56000000) ^ (uVar9 * -0x5a967754 | uVar8 >> 0x1e) ^ uVar8;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar8 & 0x1ff) * 0x10) + 4);
		uVar9 = *(uint*)(unaff_EBP + -0xc) >> 9 & 0xff;

		inst->OP = 4;
		inst->A = uVar9;
		inst->B = (uVar8 & 0x1ff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void d1535(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		//int unaff_EBP;
		int iVar6;
		uint uVar7;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		param_2 = (param_2 << 4 | param_2 >> 0x1c) ^ (param_2 << 1 | (uint)((int)param_2 < 0)) ^ param_2;
		*(int*)(unaff_EBP + -0xc) = iVar6;
		param_2 = (param_2 >> 0x1d | param_2 << 3) ^ (param_2 << 0x1b | param_2 >> 5) ^ param_2;
		bVar4 = (byte)iVar6 & 0x1e | 1;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar7 = ((param_2 << 0x14 | param_2 >> 0xc) ^ (param_2 << 0xe | param_2 >> 0x12) ^ param_2) +
			iVar6 * -0x5e266e16;
		*(uint*)(unaff_EBP + -4) = uVar7;
		bVar5 = ((byte)(0xf << bVar4) | (byte)(0xf >> 0x20 - bVar4)) & 0x1e | 1;
		bVar4 = ((byte)(3 << bVar4) | (byte)(3 >> 0x20 - bVar4)) & 0x1e | 1;
		uVar7 = (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -4) << bVar4 | *(uint*)(unaff_EBP + -4) >> 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -4);
		iVar6 = *(int*)(unaff_EBP + -0xa8);
		uVar7 = ~((((uVar7 << 0x1c | uVar7 >> 4) ^ (uVar7 << 0xd | uVar7 >> 0x13) ^ uVar7) -
			*(int*)(unaff_EBP + -0xc)) + 0x9c7f55f2);
		uVar7 = (uVar7 >> 0x1b | uVar7 << 5) ^ (uVar7 << 2 | uVar7 >> 0x1e) ^ uVar7;
		//*(undefined4*)(unaff_EBP + -0x3a8) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x39c) = 8;
		uVar7 = ~(uVar7 << ((char)*(int*)(unaff_EBP + -0xc) - 7U & 0x1e | 1) ^ uVar7);
		//*(undefined4*)(*(int*)(iVar6 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x0053cf47((uVar7 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1
		//);

		inst->OP = 5;
		inst->A = (uVar7 >> 0x12 & 0xff);
		inst->Bx = (uVar7 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void d2d70(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		int iVar7;
		//int unaff_EBP;
		uint uVar8;

		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar8 = *(int*)(unaff_EBP + -0x44) + 0x6a3e5f64 + iVar7;
		uVar8 = (uVar8 * 0x80 | uVar8 >> 0x19) + 0xf726da8a + iVar7;
		bVar4 = (byte)iVar7 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = 0x554cb2a << bVar4 | 0x554cb2aU >> 0x20 - bVar4;
		bVar5 = ((byte)(0xb >> bVar4) | (byte)(0xb << 0x20 - bVar4)) & 0x1e | 1;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar6 = -(byte)iVar7 - 0xd & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -0xc) ^ (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) * -0x7ffffff;
		uVar8 = *(uint*)(unaff_EBP + -0xc) << bVar5 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar5;
		iVar7 = *(int*)(unaff_EBP + -0xa8);
		//*(undefined4*)(unaff_EBP + -0x3d8) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		uVar8 = uVar8 << bVar6 | uVar8 >> 0x20 - bVar6;
		//*(undefined4*)(unaff_EBP + -0x3cc) = 8;
		//*(undefined4*)(*(int*)(iVar7 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x00459de6(unaff_EBP + -0x3d8,
		//	(uVar8 >> 8 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 5;
		inst->A = (uVar8 & 0xff);
		inst->Bx = (uVar8 >> 8 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void d3a93(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		byte bVar2;
		char cVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;

		uVar5 = param_2 * -0x17fd07ff;
		uVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)uVar6;
		bVar4 = (bVar2 ^ 0xf7) & 0x1e | 1;
		uVar5 = (uVar5 << bVar4 | uVar5 >> 0x20 - bVar4) ^ (uVar5 >> bVar4 | uVar5 << 0x20 - bVar4) ^
			uVar5;
		bVar4 = ~bVar2 & 0x1e | 1;
		uVar5 = (uVar5 << 0x1d | uVar5 >> 3) ^ (uVar5 >> 0x14 | uVar5 << 0xc) ^ uVar5;
		uVar5 = uVar5 >> bVar4 | uVar5 << 0x20 - bVar4;
		uVar5 = uVar5 << 0xc ^ uVar5;
		bVar4 = bVar2 & 0x1e | 1;
		uVar5 = ~((~((uVar5 >> (bVar2 * -0xe & 0x1e | 1) ^ uVar5) + 0x40313a81) * -3 -
			(0x6bdc8f42U >> bVar4 | 0x6bdc8f42 << 0x20 - bVar4)) + 0x5a35c38b);
		//pcVar1 = *(char**)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(uint*)(unaff_EBP + -0xc) =
		//	((uVar6 ^ 0x7985ca1e) * 0x29d34547 +
		//		((uVar5 << 0x13 | uVar5 >> 0xd) ^ uVar5 >> 1 ^ uVar5) * 0x58818547 >> 0xd & 0x3ffff) << 4;

		uint lol = ((uVar6 ^ 0x7985ca1e) * 0x29d34547 +
			((uVar5 << 0x13 | uVar5 >> 0xd) ^ uVar5 >> 1 ^ uVar5) * 0x58818547);

		inst->OP = 5;
		inst->A = lol & 0xff; // TODO
		inst->Bx = lol >> 0xd & 0x3ffff;
	}

	// OP_GETGLOBAL 5 : A Bx 
	void d48fc(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		int iVar2;
		char cVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;
		uint uVar11;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		uVar9 = (uVar11 ^ 0xfffffff1) & 0x1e | 1;
		uVar10 = param_2 - (param_2 << (sbyte)uVar9);
		*(uint*)(unaff_EBP + -4) = uVar9;
		*(uint*)(unaff_EBP + -0x44) = uVar10 * 0x200 | uVar10 >> 0x17;
		uVar9 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar9;
		sVar5 = (sbyte)uVar9;
		cVar3 = (char)uVar11;
		uVar9 = *(int*)(unaff_EBP + -0x44) -
			(*(int*)(unaff_EBP + -0x44) <<
				(((byte)(0x1c << sVar5) | (byte)(0x1c >> 0x20 - sVar5)) & 0x1e | 1));
		*(uint*)(unaff_EBP + -0x44) = uVar9;
		bVar6 = 9U - cVar3 & 0x1e | 1;
		bVar7 = cVar3 * '\t' & 0x1eU | 1;
		bVar8 = 4U - cVar3 & 0x1e | 1;
		uVar9 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar8 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar8) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar9 = uVar9 << bVar7 | uVar9 >> 0x20 - bVar7;
		uVar9 = (uVar9 << (-cVar3 - 10U & 0x1e | 1)) + uVar9;
		uVar9 = (uVar9 * 0x1000 | uVar9 >> 0x14) ^ (uVar9 >> 3 | uVar9 * 0x20000000) ^ uVar9;
		iVar2 = ((uVar9 << ((byte) * (undefined4*)(unaff_EBP + -4) & 0x1f)) + uVar9) * -0xffff;
		uVar9 = iVar2 - (iVar2 << (3U - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1));
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar9 = (uVar9 << (((byte)(0xb << bVar6) | (byte)(0xb >> 0x20 - bVar6)) & 0x1e | 1) ^ uVar9) -
			(0x5d36bd2eU >> bVar7 | 0x5d36bd2e << 0x20 - bVar7);
		//*(undefined4*)(unaff_EBP + -0x418) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x40c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar4 = (char*)func_0x00455a79(unaff_EBP + -0x418,
		//	(uVar9 >> 8 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 5;
		inst->A = (uVar9 & 0xff);
		inst->Bx = (uVar9 >> 8 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void d9199(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		int uVar8;
		//int unaff_EBP;
		int iVar9;
		uint uVar10;

		uVar10 = *(uint*)(unaff_EBP + -0x44) ^ 0x728d8f25;
		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar7 = uVar8 & 0x1e | 1;
		sVar4 = (sbyte)uVar7;
		*(uint*)(unaff_EBP + -4) = uVar7;
		iVar9 = (uVar10 << (((byte)(2 >> sVar4) | (byte)(2 << 0x20 - sVar4)) & 0x1e | 1)) + uVar10;
		uVar7 = iVar9 - (iVar9 << (0xbU - (char)uVar8 & 0x1e | 1)) ^ 0x7287e517 - uVar8;
		bVar5 = (byte)((-uVar8 & 3) << 3) | 1;
		uVar7 = (uVar7 << 0xf | uVar7 >> 0x11) ^ 0x30e0f46d;
		bVar6 = (char)uVar8 * -3 & 0x1eU | 1;
		uVar7 = (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0xc) * '\x0e' & 0x1eU | 1;
		uVar7 = (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^
			uVar7;
		bVar5 = 8U - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		bVar6 = 3U - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar7 = ((uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7) + 0x4e2fe53c;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar6 = bVar5 & 0x1f;
		iVar9 = (uVar7 >> 1 | (uint)((uVar7 & 1) != 0) << 0x1f) * 0x2a86f7d9 -
			(0x158c13f5U >> bVar6 | 0x158c13f5 << 0x20 - bVar6);
		bVar5 = bVar5 & 0x1f;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar7 = iVar9 + -0x77b9a0c7 +
			(iVar9 << (((byte)(4 << bVar5) | (byte)(4 >> 0x20 - bVar5)) & 0x1e | 1));
		//*(undefined4*)(unaff_EBP + -0x508) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x4fc) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x00529e97((uVar7 >> 0xc & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 5;
		inst->A = (uVar7 & 0xff);
		inst->Bx = (uVar7 >> 0xc & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void dc131(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		byte bVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		int iVar8;
		//int unaff_EBP;
		int iVar9;

		uVar7 = param_2 >> 0x1b ^ param_2;
		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar7 = (uVar7 << 0xd | param_2 >> 0x13) ^ (param_2 >> 9 | uVar7 << 0x17) ^ uVar7;
		uVar7 = (uVar7 << 0x16 | uVar7 >> 10) ^ (uVar7 << 0x13 | uVar7 >> 0xd) ^ uVar7;
		iVar8 = ((uVar7 << 8 | uVar7 >> 0x18) ^ (uVar7 >> 1 | (uint)((uVar7 & 1) != 0) << 0x1f) ^ uVar7) *
			0x20001;
		bVar2 = (byte)iVar9;
		bVar5 = bVar2 & 0x1e | 1;
		bVar6 = bVar2 + 3 & 0x1e | 1;
		iVar8 = ((iVar8 << (((byte)(0x1e << bVar5) | (byte)(0x1e >> 0x20 - bVar5)) & 0x1e | 1)) + iVar8) *
			-7 + -0x6fcec3dc;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar7 = iVar8 - (iVar8 << (bVar2 + 0xb & 0x1e | 1));
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar7 = ~(uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) + iVar9 * -0x6520bf27 ^ 0x1d0edcf0;
		//*(undefined4*)(unaff_EBP + -0x558) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x54c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar4 = (char*)func_0x005253a1((uVar7 >> 8 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 5;
		inst->A = (uVar7 & 0xff);
		inst->Bx = (uVar7 >> 8 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void dd22b(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		//int unaff_EBP;
		int iVar7;

		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar6 = (param_2 << 0x1a | param_2 >> 6) ^
			(*(uint*)(unaff_EBP + -0x44) << 0x13 | *(uint*)(unaff_EBP + -0x44) >> 0xd) ^
			*(uint*)(unaff_EBP + -0x44);
		cVar2 = (char)iVar7;
		uVar6 = uVar6 << 1 | (uint)((int)uVar6 < 0);
		*(int*)(unaff_EBP + -0xc) = iVar7;
		uVar6 = uVar6 >> (-cVar2 - 8U & 0x1e | 1) ^ uVar6;
		bVar4 = cVar2 + 0xdU & 0x1e | 1;
		bVar5 = (char)*(undefined4*)(unaff_EBP + -0xc) + 9U & 0x1e | 1;
		uVar6 = ((uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^ (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^
			uVar6) * -0x7fffff;
		cVar2 = (char)*(int*)(unaff_EBP + -0xc);
		bVar4 = cVar2 + 0xcU & 0x1e | 1;
		bVar5 = cVar2 + 8U & 0x1e | 1;
		uVar6 = (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^ (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^
			uVar6;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar6 = (uVar6 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f) + *(int*)(unaff_EBP + -0xc) * -0x1edfb6b4
			;
		uVar6 = (uVar6 >> 0x10 | uVar6 * 0x10000) ^ (uVar6 >> 0xc | uVar6 * 0x100000) ^ uVar6;
		uVar6 = (uVar6 << 6 | uVar6 >> 0x1a) * 0x64ebc631;
		//*(undefined4*)(unaff_EBP + -0x588) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x57c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x00522d60((uVar6 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar6 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1
		//);

		inst->OP = 5;
		inst->A = (uVar6 >> 0x12 & 0xff);
		inst->Bx = (uVar6 & 0x3ffff);
	}

	// OP_GETGLOBAL 5 : A Bx 
	void df608(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		sbyte sVar7;
		uint uVar8;
		//int unaff_EBP;
		uint uVar9;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar6 = (byte)uVar9;
		uVar8 = (param_2 - uVar9) + 0x95e071b7;
		uVar8 = uVar8 >> 2 ^ uVar8;
		uVar8 = ~(uVar8 << 0x1b ^ uVar8);
		uVar8 = uVar8 - (uVar8 << (-bVar6 - 0xc & 0x1e | 1));
		bVar4 = (bVar6 ^ 0xe) & 0x1e | 1;
		bVar5 = (bVar6 ^ 8) & 0x1e | 1;
		uVar8 = ~(((uVar8 >> bVar4 | uVar8 << 0x20 - bVar4) ^ (uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^
			uVar8) * 0x1c7417ad);
		bVar4 = 8 - bVar6 & 0x1e | 1;
		uVar8 = (uVar8 - (uVar8 << (9 - bVar6 & 0x1e | 1))) * -0x1fffffff;
		bVar5 = 5 - bVar6 & 0x1e | 1;
		uVar8 = (uVar8 >> bVar4 | uVar8 << 0x20 - bVar4) ^ (uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^
			uVar8;
		bVar4 = (bVar6 ^ 0xf3) & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xf5) & 0x1e | 1;
		uVar8 = (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^ (uVar8 << bVar6 | uVar8 >> 0x20 - bVar6) ^
			uVar8;
		uVar8 = (uVar8 << 0x19 | uVar8 >> 7) ^ (uVar8 << 0xb | uVar8 >> 0x15) ^ uVar8;
		uVar8 = uVar8 >> 0x1b | uVar8 << 5;
		uVar9 = uVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		sVar7 = (sbyte)uVar9;
		bVar4 = ((byte)(0x1e >> sVar7) | (byte)(0x1e << 0x20 - sVar7)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar6 = ((byte)(0xe >> bVar6) | (byte)(0xe << 0x20 - bVar6)) & 0x1e | 1;
		uVar8 = (uVar8 >> bVar4 | uVar8 << 0x20 - bVar4) ^ (uVar8 >> bVar6 | uVar8 << 0x20 - bVar6) ^
			uVar8;
		//*(undefined4*)(unaff_EBP + -0x628) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x61c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x0051ef8a((uVar8 >> 0xb & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar8 >> 3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 5;
		inst->A = (uVar8 >> 3 & 0xff);
		inst->Bx = (uVar8 >> 0xb & 0x3ffff);
	}

	// OP_GETTABLE 6 : A B C
	void d1e7c(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		char* pcVar3;
		uint uVar4;
		int iVar5;
		uint uVar6;
		//int unaff_EBP;
		int unaff_EDI;

		iVar1 = *(int*)(unaff_EBP + -0xa8);
		iVar5 = (param_2 ^ 0x27a37d40) + 0x2c2d3139;
		uVar6 = iVar5 - (iVar5 << ((char)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2) * -7 & 0x1eU |
			1));
		uVar6 = uVar6 * 0x80000 | uVar6 >> 0xd;
		//*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		uVar4 = uVar6 >> 10 ^ uVar6 ^ 0x7f944ce9;
		uVar6 = uVar4 >> 0x17;
		//if ((uVar6 & 0x100) == 0) {
		//	iVar5 = uVar6 * 0x10 + unaff_EDI;
		//}
		//else {
		//	iVar5 = (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}
		//pcVar3 = (char*)func_0x0053b792(iVar5, (uVar4 & 0xff) * 0x10 + unaff_EDI,

		inst->OP = 6;
		inst->A = (uVar4 & 0xff);
		inst->B = (uVar4 >> 0x8 & 0x1ff);
		inst->C = uVar6;
	}

	// OP_GETTABLE 6 : A B C
	void d2660(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		int iVar2;
		char cVar3;
		uint uVar4;
		int iVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		byte bVar10;
		//int unaff_EBP;
		uint uVar11;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		uVar4 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar4;
		sVar7 = (sbyte)uVar4;
		uVar4 = (0x3d2112d8U >> sVar7 | 0x3d2112d8 << 0x20 - sVar7) ^ *(int*)(unaff_EBP + -0x44) * -0x7ff
			;
		bVar8 = (char)uVar11 - 0xdU & 0x1e | 1;
		uVar4 = (uVar4 << 0x1b | uVar4 >> 5) ^ (uVar4 << 10 | uVar4 >> 0x16) ^ uVar4;
		uVar4 = (uVar4 >> 2 | uVar4 << 0x1e) ^ 0x2306113d;
		bVar9 = (char)*(undefined4*)(unaff_EBP + -0xc) + 3U & 0x1e | 1;
		uVar4 = (uVar4 >> bVar8 | uVar4 << 0x20 - bVar8) ^ (uVar4 >> bVar9 | uVar4 << 0x20 - bVar9) ^
			uVar4;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar8 = -cVar3 - 0xcU & 0x1e | 1;
		bVar9 = -cVar3 - 5U & 0x1e | 1;
		uVar4 = (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^ (uVar4 << bVar9 | uVar4 >> 0x20 - bVar9) ^
			uVar4;
		bVar8 = cVar3 + 10U & 0x1e | 1;
		bVar9 = cVar3 + 6U & 0x1e | 1;
		uVar4 = (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^ (uVar4 << bVar9 | uVar4 >> 0x20 - bVar9) ^
			uVar4;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(0xd >> bVar8) | (byte)(0xd << 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(9 >> bVar8) | (byte)(9 << 0x20 - bVar8)) & 0x1e | 1;
		uVar4 = (uVar4 >> bVar9 | uVar4 << 0x20 - bVar9) ^ (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^
			uVar4;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar4 = uVar4 << (((byte)(0x1b >> bVar8) | (byte)(0x1b << 0x20 - bVar8)) & 0x1e | 1) ^ uVar4;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar4 = uVar4 << 7 | uVar4 >> 0x19;
		bVar9 = ((byte)(0x12 >> bVar8) | (byte)(0x12 << 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar10 = ((byte)(0x10 >> bVar8) | (byte)(0x10 << 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar4 = (uVar4 >> bVar9 | uVar4 << 0x20 - bVar9) ^ (uVar4 >> bVar10 | uVar4 << 0x20 - bVar10) ^
			uVar4;
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		iVar2 = *(int*)(unaff_EBP + -0x5c);
		uVar4 = (uVar4 - (uVar4 << (((byte)(0x1b << bVar8) | (byte)(0x1b >> 0x20 - bVar8)) & 0x1e | 1))) *
			0xf8561c9 + *(int*)(unaff_EBP + -0xc) * -0x52f93335;
		uVar11 = ((uVar4 * 0x20000000 | uVar4 >> 3) ^ (uVar4 * 0x80 | uVar4 >> 0x19) ^ uVar4) * 0x4ff99db1
			;
		//*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		uVar4 = uVar11 >> 0x17;
		//if ((uVar4 & 0x100) == 0) {
		//	iVar5 = uVar4 * 0x10 + iVar2;
		//}
		//else {
		//	iVar5 = (uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}
		//pcVar6 = (char*)func_0x0053d582(iVar5, (uVar11 >> 9 & 0xff) * 0x10 + iVar2,
		//	*(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar11 >> 9 & 0xff);
		inst->B = uVar11 & 0x1ff;
		inst->C = uVar4;
	}

	// OP_GETTABLE 6 : A B C
	void d7aad(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		int iVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		uVar7 = ~(param_2 ^ 0x783054ec);
		*(uint*)(unaff_EBP + -0x44) = uVar7;
		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		bVar6 = (byte)iVar9;
		bVar4 = bVar6 + 5 & 0x1e | 1;
		bVar5 = bVar6 + 2 & 0x1e | 1;
		uVar8 = (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar5 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar4 = (bVar6 ^ 0xf9) & 0x1e | 1;
		uVar7 = uVar8 * -0x3f;
		uVar7 = (uVar8 * -0x7e00000 | uVar7 >> 0xb) ^ (uVar8 * -0x3f0000 | uVar7 >> 0x10) ^ uVar7;
		uVar7 = uVar7 >> bVar4 | uVar7 << 0x20 - bVar4;
		bVar4 = bVar6 - 10 & 0x1e | 1;
		bVar6 = bVar6 + 9 & 0x1e | 1;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar7 = (uVar7 >> 0xc | uVar7 << 0x14) ^ (uVar7 << 8 | uVar7 >> 0x18) ^ uVar7;
		bVar4 = ((byte)(0x11 >> bVar6) | (byte)(0x11 << 0x20 - bVar6)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar7 >> bVar4 | uVar7 << 0x20 - bVar4;
		bVar4 = ((byte)(0xe >> bVar6) | (byte)(0xe << 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (uint*)(unaff_EBP + -0xc);
		uVar7 = (*(uint*)(unaff_EBP + -4) ^ (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ uVar7) +
			(*(uint*)(unaff_EBP + -0xc) ^ 0x5077c72);
		bVar4 = (bVar6 ^ 0xf5) & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xfb) & 0x1e | 1;
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar7 = ((uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^
			uVar7) * -7;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		uVar8 = uVar7 >> 0xd;
		//if ((uVar8 & 0x100) == 0) {
		//	iVar2 = (uVar8 & 0x1ff) * 0x10 + iVar9;
		//}
		//else {
		//	iVar2 = (uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}
		//pcVar3 = (char*)func_0x0052ccc1(iVar2, (uVar7 >> 5 & 0xff) * 0x10 + iVar9,
		//	*(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar7 >> 5 & 0xff);
		inst->B = (uVar7 >> 0x16 & 0x1ff);
		inst->C = uVar8 & 0x1ff;
	}

	// OP_GETTABLE 6 : A B C
	void d973f(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		int iVar3;
		int iVar4;
		char* pcVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;
		uint uVar10;

		iVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar2 = (char)iVar3;
		*(int*)(unaff_EBP + -0xc) = iVar3;
		uVar10 = ~(param_2 >> (3U - cVar2 & 0x1e | 1) ^ param_2);
		bVar6 = 0xfU - cVar2 & 0x1e | 1;
		bVar7 = cVar2 - 2U & 0x1e | 1;
		bVar8 = 5U - cVar2 & 0x1e | 1;
		uVar10 = (uVar10 >> bVar6 | uVar10 << 0x20 - bVar6) ^ (uVar10 >> bVar8 | uVar10 << 0x20 - bVar8) ^
			uVar10;
		uVar9 = uVar10 >> bVar7 | uVar10 << 0x20 - bVar7;
		uVar10 = uVar9 * 0x768604f;
		uVar10 = (uVar9 * -0x2f3f6200 | uVar10 >> 0x17) ^ (uVar10 >> 6 | uVar9 * 0x3c000000) ^ uVar10;
		bVar6 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 10U & 0x1e | 1;
		bVar7 = 6U - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar10 = (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ (uVar10 >> bVar7 | uVar10 << 0x20 - bVar7) ^
			uVar10;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar7 = (bVar6 ^ 0xc) & 0x1e | 1;
		bVar8 = bVar6 - 4 & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xf7) & 0x1e | 1;
		uVar10 = ((uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^ (uVar10 >> bVar6 | uVar10 << 0x20 - bVar6)
			^ uVar10) * 0x366106a1;
		uVar10 = uVar10 >> bVar8 | uVar10 << 0x20 - bVar8;
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar6 = cVar2 * -9 & 0x1eU | 1;
		bVar7 = cVar2 * '\x02' & 0x1eU | 1;
		iVar3 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^
			uVar10;
		iVar1 = *(int*)(unaff_EBP + -0xa8);
		//*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		uVar10 = ~((uVar10 - (uVar10 << (-cVar2 - 0xcU & 0x1e | 1))) * 0x4b6c9fcf);
		//if ((uVar10 & 0x100) == 0) {
		//	iVar4 = (uVar10 & 0x1ff) * 0x10 + iVar3;
		//}
		//else {
		//	iVar4 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}
		//pcVar5 = (char*)func_0x0053d52a(iVar4, (uVar10 >> 0x12 & 0xff) * 0x10 + iVar3,
		//	*(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar10 >> 0x12 & 0xff);
		inst->B = (uVar10 >> 0x9 & 0x1ff);
		inst->C = (uVar10 & 0x1ff);
	}

	// OP_GETTABLE 6 : A B C
	void de611(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		int iVar3;
		char* pcVar4;
		uint* puVar5;
		uint* puVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		int unaff_EDI;

		iVar1 = *(int*)(unaff_EBP + -0xa8);
		uVar7 = (param_2 >> 0x11 | param_2 << 0xf) ^
			(*(uint*)(unaff_EBP + -0x44) >> 3 | *(uint*)(unaff_EBP + -0x44) << 0x1d) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = (uVar7 << 0x19 | uVar7 >> 7) ^ (uVar7 << 7 | uVar7 >> 0x19) ^ uVar7;
		uVar8 = (uVar7 * 0x3f900000 ^ uVar7 * 0xd5223f9) * 0x40581b37;
		//*(undefined4*)(*(int*)(iVar1 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		uVar7 = uVar8 >> 0xd;
		//if ((uVar7 & 0x100) == 0) {
		//	iVar3 = (uVar7 & 0x1ff) * 0x10 + unaff_EDI;
		//}
		//else {
		//	iVar3 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}
		//func_0x00520a14(iVar3, uVar8 >> 0x16 & 0x1ff, *(undefined4*)(unaff_EBP + -0xb8));

		inst->OP = 6;
		inst->A = (uVar8 & 0xff);
		inst->B = uVar8 >> 0x16 & 0x1ff;
		inst->C = (uVar7 & 0x1ff);
	}

	// OP_SETGLOBAL 7 : A Bx 
	void d1bca(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		//int unaff_EBP;
		uint uVar8;
		int iVar9;

		param_2 = param_2 << 0x15 ^ param_2;
		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		bVar6 = (byte)iVar9;
		bVar4 = (bVar6 ^ 0xf3) & 0x1e | 1;
		bVar5 = bVar6 & 0x1e | 1;
		bVar6 = (bVar6 ^ 0xfb) & 0x1e | 1;
		uVar7 = ((param_2 >> bVar4 | param_2 << 0x20 - bVar4) ^
			(param_2 >> bVar6 | param_2 << 0x20 - bVar6) ^ param_2) * 0x3121c411;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar6 = cVar2 + 0xeU & 0x1e | 1;
		bVar4 = cVar2 - 2U & 0x1e | 1;
		uVar7 = (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^ (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^
			uVar7;
		uVar7 = (uVar7 >> 0x17 | uVar7 << 9) - (0x64e3e6aU >> bVar5 | 0x64e3e6a << 0x20 - bVar5);
		uVar7 = uVar7 >> 0x11 ^ uVar7;
		uVar8 = ~(uVar7 << (((byte)(0x1d >> bVar5) | (byte)(0x1d << 0x20 - bVar5)) & 0x1e | 1) ^ uVar7);
		//*(undefined4*)(unaff_EBP + -0x3c8) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x3bc) = 8;
		uVar7 = uVar8 << 0x11;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x0053c4de((uVar8 >> 0xf | uVar7 & 0x3ffff) * 0x10 +
		//	*(int*)(unaff_EBP + -0x6c),
		//	(uVar7 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1
		//);

		inst->OP = 7;
		inst->A = (uVar7 >> 0x12 & 0xff);
		inst->Bx = (uVar8 >> 0xf | uVar7 & 0x3ffff);
	}

	// OP_SETGLOBAL 7 : A Bx 
	void d557b(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		//int unaff_EBP;
		uint uVar7;
		int iVar8;

		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar6 = (byte)iVar8;
		bVar4 = -bVar6 - 10 & 0x1e | 1;
		param_2 = param_2 >> ((bVar6 ^ 0xf5) & 0x1e | 1) ^ param_2;
		uVar7 = ~(param_2 << bVar4 | param_2 >> 0x20 - bVar4);
		uVar7 = uVar7 << ((bVar6 ^ 10) & 0x1e | 1) ^ uVar7;
		bVar4 = (bVar6 ^ 0xfb) & 0x1e | 1;
		uVar7 = ~(uVar7 << 0xc ^ uVar7) * 0x373c0485;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar5 = (bVar6 ^ 2) & 0x1e | 1;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7;
		bVar4 = -bVar6 - 0x10 & 0x1e | 1;
		bVar5 = -bVar6 - 5 & 0x1e | 1;
		uVar7 = ((uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7) + 0x84e7420f + iVar8;
		bVar6 = bVar6 & 0x1e | 1;
		//*(undefined4*)(unaff_EBP + -0x468) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x45c) = 8;
		uVar7 = (((uVar7 >> 0x1d | uVar7 * 8) ^ 0x34adedf3) -
			(0x602d1365 << bVar6 | 0x602d1365U >> 0x20 - bVar6)) * 0x1ca0d609 + 0xf671eefe;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x00532044((uVar7 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 >> 0x13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1
		//);

		inst->OP = 7;
		inst->A = (uVar7 >> 0x13 & 0xff);
		inst->Bx = (uVar7 & 0x3ffff);
	}

	// OP_SETGLOBAL 7 : A Bx 
	void d56ad(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		//int unaff_EBP;
		uint uVar7;
		uint uVar8;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar7 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar7;
		sVar4 = (sbyte)uVar7;
		uVar7 = (*(int*)(unaff_EBP + -0x44) -
			(*(int*)(unaff_EBP + -0x44) <<
				(((byte)(0xc >> sVar4) | (byte)(0xc << 0x20 - sVar4)) & 0x1e | 1))) * 0x500206fd -
			(0x5219ae08 << sVar4 | 0x5219ae08U >> 0x20 - sVar4);
		uVar7 = ((uVar7 * 0x200000 | uVar7 >> 0xb) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^ uVar7) +
			(0x78f9746aU >> sVar4 | 0x78f9746a << 0x20 - sVar4);
		bVar5 = (char)uVar8 + 0xcU & 0x1e | 1;
		bVar6 = (char)*(undefined4*)(unaff_EBP + -0xc) + 10U & 0x1e | 1;
		uVar7 = ((uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^
			uVar7) * -0x1ffff;
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar5 = cVar2 + 4U & 0x1e | 1;
		bVar6 = cVar2 - 2U & 0x1e | 1;
		uVar7 = (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^
			uVar7;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar7 = ~(uVar7 >> 0xc | uVar7 << 0x14) * 0x38406f71;
		bVar5 = ((byte)(0x1a << bVar5) | (byte)(0x1a >> 0x20 - bVar5)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar7 >> bVar5 | uVar7 << 0x20 - bVar5;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(0xe << bVar5) | (byte)(0xe >> 0x20 - bVar5)) & 0x1e | 1;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar7 = *(uint*)(unaff_EBP + -0xc) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^ uVar7;
		//*(undefined4*)(unaff_EBP + -0x478) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x46c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x00530c47((uVar7 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 >> 0x17 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1
		//);

		inst->OP = 7;
		inst->A = (uVar7 >> 0x17 & 0xff);
		inst->Bx = (uVar7 & 0x3ffff);
	}

	// OP_SETGLOBAL 7 : A Bx 
	void daa9b(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		int iVar3;
		char* pcVar4;
		byte bVar5;
		//int unaff_EBP;
		uint uVar6;

		iVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar3;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		cVar2 = (char)iVar3;
		param_2 = param_2 << (cVar2 + 0xeU & 0x1e | 1) ^ param_2;
		bVar5 = -cVar2 - 4U & 0x1e | 1;
		uVar6 = (param_2 - (param_2 << (cVar2 * -0x10 & 0x1eU | 1))) + 0xa04ef238;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^ 0x546b5323;
		uVar6 = (uVar6 << 0x18 | uVar6 >> 8) ^ (uVar6 << 4 | uVar6 >> 0x1c) ^ uVar6;
		uVar6 = uVar6 << ((char)*(undefined4*)(unaff_EBP + -0xc) + 0xcU & 0x1e | 1) ^ uVar6;
		uVar6 = (uVar6 >> 0x1e | uVar6 << 2) ^ uVar6 >> 2 ^ uVar6;
		//*(undefined4*)(unaff_EBP + -0x538) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x52c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar4 = (char*)func_0x0052765a((uVar6 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar6 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1
		//);

		inst->OP = 7;
		inst->A = (uVar6 >> 0x12 & 0xff);
		inst->Bx = (uVar6 & 0x3ffff);
	}

	// OP_SETGLOBAL 7 : A Bx 
	void df51b(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		//int unaff_EBP;
		uint uVar7;
		int iVar8;

		bVar6 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		uVar7 = (param_2 + 0x3b124f25U << ((bVar6 ^ 0xc) & 0x1e | 1) ^ param_2 + 0x3b124f25U) * 0x6f90b86f
			;
		bVar4 = bVar6 * '\n' & 0x1e | 1;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar7 = uVar7 >> bVar4 | uVar7 << 0x20 - bVar4;
		bVar4 = bVar6 & 0x1e | 1;
		iVar8 = (uVar7 << 0x1a | uVar7 >> 6) + 0x76ac49ad;
		bVar5 = bVar6 - 8 & 0x1e | 1;
		uVar7 = ((iVar8 - (iVar8 << (((byte)(4 >> bVar4) | (byte)(4 << 0x20 - bVar4)) & 0x1e | 1))) *
			0x3917ec0f ^ 0x863a9e5U) * 0x204d0d1d;
		*(uint*)(unaff_EBP + -0xc) = uVar7 >> bVar5 | uVar7 << 0x20 - bVar5;
		bVar6 = bVar6 + 5 & 0x1e | 1;
		uVar7 = (*(uint*)(unaff_EBP + -0xc) ^ (uVar7 >> bVar6 | uVar7 << 0x20 - bVar6) ^ uVar7) * -0x3ff;
		//*(undefined4*)(unaff_EBP + -0x618) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x60c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x0051febe((uVar7 >> 10 & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 7;
		inst->A = (uVar7 & 0xff);
		inst->Bx = (uVar7 >> 10 & 0x3ffff);
	}

	// OP_SETGLOBAL 7 : A Bx 
	void df9bd(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		//int unaff_EBP;
		uint uVar7;
		int iVar8;

		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar6 = (byte)iVar8;
		bVar4 = bVar6 & 0x1e | 1;
		uVar7 = (param_2 << (((byte)(0xe << bVar4) | (byte)(0xe >> 0x20 - bVar4)) & 0x1e | 1) ^ param_2) +
			0xf7f69eca;
		bVar4 = 0xf - bVar6 & 0x1e | 1;
		bVar5 = -bVar6 - 6 & 0x1e | 1;
		uVar7 = (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7;
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar7 = ((uVar7 * 0x71b812d9 >> 0x17 | uVar7 * 0x7025b200) + (0x18a9931f - iVar8)) * 0x7136c56b;
		bVar4 = 7 - bVar6 & 0x1e | 1;
		bVar6 = 1 - bVar6 & 0x1e | 1;
		uVar7 = ((uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7) + 0xc4543171;
		uVar7 = (uVar7 >> 0x13 | uVar7 * 0x2000) ^ (uVar7 * 0x1000 | uVar7 >> 0x14) ^ uVar7;
		uVar7 = (uVar7 << 0x17 | uVar7 >> 9) ^ (uVar7 << 4 | uVar7 >> 0x1c) ^ uVar7;
		//*(undefined4*)(unaff_EBP + -0x638) = *(undefined4*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//*(undefined4*)(unaff_EBP + -0x62c) = 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x0051e772((uVar7 >> 0xd & 0x3ffff) * 0x10 + *(int*)(unaff_EBP + -0x6c),
		//	(uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);

		inst->OP = 7;
		inst->A = (uVar7 & 0xff);
		inst->Bx = (uVar7 >> 0xd & 0x3ffff);
	}

	// OP_SETUPVAL 8 : A B 
	void d520b(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char cVar2;
		uint uVar3;
		char* pcVar4;
		byte bVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		int iVar10;
		//int unaff_EBP;
		undefined8* puVar11;
		uint uVar12;

		uVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		uVar3 = uVar12 & 0x1e | 1;
		bVar9 = (byte)uVar12;
		*(uint*)(unaff_EBP + -4) = uVar3;
		bVar5 = bVar9 * '\a' & 0x1e | 1;
		sVar6 = (sbyte)uVar3;
		uVar3 = (param_2 << bVar5 | param_2 >> 0x20 - bVar5) + 0x482987c9;
		*(uint*)(unaff_EBP + -0x44) = uVar3;
		bVar5 = (bVar9 ^ 10) & 0x1e | 1;
		bVar7 = ((byte)(0x15 >> sVar6) | (byte)(0x15 << 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (bVar9 ^ 0xf9) & 0x1e | 1;
		uVar3 = (uVar3 >> bVar5 | uVar3 << 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar8 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar8) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar3 = uVar3 >> bVar7 | uVar3 << 0x20 - bVar7;
		bVar5 = 0xc - bVar9 & 0x1e | 1;
		uVar3 = (uVar3 << 4 ^ uVar3) + 0x69355ab0;
		bVar7 = -bVar9 - 0xb & 0x1e | 1;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar3 = ((uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^ (uVar3 << bVar7 | uVar3 >> 0x20 - bVar7) ^
			uVar3) * 0x4e0f98d1;
		bVar5 = ((byte)(0x1c << bVar9) | (byte)(0x1c >> 0x20 - bVar9)) & 0x1e | 1;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(5 << bVar9) | (byte)(5 >> 0x20 - bVar9)) & 0x1e | 1;
		iVar10 = *(int*)(unaff_EBP + -0xc) * -0x5f1525c4 +
			((uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^ (uVar3 >> bVar9 | uVar3 << 0x20 - bVar9) ^
				uVar3) * -7;
		uVar3 = iVar10 - (iVar10 << (10U - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1));
		//puVar11 = (undefined8*)((uVar3 >> 0x17 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar1 = *(undefined8**)
			//(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar3 >> 0xe & 0x1ff) * 0x10) + 4);
		//*puVar1 = *puVar11;

		inst->OP = 8;
		inst->A = (uVar3 >> 0x17 & 0xff);
		inst->B = (uVar3 >> 0xe & 0x1ff);
	}

	// OP_SETUPVAL 8 : A B 
	void d5a62(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		int iVar2;
		char cVar3;
		uint uVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		//int unaff_EBP;
		uint uVar9;
		undefined8* puVar10;

		uVar4 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar4;
		uVar4 = uVar4 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar4;
		sVar6 = (sbyte)uVar4;
		uVar4 = (0xeU >> sVar6 | 0xe << 0x20 - sVar6) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar4;
		param_2 = (param_2 << (sbyte)uVar4) + param_2;
		uVar4 = (param_2 - (param_2 << (((byte)(1 >> sVar6) | (byte)(1 << 0x20 - sVar6)) & 0x1e | 1))) *
			0x5f65ddf7;
		bVar7 = ((byte)(0x19 << sVar6) | (byte)(0x19 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(0xb << bVar8) | (byte)(0xb >> 0x20 - bVar8)) & 0x1e | 1;
		iVar2 = (((uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^ (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^
			uVar4) + (*(uint*)(unaff_EBP + -0xc) ^ 0x5664b662)) * -0xf;
		*(int*)(unaff_EBP + -0xc) = iVar2;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar4 = iVar2 << ((byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f) ^ *(uint*)(unaff_EBP + -0xc) ^
			0x702ee61b;
		bVar7 = ((byte)(0x1a << bVar8) | (byte)(0x1a >> 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(0xf << bVar8) | (byte)(0xf >> 0x20 - bVar8)) & 0x1e | 1;
		uVar9 = ~((uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^ (uVar4 >> bVar8 | uVar4 << 0x20 - bVar8) ^
			uVar4);
		uVar9 = uVar9 >> 1 ^ uVar9;
		uVar4 = uVar9 * -0x7ffffff;
		uVar4 = (uVar4 >> 0x18 | uVar9 * 0x100) ^ uVar4 >> 0xc ^ uVar4;
		//puVar10 = (undefined8*)((uVar4 >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar4 & 0x1ff) * 0x10) + 4);

		inst->OP = 8;
		inst->A = (uVar4 >> 9 & 0xff);
		inst->B = (uVar4 & 0x1ff);
	}

	// OP_SETUPVAL 8 : A B 
	void d7ca0(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char cVar2;
		char* pcVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		//int unaff_EBP;
		uint uVar8;
		undefined8* puVar9;
		uint uVar10;
		int iVar11;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar10 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar10;
		sVar4 = (sbyte)uVar10;
		uVar10 = ((param_2 >> 5 ^ *(uint*)(unaff_EBP + -0x44)) -
			(0x60c5af8c << sVar4 | 0x60c5af8cU >> 0x20 - sVar4)) + 0x64ad0992;
		bVar5 = -(char)uVar8 - 0xfU & 0x1e | 1;
		bVar6 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 3U & 0x1e | 1;
		uVar10 = (uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^ (uVar10 >> bVar6 | uVar10 << 0x20 - bVar6) ^
			uVar10;
		bVar6 = ((byte)(0x17 >> sVar4) | (byte)(0x17 << 0x20 - sVar4)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0x12 >> bVar5) | (byte)(0x12 << 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		iVar11 = ~((uVar10 >> bVar6 | uVar10 << 0x20 - bVar6) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7)
			^ uVar10) + (0x254ce7caU >> bVar5 | 0x254ce7ca << 0x20 - bVar5);
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		iVar11 = iVar11 - (iVar11 << (bVar5 - 0xc & 0x1e | 1));
		uVar10 = (iVar11 << ((bVar5 ^ 10) & 0x1e | 1)) + iVar11;
		//puVar9 = (undefined8*)((uVar10 >> 0x14 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar10 & 0x1ff) * 0x10) + 4);

		inst->OP = 8;
		inst->A = (uVar10 >> 0x14 & 0xff);
		inst->B = (uVar10 & 0x1ff);
	}

	// OP_SETUPVAL 8 : A B 
	void da139(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;
		undefined8* puVar7;
		int unaff_EDI;

		uVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar5 = (param_2 * 0x1000000 ^ param_2 * -0x7fff) + (uVar6 ^ 0x47781be8);
		uVar5 = uVar5 >> 0x11 ^ uVar5;
		cVar2 = (char)uVar6;
		bVar4 = -cVar2 - 0xeU & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar5 << bVar4 | uVar5 >> 0x20 - bVar4;
		bVar4 = -cVar2 - 8U & 0x1e | 1;
		uVar5 = *(uint*)(unaff_EBP + -0xc) ^ (uVar5 << bVar4 | uVar5 >> 0x20 - bVar4) ^ uVar5;
		//puVar7 = (undefined8*)((uVar5 & 0xff) * 0x10 + unaff_EDI);
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar5 >> 10 & 0x1ff) * 0x10) + 4);

		inst->OP = 8;
		inst->A = (uVar5 & 0xff);
		inst->B = (uVar5 >> 10 & 0x1ff);
	}

	// OP_SETUPVAL 8 : A B 
	void dcede(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		//int unaff_EBP;
		undefined8* puVar8;
		int iVar9;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar6 = (byte)iVar9;
		bVar4 = bVar6 & 0x1e | 1;
		uVar7 = ~(((param_2 << 0x18 | param_2 >> 8) ^
			(*(uint*)(unaff_EBP + -0x44) << 5 | *(uint*)(unaff_EBP + -0x44) >> 0x1b) ^
			*(uint*)(unaff_EBP + -0x44)) - (0x6cd5282aU >> bVar4 | 0x6cd5282a << 0x20 - bVar4));
		uVar7 = (((uVar7 >> 0xf | uVar7 << 0x11) ^ (uVar7 << 4 | uVar7 >> 0x1c) ^ uVar7) * -0x7fff - iVar9
			) + 0x43a304f9;
		bVar5 = (bVar6 ^ 0xf7) & 0x1e | 1;
		bVar6 = (bVar6 ^ 4) & 0x1e | 1;
		uVar7 = (0x7b725357U >> bVar4 | 0x7b725357 << 0x20 - bVar4) + (uVar7 * 0x2000 ^ uVar7);
		uVar7 = (uVar7 * 0x1000 | uVar7 >> 0x14) ^ (uVar7 >> 9 | uVar7 * 0x800000) ^ uVar7;
		uVar7 = ((uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^
			uVar7) * -0x1ffffff + 0xa569d057;
		//puVar8 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar7 >> 8 & 0x1ff) * 0x10) + 4);

		inst->OP = 8;
		inst->A = (uVar7 & 0xff);
		inst->B = (uVar7 >> 8 & 0x1ff);
	}

	// OP_SETUPVAL 8 : A B 
	void df96b(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		char cVar2;
		uint uVar3;
		char* pcVar4;
		byte bVar5;
		sbyte sVar6;
		byte bVar7;
		//int unaff_EBP;
		undefined8* puVar8;
		uint uVar9;

		uVar3 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		int tr = uVar3;
		*(uint*)(unaff_EBP + -0xc) = uVar3;
		uVar9 = uVar3 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar5 = (byte)((-tr & 1) << 4) | 1;
		sVar6 = (sbyte)uVar9;
		uVar3 = (param_2 << (((byte)(0x19 << sVar6) | (byte)(0x19 >> 0x20 - sVar6)) & 0x1e | 1)) +
			*(int*)(unaff_EBP + -0x44);
		uVar3 = uVar3 << bVar5 | uVar3 >> 0x20 - bVar5;
		uVar3 = uVar3 >> (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xf5) & 0x1e | 1) ^ uVar3;
		bVar7 = ((byte)(0x11 >> sVar6) | (byte)(0x11 << 0x20 - sVar6)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(3 >> bVar5) | (byte)(3 << 0x20 - bVar5)) & 0x1e | 1;
		uVar3 = ((uVar3 << bVar7 | uVar3 >> 0x20 - bVar7) ^ (uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^
			uVar3) + 0xe84acb51;
		bVar5 = (byte) * (uint*)(unaff_EBP + -0xc);
		bVar7 = 5 - bVar5 & 0x1e | 1;
		uVar3 = (uVar3 * 0x40000 | uVar3 >> 0xe) ^ (uVar3 >> 10 | uVar3 * 0x400000) ^ uVar3;
		uVar3 = uVar3 >> bVar7 | uVar3 << 0x20 - bVar7;
		uVar3 = uVar3 << 6 ^ uVar3 ^ *(uint*)(unaff_EBP + -0xc) ^ 0x24a955a4;
		bVar7 = (bVar5 ^ 0xf9) & 0x1e | 1;
		uVar3 = uVar3 - (uVar3 << ((bVar5 ^ 2) & 0x1e | 1));
		uVar3 = uVar3 << bVar7 | uVar3 >> 0x20 - bVar7;
		//puVar8 = (undefined8*)((uVar3 >> 0x14 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar1 = *(undefined8**)
		//	(*(int*)(*(int*)(unaff_EBP + -0xb0) + 0x18 + (uVar3 >> 9 & 0x1ff) * 0x10) + 4);

		inst->OP = 8;
		inst->A = (uVar3 >> 0x14 & 0xff);
		inst->B = (uVar3 >> 9 & 0x1ff);
	}

	// OP_SETTABLE 9 : A B C
	void d8d7d(instr* inst, uint param_1, uint param_2) {

		byte bVar1;
		int iVar2;
		char cVar3;
		byte bVar4;
		//ushort uVar5;
		//ushort uVar6;
		uint uVar7;
		char* pcVar8;
		uint* puVar9;
		byte bVar10;
		byte bVar11;
		sbyte sVar12;
		byte bVar13;
		uint uVar14;
		byte* pbVar15;
		byte bVar16;
		byte bVar18;
		byte* pbVar17;
		byte bVar19;
		uint uVar20;
		byte* unaff_EBX;
		char** ppcVar21;
		//uint unaff_EBP;
		byte* pbVar22;
		uint uVar23;
		byte* pbVar24;
		byte* pbVar25;
		uint uVar26;
		//undefined2 in_ES;
		bool bVar27;
		byte in_AF;
		undefined auStack18[4];
		//undefined2 uStack14;
		//ushort uStack12;

		uVar23 = (param_2 * 4 ^ param_2) * 0x1dca0355;
		uVar26 = (param_1 - *(int*)(unaff_EBP - 100)) + -8 >> 2;
		cVar3 = (char)uVar26;
		uVar26 = uVar26 & 0x1e | 1;
		bVar11 = 6U - cVar3 & 0x1e | 1;
		uVar23 = uVar23 >> bVar11 | uVar23 << 0x20 - bVar11;
		*(uint*)(unaff_EBP - 0xc) = uVar26;
		sVar12 = (sbyte)uVar26;
		uVar23 = uVar23 >> (((byte)(0x1a << sVar12) | (byte)(0x1a >> 0x20 - sVar12)) & 0x1e | 1) ^ uVar23;
		bVar11 = cVar3 + 3U & 0x1e | 1;
		uVar26 = uVar23 * 0x6f3721a7;
		uVar26 = (uVar26 >> 0x1e | uVar23 * -0x43237964) ^ (uVar23 * -0x37964000 | uVar26 >> 0x12) ^
			uVar26;
		bVar13 = cVar3 * '\t' & 0x1eU | 1;
		uVar26 = (uVar26 >> 0x1e | uVar26 << 2) ^ (uVar26 >> 0x14 | uVar26 << 0xc) ^ uVar26;
		uVar26 = uVar26 << bVar13 | uVar26 >> 0x20 - bVar13;
		uVar23 = (uVar26 << bVar11 | uVar26 >> 0x20 - bVar11) ^ 0x7fbab3d3;
		bVar11 = (byte) * (undefined4*)(unaff_EBP - 0xc) & 0x1f;
		uVar23 = (uVar23 << (((byte)(0xc >> bVar11) | (byte)(0xc << 0x20 - bVar11)) & 0x1e | 1)) + uVar23;
		uVar26 = uVar23 >> 0x16 ^ uVar23;
		//*(uint*)(unaff_EBP - 0xc) = uVar26;
		//pbVar22 = *(byte**)(unaff_EBP - 0x5c);
		//pbVar24 = pbVar22 + (uVar26 >> 9 & 0xff) * 0x10;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP - 0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP - 0x50);
		uVar23 = uVar23 >> 0x11;
		/*
		if ((uVar23 & 0x100) == 0) {
			pbVar15 = pbVar22 + (uVar23 & 0x1ff) * 0x10;
		}
		else {
			pbVar15 = (byte*)(*(int*)(unaff_EBP - 0x6c) + (uVar23 & 0xff) * 0x10);
		}
		if ((uVar26 & 0x100) == 0) {
			pbVar17 = pbVar22 + (uVar26 & 0x1ff) * 0x10;
			uStack12 = (ushort)pbVar17;
		}
		else {
			pbVar17 = (byte*)(*(int*)(unaff_EBP - 0x6c) + (uVar26 & 0xff) * 0x10);
			uStack12 = (ushort)pbVar17;
		}
		*/

		inst->OP = 9;
		inst->A = (uVar26 >> 9 & 0xff);
		inst->C = (uVar23 & 0x1ff);
		inst->B = (uVar26 & 0x1ff);
	}

	// OP_SETTABLE 9 : A B C
	void db0fd(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		char cVar2;
		uint uVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		int iVar7;
		int iVar8;
		//int unaff_EBP;
		uint uVar9;
		undefined4 uVar10;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		cVar2 = (char)uVar9;
		uVar3 = ~(param_2 >> (cVar2 - 3U & 0x1e | 1) ^ param_2);
		uVar3 = uVar3 << 0x10 ^ uVar3 ^ uVar9 ^ 0x2933361f;
		uVar3 = uVar3 >> 0x1b | (uVar3 >> 0x19 ^ uVar3) << 5;
		bVar4 = cVar2 + 0xcU & 0x1e | 1;
		bVar5 = cVar2 + 5U & 0x1e | 1;
		bVar6 = cVar2 - 5U & 0x1e | 1;
		uVar3 = (uVar3 >> bVar4 | uVar3 << 0x20 - bVar4) ^ (uVar3 << bVar5 | uVar3 >> 0x20 - bVar5) ^
			uVar3;
		bVar4 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 10U & 0x1e | 1;
		bVar5 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 8U & 0x1e | 1;
		uVar3 = (uVar3 >> bVar4 | uVar3 << 0x20 - bVar4) ^ (uVar3 >> bVar5 | uVar3 << 0x20 - bVar5) ^
			uVar3;
		uVar3 = ~(uVar3 >> bVar6 | uVar3 << 0x20 - bVar6);
		uVar3 = uVar3 << 0x1a ^ uVar3;
		*(uint*)(unaff_EBP + -0xc) = uVar3;
		uVar3 = uVar3 + 0x46ff587;
		iVar8 = *(int*)(unaff_EBP + -0x5c);
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		uVar9 = uVar3 >> 0x11;
		/*
		if ((uVar9 & 0x100) == 0) {
			iVar7 = iVar8 + (uVar9 & 0x1ff) * 0x10;
		}
		else {
			iVar7 = *(int*)(unaff_EBP + -0x6c) + (uVar9 & 0xff) * 0x10;
		}
		if ((uVar3 & 0x100) == 0) {
			uVar10 = *(undefined4*)(unaff_EBP + -0xb8);
			iVar8 = (uVar3 & 0x1ff) * 0x10 + iVar8;
		}
		else {
			uVar10 = *(undefined4*)(unaff_EBP + -0xb8);
			iVar8 = *(int*)(unaff_EBP + -0x6c) + (uVar3 & 0xff) * 0x10;
		}
		*/
		//func_0x005277cc(iVar8, iVar7, uVar10);

		inst->OP = 9;
		inst->A = uVar3 >> 0x9 & 0xff;
		inst->B = (uVar3 & 0x1ff);
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_NEWTABLE 10 : A B C
	void d1ab3(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		uint uVar2;
		uint uVar3;
		int iVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		//int unaff_EBP;
		int* piVar8;

		uVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar2;
		uVar3 = uVar2 & 0x1e | 1;
		param_2 = param_2 >> (-(char)uVar2 - 3U & 0x1e | 1) ^ param_2;
		sVar5 = (sbyte)uVar3;
		*(uint*)(unaff_EBP + -4) = uVar3;
		bVar6 = ((byte)(6 >> sVar5) | (byte)(6 << 0x20 - sVar5)) & 0x1e | 1;
		uVar2 = *(int*)(unaff_EBP + -0xc) + 0x3f6d7ad8 +
			(param_2 >> (((byte)(0x18 << sVar5) | (byte)(0x18 >> 0x20 - sVar5)) & 0x1e | 1) ^ param_2)
			;
		uVar2 = uVar2 >> bVar6 | uVar2 << 0x20 - bVar6;
		bVar6 = (char)*(undefined4*)(unaff_EBP + -0xc) - 2U & 0x1e | 1;
		uVar2 = ((uVar2 >> 0x19 | uVar2 << 7) ^ (uVar2 << 0x15 | uVar2 >> 0xb) ^ uVar2) * -0xf;
		uVar2 = uVar2 >> bVar6 | uVar2 << 0x20 - bVar6;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0x1a >> bVar6) | (byte)(0x1a << 0x20 - bVar6)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(3 >> bVar6) | (byte)(3 << 0x20 - bVar6)) & 0x1e | 1;
		uVar3 = ((uVar2 << bVar7 | uVar2 >> 0x20 - bVar7) ^ (uVar2 >> bVar6 | uVar2 << 0x20 - bVar6) ^
			uVar2) * 0x40001 + 0x97301e2f;
		uVar2 = uVar3 * 8;
		uVar3 = uVar3 >> 0x1d | uVar2;
		uVar2 = ((uVar3 << 0xc | uVar2 >> 0x14) ^ (uVar3 << 5 | uVar2 >> 0x1b) ^ uVar3) * 0x36fa2a5d +
			0x6e90b0bd;
		uVar2 = (uVar2 * 0x1000 | uVar2 >> 0x14) ^ (uVar2 * 0x20 | uVar2 >> 0x1b) ^ uVar2;
		uVar2 = uVar2 << 0x15 ^ uVar2;
		uVar3 = uVar2 >> 8 & 0x1ff;
		//piVar8 = (int*)((uVar2 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//if ((uVar2 >> 0x12 & 0x1f) != 0) {
		//	uVar3 = (uVar2 >> 8 & 7) + 8 << ((char)(uVar3 >> 3) - 1U & 0x1f);
		//}

		inst->OP = 10;
		inst->A = (uVar2 & 0xff);
		inst->C = uVar3;
		inst->B = uVar2 >> 0x12 & 0x1ff;
	}

	// OP_VARARG 37 : A B C
	void d2fc8(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		int* piVar3;
		uint* puVar4;
		char* pcVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;
		int iVar11;
		uint uVar12;
		bool bVar13;

		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar10;
		bVar8 = (byte)iVar10;
		bVar6 = bVar8 + 0xe & 0x1e | 1;
		bVar7 = bVar8 + 8 & 0x1e | 1;
		bVar8 = bVar8 & 0x1e | 1;
		uVar9 = (param_2 << bVar6 | param_2 >> 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar12 = uVar9 * -0x7ffffff;
		uVar12 = (uVar12 >> 0x14 | uVar9 * 0x1000) ^ (uVar12 >> 0xb | uVar9 * 0x200000) ^ uVar12;
		uVar12 = (uVar12 - (uVar12 << (((byte)(9 << bVar8) | (byte)(9 >> 0x20 - bVar8)) & 0x1e | 1))) *
			-0xff + -0x21aa71d0 + *(int*)(unaff_EBP + -0xc);
		uVar12 = uVar12 << (((byte)(10 << bVar8) | (byte)(10 >> 0x20 - bVar8)) & 0x1e | 1) ^ uVar12;
		uVar12 = (uVar12 >> 0xd | uVar12 << 0x13) ^ (uVar12 << 6 | uVar12 >> 0x1a) ^ uVar12;
		uVar12 = (uVar12 >> 0x16 | uVar12 << 10) ^ (uVar12 << 10 | uVar12 >> 0x16) ^ uVar12;
		bVar8 = ((byte) * (uint*)(unaff_EBP + -0xc) ^ 2) & 0x1e | 1;
		uVar12 = ((uVar12 >> 0x19 | uVar12 << 7) ^ (uVar12 >> 0xb | uVar12 << 0x15) ^ uVar12) -
			(*(uint*)(unaff_EBP + -0xc) ^ 0x2bf5a57e);
		uVar12 = (uVar12 << bVar8 | uVar12 >> 0x20 - bVar8) * 0x56578f53;
		iVar10 = (uVar12 & 0x1ff) - 1;
		*(uint*)(unaff_EBP + -0xc) = (uVar12 >> 0x15 & 0xff) << 4;

		inst->OP = 37;
		inst->A = (uVar12 >> 0x15 & 0xff);
		inst->B = (uVar12 & 0x1ff);
	}

	// OP_SELF 11 : A B C
	void d59c0(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char* pcVar2;
		int iVar3;
		code* pcVar4;
		undefined4 uVar5;
		undefined4 uVar6;
		char cVar7;
		uint uVar8;
		undefined8* puVar9;
		byte bVar10;
		byte bVar11;
		byte bVar12;
		byte bVar13;
		int iVar14;
		uint uVar15;
		//int unaff_EBP;
		undefined8* puVar16;
		undefined8* puVar17;
		undefined8* puVar18;

		uVar8 = ~*(uint*)(unaff_EBP + -0x44);
		*(uint*)(unaff_EBP + -0x44) = uVar8;
		iVar14 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar14;
		bVar10 = (byte)((-iVar14 & 3U) << 3) | 1;
		bVar11 = (char)iVar14 * '\v' & 0x1eU | 1;
		uVar8 = (uVar8 << bVar10 | uVar8 >> 0x20 - bVar10) ^ (uVar8 >> bVar11 | uVar8 << 0x20 - bVar11) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar12 = (char)iVar14 - 9U & 0x1e | 1;
		bVar13 = (char)*(undefined4*)(unaff_EBP + -0xc) - 5U & 0x1e | 1;
		bVar10 = (byte) * (int*)(unaff_EBP + -0xc);
		uVar8 = ((uVar8 >> bVar12 | uVar8 << 0x20 - bVar12) ^ (uVar8 << bVar13 | uVar8 >> 0x20 - bVar13) ^
			uVar8) + 0x5aed236 + *(int*)(unaff_EBP + -0xc);
		bVar12 = (bVar10 ^ 8) & 0x1e | 1;
		bVar10 = (bVar10 ^ 6) & 0x1e | 1;
		bVar13 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 0xeU & 0x1e | 1;
		uVar8 = ((uVar8 >> bVar12 | uVar8 << 0x20 - bVar12) ^ (uVar8 << bVar10 | uVar8 >> 0x20 - bVar10) ^
			uVar8) + 0xf3640563;
		bVar10 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 7U & 0x1e | 1;
		uVar8 = ((uVar8 >> bVar13 | uVar8 << 0x20 - bVar13) ^ (uVar8 << bVar10 | uVar8 >> 0x20 - bVar10) ^
			uVar8) * 0x6247236b;
		bVar10 = (char)*(undefined4*)(unaff_EBP + -0xc) * '\n' & 0x1eU | 1;
		uVar8 = (uVar8 >> bVar10 | uVar8 << 0x20 - bVar10) ^ (uVar8 >> bVar11 | uVar8 << 0x20 - bVar11) ^
			uVar8;
		uVar8 = (((uVar8 >> 3 | uVar8 << 0x1d) ^ (uVar8 << 3 | uVar8 >> 0x1d) ^ uVar8) -
			*(int*)(unaff_EBP + -0xc)) + 0x33deeb98;
		uVar15 = uVar8 >> 0x16 ^ uVar8;
		*(uint*)(unaff_EBP + -0xc) = uVar15;
		//puVar17 = (undefined8*)((uVar8 >> 0x15 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar16 = (undefined8*)((uVar15 >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 11;
		inst->A = (uVar15 >> 9 & 0xff);
		inst->B = (uVar8 >> 0x15 & 0x1ff);
		inst->C = uVar15 & 0x1ff;
	}

	// OP_SELF 11 : A B C
	void d74f7(instr* inst, uint param_1, uint param_2) {

		short* psVar1;
		code* pcVar2;
		char cVar3;
		//undefined2* puVar4;
		//SIZE_T SVar5;
		int iVar6;
		//FARPROC pFVar7;
		//HANDLE pvVar8;
		//LPVOID pvVar9;
		uint uVar10;
		undefined8* puVar11;
		sbyte sVar12;
		byte bVar13;
		byte bVar14;
		byte bVar15;
		//undefined2 uVar16;
		int* piVar17;
		uint* puVar18;
		uint uVar19;
		//int unaff_EBP;
		uint uVar20;
		undefined8* lpAddress;
		uint uVar21;
		undefined8* puVar22;
		bool bVar23;
		int iVar24;
		int iVar25;
		int iVar26;
		//DWORD dwFlags;
		undefined4 uVar27;
		undefined4 uVar28;
		undefined4 uVar29;
		undefined4 uVar30;
		undefined4 uVar31;
		undefined4 uVar32;
		char* pcVar33;

		param_2 = ~param_2;
		*(uint*)(unaff_EBP + -0x44) = param_2;
		uVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		uVar10 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar10;
		sVar12 = (sbyte)uVar10;
		bVar13 = ((byte)(0x13 >> sVar12) | (byte)(0x13 << 0x20 - sVar12)) & 0x1e | 1;
		bVar14 = ((byte)(4 >> sVar12) | (byte)(4 << 0x20 - sVar12)) & 0x1e | 1;
		uVar10 = (param_2 << bVar13 | param_2 >> 0x20 - bVar13) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar14 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar14)
			^ *(uint*)(unaff_EBP + -0x44);
		bVar14 = ((byte)(0x12 >> sVar12) | (byte)(0x12 << 0x20 - sVar12)) & 0x1e | 1;
		bVar13 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar15 = ((byte)(5 >> bVar13) | (byte)(5 << 0x20 - bVar13)) & 0x1e | 1;
		bVar13 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar10 = (((uVar10 << bVar14 | uVar10 >> 0x20 - bVar14) ^
			(uVar10 << bVar15 | uVar10 >> 0x20 - bVar15) ^ uVar10) -
			(0x360f7c13 << bVar13 | 0x360f7c13U >> 0x20 - bVar13)) * -0x1f;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar13 = cVar3 * '\f' & 0x1eU | 1;
		bVar14 = cVar3 * -7 & 0x1eU | 1;
		bVar15 = (byte) * (undefined4*)(unaff_EBP + -4);
		uVar10 = ((uVar10 << bVar13 | uVar10 >> 0x20 - bVar13) ^
			(uVar10 << bVar14 | uVar10 >> 0x20 - bVar14) ^ uVar10) * -0xfff + 0x1fede38b;
		*(uint*)(unaff_EBP + -0x1c) = uVar10;
		*(uint*)(unaff_EBP + -4) = (0xcU >> (bVar15 & 0x1f) | 0xc << 0x20 - (bVar15 & 0x1f)) & 0x1e | 1;
		bVar13 = ((byte)(8 << (bVar15 & 0x1f)) | (byte)(8 >> 0x20 - (bVar15 & 0x1f))) & 0x1e | 1;
		uVar10 = (uVar10 * 0x8000000 | uVar10 >> 5) ^
			(*(uint*)(unaff_EBP + -0x1c) >> 0x14 | *(uint*)(unaff_EBP + -0x1c) << 0xc) ^
			*(uint*)(unaff_EBP + -0x1c);
		bVar14 = ((byte)(0x17 << (bVar15 & 0x1f)) | (byte)(0x17 >> 0x20 - (bVar15 & 0x1f))) & 0x1e | 1;
		uVar10 = ~(uVar10 << bVar13 | uVar10 >> 0x20 - bVar13);
		uVar10 = uVar10 << bVar14 | uVar10 >> 0x20 - bVar14;
		uVar10 = ((uVar10 >> 5 | uVar10 << 0x1b) + 0xcfa0a080) * 0x8c48601;
		bVar13 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar10 = uVar10 << bVar13 | uVar10 >> 0x20 - bVar13;
		uVar10 = (uVar10 << 0x1c | uVar10 >> 4) ^ (uVar10 << 5 | uVar10 >> 0x1b) ^ uVar10;
		uVar10 = uVar10 >> ((char)*(undefined4*)(unaff_EBP + -0xc) * -10 & 0x1eU | 1) ^ uVar10;
		//*(uint*)(unaff_EBP + -0xc) = uVar10;
		//puVar22 = (undefined8*)((uVar10 >> 0xc & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//lpAddress = (undefined8*)((uVar10 >> 4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 11;
		inst->A = (uVar10 >> 4 & 0xff);
		inst->B = (uVar10 >> 0xc & 0x1ff);
		inst->C = uVar10 >> 0x15 & 0x1ff;
	}

	// OP_VARARG 37 : A B 
	void d1189(instr* inst, uint param_1, uint param_2) {

		int* piVar1;
		uint* puVar2;
		char* pcVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		int iVar9;
		//int unaff_EBP;
		bool bVar10;

		uVar8 = ((param_1 - *(int*)(unaff_EBP + -100)) - 8U & 0x78 | 4) >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		sVar4 = (sbyte)uVar8;
		bVar5 = ((byte)(0xb << sVar4) | (byte)(0xb >> 0x20 - sVar4)) & 0x1e | 1;
		uVar8 = *(uint*)(unaff_EBP + -0x44) >> bVar5 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar5;
		*(uint*)(unaff_EBP + -0x44) = uVar8 << 0x1e | uVar8 >> 2;
		uVar8 = ~(*(uint*)(unaff_EBP + -0x44) ^ (0x5f09296b << sVar4 | 0x5f09296bU >> 0x20 - sVar4));
		uVar8 = uVar8 << 0x1d ^ uVar8;
		bVar6 = ((byte)(0x1b >> sVar4) | (byte)(0x1b << 0x20 - sVar4)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar7 = ((byte)(0x13 >> bVar5) | (byte)(0x13 << 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		iVar9 = ((uVar8 >> bVar6 | uVar8 << 0x20 - bVar6) ^ (uVar8 >> bVar7 | uVar8 << 0x20 - bVar7) ^
			uVar8) * 0x401;
		uVar8 = (iVar9 << (((byte)(0x1c << bVar5) | (byte)(0x1c >> 0x20 - bVar5)) & 0x1e | 1)) + iVar9;
		*(uint*)(unaff_EBP + -0xc) = (uVar8 >> 0xf & 0xff) << 4;

		inst->OP = 37;
		inst->A = (uVar8 >> 0xf & 0xff);
		inst->B = (uVar8 >> 6 & 0x1ff);
	}

	// OP_VARARG 37 : A B 
	void d4cd2(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;
		int* piVar8;
		uint* puVar9;

		iVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar7;
		bVar5 = (byte)iVar7;
		bVar3 = bVar5 & 0x1e | 1;
		uVar6 = (param_2 * 0x6cafd3cd << (((byte)(0xd >> bVar3) | (byte)(0xd << 0x20 - bVar3)) & 0x1e | 1)
			) + param_2 * 0x6cafd3cd;
		bVar3 = (byte)((-iVar7 & 1U) << 4) | 1;
		bVar4 = -((char)(iVar7 << 4) - bVar5) & 0x1e | 1;
		bVar5 = bVar5 - 0xd & 0x1e | 1;
		uVar6 = (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^ (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
			uVar6;
		bVar3 = (char)*(undefined4*)(unaff_EBP + -0xc) - 6U & 0x1e | 1;
		bVar4 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 0xcU & 0x1e | 1;
		uVar6 = ((uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^ (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^
			uVar6) * -0xffff;
		bVar5 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 0xbU & 0x1e | 1;
		uVar6 = (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^ (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^
			uVar6;
		cVar2 = (char)*(uint*)(unaff_EBP + -0xc);
		uVar6 = (uVar6 << (cVar2 - 6U & 0x1e | 1)) + uVar6;
		bVar5 = cVar2 + 0xfU & 0x1e | 1;
		bVar3 = cVar2 + 3U & 0x1e | 1;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^ (uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^
			uVar6;
		uVar6 = ~(uVar6 << 0x11 | uVar6 >> 0xf);
		uVar6 = (uVar6 << 7 | uVar6 >> 0x19) ^ (uVar6 >> 6 | uVar6 << 0x1a) ^ uVar6;
		uVar6 = (uVar6 << (cVar2 * '\x0e' & 0x1eU | 1)) + uVar6;
		uVar6 = (uVar6 >> 0x19 | uVar6 * 0x80) ^ *(uint*)(unaff_EBP + -0xc) ^ 0x3b8790;
		//*(uint*)(unaff_EBP + -0xc) = (uVar6 & 0xff) << 4;
		//*(uint*)(unaff_EBP + -4) = (uVar6 >> 0x11 & 0x1ff) - 1;

		inst->OP = 37;
		inst->A = (uVar6 & 0xff);
		inst->B = (uVar6 >> 0x11 & 0x1ff);
	}

	// OP_VARARG 37 : A B 
	void d4d36(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		int* piVar2;
		uint* puVar3;
		char* pcVar4;
		byte bVar5;
		sbyte sVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;
		bool bVar11;

		uVar9 = param_2 >> 7 ^ *(uint*)(unaff_EBP + -0x44);
		uVar9 = uVar9 >> 0x18 | uVar9 << 8;
		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar1 = (char)iVar10;
		*(int*)(unaff_EBP + -0xc) = iVar10;
		bVar5 = 3U - cVar1 & 0x1e | 1;
		uVar9 = (uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) + 0x17dcb7de ^ 0x221ddb1cU - iVar10;
		bVar5 = 10U - cVar1 & 0x1e | 1;
		uVar9 = (uVar9 >> 0x17 | uVar9 << 9) ^ (uVar9 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f) ^ uVar9;
		uVar9 = ((uVar9 << 0x17 | uVar9 >> 9) ^ (uVar9 << 3 | uVar9 >> 0x1d) ^ uVar9) * 0x1af1bd1b +
			0x8a7015a5;
		uVar9 = uVar9 << bVar5 | uVar9 >> 0x20 - bVar5;
		uVar9 = (uVar9 << (cVar1 + 7U & 0x1e | 1)) + uVar9;
		uVar8 = *(uint*)(unaff_EBP + -0xc) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar9 = (uVar9 * 0x80000 | uVar9 >> 0xd) ^ (uVar9 >> 4 | uVar9 * 0x10000000) ^ uVar9;
		sVar6 = (sbyte)uVar8;
		bVar7 = ((byte)(0x1b << sVar6) | (byte)(0x1b >> 0x20 - sVar6)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar5 = ((byte)(0x15 << bVar5) | (byte)(0x15 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar9 = (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^ (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^
			uVar9;
		uVar9 = uVar9 >> 0xe | uVar9 << 0x12;
		uVar9 = uVar9 >> 2 ^ uVar9;
		//*(uint*)(unaff_EBP + -0xc) = (uVar9 >> 0xf & 0xff) << 4;
		//bVar11 = _DAT_10675930 == 0x111111;
		//*(uint*)(unaff_EBP + -4) = (uVar9 >> 6 & 0x1ff) - 1;

		inst->OP = 37;
		inst->A = (uVar9 >> 0xf & 0xff);
		inst->B = (uVar9 >> 6 & 0x1ff);
	}

	// OP_VARARG 37 : A B
	void dbaf8(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		int* piVar2;
		uint* puVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		int iVar9;
		//int unaff_EBP;
		uint uVar10;

		uVar10 = *(uint*)(unaff_EBP + -0x44);
		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar10 = (uVar10 << 10 | uVar10 >> 0x16) ^ (uVar10 << 6 | uVar10 >> 0x1a) ^ uVar10;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		bVar5 = (char)iVar9 * -5 & 0x1eU | 1;
		iVar9 = *(int*)(unaff_EBP + -0xc);
		bVar6 = (byte)iVar9 & 0x1e | 1;
		bVar7 = ((byte)(0x14 << bVar6) | (byte)(0x14 >> 0x20 - bVar6)) & 0x1e | 1;
		bVar8 = (byte)((-iVar9 & 7U) << 2) | 1;
		uVar10 = ~(((uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^
			(uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^ uVar10) * 0x2c9aa02f ^ iVar9 * 0x482cdf8a
			);
		uVar1 = *(undefined4*)(unaff_EBP + -0xc);
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		bVar5 = ((byte)(0x18 >> bVar6) | (byte)(0x18 << 0x20 - bVar6)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = *(uint*)(unaff_EBP + -0xc) >> ((char)uVar1 * '\f' & 0x1eU | 1);
		*(uint*)(unaff_EBP + -0xc) = *(uint*)(unaff_EBP + -0xc) ^ uVar10;
		uVar10 = (*(uint*)(unaff_EBP + -0xc) >> bVar5 | *(uint*)(unaff_EBP + -0xc) << 0x20 - bVar5) +
			0x93ae474f;
		uVar10 = (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) + 0x110dcb5a;
		uint rot = (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7);
		*(uint*)(unaff_EBP + -0xc) = (rot >> 9 & 0xff) << 4;

		inst->OP = 37;
		inst->A = (rot >> 9 & 0xff);
		inst->B = rot & 0x1ff;
	}

	// OP_SELF 11 : A B C
	void dc3d0(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		code* pcVar2;
		undefined4 uVar3;
		undefined4 uVar4;
		char cVar5;
		undefined8* puVar6;
		char** ppcVar7;
		byte bVar8;
		byte bVar9;
		//int unaff_EBP;
		undefined8* puVar10;
		uint uVar11;
		undefined8* puVar12;
		undefined8* puVar13;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar9 = (byte)uVar11;
		bVar8 = bVar9 & 0x1e | 1;
		uVar11 = *(int*)(unaff_EBP + -0x44) + 0x4e78b764 +
			((param_2 << (bVar9 * -4 & 0x1e | 1)) - (uVar11 ^ 0x1342475c));
		bVar9 = ((byte)(0xd >> bVar8) | (byte)(0xd << 0x20 - bVar8)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar11 >> bVar9 | uVar11 << 0x20 - bVar9;
		bVar9 = ((byte)(7 >> bVar8) | (byte)(7 << 0x20 - bVar8)) & 0x1e | 1;
		uVar11 = (*(uint*)(unaff_EBP + -0xc) ^ (uVar11 << bVar9 | uVar11 >> 0x20 - bVar9) ^ uVar11) +
			0xb7cf3fe9;
		//*(uint*)(unaff_EBP + -0xc) = uVar11;
		//puVar12 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//uVar1 = *(undefined4*)((int)puVar12 + 4);
		//uVar3 = *(undefined4*)(puVar12 + 1);
		//uVar4 = *(undefined4*)((int)puVar12 + 0xc);
		//puVar10 = (undefined8*)((uVar11 >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 11;
		inst->A = (uVar11 >> 9 & 0xff);
		inst->B = (uVar11 & 0x1ff);
		inst->C = uVar11 >> 0x16 & 0x1ff;
	}

	// OP_SELF 11 : A B C
	void dcbbc(instr* inst, uint param_1, uint param_2) {

		byte bVar1;
		undefined4 uVar2;
		undefined4 uVar3;
		undefined4 uVar4;
		char cVar5;
		uint uVar6;
		char* pcVar7;
		byte bVar8;
		//int unaff_EBP;
		int iVar9;
		undefined4* puVar10;
		int iVar11;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar1 = (byte)iVar11;
		bVar8 = bVar1 & 0x1e | 1;
		iVar9 = ((param_2 - (param_2 << ((bVar1 ^ 2) & 0x1e | 1))) - iVar11) * 0x2529748d + -0x67c501f4;
		uVar6 = iVar9 + (iVar9 << (((byte)(0x11 >> bVar8) | (byte)(0x11 << 0x20 - bVar8)) & 0x1e | 1));
		uVar6 = ~(uVar6 * 0x80 | uVar6 >> 0x19) + 0xbb37bcaa + iVar11;
		bVar8 = (bVar1 ^ 0xf7) & 0x1e | 1;
		uVar6 = uVar6 >> ((char)(iVar11 << 4) - bVar1 & 0x1e | 1) ^ uVar6;
		uVar6 = (uVar6 >> bVar8 | uVar6 << 0x20 - bVar8) ^ (uVar6 << bVar8 | uVar6 >> 0x20 - bVar8) ^
			uVar6;
		//*(uint*)(unaff_EBP + -0xc) = uVar6;
		//puVar10 = (undefined4*)((uVar6 >> 0x17) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//pcVar7 = (char*)(uVar6 >> 0xf);

		inst->OP = 11;
		inst->A = (uVar6 >> 0xf) & 0xff;
		inst->B = (uVar6 >> 0x17);
		inst->C = uVar6 & 0x1ff;
	}

	// OP_VARARG 37 : A B
	void dde58(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char* pcVar2;
		char cVar3;
		undefined4 uVar4;
		int* piVar5;
		uint* puVar6;
		byte bVar7;
		byte bVar8;
		sbyte sVar9;
		uint uVar10;
		//int unaff_EBP;
		uint uVar11;
		int iVar12;
		int iVar13;
		bool bVar14;
		//float10 fVar15;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar3 = (char)uVar11;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		uVar10 = (param_2 << (cVar3 * -6 & 0x1eU | 1) ^ *(uint*)(unaff_EBP + -0x44)) + 0x504bee90;
		bVar7 = cVar3 * '\n' & 0x1eU | 1;
		bVar8 = cVar3 * '\a' & 0x1eU | 1;
		uVar10 = (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^ (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) ^
			uVar10;
		uVar11 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar11;
		sVar9 = (sbyte)uVar11;
		bVar8 = ((byte)(0x13 >> sVar9) | (byte)(0x13 << 0x20 - sVar9)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0xf >> bVar7) | (byte)(0xf << 0x20 - bVar7)) & 0x1e | 1;
		uVar10 = (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) ^ (uVar10 >> bVar7 | uVar10 << 0x20 - bVar7) ^
			uVar10;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar11 = ~((uVar10 >> 0x1a | uVar10 << 6) ^ (uVar10 << 6 | uVar10 >> 0x1a) ^ uVar10);
		bVar8 = ((byte)(0x10 >> bVar7) | (byte)(0x10 << 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(3 >> bVar7) | (byte)(3 << 0x20 - bVar7)) & 0x1e | 1;
		uVar11 = (uVar11 >> bVar8 | uVar11 << 0x20 - bVar8) ^ (uVar11 << bVar7 | uVar11 >> 0x20 - bVar7) ^
			uVar11;
		uVar11 = (uVar11 >> 0x1b | uVar11 << 5) ^ (uVar11 >> 0x14 | uVar11 << 0xc) ^ uVar11;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar11 = (uVar11 >> (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 2) & 0x1e | 1) ^ uVar11) -
			(0x4e22e14c << bVar7 | 0x4e22e14cU >> 0x20 - bVar7);
		bVar7 = 0xcU - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		bVar8 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 2U & 0x1e | 1;
		uVar11 = (uVar11 << bVar7 | uVar11 >> 0x20 - bVar7) ^ (uVar11 >> bVar8 | uVar11 << 0x20 - bVar8) ^
			uVar11;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar11 = ((uVar11 >> 2 ^ uVar11) - *(int*)(unaff_EBP + -0xc)) + 0x3a62b11e;
		cVar3 = (char)*(int*)(unaff_EBP + -0xc);
		uVar11 = (0x714113ae << bVar7 | 0x714113aeU >> 0x20 - bVar7) ^ (uVar11 >> 7 ^ uVar11) * 0x457d5dd3
			;
		uVar11 = uVar11 >> 0xb | uVar11 << 0x15;
		uVar11 = (uVar11 << (cVar3 * -5 & 0x1eU | 1)) + uVar11;
		uVar11 = uVar11 >> (cVar3 * -10 & 0x1eU | 1) ^ uVar11;
		iVar13 = (uVar11 >> 0x17) - 1;
		//*(uint*)(unaff_EBP + -0xc) = (uVar11 >> 0xf & 0xff) << 4;

		inst->OP = 37;
		inst->A = (uVar11 >> 0xf & 0xff);
		inst->B = (uVar11 >> 0x17);
	}

	// OP_SELF 11 : A B C
	void de478(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char* pcVar2;
		int iVar3;
		code* pcVar4;
		byte bVar5;
		undefined4 uVar6;
		undefined4 uVar7;
		char cVar8;
		undefined8* puVar9;
		byte bVar10;
		byte bVar11;
		int iVar12;
		//int unaff_EBP;
		uint uVar13;
		undefined8* puVar14;
		undefined8* puVar15;
		undefined8* puVar16;

		bVar5 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar10 = bVar5 & 0x1e | 1;
		iVar12 = *(int*)(unaff_EBP + -0x44) + 0x14ea468f +
			(*(int*)(unaff_EBP + -0x44) <<
				(((byte)(0x13 >> bVar10) | (byte)(0x13 << 0x20 - bVar10)) & 0x1e | 1));
		uVar13 = (iVar12 << (((byte)(0x16 << bVar10) | (byte)(0x16 >> 0x20 - bVar10)) & 0x1e | 1)) +
			iVar12;
		bVar10 = bVar5 + 0xf & 0x1e | 1;
		uVar13 = uVar13 >> 0x10 | uVar13 * 0x10000;
		bVar11 = bVar5 + 0xc & 0x1e | 1;
		uVar13 = (uVar13 >> bVar10 | uVar13 << 0x20 - bVar10) ^
			(uVar13 << bVar11 | uVar13 >> 0x20 - bVar11) ^ uVar13;
		uVar13 = uVar13 << (bVar5 + 3 & 0x1e | 1) ^ uVar13;
		uVar13 = ~(uVar13 >> (bVar5 + 0xb & 0x1e | 1) ^ uVar13);
		//puVar14 = (undefined8*)((uVar13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar15 = (undefined8*)((uVar13 >> 8 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 11;
		inst->A = (uVar13 & 0xff);
		inst->B = (uVar13 >> 8 & 0x1ff);
		inst->C = (uVar13 >> 0x16 & 0x1ff);
	}

	// OP_SELF 11 : A B C
	void de7a4(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char* pcVar2;
		undefined4 uVar3;
		undefined4 uVar4;
		char cVar5;
		uint uVar6;
		undefined8* puVar7;
		sbyte sVar8;
		byte bVar9;
		byte bVar10;
		byte bVar11;
		int extraout_ECX;
		//int unaff_EBP;
		uint uVar12;
		undefined8* puVar13;
		uint uVar14;
		undefined8* puVar15;

		uVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		uVar14 = (param_2 - (param_2 << (-(char)uVar12 - 9U & 0x1e | 1))) * 0x801;
		uVar6 = uVar12 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar6;
		sVar8 = (sbyte)uVar6;
		bVar9 = (char)uVar12 * -7 & 0x1eU | 1;
		bVar10 = ((byte)(0x10 >> sVar8) | (byte)(0x10 << 0x20 - sVar8)) & 0x1e | 1;
		bVar11 = (char)*(undefined4*)(unaff_EBP + -0xc) * '\x05' & 0x1eU | 1;
		uVar14 = (uVar14 << bVar9 | uVar14 >> 0x20 - bVar9) ^ (uVar14 << bVar11 | uVar14 >> 0x20 - bVar11)
			^ uVar14;
		uVar6 = uVar14 << bVar10 | uVar14 >> 0x20 - bVar10;
		uVar6 = (uVar6 >> 0x1b | uVar6 << 5) ^ (uVar6 >> 0x15 | uVar6 << 0xb) ^ uVar6;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar12 = (uVar6 << bVar9 | uVar6 >> 0x20 - bVar9) * 0xbb6e183;
		bVar9 = bVar10 - 5 & 0x1e | 1;
		bVar11 = bVar10 - 4 & 0x1e | 1;
		uVar12 = (uVar12 >> bVar9 | uVar12 << 0x20 - bVar9) ^ (uVar12 << bVar11 | uVar12 >> 0x20 - bVar11)
			^ uVar12;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar6 = uVar12 << 3;
		uVar6 = (uVar6 >> 0x1e | (uVar12 >> 0x1d | uVar6) << 2) -
			(0x48ce90f3 << bVar9 | 0x48ce90f3U >> 0x20 - bVar9);
		bVar9 = (bVar10 ^ 6) & 0x1e | 1;
		bVar10 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xfb) & 0x1e | 1;
		uVar6 = (uVar6 >> bVar9 | uVar6 << 0x20 - bVar9) ^ (uVar6 << bVar10 | uVar6 >> 0x20 - bVar10) ^
			uVar6;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar6 = uVar6 >> 0x1c | uVar6 << 4;
		bVar10 = ((byte)(0xf >> bVar9) | (byte)(0xf << 0x20 - bVar9)) & 0x1e | 1;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(5 >> bVar9) | (byte)(5 << 0x20 - bVar9)) & 0x1e | 1;
		uVar6 = (uVar6 >> bVar10 | uVar6 << 0x20 - bVar10) ^ (uVar6 >> bVar9 | uVar6 << 0x20 - bVar9) ^
			uVar6;
		uVar6 = uVar6 << 0x1a ^ uVar6;
		uVar6 = uVar6 - (uVar6 << ((char)*(undefined4*)(unaff_EBP + -0xc) + 8U & 0x1e | 1));
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(0x11 >> bVar9) | (byte)(0x11 << 0x20 - bVar9)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar6 >> bVar9 | uVar6 << 0x20 - bVar9;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(0xc >> bVar9) | (byte)(0xc << 0x20 - bVar9)) & 0x1e | 1;
		uVar6 = *(uint*)(unaff_EBP + -0xc) ^ (uVar6 << bVar9 | uVar6 >> 0x20 - bVar9) ^ uVar6;
		//*(uint*)(unaff_EBP + -0xc) = uVar6;
		//puVar15 = (undefined8*)((uVar6 >> 9 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar13 = (undefined8*)((uVar6 >> 0x13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 11;
		inst->A = (uVar6 >> 0x13 & 0xff);
		inst->B = (uVar6 >> 9 & 0x1ff);
		inst->C = uVar6 & 0x1ff;
	}

	// OP_ADD 12 : A B C
	void d0f0e(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		sbyte sVar5;
		int iVar6;
		uint uVar7;
		//int unaff_EBP;
		uint uVar8;
		undefined8* puVar9;
		uint uVar10;
		double* pdVar11;
		undefined8 uVar12;
		double dVar13;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar10 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar10;
		bVar3 = (char)uVar8 * '\v' & 0x1eU | 1;
		bVar4 = (char)uVar8 * '\x02' & 0x1eU | 1;
		uVar8 = (((param_2 << bVar3 | param_2 >> 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar4 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x44)) - uVar8) + 0xc8139d77;
		uVar7 = ((uVar8 * 0x20000000 | uVar8 >> 3) ^ (uVar8 * 0x4000000 | uVar8 >> 6) ^ uVar8) *
			0x64ac02f5;
		sVar5 = (sbyte)uVar10;
		uVar7 = uVar7 << (((byte)(0x1d << sVar5) | (byte)(0x1d >> 0x20 - sVar5)) & 0x1e | 1) ^ uVar7;
		uVar8 = uVar7 * -0x3ffffff;
		bVar4 = ((byte)(0xd << sVar5) | (byte)(0xd >> 0x20 - sVar5)) & 0x1e | 1;
		uVar8 = ~(((uVar7 * 0x10000000 | uVar8 >> 4) ^ (uVar7 * 0x8000 | uVar8 >> 0x11) ^
			*(int*)(unaff_EBP + -0xc) + 0x18a20d3eU ^ uVar8) +
			(0x4df0cf40 << sVar5 | 0x4df0cf40U >> 0x20 - sVar5) +
			(0x46d23fd0 << sVar5 | 0x46d23fd0U >> 0x20 - sVar5)) * 0x611f810b + 0xbd1ed24;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar3 = ((byte)(2 << bVar3) | (byte)(2 >> 0x20 - bVar3)) & 0x1e | 1;
		uVar8 = ((uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^ (uVar8 << bVar3 | uVar8 >> 0x20 - bVar3) ^
			uVar8) * 0x20001;
		cVar2 = (char)*(uint*)(unaff_EBP + -0xc);
		bVar3 = cVar2 + 0xfU & 0x1e | 1;
		bVar4 = cVar2 - 3U & 0x1e | 1;
		uVar8 = ~((((uVar8 << bVar3 | uVar8 >> 0x20 - bVar3) ^ (uVar8 << bVar4 | uVar8 >> 0x20 - bVar4) ^
			uVar8) - (*(uint*)(unaff_EBP + -0xc) ^ 0x67ca49df)) * 0x10001);
		iVar6 = *(int*)(unaff_EBP + -0x5c);
		//pdVar11 = (double*)((uVar8 >> 0xc & 0xff) * 0x10 + iVar6);
		//if ((uVar8 & 0x100) == 0) {
		//	puVar9 = (undefined8*)((uVar8 & 0x1ff) * 0x10 + iVar6);
		//}
		//else {
		//	puVar9 = (undefined8*)((uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}
		uint uVar8_2 = uVar8 >> 0x14;
		//if ((uVar8 & 0x100) == 0) {
		//	iVar6 = (uVar8 & 0x1ff) * 0x10 + iVar6;
		//}
		//else {
		//	iVar6 = (uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}

		inst->OP = 12;
		inst->A = (uVar8 >> 0xc & 0xff);
		inst->C = (uVar8_2 & 0x1ff);
		inst->B = (uVar8 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void d21f2(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		undefined4 uVar2;
		int iVar3;
		uint* puVar4;
		char cVar5;
		uint uVar6;
		undefined8* puVar7;
		char* pcVar8;
		sbyte sVar9;
		byte bVar10;
		byte bVar11;
		int iVar12;
		//int unaff_EBP;
		uint uVar13;
		uint* puVar14;

		uVar13 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar13;
		uVar6 = uVar13 & 0x1e | 1;
		param_2 = (param_2 << (10U - (char)uVar13 & 0x1e | 1)) + param_2;
		*(uint*)(unaff_EBP + -4) = uVar6;
		sVar9 = (sbyte)uVar6;
		bVar10 = (char)uVar13 + 0xcU & 0x1e | 1;
		uVar6 = (param_2 -
			(param_2 << (((byte)(0x16 >> sVar9) | (byte)(0x16 << 0x20 - sVar9)) & 0x1e | 1))) +
			0x322db22d;
		bVar11 = (char)*(undefined4*)(unaff_EBP + -0xc) - 10U & 0x1e | 1;
		uVar6 = (uVar6 << bVar10 | uVar6 >> 0x20 - bVar10) ^ (uVar6 >> bVar11 | uVar6 << 0x20 - bVar11) ^
			uVar6;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar11 = ((byte)(0x10 >> bVar10) | (byte)(0x10 << 0x20 - bVar10)) & 0x1e | 1;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar10 = ((byte)(0xd >> bVar10) | (byte)(0xd << 0x20 - bVar10)) & 0x1e | 1;
		iVar12 = *(int*)(unaff_EBP + -0x5c);
		uVar6 = (uVar6 >> bVar11 | uVar6 << 0x20 - bVar11) ^ (uVar6 >> bVar10 | uVar6 << 0x20 - bVar10) ^
			uVar6;
		uVar6 = (uVar6 << ((char)(*(int*)(unaff_EBP + -0xc) << 4) -
			(char)*(undefined4*)(unaff_EBP + -0xc) & 0x1eU | 1) ^ uVar6) * -0x25083107 +
			0xb5ddfc1c;
		//puVar14 = (uint*)((uVar6 >> 0x16 & 0xff) * 0x10 + iVar12);
		//if ((uVar6 & 0x100) == 0) {
		//	puVar7 = (undefined8*)((uVar6 & 0x1ff) * 0x10 + iVar12);
		//}
		//else {
		//	puVar7 = (undefined8*)((uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}
		uint uVar6_2 = uVar6 * 0x400 >> 0x13;
		//*(undefined8**)(unaff_EBP + -0xc) = puVar7;
		//if ((uVar6 & 0x100) == 0) {
		//	iVar12 = (uVar6_2 & 0x1ff) * 0x10 + iVar12;
		//}
		//else {
		//	iVar12 = (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}

		inst->OP = 12;
		inst->A = (uVar6 >> 0x16 & 0xff);
		inst->B = (uVar6 & 0x1ff);
		inst->C = (uVar6_2 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void d36d2(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint uVar2;
		int iVar3;
		uint* puVar4;
		char cVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		int iVar11;
		//int unaff_EBP;
		undefined8* puVar12;
		uint* puVar13;

		uVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		uVar10 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar10;
		sVar7 = (sbyte)uVar10;
		bVar8 = ((byte)(0xe >> sVar7) | (byte)(0xe << 0x20 - sVar7)) & 0x1e | 1;
		uVar10 = ~(param_2 * -0x1f) * 0x25d9dd23;
		uVar10 = (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) * 0x57a27515;
		uVar10 = uVar10 << (((byte)(9 >> sVar7) | (byte)(9 << 0x20 - sVar7)) & 0x1e | 1) ^ uVar10;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte)(0x1e >> bVar8) | (byte)(0x1e << 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(0xd >> bVar8) | (byte)(0xd << 0x20 - bVar8)) & 0x1e | 1;
		uVar10 = ~(((uVar10 >> bVar9 | uVar10 << 0x20 - bVar9) ^
			(uVar10 >> bVar8 | uVar10 << 0x20 - bVar8) ^ uVar10) * 0x7fa21cb7) * 0x46d5825;
		uVar10 = ~(uVar10 >> (-(char)*(undefined4*)(unaff_EBP + -0xc) - 0xcU & 0x1e | 1) ^ uVar10);
		uVar10 = uVar10 >> ((char)*(undefined4*)(unaff_EBP + -0xc) * -4 & 0x1eU | 1) ^ uVar10;
		uVar10 = (uVar10 << 0x1a | uVar10 >> 6) ^ (uVar10 >> 0x17 | uVar10 << 9) ^ uVar10;
		uVar10 = ((uVar10 >> 10 | uVar10 << 0x16) ^ uVar10 >> 1 ^ uVar10) + 0x62e6fcdd;
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		//puVar13 = (uint*)((uVar10 >> 9 & 0xff) * 0x10 + iVar11);
		//if ((uVar10 & 0x100) == 0) {
		//	puVar12 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + iVar11);
		//}
		//else {
		//	puVar12 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}
		uint uVar10_2 = uVar10 >> 0x11;
		//if ((uVar10 & 0x100) == 0) {
		//	iVar11 = (uVar10_2 & 0x1ff) * 0x10 + iVar11;
		//}
		//else {
		//	iVar11 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}

		inst->OP = 12;
		inst->A = (uVar10 >> 9 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar10_2 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void d5372(instr* inst, int param_1, uint param_2) {

		uint uVar1;
		int iVar2;
		uint* puVar3;
		char cVar4;
		char* pcVar5;
		byte bVar6;
		int iVar7;
		uint uVar8;
		uint uVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		uint* puVar11;

		bVar6 = (byte)((-((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2) & 3U) << 3) | 1;
		uVar8 = (param_2 * 0xf4892d0 | (uint)(param_2 * 0x50f4892d) >> 0x1c) + 0xe9775b27;
		uVar8 = uVar8 << bVar6 | uVar8 >> 0x20 - bVar6;
		iVar7 = *(int*)(unaff_EBP + -0x5c);
		uVar8 = (uVar8 >> 0x1d | uVar8 << 3) ^ (uVar8 << 5 | uVar8 >> 0x1b) ^ uVar8;
		uVar9 = uVar8 >> 0x14;
		puVar11 = (uint*)((uVar8 & 0xff) * 0x10 + iVar7);
		//if ((uVar9 & 0x100) == 0) {
		//	puVar10 = (undefined8*)((uVar9 & 0x1ff) * 0x10 + iVar7);
		//}
		//else {
		//	puVar10 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}
		uint uVar8_2 = uVar8 >> 8;
		//if ((uVar8 & 0x100) == 0) {
		//	iVar7 = (uVar8 & 0x1ff) * 0x10 + iVar7;
		//}
		//else {
		//	iVar7 = (uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}

		inst->OP = 12;
		inst->A = (uVar8 & 0xff);
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar8_2 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void d85d6(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		char* pcVar2;
		int iVar3;
		byte bVar4;
		char cVar5;
		undefined4 uVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		int iVar10;
		//int unaff_EBP;
		int iVar11;
		uint uVar12;

		param_2 = ~param_2;
		uVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		param_2 = (param_2 << 0xe | param_2 >> 0x12) ^ (param_2 >> 1 | (uint)((param_2 & 1) != 0) << 0x1f)
			^ param_2;
		bVar4 = (byte)uVar12;
		bVar7 = (bVar4 ^ 0xf1) & 0x1e | 1;
		bVar8 = (bVar4 ^ 6) & 0x1e | 1;
		uVar9 = ((param_2 >> bVar7 | param_2 << 0x20 - bVar7) ^
			(param_2 << bVar8 | param_2 >> 0x20 - bVar8) ^ param_2) + 0xa222269a;
		uVar1 = *(uint*)(unaff_EBP + -0x6c);
		uVar9 = uVar9 << (~bVar4 & 0x1e | 1) ^ uVar9 ^ uVar12 ^ 0x42673762;
		uVar9 = uVar9 << 0x1b ^ uVar9;
		//if ((uVar9 & 0x100) == 0) {
		//	iVar11 = (uVar9 & 0x1ff) * 0x10 + (uVar9 >> 0x17);
		//}
		//else {
		//	iVar11 = (uVar9 & 0xff) * 0x10 + uVar1;
		//}
		uVar12 = uVar9 >> 9;
		//if ((uVar12 & 0x100) == 0) {
		//	iVar10 = (uVar12 & 0x1ff) * 0x10 + (uVar9 >> 0x17);
		//}
		//else {
		//	iVar10 = (uVar12 & 0xff) * 0x10 + uVar1;
		//}

		inst->OP = 12;
		inst->A = uVar9 >> 0x17 & 0xff;
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar12 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void d993e(instr* inst, int param_1, int param_2) {

		byte bVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;
		int iVar7;
		int iVar8;

		uVar6 = param_2 + 0xeb40fd3b;
		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar6 = (uVar6 * 0x1000000 | uVar6 >> 8) ^ (uVar6 >> 5 | uVar6 * 0x8000000) ^ uVar6;
		bVar1 = (byte)iVar8;
		iVar7 = uVar6 - (uVar6 << (bVar1 - 0xb & 0x1e | 1));
		bVar4 = bVar1 & 0x1e | 1;
		uVar6 = (uint)(iVar7 * -0x1fffff) >> 6;
		uVar6 = (uVar6 << 0xf ^ (iVar7 * 0x4000000 | uVar6)) + 0xfd781aaf ^ iVar8 + 0xf2257d4U;
		uVar6 = uVar6 << 0x10 ^ uVar6;
		bVar4 = ((byte)(0x17 >> bVar4) | (byte)(0x17 << 0x20 - bVar4)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar6;
		uVar6 = uVar6 + 0xfc7eaeff;
		uVar6 = uVar6 << bVar4 | uVar6 >> 0x20 - bVar4;
		uVar5 = ~(uVar6 - (uVar6 << (-bVar1 - 8 & 0x1e | 1)) >> 1);
		uVar6 = uVar5 >> 10;
		if ((uVar6 & 0x100) == 0) {
			pcVar3 = (char*)((uVar6 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		}
		else {
			pcVar3 = (char*)((uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(char**)(unaff_EBP + -4) = pcVar3;
		if ((uVar5 & 0x100) == 0) {
			iVar7 = (uVar5 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			iVar7 = (uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 12;
		inst->A = uVar5 >> 0x13 & 0xff;
		inst->B = (uVar6 & 0x1ff);
		inst->C = (uVar5 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void daa16(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		char cVar3;
		undefined8* puVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		int iVar9;
		//int unaff_EBP;
		uint uVar10;
		uint uVar11;

		uVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		uVar11 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar11;
		uVar10 = param_2 - (param_2 << ((char)uVar10 * -4 & 0x1eU | 1));
		sVar6 = (sbyte)uVar11;
		*(uint*)(unaff_EBP + -0x44) = uVar10;
		uVar10 = uVar10 >> 0xf ^ *(uint*)(unaff_EBP + -0x44) ^ 0x142519b1;
		uVar10 = ~(uVar10 >> (((byte)(0x1c << sVar6) | (byte)(0x1c >> 0x20 - sVar6)) & 0x1e | 1) ^ uVar10
			^ 0x2bc8ba3d) ^ *(int*)(unaff_EBP + -0xc) + 0x4f0173f9U;
		uVar10 = (uVar10 << 0xc | uVar10 >> 0x14) ^ (uVar10 << 9 | uVar10 >> 0x17) ^ uVar10;
		uVar10 = ~(uVar10 >> ((char)*(int*)(unaff_EBP + -0xc) - 8U & 0x1e | 1) ^ uVar10);
		uVar10 = uVar10 << (((byte)(0x11 >> sVar6) | (byte)(0x11 << 0x20 - sVar6)) & 0x1e | 1) ^ uVar10;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(5 >> bVar8) | (byte)(5 << 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(3 >> bVar8) | (byte)(3 << 0x20 - bVar8)) & 0x1e | 1;
		uVar10 = ((uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^ (uVar10 >> bVar8 | uVar10 << 0x20 - bVar8)
			^ uVar10) + 0x9e6efc88;
		uVar10 = uVar10 << ((char)*(undefined4*)(unaff_EBP + -0xc) * -9 & 0x1eU | 1) ^ uVar10;
		uint yes = (uVar10 >> 0x13 ^ uVar10);
		uVar11 = yes >> 8;
		if ((uVar11 & 0x100) == 0) {
			puVar4 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		}
		else {
			puVar4 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uVar10 = uVar10 >> 0x11;
		//*(undefined8**)(unaff_EBP + -0xc) = puVar4;
		if ((uVar10 & 0x100) == 0) {
			iVar9 = (uVar10 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			iVar9 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 12;
		inst->A = yes & 0xff;
		inst->B = (uVar11 & 0x1ff);
		inst->C = (uVar10 & 0x1ff);
	}

	// OP_ADD 12 : A B C
	void df3a0(instr* inst, uint param_1, uint param_2) {

		undefined8 uVar1;
		uint* puVar2;
		int iVar3;
		char cVar4;
		char* pcVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		uint uVar9;
		char* pcVar10;
		//int unaff_EBP;
		undefined8* puVar11;

		uVar9 = ~param_2 << 0x12;
		uVar8 = uVar9 | ~param_2 >> 0xe;
		*(uint*)(unaff_EBP + -0x44) = uVar8;
		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar9 = ((uVar9 >> 0x15 | uVar8 << 0xb) ^
			(*(uint*)(unaff_EBP + -0x44) << 4 | *(uint*)(unaff_EBP + -0x44) >> 0x1c) ^
			*(uint*)(unaff_EBP + -0x44)) + uVar7 * 0x14f9ba27 ^ uVar7 ^ 0x28fe4c8d;
		bVar6 = (char)uVar7 - 0x10U & 0x1e | 1;
		uVar9 = (uVar9 << ((char)uVar7 * -5 & 0x1eU | 1)) + uVar9;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar9 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ 0x791766c4;
		pcVar5 = *(char**)(unaff_EBP + -0x5c);
		//*(char**)(unaff_EBP + -4) = pcVar5 + (uVar9 >> 0x12 & 0xff) * 0x10;
		//if ((uVar9 & 0x100) == 0) {
		//	puVar11 = (undefined8*)(pcVar5 + (uVar9 & 0x1ff) * 0x10);
		//}
		//else {
		//	puVar11 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}
		uint uVar9_2 = uVar9 >> 9;
		//if ((uVar9 & 0x100) == 0) {
		//	pcVar10 = pcVar5 + (uVar9 & 0x1ff) * 0x10;
		//}
		//else {
		//	pcVar10 = (char*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}

		inst->OP = 12;
		inst->A = (uVar9 >> 0x12 & 0xff);
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar9_2 & 0x1ff);
	}

	// OP_SUB 13 : A B C
	void d4d6c(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		int iVar2;
		uint* puVar3;
		char cVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		int iVar10;
		undefined8* puVar11;
		//int unaff_EBP;
		uint uVar12;
		uint uVar13;
		uint* puVar14;

		uVar13 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar13;
		uVar9 = uVar13 & 0x1e | 1;
		sVar6 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		uVar12 = (param_2 << (((byte)(2 >> sVar6) | (byte)(2 << 0x20 - sVar6)) & 0x1e | 1)) + param_2;
		bVar7 = (char)uVar13 + 9U & 0x1e | 1;
		bVar8 = (char)uVar13 + 3U & 0x1e | 1;
		uVar12 = (uVar12 << bVar7 | uVar12 >> 0x20 - bVar7) ^ (uVar12 << bVar8 | uVar12 >> 0x20 - bVar8) ^
			uVar12;
		uVar12 = (uVar12 >> 0x1a | uVar12 << 6) ^ (uVar12 << 0x11 | uVar12 >> 0xf) ^ uVar12;
		cVar4 = (char)*(int*)(unaff_EBP + -0xc);
		bVar7 = -((char)(*(int*)(unaff_EBP + -0xc) << 4) - cVar4) & 0x1eU | 1;
		bVar8 = cVar4 * -0xd & 0x1eU | 1;
		uVar12 = (uVar12 >> bVar7 | uVar12 << 0x20 - bVar7) ^ (uVar12 >> bVar8 | uVar12 << 0x20 - bVar8) ^
			uVar12;
		uVar9 = *(uint*)(unaff_EBP + -0xc);
		bVar8 = ((byte)uVar9 ^ 0xf5) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar12 = (uVar9 ^ 0xe98f24c) +
			((uVar12 >> bVar8 | uVar12 << 0x20 - bVar8) ^ (uVar12 << bVar7 | uVar12 >> 0x20 - bVar7)
				^ uVar12) * -0x3ffffff;
		uVar12 = (uVar12 >> 0x10 | uVar12 * 0x10000) - (uVar9 ^ 0x12c91121);
		uVar12 = (uVar12 >> ((byte)uVar9 * -5 & 0x1e | 1) ^ uVar12) + 0x801d1bce;
		uVar12 = uVar12 >> 4 ^ (uVar12 * 0x400000 | uVar12 >> 10) ^ 0x146c29a0 - uVar9 ^ uVar12;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		puVar14 = (uint*)((uVar12 >> 0x13 & 0xff) * 0x10 + iVar10);
		//if ((uVar12 & 0x100) == 0) {
		//	puVar11 = (undefined8*)((uVar12 & 0x1ff) * 0x10 + iVar10);
		//}
		//else {
		//	puVar11 = (undefined8*)((uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		//}
		uint uVar12_2 = uVar12 >> 9;
		//if ((uVar12 & 0x100) == 0) {
		//	iVar10 = (uVar12 & 0x1ff) * 0x10 + iVar10;
		//}
		//else {
		//	iVar10 = (uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		//}

		inst->OP = 13;
		inst->A = (uVar12 >> 0x13 & 0xff);
		inst->B = (uVar12 & 0x1ff);
		inst->C = (uVar12_2 & 0x1ff);
	}

	// OP_SUB 13 : A B C
	void d4dad(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		undefined4 uVar2;
		int iVar3;
		uint* puVar4;
		char cVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		byte bVar10;
		byte bVar11;
		uint uVar12;
		int iVar13;
		//int unaff_EBP;
		undefined8* puVar14;
		uint uVar15;
		uint* puVar16;

		uVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		uVar15 = uVar12 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar15;
		sVar7 = (sbyte)uVar15;
		bVar8 = (char)uVar12 - 2U & 0x1e | 1;
		uVar12 = *(uint*)(unaff_EBP + -0x44) >>
			(((byte)(6 << sVar7) | (byte)(6 >> 0x20 - sVar7)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar12 = (uVar12 << (((byte)(0xe << sVar7) | (byte)(0xe >> 0x20 - sVar7)) & 0x1e | 1)) + uVar12;
		uVar12 = uVar12 >> bVar8 | uVar12 << 0x20 - bVar8;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar9 = 5 - bVar8 & 0x1e | 1;
		bVar10 = 4 - bVar8 & 0x1e | 1;
		bVar11 = (bVar8 ^ 0xfd) & 0x1e | 1;
		uVar12 = (uVar12 >> bVar9 | uVar12 << 0x20 - bVar9) ^ (uVar12 >> bVar10 | uVar12 << 0x20 - bVar10)
			^ uVar12;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		*(uint*)(unaff_EBP + -0x1c) = uVar12;
		bVar8 = ((byte)(5 >> bVar8) | (byte)(5 << 0x20 - bVar8)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x54) = uVar12 >> bVar8 | uVar12 << 0x20 - bVar8;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(3 >> bVar8) | (byte)(3 << 0x20 - bVar8)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x54) =
			*(uint*)(unaff_EBP + -0x54) ^
			(*(uint*)(unaff_EBP + -0x1c) >> bVar8 | *(uint*)(unaff_EBP + -0x1c) << 0x20 - bVar8) ^
			*(uint*)(unaff_EBP + -0x1c);
		uVar12 = *(uint*)(unaff_EBP + -0x54) >> bVar11 | *(uint*)(unaff_EBP + -0x54) << 0x20 - bVar11;
		*(uint*)(unaff_EBP + -0xc) = (*(uint*)(unaff_EBP + -0xc) ^ 6) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar12 = uVar12 - (uVar12 << (((byte)(0x11 >> bVar8) | (byte)(0x11 << 0x20 - bVar8)) & 0x1e | 1));
		uVar12 = uVar12 * 0x200000 | uVar12 >> 0xb;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar12 = uVar12 >> bVar8 | uVar12 << 0x20 - bVar8;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(0xc >> bVar8) | (byte)(0xc << 0x20 - bVar8)) & 0x1e | 1;
		uVar12 = uVar12 >> 0x10 ^ uVar12;
		uVar12 = (uVar12 << bVar8 | uVar12 >> 0x20 - bVar8) * 0x70f235ff + 0x6af45112;
		iVar13 = *(int*)(unaff_EBP + -0x5c);
		puVar16 = (uint*)((uVar12 >> 9 & 0xff) * 0x10 + iVar13);
		if ((uVar12 & 0x100) == 0) {
			//puVar14 = (undefined8*)((uVar12 & 0x1ff) * 0x10 + iVar13);
		}
		else {
			//puVar14 = (undefined8*)((uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar12_2 = uVar12 >> 0x11;
		if ((uVar12 & 0x100) == 0) {
			//iVar13 = (uVar12 & 0x1ff) * 0x10 + iVar13;
		}
		else {
			//iVar13 = (uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 13;
		inst->A = (uVar12 >> 9 & 0xff);
		inst->B = (uVar12 & 0x1ff);
		inst->C = (uVar12_2 & 0x1ff);
	}

	// OP_MUL 14 : A B C
	void d1b3c(instr* inst, uint param_1, uint param_2) {

		ulonglong uVar1;
		ulonglong uVar2;
		//undefined6 uVar3;
		undefined4* puVar4;
		byte bVar5;
		byte bVar6;
		//ushort uVar7;
		char* pcVar9;
		char cVar14;
		//undefined6* puVar10;
		undefined4* puVar11;
		uint uVar12;
		undefined8* puVar13;
		char cVar17;
		uint* puVar15;
		char* pcVar16;
		char* extraout_ECX;
		char cVar22;
		//undefined2 uVar18;
		int iVar19;
		undefined4 uVar20;
		uint uVar21;
		uint unaff_EBX;
		//undefined2* puVar23;
		//undefined4* unaff_EBP;
		uint uVar24;
		undefined4* puVar25;
		char* unaff_EDI;
		//undefined2 in_ES;
		byte in_AF;
		undefined8 uVar26;
		byte* pbVar8;

		uVar24 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar12 = param_2 + 0x1aeea22dU << (-(char)uVar24 - 0xeU & 0x1e | 1) ^ param_2 + 0x1aeea22dU;
		uVar21 = uVar12 * 3;
		uVar21 = (uVar12 * 0x300000 | uVar21 >> 0xc) ^ (uVar21 >> 7 | uVar12 * 0x6000000) ^ uVar21;
		uVar12 = (uVar21 << 0x10 ^ uVar21) - (uVar24 ^ 0x441fad8f);
		uVar21 = uVar12 >> 9;
		//puVar25 = (undefined4*)(unaff_EDI + (uVar12 >> 0x14 & 0xff) * 0x10);
		if ((uVar21 & 0x100) == 0) {
			//puVar13 = (undefined8*)(unaff_EDI + (uVar21 & 0x1ff) * 0x10);
		}
		else {
			//puVar13 = (undefined8*)((uVar21 & 0xff) * 0x10 + unaff_EBP[-0x1b]);
		}
		//unaff_EBP[-3] = puVar13;
		if ((uVar12 & 0x100) == 0) {
			//pcVar16 = unaff_EDI + (uVar12 & 0x1ff) * 0x10;
		}
		else {
			//pcVar16 = (char*)((uVar12 & 0xff) * 0x10 + unaff_EBP[-0x1b]);
		}

		inst->OP = 14;
		inst->A = (uVar12 >> 0x14 & 0xff);
		inst->B = (uVar21 & 0x1ff);
		inst->C = (uVar12 & 0x1ff);
	}

	// OP_MUL 14 : A B C
	void d1ce4(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		undefined4 uVar2;
		undefined4 uVar3;
		int iVar4;
		uint* puVar5;
		char cVar6;
		undefined8* puVar7;
		char* pcVar8;
		sbyte sVar9;
		byte bVar10;
		byte bVar11;
		byte bVar12;
		uint uVar13;
		int iVar14;
		//int unaff_EBP;
		uint uVar15;
		uint* puVar16;

		uVar15 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar15;
		param_2 = param_2 << ((char)uVar15 - 0xcU & 0x1e | 1) ^ param_2;
		uVar13 = uVar15 & 0x1e | 1;
		sVar9 = (sbyte)uVar13;
		*(uint*)(unaff_EBP + -4) = uVar13;
		bVar11 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar10 = bVar11 & 0x1f;
		uVar13 = (param_2 << (((byte)(0x13 >> sVar9) | (byte)(0x13 << 0x20 - sVar9)) & 0x1e | 1)) +
			param_2 ^ uVar15 * 0x3cc736d3;
		bVar10 = ((byte)(0x11 >> bVar10) | (byte)(0x11 << 0x20 - bVar10)) & 0x1e | 1;
		bVar11 = bVar11 & 0x1f;
		bVar11 = ((byte)(0xe >> bVar11) | (byte)(0xe << 0x20 - bVar11)) & 0x1e | 1;
		uVar13 = (uVar13 << 0x11 ^ uVar13) + 0x33bcef59;
		uVar13 = ((uVar13 >> bVar11 | uVar13 << 0x20 - bVar11) ^
			(uVar13 >> bVar10 | uVar13 << 0x20 - bVar10) ^ uVar13) * 0x1000001 ^ 0x4ba898e9;
		uVar13 = uVar13 >> bVar10 ^ uVar13;
		uVar13 = uVar13 << ((char)*(undefined4*)(unaff_EBP + -0xc) + 4U & 0x1e | 1) ^ uVar13;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar13 = (uVar13 << (((byte)(0xb << bVar10) | (byte)(0xb >> 0x20 - bVar10)) & 0x1e | 1) ^ uVar13)
			* -0x1fff;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar11 = bVar10 + 7 & 0x1e | 1;
		bVar12 = bVar10 - 4 & 0x1e | 1;
		uVar13 = uVar13 << bVar11 | uVar13 >> 0x20 - bVar11;
		uVar13 = uVar13 << bVar12 | uVar13 >> 0x20 - bVar12;
		uVar13 = (uVar13 << 0x1d | uVar13 >> 3) ^ (uVar13 << 0xd | uVar13 >> 0x13) ^ uVar13 ^ 0x9d9fa62;
		bVar11 = (bVar10 ^ 10) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar13 << bVar11 | uVar13 >> 0x20 - bVar11;
		bVar10 = (bVar10 ^ 0xfb) & 0x1e | 1;
		iVar14 = *(int*)(unaff_EBP + -0x5c);
		uVar15 = *(uint*)(unaff_EBP + -0xc) ^ (uVar13 >> bVar10 | uVar13 << 0x20 - bVar10) ^ uVar13 ^
			0x2830ac38;
		uVar13 = uVar15 >> 0x11;
		puVar16 = (uint*)((uVar15 >> 9 & 0xff) * 0x10 + iVar14);
		if ((uVar13 & 0x100) == 0) {
			//puVar7 = (undefined8*)((uVar13 & 0x1ff) * 0x10 + iVar14);
		}
		else {
			//puVar7 = (undefined8*)((uVar13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar7;
		if ((uVar15 & 0x100) == 0) {
			//iVar14 = (uVar15 & 0x1ff) * 0x10 + iVar14;
		}
		else {
			//iVar14 = (uVar15 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 14;
		inst->A = (uVar15 >> 9 & 0xff);
		inst->B = (uVar13 & 0x1ff);
		inst->C = (uVar15 & 0x1ff);
	}

	// OP_MUL 14 : A B C
	void d4e35(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		int iVar2;
		uint* puVar3;
		char cVar4;
		char* pcVar5;
		byte bVar6;
		byte bVar7;
		int iVar8;
		undefined8* puVar9;
		//int unaff_EBP;
		uint uVar10;
		uint uVar11;
		uint* puVar12;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		uVar10 = ((uVar11 ^ 0x45245569) + param_2) * -0x1ffffff;
		bVar6 = (char)uVar11 * -0xe & 0x1eU | 1;
		uVar10 = uVar10 >> bVar6 | uVar10 << 0x20 - bVar6;
		uVar10 = (uVar10 << 0x1c | uVar10 >> 4) ^ (uVar10 << 0x18 | uVar10 >> 8) ^ uVar10 ^ uVar11 ^
			0x38f14d51;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar10 = (uVar10 << 0xc | uVar10 >> 0x14) ^ (uVar10 << 6 | uVar10 >> 0x1a) ^ uVar10;
		uVar10 = (uVar10 >> 0x1d | uVar10 << 3) ^ (uVar10 << 0x1d | uVar10 >> 3) ^ uVar10;
		bVar7 = ((byte)(0xf >> bVar6) | (byte)(0xf << 0x20 - bVar6)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar10 << bVar7 | uVar10 >> 0x20 - bVar7;
		bVar6 = ((byte)(0xd >> bVar6) | (byte)(0xd << 0x20 - bVar6)) & 0x1e | 1;
		uVar10 = (*(uint*)(unaff_EBP + -4) ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ uVar10) +
			0xaad6c180;
		cVar4 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar6 = cVar4 * '\x02' & 0x1eU | 1;
		bVar7 = cVar4 * -2 & 0x1eU | 1;
		uVar10 = (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^
			uVar10;
		uVar10 = uVar10 >> 2 ^ (uVar10 << 0xc | uVar10 >> 0x14) ^ uVar10;
		iVar8 = *(int*)(unaff_EBP + -0x5c);
		//puVar12 = (uint*)((uVar10 >> 0x12 & 0xff) * 0x10 + iVar8);
		if ((uVar10 & 0x100) == 0) {
			//puVar9 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + iVar8);
		}
		else {
			//puVar9 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar10_2 = uVar10 >> 9;
		if ((uVar10 & 0x100) == 0) {
			//iVar8 = (uVar10 & 0x1ff) * 0x10 + iVar8;
		}
		else {
			//iVar8 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 14;
		inst->A = (uVar10 >> 0x12 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar10_2 & 0x1ff);
	}

	// OP_MUL 14 : A B C
	void d8131(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		char cVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		char* pcVar10;
		//int unaff_EBP;
		undefined8* puVar11;
		uint uVar12;
		uint* puVar13;

		uVar12 = *(uint*)(unaff_EBP + -0x44) ^ 0x36a3bdf4;
		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		uVar9 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar9;
		uVar12 = uVar12 - (uVar12 << (((byte)uVar8 ^ 0xe) & 0x1e | 1));
		sVar5 = (sbyte)uVar9;
		uVar12 = uVar12 << (((byte)(4 >> sVar5) | (byte)(4 << 0x20 - sVar5)) & 0x1e | 1) ^ uVar12;
		bVar6 = ((byte)(0x18 << sVar5) | (byte)(0x18 >> 0x20 - sVar5)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0xb << bVar7) | (byte)(0xb >> 0x20 - bVar7)) & 0x1e | 1;
		uVar12 = (uVar12 >> bVar6 | uVar12 << 0x20 - bVar6) ^ (uVar12 << bVar7 | uVar12 >> 0x20 - bVar7) ^
			uVar12;
		*(uint*)(unaff_EBP + -0xc) = (*(uint*)(unaff_EBP + -0xc) ^ 4) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar7 = bVar6 & 0x1f;
		bVar7 = ((byte)(7 >> bVar7) | (byte)(7 << 0x20 - bVar7)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar12 << bVar7 | uVar12 >> 0x20 - bVar7;
		bVar6 = bVar6 & 0x1f;
		bVar7 = ((byte)(5 >> bVar6) | (byte)(5 << 0x20 - bVar6)) & 0x1e | 1;
		pcVar4 = *(char**)(unaff_EBP + -0x5c);
		uVar12 = *(uint*)(unaff_EBP + -4) ^ (uVar12 << bVar7 | uVar12 >> 0x20 - bVar7) ^ uVar12;
		uVar8 = (uVar12 << 0x1b | uVar12 >> 5) + 0x472d348d;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar8 = (uVar8 >> bVar7 | uVar8 << 0x20 - bVar7) ^ 0x204e6ce;
		//puVar13 = (uint*)(pcVar4 + (uVar8 >> 0x18) * 0x10);
		if ((uVar8 & 0x100) == 0) {
			//puVar11 = (undefined8*)(pcVar4 + (uVar8 & 0x1ff) * 0x10);
		}
		else {
			//puVar11 = (undefined8*)((uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar8_2 = uVar8 >> 0xf;
		if ((uVar8 & 0x100) == 0) {
			//pcVar10 = pcVar4 + (uVar8 & 0x1ff) * 0x10;
		}
		else {
			//pcVar10 = (char*)((uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 14;
		inst->A = (uVar8 >> 0x18);
		inst->B = (uVar8 & 0x1ff);
		inst->C = (uVar8_2 & 0x1ff);
	}

	// OP_MUL 14 : A B C
	void dd41e(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		int iVar2;
		uint* puVar3;
		char cVar4;
		undefined8* puVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;
		int iVar11;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar11;
		bVar6 = (byte)iVar11 & 0x1e | 1;
		uVar9 = param_2 * 0x801 + iVar11 * -0x6a0fdae3;
		uVar9 = uVar9 << (((byte)(0x10 >> bVar6) | (byte)(0x10 << 0x20 - bVar6)) & 0x1e | 1) ^ uVar9;
		cVar4 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar6 = (byte)iVar11 * '\b' - cVar4 & 0x1e | 1;
		uVar9 = ~(uVar9 << bVar6 ^ uVar9);
		uVar9 = (uVar9 << (cVar4 * '\x03' & 0x1eU | 1)) + uVar9;
		cVar4 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar7 = cVar4 - 0xfU & 0x1e | 1;
		bVar8 = cVar4 + 0xdU & 0x1e | 1;
		uVar9 = ((uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^ (uVar9 << bVar8 | uVar9 >> 0x20 - bVar8) ^
			uVar9) + 0xd2742622;
		uVar9 = (uVar9 >> 0x13 | uVar9 * 0x2000) ^ (uVar9 >> 8 | uVar9 * 0x1000000) ^ uVar9;
		uVar9 = (uVar9 >> 0x1e | uVar9 << 2) ^ (uVar9 << 0x1d | uVar9 >> 3) ^ uVar9;
		cVar4 = (char)*(int*)(unaff_EBP + -0xc);
		uVar9 = (uVar9 - (uVar9 << bVar6)) + 0xaab97cfc;
		uVar9 = ~(uVar9 << (cVar4 - 9U & 0x1e | 1) ^ uVar9);
		uVar9 = uVar9 << 0x14 | uVar9 >> 0xc;
		uVar9 = uVar9 << (cVar4 + 2U & 0x1e | 1) ^ uVar9;
		uVar10 = *(int*)(unaff_EBP + -0xc) + -0x4d34f6cb + (uVar9 * 8 ^ uVar9 ^ 0x237aa635);
		uVar9 = uVar10 >> 0x11;
		if ((uVar9 & 0x100) == 0) {
			//puVar5 = (undefined8*)((uVar9 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		}
		else {
			//puVar5 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar10_2 = uVar10 >> 8;
		//*(undefined8**)(unaff_EBP + -0xc) = puVar5;
		if ((uVar10 & 0x100) == 0) {
			//iVar11 = (uVar10 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar11 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 14;
		inst->A = uVar10 & 0xff;
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar10_2 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void d0c84(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint uVar2;
		undefined4 uVar3;
		int iVar4;
		uint* puVar5;
		char cVar6;
		char* pcVar7;
		byte bVar8;
		byte bVar9;
		undefined8* puVar10;
		uint uVar11;
		int iVar12;
		//int unaff_EBP;
		uint* puVar13;

		bVar9 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar8 = -bVar9 - 10 & 0x1e | 1;
		uVar11 = (param_2 << bVar8 | param_2 >> 0x20 - bVar8) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar8 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar8) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar8 = (bVar9 ^ 6) & 0x1e | 1;
		uVar11 = (uVar11 << 0x1d | uVar11 >> 3) ^ (uVar11 >> 0x1a | uVar11 << 6) ^ uVar11;
		bVar9 = (bVar9 ^ 0xfd) & 0x1e | 1;
		uVar11 = (uVar11 >> bVar8 | uVar11 << 0x20 - bVar8) ^ (uVar11 << bVar9 | uVar11 >> 0x20 - bVar9) ^
			uVar11;
		uVar11 = ~((uVar11 << 0xf | uVar11 >> 0x11) ^ (uVar11 << 7 | uVar11 >> 0x19) ^ uVar11);
		uVar11 = uVar11 << 0xb ^ uVar11;
		iVar12 = *(int*)(unaff_EBP + -0x5c);
		//puVar13 = (uint*)((uVar11 >> 0xd & 0xff) * 0x10 + iVar12);
		if ((uVar11 & 0x100) == 0) {
			//puVar10 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + iVar12);
		}
		else {
			//puVar10 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar11_2 = uVar11 >> 0x15;
		if ((uVar11 & 0x100) == 0) {
			//iVar12 = (uVar11 & 0x1ff) * 0x10 + iVar12;
		}
		else {
			//iVar12 = (uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = (uVar11 >> 0xd & 0xff);
		inst->B = (uVar11 & 0x1ff);
		inst->C = (uVar11_2 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void d4223(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		char cVar3;
		uint uVar4;
		undefined8* puVar5;
		char* pcVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		uint uVar10;
		int iVar11;
		//int unaff_EBP;
		uint* puVar12;

		bVar8 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar7 = bVar8 & 0x1e | 1;
		bVar8 = (bVar8 ^ 0xf5) & 0x1e | 1;
		bVar7 = ((byte)(0x1b << bVar7) | (byte)(0x1b >> 0x20 - bVar7)) & 0x1e | 1;
		uVar9 = ((param_2 << bVar7 | param_2 >> 0x20 - bVar7) * 0x7a0ee99 ^ 0x3d2a33dd) + 0x6fa27c7a;
		*(uint*)(unaff_EBP + -0xc) =
			(uVar9 * 0x40000000 | uVar9 >> 2) ^ (uVar9 >> 0xc | uVar9 * 0x100000) ^ uVar9;
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = (*(uint*)(unaff_EBP + -0xc) << bVar8 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar8) +
			0x88598048;
		uVar9 = uVar10 >> 8;
		uVar10 = uVar10 * 0x1000000;
		uVar4 = (uVar9 | uVar10) >> 0x11;
		//puVar12 = (uint*)(((uVar9 & 0x1fe00) >> 9) * 0x10 + iVar11);
		if ((uVar10 & 0x2000000) == 0) {
			//puVar5 = (undefined8*)((uVar4 & 0x1ff) * 0x10 + iVar11);
		}
		else {
			//puVar5 = (undefined8*)((uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar5;
		if ((uVar9 & 0x100) == 0) {
			//iVar11 = (uVar9 & 0x1ff) * 0x10 + iVar11;
		}
		else {
			//iVar11 = (uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = (uVar9 & 0x1fe00) >> 9;
		inst->B = (uVar4 & 0x1ff);
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void d4281(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char cVar2;
		char* pcVar3;
		char* pcVar4;
		uint uVar5;
		undefined8* puVar6;
		char* extraout_ECX;
		uint uVar7;
		int iVar8;
		char* pcVar9;
		//int unaff_EBP;
		undefined8 uVar10;

		uVar5 = ((param_2 << 0x1a | param_2 >> 6) ^ (param_2 >> 9 | param_2 << 0x17) ^ param_2) +
			((*(int*)(unaff_EBP + -0x50) - *(int*)(unaff_EBP + -100)) + -8 >> 2) + -0x3a0f4688;
		uVar5 = (uVar5 * 0x200000 | uVar5 >> 0xb) ^ (uVar5 * 0x1000 | uVar5 >> 0x14) ^ uVar5;
		uVar5 = (uVar5 >> 0xe | uVar5 << 0x12) ^ (uVar5 >> 4 | uVar5 << 0x1c) ^ uVar5;
		uVar7 = ((uVar5 << 0x18 | uVar5 >> 8) ^ (uVar5 >> 0xd | uVar5 << 0x13) ^ uVar5) + 0x25aa97a3;
		uVar5 = uVar7 >> 0xc;
		if ((uVar5 & 0x100) == 0) {
			//puVar6 = (undefined8*)((uVar5 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		}
		else {
			//puVar6 = (undefined8*)((uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar7_2 = uVar7 >> 0x15;
		if ((uVar7 & 0x100) == 0) {
			//iVar8 = (uVar7 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar8 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = uVar7 & 0xff;
		inst->B = (uVar5 & 0x1ff);
		inst->C = (uVar7_2 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void d73f0(instr* inst, uint param_1, uint param_2) {

		undefined8 uVar1;
		uint uVar2;
		uint* puVar3;
		undefined4 uVar4;
		undefined4 uVar5;
		int iVar6;
		char cVar7;
		undefined8* puVar8;
		char* pcVar9;
		byte bVar10;
		byte bVar11;
		uint uVar12;
		uint uVar13;
		//int unaff_EBP;
		int iVar14;

		param_2 = ~param_2;
		*(uint*)(unaff_EBP + -0x44) = param_2;
		iVar14 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar12 = (param_2 >> 0xc | param_2 << 0x14) ^
			(*(uint*)(unaff_EBP + -0x44) >> 6 | *(uint*)(unaff_EBP + -0x44) << 0x1a) ^
			*(uint*)(unaff_EBP + -0x44);
		*(int*)(unaff_EBP + -0xc) = iVar14;
		bVar10 = (byte)iVar14 & 0x1e | 1;
		bVar11 = ((byte)(0x19 << bVar10) | (byte)(0x19 >> 0x20 - bVar10)) & 0x1e | 1;
		uVar12 = ((uVar12 << ((byte)iVar14 * -0x10 & 0x1e | 1) ^ uVar12 ^ 0x47959f7f) + iVar14) *
			0x559458e9 + 0xee3ff813;
		*(uint*)(unaff_EBP + -4) = uVar12;
		bVar10 = ((byte)(0x14 << bVar10) | (byte)(0x14 >> 0x20 - bVar10)) & 0x1e | 1;
		uVar12 = (uVar12 >> bVar11 | uVar12 << 0x20 - bVar11) ^
			(*(uint*)(unaff_EBP + -4) << bVar10 | *(uint*)(unaff_EBP + -4) >> 0x20 - bVar10) ^
			*(uint*)(unaff_EBP + -4);
		uVar12 = (uVar12 >> 0x13 | uVar12 << 0xd) ^ (uVar12 >> 10 | uVar12 << 0x16) ^ uVar12;
		uVar12 = uVar12 >> 0x1c ^ uVar12;
		bVar10 = (byte) * (int*)(unaff_EBP + -0xc);
		uVar12 = (uVar12 - (uVar12 << ((bVar10 ^ 0xfb) & 0x1e | 1))) * 0x139a7431;
		uVar12 = uVar12 >> 0x19 ^ uVar12;
		uVar12 = uVar12 << (0xb - bVar10 & 0x1e | 1) ^ uVar12;
		bVar10 = (byte)((-*(int*)(unaff_EBP + -0xc) & 1U) << 4) | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		uVar13 = uVar12 << bVar10 | uVar12 >> 0x20 - bVar10;
		iVar14 = *(int*)(unaff_EBP + -0x5c);
		uVar12 = uVar13 >> 0x17;
		//*(uint*)(unaff_EBP + -4) = (uVar13 & 0xff) * 0x10 + iVar14;
		if ((uVar12 & 0x100) == 0) {
			//puVar8 = (undefined8*)(uVar12 * 0x10 + iVar14);
		}
		else {
			//puVar8 = (undefined8*)((uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar13_2 = uVar13 >> 8;
		//*(undefined8**)(unaff_EBP + -0x1c) = puVar8;
		if ((uVar13 & 0x100) == 0) {
			//iVar14 = (uVar13 & 0x1ff) * 0x10 + iVar14;
		}
		else {
			//iVar14 = (uVar13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = (uVar13 & 0xff);
		inst->B = uVar12;
		inst->C = (uVar13_2 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void da2de(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		char* pcVar2;
		int iVar3;
		uint* puVar4;
		char cVar5;
		undefined8* puVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;
		uint uVar11;
		uint* puVar12;

		uVar11 = param_2 * -0x1fffffff;
		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar10;
		*(uint*)(unaff_EBP + -0x44) = uVar11;
		bVar7 = (byte)iVar10 & 0x1e | 1;
		bVar8 = ((byte)(8 >> bVar7) | (byte)(8 << 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = ((byte)(2 >> bVar7) | (byte)(2 << 0x20 - bVar7)) & 0x1e | 1;
		uVar11 = (uVar11 >> bVar8 | uVar11 << 0x20 - bVar8) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar7 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar7 = (char)*(int*)(unaff_EBP + -0xc) * '\x04' & 0x1eU | 1;
		bVar8 = (byte)((-*(int*)(unaff_EBP + -0xc) & 7U) << 2) | 1;
		uVar11 = ((uVar11 << bVar7 | uVar11 >> 0x20 - bVar7) ^ (uVar11 << bVar8 | uVar11 >> 0x20 - bVar8)
			^ uVar11) * 0x7a69d8ab;
		uVar11 = uVar11 >> 0xb ^ uVar11;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = ~(((uVar11 << 0x17 | uVar11 >> 9) ^ (uVar11 << 0x15 | uVar11 >> 0xb) ^ uVar11) *
			0x41d1bc29);
		uVar11 = uVar9 >> 0x13;
		//puVar12 = (uint*)((uVar9 >> 0xb & 0xff) * 0x10 + iVar10);
		if ((uVar11 & 0x100) == 0) {
			//puVar6 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + iVar10);
		}
		else {
			//puVar6 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -0xc) = puVar6;
		if ((uVar9 & 0x100) == 0) {
			//iVar10 = (uVar9 & 0x1ff) * 0x10 + iVar10;
		}
		else {
			//iVar10 = (uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = (uVar9 >> 0xb & 0xff);
		inst->B = (uVar11 & 0x1ff);
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void dad9d(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		undefined4 uVar2;
		int iVar3;
		code* pcVar4;
		uint* puVar5;
		char cVar6;
		char* pcVar7;
		byte bVar8;
		byte bVar9;
		byte bVar10;
		int iVar11;
		uint uVar12;
		uint uVar13;
		undefined8* puVar14;
		//int unaff_EBP;
		uint* puVar15;

		uVar12 = param_2 * 0x200001;
		cVar6 = (char)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar8 = 0xbU - cVar6 & 0x1e | 1;
		bVar9 = 9U - cVar6 & 0x1e | 1;
		bVar10 = cVar6 + 7U & 0x1e | 1;
		uVar12 = (uVar12 << bVar8 | uVar12 >> 0x20 - bVar8) ^ (uVar12 >> bVar9 | uVar12 << 0x20 - bVar9) ^
			uVar12;
		bVar8 = cVar6 - 3U & 0x1e | 1;
		uVar12 = (uVar12 << bVar10 | uVar12 >> 0x20 - bVar10) ^ (uVar12 << bVar8 | uVar12 >> 0x20 - bVar8)
			^ uVar12;
		bVar8 = 10U - cVar6 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar12 >> bVar8 | uVar12 << 0x20 - bVar8;
		bVar8 = -cVar6 - 7U & 0x1e | 1;
		uVar12 = *(uint*)(unaff_EBP + -0xc) ^ (uVar12 >> bVar8 | uVar12 << 0x20 - bVar8) ^ uVar12 ^
			0x1cdd765;
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		uVar13 = uVar12 >> 0x17;
		//puVar15 = (uint*)((uVar12 >> 9 & 0xff) * 0x10 + iVar11);
		if ((uVar13 & 0x100) == 0) {
			//puVar14 = (undefined8*)(uVar13 * 0x10 + iVar11);
		}
		else {
			//puVar14 = (undefined8*)((uVar13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		if ((uVar12 & 0x100) == 0) {
			//iVar11 = (uVar12 & 0x1ff) * 0x10 + iVar11;
		}
		else {
			//iVar11 = (uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = (uVar12 >> 9 & 0xff);
		inst->B = uVar13;
		inst->C = (uVar12 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void db5be(instr* inst, uint param_1, uint param_2) {

		int** ppiVar1;
		int iVar2;
		int* piVar3;
		uint uVar4;
		undefined8* puVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		int iVar9;
		uint uVar10;
		undefined4 extraout_ECX;
		int* extraout_EDX;
		int iVar11;
		//int unaff_EBP;
		int* piVar12;
		undefined8 uVar13;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		param_2 = (param_2 << 0xf | param_2 >> 0x11) ^ (param_2 << 0xe | param_2 >> 0x12) ^ param_2;
		bVar6 = ((byte)iVar9 ^ 0xf7) & 0x1e | 1;
		bVar7 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 2) & 0x1e | 1;
		bVar8 = (byte)((-iVar9 & 7U) << 2) | 1;
		param_2 = (param_2 >> bVar6 | param_2 << 0x20 - bVar6) ^
			(param_2 >> bVar7 | param_2 << 0x20 - bVar7) ^ 0x3c146706U - *(int*)(unaff_EBP + -0xc)
			^ param_2;
		iVar9 = (param_2 << bVar8 | param_2 >> 0x20 - bVar8) + 0xdb0d15aa + *(int*)(unaff_EBP + -0xc);
		uVar10 = iVar9 + -0x4562e7a9 + (iVar9 << ((char)*(int*)(unaff_EBP + -0xc) + 10U & 0x1e | 1));
		uVar4 = uVar10 * 0x10;
		uVar10 = uVar10 >> 0x1c | uVar4;
		uVar10 = ((uVar4 >> 0xc | uVar10 << 0x14) ^ (uVar10 << 8 | uVar4 >> 0x18) ^ uVar10) + 0xd6c69b2f;
		uVar4 = uVar10 >> 0x16;
		if ((uVar4 & 0x100) == 0) {
			//puVar5 = (undefined8*)((uVar4 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		}
		else {
			//puVar5 = (undefined8*)((uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar10_2 = uVar10 >> 8;
		//*(undefined8**)(unaff_EBP + -0xc) = puVar5;
		if ((uVar10 & 0x100) == 0) {
			//iVar9 = (uVar10 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar9 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = uVar10 & 0xff;
		inst->B = (uVar4 & 0x1ff);
		inst->C = (uVar10_2 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void dc9c9(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint uVar2;
		undefined4 uVar3;
		char* pcVar4;
		int iVar5;
		//undefined6 uVar6;
		uint* puVar7;
		char cVar8;
		uint uVar9;
		//undefined6* puVar10;
		byte bVar11;
		byte bVar12;
		int iVar13;
		char* unaff_EBX;
		//int unaff_EBP;
		undefined8* puVar14;
		uint* puVar15;

		uVar9 = (param_2 * 0x400000 | (uint)(param_2 * 0x8001) >> 10) + 0x814cc031;
		cVar8 = (char)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		uVar9 = uVar9 >> (cVar8 + 2U & 0x1e | 1) ^ uVar9;
		bVar11 = cVar8 + 0xbU & 0x1e | 1;
		bVar12 = cVar8 - 4U & 0x1e | 1;
		uVar9 = (uVar9 << bVar11 | uVar9 >> 0x20 - bVar11) ^ (uVar9 >> bVar12 | uVar9 << 0x20 - bVar12) ^
			uVar9;
		uVar9 = (uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 >> 0xb | uVar9 << 0x15) ^ uVar9;
		uVar9 = uVar9 << 0xc ^ uVar9;
		iVar13 = *(int*)(unaff_EBP + -0x5c);
		//puVar15 = (uint*)((uVar9 >> 9 & 0xff) * 0x10 + iVar13);
		if ((uVar9 & 0x100) == 0) {
			//puVar14 = (undefined8*)((uVar9 & 0x1ff) * 0x10 + iVar13);
		}
		else {
			//puVar14 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar9_2 = uVar9 >> 0x12;
		if ((uVar9 & 0x100) == 0) {
			//iVar13 = (uVar9 & 0x1ff) * 0x10 + iVar13;
		}
		else {
			//iVar13 = (uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = (uVar9 >> 9 & 0xff);
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar9_2 & 0x1ff);
	}

	// OP_DIV 15 : A B C
	void dd601(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		undefined4 uVar2;
		int iVar3;
		code* pcVar4;
		uint* puVar5;
		char cVar6;
		uint uVar7;
		undefined8* puVar8;
		char* pcVar9;
		byte bVar10;
		byte bVar11;
		uint uVar12;
		int iVar13;
		//int unaff_EBP;

		bVar11 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar10 = bVar11 & 0x1e | 1;
		uVar12 = (0x130d4de4 << bVar10 | 0x130d4de4U >> 0x20 - bVar10) ^
			*(uint*)(unaff_EBP + -0x44) >> (1 - bVar11 & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44);
		uVar12 = uVar12 >> 0x16 ^ uVar12;
		uVar12 = uVar12 - (uVar12 << (((byte)(6 << bVar10) | (byte)(6 >> 0x20 - bVar10)) & 0x1e | 1));
		bVar11 = ((byte)(0xb >> bVar10) | (byte)(0xb << 0x20 - bVar10)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar12 << bVar11 | uVar12 >> 0x20 - bVar11;
		bVar11 = ((byte)(3 >> bVar10) | (byte)(3 << 0x20 - bVar10)) & 0x1e | 1;
		uVar12 = *(uint*)(unaff_EBP + -0xc) ^ (uVar12 >> bVar11 | uVar12 << 0x20 - bVar11) ^ uVar12;
		uVar7 = uVar12 >> 0x15;
		if ((uVar7 & 0x100) == 0) {
			//puVar8 = (undefined8*)((uVar7 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		}
		else {
			//puVar8 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar8;
		if ((uVar12 & 0x100) == 0) {
			//iVar13 = (uVar12 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar13 = (uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 15;
		inst->A = uVar12 >> 0x9 & 0xff;
		inst->B = (uVar7 & 0x1ff);
		inst->C = (uVar12 & 0x1ff);
	}

	// OP_MOD 16 : A B C
	void d34b9(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint* puVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		char* pcVar8;
		uint uVar9;
		uint uVar10;
		undefined8* puVar11;
		//int unaff_EBP;
		int iVar12;
		//float10 extraout_ST0;

		uVar9 = param_2 + 0x853e9af2U >> 5;
		iVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar12;
		uVar9 = ~(uVar9 << 0x1a ^ ((param_2 + 0x853e9af2U) * 0x8000000 | uVar9)) * 0x81;
		cVar3 = (char)iVar12;
		bVar5 = cVar3 - 0xcU & 0x1e | 1;
		bVar6 = cVar3 + 8U & 0x1e | 1;
		uVar9 = (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^ (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^
			uVar9;
		uVar9 = (uVar9 >> 0xf | uVar9 << 0x11) ^ (uVar9 << 4 | uVar9 >> 0x1c) ^ uVar9;
		cVar1 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar9 = uVar9 >> 0x1c ^ uVar9;
		bVar5 = -(cVar3 * '\x04' - cVar1) & 0x1eU | 1;
		bVar6 = cVar1 * -0xe & 0x1eU | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar9 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ (uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) ^
			uVar9;
		uVar9 = ((uVar9 << 0x12 | uVar9 >> 0xe) ^ (uVar9 << 0xb | uVar9 >> 0x15) ^ uVar9) + 0xa8beed21;
		uVar9 = uVar9 >> bVar5 | uVar9 << 0x20 - bVar5;
		uVar9 = (uVar9 << (((byte)(0x1a << bVar7) | (byte)(0x1a >> 0x20 - bVar7)) & 0x1e | 1) ^ uVar9) -
			(0x18a540e2U >> bVar7 | 0x18a540e2 << 0x20 - bVar7);
		uVar9 = (uVar9 * 0x10000000 | uVar9 >> 4) ^ (uVar9 >> 6 | uVar9 * 0x4000000) ^ uVar9;
		pcVar4 = *(char**)(unaff_EBP + -0x5c);
		uVar10 = uVar9 >> 0x17;
		//*(char**)(unaff_EBP + -0xc) = pcVar4 + (uVar9 >> 9 & 0xff) * 0x10;
		if ((uVar10 & 0x100) == 0) {
			//puVar11 = (undefined8*)(pcVar4 + uVar10 * 0x10);
		}
		else {
			//puVar11 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		if ((uVar9 & 0x100) == 0) {
			//pcVar8 = pcVar4 + (uVar9 & 0x1ff) * 0x10;
		}
		else {
			//pcVar8 = (char*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 16;
		inst->A = (uVar9 >> 9 & 0xff);
		inst->B = uVar10;
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_MOD 16 : A B C
	void d84be(instr* inst, uint param_1, uint param_2) {

		byte bVar1;
		uint* puVar2;
		char cVar3;
		undefined8* puVar4;
		char* pcVar5;
		sbyte sVar6;
		uint uVar7;
		uint uVar8;
		undefined8* puVar9;
		//int unaff_EBP;
		int iVar10;
		uint uVar11;
		//float10 extraout_ST0;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		param_2 = (param_2 << 0x1b | param_2 >> 5) ^ (param_2 << 4 | param_2 >> 0x1c) ^ param_2;
		uVar7 = param_2 << 1 | (uint)((int)param_2 < 0);
		uVar8 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		sVar6 = (sbyte)uVar8;
		uVar7 = (((param_2 << 1) >> 3 | uVar7 << 0x1d) ^
			(param_2 & 0x7fffffff | (uint)((int)param_2 < 0 != 0) << 0x1f) ^ uVar7) -
			(uVar11 ^ 0x72611257) ^ (0x73169de6 << sVar6 | 0x73169de6U >> 0x20 - sVar6);
		iVar10 = uVar7 - (uVar7 << (((byte)(0x1c >> sVar6) | (byte)(0x1c << 0x20 - sVar6)) & 0x1e | 1));
		uVar8 = iVar10 - (iVar10 << ((char)uVar11 - 2U & 0x1e | 1));
		uVar8 = uVar8 * 0x1000 ^ uVar8;
		bVar1 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar8 = (uVar8 >> 0x19 | uVar8 << 7) ^ (uVar8 << 8 | uVar8 >> 0x18) ^ uVar8;
		iVar10 = *(int*)(unaff_EBP + -0x5c);
		uVar8 = (uVar8 << (((byte)(0x11 >> bVar1) | (byte)(0x11 << 0x20 - bVar1)) & 0x1e | 1)) + uVar8;
		uVar7 = uVar8 >> 9;
		//*(uint*)(unaff_EBP + -0xc) = (uVar8 >> 0x12 & 0xff) * 0x10 + iVar10;
		if ((uVar7 & 0x100) == 0) {
			//puVar4 = (undefined8*)((uVar7 & 0x1ff) * 0x10 + iVar10);
		}
		else {
			//puVar4 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar4;
		//puVar2 = _DAT_10675ab8;
		if ((uVar8 & 0x100) == 0) {
			//puVar9 = (undefined8*)((uVar8 & 0x1ff) * 0x10 + iVar10);
		}
		else {
			//puVar9 = (undefined8*)((uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 16;
		inst->A = (uVar8 >> 0x12 & 0xff);
		inst->B = (uVar7 & 0x1ff);
		inst->C = (uVar8 & 0x1ff);
	}

	// OP_MOD 16 : A B C
	void db178(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		char cVar3;
		char* pcVar4;
		uint uVar5;
		char* pcVar6;
		uint uVar7;
		undefined8* puVar8;
		//int unaff_EBP;
		//float10 extraout_ST0;

		*(int*)(unaff_EBP + -0x44) = param_2 * -0x7f;
		uVar7 = (param_2 * -0x7f00 | (uint)(param_2 * -0x7f) >> 0x18) ^
			(*(uint*)(unaff_EBP + -0x44) >> 3 | *(uint*)(unaff_EBP + -0x44) << 0x1d) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = uVar7 >> (((byte)((*(int*)(unaff_EBP + -0x50) - *(int*)(unaff_EBP + -100)) + -8 >> 2) ^
			0xfd) & 0x1e | 1) ^ uVar7;
		uVar5 = uVar7 * 0x45d23589;
		uVar5 = (uVar5 >> 0x1b | uVar7 * -0x45b94ee0) ^ (uVar5 >> 0x1a | uVar7 * 0x748d6240) ^ uVar5;
		uVar7 = uVar5 >> 0xf ^ uVar5;
		pcVar4 = *(char**)(unaff_EBP + -0x5c);
		uVar5 = uVar5 >> 0x14;
		//*(char**)(unaff_EBP + -0xc) = pcVar4 + (uVar7 >> 9 & 0xff) * 0x10;
		if ((uVar5 & 0x100) == 0) {
			//puVar8 = (undefined8*)(pcVar4 + (uVar5 & 0x1ff) * 0x10);
		}
		else {
			//puVar8 = (undefined8*)((uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		if ((uVar7 & 0x100) == 0) {
			//pcVar6 = pcVar4 + (uVar7 & 0x1ff) * 0x10;
		}
		else {
			//pcVar6 = (char*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 16;
		inst->A = (uVar7 >> 9 & 0xff);
		inst->B = (uVar5 & 0x1ff);
		inst->C = (uVar7 & 0x1ff);
	}

	// OP_MOD 16 : A B C
	void dc168(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		byte bVar2;
		uint* puVar3;
		char cVar4;
		int iVar5;
		byte bVar6;
		byte bVar7;
		char* pcVar8;
		uint uVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		uint uVar11;
		//float10 fVar12;

		uVar11 = param_2 * 0x48a01e79;
		bVar2 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar6 = (bVar2 ^ 8) & 0x1e | 1;
		bVar7 = (bVar2 ^ 0xf9) & 0x1e | 1;
		uVar11 = (uVar11 << bVar6 | uVar11 >> 0x20 - bVar6) ^ (uVar11 << bVar7 | uVar11 >> 0x20 - bVar7) ^
			uVar11;
		uVar11 = ~(uVar11 * 0x20010 ^ uVar11 * 0x2001) + 0x2327f7bc;
		uVar11 = ~(uVar11 * 0x2000000 | uVar11 >> 7);
		iVar5 = uVar11 << (bVar2 * -7 & 0x1e | 1);
		*(int*)(unaff_EBP + -0xc) = iVar5;
		uVar11 = iVar5 + uVar11;
		pcVar1 = *(char**)(unaff_EBP + -0x5c);
		uVar9 = uVar11 >> 0x11;
		//*(char**)(unaff_EBP + -4) = pcVar1 + (uVar11 >> 9 & 0xff) * 0x10;
		if ((uVar9 & 0x100) == 0) {
			//puVar10 = (undefined8*)(pcVar1 + (uVar9 & 0x1ff) * 0x10);
		}
		else {
			//puVar10 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		if ((uVar11 & 0x100) == 0) {
			//pcVar8 = pcVar1 + (uVar11 & 0x1ff) * 0x10;
		}
		else {
			//pcVar8 = (char*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 16;
		inst->A = (uVar11 >> 9 & 0xff);
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar11 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void d4cba(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint uVar2;
		byte bVar3;
		uint* puVar4;
		char cVar5;
		undefined8* puVar6;
		char* pcVar7;
		sbyte sVar8;
		byte bVar9;
		uint uVar10;
		uint uVar11;
		undefined8* puVar12;
		//int unaff_EBP;
		undefined8 uVar13;

		uVar10 = *(int*)(unaff_EBP + -0x44) + 0x21121c93;
		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		uVar11 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar11;
		uVar10 = (uVar10 * 0x8000000 | uVar10 >> 5) ^ (uVar10 * 0x2000000 | uVar10 >> 7) ^ uVar10;
		sVar8 = (sbyte)uVar11;
		uVar10 = uVar10 - (uVar10 << (((byte)(5 >> sVar8) | (byte)(5 << 0x20 - sVar8)) & 0x1e | 1));
		uVar10 = (uVar10 * 0x40000 | uVar10 >> 0xe) ^ (uVar10 * 8 | uVar10 >> 0x1d) ^ uVar10;
		uVar10 = uVar10 << 0x1b | uVar10 >> 5;
		uVar10 = uVar10 >> (((byte)(8 >> sVar8) | (byte)(8 << 0x20 - sVar8)) & 0x1e | 1) ^ uVar10 ^
			0x480a259e;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar9 = ((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xfb) & 0x1e | 1;
		uVar10 = (0x2a1f8618 << bVar3 | 0x2a1f8618U >> 0x20 - bVar3) ^
			(uVar10 >> (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xfd) & 0x1e | 1) ^ uVar10) *
			0x200001;
		uVar10 = uVar10 << bVar9 | uVar10 >> 0x20 - bVar9;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = (uVar10 - (uVar10 << (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 4) & 0x1e | 1))) +
			0x57238c42;
		uVar11 = (uVar10 >> 0xc | uVar10 * 0x100000) * 0x2dbb5ced;
		uVar10 = uVar11 >> 8;
		//*(uint*)(unaff_EBP + -0xc) = (uVar11 & 0xff) * 0x10 + iVar1;
		if ((uVar10 & 0x100) == 0) {
			//puVar6 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + iVar1);
		}
		else {
			//puVar6 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar11_2 = uVar11 >> 0x11;
		//*(undefined8**)(unaff_EBP + -4) = puVar6;
		//puVar4 = _DAT_10675ab8;
		if ((uVar11 & 0x100) == 0) {
			//puVar12 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + iVar1);
		}
		else {
			//puVar12 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar11 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar11_2 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void d57a7(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		char cVar3;
		uint uVar4;
		char* pcVar5;
		byte bVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		uint uVar11;
		undefined8* puVar12;
		//int unaff_EBP;
		undefined8* puVar13;
		undefined8 uVar14;

		uVar4 = *(int*)(unaff_EBP + -0x44) + 0xcffbb0aa;
		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		uVar4 = uVar4 << ((char)uVar11 - 0xfU & 0x1e | 1) ^ uVar4;
		uVar10 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar10;
		bVar6 = (char)uVar11 + 5U & 0x1e | 1;
		sVar7 = (sbyte)uVar10;
		uVar4 = uVar4 >> (((byte)(0xf << sVar7) | (byte)(0xf >> 0x20 - sVar7)) & 0x1e | 1) ^ uVar4;
		uVar4 = (uVar4 << bVar6 | uVar4 >> 0x20 - bVar6) - (*(uint*)(unaff_EBP + -0xc) ^ 0x7f702823);
		iVar1 = *(int*)(unaff_EBP + -0xc);
		uVar10 = ~(uVar4 * 0x100000 ^ uVar4);
		uVar10 = uVar10 >> (-(char)*(undefined4*)(unaff_EBP + -0xc) - 2U & 0x1e | 1) ^ uVar10;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar10 = uVar10 << (((byte)(0x17 << bVar6) | (byte)(0x17 >> 0x20 - bVar6)) & 0x1e | 1) ^ uVar10;
		uVar10 = uVar10 << ((char)*(undefined4*)(unaff_EBP + -0xc) + 9U & 0x1e | 1) ^ uVar10;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar10 = uVar10 >> (((byte)(0x19 << bVar6) | (byte)(0x19 >> 0x20 - bVar6)) & 0x1e | 1) ^ uVar10;
		uVar4 = uVar10 >> 4;
		uVar10 = uVar4 | uVar10 << 0x1c;
		uVar10 = (uVar10 >> 0x1a | uVar4 << 6) ^ (uVar10 >> 6 | uVar4 << 0x1a) ^ uVar10;
		bVar6 = (byte)iVar1;
		bVar8 = bVar6 * -0xb & 0x1e | 1;
		bVar9 = (bVar6 ^ 0xf5) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar10 >> bVar9 | uVar10 << 0x20 - bVar9;
		bVar6 = (bVar6 ^ 6) & 0x1e | 1;
		uVar10 = *(uint*)(unaff_EBP + -0xc) ^ (uVar10 >> bVar6 | uVar10 << 0x20 - bVar6) ^ uVar10;
		*(uint*)(unaff_EBP + -0xc) = uVar10 >> 0x10 | uVar10 << 0x10;
		uVar4 = (*(uint*)(unaff_EBP + -0xc) << bVar8 | *(uint*)(unaff_EBP + -0xc) >> 0x20 - bVar8) +
			(0x4d3b169b - iVar1);
		pcVar5 = *(char**)(unaff_EBP + -0x5c);
		//*(char**)(unaff_EBP + -0xc) = pcVar5 + (uVar4 >> 0x12 & 0xff) * 0x10;
		//puVar2 = _DAT_10675ab8;
		if ((uVar4 & 0x100) == 0) {
			//puVar13 = (undefined8*)(pcVar5 + (uVar4 & 0x1ff) * 0x10);
		}
		else {
			//puVar13 = (undefined8*)((uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar4_2 = uVar4 >> 9;
		if ((uVar4 & 0x100) == 0) {
			//puVar12 = (undefined8*)(pcVar5 + (uVar4 & 0x1ff) * 0x10);
		}
		else {
			//puVar12 = (undefined8*)((uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar4 >> 0x12 & 0xff);
		inst->B = (uVar4 & 0x1ff);
		inst->C = (uVar4_2 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void d5bf1(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		int iVar2;
		uint* puVar3;
		char cVar4;
		undefined8* puVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		int iVar11;
		undefined8* puVar12;
		//int unaff_EBP;
		uint uVar13;

		uVar13 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar10 = uVar13 & 0x1e | 1;
		sVar7 = (sbyte)uVar10;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		param_2 = param_2 >> (((byte)(0x16 << sVar7) | (byte)(0x16 >> 0x20 - sVar7)) & 0x1e | 1) ^ param_2
			;
		cVar4 = (char)uVar13;
		bVar8 = (char)(uVar13 << 4) - cVar4 & 0x1eU | 1;
		uVar10 = (param_2 << 0x11 ^ param_2) + 0x62210969;
		iVar11 = ((uVar10 >> bVar8 | uVar10 << 0x20 - bVar8) + (0x2aa3eec4 - uVar13)) * 0x2db65133;
		uVar10 = iVar11 - (iVar11 << (cVar4 - 0xfU & 0x1e | 1));
		bVar8 = -cVar4 - 0xfU & 0x1e | 1;
		bVar9 = -cVar4 - 2U & 0x1e | 1;
		uVar10 = (uVar10 >> bVar8 | uVar10 << 0x20 - bVar8) ^ (uVar10 >> bVar9 | uVar10 << 0x20 - bVar9) ^
			uVar10;
		bVar8 = 6U - cVar4 & 0x1e | 1;
		uVar10 = (uVar10 << 0x11 ^ uVar10) + (uVar13 ^ 0x18383407);
		uVar10 = uVar10 >> bVar8 | uVar10 << 0x20 - bVar8;
		uVar10 = ~(uVar10 >> (cVar4 - 3U & 0x1e | 1) ^ uVar10);
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		iVar2 = (uVar10 >> 7 ^ uVar10) * -0x7f;
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		uVar13 = (iVar2 - (iVar2 << (((byte)(0xb >> bVar8) | (byte)(0xb << 0x20 - bVar8)) & 0x1e | 1))) *
			0xd4c7195;
		uVar10 = uVar13 >> 0xb;
		//*(uint*)(unaff_EBP + -0xc) = (uVar13 & 0xff) * 0x10 + iVar11;
		if ((uVar10 & 0x100) == 0) {
			//puVar5 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + iVar11);
		}
		else {
			//puVar5 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar13_2 = uVar13 >> 0x14;
		//*(undefined8**)(unaff_EBP + -4) = puVar5;
		//puVar3 = _DAT_10675ab8;
		if ((uVar13 & 0x100) == 0) {
			//puVar12 = (undefined8*)((uVar13 & 0x1ff) * 0x10 + iVar11);
		}
		else {
			//puVar12 = (undefined8*)((uVar13 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar13 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar13_2 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void d750e(instr* inst, uint param_1, uint param_2) {

		undefined8 uVar1;
		byte bVar2;
		uint* puVar3;
		char cVar4;
		undefined8* puVar5;
		char* pcVar6;
		byte bVar7;
		uint uVar8;
		uint uVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		//int unaff_EDI;

		uVar8 = (param_2 + 0x9f6fe848U) * 0x100 ^ param_2 + 0x9f6fe848U;
		uVar8 = uVar8 >> 0x19 ^ uVar8;
		bVar2 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar7 = bVar2 + 1 & 0x1e | 1;
		uVar8 = uVar8 << bVar7 | uVar8 >> 0x20 - bVar7;
		uVar8 = uVar8 << ((bVar2 ^ 6) & 0x1e | 1) ^ uVar8;
		uVar9 = (uVar8 >> 0x17 | uVar8 << 9) ^ 0x2045c275;
		uVar8 = uVar9 >> 0x16;
		//*(uint*)(unaff_EBP + -0xc) = (uVar9 >> 9 & 0xff) * 0x10 + unaff_EDI;
		if ((uVar8 & 0x100) == 0) {
			//puVar5 = (undefined8*)((uVar8 & 0x1ff) * 0x10 + unaff_EDI);
		}
		else {
			//puVar5 = (undefined8*)((uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar5;
		//puVar3 = _DAT_10675ab8;
		if ((uVar9 & 0x100) == 0) {
			//puVar10 = (undefined8*)((uVar9 & 0x1ff) * 0x10 + unaff_EDI);
		}
		else {
			//puVar10 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar9 >> 9 & 0xff);
		inst->B = (uVar8 & 0x1ff);
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void dc602(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		code* pcVar2;
		uint* puVar3;
		char cVar4;
		undefined8* puVar5;
		char* pcVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		uint uVar11;
		//int unaff_EDI;
		undefined8 uVar12;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar8 = (byte)uVar9;
		bVar7 = bVar8 & 0x1e | 1;
		uVar11 = *(int*)(unaff_EBP + -0x44) - (0x6694a1fb << bVar7 | 0x6694a1fbU >> 0x20 - bVar7);
		bVar8 = bVar8 + 10 & 0x1e | 1;
		uVar11 = uVar11 << bVar8 ^ uVar11;
		uVar9 = (uVar11 << 7 ^ uVar11 ^ 0x7fb23dd1) + (uVar9 ^ 0x68c959cd);
		uVar9 = uVar9 << bVar8 ^ uVar9;
		uVar9 = (uVar9 >> 5 | uVar9 << 0x1b) ^ (uVar9 >> 4 | uVar9 << 0x1c) ^ uVar9;
		uVar9 = (uVar9 >> 0x10 | uVar9 << 0x10) ^ (uVar9 << 1 | (uint)((int)uVar9 < 0)) ^ uVar9;
		uVar11 = uVar9 >> 0x11;
		//*(uint*)(unaff_EBP + -0xc) = (uVar9 >> 9 & 0xff) * 0x10 + unaff_EDI;
		if ((uVar11 & 0x100) == 0) {
			//puVar5 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + unaff_EDI);
		}
		else {
			//puVar5 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar5;
		//puVar3 = _DAT_10675ab8;
		if ((uVar9 & 0x100) == 0) {
			//puVar10 = (undefined8*)((uVar9 & 0x1ff) * 0x10 + unaff_EDI);
		}
		else {
			//puVar10 = (undefined8*)((uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar9 >> 9 & 0xff);
		inst->B = (uVar11 & 0x1ff);
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void df9f0(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint uVar7;
		undefined8* puVar8;
		//int unaff_EBP;
		int iVar9;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar9;
		bVar5 = (byte)iVar9;
		bVar4 = bVar5 & 0x1e | 1;
		uVar6 = (param_2 << ((bVar5 ^ 0xf5) & 0x1e | 1)) + *(int*)(unaff_EBP + -0x44);
		uVar6 = (uVar6 >> 0x1c | uVar6 * 0x10) ^ (uVar6 >> 4 | uVar6 * 0x10000000) ^ uVar6 ^ 0x69c8ef95;
		uVar6 = uVar6 << 0x1b ^ uVar6;
		*(uint*)(unaff_EBP + -4) = uVar6;
		bVar5 = ((byte)(0x15 >> bVar4) | (byte)(0x15 << 0x20 - bVar4)) & 0x1e | 1;
		bVar4 = ((byte)(1 >> bVar4) | (byte)(1 << 0x20 - bVar4)) & 0x1e | 1;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -4) >> bVar4 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -4);
		uVar6 = (uVar6 >> 0x19 | uVar6 << 7) ^ (uVar6 >> 0xf | uVar6 << 0x11) ^ uVar6;
		cVar2 = (char)*(undefined4*)(unaff_EBP + -0xc);
		bVar5 = -cVar2 - 0xcU & 0x1e | 1;
		bVar4 = 6U - cVar2 & 0x1e | 1;
		uVar6 = (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^ (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
			uVar6;
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar6 = uVar6 >> (cVar2 + 6U & 0x1e | 1) ^ uVar6;
		uVar7 = uVar6 >> 8;
		//*(uint*)(unaff_EBP + -0xc) = (uVar6 & 0xff) * 0x10 + iVar9;
		if ((uVar7 & 0x100) == 0) {
			//puVar8 = (undefined8*)((uVar7 & 0x1ff) * 0x10 + iVar9);
		}
		else {
			//puVar8 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar6_2 = uVar6 >> 0x11;
		if ((uVar6 & 0x100) == 0) {
			//pcVar3 = (char*)((uVar6 & 0x1ff) * 0x10 + iVar9);
		}
		else {
			//pcVar3 = (char*)((uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar6 & 0xff);
		inst->B = (uVar7 & 0x1ff);
		inst->C = (uVar6_2 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void dfe5d(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint* puVar2;
		char cVar3;
		undefined8* puVar4;
		char* pcVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		int iVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		int iVar11;
		uint uVar12;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar3 = (char)iVar11;
		*(int*)(unaff_EBP + -0xc) = iVar11;
		bVar6 = 1U - cVar3 & 0x1e | 1;
		uVar8 = (param_2 ^ 0x6fb2b449) >> bVar6 | (param_2 ^ 0x6fb2b449) << 0x20 - bVar6;
		uVar8 = (uVar8 >> 7 | uVar8 << 0x19) ^ (uVar8 << 2 | uVar8 >> 0x1e) ^ uVar8;
		iVar9 = (uVar8 >> 4 ^ uVar8) * 0x8000001;
		uVar8 = (iVar9 << (-cVar3 - 3U & 0x1e | 1)) + iVar9;
		uVar8 = uVar8 * 0x40000 | uVar8 >> 0xe;
		uVar8 = uVar8 >> 2 ^ uVar8;
		uVar8 = (uVar8 << 0xf | uVar8 >> 0x11) ^ (uVar8 >> 8 | uVar8 << 0x18) ^ uVar8;
		bVar6 = cVar3 * '\x05' & 0x1eU | 1;
		uVar8 = uVar8 >> 0x14 ^ uVar8;
		uVar8 = (uVar8 >> bVar6 | uVar8 << 0x20 - bVar6) * 0x3b266d63;
		uVar8 = uVar8 << (cVar3 * -0xb & 0x1eU | 1) ^ iVar11 + 0x21a6e72U ^ uVar8;
		bVar6 = -cVar3 - 7U & 0x1e | 1;
		uVar8 = (uVar8 >> 0x11 | uVar8 << 0xf) ^ (uVar8 >> 5 | uVar8 << 0x1b) ^ uVar8;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar12 = (uVar8 >> bVar6 | uVar8 << 0x20 - bVar6) + 0x918029fd;
		bVar6 = ((byte)(0x1b >> bVar7) | (byte)(0x1b << 0x20 - bVar7)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar12 >> bVar6 | uVar12 << 0x20 - bVar6;
		bVar6 = ((byte)(1 >> bVar7) | (byte)(1 << 0x20 - bVar7)) & 0x1e | 1;
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar12 = *(uint*)(unaff_EBP + -4) ^ (uVar12 >> bVar6 | uVar12 << 0x20 - bVar6) ^
			*(int*)(unaff_EBP + -0xc) + 0x59ae1f10U ^ uVar12;
		uVar8 = uVar12 >> 0x15;
		//*(uint*)(unaff_EBP + -0xc) = (uVar12 >> 9 & 0xff) * 0x10 + iVar9;
		if ((uVar8 & 0x100) == 0) {
			//puVar4 = (undefined8*)((uVar8 & 0x1ff) * 0x10 + iVar9);
		}
		else {
			//puVar4 = (undefined8*)((uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		//*(undefined8**)(unaff_EBP + -4) = puVar4;
		//puVar2 = _DAT_10675ab8;
		if ((uVar12 & 0x100) == 0) {
			//puVar10 = (undefined8*)((uVar12 & 0x1ff) * 0x10 + iVar9);
		}
		else {
			//puVar10 = (undefined8*)((uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar12 >> 9 & 0xff);
		inst->B = (uVar8 & 0x1ff);
		inst->C = (uVar12 & 0x1ff);
	}

	// OP_UNM 18 : A B 
	void d1eb3(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint uVar2;
		undefined4 uVar3;
		uint* puVar4;
		char cVar5;
		char* pcVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		undefined8* puVar11;
		//int unaff_EBP;
		int iVar12;
		uint* puVar13;
		uint in_XMM2_Da;
		uint in_XMM2_Db;

		iVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar12;
		uVar10 = ~(~((param_2 >> 0x19 | param_2 << 7) ^ (param_2 >> 0x14 | param_2 << 0xc) ^ param_2) *
			0x211ab743) + 0x7df1ca16;
		uVar10 = (uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 * 2 | (uint)((int)uVar10 < 0)) ^ uVar10;
		bVar9 = (byte)iVar12;
		bVar7 = bVar9 * '\n' & 0x1e | 1;
		uVar10 = (uVar10 >> 0x15 | uVar10 << 0xb) ^ (uVar10 << 9 | uVar10 >> 0x17) ^ uVar10;
		uVar10 = uVar10 << bVar7 | uVar10 >> 0x20 - bVar7;
		bVar7 = bVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) =
			~((uVar10 >> 0x1e | uVar10 << 2) ^ (uVar10 >> 0x10 | uVar10 << 0x10) ^ uVar10);
		*(uint*)(unaff_EBP + -0x1c) = iVar12 + 5U & 0x1e | 1;
		bVar8 = ((byte)(9 >> bVar7) | (byte)(9 << 0x20 - bVar7)) & 0x1e | 1;
		bVar9 = bVar9 * -4 - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -4) >> bVar8 | *(uint*)(unaff_EBP + -4) << 0x20 - bVar8;
		bVar7 = ((byte)(4 >> bVar7) | (byte)(4 << 0x20 - bVar7)) & 0x1e | 1;
		uVar10 = *(uint*)(unaff_EBP + -0xc) ^
			(*(uint*)(unaff_EBP + -4) << bVar7 | *(uint*)(unaff_EBP + -4) >> 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -4);
		uVar10 = uVar10 >> bVar9 | uVar10 << 0x20 - bVar9;
		bVar9 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar10 = (uVar10 << bVar9 | uVar10 >> 0x20 - bVar9) << 6;
		//puVar13 = (uint*)((uVar10 >> 0x18) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar11 = (undefined8*)((uVar10 >> 0xf & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 18;
		inst->A = (uVar10 >> 0x18);
		inst->B = (uVar10 >> 0xf & 0x1ff);
	}

	// OP_UNM 18 : A B 
	void d40b9(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint uVar2;
		undefined4 uVar3;
		uint* puVar4;
		char cVar5;
		uint uVar6;
		char* pcVar7;
		byte bVar8;
		byte bVar9;
		byte bVar10;
		int iVar11;
		undefined8* puVar12;
		//int unaff_EBP;
		uint* puVar13;
		uint in_XMM2_Da;
		uint in_XMM2_Db;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar11;
		bVar10 = (byte)iVar11;
		bVar8 = bVar10 & 0x1e | 1;
		bVar9 = bVar10 - 0x10 & 0x1e | 1;
		bVar10 = (bVar10 ^ 0xf9) & 0x1e | 1;
		uVar6 = (*(uint*)(unaff_EBP + -0x44) >> bVar9 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar9) +
			0x6b77fa55;
		*(uint*)(unaff_EBP + -0x44) = (uVar6 * 0x4000 | uVar6 >> 0x12) + 0xfca69eba;
		*(uint*)(unaff_EBP + -4) =
			*(uint*)(unaff_EBP + -0x44) >> (((byte)(1 << bVar8) | (byte)(1 >> 0x20 - bVar8)) & 0x1e | 1)
			^ *(uint*)(unaff_EBP + -0x44);
		*(int*)(unaff_EBP + -4) =
			*(int*)(unaff_EBP + -4) - (0x47ef2074 << bVar8 | 0x47ef2074U >> 0x20 - bVar8);
		//puVar4 = _DAT_10675ab8;
		uVar6 = *(int*)(unaff_EBP + -4) -
			(*(int*)(unaff_EBP + -4) << (((byte)(9 << bVar8) | (byte)(9 >> 0x20 - bVar8)) & 0x1e | 1)
				);
		uVar6 = (uVar6 >> bVar10 | uVar6 << 0x20 - bVar10) + *(int*)(unaff_EBP + -0xc) * -0x73d540f7;
		//puVar13 = (uint*)((uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar12 = (undefined8*)((uVar6 >> 0x11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 18;
		inst->A = (uVar6 & 0xff);
		inst->B = (uVar6 >> 0x11 & 0x1ff);
	}

	// OP_UNM 18 : A B 
	void d59d1(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		char* pcVar3;
		byte bVar4;
		sbyte sVar5;
		byte bVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;

		uVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar2;
		bVar4 = -(char)uVar2 - 10U & 0x1e | 1;
		uVar7 = param_2 << bVar4 | param_2 >> 0x20 - bVar4;
		uVar2 = uVar2 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x44) = uVar7;
		*(uint*)(unaff_EBP + -4) = uVar2;
		sVar5 = (sbyte)uVar2;
		uVar2 = uVar7 << (((byte)(0xf >> sVar5) | (byte)(0xf << 0x20 - sVar5)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar6 = ((byte)(0x1c << sVar5) | (byte)(0x1c >> 0x20 - sVar5)) & 0x1e | 1;
		uVar2 = ~((((uVar2 << 0x1b | uVar2 >> 5) ^ (uVar2 << 7 | uVar2 >> 0x19) ^ uVar2) -
			*(int*)(unaff_EBP + -0xc)) + 0x85a54ce8);
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar4 = ((byte)(8 << bVar4) | (byte)(8 >> 0x20 - bVar4)) & 0x1e | 1;
		iVar8 = ((uVar2 << bVar6 | uVar2 >> 0x20 - bVar6) ^ (uVar2 << bVar4 | uVar2 >> 0x20 - bVar4) ^
			uVar2) + 0x6ff05085;
		uVar2 = (iVar8 - (iVar8 << (-(char)*(undefined4*)(unaff_EBP + -0xc) - 0xeU & 0x1e | 1))) *
			0x800001;
		uVar2 = (uVar2 >> 0x16 ^ uVar2) + 0x21d58ad9;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = (byte) * (uint*)(unaff_EBP + -0xc);
		uVar7 = ~((uVar2 * 8 ^ uVar2) - (0x25b1dae6U >> bVar4 | 0x25b1dae6 << 0x20 - bVar4)) + 0x9faadc07;
		uVar7 = uVar7 << ((bVar6 ^ 2) & 0x1e | 1) ^ uVar7;
		bVar6 = (bVar6 ^ 0xe) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = (*(uint*)(unaff_EBP + -0xc) ^ 10) & 0x1e | 1;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar7 = (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^ (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^
			uVar7;
		uVar2 = uVar7 >> 6;
		uint lol = (uVar2 << 0x16 ^ (uVar7 << 0x1a | uVar2));
		//if (*(int*)(((uVar2 << 0x16 ^ (uVar7 << 0x1a | uVar2)) >> 0x14 & 0x1ff) * 0x10 +
		//	*(int*)(unaff_EBP + -0x5c) + 0xc) == 4) {

		inst->OP = 18;
		inst->A = lol >> 0x9 & 0xff;
		inst->B = lol >> 0x14 & 0x1ff;
	}

	// OP_UNM 18 : A B 
	void dc48b(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4 uVar2;
		char cVar3;
		char* pcVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		int iVar8;
		//int unaff_EBP;
		uint uVar9;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar9 = uVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar9;
		sVar5 = (sbyte)uVar9;
		bVar6 = ((byte)(0x15 << sVar5) | (byte)(0x15 >> 0x20 - sVar5)) & 0x1e | 1;
		bVar7 = ((byte)(0xd << sVar5) | (byte)(0xd >> 0x20 - sVar5)) & 0x1e | 1;
		uVar9 = (param_2 >> bVar6 | param_2 << 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar7 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar9 = (uVar9 << (((byte)(0x17 << sVar5) | (byte)(0x17 >> 0x20 - sVar5)) & 0x1e | 1)) + uVar9;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar9 = uVar9 >> (((byte)(0x14 >> bVar6) | (byte)(0x14 << 0x20 - bVar6)) & 0x1e | 1) ^ uVar9;
		cVar3 = (char)*(int*)(unaff_EBP + -0xc);
		bVar6 = cVar3 + 0xcU & 0x1e | 1;
		uVar9 = (((uVar9 >> 0x19 | uVar9 << 7) ^ (uVar9 >> 0x16 | uVar9 << 10) ^ uVar9) -
			*(int*)(unaff_EBP + -0xc)) + 0xeb1980c3;
		bVar7 = cVar3 - 7U & 0x1e | 1;
		uVar9 = ~((uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			uVar9);
		uVar9 = (uVar9 >> 0x1c | uVar9 << 4) ^ (uVar9 >> 0xf | uVar9 << 0x11) ^ uVar9;
		uVar9 = (uVar9 << 0x19 | uVar9 >> 7) ^ (uVar9 >> 5 | uVar9 << 0x1b) ^ uVar9;
		bVar6 = cVar3 * -0xd & 0x1eU | 1;
		bVar7 = cVar3 * '\x05' & 0x1eU | 1;
		uVar9 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			uVar9;
		uVar9 = (uVar9 >> 0x15 | uVar9 << 0xb) ^ (uVar9 << 0xc | uVar9 >> 0x14) ^ uVar9;
		uVar9 = uVar9 << 5 ^ uVar9;
		uVar9 = uVar9 << (cVar3 - 7U & 0x1e | 1) ^ uVar9;
		bVar6 = 0xeU - cVar3 & 0x1e | 1;
		uVar9 = uVar9 >> 0x15 ^ uVar9;
		bVar7 = -cVar3 - 0xeU & 0x1e | 1;
		uVar9 = (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^
			uVar9;
		bVar6 = -cVar3 - 0xcU & 0x1e | 1;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		bVar7 = -cVar3 - 4U & 0x1e | 1;
		uVar9 = ~((uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^
			uVar9) + 0xfefb89f0;
		iVar8 = (uVar9 >> 0x15 & 0x1ff) * 0x10 + iVar1;

		inst->OP = 18;
		inst->A = uVar9 & 0xff;
		inst->B = (uVar9 >> 0x15 & 0x1ff);
	}

	// OP_NOT 19 : A B 
	void d072d(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		char* pcVar2;
		char cVar3;
		int iVar4;
		byte bVar5;
		uint uVar6;
		//int unaff_EBP;
		uint uVar7;

		iVar4 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar4;
		bVar5 = (byte)iVar4 & 0x1e | 1;
		uVar6 = param_2 >> (((byte)(0x19 >> bVar5) | (byte)(0x19 << 0x20 - bVar5)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = uVar6 << 0x14;
		iVar4 = *(int*)(unaff_EBP + -0x5c);
		uVar7 = uVar7 >> 0x1e ^ (uVar7 | uVar6 >> 0xc);
		bVar5 = ((byte)(1 >> bVar5) | (byte)(1 << 0x20 - bVar5)) & 0x1e | 1;
		uVar7 = (uVar7 - (uVar7 << (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xf7) & 0x1e | 1))) *
			0x64fb343f;
		uVar7 = (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) * -0xf;
		uVar6 = uVar7 >> 0x13 & 0x1ff;
		uVar7 = uVar7 >> 0xb & 0xff;

		inst->OP = 19;
		inst->A = uVar7;
		inst->B = uVar6;
	}

	// OP_NOT 19 : A B 
	void d41ac(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		int iVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		//int unaff_EBP;
		uint uVar7;

		uVar7 = (param_2 << 0xb | param_2 >> 0x15) * 0x400001;
		iVar2 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar2;
		bVar3 = (byte)iVar2 & 0x1e | 1;
		bVar4 = ((byte)(0x17 >> bVar3) | (byte)(0x17 << 0x20 - bVar3)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar7 >> bVar4 | uVar7 << 0x20 - bVar4;
		bVar3 = ((byte)(0xc >> bVar3) | (byte)(0xc << 0x20 - bVar3)) & 0x1e | 1;
		uVar7 = *(uint*)(unaff_EBP + -4) ^ (uVar7 >> bVar3 | uVar7 << 0x20 - bVar3) ^ uVar7;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar4 = (bVar3 ^ 0xf1) & 0x1e | 1;
		bVar5 = (bVar3 ^ 0xfd) & 0x1e | 1;
		uVar7 = (uVar7 << bVar4 | uVar7 >> 0x20 - bVar4) ^ (uVar7 << bVar5 | uVar7 >> 0x20 - bVar5) ^
			uVar7;
		uVar6 = uVar7 * 0x6198d707;
		uVar6 = ~((uVar7 * -0x6728f900 | uVar6 >> 0x18) ^ (uVar6 >> 3 | uVar7 * -0x20000000) ^ uVar6);
		bVar4 = 0xb - bVar3 & 0x1e | 1;
		iVar2 = *(int*)(unaff_EBP + -0x5c);
		bVar3 = -bVar3 - 4 & 0x1e | 1;
		uVar6 = ((uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^ (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^
			uVar6) * 0x1a3a2715;
		uVar7 = uVar6 >> 0xf & 0x1ff;
		uVar6 = uVar6 >> 0x18;

		inst->OP = 19;
		inst->A = uVar6;
		inst->B = uVar7;
	}

	// OP_NOT 19 : A B 
	void d87ee(instr* inst, uint param_1, uint param_2) {

		code* pcVar1;
		byte bVar2;
		char* pcVar3;
		char cVar4;
		int iVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//uint unaff_EBP;
		uint uVar10;
		undefined4 uVar11;
		undefined4 uVar12;

		iVar5 = *(int*)(unaff_EBP - 100);
		*(uint*)(unaff_EBP - 0x44) = param_2 << 0x1b | param_2 >> 5;
		uVar10 = (param_1 - iVar5) + -8 >> 2;
		uVar9 = (param_2 >> 5) << 0xf ^ *(uint*)(unaff_EBP - 0x44);
		*(uint*)(unaff_EBP - 0xc) = uVar10;
		uVar9 = uVar9 << (((byte)uVar10 ^ 10) & 0x1e | 1) ^ uVar9;
		uVar10 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP - 4) = uVar10;
		sVar6 = (sbyte)uVar10;
		bVar7 = ((byte)(0x1d >> sVar6) | (byte)(0x1d << 0x20 - sVar6)) & 0x1e | 1;
		uVar9 = uVar9 * -0x25780000 | uVar9 * 0x26b53b51 >> 0xd;
		bVar2 = (byte) * (undefined4*)(unaff_EBP - 4) & 0x1f;
		bVar8 = ((byte)(0x18 >> bVar2) | (byte)(0x18 << 0x20 - bVar2)) & 0x1e | 1;
		bVar2 = (byte) * (undefined4*)(unaff_EBP - 4) & 0x1f;
		uVar9 = (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^ (uVar9 << bVar8 | uVar9 >> 0x20 - bVar8) ^
			*(int*)(unaff_EBP - 0xc) + 0x123c73bfU ^ uVar9;
		pcVar1 = *(code**)(unaff_EBP - 0x5c);
		uVar9 = (uVar9 << (((byte)(0x1c >> bVar2) | (byte)(0x1c << 0x20 - bVar2)) & 0x1e | 1)) + uVar9;
		uVar9 = (uVar9 >> 0x14 | uVar9 * 0x1000) ^ (uVar9 * 0x400 | uVar9 >> 0x16) ^ uVar9;
		uVar10 = uVar9 & 0x1ff;
		uVar9 = uVar9 >> 9 & 0xff;

		inst->OP = 19;
		inst->A = uVar9;
		inst->B = uVar10;
	}

	// OP_NOT 19 : A B 
	void deb86(instr* inst, uint param_1, uint param_2) {

		char* pcVar1;
		byte bVar2;
		char cVar3;
		byte bVar4;
		uint uVar5;
		uint uVar6;
		uint uVar7;
		int iVar8;
		char unaff_BL;
		//int unaff_EBP;
		int iVar9;
		undefined4 uStack000000c0;

		iVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar2 = (byte)iVar9;
		bVar4 = (bVar2 ^ 0xc) & 0x1e | 1;
		uVar6 = param_2 >> bVar4 | param_2 << 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0x44) = uVar6;
		uVar7 = (uVar6 >> (bVar2 - 0xd & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44)) + iVar9 * -0x407e1134;
		uVar6 = uVar7 >> 0x12;
		uVar7 = uVar7 * 0x4000 | uVar6;
		uVar7 = uVar7 << 9 ^ uVar7;
		uVar5 = uVar7 * 0x6297d4d3;
		uVar6 = ((uVar5 >> 10 | uVar7 * 0x34c00000) ^ (uVar5 >> 9 | uVar6 * 0x69800000) ^ uVar5) +
			0x4cb3bfa0 ^ iVar9 + 0x67a039beU;
		bVar4 = bVar2 & 0x1e | 1;
		iVar8 = ~(uVar6 >> 0xf | uVar6 << 0x11) + 0x96edd2d8;
		iVar8 = (iVar8 << (((byte)(0xd >> bVar4) | (byte)(0xd << 0x20 - bVar4)) & 0x1e | 1)) + iVar8;
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar6 = iVar8 - (iVar8 << (bVar2 * '\x03' & 0x1e | 1));
		uVar7 = uVar6 >> 9 & 0x1ff;
		uVar6 = uVar6 >> 0x12 & 0xff;

		inst->OP = 19;
		inst->A = uVar6;
		inst->B = uVar7;
	}

	// OP_LEN 20 : A B 
	uint d737c_A(instr* inst, uint param_1, uint param_2) {
		uint uVar1;
		char cVar2;
		char* pcVar3;
		sbyte sVar4;
		uint uVar5;
		//int unaff_EBP;

		param_2 = param_2 << 0x1d ^ param_2;
		sVar4 = (sbyte)(((param_1 - *(int*)(unaff_EBP + -100)) - 8U & 0x78 | 4) >> 2);
		param_2 = param_2 >> (((byte)(0x1d << sVar4) | (byte)(0x1d >> 0x20 - sVar4)) & 0x1e | 1) ^ param_2
			;
		uVar1 = param_2 >> 8;
		uVar5 = param_2 << 0x18 | uVar1;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar3 = (char*)func_0x00525520((((uVar1 << 0x15 | uVar5 >> 0xb) ^ (uVar1 << 0xd | uVar5 >> 0x13)
		//	^ uVar5) * 0x801 >> 0x17 & 0xff)

		return (((uVar1 << 0x15 | uVar5 >> 0xb) ^ (uVar1 << 0xd | uVar5 >> 0x13)
			^ uVar5) * 0x801 >> 0x17 & 0xff);
	}
	uint d737c_B(instr* inst, uint param_1, uint param_2) {
		char cVar1;
		char* pcVar2;
		sbyte sVar3;
		uint uVar4;
		//int unaff_EBP;
		int unaff_EDI;

		param_2 = param_2 << 0x1d ^ param_2;
		sVar3 = (sbyte)(((param_1 - *(int*)(unaff_EBP + -100)) - 8U & 0x78 | 4) >> 2);
		param_2 = param_2 >> (((byte)(0x1d << sVar3) | (byte)(0x1d >> 0x20 - sVar3)) & 0x1e | 1) ^ param_2
			;
		uVar4 = param_2 << 0x18 | param_2 >> 8;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar2 = (char*)func_0x00525520(((uVar4 >> 0xb ^ uVar4 >> 0x13 ^ uVar4) * 0x801 & 0x1ff)

		return ((uVar4 >> 0xb ^ uVar4 >> 0x13 ^ uVar4) * 0x801 & 0x1ff);
	}
	void d737c(instr* inst, uint param_1, uint param_2) {
		inst->OP = 20;
		inst->A = d737c_A(inst, param_1, param_2);
		inst->B = d737c_B(inst, param_1, param_2);
	}

	// OP_LEN 20 : A B 
	uint d974d_A(instr* inst, uint param_1, uint param_2) {
		undefined4 uVar1;
		int iVar2;
		char cVar3;
		uint uVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		//int unaff_EBP;
		uint uVar8;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar4 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar4;
		sVar6 = (sbyte)uVar4;
		uVar4 = (0x21450151U >> sVar6 | 0x21450151 << 0x20 - sVar6) ^ *(uint*)(unaff_EBP + -0x44);
		bVar7 = ((byte)uVar8 ^ 0xc) & 0x1e | 1;
		uVar4 = ~(((((uVar4 >> 0xf | uVar4 << 0x11) ^ (uVar4 << 8 | uVar4 >> 0x18) ^ uVar4) - uVar8) +
			0x5d3dc91e ^ 0x37a4e174) + uVar8 * 0x260447e5);
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar4 = (uVar4 >> bVar7 | uVar4 << 0x20 - bVar7) + 0xd134904 + uVar8 * 2;
		iVar2 = *(int*)(unaff_EBP + -0xa8);
		uVar4 = (uVar4 * 0x1000 | uVar4 >> 0x14) ^ (uVar4 * 0x800 | uVar4 >> 0x15) ^ uVar4;
		uVar4 = (uVar4 >> 0x1c | uVar4 << 4) ^ (uVar4 << 10 | uVar4 >> 0x16) ^ uVar4;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		//*(undefined4*)(*(int*)(iVar2 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//pcVar5 = (char*)func_0x0052ae3f(((uVar4 - (uVar4 << (((byte)(0x14 << bVar7) |
		//	(byte)(0x14 >> 0x20 - bVar7)) & 0x1e | 1)))
		//	* -0x51d9bf40 >> 0xd & 0xff)

		uint lol = ((uVar4 - (uVar4 << (((byte)(0x14 << bVar7) |
			(byte)(0x14 >> 0x20 - bVar7)) & 0x1e | 1)))
			* -0x51d9bf40 >> 0xd & 0xff);

		return lol;
	}
	uint d974d_B(instr* inst, uint param_1, uint param_2) {
		undefined4 uVar1;
		int iVar2;
		char cVar3;
		uint uVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		//int unaff_EBP;
		int iVar8;
		uint uVar9;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar4 = uVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar4;
		sVar6 = (sbyte)uVar4;
		uVar4 = (0x21450151U >> sVar6 | 0x21450151 << 0x20 - sVar6) ^ *(uint*)(unaff_EBP + -0x44);
		bVar7 = ((byte)uVar9 ^ 0xc) & 0x1e | 1;
		uVar4 = ~(((((uVar4 >> 0xf | uVar4 << 0x11) ^ (uVar4 << 8 | uVar4 >> 0x18) ^ uVar4) - uVar9) +
			0x5d3dc91e ^ 0x37a4e174) + uVar9 * 0x260447e5);
		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		uVar4 = (uVar4 >> bVar7 | uVar4 << 0x20 - bVar7) + 0xd134904 + uVar9 * 2;
		iVar2 = *(int*)(unaff_EBP + -0xa8);
		uVar4 = (uVar4 * 0x1000 | uVar4 >> 0x14) ^ (uVar4 * 0x800 | uVar4 >> 0x15) ^ uVar4;
		uVar4 = (uVar4 >> 0x1c | uVar4 << 4) ^ (uVar4 << 10 | uVar4 >> 0x16) ^ uVar4;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		iVar8 = uVar4 - (uVar4 << (((byte)(0x14 << bVar7) | (byte)(0x14 >> 0x20 - bVar7)) & 0x1e | 1));
		//*(undefined4*)(*(int*)(iVar2 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//pcVar5 = (char*)func_0x0052ae3f(((iVar8 * -0x51d9bf40 | (uint)(iVar8 * 0x3ab89903) >> 0x1a) >> 4
		//	& 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c), uVar1);
		uint lol = ((iVar8 * -0x51d9bf40 | (uint)(iVar8 * 0x3ab89903) >> 0x1a) >> 4
			& 0x1ff);

		return lol;
	}
	void d974d(instr* inst, uint param_1, uint param_2) {
		inst->OP = 20;
		inst->A = d974d_A(inst, param_1, param_2);
		inst->B = d974d_B(inst, param_1, param_2);
	}

	// OP_LEN 20 : A B 
	uint dcc31_A(instr* inst, uint param_1, uint param_2) {
		char cVar1;
		char* pcVar2;
		uint uVar3;
		//int unaff_EBP;

		uVar3 = ((param_2 >> 0x1e | param_2 << 2) ^
			(*(uint*)(unaff_EBP + -0x44) >> 0x1c | *(uint*)(unaff_EBP + -0x44) << 4) ^
			*(uint*)(unaff_EBP + -0x44)) + 0x711d9ed8;
		uVar3 = (uVar3 >> 7 | uVar3 * 0x2000000) + 0x74336f35;
		uVar3 = (uVar3 >> 0x1c | uVar3 * 0x10) ^ (uVar3 >> 10 | uVar3 * 0x400000) ^ uVar3;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar2 = (char*)func_0x00525515(((uVar3 * -0x4145ca00 ^
		//	(uVar3 * 0x7b5f5d1b >> 0x11 | uVar3 * -0x51728000) ^
		//	uVar3 * 0x7b5f5d1b) >> 9 & 0xff)

		return ((uVar3 * -0x4145ca00 ^
			(uVar3 * 0x7b5f5d1b >> 0x11 | uVar3 * -0x51728000) ^
			uVar3 * 0x7b5f5d1b) >> 9 & 0xff);
	}
	uint dcc31_B(instr* inst, uint param_1, uint param_2) {
		char cVar1;
		char* pcVar2;
		uint uVar3;
		//int unaff_EBP;
		int unaff_EDI;

		uVar3 = ((param_2 >> 0x1e | param_2 << 2) ^
			(*(uint*)(unaff_EBP + -0x44) >> 0x1c | *(uint*)(unaff_EBP + -0x44) << 4) ^
			*(uint*)(unaff_EBP + -0x44)) + 0x711d9ed8;
		uVar3 = (uVar3 >> 7 | uVar3 * 0x2000000) + 0x74336f35;
		uVar3 = ((uVar3 >> 0x1c | uVar3 * 0x10) ^ (uVar3 >> 10 | uVar3 * 0x400000) ^ uVar3) * 0x7b5f5d1b;
		//*(undefined4*)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) =
		//	*(undefined4*)(unaff_EBP + -0x50);
		//pcVar2 = (char*)func_0x00525515(((uVar3 >> 0x17 ^ uVar3 >> 0x11 ^ uVar3) & 0x1ff)

		return (uVar3 >> 0x17 ^ uVar3 >> 0x11 ^ uVar3) & 0x1ff;
	}
	void dcc31(instr* inst, uint param_1, uint param_2) {
		inst->OP = 20;
		inst->A = dcc31_A(inst, param_1, param_2);
		inst->B = dcc31_B(inst, param_1, param_2);
	}

	// OP_CONCAT 21 : A B C
	void d5011(instr* inst, uint param_1, uint param_2) {

		undefined8 uVar1;
		undefined4 uVar2;
		int iVar3;
		char* pcVar4;
		char cVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;
		uint uVar11;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		param_2 = (param_2 << 0x1e | param_2 >> 2) ^ (param_2 << 1 | (uint)((int)param_2 < 0)) ^ param_2;
		uVar9 = uVar9 & 0x1e | 1;
		sVar6 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar7 = ((byte)(0x14 << sVar6) | (byte)(0x14 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar8 = ((byte)(0xf << bVar8) | (byte)(0xf >> 0x20 - bVar8)) & 0x1e | 1;
		param_2 = (param_2 << bVar7 | param_2 >> 0x20 - bVar7) ^
			(param_2 >> bVar8 | param_2 << 0x20 - bVar8) ^ param_2;
		uVar9 = param_2 << 0x13;
		cVar5 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar9 = ~(uVar9 >> 0x17 ^ (uVar9 | param_2 >> 0xd));
		uVar9 = uVar9 << (cVar5 - 6U & 0x1e | 1) ^ uVar9;
		uVar9 = (uVar9 << 0x14 | uVar9 >> 0xc) ^ 0x69a7d68f;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar8 = bVar7 & 0x1f;
		bVar7 = bVar7 & 0x1f;
		iVar10 = ~(((uVar9 << 0x1d | uVar9 >> 3) ^ (uVar9 << 0x18 | uVar9 >> 8) ^ uVar9) -
			(0x30524425 << bVar8 | 0x30524425U >> 0x20 - bVar8)) +
			(0x92391ac << bVar7 | 0x92391acU >> 0x20 - bVar7);
		uVar9 = (iVar10 << (cVar5 - 10U & 0x1e | 1)) + iVar10;
		uVar9 = (uVar9 * 0x100000 | uVar9 >> 0xc) ^ (uVar9 * 0x40 | uVar9 >> 0x1a) ^ uVar9;
		uVar9 = (uVar9 << (-cVar5 - 6U & 0x1e | 1)) + uVar9;
		iVar10 = *(int*)(unaff_EBP + -0xa8);
		uVar9 = (uVar9 >> 0xe | uVar9 * 0x40000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ uVar9;
		uVar2 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		//iVar3 = *(int*)(iVar10 + 0x1c);
		uVar9 = (uVar9 << (((byte)(7 >> bVar8) | (byte)(7 << 0x20 - bVar8)) & 0x1e | 1)) + uVar9;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar11 = uVar9 >> 4 & 0x1ff;
		//*(undefined4*)(iVar3 + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//func_0x005337b6(uVar9 >> 0x15 & 0x1ff, uVar2);
		//FUN_004552a6();
		//iVar10 = *(int*)(iVar10 + 0x14);
		//uVar1 = *(undefined8*)(iVar10 + uVar11 * 0x10);
		uint uVar9_2 = *(uint*)(unaff_EBP + -0xc) >> 0xd & 0xff;

		inst->OP = 21;
		inst->A = uVar9_2;
		inst->C = uVar9 >> 0x15 & 0x1ff;
		inst->B = uVar11;
	}

	// OP_CONCAT 21 : A B C
	void df5c5(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char* pcVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		int iVar8;
		//int unaff_EBP;
		uint uVar9;

		uVar1 = *(undefined4*)(unaff_EBP + -0xb8);
		bVar6 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar4 = bVar6 + 1 & 0x1e | 1;
		uVar7 = param_2 << bVar4 | param_2 >> 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0x44) = uVar7;
		uVar7 = uVar7 << ((bVar6 ^ 4) & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44);
		uVar7 = uVar7 - (uVar7 << ((bVar6 ^ 0xfd) & 0x1e | 1));
		uVar7 = uVar7 >> 3 ^ uVar7;
		iVar8 = (uVar7 << (bVar6 - 0xe & 0x1e | 1)) + uVar7;
		uVar7 = (iVar8 << (-bVar6 - 0xd & 0x1e | 1)) + iVar8;
		bVar4 = bVar6 & 0x1e | 1;
		bVar4 = ((byte)(1 >> bVar4) | (byte)(1 << 0x20 - bVar4)) & 0x1e | 1;
		bVar5 = bVar6 + 9 & 0x1e | 1;
		iVar8 = *(int*)(unaff_EBP + -0xa8);
		*(uint*)(unaff_EBP + -0xc) = uVar7 >> bVar5 | uVar7 << 0x20 - bVar5;
		bVar6 = bVar6 + 2 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) =
			*(uint*)(unaff_EBP + -0xc) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6);
		uVar7 = *(uint*)(unaff_EBP + -0xc) ^ uVar7;
		uVar7 = uVar7 << bVar4 | uVar7 >> 0x20 - bVar4;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar9 = uVar7 >> 8 & 0x1ff;
		//*(undefined4*)(*(int*)(iVar8 + 0x1c) + 0xc) = *(undefined4*)(unaff_EBP + -0x50);
		//func_0x0051fcd1(uVar7 >> 0x11 & 0x1ff, uVar1);
		//func_0x004417c1();
		//iVar8 = *(int*)(iVar8 + 0x14);
		uint uVar7_2 = *(uint*)(unaff_EBP + -0xc) & 0xff;

		inst->OP = 21;
		inst->A = uVar7_2;
		inst->B = uVar9;
		inst->C = uVar7 >> 0x11 & 0x1ff;
	}

	// OP_JMP 22 : sBx  
	void d8f95(instr* inst, uint param_1, uint param_2) {

		byte bVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		int iVar5;
		uint* puVar6;
		uint* puVar7;
		uint uVar8;
		//int unaff_EBP;

		iVar5 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x50) = iVar5;
		uVar8 = param_2 - (param_2 << ((char)iVar5 + 10U & 0x1e | 1));
		bVar1 = (byte) * (undefined4*)(unaff_EBP + -0x50);
		uVar8 = ~((uVar8 >> 0xc | uVar8 * 0x100000) ^ (uVar8 * 0x200 | uVar8 >> 0x17) ^ uVar8);
		uVar8 = (uVar8 << (bVar1 + 7 & 0x1e | 1)) + uVar8;
		uVar8 = (uVar8 >> 0x1d | uVar8 * 8) ^ (uVar8 * 0x2000 | uVar8 >> 0x13) ^ uVar8;
		uVar8 = (uVar8 << 0x1b | uVar8 >> 5) ^ (uVar8 >> 0xc | uVar8 << 0x14) ^ uVar8;
		uVar8 = (uVar8 << 10 ^ uVar8) + 0xac16cbe;
		bVar4 = bVar1 & 0x1e | 1;
		uVar8 = uVar8 * 0x100000 ^ uVar8;
		uVar8 = uVar8 - (uVar8 << (((byte)(0x15 << bVar4) | (byte)(0x15 >> 0x20 - bVar4)) & 0x1e | 1));
		//puVar6 = (uint*)(*(int*)(unaff_EBP + -0x24) +
		//	((uVar8 << (bVar1 + 0xd & 0x1e | 1) ^ uVar8) & 0x3ffffff) * 8 + -0xffffff4);

		inst->OP = 22;
		inst->sBx = sBxConversion(((uVar8 << (bVar1 + 0xd & 0x1e | 1) ^ uVar8) & 0x3ffffff) * 8 + -0xffffff4);
	}

	// OP_JMP 22 : sBx  
	void d9573(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		char* pcVar3;
		uint* puVar4;
		uint* puVar5;
		//int unaff_EBP;
		int unaff_ESI;

		*(int*)(unaff_EBP + -0x50) = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		//puVar4 = (uint*)((((~(~param_2 + 0x1a4ad7f2) <<
		//	(-(char)*(undefined4*)(unaff_EBP + -0x50) - 3U & 0x1e | 1)) +
		//	~(~param_2 + 0x1a4ad7f2)) * 0xec38689 >> 4 & 0x3ffffff) * 8 + -0xffffff4 +
		//	unaff_ESI);

		int lol = (((~(~param_2 + 0x1a4ad7f2) <<
			(-(char)*(undefined4*)(unaff_EBP + -0x50) - 3U & 0x1e | 1)) +
			~(~param_2 + 0x1a4ad7f2)) * 0xec38689 >> 4 & 0x3ffffff) * 8 + -0xffffff4;

		inst->OP = 22;
		inst->sBx = sBxConversion(lol);
	}

	// OP_JMP 22 : sBx  
	void dbc60(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		int iVar6;
		uint* puVar7;
		uint* puVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;

		iVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0x50) = iVar6;
		bVar3 = (char)iVar6 + 0xdU & 0x1e | 1;
		bVar4 = (char)*(undefined4*)(unaff_EBP + -0x50) + 10U & 0x1e | 1;
		uVar9 = (param_2 >> bVar3 | param_2 << 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar4 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x44);
		cVar1 = (char)*(undefined4*)(unaff_EBP + -0x50);
		bVar3 = 8U - cVar1 & 0x1e | 1;
		uVar9 = (uVar9 * 8 ^ uVar9) * 0x800001 + 0x35671150;
		bVar4 = cVar1 * '\r' & 0x1eU | 1;
		bVar5 = cVar1 * -9 & 0x1eU | 1;
		uVar9 = (uVar9 << bVar4 | uVar9 >> 0x20 - bVar4) ^ (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^
			uVar9;
		uVar10 = uVar9 >> bVar3 | uVar9 << 0x20 - bVar3;
		uVar9 = uVar10 * 0x4aece4d9;
		iVar6 = ((uVar9 >> 0xe | uVar10 * -0x6c9c0000) ^ (uVar9 >> 4 | uVar10 * -0x70000000) ^ uVar9) *
			-0x3fffff;
		//puVar7 = (uint*)(*(int*)(unaff_EBP + -0x24) + -0xffffff4 +
		//	(((iVar6 - (iVar6 << (((byte) * (undefined4*)(unaff_EBP + -0x50) ^ 6) & 0x1e | 1))
		//		) * -0x1ff - *(int*)(unaff_EBP + -0x50)) + 0x1d6c1c5U & 0x3ffffff) * 8);

		int yes = -0xffffff4 +
			(((iVar6 - (iVar6 << (((byte) * (undefined4*)(unaff_EBP + -0x50) ^ 6) & 0x1e | 1))
				) * -0x1ff - *(int*)(unaff_EBP + -0x50)) + 0x1d6c1c5U & 0x3ffffff) * 8;

		inst->OP = 22;
		inst->sBx = sBxConversion(yes);
	}

	// OP_EQ 23 : A B C
	void d346b(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		uint uVar2;
		uint uVar3;
		int iVar4;
		char* pcVar5;
		int iVar6;
		//int unaff_EBP;

		param_2 = param_2 ^ 0x47f58b37;
		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		uVar2 = param_2 << 0x1d | (param_2 << 5 ^ param_2) >> 3;
		uVar2 = uVar2 >> 2 ^ uVar2;
		uVar2 = (uVar2 << ((char)(param_1 + -8 >> 2) - 0xcU & 0x1e | 1)) + uVar2;
		uVar2 = ~((uVar2 >> 0x16 | uVar2 * 0x400) ^ (uVar2 >> 1 | (uint)((uVar2 & 1) != 0) << 0x1f) ^
			uVar2 ^ 0x231a58ab) * 0x5fd719db;
		*(uint*)(unaff_EBP + -0xc) = uVar2;
		uVar3 = uVar2 >> 0x12;
		if ((uVar3 & 0x100) == 0) {
			//iVar4 = (uVar3 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar4 = (uVar3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		if ((uVar2 & 0x100) == 0) {
			//iVar6 = (uVar2 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar6 = (uVar2 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar4 + 0xc) == *(int*)(iVar6 + 0xc)) {
			//iVar4 = func_0x00459003(iVar4, iVar6);
			//if (iVar4 != 0) {
			//	uVar2 = 1;
				//goto LAB_0046fe97;
			//}
		//}
		//uVar2 = 0;
	//LAB_0046fe97:
		//if (uVar2 == (*(uint*)(unaff_EBP + -0xc) >> 10 & 0xff)) {

		inst->OP = 23;
		inst->A = uVar2 >> 10 & 0xff;
		inst->B = (uVar3 & 0x1ff);
		inst->C = (uVar2 & 0x1ff);
	}

	// OP_EQ 23 : A B C
	void d4033(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		int iVar7;
		char* pcVar8;
		//int unaff_EBP;
		int iVar9;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar9 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar9;
		uVar6 = param_2 * 0x416618e1 + iVar9 * -0x57ebe78;
		bVar5 = (byte)iVar9;
		uVar6 = uVar6 * 0x10000000 ^ uVar6 ^ 0x1f1f36a1;
		bVar3 = (bVar5 ^ 0xf3) & 0x1e | 1;
		bVar4 = bVar5 & 0x1e | 1;
		bVar5 = (bVar5 ^ 0xf9) & 0x1e | 1;
		uVar6 = (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^ (uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^
			uVar6;
		uVar6 = uVar6 >> (((byte)(0x1c << bVar4) | (byte)(0x1c >> 0x20 - bVar4)) & 0x1e | 1) ^ uVar6;
		bVar5 = 0xeU - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		bVar3 = -(char)*(undefined4*)(unaff_EBP + -4) - 4U & 0x1e | 1;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^ (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^
			uVar6;
		uVar6 = (((uVar6 << 0x1e | uVar6 >> 2) ^ (uVar6 << 0x11 | uVar6 >> 0xf) ^ uVar6) +
			(0x599c5858 << bVar4 | 0x599c5858U >> 0x20 - bVar4)) * 0x7de6c049;
		uVar6 = uVar6 << ((char)*(undefined4*)(unaff_EBP + -4) + 3U & 0x1e | 1) ^ uVar6;
		*(uint*)(unaff_EBP + -4) = uVar6;
		uVar6 = uVar6 >> 0x13;
		if ((uVar6 & 0x100) == 0) {
			//iVar9 = (uVar6 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar9 = (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uint uVar6_2 = *(uint*)(unaff_EBP + -4) >> 10;
		if ((uVar6 & 0x100) == 0) {
			//iVar7 = (uVar6 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar7 = (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar9 + 0xc) == *(int*)(iVar7 + 0xc)) {
			//iVar9 = func_0x00457f97(iVar9, iVar7);
			//if (iVar9 != 0) {
				//uVar6 = 1;
				//goto LAB_0046ff13;
			//}
		//}
		//uVar6 = 0;
	//LAB_0046ff13:
		//if (uVar6 == (*(uint*)(unaff_EBP + -4) >> 2 & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -4) >> 2 & 0xff;
		inst->B = (uVar6 & 0x1ff);
		inst->C = (uVar6_2 & 0x1ff);
	}

	// OP_EQ 23 : A B C
	void d55b2(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		byte bVar2;
		uint uVar3;
		int iVar4;
		char* pcVar5;
		int iVar6;
		//int unaff_EBP;
		uint uVar7;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		iVar6 = param_1 + -8 >> 2;
		bVar2 = (byte)iVar6 & 0x1e | 1;
		uVar7 = (((0x528c28ffU >> bVar2 | 0x528c28ff << 0x20 - bVar2) ^
			*(int*)(unaff_EBP + -0x44) * 0x1bdb12e7) - iVar6) + 0x94b8fb6f;
		uVar3 = uVar7 >> 0x12;
		uVar7 = uVar3 | uVar7 * 0x4000;
		uVar7 = (uVar3 << 0x16 | uVar7 >> 10) ^ (uVar7 >> 5 | uVar3 << 0x1b) ^ uVar7;
		uVar7 = (uVar7 << 0x13 | uVar7 >> 0xd) ^ (uVar7 << 0xf | uVar7 >> 0x11) ^ uVar7;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar7 = uVar7 >> 8;
		if ((uVar7 & 0x100) == 0) {
			//iVar6 = (uVar7 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar6 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uVar3 = *(uint*)(unaff_EBP + -0xc) >> 0x11;
		if ((uVar3 & 0x100) == 0) {
			//iVar4 = (uVar3 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar4 = (uVar3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar6 + 0xc) == *(int*)(iVar4 + 0xc)) {
		//	iVar6 = func_0x005326d7(iVar4);
		//	if (iVar6 != 0) {
		//		uVar3 = 1;
		//		goto LAB_0046fe9b;
		//	}
		//}
	//LAB_0046fe9b:
		//if (uVar3 == (*(uint*)(unaff_EBP + -0xc) & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -0xc) & 0xff;
		inst->B = (uVar7 & 0x1ff);
		inst->C = (uVar3 & 0x1ff);
	}

	// OP_EQ 23 : A B C
	void d733e(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		int iVar3;
		byte bVar4;
		byte bVar5;
		sbyte sVar6;
		byte bVar7;
		int iVar8;
		char* pcVar9;
		uint uVar10;
		//int unaff_EBP;
		uint uVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar11 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar11;
		bVar5 = (byte)uVar11;
		uVar10 = ((param_2 << ((bVar5 ^ 0xe) & 0x1e | 1)) + param_2) * 0x65228539;
		bVar4 = bVar5 * '\x0e' & 0x1e | 1;
		bVar5 = bVar5 * -0xb & 0x1e | 1;
		uVar11 = uVar11 & 0x1e | 1;
		uVar10 = (uVar10 >> bVar4 | uVar10 << 0x20 - bVar4) ^ (uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^
			uVar10;
		*(uint*)(unaff_EBP + -0x1c) = uVar11;
		sVar6 = (sbyte)uVar11;
		bVar4 = ((byte)(10 << sVar6) | (byte)(10 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar5 = ((byte)(4 << bVar5) | (byte)(4 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar10 = (uVar10 >> bVar4 | uVar10 << 0x20 - bVar4) ^ (uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^
			uVar10;
		bVar4 = 0xdU - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		bVar7 = 8U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar10 = (uVar10 >> bVar4 | uVar10 << 0x20 - bVar4) ^ (uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^
			uVar10;
		iVar3 = (uVar10 << (((byte)(0x16 << bVar5) | (byte)(0x16 >> 0x20 - bVar5)) & 0x1e | 1)) + uVar10;
		uVar11 = iVar3 * 0x40000001;
		uVar11 = (iVar3 * 0x1000000 | uVar11 >> 8) ^ (uVar11 >> 0xd | iVar3 * 0x80000) ^ uVar11;
		*(uint*)(unaff_EBP + -4) = uVar11;
		uVar11 = uVar11 >> 9;
		if ((uVar11 & 0x100) == 0) {
			//iVar3 = (uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar3 = (uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uint uVar11_2 = *(uint*)(unaff_EBP + -4) >> 0x12;
		if ((uVar11 & 0x100) == 0) {
			//iVar8 = (uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar8 = (uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar3 + 0xc) == *(int*)(iVar8 + 0xc)) {
		//	iVar3 = func_0x0052e5a4(iVar8);
		//	if (iVar3 != 0) {
		//		uVar11 = 1;
		//		goto LAB_0046ff2a;
		//	}
		//}
		//uVar11 = 0;
	//LAB_0046ff2a:
		//if (uVar11 == (*(uint*)(unaff_EBP + -4) & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -4) & 0xff;
		inst->B = (uVar11 & 0x1ff);
		inst->C = (uVar11_2 & 0x1ff);
	}

	// OP_EQ 23 : A B C
	void d7eb6(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		int iVar6;
		char* pcVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar9 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar9;
		bVar3 = (byte)iVar9 & 0x1e | 1;
		uVar5 = ((param_2 >> 0x1d | param_2 << 3) ^ (param_2 << 0x11 | param_2 >> 0xf) ^ param_2) *
			0x80001 + 0x59792e15;
		uVar5 = (uVar5 * 0x8000 | uVar5 >> 0x11) ^ (uVar5 * 0x400 | uVar5 >> 0x16) ^ uVar5;
		uVar5 = ((uVar5 >> 0x1e | uVar5 << 2) ^ (uVar5 << 0x16 | uVar5 >> 10) ^ uVar5) * 0x735b91ff;
		bVar4 = ((byte)(0xb >> bVar3) | (byte)(0xb << 0x20 - bVar3)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar5;
		bVar3 = ((byte)(2 >> bVar3) | (byte)(2 << 0x20 - bVar3)) & 0x1e | 1;
		uVar5 = (uVar5 >> bVar4 | uVar5 << 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x1c) << bVar3 | *(uint*)(unaff_EBP + -0x1c) >> 0x20 - bVar3) ^
			*(uint*)(unaff_EBP + -0x1c);
		bVar3 = 4U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		uVar5 = (uVar5 >> 0x1a | uVar5 << 6) ^ (uVar5 >> 0x18 | uVar5 << 8) ^ uVar5;
		bVar4 = 2U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		uVar5 = ~((uVar5 >> bVar3 | uVar5 << 0x20 - bVar3) ^ (uVar5 << bVar4 | uVar5 >> 0x20 - bVar4) ^
			uVar5) * 0x8001;
		*(uint*)(unaff_EBP + -4) = uVar5;
		uVar8 = uVar5 >> 0x15;
		if ((uVar8 & 0x100) == 0) {
			//iVar9 = (uVar8 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar9 = (uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uVar5 = uVar5 >> 4;
		if ((uVar5 & 0x100) == 0) {
			//iVar6 = (uVar5 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar6 = (uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar9 + 0xc) == *(int*)(iVar6 + 0xc)) {
		//	iVar9 = func_0x0044e031(iVar9, iVar6);
		//	if (iVar9 != 0) {
		//		uVar5 = 1;
		//		goto LAB_0046ff13;
		//	}
		//}
		//uVar5 = 0;
	//LAB_0046ff13:
		//if (uVar5 == (*(uint*)(unaff_EBP + -4) >> 0xd & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -4) >> 0xd & 0xff;
		inst->B = (uVar8 & 0x1ff);
		inst->C = (uVar5 & 0x1ff);
	}

	// OP_EQ 23 : A B C
	void d83ec(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		byte bVar2;
		char cVar3;
		uint uVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		int iVar8;
		char* pcVar9;
		int iVar10;
		//int unaff_EBP;
		uint uVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar11 = param_1 + -8 >> 2;
		uVar4 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar4;
		sVar5 = (sbyte)uVar4;
		uVar4 = (0x2761e8bf << sVar5 | 0x2761e8bfU >> 0x20 - sVar5) ^ *(uint*)(unaff_EBP + -0x44);
		bVar2 = (byte)uVar11;
		bVar6 = bVar2 * -0xb & 0x1e | 1;
		bVar7 = bVar2 * '\x03' & 0x1e | 1;
		uVar4 = (uVar4 << bVar6 | uVar4 >> 0x20 - bVar6) ^ (uVar4 >> bVar7 | uVar4 << 0x20 - bVar7) ^
			uVar4;
		bVar6 = -bVar2 - 3 & 0x1e | 1;
		uVar4 = (uVar4 << 9 | uVar4 >> 0x17) ^ (uVar4 >> 5 | uVar4 << 0x1b) ^ uVar4;
		uVar4 = uVar4 << bVar6 | uVar4 >> 0x20 - bVar6;
		uVar4 = uVar4 - (uVar4 << ((bVar2 ^ 0xf5) & 0x1e | 1));
		bVar2 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar4 = uVar4 * 0x1000000 ^ uVar4 ^ 0x3aee9e97;
		uVar4 = uVar4 - (uVar4 << (((byte)(4 << bVar2) | (byte)(4 >> 0x20 - bVar2)) & 0x1e | 1));
		uVar4 = uVar4 * 0x400 ^ uVar4;
		*(uint*)(unaff_EBP + -4) = uVar4;
		uVar11 = uVar4 >> 6;
		if ((uVar11 & 0x100) == 0) {
			//iVar10 = (uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar10 = (uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uVar4 = uVar4 >> 0x17;
		if ((uVar4 & 0x100) == 0) {
			//iVar8 = uVar4 * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar8 = (uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar10 + 0xc) == *(int*)(iVar8 + 0xc)) {
		//	iVar10 = func_0x0052c5bd(iVar8);
		//	if (iVar10 != 0) {
		//		uVar4 = 1;
		//		goto LAB_0046fee8;
		//	}
		//}
		//uVar4 = 0;
	//LAB_0046fee8:
		//if (uVar4 == (*(uint*)(unaff_EBP + -4) >> 0xf & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -4) >> 0xf & 0xff;
		inst->B = (uVar11 & 0x1ff);
		inst->C = uVar4;
	}

	// OP_EQ 23 : A B C
	void d8b4d(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		uint uVar6;
		int iVar7;
		char* pcVar8;
		uint uVar9;
		//int unaff_EBP;
		int iVar10;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar10 = param_1 + -8 >> 2;
		cVar2 = (char)iVar10;
		bVar3 = 0xdU - cVar2 & 0x1e | 1;
		bVar4 = -cVar2 - 9U & 0x1e | 1;
		uVar9 = (param_2 << bVar3 | param_2 >> 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar4 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar9 = (uVar9 << 0x17 | uVar9 >> 9) ^ (uVar9 >> 4 | uVar9 << 0x1c) ^ uVar9;
		uVar9 = uVar9 << 0x1a ^ uVar9;
		bVar3 = 0xeU - cVar2 & 0x1e | 1;
		bVar4 = 9U - cVar2 & 0x1e | 1;
		uVar9 = (uVar9 >> bVar3 | uVar9 << 0x20 - bVar3) ^ (uVar9 >> bVar4 | uVar9 << 0x20 - bVar4) ^
			uVar9;
		uVar5 = ((uVar9 >> 0x19 | uVar9 << 7) ^ (uVar9 << 5 | uVar9 >> 0x1b) ^ uVar9) +
			iVar10 * 0x6a157e71;
		uVar9 = uVar5 >> 0xb;
		uVar5 = uVar5 * 0x200000;
		uVar6 = uVar9 | uVar5;
		*(uint*)(unaff_EBP + -4) = uVar6;
		if ((uVar9 & 0x100) == 0) {
			//iVar10 = (uVar9 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar10 = (uVar9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uVar6 = uVar6 >> 0x13;
		if ((uVar5 & 0x8000000) == 0) {
			//iVar7 = (uVar6 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar7 = (uVar6 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar10 + 0xc) == *(int*)(iVar7 + 0xc)) {
		//	iVar10 = func_0x0052b642(iVar7);
		//	if (iVar10 != 0) {
		//		uVar9 = 1;
		//		goto LAB_0046fed4;
		//	}
		//}
		//uVar9 = 0;
	//LAB_0046fed4:
		//if (uVar9 == (*(uint*)(unaff_EBP + -4) >> 9 & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -4) >> 9 & 0xff;
		inst->B = (uVar9 & 0x1ff);
		inst->C = (uVar6 & 0x1ff);
	}

	// OP_EQ 23 : A B C
	void dc7f9(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		int iVar6;
		char* pcVar7;
		uint uVar8;
		int iVar9;
		//int unaff_EBP;
		uint uVar10;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar10 = param_1 + -8 >> 2;
		bVar5 = (byte)uVar10;
		uVar10 = ((uVar10 ^ 0x111a4806) + param_2) * -0x7f;
		bVar3 = bVar5 - 8 & 0x1e | 1;
		uVar10 = uVar10 >> 0x13 ^ uVar10;
		uVar10 = uVar10 >> 1 ^ uVar10;
		uVar10 = uVar10 >> ((bVar5 ^ 0xfb) & 0x1e | 1) ^ uVar10;
		bVar4 = bVar5 - 0xf & 0x1e | 1;
		uVar10 = ~((uVar10 << bVar3 | uVar10 >> 0x20 - bVar3) * 0x11be49d1 + 0xe048eff0);
		*(uint*)(unaff_EBP + -4) = uVar10 << bVar4 | uVar10 >> 0x20 - bVar4;
		bVar5 = bVar5 - 9 & 0x1e | 1;
		uVar10 = *(uint*)(unaff_EBP + -4) ^ (uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^ uVar10;
		*(uint*)(unaff_EBP + -4) = uVar10;
		uVar8 = uVar10 >> 9;
		if ((uVar8 & 0x100) == 0) {
			//iVar9 = (uVar8 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar9 = (uVar8 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		if ((uVar10 & 0x100) == 0) {
			//iVar6 = (uVar10 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar6 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//if (*(int*)(iVar9 + 0xc) == *(int*)(iVar6 + 0xc)) {
		//	iVar9 = func_0x00524afe(iVar6);
		//	if (iVar9 != 0) {
		//		uVar10 = 1;
		//		goto LAB_0046fec8;
		//	}
		//}
		//uVar10 = 0;
	//LAB_0046fec8:
		//if (uVar10 == (*(uint*)(unaff_EBP + -4) >> 0x12 & 0xff)) {

		inst->OP = 23;
		inst->A = *(uint*)(unaff_EBP + -4) >> 0x12 & 0xff;
		inst->B = (uVar8 & 0x1ff);
		inst->C = (uVar10 & 0x1ff);
	}

	// OP_LT 24 : A B C
	void d2e99(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		uint uVar4;
		sbyte sVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		int iVar9;
		char* pcVar10;
		//int unaff_EBP;
		uint uVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar11 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar11;
		uVar4 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar4;
		sVar5 = (sbyte)uVar4;
		bVar6 = ((byte)(0x12 << sVar5) | (byte)(0x12 >> 0x20 - sVar5)) & 0x1e | 1;
		uVar4 = ~(((*(uint*)(unaff_EBP + -0x44) >> 0xc ^ *(uint*)(unaff_EBP + -0x44)) - uVar11) +
			0x5328aecf);
		uVar4 = (uVar4 >> bVar6 | uVar4 << 0x20 - bVar6) * 0x5441111b;
		bVar7 = (char)uVar11 + 0xdU & 0x1e | 1;
		bVar8 = (char)uVar11 + 1U & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar4 = ~((uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^ (uVar4 >> bVar8 | uVar4 << 0x20 - bVar8) ^
			uVar4);
		*(uint*)(unaff_EBP + -0x54) = uVar4;
		bVar7 = ((byte)(0x1b << bVar6) | (byte)(0x1b >> 0x20 - bVar6)) & 0x1e | 1;
		int intuVar11 = uVar11;
		bVar8 = (byte)((-intuVar11 & 7) << 2) | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar6 = ((byte)(0x1a << bVar6) | (byte)(0x1a >> 0x20 - bVar6)) & 0x1e | 1;
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		uVar4 = (uVar4 >> bVar7 | uVar4 << 0x20 - bVar7) ^
			(*(uint*)(unaff_EBP + -0x54) >> bVar6 | *(uint*)(unaff_EBP + -0x54) << 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -0x54) ^ *(uint*)(unaff_EBP + -4) ^ 0x5369926d;
		uVar4 = uVar4 >> bVar8 | uVar4 << 0x20 - bVar8;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar4 = (uVar4 - (uVar4 << (((byte)(4 >> bVar6) | (byte)(4 << 0x20 - bVar6)) & 0x1e | 1))) *
			0x36e3314f ^ (0x3b0fdb97U >> bVar7 | 0x3b0fdb97 << 0x20 - bVar7);
		*(uint*)(unaff_EBP + -4) = uVar4;
		//iVar9 = *(int*)(unaff_EBP + -0x5c);
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		if ((uVar4 & 0x100) == 0) {
			//iVar9 = (uVar4 & 0x1ff) * 0x10 + iVar9;
		}
		else {
			//iVar9 = *(int*)(unaff_EBP + -0x6c) + (uVar4 & 0xff) * 0x10;
		}
		//uVar4 = func_0x005392d3(iVar9);
		//if (uVar4 == *(uint*)(unaff_EBP + -4) >> 0x18) {

		inst->OP = 24;
		inst->A = *(uint*)(unaff_EBP + -4) >> 0x18;
		inst->C = (uVar4 & 0x1ff);
		inst->B = uVar4 >> 0x9 & 0x1ff;
	}

	// OP_LT 24 : A B C
	void d4860(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		int iVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		uint uVar8;
		char* pcVar9;
		uint uVar10;
		//int unaff_EBP;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar4 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar4;
		bVar6 = (byte)iVar4;
		bVar5 = (bVar6 ^ 8) & 0x1e | 1;
		bVar6 = bVar6 & 0x1e | 1;
		uVar10 = param_2 << bVar5 | param_2 >> 0x20 - bVar5;
		*(uint*)(unaff_EBP + -0x44) = uVar10;
		bVar5 = ((byte)(0x14 >> bVar6) | (byte)(0x14 << 0x20 - bVar6)) & 0x1e | 1;
		bVar7 = ((byte)(8 >> bVar6) | (byte)(8 << 0x20 - bVar6)) & 0x1e | 1;
		uVar10 = ((uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44)) * 0x1000001;
		uVar8 = uVar10 >> 10 ^ uVar10;
		uVar8 = (uVar10 >> 0x1c | uVar8 << 4) ^ (uVar8 >> 0xe | uVar8 << 0x12) ^ uVar8;
		uVar8 = uVar8 << (-(char)*(undefined4*)(unaff_EBP + -4) - 7U & 0x1e | 1) ^ uVar8;
		iVar4 = uVar8 - (uVar8 << (((byte)(0x16 >> bVar6) | (byte)(0x16 << 0x20 - bVar6)) & 0x1e | 1));
		uVar10 = iVar4 * -0x3f;
		uVar10 = (iVar4 * -0xfc0000 | uVar10 >> 0xe) ^ (uVar10 >> 5 | iVar4 * 0x8000000) ^ uVar10;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -4);
		bVar5 = cVar3 + 0xbU & 0x1e | 1;
		bVar7 = cVar3 - 3U & 0x1e | 1;
		iVar4 = (((uVar10 << bVar5 | uVar10 >> 0x20 - bVar5) ^ (uVar10 >> bVar7 | uVar10 << 0x20 - bVar7)
			^ uVar10) + 0x3acc02a1) * -0x7fff;
		iVar4 = iVar4 - (iVar4 << (((byte)(1 >> bVar6) | (byte)(1 << 0x20 - bVar6)) & 0x1e | 1));
		uVar10 = iVar4 * 0xa137725;
		uVar10 = (uVar10 >> 0x1c | iVar4 * -0x5ec88db0) ^ (iVar4 * 0x1426ee4a | (uint)((int)uVar10 < 0)) ^
			uVar10;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -4);
		bVar6 = cVar3 - 0xeU & 0x1e | 1;
		uVar8 = uVar10 >> bVar6 | uVar10 << 0x20 - bVar6;
		*(uint*)(unaff_EBP + -4) = uVar8;
		bVar6 = cVar3 - 8U & 0x1e | 1;
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		iVar4 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = ~(uVar8 ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^ uVar10);
		*(uint*)(unaff_EBP + -4) = uVar10;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		uVar10 = uVar10 >> 8;
		if ((uVar10 & 0x100) == 0) {
			//iVar4 = iVar4 + (uVar10 & 0x1ff) * 0x10;
		}
		else {
			//iVar4 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//uVar10 = func_0x00535718(iVar4);
		//if (uVar10 == (*(uint*)(unaff_EBP + -4) & 0xff)) {

		inst->OP = 24;
		inst->A = *(uint*)(unaff_EBP + -4) & 0xff;
		inst->C = (uVar10 & 0x1ff);
		inst->B = (*(uint*)(unaff_EBP + -4) >> 0x13 & 0x1ff);
	}

	// OP_LT 24 : A B C
	void d9d2d(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		uint uVar4;
		int iVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		sbyte sVar9;
		char* pcVar10;
		int iVar11;
		//int unaff_EBP;
		uint uVar12;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar4 = param_1 + -8 >> 2;
		bVar8 = (byte)uVar4;
		*(uint*)(unaff_EBP + -4) = uVar4;
		bVar6 = -bVar8 - 0xb & 0x1e | 1;
		bVar7 = (bVar8 ^ 0xfb) & 0x1e | 1;
		bVar8 = 6 - bVar8 & 0x1e | 1;
		uVar12 = uVar4 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar12;
		uVar4 = (*(uint*)(unaff_EBP + -0x44) << bVar6 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar8 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar8) ^
			*(uint*)(unaff_EBP + -0x44);
		sVar9 = (sbyte)uVar12;
		bVar8 = ((byte) * (undefined4*)(unaff_EBP + -4) ^ 0xf9) & 0x1e | 1;
		uVar4 = ~(((uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^ 0x62389e28) +
			(0x687df4c8 << sVar9 | 0x687df4c8U >> 0x20 - sVar9) +
			*(int*)(unaff_EBP + -4) * 0x48ee6fcd);
		uVar4 = (uVar4 << 8 | uVar4 >> 0x18) ^ (uVar4 << 6 | uVar4 >> 0x1a) ^ uVar4;
		bVar6 = ((byte) * (undefined4*)(unaff_EBP + -4) ^ 0xfd) & 0x1e | 1;
		uVar4 = (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^ (uVar4 << bVar6 | uVar4 >> 0x20 - bVar6) ^
			uVar4;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -4);
		uVar4 = uVar4 - (uVar4 << (cVar3 * '\x04' & 0x1eU | 1)) ^ 0x5771aac9;
		bVar8 = cVar3 + 3U & 0x1e | 1;
		uVar4 = (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^ (uVar4 >> bVar8 | uVar4 << 0x20 - bVar8) ^
			uVar4;
		uVar4 = uVar4 >> (4U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1) ^ uVar4;
		bVar6 = ((byte)(0x1b << sVar9) | (byte)(0x1b >> 0x20 - sVar9)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar7 = ((byte)(5 << bVar8) | (byte)(5 >> 0x20 - bVar8)) & 0x1e | 1;
		iVar11 = *(int*)(unaff_EBP + -4);
		bVar8 = (byte)iVar11;
		uVar4 = (uVar4 >> bVar6 | uVar4 << 0x20 - bVar6) ^ (uVar4 << bVar7 | uVar4 >> 0x20 - bVar7) ^
			uVar4;
		bVar6 = (bVar8 ^ 0xc) & 0x1e | 1;
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		*(uint*)(unaff_EBP + -4) = uVar4 << bVar6 | uVar4 >> 0x20 - bVar6;
		bVar8 = (bVar8 ^ 10) & 0x1e | 1;
		iVar5 = *(int*)(unaff_EBP + -0x5c);
		uVar4 = ((*(uint*)(unaff_EBP + -4) ^ (uVar4 << bVar8 | uVar4 >> 0x20 - bVar8) ^ uVar4) - iVar11)
			+ 0x3aa973bd;
		//iVar11 = *(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c);
		*(uint*)(unaff_EBP + -4) = uVar4;
		//*(uint**)(iVar11 + 0xc) = puVar1;
		if ((uVar4 & 0x100) == 0) {
			//iVar11 = (uVar4 & 0x1ff) * 0x10 + iVar5;
		}
		else {
			//iVar11 = (uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uint uVar4_2 = uVar4 >> 0xe;
		if ((uVar4 & 0x100) == 0) {
			//iVar5 = (uVar4 & 0x1ff) * 0x10 + iVar5;
		}
		else {
			//iVar5 = (uVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		/* WARNING: Call to offcut address within same function */
		//uVar4 = func_0x0046ffe3(iVar5, iVar11);
		//if (uVar4 == (*(uint*)(unaff_EBP + -4) >> 0x17 & 0xff)) {

		inst->OP = 24;
		inst->A = *(uint*)(unaff_EBP + -4) >> 0x17 & 0xff;
		inst->C = (uVar4 & 0x1ff);
		inst->B = (uVar4_2 & 0x1ff);
	}

	// OP_LE 25 : A B C
	void d1f6b(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		char* pcVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		uVar7 = *(uint*)(unaff_EBP + -0x44) >> 0x17 |
			(param_2 >> 0x10 ^ *(uint*)(unaff_EBP + -0x44)) << 9;
		*(int*)(unaff_EBP + -0xc) = param_1;
		cVar3 = (char)(param_1 + -8 >> 2);
		bVar4 = -cVar3 - 0x10U & 0x1e | 1;
		bVar5 = 1U - cVar3 & 0x1e | 1;
		uVar7 = (uVar7 >> bVar4 | uVar7 << 0x20 - bVar4) ^ (uVar7 >> bVar5 | uVar7 << 0x20 - bVar5) ^
			uVar7;
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		uVar7 = (uVar7 >> 4 | uVar7 << 0x1c) ^ (uVar7 << 1 | (uint)((int)uVar7 < 0)) ^ uVar7 ^ 0xcf84685;
		iVar8 = *(int*)(unaff_EBP + -0x5c);
		*(uint*)(unaff_EBP + -4) = ~(uVar7 << (cVar3 * -6 & 0x1eU | 1) ^ uVar7);
		uVar7 = *(uint*)(unaff_EBP + -4);
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		uVar7 = uVar7 >> 8;
		if ((uVar7 & 0x100) == 0) {
			//iVar8 = iVar8 + (uVar7 & 0x1ff) * 0x10;
		}
		else {
			//iVar8 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//uVar7 = func_0x0053c154(iVar8);
		//if (uVar7 == (*(uint*)(unaff_EBP + -4) & 0xff)) {

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) & 0xff;
		inst->B = (*(uint*)(unaff_EBP + -4) >> 0x12 & 0x1ff);
		inst->C = (uVar7 & 0x1ff);
	}

	// OP_LE 25 : A B C
	void d2de8(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		uint* puVar2;
		char cVar3;
		char cVar4;
		//ushort uVar5;
		byte bVar6;
		byte bVar7;
		char cVar8;
		char* pcVar9;
		uint uVar10;
		//int unaff_EBP;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		bVar7 = (byte)(param_1 + -8 >> 2);
		bVar6 = bVar7 & 0x1e | 1;
		uVar10 = (param_2 << (bVar7 * '\x02' & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44)) + 0x1b11c59c;
		uVar10 = (uVar10 >> 0xe | uVar10 * 0x40000) ^ (uVar10 >> 3 | uVar10 * 0x20000000) ^ uVar10;
		uVar10 = uVar10 * 4 ^ uVar10;
		bVar7 = ((byte)(0x1c << bVar6) | (byte)(0x1c >> 0x20 - bVar6)) & 0x1e | 1;
		uVar1 = *(undefined4*)(unaff_EBP + -0x5c);
		*(uint*)(unaff_EBP + -4) = uVar10 >> bVar7 | uVar10 << 0x20 - bVar7;
		bVar7 = ((byte)(0x12 << bVar6) | (byte)(0x12 >> 0x20 - bVar6)) & 0x1e | 1;
		uVar10 = *(uint*)(unaff_EBP + -4) ^ (uVar10 >> bVar7 | uVar10 << 0x20 - bVar7) ^ uVar10;
		puVar2 = *(uint**)(unaff_EBP + -0x50);
		*(uint*)(unaff_EBP + -4) = uVar10;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar2;
		//cVar4 = (char)uVar1;
		if ((uVar10 & 0x100) == 0) {
			//cVar8 = (char)uVar10 * '\x10' + cVar4;
		}
		else {
			//cVar8 = (char)uVar10 * '\x10' + (char)*(undefined4*)(unaff_EBP + -0x6c);
		}
		//cVar3 = (char)(uVar10 >> 0x11);
		if ((uVar10 >> 0x11 & 0x100) == 0) {
			//cVar4 = cVar3 * '\x10' + cVar4;
		}
		else {
			//cVar4 = cVar3 * '\x10' + (char)*(undefined4*)(unaff_EBP + -0x6c);
		}
		//uVar10 = FUN_0045acf8(cVar4, cVar8);
		//if (uVar10 != (*(uint*)(unaff_EBP + -4) >> 9 & 0xff)) {

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) >> 9 & 0xff;
		inst->C = uVar10 & 0x1ff;
		inst->B = uVar10 >> 0x11 & 0x1ff;
	}

	// OP_LE 25 : A B C
	void dc39b(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		int iVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		int iVar9;
		char* pcVar10;
		//int unaff_EBP;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar7 = ~((param_2 >> 0xf | param_2 << 0x11) ^ (param_2 << 2 | param_2 >> 0x1e) ^ param_2);
		uVar8 = uVar7 * 0x80001;
		uVar8 = (uVar8 >> 0x1e | uVar7 * 0x200004) ^ (uVar7 * 0x200004 | uVar8 >> 0x1e) ^ uVar8;
		bVar6 = (byte)(param_1 + -8 >> 2);
		bVar5 = bVar6 & 0x1e | 1;
		uVar7 = ~((uVar8 << (-bVar6 - 6 & 0x1e | 1)) + uVar8);
		uVar7 = uVar7 - (uVar7 << (((byte)(0x11 >> bVar5) | (byte)(0x11 << 0x20 - bVar5)) & 0x1e | 1));
		bVar6 = ((byte)(8 << bVar5) | (byte)(8 >> 0x20 - bVar5)) & 0x1e | 1;
		iVar4 = *(int*)(unaff_EBP + -0x5c);
		*(uint*)(unaff_EBP + -4) = uVar7 << bVar6 | uVar7 >> 0x20 - bVar6;
		bVar6 = ((byte)(4 << bVar5) | (byte)(4 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar7 = *(uint*)(unaff_EBP + -4) ^ (uVar7 << bVar6 | uVar7 >> 0x20 - bVar6) ^ uVar7;
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		*(uint*)(unaff_EBP + -4) = uVar7;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		if ((uVar7 & 0x100) == 0) {
			//iVar9 = (uVar7 & 0x1ff) * 0x10 + iVar4;
		}
		else {
			//iVar9 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uint uVar7_2 = uVar7 >> 0x13;
		if ((uVar7 & 0x100) == 0) {
			//iVar4 = (uVar7 & 0x1ff) * 0x10 + iVar4;
		}
		else {
			//iVar4 = (uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//uVar7 = FUN_004465af(iVar9, iVar4);
		//if (uVar7 == (*(uint*)(unaff_EBP + -4) >> 9 & 0xff)) {

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) >> 9 & 0xff;
		inst->B = (uVar7_2 & 0x1ff);
		inst->C = (uVar7 & 0x1ff);
	}

	// OP_LE 25 : A B C
	void dccf9(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		int iVar4;
		char** ppcVar5;
		byte bVar6;
		byte bVar7;
		int iVar8;
		char** ppcVar9;
		char* pcVar10;
		//int unaff_EBP;
		uint uVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar4 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar4;
		bVar7 = (byte)iVar4;
		bVar6 = (bVar7 ^ 0xf1) & 0x1e | 1;
		param_2 = param_2 << (bVar7 * '\x05' & 0x1e | 1) ^ param_2;
		bVar7 = (bVar7 ^ 0xfd) & 0x1e | 1;
		param_2 = (param_2 >> bVar7 | param_2 << 0x20 - bVar7) ^
			(param_2 >> bVar6 | param_2 << 0x20 - bVar6) ^ param_2;
		uVar11 = (param_2 >> ((char)*(undefined4*)(unaff_EBP + -4) * -3 & 0x1eU | 1) ^ param_2) +
			0x9e767f11;
		uVar11 = uVar11 * 0x10000000 | uVar11 >> 4;
		bVar7 = ((byte) * (undefined4*)(unaff_EBP + -4) ^ 0xf3) & 0x1e | 1;
		iVar4 = *(int*)(unaff_EBP + -0x6c);
		uVar11 = (uVar11 << bVar7 | uVar11 >> 0x20 - bVar7) ^ (uVar11 << bVar6 | uVar11 >> 0x20 - bVar6) ^
			uVar11;
		cVar3 = (char)*(int*)(unaff_EBP + -4);
		uVar11 = (uVar11 << (cVar3 - 9U & 0x1e | 1)) + uVar11;
		//puVar1 = *(uint**)(unaff_EBP + -0x50);
		uVar11 = ((uVar11 >> (cVar3 - 0xfU & 0x1e | 1) ^ uVar11) * 0x1dfff1 - *(int*)(unaff_EBP + -4)) +
			0x8f32cfdc;
		*(uint*)(unaff_EBP + -4) = uVar11;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		if ((uVar11 & 0x100) == 0) {
			//iVar8 = (uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar8 = (uVar11 & 0xff) * 0x10 + iVar4;
		}
		uint uVar11_2 = uVar11 >> 9;
		if ((uVar11 & 0x100) == 0) {
			//iVar4 = (uVar11 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c);
		}
		else {
			//iVar4 = (uVar11 & 0xff) * 0x10 + iVar4;
		}
		//ppcVar5 = (char**)FUN_0046ff5f(iVar8, iVar4);
		//ppcVar9 = (char**)(*(uint*)(unaff_EBP + -4) >> 0x14 & 0xff);

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) >> 0x14 & 0xff;
		inst->B = (uVar11_2 & 0x1ff);
		inst->C = (uVar11 & 0x1ff);
	}

	// OP_LE 25 : A B C
	void dceda(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		int iVar7;
		char* pcVar8;
		int iVar9;
		//int unaff_EBP;
		uint uVar10;
		uint uVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar10 = param_1 + -8 >> 2;
		uVar11 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar11;
		sVar4 = (sbyte)uVar11;
		bVar5 = ((byte)(0x19 >> sVar4) | (byte)(0x19 << 0x20 - sVar4)) & 0x1e | 1;
		uVar11 = (param_2 << bVar5 | param_2 >> 0x20 - bVar5) ^ uVar10 + 0x22c76a03;
		*(uint*)(unaff_EBP + -0x44) = uVar11;
		bVar5 = ((byte)uVar10 ^ 6) & 0x1e | 1;
		bVar6 = ((byte)uVar10 ^ 2) & 0x1e | 1;
		uVar10 = (uVar11 >> bVar5 | uVar11 << 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar6 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar11 = uVar10 >> 0xd;
		uVar11 = (uVar11 << 0x18 | (uVar10 << 0x13 | uVar11) >> 8) +
			(0x50de77d0U >> sVar4 | 0x50de77d0 << 0x20 - sVar4) ^
			(0x5e9c8602U >> sVar4 | 0x5e9c8602 << 0x20 - sVar4);
		uVar11 = uVar11 << 5 ^ uVar11;
		bVar6 = ((byte)(0x1e << sVar4) | (byte)(0x1e >> 0x20 - sVar4)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(0x17 << bVar5) | (byte)(0x17 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar11 = (uVar11 << bVar6 | uVar11 >> 0x20 - bVar6) ^ (uVar11 >> bVar5 | uVar11 << 0x20 - bVar5) ^
			uVar11;
		uVar11 = uVar11 >> 9 ^ uVar11;
		uVar11 = ~(uVar11 << 0x1d ^ uVar11);
		uVar10 = uVar11 * 0x24e404af;
		uVar10 = (uVar11 * -0x20000000 | uVar10 >> 3) ^ (uVar11 * -0x37f6a200 | uVar10 >> 0x17) ^ uVar10;
		uVar10 = (uVar10 >> 0x1e | uVar10 << 2) ^ (uVar10 << 4 | uVar10 >> 0x1c) ^ uVar10;
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = (uVar10 >> 0x14 | uVar10 << 0xc) ^ (uVar10 >> 0xb | uVar10 << 0x15) ^ uVar10;
		*(uint*)(unaff_EBP + -4) = uVar10;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		uVar11 = uVar10 >> 0x15;
		if ((uVar11 & 0x100) == 0) {
			//iVar7 = iVar9 + (uVar11 & 0x1ff) * 0x10;
		}
		else {
			//iVar7 = *(int*)(unaff_EBP + -0x6c) + (uVar11 & 0xff) * 0x10;
		}
		uVar10 = uVar10 >> 8;
		if ((uVar10 & 0x100) == 0) {
			//iVar9 = iVar9 + (uVar10 & 0x1ff) * 0x10;
		}
		else {
			//iVar9 = *(int*)(unaff_EBP + -0x6c) + (uVar10 & 0xff) * 0x10;
		}
		//uVar11 = FUN_0046ff97(iVar7, iVar9);
		//if (uVar11 == (*(uint*)(unaff_EBP + -4) & 0xff)) {

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) & 0xff;
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar11 & 0x1ff);
	}

	// OP_LE 25 : A B C
	void ddd85(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		uint uVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		int iVar10;
		int iVar11;
		//int unaff_EBP;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar9 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar9;
		uVar4 = param_2 * 0x80001 + -0x10fbaac2 + uVar9;
		uVar9 = uVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar9;
		uVar4 = uVar4 >> 0xb ^ uVar4;
		sVar6 = (sbyte)uVar9;
		bVar7 = ((byte)(0x14 << sVar6) | (byte)(0x14 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar8 = ((byte)(1 << bVar8) | (byte)(1 >> 0x20 - bVar8)) & 0x1e | 1;
		uVar4 = (uVar4 >> bVar7 | uVar4 << 0x20 - bVar7) ^ (uVar4 >> bVar8 | uVar4 << 0x20 - bVar8) ^
			uVar4;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0x1c);
		uVar4 = ~(uVar4 + 0x829fb754 +
			(uVar4 << (((byte)(4 << (bVar8 & 0x1f)) | (byte)(4 >> 0x20 - (bVar8 & 0x1f))) & 0x1e | 1)
				));
		uVar4 = uVar4 >> (((byte)(0xb << (bVar8 & 0x1f)) | (byte)(0xb >> 0x20 - (bVar8 & 0x1f))) & 0x1e |
			1) ^ uVar4;
		uVar4 = ((uVar4 >> 0x16 | uVar4 << 10) ^ (uVar4 >> 0x15 | uVar4 << 0xb) ^ uVar4) * 0x759b8a1b -
			(0x28666b5d << (bVar8 & 0x1f) | 0x28666b5dU >> 0x20 - (bVar8 & 0x1f));
		uVar4 = uVar4 * 8 ^ uVar4;
		uVar4 = (uVar4 << 5 | uVar4 >> 0x1b) ^ (uVar4 << 1 | (uint)((int)uVar4 < 0)) ^ uVar4;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -4);
		uVar9 = ~((uVar4 << (cVar3 + 0xbU & 0x1e | 1)) + uVar4);
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = uVar9 << (cVar3 + 5U & 0x1e | 1) ^ uVar9;
		uVar4 = uVar9 << 0xe;
		uVar9 = uVar4 | uVar9 >> 0x12;
		*(uint*)(unaff_EBP + -4) = uVar9;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		uVar9 = uVar9 >> 8;
		if ((uVar4 & 0x10000) == 0) {
			//iVar10 = iVar11 + (uVar9 & 0x1ff) * 0x10;
		}
		else {
			//iVar10 = *(int*)(unaff_EBP + -0x6c) + (uVar9 & 0xff) * 0x10;
		}
		uVar4 = uVar4 >> 0x11;
		if ((uVar4 & 0x100) == 0) {
			//iVar11 = iVar11 + (uVar4 & 0x1ff) * 0x10;
		}
		else {
			//iVar11 = *(int*)(unaff_EBP + -0x6c) + (uVar4 & 0xff) * 0x10;
		}
		//pcVar5 = (char*)FUN_0046ffa2(iVar11, iVar10);
		//if (pcVar5 == (char*)(*(uint*)(unaff_EBP + -4) & 0xff)) {

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) & 0xff;
		inst->B = (uVar4 & 0x1ff);
		inst->C = (uVar9 & 0x1ff);
	}

	// OP_LE 25 : A B C
	void defdd(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		int iVar4;
		uint uVar5;
		char** ppcVar6;
		byte bVar7;
		byte bVar8;
		char* pcVar9;
		uint uVar10;
		//int unaff_EBP;
		int iVar11;
		//undefined2 in_ES;

		iVar4 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = iVar4;
		uVar10 = iVar4 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar10;
		uVar5 = ~*(uint*)(unaff_EBP + -0x44) ^ uVar10 ^ 0x44e6dea;
		uVar5 = uVar5 >> 0x10 | uVar5 << 0x10;
		*(uint*)(unaff_EBP + -0x44) = uVar5;
		uVar5 = *(int*)(unaff_EBP + -0x44) - (uVar5 << (3 - (byte)uVar10 & 0x1e | 1));
		bVar7 = (byte)uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x44) = uVar5;
		*(uint*)(unaff_EBP + -0x1c) = (uVar10 ^ 0xfffffff7) & 0x1e | 1;
		bVar8 = ((byte)(10 << bVar7) | (byte)(10 >> 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = ((byte)(8 << bVar7) | (byte)(8 >> 0x20 - bVar7)) & 0x1e | 1;
		uVar5 = ~((uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7) ^
			*(uint*)(unaff_EBP + -0x44));
		puVar1 = *(uint**)(unaff_EBP + -0x50);
		uVar5 = (uVar5 >> 10 | uVar5 << 0x16) * 0x200001 ^ 0xc61248e;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar10 = uVar5 << bVar7 | uVar5 >> 0x20 - bVar7;
		uVar10 = (uVar10 << (((byte) * (undefined4*)(unaff_EBP + -4) ^ 4) & 0x1e | 1)) + uVar10;
		iVar4 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = uVar10 * 0x100 ^ uVar10;
		*(uint*)(unaff_EBP + -4) = uVar10;
		//*(uint**)(*(int*)(*(int*)(unaff_EBP + -0xa8) + 0x1c) + 0xc) = puVar1;
		uVar5 = uVar10 >> 8;
		if ((uVar5 & 0x100) == 0) {
			//iVar11 = iVar4 + (uVar5 & 0x1ff) * 0x10;
		}
		else {
			//iVar11 = (uVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		uVar10 = uVar10 >> 0x17;
		if ((uVar10 & 0x100) == 0) {
			//iVar4 = iVar4 + uVar10 * 0x10;
		}
		else {
			//iVar4 = (uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}
		//ppcVar6 = (char**)FUN_0046ff53(iVar4, iVar11);
		//if (ppcVar6 == (char**)(*(uint*)(unaff_EBP + -4) & 0xff)) {

		inst->OP = 25;
		inst->A = *(uint*)(unaff_EBP + -4) & 0xff;
		inst->B = uVar10;
		inst->C = (uVar5 & 0x1ff);
	}

	// OP_TEST 26 : A C 
	void d1c23(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		char* pcVar7;
		uint uVar8;
		//int unaff_EBP;
		int iVar9;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar9 = param_1 + -8 >> 2;
		bVar5 = (byte)iVar9;
		*(int*)(unaff_EBP + -4) = iVar9;
		uVar8 = param_2 >> (0xf - bVar5 & 0x1e | 1) ^ *(uint*)(unaff_EBP + -0x44);
		bVar3 = bVar5 * -0xb & 0x1e | 1;
		bVar4 = bVar5 & 0x1e | 1;
		bVar5 = bVar5 * '\x06' & 0x1e | 1;
		uVar8 = (uVar8 << bVar3 | uVar8 >> 0x20 - bVar3) ^ (uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^
			uVar8;
		uVar8 = uVar8 >> 9 | uVar8 << 0x17;
		bVar5 = ((byte)(0x1d << bVar4) | (byte)(0x1d >> 0x20 - bVar4)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar8;
		bVar3 = ((byte)(0x10 << bVar4) | (byte)(0x10 >> 0x20 - bVar4)) & 0x1e | 1;
		iVar9 = ((uVar8 >> bVar5 | uVar8 << 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x1c) >> bVar3 | *(uint*)(unaff_EBP + -0x1c) << 0x20 - bVar3) ^
			*(int*)(unaff_EBP + -4) * 0x17c7d9b1 ^ *(uint*)(unaff_EBP + -0x1c)) + 0xad0d6b7f;
		uVar8 = (iVar9 - (iVar9 << (((byte)(0x16 >> bVar4) | (byte)(0x16 << 0x20 - bVar4)) & 0x1e | 1))) *
			-3;
		uVar8 = ~(uVar8 >> 0x19 ^ uVar8) * 0x61f25ecd + 0x1da7a1c3;
		uVar8 = uVar8 >> 1 ^ uVar8;
		uVar8 = (uVar8 << ((char)*(undefined4*)(unaff_EBP + -4) + 6U & 0x1e | 1)) + uVar8;
		uVar6 = uVar8 & 0xff;
		//iVar9 = *(int*)(*(int*)(unaff_EBP + -0x5c) + 0xc + uVar6 * 0x10);
		//if ((iVar9 == 0) || ((iVar9 == 1 && (*(int*)(*(int*)(unaff_EBP + -0x5c) + uVar6 * 0x10) == 0))))
		//{
			//uVar6 = 1;
		//}
		//else {
			//uVar6 = 0;
		//}
		//if (uVar6 != (uVar8 >> 0xe & 0x1ff)) {

		inst->OP = 26;
		inst->A = uVar6;
		inst->C = uVar8 >> 0xe & 0x1ff;
	}

	// OP_TEST 26 : A C 
	void d4c2a(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4 uVar2;
		char cVar3;
		sbyte sVar4;
		byte bVar5;
		byte bVar6;
		char* pcVar7;
		uint uVar8;
		//int unaff_EBP;
		uint uVar9;
		uint uVar10;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar10 = *(uint*)(unaff_EBP + -0x44) >> 4 | *(uint*)(unaff_EBP + -0x44) << 0x1c;
		uVar8 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar8;
		uVar9 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar9;
		sVar4 = (sbyte)uVar9;
		uVar8 = ~(uVar10 - (uVar10 << ((char)uVar8 * -5 & 0x1eU | 1)));
		*(uint*)(unaff_EBP + -0x44) = uVar8;
		bVar5 = ((byte)(0x12 << sVar4) | (byte)(0x12 >> 0x20 - sVar4)) & 0x1e | 1;
		bVar6 = ((byte)(8 << sVar4) | (byte)(8 >> 0x20 - sVar4)) & 0x1e | 1;
		uVar8 = (uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar6 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar6) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar8 = uVar8 - (uVar8 << (((byte)(0x19 << sVar4) | (byte)(0x19 >> 0x20 - sVar4)) & 0x1e | 1));
		iVar1 = *(int*)(unaff_EBP + -4);
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0x1c);
		bVar5 = bVar6 & 0x1f;
		uVar8 = (~(uVar8 << (((byte)(2 >> sVar4) | (byte)(2 << 0x20 - sVar4)) & 0x1e | 1) ^ uVar8) +
			iVar1 * -0x60dd77aa + (0x3c03e85f << bVar5 | 0x3c03e85fU >> 0x20 - bVar5)) * -0x7ffffff;
		bVar6 = bVar6 & 0x1f;
		uVar8 = uVar8 >> (((byte)(0xc << bVar6) | (byte)(0xc >> 0x20 - bVar6)) & 0x1e | 1) ^ uVar8;
		uVar8 = ((uVar8 >> 0x17 | uVar8 << 9) ^ (uVar8 >> 4 | uVar8 << 0x1c) ^ 0x5fb07bfaU - iVar1 ^ uVar8
			) * -0x1a602657;
		bVar5 = 0xcU - (char)iVar1 & 0x1e | 1;
		bVar6 = -(char)iVar1 - 5U & 0x1e | 1;
		uVar8 = iVar1 + 0x2fde62f3 +
			((uVar8 << bVar5 | uVar8 >> 0x20 - bVar5) ^ (uVar8 >> bVar6 | uVar8 << 0x20 - bVar6) ^
				uVar8);
		uVar9 = uVar8 & 0xff;
		//iVar1 = *(int*)(*(int*)(unaff_EBP + -0x5c) + 0xc + uVar9 * 0x10);
		//if ((iVar1 == 0) || ((iVar1 == 1 && (*(int*)(*(int*)(unaff_EBP + -0x5c) + uVar9 * 0x10) == 0))))
		//{
		//	uVar9 = 1;
		//}
		//else {
		//	uVar9 = 0;
		//}
		//if (uVar9 != (uVar8 >> 8 & 0x1ff)) {

		inst->OP = 26;
		inst->A = uVar9;
		inst->C = (uVar8 >> 8 & 0x1ff);
	}

	// OP_TEST 26 : A C 
	void d5702(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4 uVar2;
		byte bVar3;
		char cVar4;
		uint uVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		//int unaff_EBP;
		uint uVar9;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar9 = param_1 + -8 >> 2;
		param_2 = (param_2 >> 9 | param_2 << 0x17) ^ (param_2 << 1 | (uint)((int)param_2 < 0)) ^ param_2;
		uVar5 = uVar9 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar5;
		sVar7 = (sbyte)uVar5;
		bVar8 = ((byte)uVar9 ^ 0xf9) & 0x1e | 1;
		param_2 = param_2 - (param_2 << (((byte)(0xe << sVar7) | (byte)(0xe >> 0x20 - sVar7)) & 0x1e | 1))
			;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		param_2 = (param_2 << bVar8 | param_2 >> 0x20 - bVar8) ^
			(param_2 >> bVar3 | param_2 << 0x20 - bVar3) ^ param_2;
		uVar5 = ~(param_2 >> 0x11 | param_2 << 0xf);
		uVar5 = uVar5 >> 0x16 ^ uVar5;
		uVar9 = uVar5 * 0x1b9b8149;
		uVar9 = (uVar9 >> 0xc | uVar5 * 0x14900000) ^ (uVar5 * 0x37370292 | (uint)((int)uVar9 < 0)) ^
			uVar9;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar5 = ~((uVar9 >> 0xd | uVar9 << 0x13) ^ (uVar9 >> 7 | uVar9 << 0x19) ^ uVar9) + 0xc9297fc4;
		uVar9 = (uVar5 >> 4 | uVar5 * 0x10000000) + 0xf00216b4;
		uVar9 = uVar9 >> (((byte)(0x1d << bVar3) | (byte)(0x1d >> 0x20 - bVar3)) & 0x1e | 1) ^ uVar9;
		uVar5 = uVar9 >> 0x12 & 0xff;
		//iVar1 = *(int*)(*(int*)(unaff_EBP + -0x5c) + 0xc + uVar5 * 0x10);
		//if ((iVar1 == 0) || ((iVar1 == 1 && (*(int*)(*(int*)(unaff_EBP + -0x5c) + uVar5 * 0x10) == 0))))
		//{
		//	pcVar6 = &DAT_00000001;
		//}
		//else {
		//	pcVar6 = (char*)0x0;
		//}
		//if (pcVar6 != (char*)(uVar9 >> 9 & 0x1ff)) {

		inst->OP = 26;
		inst->A = uVar5;
		inst->C = uVar9 >> 9 & 0x1ff;
	}

	// OP_TESTSET 27 : A B C
	void d453c(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4 uVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		int iVar7;
		undefined8* puVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		uVar10 = (param_2 ^ 0x53663a01) << 6;
		uVar9 = (param_2 ^ 0x53663a01) >> 0x1a | uVar10;
		*(uint*)(unaff_EBP + -0x44) = uVar9;
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar7 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar7;
		bVar5 = (byte)iVar7 & 0x1e | 1;
		uVar10 = (uVar9 << 0x17 | uVar10 >> 9) ^
			(*(uint*)(unaff_EBP + -0x44) >> 0x11 | *(uint*)(unaff_EBP + -0x44) << 0xf) ^
			*(uint*)(unaff_EBP + -0x44);
		*(uint*)(unaff_EBP + -0x1c) = uVar10;
		bVar6 = ((byte)(0xf >> bVar5) | (byte)(0xf << 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = ((byte)(0xd >> bVar5) | (byte)(0xd << 0x20 - bVar5)) & 0x1e | 1;
		uVar10 = (uVar10 >> bVar6 | uVar10 << 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x1c) >> bVar5 | *(uint*)(unaff_EBP + -0x1c) << 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -0x1c);
		cVar3 = (char)*(undefined4*)(unaff_EBP + -4);
		bVar5 = cVar3 + 6U & 0x1e | 1;
		bVar6 = cVar3 - 5U & 0x1e | 1;
		uVar10 = (uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^
			uVar10;
		cVar3 = (char)*(undefined4*)(unaff_EBP + -4);
		bVar5 = cVar3 + 0xbU & 0x1e | 1;
		bVar6 = cVar3 - 3U & 0x1e | 1;
		uVar10 = (uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6) ^
			uVar10;
		bVar5 = 10U - cVar3 & 0x1e | 1;
		bVar6 = -cVar3 - 6U & 0x1e | 1;
		uVar10 = ((uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^ (uVar10 << bVar6 | uVar10 >> 0x20 - bVar6)
			^ uVar10) * 0x5d730ca1;
		bVar5 = cVar3 + 0xfU & 0x1e | 1;
		iVar7 = *(int*)(unaff_EBP + -0x5c);
		bVar6 = cVar3 - 10U & 0x1e | 1;
		uVar9 = ((uVar10 >> bVar5 | uVar10 << 0x20 - bVar5) ^ (uVar10 >> bVar6 | uVar10 << 0x20 - bVar6) ^
			uVar10) * 0x3d6ae8f7;
		//puVar8 = (undefined8*)((uVar9 >> 9 & 0x1ff) * 0x10 + iVar7);
		uVar10 = uVar9 >> 0x13 & 0xff;
		//if ((*(int*)((int)puVar8 + 0xc) == 0) ||
		//	((*(int*)((int)puVar8 + 0xc) == 1 && (*(int*)puVar8 == 0)))) {
		//	pcVar4 = &DAT_00000001;
		//}
		//else {
		//	pcVar4 = (char*)0x0;
		//}
		//if (pcVar4 != (char*)(uVar9 & 0x1ff)) {

		inst->OP = 27;
		inst->A = uVar10;
		inst->B = uVar9 >> 9 & 0x1ff;
		inst->C = uVar9 & 0x1ff;
	}

	// OP_TESTSET 27 : A B C
	void d716d(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4 uVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		byte bVar7;
		undefined8* puVar8;
		uint uVar9;
		//int unaff_EBP;
		uint uVar10;
		int iVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar11 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar11;
		uVar9 = (param_2 - iVar11) + 0xf984c08d;
		bVar7 = (byte)iVar11;
		bVar5 = (bVar7 ^ 8) & 0x1e | 1;
		uVar9 = ((uVar9 >> 0x1e | uVar9 * 4) ^ (uVar9 >> 0x1c | uVar9 * 0x10) ^ uVar9) +
			iVar11 * -0x10f3e598;
		uVar9 = uVar9 >> bVar5 | uVar9 << 0x20 - bVar5;
		bVar5 = (bVar7 ^ 0xfd) & 0x1e | 1;
		uVar9 = (uVar9 >> 0x1e | uVar9 << 2) ^ (uVar9 >> 0x12 | uVar9 << 0xe) ^ uVar9;
		uVar9 = ~((uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) + 0xa4843d53 + iVar11);
		uVar9 = (uVar9 >> 0xe | uVar9 << 0x12) ^ (uVar9 >> 0xd | uVar9 << 0x13) ^ uVar9;
		uVar9 = uVar9 << 0x16 | uVar9 >> 10;
		bVar5 = -bVar7 - 4 & 0x1e | 1;
		bVar6 = 3 - bVar7 & 0x1e | 1;
		uVar9 = (uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^ (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^
			uVar9;
		bVar5 = (bVar7 ^ 0xe) & 0x1e | 1;
		bVar7 = (byte) * (uint*)(unaff_EBP + -4);
		bVar6 = (bVar7 ^ 6) & 0x1e | 1;
		iVar11 = ((uVar9 << bVar5 | uVar9 >> 0x20 - bVar5) ^ (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^
			uVar9) + 0x9088fe03;
		uVar9 = iVar11 - (iVar11 << (bVar7 * '\x0e' & 0x1e | 1));
		*(uint*)(unaff_EBP + -4) = *(uint*)(unaff_EBP + -4) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar7 = ((byte)(0x1b >> bVar7) | (byte)(0x1b << 0x20 - bVar7)) & 0x1e | 1;
		iVar11 = *(int*)(unaff_EBP + -0x5c);
		uVar9 = ((uVar9 * 0x40 | uVar9 >> 0x1a) ^ (uVar9 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f) ^ uVar9)
			+ 0x6ebe869d;
		uVar10 = uVar9 << bVar7 | uVar9 >> 0x20 - bVar7;
		puVar8 = (undefined8*)((uVar10 >> 9 & 0x1ff) * 0x10 + iVar11);
		uVar9 = uVar10 >> 0x14 & 0xff;
		//if ((*(int*)((int)puVar8 + 0xc) == 0) ||
		//	((*(int*)((int)puVar8 + 0xc) == 1 && (*(int*)puVar8 == 0)))) {
		//	pcVar4 = &DAT_00000001;
		//}
		//else {
		//	pcVar4 = (char*)0x0;
		//}
		//if (pcVar4 != (char*)(uVar10 & 0x1ff)) {

		inst->OP = 27;
		inst->A = uVar9;
		inst->B = (uVar10 >> 9 & 0x1ff);
		inst->C = uVar10 & 0x1ff;
	}

	// OP_TESTSET 27 : A B C
	void d77ff(instr* inst, uint param_1, uint param_2) {

		undefined4 uVar1;
		char cVar2;
		uint uVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		undefined8* puVar7;
		char* pcVar8;
		uint uVar9;
		undefined8* puVar10;
		//int unaff_EBP;
		int iVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		iVar11 = param_1 + -8 >> 2;
		bVar6 = (byte)iVar11;
		bVar4 = bVar6 & 0x1e | 1;
		bVar5 = (bVar6 ^ 8) & 0x1e | 1;
		uVar9 = ((~((param_2 << 0xf | param_2 >> 0x11) ^
			(*(uint*)(unaff_EBP + -0x44) >> 5 | *(uint*)(unaff_EBP + -0x44) << 0x1b) ^
			*(uint*)(unaff_EBP + -0x44)) ^ iVar11 * 0x45e603dc) -
			(0x4d9bc262U >> bVar4 | 0x4d9bc262 << 0x20 - bVar4)) * -0x7fff ^ 0x5a05a631;
		uVar9 = uVar9 >> bVar5 | uVar9 << 0x20 - bVar5;
		bVar4 = bVar6 * -10 & 0x1e | 1;
		uVar9 = ((uVar9 << 0x11 | uVar9 >> 0xf) * 0x36b1b3cf + -0x72ba6e30) * -0x7ffffff;
		*(uint*)(unaff_EBP + -0xc) = uVar9 >> bVar4 | uVar9 << 0x20 - bVar4;
		bVar6 = bVar6 * '\x06' & 0x1e | 1;
		uVar9 = *(uint*)(unaff_EBP + -0xc) ^ (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^ uVar9;
		//puVar7 = (undefined8*)((uVar9 & 0x1ff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar10 = (undefined8*)((uVar9 >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//if ((*(int*)((int)puVar7 + 0xc) == 0) ||
		//	((*(int*)((int)puVar7 + 0xc) == 1 && (*(int*)puVar7 == 0)))) {
		//	uVar3 = 1;
		//}
		//else {
		//	uVar3 = 0;
		//}
		//if (uVar3 != uVar9 >> 0x17) {

		inst->OP = 27;
		inst->A = (uVar9 >> 9 & 0xff);
		inst->B = uVar9 & 0x1ff;
		inst->C = uVar9 >> 0x17;
	}

	// OP_TESTSET 27 : A B C
	void ddc9e(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		int iVar2;
		char cVar3;
		undefined4 uVar4;
		uint uVar5;
		uint uVar6;
		byte bVar7;
		byte bVar8;
		sbyte sVar9;
		undefined8* puVar10;
		char* pcVar11;
		//int unaff_EBP;
		uint uVar12;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar5 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar5;
		bVar7 = ((byte)uVar5 ^ 4) & 0x1e | 1;
		uVar12 = uVar5 & 0x1e | 1;
		bVar8 = ((byte)uVar5 ^ 6) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar12;
		sVar9 = (sbyte)uVar12;
		uVar5 = ((param_2 << bVar7 | param_2 >> 0x20 - bVar7) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar8 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar8) ^
			(0x3108a5eb << sVar9 | 0x3108a5ebU >> 0x20 - sVar9) ^ *(uint*)(unaff_EBP + -0x44)) *
			0x100001 + 0xad46fdf8;
		uVar5 = ~(uVar5 << bVar8 ^ uVar5);
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar5 = (uVar5 << (((byte)(4 << bVar7) | (byte)(4 >> 0x20 - bVar7)) & 0x1e | 1)) + uVar5;
		bVar8 = (byte) * (uint*)(unaff_EBP + -4);
		uVar5 = (uVar5 >> (~bVar8 & 0x1e | 1) ^ uVar5) - (*(uint*)(unaff_EBP + -4) ^ 0x44d1fcf7);
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar5 = uVar5 >> 0x1d | uVar5 * 8;
		uVar5 = uVar5 >> (((byte)(0x1a << bVar7) | (byte)(0x1a >> 0x20 - bVar7)) & 0x1e | 1) ^ uVar5;
		uVar5 = ~(uVar5 << 4 | uVar5 >> 0x1c);
		uVar5 = uVar5 << (bVar8 + 5 & 0x1e | 1) ^ uVar5;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar8 = ((byte)(0x1c << bVar7) | (byte)(0x1c >> 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar7 = ((byte)(9 << bVar7) | (byte)(9 >> 0x20 - bVar7)) & 0x1e | 1;
		uVar5 = (uVar5 << bVar8 | uVar5 >> 0x20 - bVar8) ^ (uVar5 >> bVar7 | uVar5 << 0x20 - bVar7) ^
			uVar5;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar5 = (uVar5 >> 2 | uVar5 << 0x1e) * 0x43687f5f;
		uVar5 = uVar5 << (((byte)(0x13 << bVar7) | (byte)(0x13 >> 0x20 - bVar7)) & 0x1e | 1) ^ uVar5;
		puVar10 = (undefined8*)((uVar5 >> 0x16 & 0x1ff) * 0x10 + iVar1);
		uVar12 = uVar5 >> 9 & 0xff;
		//if ((*(int*)((int)puVar10 + 0xc) == 0) ||
		//	((*(int*)((int)puVar10 + 0xc) == 1 && (*(int*)puVar10 == 0)))) {
		//	uVar6 = 1;
		//}
		//else {
		//	uVar6 = 0;
		//}
		//if (uVar6 != (uVar5 & 0x1ff)) {

		inst->OP = 27;
		inst->A = uVar12;
		inst->B = (uVar5 >> 0x16 & 0x1ff);
		inst->C = uVar5 & 0x1ff;
	}

	// OP_FORLOOP 31 : A sBx 
	void d08a0(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		bool bVar2;
		uint* puVar3;
		char cVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		uint uVar8;
		//int unaff_EBP;
		double* pdVar9;
		double dVar10;
		double in_XMM3_Qa;

		uVar7 = ((param_2 << 0x19 | param_2 >> 7) ^
			(*(uint*)(unaff_EBP + -0x44) << 0x13 | *(uint*)(unaff_EBP + -0x44) >> 0xd) ^
			*(uint*)(unaff_EBP + -0x44)) * 0x30760377;
		bVar6 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar5 = bVar6 + 8 & 0x1e | 1;
		uVar8 = uVar7 << bVar5 | uVar7 >> 0x20 - bVar5;
		uVar8 = (uVar8 >> 0xb | uVar8 << 0x15) ^ (uVar8 >> 2 | uVar8 << 0x1e) ^ uVar8;
		uVar7 = uVar8 << 5;
		uVar8 = (uVar7 | uVar8 >> 0x1b) << 0xc;
		uVar7 = uVar8 | uVar7 >> 0x14;
		uVar7 = ((uVar8 >> 0xf | uVar7 << 0x11) ^ (uVar7 << 8 | uVar8 >> 0x18) ^ uVar7) + 0xc4b6ed18;
		uVar7 = ~((uVar7 * 0x400000 | uVar7 >> 10) ^ (uVar7 >> 0x15 | uVar7 * 0x800) ^ uVar7);
		bVar5 = bVar6 & 0x1e | 1;
		bVar6 = -bVar6 - 10 & 0x1e | 1;
		uVar7 = uVar7 << 6 ^ uVar7;
		bVar5 = ((byte)(0xe >> bVar5) | (byte)(0xe << 0x20 - bVar5)) & 0x1e | 1;
		uVar7 = uVar7 >> bVar6 | uVar7 << 0x20 - bVar6;
		uVar7 = uVar7 >> bVar5 | uVar7 << 0x20 - bVar5;
		//pdVar9 = (double*)((uVar7 >> 0x18) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//dVar10 = pdVar9[4] + *pdVar9;

		inst->OP = 31;
		inst->A = (uVar7 >> 0x18);
		inst->sBx = (uVar7 & 0x3ffff);
	}

	// OP_FORLOOP 31 : A sBx 
	void d4453(instr* inst, uint param_1, uint param_2) {

		bool bVar1;
		char cVar2;
		uint uVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		int iVar8;
		//int unaff_EBP;
		double* pdVar9;
		double dVar10;
		double in_XMM3_Qa;

		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		bVar5 = -(byte)uVar7 - 0xe & 0x1e | 1;
		bVar6 = (byte)uVar7 & 0x1e | 1;
		uVar3 = (*(int*)(unaff_EBP + -0x44) - (uVar7 ^ 0x6d99cfba)) * 0x861 + 0xadd79f4;
		*(uint*)(unaff_EBP + -4) =
			(uVar3 >> bVar5 | uVar3 << 0x20 - bVar5) * 0x6ce4ac8d + uVar7 * 0x78dae54d;
		bVar5 = ((byte)(0xd >> bVar6) | (byte)(0xd << 0x20 - bVar6)) & 0x1e | 1;
		uVar3 = (*(int*)(unaff_EBP + -4) -
			(*(int*)(unaff_EBP + -4) << (((byte)(1 >> bVar6) | (byte)(1 << 0x20 - bVar6)) & 0x1e | 1)
				)) + (0x68bd8a2eU >> bVar6 | 0x68bd8a2e << 0x20 - bVar6);
		iVar8 = (uVar3 >> bVar5 | uVar3 << 0x20 - bVar5) -
			(0x192b9a1f << bVar6 | 0x192b9a1fU >> 0x20 - bVar6);
		pcVar4 = (char*)((iVar8 << (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xe) & 0x1e | 1)) + iVar8)
			;
		//pdVar9 = (double*)(((uint)pcVar4 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//dVar10 = pdVar9[4] + *pdVar9;
		//if (pdVar9[4] <= in_XMM3_Qa) {
		//	bVar1 = dVar10 < pdVar9[2];
		//}
		//else {
		//	bVar1 = pdVar9[2] < dVar10;
		//}
		//if (!bVar1) {
		//	pcVar4 = (char*)(((uint)pcVar4 >> 8 & 0x3ffff)

		inst->OP = 31;
		inst->A = (uint)pcVar4 & 0xff;
		inst->sBx = (uint)pcVar4 >> 8 & 0x3ffff;
	}

	// OP_FORLOOP 31 : A sBx 
	void d6d36(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		bool bVar2;
		uint* puVar3;
		char cVar4;
		uint uVar5;
		byte bVar6;
		sbyte sVar7;
		byte bVar8;
		//int unaff_EBP;
		uint uVar9;
		double* pdVar10;
		double dVar11;
		double in_XMM3_Qa;

		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar5 = (uint)~(param_2 * 0x53aa5493) >> 8 | ~(param_2 * 0x53aa5493) << 0x18;
		bVar6 = (char)uVar9 - 10U & 0x1e | 1;
		uVar9 = uVar9 & 0x1e | 1;
		sVar7 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -4) = uVar9;
		bVar8 = ((byte)(0xd << sVar7) | (byte)(0xd >> 0x20 - sVar7)) & 0x1e | 1;
		uVar5 = ((uVar5 << bVar6 | uVar5 >> 0x20 - bVar6) * 0x6094ef1d + -0x4044058c) * -0x3f;
		bVar6 = ((byte)(0xc << sVar7) | (byte)(0xc >> 0x20 - sVar7)) & 0x1e | 1;
		uVar5 = (uVar5 >> bVar6 | uVar5 << 0x20 - bVar6) ^ (uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^
			uVar5;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(0x16 << bVar6) | (byte)(0x16 >> 0x20 - bVar6)) & 0x1e | 1;
		uVar5 = (uVar5 >> bVar6 | uVar5 << 0x20 - bVar6) ^ (uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^
			uVar5;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4);
		uVar5 = uVar5 << 5 | uVar5 >> 0x1b;
		bVar8 = ((byte)(0xf >> (bVar6 & 0x1f)) | (byte)(0xf << 0x20 - (bVar6 & 0x1f))) & 0x1e | 1;
		uVar5 = (uVar5 << (bVar6 & 0x1f)) + uVar5;
		uVar5 = (((uVar5 >> 0x1a | uVar5 * 0x40) ^ (uVar5 * 0x400000 | uVar5 >> 10) ^ uVar5) -
			(0x37dcd427 << (bVar6 & 0x1f) | 0x37dcd427U >> 0x20 - (bVar6 & 0x1f))) * 0x7305b147;
		bVar6 = (byte) * (int*)(unaff_EBP + -0xc);
		uVar5 = (uVar5 << bVar8 | uVar5 >> 0x20 - bVar8) ^ 0x78027a84U - *(int*)(unaff_EBP + -0xc);
		bVar8 = (bVar6 ^ 10) & 0x1e | 1;
		bVar6 = (bVar6 ^ 8) & 0x1e | 1;
		uVar5 = ((uVar5 >> bVar8 | uVar5 << 0x20 - bVar8) ^ (uVar5 >> bVar6 | uVar5 << 0x20 - bVar6) ^
			uVar5) * 0x618d7b6f;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(0x14 >> bVar6) | (byte)(0x14 << 0x20 - bVar6)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar5 << bVar6 | uVar5 >> 0x20 - bVar6;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar6 = ((byte)(6 >> bVar6) | (byte)(6 << 0x20 - bVar6)) & 0x1e | 1;
		uVar5 = *(uint*)(unaff_EBP + -0xc) ^ (uVar5 >> bVar6 | uVar5 << 0x20 - bVar6) ^ uVar5;
		//pdVar10 = (double*)((uVar5 >> 0x16 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//dVar11 = pdVar10[4] + *pdVar10;

		inst->OP = 31;
		inst->A = (uVar5 >> 0x16 & 0xff);
		inst->sBx = (uVar5 & 0x3ffff);
	}

	// OP_FORLOOP 31 : A sBx 
	void dd7d9(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		bool bVar2;
		code* pcVar3;
		uint* puVar4;
		char cVar5;
		byte bVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		char unaff_BH;
		//int unaff_EBP;
		double* pdVar10;
		uint uVar11;
		double dVar12;
		double in_XMM3_Qa;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar8 = (byte)uVar11;
		bVar6 = bVar8 & 0x1e | 1;
		bVar7 = bVar8 - 2 & 0x1e | 1;
		uVar9 = ~((0x2587c6f5U >> bVar6 | 0x2587c6f5 << 0x20 - bVar6) +
			(*(uint*)(unaff_EBP + -0x44) >> 0xd | *(uint*)(unaff_EBP + -0x44) << 0x13) ^ uVar11 ^
			0x24df546f);
		uVar9 = uVar9 >> 0x10 ^ uVar9;
		uVar9 = uVar9 << bVar7 | uVar9 >> 0x20 - bVar7;
		uVar9 = uVar9 << (bVar8 - 7 & 0x1e | 1) ^ uVar9;
		bVar6 = 0xd - bVar8 & 0x1e | 1;
		uVar9 = ((uVar9 << (6 - bVar8 & 0x1e | 1)) + uVar9) * 0x4f18cfcb + uVar11 * -0x27a7732 ^ 0x80ee6e6
			;
		bVar8 = 4 - bVar8 & 0x1e | 1;
		uVar9 = (uVar9 >> bVar6 | uVar9 << 0x20 - bVar6) ^ (uVar9 << bVar8 | uVar9 >> 0x20 - bVar8) ^
			uVar9;
		uVar9 = (uVar9 >> 0x11 | uVar9 << 0xf) * 0x4000001 + 0x2cbbad72;
		uVar9 = ~((uVar9 * 0x800000 | uVar9 >> 9) ^ (uVar9 * 0x4000 | uVar9 >> 0x12) ^ uVar9) -
			(uVar11 ^ 0x3f3a77f);
		uVar9 = (uVar9 * 0x100 | uVar9 >> 0x18) ^ (uVar9 * 4 | uVar9 >> 0x1e) ^ uVar9;
		//pdVar10 = (double*)((uVar9 >> 0x18) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 31;
		inst->A = (uVar9 >> 0x18);
		inst->sBx = (uVar9 & 0x3ffff);
	}

	// OP_FORPREP 32 : A sBx 
	void d5b47(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		double* pdVar2;
		char cVar3;
		uint uVar4;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		//int unaff_EBP;
		undefined8* puVar10;
		uint uVar11;
		uint* puVar5;

		uVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar4 = uVar11 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar4;
		sVar7 = (sbyte)uVar4;
		bVar9 = (byte)uVar11;
		uVar4 = *(uint*)(unaff_EBP + -0x44) >>
			(((byte)(6 << sVar7) | (byte)(6 >> 0x20 - sVar7)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar11 = uVar4 * 0x201;
		bVar8 = bVar9 * -0xd & 0x1e | 1;
		uVar11 = (uVar4 * 0x4020000 | uVar11 >> 0xf) ^ (uVar11 >> 6 | uVar4 * 0x4000000) ^ uVar11;
		uVar4 = ((uVar11 << ((bVar9 ^ 0xf9) & 0x1e | 1)) + uVar11) * 0x6aabd057 + 0xd3844d40;
		uVar11 = (uVar4 >> bVar8 | uVar4 << 0x20 - bVar8) ^ 0x7a720f0a;
		uVar4 = uVar11 * 0x41;
		uVar4 = (uVar11 * 0x20800 | uVar4 >> 0x15) ^ (uVar4 >> 3 | uVar11 * 0x20000000) ^ uVar4;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar9 = bVar8 & 0x1f;
		bVar9 = ((byte)(0x1d >> bVar9) | (byte)(0x1d << 0x20 - bVar9)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar4 >> bVar9 | uVar4 << 0x20 - bVar9;
		bVar8 = bVar8 & 0x1f;
		bVar9 = ((byte)(2 >> bVar8) | (byte)(2 << 0x20 - bVar8)) & 0x1e | 1;
		uVar11 = *(uint*)(unaff_EBP + -0xc) ^ (uVar4 << bVar9 | uVar4 >> 0x20 - bVar9) ^ uVar4 ^
			0x162985be;
		//puVar10 = (undefined8*)((uVar11 >> 3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 32;
		inst->A = (uVar11 >> 3 & 0xff);
		inst->sBx = uVar11 >> 0xb & 0x3ffff;
	}

	// OP_FORPREP 32 : A sBx 
	void db1bf(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		uint uVar2;
		int iVar3;
		byte bVar4;
		char cVar5;
		char* pcVar6;
		sbyte sVar7;
		byte bVar8;
		byte bVar9;
		uint* puVar10;
		uint* puVar11;
		//int unaff_EBP;
		uint uVar12;
		uint uVar13;
		double* pdVar14;

		uVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar4 = (byte)uVar12;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		param_2 = (param_2 << (bVar4 * -0xe & 0x1e | 1)) + param_2;
		uVar12 = uVar12 & 0x1e | 1;
		sVar7 = (sbyte)uVar12;
		*(uint*)(unaff_EBP + -4) = uVar12;
		bVar8 = ((byte)(5 >> sVar7) | (byte)(5 << 0x20 - sVar7)) & 0x1e | 1;
		bVar9 = (bVar4 ^ 6) & 0x1e | 1;
		uVar12 = (param_2 << ((bVar4 ^ 0xf9) & 0x1e | 1)) + param_2;
		uVar12 = (uVar12 >> 0x1b | uVar12 * 0x20) ^ 0x60bbe236;
		uVar12 = uVar12 << bVar8 | uVar12 >> 0x20 - bVar8;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar13 = ~((uVar12 << bVar9 | uVar12 >> 0x20 - bVar9) + *(int*)(unaff_EBP + -0xc) * -0xf3420e1);
		uVar13 = uVar13 >> (((byte)(3 << bVar4) | (byte)(3 >> 0x20 - bVar4)) & 0x1e | 1) ^ uVar13;
		uVar13 = uVar13 >> ((char)*(int*)(unaff_EBP + -0xc) * '\x02' & 0x1eU | 1) ^ uVar13;
		uVar12 = uVar13 >> 4;
		uVar13 = uVar12 | uVar13 << 0x1c;
		uVar13 = (uVar13 >> 0x19 | uVar12 << 7) ^ (uVar12 << 5 | uVar13 >> 0x1b) ^ uVar13;
		//*(uint*)(unaff_EBP + -0xc) = uVar13;
		//pcVar6 = *(char**)(*(int*)(unaff_EBP + -0xa8) + 0x1c);
		//pdVar14 = (double*)((uVar13 >> 0x18) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 32;
		inst->A = (uVar13 >> 0x18);
		inst->sBx = (uVar13 & 0x3ffff);
	}

	// OP_FORPREP 32 : A sBx 
	void df908(instr* inst, uint param_1, uint param_2) {

		undefined8* puVar1;
		uint uVar2;
		char cVar3;
		char* pcVar4;
		byte bVar5;
		byte bVar6;
		uint* puVar7;
		uint* puVar8;
		uint uVar9;
		uint uVar10;
		//int unaff_EBP;
		int iVar11;
		double* pdVar12;

		*(uint*)(unaff_EBP + -0x44) = ~param_2;
		uVar9 = (~param_2 >> 0x1b ^ *(uint*)(unaff_EBP + -0x44)) << 0x1a |
			*(uint*)(unaff_EBP + -0x44) >> 6;
		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar3 = (char)iVar11;
		*(int*)(unaff_EBP + -0xc) = iVar11;
		uVar9 = (uVar9 >> (-cVar3 - 8U & 0x1e | 1) ^ uVar9) * 0x76e2aa6f;
		uVar9 = uVar9 >> 10 ^ uVar9;
		uVar9 = (uVar9 << 0x1e | uVar9 >> 2) ^ (uVar9 << 0x1a | uVar9 >> 6) ^ uVar9;
		uVar9 = (uVar9 << 10 | uVar9 >> 0x16) + 0xa6a83d9a;
		bVar5 = cVar3 * -7 & 0x1eU | 1;
		uVar9 = (uVar9 >> 0x1d | uVar9 * 8) ^ (uVar9 * 4 | uVar9 >> 0x1e) ^ uVar9;
		bVar6 = (char)*(undefined4*)(unaff_EBP + -0xc) * '\x02' & 0x1eU | 1;
		uVar9 = (uVar9 >> bVar5 | uVar9 << 0x20 - bVar5) ^ (uVar9 << bVar6 | uVar9 >> 0x20 - bVar6) ^
			uVar9 ^ 0x25ba1456;
		uVar9 = (uVar9 << 10 | uVar9 >> 0x16) ^ (uVar9 << 9 | uVar9 >> 0x17) ^ uVar9;
		uVar10 = (uVar9 << 0xc | uVar9 >> 0x14) ^ 0x45135f3f;
		uVar9 = *(uint*)(unaff_EBP + -0x50);
		uVar10 = uVar10 >> ((char)*(undefined4*)(unaff_EBP + -0xc) - 0xcU & 0x1e | 1) ^ uVar10;
		//*(uint*)(unaff_EBP + -0xc) = uVar10;
		//pdVar12 = (double*)((uVar10 >> 3 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));

		inst->OP = 32;
		inst->A = (uVar10 >> 3 & 0xff);
		inst->sBx = (uVar10 >> 0xb & 0x3ffff);
	}

	// OP_TFORLOOP 33 : A C 
	void d2841(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4* puVar2;
		int iVar3;
		uint* puVar4;
		char cVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		undefined8* puVar10;
		char* pcVar11;
		uint uVar12;
		//int unaff_EBP;
		uint uVar13;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar13 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar13;
		uVar9 = uVar13 & 0x1e | 1;
		sVar6 = (sbyte)uVar9;
		*(uint*)(unaff_EBP + -0x1c) = uVar9;
		bVar7 = ((byte)(1 << sVar6) | (byte)(1 >> 0x20 - sVar6)) & 0x1e | 1;
		cVar5 = (char)uVar13;
		bVar8 = -cVar5 - 8U & 0x1e | 1;
		uVar9 = param_2 << bVar8 | param_2 >> 0x20 - bVar8;
		uVar9 = uVar9 << bVar7 | uVar9 >> 0x20 - bVar7;
		*(uint*)(unaff_EBP + -0x44) = uVar9;
		bVar7 = 0xfU - cVar5 & 0x1e | 1;
		bVar8 = 5U - cVar5 & 0x1e | 1;
		uVar12 = (uVar9 >> bVar7 | uVar9 << 0x20 - bVar7) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar8 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar8) ^
			uVar13 + 0x65cebbf8 ^ *(uint*)(unaff_EBP + -0x44);
		uVar9 = uVar12 * -0x1fffffff;
		uVar9 = (uVar12 * 0x20000 | uVar9 >> 0xf) ^ (uVar9 >> 0xb | uVar12 * 0x200000) ^ uVar9;
		uVar9 = ((uVar9 >> 0x18 | uVar9 << 8) ^ (uVar9 << 6 | uVar9 >> 0x1a) ^ uVar9) +
			(uVar13 ^ 0x1fe47013);
		uVar9 = (uVar9 * 0x8000000 | uVar9 >> 5) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9;
		uVar9 = uVar9 >> (cVar5 * -10 & 0x1eU | 1) ^ uVar9;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar8 = ((byte)(0xf >> bVar7) | (byte)(0xf << 0x20 - bVar7)) & 0x1e | 1;
		bVar7 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar7 = ((byte)(1 >> bVar7) | (byte)(1 << 0x20 - bVar7)) & 0x1e | 1;
		uVar9 = (uVar9 << bVar8 | uVar9 >> 0x20 - bVar8) ^ (uVar9 << bVar7 | uVar9 >> 0x20 - bVar7) ^
			uVar9;
		uVar12 = uVar9 * 0x488b7d61;
		uVar12 = (uVar9 * 0x61000000 | uVar12 >> 8) ^ (uVar12 >> 0xd | uVar9 * -0x14f80000) ^ uVar12;
		uVar12 = (uVar12 << (((byte) * (undefined4*)(unaff_EBP + -4) ^ 0xf7) & 0x1e | 1)) + uVar12;
		uVar12 = ~((uVar12 >> 0x13 | uVar12 * 0x2000) ^ (uVar12 * 0x10 | uVar12 >> 0x1c) ^ uVar12);
		uVar12 = (uVar12 << 0x15 | uVar12 >> 0xb) ^ (uVar12 >> 0x10 | uVar12 << 0x10) ^ uVar12;
		uVar9 = uVar12 << 7;
		uVar12 = uVar9 | uVar12 >> 0x19;
		uVar12 = (uVar12 << 0x18 | uVar9 >> 8) ^ (uVar12 << 0xf | uVar9 >> 0x11) ^ uVar12;
		uVar9 = uVar12 >> 9 & 0xff;
		//puVar10 = (undefined8*)(uVar9 * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar10[10] = puVar10[4];
		//*(undefined4*)(puVar10 + 0xb) = *(undefined4*)(puVar10 + 5);
		//*(undefined4*)((int)puVar10 + 0x5c) = *(undefined4*)((int)puVar10 + 0x2c);
		//puVar10[8] = puVar10[2];
		//*(undefined4*)(puVar10 + 9) = *(undefined4*)(puVar10 + 3);
		//*(undefined4*)((int)puVar10 + 0x4c) = *(undefined4*)((int)puVar10 + 0x1c);
		//puVar10[6] = *puVar10;
		//*(undefined4*)(puVar10 + 7) = *(undefined4*)(puVar10 + 1);
		//iVar1 = *(int*)(unaff_EBP + -0xa8);
		//*(uint*)((int)puVar10 + 0x3c) = uVar12 >> 0x12 & 0x1ff;

		inst->OP = 33;
		inst->A = uVar9;
		inst->C = uVar12 >> 0x12 & 0x1ff;
	}

	// OP_TFORLOOP 33 : A C 
	void d8fd9(instr* inst, uint param_1, uint param_2) {

		undefined4* puVar1;
		uint* puVar2;
		char cVar3;
		byte bVar4;
		byte bVar5;
		byte bVar6;
		uint uVar7;
		undefined8* puVar8;
		char* pcVar9;
		//int unaff_EBP;
		uint uVar10;
		int iVar11;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		iVar11 = param_1 + -8 >> 2;
		*(int*)(unaff_EBP + -4) = iVar11;
		uVar10 = (param_2 << 0x12 ^ param_2) * 0x4af2eba9;
		uVar10 = (param_2 * 0x40000000 | uVar10 >> 2) ^ (uVar10 >> 0x11 | param_2 * 0x75d48000) ^ uVar10;
		bVar6 = (byte)iVar11;
		bVar4 = (bVar6 ^ 0xc) & 0x1e | 1;
		bVar5 = (bVar6 ^ 0xfb) & 0x1e | 1;
		uVar10 = ~((uVar10 >> bVar4 | uVar10 << 0x20 - bVar4) ^ (uVar10 >> bVar5 | uVar10 << 0x20 - bVar5)
			^ uVar10);
		uVar7 = uVar10 + 0x10b11954 + (uVar10 << (bVar6 * '\x04' & 0x1e | 1));
		uVar7 = (uVar7 >> 0x1a | uVar7 * 0x40) ^ (uVar7 >> 0x11 | uVar7 * 0x8000) ^ uVar7;
		uVar7 = uVar7 << (bVar6 * -9 & 0x1e | 1) ^ uVar7;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1e | 1;
		uVar10 = uVar7 * -0x3ffff;
		bVar6 = ((byte)(4 >> bVar6) | (byte)(4 << 0x20 - bVar6)) & 0x1e | 1;
		uVar10 = ((uVar10 >> 8 | uVar7 * 0x1000000) ^ (uVar7 * -0x1ffff8 | uVar10 >> 0x1d) ^ uVar10) *
			-0x582736ef;
		uVar7 = uVar10 << bVar6 | uVar10 >> 0x20 - bVar6;
		uVar10 = uVar7 >> 10 & 0xff;
		//puVar8 = (undefined8*)(uVar10 * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar8[10] = puVar8[4];
		//*(undefined4*)(puVar8 + 0xb) = *(undefined4*)(puVar8 + 5);
		//*(uint*)((int)puVar8 + 0x5c) = uVar7 >> 0x12 & 0x1ff;

		inst->OP = 33;
		inst->A = uVar10;
		inst->C = uVar7 >> 0x12 & 0x1ff;
	}

	// OP_TFORLOOP 33 : A C 
	void d9123(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4* puVar2;
		uint* puVar3;
		undefined4 uVar4;
		byte bVar5;
		char cVar6;
		uint uVar7;
		byte bVar8;
		byte bVar9;
		undefined8* puVar10;
		char* pcVar11;
		//int unaff_EBP;
		uint uVar12;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar12 = param_1 + -8 >> 2;
		bVar5 = (byte)uVar12;
		uVar7 = (param_2 << (-bVar5 - 3 & 0x1e | 1)) + param_2;
		bVar8 = (bVar5 ^ 0xc) & 0x1e | 1;
		uVar7 = uVar7 * 0x1000000 | (uVar7 * 0x20000000 ^ uVar7) >> 8;
		bVar9 = (bVar5 ^ 0xf3) & 0x1e | 1;
		uVar7 = (uVar7 << bVar8 | uVar7 >> 0x20 - bVar8) ^ (uVar7 >> bVar9 | uVar7 << 0x20 - bVar9) ^
			uVar7;
		bVar8 = bVar5 & 0x1e | 1;
		uVar7 = ((uVar7 + (uVar7 << (bVar5 * -6 & 0x1e | 1))) -
			(0x32c1bc7f << bVar8 | 0x32c1bc7fU >> 0x20 - bVar8) ^ 0x7f438551) + 0x43c85eda +
			(uVar12 ^ 0x691eddcc) ^ 0x59376c0b;
		uVar12 = uVar7 >> 0x18;
		//puVar10 = (undefined8*)(uVar12 * 0x10 + *(int*)(unaff_EBP + -0x5c));
		uVar7 = uVar7 >> 9 & 0x1ff;

		inst->OP = 33;
		inst->A = uVar12;
		inst->C = uVar7;
	}

	// OP_TFORLOOP 33 : A C 
	void df48e(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		undefined4* puVar2;
		uint* puVar3;
		undefined4 uVar4;
		char cVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		uint uVar9;
		undefined8* puVar10;
		char* pcVar11;
		//int unaff_EBP;
		uint uVar12;

		param_1 = param_1 - *(int*)(unaff_EBP + -100);
		*(int*)(unaff_EBP + -0xc) = param_1;
		uVar9 = param_1 + -8 >> 2;
		*(uint*)(unaff_EBP + -4) = uVar9;
		uVar9 = uVar9 & 0x1e | 1;
		sVar6 = (sbyte)uVar9;
		uVar12 = ~((param_2 >> 0x1a | param_2 << 6) ^ (param_2 << 1 | (uint)((int)param_2 < 0)) ^ param_2)
			;
		*(uint*)(unaff_EBP + -0x1c) = uVar9;
		bVar7 = ((byte)(0x12 >> sVar6) | (byte)(0x12 << 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		bVar8 = ((byte)(5 >> bVar8) | (byte)(5 << 0x20 - bVar8)) & 0x1e | 1;
		uVar12 = (uVar12 << bVar7 | uVar12 >> 0x20 - bVar7) ^ (uVar12 << bVar8 | uVar12 >> 0x20 - bVar8) ^
			uVar12;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f;
		uVar12 = (uVar12 >> 0x1d | uVar12 << 3) ^ (uVar12 >> 0x19 | uVar12 << 7) ^ uVar12;
		uVar12 = (uVar12 << (((byte)(0xc >> bVar8) | (byte)(0xc << 0x20 - bVar8)) & 0x1e | 1)) + uVar12;
		uVar12 = uVar12 << (4U - (char)*(undefined4*)(unaff_EBP + -4) & 0x1e | 1) ^ uVar12;
		uVar12 = (uVar12 << 0x1e | uVar12 >> 2) ^ (uVar12 >> 0xd | uVar12 << 0x13) ^ uVar12;
		uVar9 = (uVar12 << 0x10 | uVar12 >> 0x10) ^ 0x25db1d3b;
		uVar9 = (uVar9 << 0x18 ^ uVar9) >> 8;
		uVar9 = uVar9 << 5 ^ uVar9;
		uVar12 = uVar9 >> 9 & 0xff;
		//puVar10 = (undefined8*)(uVar12 * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//puVar10[10] = puVar10[4];
		//*(undefined4*)(puVar10 + 0xb) = *(undefined4*)(puVar10 + 5);
		uVar9 = uVar9 & 0x1ff;

		inst->OP = 33;
		inst->A = uVar12;
		inst->C = uVar9;
	}

	// OP_SETLIST 34 : A B C
	void d9782(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		byte bVar3;
		undefined8* puVar4;
		byte bVar5;
		uint uVar6;
		int iVar7;
		//int unaff_EBP;
		uint uVar8;
		int* piVar9;
		undefined8* puVar10;
		undefined4* in_FS_OFFSET;
		bool bVar11;

		bVar3 = (byte)((param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2);
		bVar5 = bVar3 & 0x1e | 1;
		uVar8 = (uint)~(param_2 * -0x1fffffff) >> (bVar3 * -0xf & 0x1e | 1) ^ ~(param_2 * -0x1fffffff);
		uVar8 = (uVar8 >> 0x18 | uVar8 << 8) ^ (uVar8 >> 0x13 | uVar8 << 0xd) ^ uVar8;
		uVar8 = uVar8 << 0x11 ^ uVar8;
		uVar8 = (uVar8 << (((byte)(8 << bVar5) | (byte)(8 >> 0x20 - bVar5)) & 0x1e | 1)) + uVar8;
		piVar9 = (int*)((uVar8 >> 10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		uVar6 = uVar8 >> 1 & 0x1ff;
		//*(int**)(unaff_EBP + -0xc) = piVar9;
		//uVar8 = uVar8 >> 0x12 & 0x1ff;

		inst->OP = 34;
		inst->A = (uVar8 >> 10 & 0xff);
		inst->C = uVar6;
		inst->B = uVar8 >> 0x12 & 0x1ff;
	}

	// OP_SETLIST 34 : A B C
	void dee53(instr* inst, uint param_1, uint param_2) {

		uint* puVar1;
		undefined4 uVar2;
		char cVar3;
		int iVar4;
		uint uVar5;
		undefined8* puVar6;
		char* pcVar7;
		sbyte sVar8;
		byte bVar9;
		byte bVar10;
		byte bVar11;
		byte bVar12;
		uint uVar13;
		int iVar14;
		//int unaff_EBP;
		int* piVar15;
		undefined8* puVar16;
		int unaff_retaddr;

		uVar13 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar13;
		uVar5 = uVar13 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar5;
		sVar8 = (sbyte)uVar5;
		bVar9 = ((byte)uVar13 ^ 4) & 0x1e | 1;
		bVar10 = ((byte)(9 << sVar8) | (byte)(9 >> 0x20 - sVar8)) & 0x1e | 1;
		uVar5 = *(int*)(unaff_EBP + -0x44) << (((byte)uVar13 ^ 0xe) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar5 = (uVar5 >> bVar9 | uVar5 << 0x20 - bVar9) + uVar13 * -2 + -0x1039109b;
		uVar5 = (uVar5 << bVar10 | uVar5 >> 0x20 - bVar10) + 0x492d871a ^
			*(int*)(unaff_EBP + -0xc) + 0x285b6da5U;
		bVar9 = (byte) * (int*)(unaff_EBP + -0xc);
		bVar10 = bVar9 + 0xc & 0x1e | 1;
		bVar11 = bVar9 - 0xb & 0x1e | 1;
		uVar5 = (uVar5 << bVar10 | uVar5 >> 0x20 - bVar10) ^ (uVar5 >> bVar11 | uVar5 << 0x20 - bVar11) ^
			uVar5;
		uVar5 = uVar5 - (uVar5 << ((bVar9 ^ 0xf9) & 0x1e | 1));
		bVar11 = (bVar9 ^ 10) & 0x1e | 1;
		bVar12 = (bVar9 ^ 2) & 0x1e | 1;
		bVar10 = (byte) * (undefined4*)(unaff_EBP + -4);
		bVar9 = bVar10 & 0x1f;
		bVar10 = bVar10 & 0x1f;
		bVar9 = ((byte)(8 >> bVar9) | (byte)(8 << 0x20 - bVar9)) & 0x1e | 1;
		bVar10 = ((byte)(0xe >> bVar10) | (byte)(0xe << 0x20 - bVar10)) & 0x1e | 1;
		uVar5 = ((uVar5 >> bVar11 | uVar5 << 0x20 - bVar11) ^ (uVar5 >> bVar12 | uVar5 << 0x20 - bVar12) ^
			uVar5) * -0x7ffff;
		uVar5 = uVar5 >> bVar10 | uVar5 << 0x20 - bVar10;
		uVar5 = uVar5 >> bVar9 | uVar5 << 0x20 - bVar9;
		uVar5 = uVar5 << 1 | (uint)((int)uVar5 < 0);
		bVar9 = (char)*(undefined4*)(unaff_EBP + -0xc) - 9U & 0x1e | 1;
		uVar13 = ~((uVar5 << bVar9 | uVar5 >> 0x20 - bVar9) ^ (uVar5 >> bVar9 | uVar5 << 0x20 - bVar9) ^
			uVar5);
		uVar5 = uVar13 & 0x1ff;
		//piVar15 = (int*)((uVar13 >> 9 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//*(int**)(unaff_EBP + -0xc) = piVar15;
		//uVar13 = uVar13 >> 0x13 & 0x1ff;

		inst->OP = 34;
		inst->A = (uVar13 >> 9 & 0xff);
		inst->B = uVar13 >> 0x13 & 0x1ff;
		inst->C = uVar5;
	}

	// OP_SETLIST 34 : A B C
	void dfe27(instr* inst, uint param_1, uint param_2) {

		int* piVar1;
		code* pcVar2;
		char cVar3;
		uint uVar4;
		uint* puVar5;
		undefined8* puVar6;
		char* pcVar7;
		byte bVar9;
		int extraout_ECX;
		int iVar8;
		uint uVar10;
		int* piVar11;
		char* unaff_EBX;
		//uint unaff_EBP;
		undefined8* puVar12;

		param_2 = ~param_2;
		param_2 = (param_2 >> 0x1b | param_2 << 5) ^ (param_2 << 0xc | param_2 >> 0x14) ^ param_2;
		uVar4 = (param_2 >> 0x17 ^ param_2) << 0x11;
		uVar10 = uVar4 | param_2 >> 0xf;
		uVar10 = (uVar4 >> 0x1c | uVar10 << 4) ^ (uVar10 >> 0xd | (param_2 >> 0xf) << 0x13) ^ uVar10;
		cVar3 = (char)((param_1 - *(int*)(unaff_EBP - 100)) + -8 >> 2);
		uVar4 = ~(((uVar10 << 0x13 | uVar10 >> 0xd) ^ (uVar10 >> 0xc | uVar10 << 0x14) ^ uVar10) *
			0x17a3d40b);
		uVar4 = uVar4 >> (cVar3 * '\x03' & 0x1eU | 1) ^ uVar4;
		uVar10 = (uVar4 << (cVar3 * -5 & 0x1eU | 1) ^ uVar4) + 0x853b0297;
		puVar5 = (uint*)(uVar10 >> 9);
		uVar4 = uVar10 & 0x1ff;
		//piVar11 = (int*)(((uint)puVar5 & 0xff) * 0x10 + *(int*)(unaff_EBP - 0x5c));
		//uVar10 = uVar10 >> 0x17;

		inst->OP = 34;
		inst->A = (uint)puVar5 & 0xff;
		inst->B = uVar10 >> 0x17;
		inst->C = uVar4;
	}

	// OP_CLOSE 35 : A  
	void d3ec6(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		sbyte sVar5;
		uint uVar6;
		//int unaff_EBP;
		uint uVar7;
		uint uVar8;

		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		bVar3 = -(char)uVar8 - 0xdU & 0x1e | 1;
		bVar4 = 1U - (char)uVar8 & 0x1e | 1;
		uVar6 = (param_2 >> bVar3 | param_2 << 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x44) << bVar4 | *(uint*)(unaff_EBP + -0x44) >> 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar7 = ~((uVar6 << 0x19 | uVar6 >> 7) ^ (uVar6 << 0x16 | uVar6 >> 10) ^ uVar6);
		uVar6 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar6;
		sVar5 = (sbyte)uVar6;
		uVar6 = (uVar7 << (((byte)(0xd << sVar5) | (byte)(0xd >> 0x20 - sVar5)) & 0x1e | 1)) + uVar7 ^
			0x1acfdb77U - *(int*)(unaff_EBP + -0xc);
		bVar3 = ((byte)(0x14 >> sVar5) | (byte)(0x14 << 0x20 - sVar5)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar6 << bVar3 | uVar6 >> 0x20 - bVar3;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar3 = ((byte)(0x10 >> bVar3) | (byte)(0x10 << 0x20 - bVar3)) & 0x1e | 1;
		//pcVar2 = (char*)FUN_0046fee0(((*(uint*)(unaff_EBP + -0xc) ^
		//	(uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^ uVar6) & 0xff) * 0x10 +
		//	*(int*)(unaff_EBP + -0x5c));

		uint lol = ((*(uint*)(unaff_EBP + -0xc) ^
			(uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^ uVar6) & 0xff);

		inst->OP = 35;
		inst->A = lol;
	}

	// OP_CLOSE 35 : A  
	void d3faa(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		sbyte sVar3;
		byte bVar4;
		byte bVar5;
		//int unaff_EBP;
		uint uVar6;
		uint uVar7;

		uVar7 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar6 = uVar7 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar6;
		sVar3 = (sbyte)uVar6;
		uVar6 = param_2 >> (((byte)(0x14 >> sVar3) | (byte)(0x14 << 0x20 - sVar3)) & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar6 = uVar6 >> (((byte)(2 << sVar3) | (byte)(2 >> 0x20 - sVar3)) & 0x1e | 1) ^ uVar6;
		bVar4 = (byte)uVar7 * '\x05' & 0x1e | 1;
		uVar6 = uVar6 << (((byte)uVar7 ^ 8) & 0x1e | 1) ^ uVar6;
		uVar6 = uVar6 << bVar4 | uVar6 >> 0x20 - bVar4;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(0x1b >> bVar4) | (byte)(0x1b << 0x20 - bVar4)) & 0x1e | 1;
		bVar4 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar4 = ((byte)(0x17 >> bVar4) | (byte)(0x17 << 0x20 - bVar4)) & 0x1e | 1;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^ (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^
			uVar6;
		cVar1 = (char)*(undefined4*)(unaff_EBP + -0xc);
		uVar6 = uVar6 >> (cVar1 + 3U & 0x1e | 1) ^ uVar6;
		uVar6 = ~((uVar6 >> 0x15 | uVar6 << 0xb) * 0x76f546b);
		uVar7 = uVar6 << 0x1e ^ uVar6;
		uVar7 = (uVar7 >> 0x15 | uVar6 << 0xb) ^ (uVar7 >> 0x12 | uVar6 << 0xe) ^ uVar7;
		uVar6 = uVar7 * -3;
		uVar6 = ~((uVar6 >> 0x12 | uVar7 * -0xc000) ^ (uVar6 >> 3 | uVar7 * -0x60000000) ^ uVar6);
		bVar4 = cVar1 - 0xfU & 0x1e | 1;
		bVar5 = cVar1 + 6U & 0x1e | 1;
		//pcVar2 = (char*)FUN_0046ff3c((((uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
		//	(uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^ uVar6) >> 0x12 & 0xff)
		//	* 0x10 + *(int*)(unaff_EBP + -0x5c));

		uint lol = (((uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
			(uVar6 >> bVar5 | uVar6 << 0x20 - bVar5) ^ uVar6) >> 0x12 & 0xff);

		inst->OP = 35;
		inst->A = lol;
	}

	// OP_CLOSE 35 : A  
	void ddf96(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		uint uVar7;
		//int unaff_EBP;
		int iVar8;

		uVar6 = param_2 + 0xf50aed2b;
		iVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(int*)(unaff_EBP + -0xc) = iVar8;
		bVar5 = (byte)iVar8;
		bVar3 = (bVar5 ^ 0xf3) & 0x1e | 1;
		bVar4 = (bVar5 ^ 0xf5) & 0x1e | 1;
		uVar7 = ~((uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^ (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^
			uVar6);
		uVar6 = uVar7 * 0x4e8d7db9;
		bVar5 = bVar5 & 0x1e | 1;
		uVar6 = (uVar7 * -0x91c0000 | uVar6 >> 0xe) ^ (uVar6 >> 0xc | uVar7 * -0x24700000) ^ uVar6;
		uVar6 = (uVar6 >> (((byte)(0xb >> bVar5) | (byte)(0xb << 0x20 - bVar5)) & 0x1e | 1) ^ uVar6) +
			(0x7f4e925d << bVar5 | 0x7f4e925dU >> 0x20 - bVar5) +
			(*(uint*)(unaff_EBP + -0xc) ^ 0x3fc2772c);
		uVar6 = (uVar6 >> 0x1c | uVar6 * 0x10) ^ (uVar6 * 2 | (uint)((int)uVar6 < 0)) ^ uVar6;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		uVar6 = uVar6 >> ((bVar5 ^ 0xf3) & 0x1e | 1) ^ uVar6;
		uVar6 = (uVar6 << 0x1a | uVar6 >> 6) ^ (uVar6 << 4 | uVar6 >> 0x1c) ^ uVar6;
		uVar6 = (uVar6 >> 6 | uVar6 << 0x1a) * 0x46bd3b7b;
		bVar3 = bVar5 + 7 & 0x1e | 1;
		bVar5 = bVar5 + 1 & 0x1e | 1;
		uVar6 = (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^ (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^
			uVar6;
		//pcVar2 = (char*)FUN_0046ff16(((uVar6 >> 0xb ^ uVar6 >> 0xf ^ uVar6) & 0xff) * 0x10 +
		//	*(int*)(unaff_EBP + -0x5c));

		inst->OP = 35;
		inst->A = ((uVar6 >> 0xb ^ uVar6 >> 0xf ^ uVar6) & 0xff);
	}

	// OP_UNK 7 : A Bx
	void d489f(instr* inst, uint param_1, uint param_2) {
		byte* pbVar1;
		int iVar2;
		int iVar3;
		undefined4 uVar4;
		char* pcVar5;
		char cVar6;
		uint uVar7;
		byte bVar8;
		byte bVar9;
		int iVar10;
		//int unaff_EBP;
		int iVar11;
		undefined8* puVar12;

		iVar11 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar9 = (byte)iVar11;
		bVar8 = bVar9 & 0x1e | 1;
		uVar7 = (*(int*)(unaff_EBP + -0x44) * 3 - (0x1a8929d << bVar8 | 0x1a8929dU >> 0x20 - bVar8)) *
			0x100001;
		bVar8 = (byte)((-iVar11 & 1U) << 4) | 1;
		uVar7 = uVar7 >> 7 ^ uVar7;
		bVar9 = bVar9 * -9 & 0x1e | 1;
		uVar7 = (uVar7 >> bVar8 | uVar7 << 0x20 - bVar8) ^ (uVar7 >> bVar9 | uVar7 << 0x20 - bVar9) ^
			uVar7;
		*(uint*)(unaff_EBP + -0xc) = uVar7;
		uVar7 = uVar7 * -7;
		//iVar11 = *(int*)(*(int*)(unaff_EBP + -0xb0) + 0xc);
		//puVar12 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//iVar10 = (uVar7 >> 8 & 0x3ffff) * 0x10;

		inst->OP = 7;
		inst->A = (uVar7 & 0xff);
		inst->Bx = (uVar7 >> 8 & 0x3ffff);
	}

	// OP_UNK 7 : A Bx
	void d5ed0(instr* inst, uint param_1, uint param_2) {
		byte* pbVar1;
		int iVar2;
		int iVar3;
		int iVar4;
		char* pcVar5;
		byte bVar6;
		char cVar7;
		sbyte sVar8;
		byte bVar9;
		byte bVar10;
		byte bVar11;
		uint uVar12;
		undefined8* puVar13;
		//int unaff_EBP;
		int iVar14;
		uint uVar15;

		param_2 = ~param_2;
		*(uint*)(unaff_EBP + -0x44) = param_2;
		uVar15 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar12 = (param_2 << 0x16 | param_2 >> 10) ^
			(*(uint*)(unaff_EBP + -0x44) << 0xb | *(uint*)(unaff_EBP + -0x44) >> 0x15) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar12 = uVar12 << 3 | uVar12 >> 0x1d;
		uVar12 = uVar12 - (uVar12 << ((char)uVar15 * -0xf & 0x1eU | 1));
		uVar12 = (uVar12 >> (0xdU - (char)uVar15 & 0x1e | 1) ^ uVar12) + 0xa3f250 + uVar15;
		uVar15 = uVar15 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar15;
		sVar8 = (sbyte)uVar15;
		bVar9 = ((byte)(7 >> sVar8) | (byte)(7 << 0x20 - sVar8)) & 0x1e | 1;
		bVar11 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar10 = ((byte)(2 >> bVar11) | (byte)(2 << 0x20 - bVar11)) & 0x1e | 1;
		bVar11 = (byte) * (undefined4*)(unaff_EBP + -0xc);
		bVar6 = bVar11 & 0x1f;
		bVar11 = bVar11 & 0x1f;
		uVar12 = ((uVar12 << bVar9 | uVar12 >> 0x20 - bVar9) ^
			(uVar12 >> bVar10 | uVar12 << 0x20 - bVar10) ^ uVar12) -
			(0xb2b218d << bVar11 | 0xb2b218dU >> 0x20 - bVar11);
		uVar12 = (uVar12 * 0x1000000 | uVar12 >> 8) ^ (uVar12 * 2 | (uint)((int)uVar12 < 0)) ^ uVar12;
		uVar12 = uVar12 - (uVar12 << (((byte)(0x1a >> bVar6) | (byte)(0x1a << 0x20 - bVar6)) & 0x1e | 1));
		//puVar13 = (undefined8*)((uVar12 >> 0x12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		//iVar14 = (uVar12 & 0x3ffff) * 0x10;

		inst->OP = 7;
		inst->A = (uVar12 >> 0x12 & 0xff);
		inst->Bx = (uVar12 & 0x3ffff);
	}

	// OP_UNK 7 : A Bx
	void da0c1(instr* inst, uint param_1, uint param_2) {
		int iVar1;
		char cVar2;
		char* pcVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		int iVar7;
		//int unaff_EBP;
		uint uVar8;
		undefined8* puVar9;
		int iVar10;

		iVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		bVar5 = (byte)iVar10;
		bVar4 = bVar5 & 0x1e | 1;
		bVar5 = bVar5 * '\x06' & 0x1e | 1;
		uVar6 = (param_2 + iVar10) * 0x3fff001 + 0x358b7235;
		uVar8 = uVar6 * 0x8000;
		uVar6 = uVar8 | uVar6 >> 0x11;
		uVar8 = ((uVar8 >> 0x14 | uVar6 << 0xc) ^ (uVar6 << 6 | uVar8 >> 0x1a) ^ uVar6) + 0x2ada548f;
		uVar8 = uVar8 >> bVar5 | uVar8 << 0x20 - bVar5;
		uVar8 = (0x1163b5U >> bVar4 | 0x1163b5 << 0x20 - bVar4) + (uVar8 >> 4 ^ uVar8 ^ 0x501777a7) ^
			0x30609c44;
		//pcVar3 = *(char**)(unaff_EBP + -0xb0);
		//puVar9 = (undefined8*)((uVar8 >> 0x17 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x5c));
		iVar7 = (uVar8 >> 5 & 0x3ffff) * 0x10;

		inst->OP = 7;
		inst->A = (uVar8 >> 0x17 & 0xff);
		inst->Bx = (uVar8 >> 5 & 0x3ffff);
	}

	// OP_MOD 16 : A B C
	void df7b9(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		code* pcVar2;
		uint* puVar3;
		char cVar4;
		char* pcVar5;
		byte bVar6;
		byte bVar7;
		sbyte sVar8;
		int iVar9;
		uint uVar10;
		undefined8* puVar11;
		//int unaff_EBP;
		uint uVar12;
		//float10 extraout_ST0;

		uVar12 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		cVar4 = (char)uVar12;
		*(uint*)(unaff_EBP + -0xc) = uVar12;
		bVar6 = 10U - cVar4 & 0x1e | 1;
		bVar7 = -cVar4 - 9U & 0x1e | 1;
		uVar10 = ~((param_2 << bVar6 | param_2 >> 0x20 - bVar6) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar7 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar7)
			^ *(uint*)(unaff_EBP + -0x44));
		uVar10 = ((uVar10 >> 0x1b | uVar10 << 5) ^ (uVar10 >> 0x10 | uVar10 << 0x10) ^ uVar10) * 0x81;
		bVar6 = cVar4 * '\x02' & 0x1eU | 1;
		uVar10 = uVar10 >> (cVar4 + 5U & 0x1e | 1) ^ uVar10 ^ uVar12 ^ 0x51c5a4d2;
		uVar10 = (uVar10 << 0x13 | uVar10 >> 0xd) ^ (uVar10 << 0xb | uVar10 >> 0x15) ^ uVar10;
		uVar12 = uVar10 >> 0x18 | uVar10 << 8;
		uVar10 = *(uint*)(unaff_EBP + -0xc) & 0x1e | 1;
		uVar12 = (uVar12 << bVar6 | uVar12 >> 0x20 - bVar6) * -0x3fff + 0x30b3883f;
		*(uint*)(unaff_EBP + -0xc) = uVar10;
		sVar8 = (sbyte)uVar10;
		uVar12 = (uVar12 * 0x800000 | uVar12 >> 9) ^ (uVar12 >> 0x10 | uVar12 * 0x10000) ^ uVar12;
		bVar7 = ((byte)(0x13 << sVar8) | (byte)(0x13 >> 0x20 - sVar8)) & 0x1e | 1;
		bVar6 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar6 = ((byte)(0x12 << bVar6) | (byte)(0x12 >> 0x20 - bVar6)) & 0x1e | 1;
		uVar12 = (uVar12 >> bVar7 | uVar12 << 0x20 - bVar7) ^ (uVar12 >> bVar6 | uVar12 << 0x20 - bVar6) ^
			uVar12;
		uVar12 = (uVar12 << ((byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f)) + uVar12;
		uVar10 = uVar12 * 0x80;
		uVar12 = uVar10 | uVar12 >> 0x19;
		uVar12 = (uVar10 >> 0x16 | uVar12 << 10) ^ (uVar12 << 4 | uVar10 >> 0x1c) ^ uVar12;
		iVar9 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = uVar12 >> 0xe;
		//*(uint*)(unaff_EBP + -0xc) = (uVar12 >> 0x17 & 0xff) * 0x10 + iVar9;
		if ((uVar10 & 0x100) == 0) {
			//puVar11 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + iVar9);
		}
		else {
			//puVar11 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		if ((uVar12 & 0x100) == 0) {
			//iVar9 = (uVar12 & 0x1ff) * 0x10 + iVar9;
		}
		else {
			//iVar9 = (uVar12 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c);
		}

		inst->OP = 16;
		inst->A = (uVar12 >> 0x17 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar12 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void d52c9(instr* inst, uint param_1, uint param_2) {

		int iVar1;
		uint* puVar2;
		char cVar3;
		undefined8* puVar4;
		char* pcVar5;
		sbyte sVar6;
		byte bVar7;
		byte bVar8;
		byte bVar9;
		uint uVar10;
		uint uVar11;
		undefined8* puVar12;
		//int unaff_EBP;
		undefined8 uVar13;

		uVar10 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar11 = uVar10 & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar11;
		sVar6 = (sbyte)uVar11;
		uVar10 = (*(int*)(unaff_EBP + -0x44) << (-(char)uVar10 - 4U & 0x1e | 1) ^
			*(uint*)(unaff_EBP + -0x44)) + 0x6dcbc8c9;
		bVar7 = ((byte)(0x19 << sVar6) | (byte)(0x19 >> 0x20 - sVar6)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar8 = ((byte)(10 << bVar8) | (byte)(10 >> 0x20 - bVar8)) & 0x1e | 1;
		uVar10 = (uVar10 >> bVar7 | uVar10 << 0x20 - bVar7) ^ (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) ^
			uVar10;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar7 = ((byte)(0x14 << bVar8) | (byte)(0x14 >> 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar9 = ((byte)(0xd << bVar8) | (byte)(0xd >> 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		uVar10 = ((uVar10 << bVar7 | uVar10 >> 0x20 - bVar7) ^ (uVar10 >> bVar9 | uVar10 << 0x20 - bVar9)
			^ uVar10) * 0x7357006f;
		bVar7 = ((byte)(0x1a >> bVar8) | (byte)(0x1a << 0x20 - bVar8)) & 0x1e | 1;
		bVar8 = (byte) * (undefined4*)(unaff_EBP + -0xc) & 0x1f;
		bVar8 = ((byte)(2 >> bVar8) | (byte)(2 << 0x20 - bVar8)) & 0x1e | 1;
		uVar10 = (uVar10 >> bVar7 | uVar10 << 0x20 - bVar7) ^ (uVar10 << bVar8 | uVar10 >> 0x20 - bVar8) ^
			uVar10;
		uVar10 = uVar10 * 2 ^ uVar10;
		uVar11 = ~(uVar10 >> 0x10 ^ uVar10);
		uVar11 = uVar11 >> 7 ^ uVar11;
		iVar1 = *(int*)(unaff_EBP + -0x5c);
		uVar10 = uVar11 >> 8;
		//*(uint*)(unaff_EBP + -0xc) = (uVar11 & 0xff) * 0x10 + iVar1;
		if ((uVar10 & 0x100) == 0) {
			//puVar4 = (undefined8*)((uVar10 & 0x1ff) * 0x10 + iVar1);
		}
		else {
			//puVar4 = (undefined8*)((uVar10 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar11_2 = uVar11 >> 0x11;
		//*(undefined8**)(unaff_EBP + -4) = puVar4;
		//puVar2 = _DAT_10675ab8;
		if ((uVar11 & 0x100) == 0) {
			//puVar12 = (undefined8*)((uVar11 & 0x1ff) * 0x10 + iVar1);
		}
		else {
			//puVar12 = (undefined8*)((uVar11 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar11 & 0xff);
		inst->B = (uVar10 & 0x1ff);
		inst->C = (uVar11_2 & 0x1ff);
	}

	// OP_POW 17 : A B C
	void d784a(instr* inst, uint param_1, uint param_2) {

		uint uVar1;
		uint* puVar2;
		char cVar3;
		char* pcVar4;
		char* pcVar5;
		int iVar6;
		uint uVar7;
		undefined8* puVar8;
		//int unaff_EBP;

		param_2 = param_2 ^ 0x7813063a;
		iVar6 = ~((param_2 >> 0x10 | param_2 << 0x10) ^ (param_2 << 3 | param_2 >> 0x1d) ^ param_2) *
			0x2cb50ccd + -0x51180d3;
		uVar7 = ~(iVar6 - (iVar6 << (((byte)((*(int*)(unaff_EBP + -0x50) - *(int*)(unaff_EBP + -100)) +
			-8 >> 2) ^ 0xf7) & 0x1e | 1)));
		uVar7 = (uVar7 << 0x14 | uVar7 >> 0xc) ^ (uVar7 >> 0xe | uVar7 << 0x12) ^ uVar7;
		//pcVar4 = *(char**)(unaff_EBP + -0x5c);
		//*(char**)(unaff_EBP + -0xc) = pcVar4 + (uVar7 >> 0xf & 0xff) * 0x10;
		if ((uVar7 & 0x100) == 0) {
			//puVar8 = (undefined8*)(pcVar4 + (uVar7 & 0x1ff) * 0x10);
		}
		else {
			//puVar8 = (undefined8*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}
		uint uVar7_2 = uVar7 >> 0x17;
		if ((uVar7 & 0x100) == 0) {
			//pcVar5 = pcVar4 + uVar7 * 0x10;
		}
		else {
			//pcVar5 = (char*)((uVar7 & 0xff) * 0x10 + *(int*)(unaff_EBP + -0x6c));
		}

		inst->OP = 17;
		inst->A = (uVar7 >> 0xf & 0xff);
		inst->B = (uVar7 & 0x1ff);
		inst->C = uVar7_2;
	}

	// OP_VARARG 37 : A B 
	void dc83e(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		sbyte sVar5;
		uint uVar6;
		uint uVar7;
		//int unaff_EBP;
		uint uVar8;

		uVar6 = param_2 * -3;
		*(uint*)(unaff_EBP + -0x44) = uVar6;
		uVar8 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar8;
		bVar3 = (char)uVar8 - 6U & 0x1e | 1;
		bVar4 = (char)uVar8 - 3U & 0x1e | 1;
		uVar7 = (uVar6 >> bVar3 | uVar6 << 0x20 - bVar3) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar4 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar4) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar6 = uVar8 & 0x1e | 1;
		*(uint*)(unaff_EBP + -4) = uVar6;
		sVar5 = (sbyte)uVar6;
		uVar6 = (uVar7 << 0x1a ^ uVar7) + 0x532bf7da;
		bVar4 = ((byte)(0x12 << sVar5) | (byte)(0x12 >> 0x20 - sVar5)) & 0x1e | 1;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar3 = ((byte)(5 << bVar3) | (byte)(5 >> 0x20 - bVar3)) & 0x1e | 1;
		uVar6 = ((uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^ (uVar6 << bVar3 | uVar6 >> 0x20 - bVar3) ^
			uVar6) + 0x73dcdf55;
		uVar6 = (uVar6 * 0x400000 | uVar6 >> 10) ^ (uVar6 >> 9 | uVar6 * 0x800000) ^ uVar6 ^ 0x35823305;
		uVar6 = (uVar6 << 0x18 | uVar6 >> 8) ^ (uVar6 << 0xe | uVar6 >> 0x12) ^ uVar6;
		uVar6 = uVar6 << (((byte) * (undefined4*)(unaff_EBP + -0xc) ^ 0xc) & 0x1e | 1) ^ uVar6;
		bVar3 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar6 = (uVar6 << 7 | uVar6 >> 0x19) ^ 0x1882429e;
		uVar6 = uVar6 << (((byte)(0x1d >> bVar3) | (byte)(0x1d << 0x20 - bVar3)) & 0x1e | 1) ^ uVar6;
		//pcVar2 = (char*)((uVar6 >> 0x12 & 0xff) << 4);
		//*(char**)(unaff_EBP + -0xc) = pcVar2;
		//*(uint*)(unaff_EBP + -4) = (uVar6 >> 9 & 0x1ff) - 1;

		inst->OP = 37;
		inst->A = (uVar6 >> 0x12 & 0xff);
		inst->B = (uVar6 >> 9 & 0x1ff);
	}

	// OP_VARARG 37 : A B 
	void dd77e(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		byte bVar3;
		byte bVar4;
		uint uVar5;
		//int unaff_EBP;
		uint uVar6;

		uVar6 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		uVar5 = (param_2 << 0x16 | param_2 >> 10) ^
			(*(uint*)(unaff_EBP + -0x44) << 9 | *(uint*)(unaff_EBP + -0x44) >> 0x17) ^
			*(uint*)(unaff_EBP + -0x44);
		uVar5 = ((uVar5 >> 0x11 | uVar5 << 0xf) ^ (uVar5 >> 0xe | uVar5 << 0x12) ^ uVar5) * 0x31721b33 ^
			0x7279f9ad;
		uVar5 = (uVar5 << 0xd ^ uVar5) + (uVar6 ^ 0x7ea1bc39);
		bVar3 = (byte)uVar6 & 0x1e | 1;
		bVar4 = ((byte)(0x1b >> bVar3) | (byte)(0x1b << 0x20 - bVar3)) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0xc) = uVar5 >> bVar4 | uVar5 << 0x20 - bVar4;
		bVar3 = ((byte)(0x10 >> bVar3) | (byte)(0x10 << 0x20 - bVar3)) & 0x1e | 1;
		uVar5 = *(uint*)(unaff_EBP + -0xc) ^ (uVar5 << bVar3 | uVar5 >> 0x20 - bVar3) ^ uVar5;
		//pcVar2 = (char*)((uVar5 >> 0xd & 0xff) << 4);
		//*(char**)(unaff_EBP + -4) = pcVar2;
		//*(uint*)(unaff_EBP + -0xc) = (uVar5 >> 0x15 & 0x1ff) - 1;

		inst->OP = 37;
		inst->A = (uVar5 >> 0xd & 0xff);
		inst->B = (uVar5 >> 0x15 & 0x1ff);
	}

	// OP_VARARG 37 : A B 
	void df5fc(instr* inst, uint param_1, uint param_2) {

		char cVar1;
		char* pcVar2;
		sbyte sVar3;
		byte bVar4;
		byte bVar5;
		uint uVar6;
		//int unaff_EBP;
		int iVar7;
		uint uVar8;
		uint uVar9;

		param_2 = param_2 ^ 0x1485f4e0;
		*(uint*)(unaff_EBP + -0x44) = param_2;
		uVar9 = (param_1 - *(int*)(unaff_EBP + -100)) + -8 >> 2;
		*(uint*)(unaff_EBP + -0xc) = uVar9;
		uVar6 = uVar9 & 0x1e | 1;
		sVar3 = (sbyte)uVar6;
		*(uint*)(unaff_EBP + -4) = uVar6;
		bVar4 = ((byte)(0x18 << sVar3) | (byte)(0x18 >> 0x20 - sVar3)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(1 << bVar5) | (byte)(1 >> 0x20 - bVar5)) & 0x1e | 1;
		uVar6 = (param_2 >> bVar4 | param_2 << 0x20 - bVar4) ^
			(*(uint*)(unaff_EBP + -0x44) >> bVar5 | *(uint*)(unaff_EBP + -0x44) << 0x20 - bVar5) ^
			*(uint*)(unaff_EBP + -0x44);
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		iVar7 = (uVar6 >> 0x10 | uVar6 << 0x10) + 0x3533e272;
		uVar6 = ((iVar7 << (((byte)(0x14 >> bVar5) | (byte)(0x14 << 0x20 - bVar5)) & 0x1e | 1)) + iVar7) *
			0x3aec2835;
		uVar8 = (uVar9 ^ 8) & 0x1e | 1;
		*(uint*)(unaff_EBP + -0x1c) = uVar8;
		uVar6 = uVar6 >> 2 ^ uVar6;
		uVar6 = (uVar6 << 0x1b | uVar6 >> 5) ^ (uVar6 >> 0x1a | uVar6 << 6) ^ uVar6;
		bVar5 = ((byte)uVar9 ^ 0xf1) & 0x1e | 1;
		sVar3 = (sbyte)uVar8;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^ (uVar6 >> sVar3 | uVar6 << 0x20 - sVar3) ^
			uVar6;
		bVar5 = 0xcU - (char)*(undefined4*)(unaff_EBP + -0xc) & 0x1e | 1;
		bVar4 = -(char)*(undefined4*)(unaff_EBP + -0xc) - 5U & 0x1e | 1;
		uVar6 = (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^ (uVar6 << bVar4 | uVar6 >> 0x20 - bVar4) ^
			uVar6;
		uVar6 = ((uVar6 << 0xf | uVar6 >> 0x11) ^ (uVar6 << 1 | (uint)((int)uVar6 < 0)) ^ uVar6) *
			0x3bb2a16f;
		uVar6 = uVar6 << ((byte) * (undefined4*)(unaff_EBP + -0x1c) & 0x1f) ^ uVar6;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar4 = ((byte)(0xd >> bVar5) | (byte)(0xd << 0x20 - bVar5)) & 0x1e | 1;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		bVar5 = ((byte)(7 >> bVar5) | (byte)(7 << 0x20 - bVar5)) & 0x1e | 1;
		uVar6 = (uVar6 >> bVar4 | uVar6 << 0x20 - bVar4) ^ (uVar6 << bVar5 | uVar6 >> 0x20 - bVar5) ^
			uVar6;
		bVar5 = (byte) * (undefined4*)(unaff_EBP + -4) & 0x1f;
		uVar6 = uVar6 >> (((byte)(0xe << bVar5) | (byte)(0xe >> 0x20 - bVar5)) & 0x1e | 1) ^ uVar6;
		uVar6 = (uVar6 << 0x16 | uVar6 >> 10) ^ (uVar6 >> 0x13 | uVar6 << 0xd) ^ uVar6;
		uVar6 = ((uVar6 >> 0x18 | uVar6 << 8) ^ (uVar6 >> 0x16 | uVar6 << 10) ^ uVar6) * 0x71a1aa1b;
		//pcVar2 = (char*)((uVar6 & 0xff) << 4);
		//*(char**)(unaff_EBP + -0xc) = pcVar2;
		//*(uint*)(unaff_EBP + -4) = (uVar6 >> 8 & 0x1ff) - 1;

		inst->OP = 37;
		inst->A = (uVar6 & 0xff);
		inst->B = (uVar6 >> 8 & 0x1ff);
	}

	instr decrypt(uint pc, uint key, uint data) {
		instr inst;

		*(uint*)(unaff_EBP + -100) = 0;
		*(uint*)(unaff_EBP + -0x44) = data;
		*(uint*)(unaff_EBP + -0x50) = pc;

		//std::cout << pc << ": " << key << std::endl;

		switch (key) {
			// OP_MOVE 0 : A B 
		case 0x4d65: d4d65(&inst, pc, data); break;
		case 0x6692: d6692(&inst, pc, data); break;
		case 0x7d2e: d7d2e(&inst, pc, data); break;

			// OP_LOADK 1 : A Bx 
		case 0x05f1: d05f1(&inst, pc, data); break;
		case 0x67f6: d67f6(&inst, pc, data); break;
		case 0xd2f2: dd2f2(&inst, pc, data); break;

			// OP_LOADBOOL 2 : A B C
		case 0x3619: d3619(&inst, pc, data); break;
		case 0x5fa6: d5fa6(&inst, pc, data); break;
		case 0x735b: d735b(&inst, pc, data); break;
		case 0x7f13: d7f13(&inst, pc, data); break;
		case 0xa0b0: da0b0(&inst, pc, data); break;
		case 0xbad2: dbad2(&inst, pc, data); break;
		case 0xe49f: de49f(&inst, pc, data); break;
		case 0xeb58: deb58(&inst, pc, data); break;

			// OP_LOADNIL 3 : A B 
		case 0x5e7f: d5e7f(&inst, pc, data); break;
		case 0x6442: d6442(&inst, pc, data); break;
		case 0xad24: dad24(&inst, pc, data); break;
		case 0xbae9: dbae9(&inst, pc, data); break;
		case 0xded8: dded8(&inst, pc, data); break;
		case 0xf546: df546(&inst, pc, data); break;
		case 0xfe4d: dfe4d(&inst, pc, data); break;

			// OP_GETUPVAL 4 : A B 
		case 0x2245: d2245(&inst, pc, data); break;
		case 0x236a: d236a(&inst, pc, data); break;
		case 0x23d5: d23d5(&inst, pc, data); break;
		case 0x2e98: d2e98(&inst, pc, data); break;
		case 0x4af3: d4af3(&inst, pc, data); break;
		case 0x8556: d8556(&inst, pc, data); break;
		case 0xc7de: dc7de(&inst, pc, data); break;
		case 0xe0bf: de0bf(&inst, pc, data); break;

			// OP_GETGLOBAL 5 : A Bx 
		case 0x0985: d0985(&inst, pc, data); break;
		case 0x1535: d1535(&inst, pc, data); break;
		case 0x15f0: d15f0(&inst, pc, data); break;
		case 0x2d70: d2d70(&inst, pc, data); break;
		case 0x3a93: d3a93(&inst, pc, data); break;
		case 0x4275: d4275(&inst, pc, data); break;
		case 0x48fc: d48fc(&inst, pc, data); break;
		case 0x5001: d5001(&inst, pc, data); break;
		case 0x6bd3: d6bd3(&inst, pc, data); break;
		case 0x86c5: d86c5(&inst, pc, data); break;
		case 0x9199: d9199(&inst, pc, data); break;
		case 0xc131: dc131(&inst, pc, data); break;
		case 0xd22b: dd22b(&inst, pc, data); break;
		case 0xe270: de270(&inst, pc, data); break;
		case 0xe905: de905(&inst, pc, data); break;
		case 0xf608: df608(&inst, pc, data); break;

			// OP_GETTABLE 6 : A B C
		case 0x0ddc: d0ddc(&inst, pc, data); break;
		case 0x19b4: d19b4(&inst, pc, data); break;
		case 0x1e7c: d1e7c(&inst, pc, data); break;
		case 0x2660: d2660(&inst, pc, data); break;
		case 0x2bff: d2bff(&inst, pc, data); break;
		case 0x7aad: d7aad(&inst, pc, data); break;
		case 0x973f: d973f(&inst, pc, data); break;
		case 0xd31d: dd31d(&inst, pc, data); break;
		case 0xe611: de611(&inst, pc, data); break;

			// OP_SETGLOBAL 7 : A Bx 
		case 0x1bca: d1bca(&inst, pc, data); break;
			case 0x489f: d489f(&inst, pc, data); break;
		case 0x557b: d557b(&inst, pc, data); break;
		case 0x56ad: d56ad(&inst, pc, data); break;
			case 0x5ed0: d5ed0(&inst, pc, data); break;
			case 0xa0c1: da0c1(&inst, pc, data); break;
		case 0xaa9b: daa9b(&inst, pc, data); break;
		case 0xf51b: df51b(&inst, pc, data); break;
		case 0xf9bd: df9bd(&inst, pc, data); break;

			// OP_SETUPVAL 8 : A B 
		case 0x520b: d520b(&inst, pc, data); break;
		case 0x5a62: d5a62(&inst, pc, data); break;
		case 0x7ca0: d7ca0(&inst, pc, data); break;
		case 0xa139: da139(&inst, pc, data); break;
		case 0xcede: dcede(&inst, pc, data); break;
		case 0xf96b: df96b(&inst, pc, data); break;

			// OP_SETTABLE 9 : A B C
		case 0x6411: d6411(&inst, pc, data); break;
		case 0x71e4: d71e4(&inst, pc, data); break;
		case 0x8d7d: d8d7d(&inst, pc, data); break;
		case 0x958f: d958f(&inst, pc, data); break;
		case 0xa966: da966(&inst, pc, data); break;
		case 0xb0fd: db0fd(&inst, pc, data); break;

			// OP_NEWTABLE 10 : A B C
		case 0x11f5: d11f5(&inst, pc, data); break;
		case 0x1ab3: d1ab3(&inst, pc, data); break;
		case 0x6a43: d6a43(&inst, pc, data); break;

			// OP_SELF 11 : A B C
		case 0x59c0: d59c0(&inst, pc, data); break;
		case 0x74f7: d74f7(&inst, pc, data); break;
		case 0xbc27: dbc27(&inst, pc, data); break;
		case 0xc3d0: dc3d0(&inst, pc, data); break;
		case 0xcbbc: dcbbc(&inst, pc, data); break;
		case 0xe478: de478(&inst, pc, data); break;
		case 0xe7a4: de7a4(&inst, pc, data); break;

			// OP_ADD 12 : A B C
		case 0x0f0e: d0f0e(&inst, pc, data); break;
		case 0x21f2: d21f2(&inst, pc, data); break;
		case 0x36d2: d36d2(&inst, pc, data); break;
		case 0x5372: d5372(&inst, pc, data); break;
		case 0x85d6: d85d6(&inst, pc, data); break;
		case 0x993e: d993e(&inst, pc, data); break;
		case 0xaa16: daa16(&inst, pc, data); break;
		case 0xf3a0: df3a0(&inst, pc, data); break;

			// OP_SUB 13 : A B C
		case 0x4d6c: d4d6c(&inst, pc, data); break;
		case 0x4dad: d4dad(&inst, pc, data); break;
		case 0xa360: da360(&inst, pc, data); break;

			// OP_MUL 14 : A B C
		case 0x176f: d176f(&inst, pc, data); break;
		case 0x1b3c: d1b3c(&inst, pc, data); break;
		case 0x1ce4: d1ce4(&inst, pc, data); break;
		case 0x4e35: d4e35(&inst, pc, data); break;
		case 0x5235: d5235(&inst, pc, data); break;
		case 0x8131: d8131(&inst, pc, data); break;
		case 0xd41e: dd41e(&inst, pc, data); break;
		case 0xe7b8: de7b8(&inst, pc, data); break;

			// OP_DIV 15 : A B C
		case 0x0c84: d0c84(&inst, pc, data); break;
		case 0x4223: d4223(&inst, pc, data); break;
		case 0x4281: d4281(&inst, pc, data); break;
		case 0x73f0: d73f0(&inst, pc, data); break;
		case 0xa2de: da2de(&inst, pc, data); break;
		case 0xad9d: dad9d(&inst, pc, data); break;
		case 0xb5be: db5be(&inst, pc, data); break;
		case 0xc9c9: dc9c9(&inst, pc, data); break;
		case 0xd601: dd601(&inst, pc, data); break;

			// OP_MOD 16 : A B C
		case 0x34b9: d34b9(&inst, pc, data); break;
		case 0x84be: d84be(&inst, pc, data); break;
		case 0xb178: db178(&inst, pc, data); break;
		case 0xc168: dc168(&inst, pc, data); break;
			case 0xf7b9: df7b9(&inst, pc, data); break;

		// OP_POW 17 : A B C
		case 0x4cba: d4cba(&inst, pc, data); break;
			case 0x52c9: d52c9(&inst, pc, data); break;
		case 0x57a7: d57a7(&inst, pc, data); break;
		case 0x5bf1: d5bf1(&inst, pc, data); break;
		case 0x750e: d750e(&inst, pc, data); break;
			case 0x784a: d784a(&inst, pc, data); break;
		case 0xc602: dc602(&inst, pc, data); break;
		case 0xf9f0: df9f0(&inst, pc, data); break;
		case 0xfe5d: dfe5d(&inst, pc, data); break;

			// OP_UNM 18 : A B 
		case 0x1eb3: d1eb3(&inst, pc, data); break;
		case 0x40b9: d40b9(&inst, pc, data); break;
		case 0x59d1: d59d1(&inst, pc, data); break;
		case 0xc48b: dc48b(&inst, pc, data); break;

			// OP_NOT 19 : A B 
		case 0x072d: d072d(&inst, pc, data); break;
		case 0x41ac: d41ac(&inst, pc, data); break;
		case 0x87ee: d87ee(&inst, pc, data); break;
		case 0xeb86: deb86(&inst, pc, data); break;

			// OP_LEN 20 : A B 
		case 0x737c: d737c(&inst, pc, data); break;
		case 0x974d: d974d(&inst, pc, data); break;
		case 0xcc31: dcc31(&inst, pc, data); break;
		case 0xf59f: df59f(&inst, pc, data); break;

			// OP_CONCAT 21 : A B C
		case 0x5011: d5011(&inst, pc, data); break;
		case 0x8bad: d8bad(&inst, pc, data); break;
		case 0xf5c5: df5c5(&inst, pc, data); break;

			// OP_JMP 22 : sBx  
		case 0x0134: d0134(&inst, pc, data); break;
		case 0x8f95: d8f95(&inst, pc, data); break;
		case 0x9573: d9573(&inst, pc, data); break;
		case 0xbc60: dbc60(&inst, pc, data); break;
		case 0xcd4f: dcd4f(&inst, pc, data); break;
		case 0xdb27: ddb27(&inst, pc, data); break;
		case 0xf553: df553(&inst, pc, data); break;
		case 0xfdb9: dfdb9(&inst, pc, data); break;

			// OP_EQ 23 : A B C
		case 0x346b: d346b(&inst, pc, data); break;
		case 0x4033: d4033(&inst, pc, data); break;
		case 0x55b2: d55b2(&inst, pc, data); break;
		case 0x733e: d733e(&inst, pc, data); break;
		case 0x7eb6: d7eb6(&inst, pc, data); break;
		case 0x83ec: d83ec(&inst, pc, data); break;
		case 0x8b4d: d8b4d(&inst, pc, data); break;
		case 0xc7f9: dc7f9(&inst, pc, data); break;

			// OP_LT 24 : A B C
		case 0x2e99: d2e99(&inst, pc, data); break;
		case 0x4860: d4860(&inst, pc, data); break;
		case 0x9d2d: d9d2d(&inst, pc, data); break;

			// OP_LE 25 : A B C
		case 0x1f6b: d1f6b(&inst, pc, data); break;
		case 0x2de8: d2de8(&inst, pc, data); break;
		case 0xc39b: dc39b(&inst, pc, data); break;
		case 0xccf9: dccf9(&inst, pc, data); break;
		case 0xceda: dceda(&inst, pc, data); break;
		case 0xdd85: ddd85(&inst, pc, data); break;
		case 0xefdd: defdd(&inst, pc, data); break;

			// OP_TEST 26 : A C 
		case 0x1c23: d1c23(&inst, pc, data); break;
		case 0x4c2a: d4c2a(&inst, pc, data); break;
		case 0x5702: d5702(&inst, pc, data); break;

			// OP_TESTSET 27 : A B C
		case 0x453c: d453c(&inst, pc, data); break;
		case 0x716d: d716d(&inst, pc, data); break;
		case 0x77ff: d77ff(&inst, pc, data); break;
		case 0xdc9e: ddc9e(&inst, pc, data); break;

			// OP_CALL 28 : A B C
		case 0x05cd: d05cd(&inst, pc, data); break;
		case 0x4075: d4075(&inst, pc, data); break;
		case 0x5207: d5207(&inst, pc, data); break;
		case 0x6ad1: d6ad1(&inst, pc, data); break;
		case 0x9016: d9016(&inst, pc, data); break;
		case 0x9773: d9773(&inst, pc, data); break;
		case 0x9cc4: d9cc4(&inst, pc, data); break;
		case 0xb621: db621(&inst, pc, data); break;
		case 0xc2cf: dc2cf(&inst, pc, data); break;

			// OP_RETURN 30 : A B 
		case 0x822d: d822d(&inst, pc, data); break;
		case 0xf113: df113(&inst, pc, data); break;
		case 0xf62e: df62e(&inst, pc, data); break;

			// OP_FORLOOP 31 : A sBx 
		case 0x08a0: d08a0(&inst, pc, data); break;
		case 0x0ecb: d0ecb(&inst, pc, data); break;
		case 0x3d7f: d3d7f(&inst, pc, data); break;
		case 0x4453: d4453(&inst, pc, data); break;
		case 0x6d36: d6d36(&inst, pc, data); break;
		case 0x90dd: d90dd(&inst, pc, data); break;
		case 0xd7d9: dd7d9(&inst, pc, data); break;

			// OP_FORPREP 32 : A sBx 
		case 0x0541: d0541(&inst, pc, data); break;
		case 0x5b47: d5b47(&inst, pc, data); break;
		case 0x6255: d6255(&inst, pc, data); break;
		case 0x8ee2: d8ee2(&inst, pc, data); break;
		case 0xa88e: da88e(&inst, pc, data); break;
		case 0xb1bf: db1bf(&inst, pc, data); break;
		case 0xf908: df908(&inst, pc, data); break;

			// OP_TFORLOOP 33 : A C 
		case 0x2841: d2841(&inst, pc, data); break;
		case 0x2d58: d2d58(&inst, pc, data); break;
		case 0x34cb: d34cb(&inst, pc, data); break;
		case 0x8fd9: d8fd9(&inst, pc, data); break;
		case 0x9123: d9123(&inst, pc, data); break;
		case 0xf48e: df48e(&inst, pc, data); break;

			// OP_SETLIST 34 : A B C
		case 0x9782: d9782(&inst, pc, data); break;
		case 0xee53: dee53(&inst, pc, data); break;
		case 0xfe27: dfe27(&inst, pc, data); break;

			// OP_CLOSE 35 : A  
		case 0x3ec6: d3ec6(&inst, pc, data); break;
		case 0x3faa: d3faa(&inst, pc, data); break;
		case 0xdf96: ddf96(&inst, pc, data); break;

			// OP_CLOSURE 36 : A Bx 
		case 0x0800: d0800(&inst, pc, data); break;
		case 0x2709: d2709(&inst, pc, data); break;
		case 0x3174: d3174(&inst, pc, data); break;
		case 0x4f85: d4f85(&inst, pc, data); break;
		case 0x5626: d5626(&inst, pc, data); break;

			// OP_VARARG 37 : A B 
		case 0x1189: d1189(&inst, pc, data); break;
		case 0x2fc8: d2fc8(&inst, pc, data); break;
		case 0x4cd2: d4cd2(&inst, pc, data); break;
		case 0x4d36: d4d36(&inst, pc, data); break;
		case 0xbaf8: dbaf8(&inst, pc, data); break;
			case 0xc83e: dc83e(&inst, pc, data); break;
			case 0xd77e: dd77e(&inst, pc, data); break;
		case 0xde58: dde58(&inst, pc, data); break;
			case 0xf5fc: df5fc(&inst, pc, data); break;
		}

		return inst;
	}
}

uint serializeInstr(instr inst) {
	uint opmode = opmodeMap[inst.OP];
	uint res = 0;

	if (opmode == 0) {
		res = res | (inst.OP & 63);
		res = res | ((inst.A & 255) << 6);
		res = res | ((inst.C & 511) << 14);
		res = res | ((inst.B & 511) << 23);
	}else if(opmode == 1){
		res = res | (inst.OP & 63);
		res = res | ((inst.A & 255) << 6);
		res = res | ((inst.Bx & 262143) << 14);
	}else if (opmode == 2) {
		res = res | (inst.OP & 63);
		res = res | ((inst.A & 255) << 6);
		res = res | ((inst.sBx & 262143) << 14);
	}

	return res;
}

int secdec(lua_State* L) {
	std::string vmName = lua_tostring(L, 1);
	uint pc = lua_tonumber(L, 2);
	uint key = lua_tonumber(L, 3);
	uint data = lua_tonumber(L, 4);
	//std::cout << vmName << ": " << pc << ") " << key << " -> " << data << std::endl;

	instr result;

	if (vmName == "Alpha") {
		result = Alpha::decrypt(pc, key, data);
	}

	lua_pushnumber(L, serializeInstr(result));

	return 1;
}

int main()
{
    lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	const char* scr = R""""(
local file = io.open("sec.lua", "r")

-- sets the default input file as test.lua
io.input(file)

-- prints the first line of the file
local f = io.read("*a")

-- closes the open file
io.close(file)

local s,e = pcall(load(f))
print(s,e)
)"""";

	lua_pushcfunction(L, secdec);
	lua_setglobal(L, "secdec");

	luaL_loadstring(L, scr);
	lua_call(L,0,0);

	return 0;
}