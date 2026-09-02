#include "hydrothunder_init.h"

DEFINE_REX_FUNC(sub_827E3238) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a1c80
	ctx.lr = 0x827E3240;
	__savegprlr_14(ctx, base);
	// stwu r1,-1024(r1)
	ea = -1024 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,1392(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 1392);
	// stw r5,1060(r1)
	REX_STORE_U32(ctx.r1.u32 + 1060, ctx.r5.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lwz r6,1312(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1312);
	// beq cr6,0x827e326c
	if (ctx.cr6.eq) goto loc_827E326C;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// bne cr6,0x827e3270
	if (!ctx.cr6.eq) goto loc_827E3270;
loc_827E326C:
	// li r11,1
	ctx.r11.s64 = 1;
loc_827E3270:
	// stw r4,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r4.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r4.u32);
	// sth r4,16(r5)
	REX_STORE_U16(ctx.r5.u32 + 16, ctx.r4.u16);
	// stw r11,628(r1)
	REX_STORE_U32(ctx.r1.u32 + 628, ctx.r11.u32);
	// lwz r11,616(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 616);
	// stw r11,36(r5)
	REX_STORE_U32(ctx.r5.u32 + 36, ctx.r11.u32);
	// lwz r10,428(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// stw r10,40(r5)
	REX_STORE_U32(ctx.r5.u32 + 40, ctx.r10.u32);
	// lwz r9,1164(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1164);
	// stw r9,44(r5)
	REX_STORE_U32(ctx.r5.u32 + 44, ctx.r9.u32);
	// lhz r7,52(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// subfic r10,r11,2
	ctx.xer.ca = ctx.r11.u32 <= 2;
	ctx.r10.u64 = static_cast<uint64_t>(2) - ctx.r11.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r8,74(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// rlwinm r30,r7,31,1,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r7,76(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r29,r9,31,1,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r4,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, ctx.r4.u32);
	// stw r4,604(r1)
	REX_STORE_U32(ctx.r1.u32 + 604, ctx.r4.u32);
	// stw r30,716(r1)
	REX_STORE_U32(ctx.r1.u32 + 716, ctx.r30.u32);
	// stw r29,632(r1)
	REX_STORE_U32(ctx.r1.u32 + 632, ctx.r29.u32);
	// stw r10,720(r1)
	REX_STORE_U32(ctx.r1.u32 + 720, ctx.r10.u32);
	// stw r10,448(r1)
	REX_STORE_U32(ctx.r1.u32 + 448, ctx.r10.u32);
	// beq cr6,0x827e32ec
	if (ctx.cr6.eq) goto loc_827E32EC;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,448(r1)
	REX_STORE_U32(ctx.r1.u32 + 448, ctx.r10.u32);
loc_827E32EC:
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r9,268(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// stw r4,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r9,444(r1)
	REX_STORE_U32(ctx.r1.u32 + 444, ctx.r9.u32);
	// beq cr6,0x827e89c8
	if (ctx.cr6.eq) goto loc_827E89C8;
	// rlwinm r11,r8,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r14,108(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r15,104(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r9,r6,-8
	ctx.r9.s64 = ctx.r6.s64 + -8;
	// stw r11,712(r1)
	REX_STORE_U32(ctx.r1.u32 + 712, ctx.r11.u32);
	// stw r10,724(r1)
	REX_STORE_U32(ctx.r1.u32 + 724, ctx.r10.u32);
	// stw r9,624(r1)
	REX_STORE_U32(ctx.r1.u32 + 624, ctx.r9.u32);
	// b 0x827e3348
	goto loc_827E3348;
loc_827E333C:
	// lwz r5,1060(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,632(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 632);
loc_827E3348:
	// lwz r11,592(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 592);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r10,604(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 604);
	// stw r4,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r4.u32);
	// sth r4,18(r5)
	REX_STORE_U16(ctx.r5.u32 + 18, ctx.r4.u16);
	// stw r11,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
	// stw r10,12(r5)
	REX_STORE_U32(ctx.r5.u32 + 12, ctx.r10.u32);
	// beq cr6,0x827e8970
	if (ctx.cr6.eq) goto loc_827E8970;
loc_827E3368:
	// lwz r11,1060(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// lwz r10,624(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 624);
	// lwz r16,348(r31)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lwz r18,0(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// ldu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// rlwinm r9,r18,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r16,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r16.u32);
	// stw r18,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r18.u32);
	// stw r10,624(r1)
	REX_STORE_U32(ctx.r1.u32 + 624, ctx.r10.u32);
	// lwzx r8,r9,r16
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r16.u32);
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e890c
	if (ctx.cr6.eq) goto loc_827E890C;
	// rldicl r11,r11,9,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 9) & 0x1FF;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e7170
	if (ctx.cr6.eq) goto loc_827E7170;
	// lwz r11,444(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 444);
	// lwz r10,1060(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// lhz r17,50(r31)
	ctx.r17.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r19,r9,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r7,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x7;
	// stw r17,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r17.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r6,468(r1)
	REX_STORE_U32(ctx.r1.u32 + 468, ctx.r6.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// stw r11,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r11.u32);
	// bgt cr6,0x827e5c24
	if (ctx.cr6.gt) goto loc_827E5C24;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e5270
	if (ctx.cr6.eq) goto loc_827E5270;
	// bdz 0x827e3df4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_827E3DF4;
	// bdz 0x827e487c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_827E487C;
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,1840(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// lwz r24,1836(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// srawi r21,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r17.s32 >> 1;
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r22,0(r28)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r22,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// bne cr6,0x827e3454
	if (!ctx.cr6.eq) goto loc_827E3454;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e3448
	if (ctx.cr6.eq) goto loc_827E3448;
	// srawi r11,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e3454
	if (ctx.cr6.eq) goto loc_827E3454;
loc_827E3448:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r20,0
	ctx.r20.s64 = 0;
	// b 0x827e345c
	goto loc_827E345C;
loc_827E3454:
	// li r20,0
	ctx.r20.s64 = 0;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
loc_827E345C:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// lis r9,-32134
	ctx.r9.s64 = -2105933824;
	// stw r20,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r20.u32);
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r20,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r20.u32);
	// lis r15,1
	ctx.r15.s64 = 65536;
	// stw r20,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r20.u32);
	// srawi r23,r22,16
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0xFFFF) != 0);
	ctx.r23.s64 = ctx.r22.s32 >> 16;
	// stw r20,388(r1)
	REX_STORE_U32(ctx.r1.u32 + 388, ctx.r20.u32);
	// addi r7,r10,-27024
	ctx.r7.s64 = ctx.r10.s64 + -27024;
	// stw r20,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r20.u32);
	// addi r6,r9,-26744
	ctx.r6.s64 = ctx.r9.s64 + -26744;
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r23.u32);
	// subf r5,r8,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r8.u64;
	// stw r7,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r7.u32);
	// stw r6,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r6.u32);
	// mr r27,r20
	ctx.r27.u64 = ctx.r20.u64;
	// stw r5,392(r1)
	REX_STORE_U32(ctx.r1.u32 + 392, ctx.r5.u32);
	// mr r26,r20
	ctx.r26.u64 = ctx.r20.u64;
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x827e352c
	if (ctx.cr6.eq) goto loc_827E352C;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,146(r1)
	REX_STORE_U16(ctx.r1.u32 + 146, ctx.r10.u16);
	// sth r9,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r9.u16);
	// lwz r4,144(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e352c
	if (ctx.cr6.eq) goto loc_827E352C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e350c
	if (ctx.cr6.eq) goto loc_827E350C;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r4,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E3500;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x827e3528
	goto loc_827E3528;
loc_827E350C:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E3520;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
loc_827E3528:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E352C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x827e3650
	if (!ctx.cr6.eq) goto loc_827E3650;
	// subf r29,r17,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r17.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r24,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// sth r10,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r10.u16);
	// sth r9,146(r1)
	REX_STORE_U16(ctx.r1.u32 + 146, ctx.r9.u16);
	// lwz r4,144(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e35b8
	if (ctx.cr6.eq) goto loc_827E35B8;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r14,r30,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3590
	if (ctx.cr6.eq) goto loc_827E3590;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r14,r10
	REX_STORE_U32(ctx.r14.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3584;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x827e35b0
	goto loc_827E35B0;
loc_827E3590:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r14,r10
	REX_STORE_U32(ctx.r14.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E35A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_827E35B0:
	// stwx r3,r14,r9
	REX_STORE_U32(ctx.r14.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_827E35B8:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x827e3650
	if (!ctx.cr6.gt) goto loc_827E3650;
	// addi r11,r17,-2
	ctx.r11.s64 = ctx.r17.s64 + -2;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x827e35d4
	if (!ctx.cr6.eq) goto loc_827E35D4;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_827E35D4:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,146(r1)
	REX_STORE_U16(ctx.r1.u32 + 146, ctx.r10.u16);
	// sth r9,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r9.u16);
	// lwz r4,144(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e3650
	if (ctx.cr6.eq) goto loc_827E3650;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e362c
	if (ctx.cr6.eq) goto loc_827E362C;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3620;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x827e364c
	goto loc_827E364C;
loc_827E362C:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3644;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_827E364C:
	// stwx r3,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E3650:
	// add r11,r26,r27
	ctx.r11.u64 = ctx.r26.u64 + ctx.r27.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e37d4
	if (!ctx.cr6.gt) goto loc_827E37D4;
	// lhz r11,234(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 234);
	// lhz r10,230(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 230);
	// lhz r9,226(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 226);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,232(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 232);
	// extsh r25,r9
	ctx.r25.s64 = ctx.r9.s16;
	// lhz r7,228(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 228);
	// lhz r6,224(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 224);
	// extsh r24,r8
	ctx.r24.s64 = ctx.r8.s16;
	// lhz r5,394(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 394);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,390(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 390);
	// subf r10,r25,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r25.u64;
	// lhz r11,386(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 386);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r8,392(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 392);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,388(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 388);
	// subf r7,r25,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r25.u64;
	// lhz r21,384(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 384);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r24,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r24.u64;
	// subf r4,r22,r24
	ctx.r4.u64 = ctx.r24.u64 - ctx.r22.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 & ctx.r25.u64;
	// lwz r25,112(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 & ~ctx.r25.u64;
	// or r24,r7,r6
	ctx.r24.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r24
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r24.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r23,108(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r17,164(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// li r20,0
	ctx.r20.s64 = 0;
	// lwz r18,160(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r16,100(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r22,104(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// sth r5,458(r1)
	REX_STORE_U16(ctx.r1.u32 + 458, ctx.r5.u16);
	// sth r4,456(r1)
	REX_STORE_U16(ctx.r1.u32 + 456, ctx.r4.u16);
	// sth r11,482(r1)
	REX_STORE_U16(ctx.r1.u32 + 482, ctx.r11.u16);
	// sth r10,480(r1)
	REX_STORE_U16(ctx.r1.u32 + 480, ctx.r10.u16);
	// b 0x827e3800
	goto loc_827E3800;
loc_827E37D4:
	// bne cr6,0x827e37ec
	if (!ctx.cr6.eq) goto loc_827E37EC;
	// lwz r11,224(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 224);
	// lwz r10,384(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// stw r11,456(r1)
	REX_STORE_U32(ctx.r1.u32 + 456, ctx.r11.u32);
	// stw r10,480(r1)
	REX_STORE_U32(ctx.r1.u32 + 480, ctx.r10.u32);
	// b 0x827e3800
	goto loc_827E3800;
loc_827E37EC:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r20,456(r1)
	REX_STORE_U32(ctx.r1.u32 + 456, ctx.r20.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r15
	ctx.r9.u64 = ctx.r15.u64 - ctx.r10.u64;
	// stw r9,480(r1)
	REX_STORE_U32(ctx.r1.u32 + 480, ctx.r9.u32);
loc_827E3800:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e381c
	if (ctx.cr6.eq) goto loc_827E381C;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x827e3828
	if (!ctx.cr6.gt) goto loc_827E3828;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e382c
	if (!ctx.cr6.eq) goto loc_827E382C;
loc_827E381C:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e382c
	if (ctx.cr6.eq) goto loc_827E382C;
loc_827E3828:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E382C:
	// clrlwi r11,r23,31
	ctx.r11.u64 = ctx.r23.u32 & 0x1;
	// lwz r9,480(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 480);
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x827e3844
	if (!ctx.cr6.eq) goto loc_827E3844;
	// lwz r9,456(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 456);
loc_827E3844:
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r7,66(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// lhz r8,62(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// add r11,r17,r18
	ctx.r11.u64 = ctx.r17.u64 + ctx.r18.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// stw r6,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lhz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 144);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// lhz r7,146(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 146);
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r29,r18,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r22
	ctx.r6.u64 = ctx.r10.u64 + ctx.r22.u64;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r4,r3,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r3.u64;
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,2(r28)
	REX_STORE_U16(ctx.r28.u32 + 2, ctx.r3.u16);
	// mr r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	// lwz r10,1836(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// sth r3,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r3.u16);
	// lwz r7,1836(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r3,r7,r30
	REX_STORE_U16(ctx.r7.u32 + ctx.r30.u32, ctx.r3.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r6,r10,r29
	ctx.r6.u64 = ctx.r10.u64 + ctx.r29.u64;
	// sth r3,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r3.u16);
	// lwz r5,1836(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r3,r5,r29
	REX_STORE_U16(ctx.r5.u32 + ctx.r29.u32, ctx.r3.u16);
	// lhz r4,68(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// lhz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r14,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r14.u32);
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// add r7,r10,r23
	ctx.r7.u64 = ctx.r10.u64 + ctx.r23.u64;
	// and r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 & ctx.r8.u64;
	// subf r4,r3,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r3.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,0(r28)
	REX_STORE_U16(ctx.r28.u32 + 0, ctx.r3.u16);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// lwz r10,1840(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// sth r3,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r3.u16);
	// lwz r8,1840(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r3,r8,r30
	REX_STORE_U16(ctx.r8.u32 + ctx.r30.u32, ctx.r3.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// sth r3,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r3.u16);
	// lwz r6,1840(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r3,r6,r29
	REX_STORE_U16(ctx.r6.u32 + ctx.r29.u32, ctx.r3.u16);
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r5,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r5.u32);
	// lhz r27,50(r31)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// srawi r21,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r27.s32 >> 1;
	// lwz r25,1848(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r24,1844(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r3,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bne cr6,0x827e3984
	if (!ctx.cr6.eq) goto loc_827E3984;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e397c
	if (ctx.cr6.eq) goto loc_827E397C;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e3984
	if (ctx.cr6.eq) goto loc_827E3984;
loc_827E397C:
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x827e3988
	goto loc_827E3988;
loc_827E3984:
	// mr r26,r20
	ctx.r26.u64 = ctx.r20.u64;
loc_827E3988:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,1372(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1372);
	// mr r22,r20
	ctx.r22.u64 = ctx.r20.u64;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r20,264(r1)
	REX_STORE_U32(ctx.r1.u32 + 264, ctx.r20.u32);
	// stw r20,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r20.u32);
	// mr r23,r20
	ctx.r23.u64 = ctx.r20.u64;
	// subf r7,r8,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r8.u64;
	// stw r20,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r20.u32);
	// stw r20,356(r1)
	REX_STORE_U32(ctx.r1.u32 + 356, ctx.r20.u32);
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
	// stw r20,352(r1)
	REX_STORE_U32(ctx.r1.u32 + 352, ctx.r20.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r7,360(r1)
	REX_STORE_U32(ctx.r1.u32 + 360, ctx.r7.u32);
	// stw r20,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r20.u32);
	// bne cr6,0x827e39e0
	if (!ctx.cr6.eq) goto loc_827E39E0;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27712
	ctx.r9.s64 = ctx.r11.s64 + -27712;
	// addi r8,r10,-27304
	ctx.r8.s64 = ctx.r10.s64 + -27304;
	// b 0x827e39f0
	goto loc_827E39F0;
loc_827E39E0:
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27584
	ctx.r9.s64 = ctx.r11.s64 + -27584;
	// addi r8,r10,-27648
	ctx.r8.s64 = ctx.r10.s64 + -27648;
loc_827E39F0:
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stw r8,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// rlwinm r20,r11,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x827e3a80
	if (ctx.cr6.eq) goto loc_827E3A80;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,154(r1)
	REX_STORE_U16(ctx.r1.u32 + 154, ctx.r10.u16);
	// sth r9,152(r1)
	REX_STORE_U16(ctx.r1.u32 + 152, ctx.r9.u16);
	// lwz r4,152(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e3a80
	if (ctx.cr6.eq) goto loc_827E3A80;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3a60
	if (ctx.cr6.eq) goto loc_827E3A60;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,352(r1)
	REX_STORE_U32(ctx.r1.u32 + 352, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E3A50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r22,1
	ctx.r22.s64 = 1;
	// stw r3,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e3a7c
	goto loc_827E3A7C;
loc_827E3A60:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E3A74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,352(r1)
	REX_STORE_U32(ctx.r1.u32 + 352, ctx.r3.u32);
	// li r23,1
	ctx.r23.s64 = 1;
loc_827E3A7C:
	// li r28,1
	ctx.r28.s64 = 1;
loc_827E3A80:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x827e3bac
	if (!ctx.cr6.eq) goto loc_827E3BAC;
	// subf r26,r27,r18
	ctx.r26.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r24,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// sth r10,152(r1)
	REX_STORE_U16(ctx.r1.u32 + 152, ctx.r10.u16);
	// sth r9,154(r1)
	REX_STORE_U16(ctx.r1.u32 + 154, ctx.r9.u16);
	// lwz r4,152(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e3b10
	if (ctx.cr6.eq) goto loc_827E3B10;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r19,r28,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3ae8
	if (ctx.cr6.eq) goto loc_827E3AE8;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r19,r10
	REX_STORE_U32(ctx.r19.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3AD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e3b08
	goto loc_827E3B08;
loc_827E3AE8:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r19,r10
	REX_STORE_U32(ctx.r19.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3B00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_827E3B08:
	// stwx r3,r19,r9
	REX_STORE_U32(ctx.r19.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_827E3B10:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x827e3bac
	if (!ctx.cr6.gt) goto loc_827E3BAC;
	// addi r11,r27,-2
	ctx.r11.s64 = ctx.r27.s64 + -2;
	// cmpw cr6,r20,r11
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r26,2
	ctx.r11.s64 = ctx.r26.s64 + 2;
	// bne cr6,0x827e3b2c
	if (!ctx.cr6.eq) goto loc_827E3B2C;
	// addi r11,r26,-2
	ctx.r11.s64 = ctx.r26.s64 + -2;
loc_827E3B2C:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,154(r1)
	REX_STORE_U16(ctx.r1.u32 + 154, ctx.r10.u16);
	// sth r9,152(r1)
	REX_STORE_U16(ctx.r1.u32 + 152, ctx.r9.u16);
	// lwz r4,152(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e3bac
	if (ctx.cr6.eq) goto loc_827E3BAC;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3b88
	if (ctx.cr6.eq) goto loc_827E3B88;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r28,r10
	REX_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3B78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e3ba8
	goto loc_827E3BA8;
loc_827E3B88:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r28,r10
	REX_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3BA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_827E3BA8:
	// stwx r3,r28,r9
	REX_STORE_U32(ctx.r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E3BAC:
	// add r11,r22,r23
	ctx.r11.u64 = ctx.r22.u64 + ctx.r23.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e3d24
	if (!ctx.cr6.gt) goto loc_827E3D24;
	// lhz r11,266(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 266);
	// lhz r10,262(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 262);
	// lhz r9,258(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 258);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// extsh r27,r10
	ctx.r27.s64 = ctx.r10.s16;
	// lhz r8,264(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 264);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,260(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 260);
	// lhz r6,256(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 256);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// lhz r5,362(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 362);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,358(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 358);
	// subf r10,r26,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r26.u64;
	// lhz r11,354(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 354);
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// lhz r8,360(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 360);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,356(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 356);
	// subf r7,r26,r28
	ctx.r7.u64 = ctx.r28.u64 - ctx.r26.u64;
	// lhz r21,352(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 352);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r22.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// subf r4,r22,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r22.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// lwz r26,112(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// andc r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 & ~ctx.r20.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 | ctx.r10.u64;
	// and r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r28,r18,r25
	ctx.r28.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r27,r15,r22
	ctx.r27.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r28,r6
	ctx.r9.u64 = ctx.r28.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r27,r4
	ctx.r7.u64 = ctx.r27.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r15,104(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,108(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r22,96(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// sth r5,514(r1)
	REX_STORE_U16(ctx.r1.u32 + 514, ctx.r5.u16);
	// sth r4,512(r1)
	REX_STORE_U16(ctx.r1.u32 + 512, ctx.r4.u16);
	// sth r11,506(r1)
	REX_STORE_U16(ctx.r1.u32 + 506, ctx.r11.u16);
	// sth r10,504(r1)
	REX_STORE_U16(ctx.r1.u32 + 504, ctx.r10.u16);
	// b 0x827e3d54
	goto loc_827E3D54;
loc_827E3D24:
	// bne cr6,0x827e3d3c
	if (!ctx.cr6.eq) goto loc_827E3D3C;
	// lwz r11,256(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// lwz r10,352(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 352);
	// stw r11,512(r1)
	REX_STORE_U32(ctx.r1.u32 + 512, ctx.r11.u32);
	// stw r10,504(r1)
	REX_STORE_U32(ctx.r1.u32 + 504, ctx.r10.u32);
	// b 0x827e3d54
	goto loc_827E3D54;
loc_827E3D3C:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,512(r1)
	REX_STORE_U32(ctx.r1.u32 + 512, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,504(r1)
	REX_STORE_U32(ctx.r1.u32 + 504, ctx.r8.u32);
loc_827E3D54:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3d70
	if (ctx.cr6.eq) goto loc_827E3D70;
	// cmpw cr6,r23,r22
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x827e3d7c
	if (!ctx.cr6.gt) goto loc_827E3D7C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e3d80
	if (!ctx.cr6.eq) goto loc_827E3D80;
loc_827E3D70:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3d80
	if (ctx.cr6.eq) goto loc_827E3D80;
loc_827E3D7C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E3D80:
	// lwz r11,504(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 504);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827e3d90
	if (!ctx.cr6.eq) goto loc_827E3D90;
	// lwz r11,512(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 512);
loc_827E3D90:
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r9,1844(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r11,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r11.u32);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 100);
	// sth r11,2(r9)
	REX_STORE_U16(ctx.r9.u32 + 2, ctx.r11.u16);
	// lwz r8,1844(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r11,r8,r30
	REX_STORE_U16(ctx.r8.u32 + ctx.r30.u32, ctx.r11.u16);
	// lwz r9,1844(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// add r7,r9,r29
	ctx.r7.u64 = ctx.r9.u64 + ctx.r29.u64;
	// sth r11,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r11.u16);
	// lwz r6,1844(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r11,r6,r29
	REX_STORE_U16(ctx.r6.u32 + ctx.r29.u32, ctx.r11.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r5,r30,r11
	ctx.r5.u64 = ctx.r30.u64 + ctx.r11.u64;
	// sth r10,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r10.u16);
	// lwz r4,1848(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r10,r30,r4
	REX_STORE_U16(ctx.r30.u32 + ctx.r4.u32, ctx.r10.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r3,r29,r11
	ctx.r3.u64 = ctx.r29.u64 + ctx.r11.u64;
	// sth r10,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r10.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r10,r29,r11
	REX_STORE_U16(ctx.r29.u32 + ctx.r11.u32, ctx.r10.u16);
	// b 0x827e5c24
	goto loc_827E5C24;
loc_827E3DF4:
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,1840(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// clrlwi r20,r10,31
	ctx.r20.u64 = ctx.r10.u32 & 0x1;
	// lwz r24,1836(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// stw r20,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r20.u32);
	// srawi r21,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r17.s32 >> 1;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwzx r23,r11,r16
	ctx.r23.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r23,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r23.u32);
	// stw r11,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// bne cr6,0x827e3e54
	if (!ctx.cr6.eq) goto loc_827E3E54;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e3e48
	if (ctx.cr6.eq) goto loc_827E3E48;
	// srawi r11,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e3e54
	if (ctx.cr6.eq) goto loc_827E3E54;
loc_827E3E48:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r15,0
	ctx.r15.s64 = 0;
	// b 0x827e3e5c
	goto loc_827E3E5C;
loc_827E3E54:
	// li r15,0
	ctx.r15.s64 = 0;
	// mr r29,r15
	ctx.r29.u64 = ctx.r15.u64;
loc_827E3E5C:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// lis r9,-32134
	ctx.r9.s64 = -2105933824;
	// stw r15,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r15.u32);
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r15,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r15.u32);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stw r15,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r15.u32);
	// srawi r22,r23,16
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0xFFFF) != 0);
	ctx.r22.s64 = ctx.r23.s32 >> 16;
	// stw r15,420(r1)
	REX_STORE_U32(ctx.r1.u32 + 420, ctx.r15.u32);
	// addi r6,r10,-27024
	ctx.r6.s64 = ctx.r10.s64 + -27024;
	// stw r15,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r15.u32);
	// addi r5,r9,-26744
	ctx.r5.s64 = ctx.r9.s64 + -26744;
	// stw r22,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r22.u32);
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// stw r6,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r6.u32);
	// stw r5,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r5.u32);
	// mr r27,r15
	ctx.r27.u64 = ctx.r15.u64;
	// stw r4,424(r1)
	REX_STORE_U32(ctx.r1.u32 + 424, ctx.r4.u32);
	// mr r26,r15
	ctx.r26.u64 = ctx.r15.u64;
	// mr r30,r15
	ctx.r30.u64 = ctx.r15.u64;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x827e3f2c
	if (ctx.cr6.eq) goto loc_827E3F2C;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// sth r9,140(r1)
	REX_STORE_U16(ctx.r1.u32 + 140, ctx.r9.u16);
	// sth r10,142(r1)
	REX_STORE_U16(ctx.r1.u32 + 142, ctx.r10.u16);
	// lwz r4,140(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e3f2c
	if (ctx.cr6.eq) goto loc_827E3F2C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3f0c
	if (ctx.cr6.eq) goto loc_827E3F0C;
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r4,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E3F00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x827e3f28
	goto loc_827E3F28;
loc_827E3F0C:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E3F20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
loc_827E3F28:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E3F2C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x827e4050
	if (!ctx.cr6.eq) goto loc_827E4050;
	// subf r29,r17,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r17.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,142(r1)
	REX_STORE_U16(ctx.r1.u32 + 142, ctx.r10.u16);
	// sth r9,140(r1)
	REX_STORE_U16(ctx.r1.u32 + 140, ctx.r9.u16);
	// lwz r4,140(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e3fb8
	if (ctx.cr6.eq) goto loc_827E3FB8;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r14,r30,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e3f90
	if (ctx.cr6.eq) goto loc_827E3F90;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r14,r10
	REX_STORE_U32(ctx.r14.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3F84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x827e3fb0
	goto loc_827E3FB0;
loc_827E3F90:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r14,r10
	REX_STORE_U32(ctx.r14.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E3FA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_827E3FB0:
	// stwx r3,r14,r9
	REX_STORE_U32(ctx.r14.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_827E3FB8:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x827e4050
	if (!ctx.cr6.gt) goto loc_827E4050;
	// addi r11,r17,-2
	ctx.r11.s64 = ctx.r17.s64 + -2;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x827e3fd4
	if (!ctx.cr6.eq) goto loc_827E3FD4;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_827E3FD4:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,142(r1)
	REX_STORE_U16(ctx.r1.u32 + 142, ctx.r10.u16);
	// sth r9,140(r1)
	REX_STORE_U16(ctx.r1.u32 + 140, ctx.r9.u16);
	// lwz r4,140(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4050
	if (ctx.cr6.eq) goto loc_827E4050;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e402c
	if (ctx.cr6.eq) goto loc_827E402C;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x827e404c
	goto loc_827E404C;
loc_827E402C:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4044;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_827E404C:
	// stwx r3,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E4050:
	// add r11,r26,r27
	ctx.r11.u64 = ctx.r26.u64 + ctx.r27.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e41d4
	if (!ctx.cr6.gt) goto loc_827E41D4;
	// lhz r11,202(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 202);
	// lhz r10,198(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 198);
	// lhz r9,194(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 194);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,200(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 200);
	// extsh r25,r9
	ctx.r25.s64 = ctx.r9.s16;
	// lhz r7,196(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 196);
	// lhz r6,192(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 192);
	// extsh r24,r8
	ctx.r24.s64 = ctx.r8.s16;
	// lhz r5,426(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 426);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,422(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 422);
	// subf r10,r25,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r25.u64;
	// lhz r11,418(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 418);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r8,424(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 424);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,420(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 420);
	// subf r7,r25,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r25.u64;
	// lhz r21,416(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 416);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r24,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r24.u64;
	// subf r4,r22,r24
	ctx.r4.u64 = ctx.r24.u64 - ctx.r22.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 & ctx.r25.u64;
	// lwz r25,112(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 & ~ctx.r25.u64;
	// or r24,r7,r6
	ctx.r24.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r24
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r24.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r16,100(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r18,160(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r17,164(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r23,104(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r22,108(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r20,176(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// sth r5,494(r1)
	REX_STORE_U16(ctx.r1.u32 + 494, ctx.r5.u16);
	// sth r4,492(r1)
	REX_STORE_U16(ctx.r1.u32 + 492, ctx.r4.u16);
	// sth r11,522(r1)
	REX_STORE_U16(ctx.r1.u32 + 522, ctx.r11.u16);
	// sth r10,520(r1)
	REX_STORE_U16(ctx.r1.u32 + 520, ctx.r10.u16);
	// b 0x827e4204
	goto loc_827E4204;
loc_827E41D4:
	// bne cr6,0x827e41ec
	if (!ctx.cr6.eq) goto loc_827E41EC;
	// lwz r11,192(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r10,416(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 416);
	// stw r11,492(r1)
	REX_STORE_U32(ctx.r1.u32 + 492, ctx.r11.u32);
	// stw r10,520(r1)
	REX_STORE_U32(ctx.r1.u32 + 520, ctx.r10.u32);
	// b 0x827e4204
	goto loc_827E4204;
loc_827E41EC:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r15,492(r1)
	REX_STORE_U32(ctx.r1.u32 + 492, ctx.r15.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,520(r1)
	REX_STORE_U32(ctx.r1.u32 + 520, ctx.r8.u32);
loc_827E4204:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4220
	if (ctx.cr6.eq) goto loc_827E4220;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x827e422c
	if (!ctx.cr6.gt) goto loc_827E422C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e4230
	if (!ctx.cr6.eq) goto loc_827E4230;
loc_827E4220:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4230
	if (ctx.cr6.eq) goto loc_827E4230;
loc_827E422C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E4230:
	// clrlwi r11,r22,31
	ctx.r11.u64 = ctx.r22.u32 & 0x1;
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,520(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 520);
	// bne cr6,0x827e4248
	if (!ctx.cr6.eq) goto loc_827E4248;
	// lwz r10,492(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 492);
loc_827E4248:
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r8,62(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r7,66(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// rlwinm r30,r18,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// stw r6,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r6.u32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// add r11,r17,r18
	ctx.r11.u64 = ctx.r17.u64 + ctx.r18.u64;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// rlwinm r29,r11,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lhz r10,142(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 142);
	// lhz r3,140(r1)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r1.u32 + 140);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r10,r23
	ctx.r9.u64 = ctx.r10.u64 + ctx.r23.u64;
	// and r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 & ctx.r5.u64;
	// subf r6,r4,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r4.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,2(r28)
	REX_STORE_U16(ctx.r28.u32 + 2, ctx.r5.u16);
	// mr r14,r5
	ctx.r14.u64 = ctx.r5.u64;
	// lwz r10,1836(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + ctx.r29.u64;
	// sth r5,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r5.u16);
	// lwz r3,1836(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r5,r3,r29
	REX_STORE_U16(ctx.r3.u32 + ctx.r29.u32, ctx.r5.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// sth r5,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r5.u16);
	// lwz r9,1836(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r5,r9,r30
	REX_STORE_U16(ctx.r9.u32 + ctx.r30.u32, ctx.r5.u16);
	// lhz r7,68(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// lhz r6,64(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r6
	ctx.r10.s64 = ctx.r6.s16;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r5,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// add r4,r10,r22
	ctx.r4.u64 = ctx.r10.u64 + ctx.r22.u64;
	// and r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 & ctx.r5.u64;
	// subf r9,r6,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r6.u64;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,0(r28)
	REX_STORE_U16(ctx.r28.u32 + 0, ctx.r8.u16);
	// mr r15,r8
	ctx.r15.u64 = ctx.r8.u64;
	// lwz r10,1840(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// sth r8,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r8.u16);
	// lwz r6,1840(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r8,r6,r29
	REX_STORE_U16(ctx.r6.u32 + ctx.r29.u32, ctx.r8.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// sth r8,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r8.u16);
	// lwz r4,1840(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r8,r4,r30
	REX_STORE_U16(ctx.r4.u32 + ctx.r30.u32, ctx.r8.u16);
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// stw r3,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// lhz r27,50(r31)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// srawi r21,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r27.s32 >> 1;
	// lwz r25,1848(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r24,1844(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bne cr6,0x827e4388
	if (!ctx.cr6.eq) goto loc_827E4388;
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e437c
	if (ctx.cr6.eq) goto loc_827E437C;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e4388
	if (ctx.cr6.eq) goto loc_827E4388;
loc_827E437C:
	// li r26,1
	ctx.r26.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// b 0x827e4390
	goto loc_827E4390;
loc_827E4388:
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
loc_827E4390:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,172(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// mr r22,r28
	ctx.r22.u64 = ctx.r28.u64;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// lwz r7,1372(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1372);
	// srawi r19,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r19.s64 = ctx.r9.s32 >> 16;
	// stw r28,328(r1)
	REX_STORE_U32(ctx.r1.u32 + 328, ctx.r28.u32);
	// subf r6,r8,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r8.u64;
	// stw r28,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r28.u32);
	// stw r28,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r28.u32);
	// mr r23,r28
	ctx.r23.u64 = ctx.r28.u64;
	// stw r28,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r28.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r28,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r28.u32);
	// stw r19,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r19.u32);
	// stw r6,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r6.u32);
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// bne cr6,0x827e43f0
	if (!ctx.cr6.eq) goto loc_827E43F0;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27712
	ctx.r9.s64 = ctx.r11.s64 + -27712;
	// addi r8,r10,-27304
	ctx.r8.s64 = ctx.r10.s64 + -27304;
	// b 0x827e4400
	goto loc_827E4400;
loc_827E43F0:
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27584
	ctx.r9.s64 = ctx.r11.s64 + -27584;
	// addi r8,r10,-27648
	ctx.r8.s64 = ctx.r10.s64 + -27648;
loc_827E4400:
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stw r8,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// rlwinm r20,r11,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x827e4490
	if (ctx.cr6.eq) goto loc_827E4490;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,138(r1)
	REX_STORE_U16(ctx.r1.u32 + 138, ctx.r10.u16);
	// sth r9,136(r1)
	REX_STORE_U16(ctx.r1.u32 + 136, ctx.r9.u16);
	// lwz r4,136(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4490
	if (ctx.cr6.eq) goto loc_827E4490;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4470
	if (ctx.cr6.eq) goto loc_827E4470;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E4460;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r22,1
	ctx.r22.s64 = 1;
	// stw r3,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r3.u32);
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e448c
	goto loc_827E448C;
loc_827E4470:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E4484;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// li r23,1
	ctx.r23.s64 = 1;
loc_827E448C:
	// li r28,1
	ctx.r28.s64 = 1;
loc_827E4490:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x827e45bc
	if (!ctx.cr6.eq) goto loc_827E45BC;
	// subf r26,r27,r18
	ctx.r26.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r24,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// sth r10,136(r1)
	REX_STORE_U16(ctx.r1.u32 + 136, ctx.r10.u16);
	// sth r9,138(r1)
	REX_STORE_U16(ctx.r1.u32 + 138, ctx.r9.u16);
	// lwz r4,136(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4520
	if (ctx.cr6.eq) goto loc_827E4520;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r18,r28,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e44f8
	if (ctx.cr6.eq) goto loc_827E44F8;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r18,r10
	REX_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E44E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e4518
	goto loc_827E4518;
loc_827E44F8:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r18,r10
	REX_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4510;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_827E4518:
	// stwx r3,r18,r9
	REX_STORE_U32(ctx.r18.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_827E4520:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x827e45bc
	if (!ctx.cr6.gt) goto loc_827E45BC;
	// addi r11,r27,-2
	ctx.r11.s64 = ctx.r27.s64 + -2;
	// cmpw cr6,r20,r11
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r26,2
	ctx.r11.s64 = ctx.r26.s64 + 2;
	// bne cr6,0x827e453c
	if (!ctx.cr6.eq) goto loc_827E453C;
	// addi r11,r26,-2
	ctx.r11.s64 = ctx.r26.s64 + -2;
loc_827E453C:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,138(r1)
	REX_STORE_U16(ctx.r1.u32 + 138, ctx.r10.u16);
	// sth r9,136(r1)
	REX_STORE_U16(ctx.r1.u32 + 136, ctx.r9.u16);
	// lwz r4,136(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e45bc
	if (ctx.cr6.eq) goto loc_827E45BC;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4598
	if (ctx.cr6.eq) goto loc_827E4598;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r28,r10
	REX_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4588;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e45b8
	goto loc_827E45B8;
loc_827E4598:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r28,r10
	REX_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E45B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_827E45B8:
	// stwx r3,r28,r9
	REX_STORE_U32(ctx.r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E45BC:
	// add r11,r22,r23
	ctx.r11.u64 = ctx.r22.u64 + ctx.r23.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e4738
	if (!ctx.cr6.gt) goto loc_827E4738;
	// lhz r11,330(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 330);
	// lhz r10,326(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 326);
	// lhz r9,322(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 322);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// extsh r27,r10
	ctx.r27.s64 = ctx.r10.s16;
	// lhz r8,328(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 328);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,324(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 324);
	// lhz r6,320(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 320);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// lhz r5,218(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 218);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,214(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 214);
	// subf r10,r26,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r26.u64;
	// lhz r11,210(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 210);
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// lhz r8,216(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 216);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,212(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 212);
	// subf r7,r26,r28
	ctx.r7.u64 = ctx.r28.u64 - ctx.r26.u64;
	// lhz r21,208(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 208);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r22.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// subf r4,r22,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r22.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// lwz r26,112(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// andc r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 & ~ctx.r20.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 | ctx.r10.u64;
	// and r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r7,r7,r17
	ctx.r7.u64 = ctx.r7.u64 & ctx.r17.u64;
	// andc r28,r18,r25
	ctx.r28.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r27,r15,r22
	ctx.r27.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 | ctx.r7.u64;
	// and r8,r6,r16
	ctx.r8.u64 = ctx.r6.u64 & ctx.r16.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r27,r4
	ctx.r7.u64 = ctx.r27.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r19,176(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r14,108(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r15,104(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r22,96(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// sth r5,510(r1)
	REX_STORE_U16(ctx.r1.u32 + 510, ctx.r5.u16);
	// sth r4,508(r1)
	REX_STORE_U16(ctx.r1.u32 + 508, ctx.r4.u16);
	// sth r11,474(r1)
	REX_STORE_U16(ctx.r1.u32 + 474, ctx.r11.u16);
	// sth r10,472(r1)
	REX_STORE_U16(ctx.r1.u32 + 472, ctx.r10.u16);
	// b 0x827e4768
	goto loc_827E4768;
loc_827E4738:
	// bne cr6,0x827e4750
	if (!ctx.cr6.eq) goto loc_827E4750;
	// lwz r11,320(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 320);
	// lwz r10,208(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// stw r11,508(r1)
	REX_STORE_U32(ctx.r1.u32 + 508, ctx.r11.u32);
	// stw r10,472(r1)
	REX_STORE_U32(ctx.r1.u32 + 472, ctx.r10.u32);
	// b 0x827e4768
	goto loc_827E4768;
loc_827E4750:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,508(r1)
	REX_STORE_U32(ctx.r1.u32 + 508, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,472(r1)
	REX_STORE_U32(ctx.r1.u32 + 472, ctx.r8.u32);
loc_827E4768:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4784
	if (ctx.cr6.eq) goto loc_827E4784;
	// cmpw cr6,r23,r22
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x827e4790
	if (!ctx.cr6.gt) goto loc_827E4790;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e4794
	if (!ctx.cr6.eq) goto loc_827E4794;
loc_827E4784:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4794
	if (ctx.cr6.eq) goto loc_827E4794;
loc_827E4790:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E4794:
	// clrlwi r11,r19,31
	ctx.r11.u64 = ctx.r19.u32 & 0x1;
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,472(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 472);
	// bne cr6,0x827e47ac
	if (!ctx.cr6.eq) goto loc_827E47AC;
	// lwz r10,508(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 508);
loc_827E47AC:
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r8,62(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r7,66(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,172(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// lwz r11,1844(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r6,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lhz r10,138(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 138);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lhz r8,136(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 136);
	// add r7,r10,r5
	ctx.r7.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// and r6,r7,r4
	ctx.r6.u64 = ctx.r7.u64 & ctx.r4.u64;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// subf r5,r3,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r3.u64;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r4.u16);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,1844(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r4,r11,r29
	REX_STORE_U16(ctx.r11.u32 + ctx.r29.u32, ctx.r4.u16);
	// lwz r11,1844(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// sth r4,2(r9)
	REX_STORE_U16(ctx.r9.u32 + 2, ctx.r4.u16);
	// lwz r8,1844(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r4,r8,r30
	REX_STORE_U16(ctx.r8.u32 + ctx.r30.u32, ctx.r4.u16);
	// lhz r6,64(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// lhz r7,68(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// stw r4,616(r1)
	REX_STORE_U32(ctx.r1.u32 + 616, ctx.r4.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,1848(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r9,r29,r11
	ctx.r9.u64 = ctx.r29.u64 + ctx.r11.u64;
	// add r4,r10,r19
	ctx.r4.u64 = ctx.r10.u64 + ctx.r19.u64;
	// and r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 & ctx.r5.u64;
	// subf r8,r6,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r6.u64;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// sth r7,2(r9)
	REX_STORE_U16(ctx.r9.u32 + 2, ctx.r7.u16);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r5,1848(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r7,r29,r5
	REX_STORE_U16(ctx.r29.u32 + ctx.r5.u32, ctx.r7.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r4,r30,r11
	ctx.r4.u64 = ctx.r30.u64 + ctx.r11.u64;
	// sth r7,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r7.u16);
	// stw r7,608(r1)
	REX_STORE_U32(ctx.r1.u32 + 608, ctx.r7.u32);
	// lwz r3,1848(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r7,r30,r3
	REX_STORE_U16(ctx.r30.u32 + ctx.r3.u32, ctx.r7.u16);
	// b 0x827e5c24
	goto loc_827E5C24;
loc_827E487C:
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,1848(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r24,1844(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// srawi r21,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r17.s32 >> 1;
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r22,0(r28)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r22,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// bne cr6,0x827e48d0
	if (!ctx.cr6.eq) goto loc_827E48D0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e48c4
	if (ctx.cr6.eq) goto loc_827E48C4;
	// srawi r11,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e48d0
	if (ctx.cr6.eq) goto loc_827E48D0;
loc_827E48C4:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r20,0
	ctx.r20.s64 = 0;
	// b 0x827e48d8
	goto loc_827E48D8;
loc_827E48D0:
	// li r20,0
	ctx.r20.s64 = 0;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
loc_827E48D8:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r15,1
	ctx.r15.s64 = 65536;
	// lwz r10,1372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1372);
	// srawi r23,r22,16
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0xFFFF) != 0);
	ctx.r23.s64 = ctx.r22.s32 >> 16;
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r20,248(r1)
	REX_STORE_U32(ctx.r1.u32 + 248, ctx.r20.u32);
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r23.u32);
	// mr r27,r20
	ctx.r27.u64 = ctx.r20.u64;
	// subf r8,r9,r15
	ctx.r8.u64 = ctx.r15.u64 - ctx.r9.u64;
	// stw r20,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r20.u32);
	// stw r20,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r20.u32);
	// mr r26,r20
	ctx.r26.u64 = ctx.r20.u64;
	// stw r20,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r20.u32);
	// mr r30,r20
	ctx.r30.u64 = ctx.r20.u64;
	// stw r20,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r20.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r8,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, ctx.r8.u32);
	// bne cr6,0x827e4934
	if (!ctx.cr6.eq) goto loc_827E4934;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27712
	ctx.r9.s64 = ctx.r11.s64 + -27712;
	// addi r8,r10,-27304
	ctx.r8.s64 = ctx.r10.s64 + -27304;
	// b 0x827e4944
	goto loc_827E4944;
loc_827E4934:
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27584
	ctx.r9.s64 = ctx.r11.s64 + -27584;
	// addi r8,r10,-27648
	ctx.r8.s64 = ctx.r10.s64 + -27648;
loc_827E4944:
	// stw r8,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// stw r9,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// beq cr6,0x827e49c8
	if (ctx.cr6.eq) goto loc_827E49C8;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,134(r1)
	REX_STORE_U16(ctx.r1.u32 + 134, ctx.r10.u16);
	// sth r9,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e49c8
	if (ctx.cr6.eq) goto loc_827E49C8;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e49a8
	if (ctx.cr6.eq) goto loc_827E49A8;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E499C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x827e49c4
	goto loc_827E49C4;
loc_827E49A8:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E49BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
loc_827E49C4:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E49C8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x827e4aec
	if (!ctx.cr6.eq) goto loc_827E4AEC;
	// subf r29,r17,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r17.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r11,r24
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// sth r10,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r10.u16);
	// sth r9,134(r1)
	REX_STORE_U16(ctx.r1.u32 + 134, ctx.r9.u16);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4a54
	if (ctx.cr6.eq) goto loc_827E4A54;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r14,r30,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4a2c
	if (ctx.cr6.eq) goto loc_827E4A2C;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r14,r10
	REX_STORE_U32(ctx.r14.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4A20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x827e4a4c
	goto loc_827E4A4C;
loc_827E4A2C:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r14,r10
	REX_STORE_U32(ctx.r14.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4A44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_827E4A4C:
	// stwx r3,r14,r9
	REX_STORE_U32(ctx.r14.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_827E4A54:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x827e4aec
	if (!ctx.cr6.gt) goto loc_827E4AEC;
	// addi r11,r17,-2
	ctx.r11.s64 = ctx.r17.s64 + -2;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x827e4a70
	if (!ctx.cr6.eq) goto loc_827E4A70;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_827E4A70:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,134(r1)
	REX_STORE_U16(ctx.r1.u32 + 134, ctx.r10.u16);
	// sth r9,132(r1)
	REX_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4aec
	if (ctx.cr6.eq) goto loc_827E4AEC;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4ac8
	if (ctx.cr6.eq) goto loc_827E4AC8;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4ABC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x827e4ae8
	goto loc_827E4AE8;
loc_827E4AC8:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4AE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_827E4AE8:
	// stwx r3,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E4AEC:
	// add r11,r26,r27
	ctx.r11.u64 = ctx.r26.u64 + ctx.r27.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e4c6c
	if (!ctx.cr6.gt) goto loc_827E4C6C;
	// lhz r11,250(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 250);
	// lhz r10,246(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 246);
	// lhz r9,242(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 242);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,248(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 248);
	// extsh r25,r9
	ctx.r25.s64 = ctx.r9.s16;
	// lhz r7,244(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 244);
	// lhz r6,240(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 240);
	// extsh r24,r8
	ctx.r24.s64 = ctx.r8.s16;
	// lhz r5,282(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 282);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,278(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 278);
	// subf r10,r25,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r25.u64;
	// lhz r11,274(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 274);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r8,280(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 280);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,276(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 276);
	// subf r7,r25,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r25.u64;
	// lhz r21,272(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 272);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r24,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r24.u64;
	// subf r4,r22,r24
	ctx.r4.u64 = ctx.r24.u64 - ctx.r22.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 & ctx.r25.u64;
	// lwz r25,112(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 & ~ctx.r25.u64;
	// or r24,r7,r6
	ctx.r24.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r24
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r24.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r23,108(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r16,100(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r18,160(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r17,164(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r22,104(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// sth r5,502(r1)
	REX_STORE_U16(ctx.r1.u32 + 502, ctx.r5.u16);
	// sth r4,500(r1)
	REX_STORE_U16(ctx.r1.u32 + 500, ctx.r4.u16);
	// sth r11,478(r1)
	REX_STORE_U16(ctx.r1.u32 + 478, ctx.r11.u16);
	// sth r10,476(r1)
	REX_STORE_U16(ctx.r1.u32 + 476, ctx.r10.u16);
	// b 0x827e4c98
	goto loc_827E4C98;
loc_827E4C6C:
	// bne cr6,0x827e4c84
	if (!ctx.cr6.eq) goto loc_827E4C84;
	// lwz r11,240(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 240);
	// lwz r10,272(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// stw r11,500(r1)
	REX_STORE_U32(ctx.r1.u32 + 500, ctx.r11.u32);
	// stw r10,476(r1)
	REX_STORE_U32(ctx.r1.u32 + 476, ctx.r10.u32);
	// b 0x827e4c98
	goto loc_827E4C98;
loc_827E4C84:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r20,500(r1)
	REX_STORE_U32(ctx.r1.u32 + 500, ctx.r20.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r15
	ctx.r9.u64 = ctx.r15.u64 - ctx.r10.u64;
	// stw r9,476(r1)
	REX_STORE_U32(ctx.r1.u32 + 476, ctx.r9.u32);
loc_827E4C98:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4cb4
	if (ctx.cr6.eq) goto loc_827E4CB4;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x827e4cc0
	if (!ctx.cr6.gt) goto loc_827E4CC0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e4cc4
	if (!ctx.cr6.eq) goto loc_827E4CC4;
loc_827E4CB4:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4cc4
	if (ctx.cr6.eq) goto loc_827E4CC4;
loc_827E4CC0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E4CC4:
	// clrlwi r11,r23,31
	ctx.r11.u64 = ctx.r23.u32 & 0x1;
	// lwz r9,476(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 476);
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x827e4cdc
	if (!ctx.cr6.eq) goto loc_827E4CDC;
	// lwz r9,500(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 500);
loc_827E4CDC:
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r8,62(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r7,66(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// add r11,r17,r18
	ctx.r11.u64 = ctx.r17.u64 + ctx.r18.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// stw r6,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lhz r3,134(r1)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r1.u32 + 134);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 132);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// add r6,r10,r22
	ctx.r6.u64 = ctx.r10.u64 + ctx.r22.u64;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// subf r4,r7,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r7.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r3,2(r28)
	REX_STORE_U16(ctx.r28.u32 + 2, ctx.r3.u16);
	// rlwinm r29,r18,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	// stw r3,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lwz r10,1844(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// sth r3,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r3.u16);
	// lwz r7,1844(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r3,r7,r30
	REX_STORE_U16(ctx.r7.u32 + ctx.r30.u32, ctx.r3.u16);
	// lwz r10,1844(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// add r6,r10,r29
	ctx.r6.u64 = ctx.r10.u64 + ctx.r29.u64;
	// sth r3,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r3.u16);
	// lwz r5,1844(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r3,r5,r29
	REX_STORE_U16(ctx.r5.u32 + ctx.r29.u32, ctx.r3.u16);
	// lhz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// lhz r4,68(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r7,r10,r23
	ctx.r7.u64 = ctx.r10.u64 + ctx.r23.u64;
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// and r5,r7,r9
	ctx.r5.u64 = ctx.r7.u64 & ctx.r9.u64;
	// subf r4,r3,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r3.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,0(r28)
	REX_STORE_U16(ctx.r28.u32 + 0, ctx.r3.u16);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// lwz r10,1848(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// sth r3,2(r10)
	REX_STORE_U16(ctx.r10.u32 + 2, ctx.r3.u16);
	// stw r3,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// lwz r9,1848(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r3,r30,r9
	REX_STORE_U16(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u16);
	// lwz r10,1848(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r7,r29,r10
	ctx.r7.u64 = ctx.r29.u64 + ctx.r10.u64;
	// sth r3,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r3.u16);
	// lwz r6,1848(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r3,r29,r6
	REX_STORE_U16(ctx.r29.u32 + ctx.r6.u32, ctx.r3.u16);
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r5,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r5.u32);
	// lhz r27,50(r31)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r25,1840(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// lwz r24,1836(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// srawi r20,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r20.s64 = ctx.r27.s32 >> 1;
	// bne cr6,0x827e4e20
	if (!ctx.cr6.eq) goto loc_827E4E20;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e4e14
	if (ctx.cr6.eq) goto loc_827E4E14;
	// srawi r11,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e4e20
	if (ctx.cr6.eq) goto loc_827E4E20;
loc_827E4E14:
	// li r26,1
	ctx.r26.s64 = 1;
	// li r19,0
	ctx.r19.s64 = 0;
	// b 0x827e4e28
	goto loc_827E4E28;
loc_827E4E20:
	// li r19,0
	ctx.r19.s64 = 0;
	// mr r26,r19
	ctx.r26.u64 = ctx.r19.u64;
loc_827E4E28:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lis r8,-32134
	ctx.r8.s64 = -2105933824;
	// rlwinm r7,r11,17,0,14
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r19,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r19.u32);
	// lis r17,1
	ctx.r17.s64 = 65536;
	// stw r19,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r19.u32);
	// addi r6,r10,-27024
	ctx.r6.s64 = ctx.r10.s64 + -27024;
	// stw r19,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r19.u32);
	// addi r5,r8,-26744
	ctx.r5.s64 = ctx.r8.s64 + -26744;
	// stw r19,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r19.u32);
	// subf r4,r7,r17
	ctx.r4.u64 = ctx.r17.u64 - ctx.r7.u64;
	// stw r6,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r6.u32);
	// rlwinm r21,r9,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r5.u32);
	// mr r22,r19
	ctx.r22.u64 = ctx.r19.u64;
	// stw r19,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r19.u32);
	// stw r4,344(r1)
	REX_STORE_U32(ctx.r1.u32 + 344, ctx.r4.u32);
	// mr r23,r19
	ctx.r23.u64 = ctx.r19.u64;
	// stw r19,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r19.u32);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq cr6,0x827e4f00
	if (ctx.cr6.eq) goto loc_827E4F00;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,158(r1)
	REX_STORE_U16(ctx.r1.u32 + 158, ctx.r10.u16);
	// sth r9,156(r1)
	REX_STORE_U16(ctx.r1.u32 + 156, ctx.r9.u16);
	// lwz r4,156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4f00
	if (ctx.cr6.eq) goto loc_827E4F00;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4ee0
	if (ctx.cr6.eq) goto loc_827E4EE0;
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r4,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E4ED0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r22,1
	ctx.r22.s64 = 1;
	// stw r3,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e4efc
	goto loc_827E4EFC;
loc_827E4EE0:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E4EF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r3.u32);
	// li r23,1
	ctx.r23.s64 = 1;
loc_827E4EFC:
	// li r28,1
	ctx.r28.s64 = 1;
loc_827E4F00:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x827e502c
	if (!ctx.cr6.eq) goto loc_827E502C;
	// subf r26,r27,r18
	ctx.r26.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,158(r1)
	REX_STORE_U16(ctx.r1.u32 + 158, ctx.r10.u16);
	// sth r9,156(r1)
	REX_STORE_U16(ctx.r1.u32 + 156, ctx.r9.u16);
	// lwz r4,156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e4f90
	if (ctx.cr6.eq) goto loc_827E4F90;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r18,r28,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e4f68
	if (ctx.cr6.eq) goto loc_827E4F68;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r18,r10
	REX_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4F58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e4f88
	goto loc_827E4F88;
loc_827E4F68:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r18,r10
	REX_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4F80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_827E4F88:
	// stwx r3,r18,r9
	REX_STORE_U32(ctx.r18.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_827E4F90:
	// cmpwi cr6,r20,1
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 1, ctx.xer);
	// ble cr6,0x827e502c
	if (!ctx.cr6.gt) goto loc_827E502C;
	// addi r11,r27,-2
	ctx.r11.s64 = ctx.r27.s64 + -2;
	// cmpw cr6,r21,r11
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r26,2
	ctx.r11.s64 = ctx.r26.s64 + 2;
	// bne cr6,0x827e4fac
	if (!ctx.cr6.eq) goto loc_827E4FAC;
	// addi r11,r26,-2
	ctx.r11.s64 = ctx.r26.s64 + -2;
loc_827E4FAC:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,158(r1)
	REX_STORE_U16(ctx.r1.u32 + 158, ctx.r10.u16);
	// sth r9,156(r1)
	REX_STORE_U16(ctx.r1.u32 + 156, ctx.r9.u16);
	// lwz r4,156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e502c
	if (ctx.cr6.eq) goto loc_827E502C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e5008
	if (ctx.cr6.eq) goto loc_827E5008;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r28,r10
	REX_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E4FF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stw r22,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// b 0x827e5028
	goto loc_827E5028;
loc_827E5008:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r28,r10
	REX_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E5020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_827E5028:
	// stwx r3,r28,r9
	REX_STORE_U32(ctx.r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E502C:
	// add r11,r22,r23
	ctx.r11.u64 = ctx.r22.u64 + ctx.r23.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e51a4
	if (!ctx.cr6.gt) goto loc_827E51A4;
	// lhz r11,314(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 314);
	// lhz r10,310(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 310);
	// lhz r9,306(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 306);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// extsh r27,r10
	ctx.r27.s64 = ctx.r10.s16;
	// lhz r8,312(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 312);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,308(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 308);
	// lhz r6,304(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 304);
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// lhz r5,346(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 346);
	// subf r10,r26,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r26.u64;
	// lhz r4,342(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 342);
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r11,338(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 338);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// lhz r6,340(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 340);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,344(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 344);
	// subf r7,r26,r28
	ctx.r7.u64 = ctx.r28.u64 - ctx.r26.u64;
	// lhz r21,336(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 336);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r20,r22,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r22.u64;
	// subf r4,r22,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r22.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// lwz r26,112(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// lwz r20,120(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// and r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	// andc r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 & ~ctx.r20.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 | ctx.r10.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r28,r18,r25
	ctx.r28.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r27,r15,r22
	ctx.r27.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r28,r6
	ctx.r9.u64 = ctx.r28.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r27,r4
	ctx.r7.u64 = ctx.r27.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r22,96(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r15,104(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,108(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// sth r5,518(r1)
	REX_STORE_U16(ctx.r1.u32 + 518, ctx.r5.u16);
	// sth r4,516(r1)
	REX_STORE_U16(ctx.r1.u32 + 516, ctx.r4.u16);
	// sth r11,486(r1)
	REX_STORE_U16(ctx.r1.u32 + 486, ctx.r11.u16);
	// sth r10,484(r1)
	REX_STORE_U16(ctx.r1.u32 + 484, ctx.r10.u16);
	// b 0x827e51d0
	goto loc_827E51D0;
loc_827E51A4:
	// bne cr6,0x827e51bc
	if (!ctx.cr6.eq) goto loc_827E51BC;
	// lwz r11,304(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 304);
	// lwz r10,336(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 336);
	// stw r11,516(r1)
	REX_STORE_U32(ctx.r1.u32 + 516, ctx.r11.u32);
	// stw r10,484(r1)
	REX_STORE_U32(ctx.r1.u32 + 484, ctx.r10.u32);
	// b 0x827e51d0
	goto loc_827E51D0;
loc_827E51BC:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r19,516(r1)
	REX_STORE_U32(ctx.r1.u32 + 516, ctx.r19.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r17
	ctx.r9.u64 = ctx.r17.u64 - ctx.r10.u64;
	// stw r9,484(r1)
	REX_STORE_U32(ctx.r1.u32 + 484, ctx.r9.u32);
loc_827E51D0:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e51ec
	if (ctx.cr6.eq) goto loc_827E51EC;
	// cmpw cr6,r23,r22
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x827e51f8
	if (!ctx.cr6.gt) goto loc_827E51F8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e51fc
	if (!ctx.cr6.eq) goto loc_827E51FC;
loc_827E51EC:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e51fc
	if (ctx.cr6.eq) goto loc_827E51FC;
loc_827E51F8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E51FC:
	// lwz r11,484(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 484);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827e520c
	if (!ctx.cr6.eq) goto loc_827E520C;
	// lwz r11,516(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 516);
loc_827E520C:
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r9,1836(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// stw r11,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// lhz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 100);
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// sth r11,2(r9)
	REX_STORE_U16(ctx.r9.u32 + 2, ctx.r11.u16);
	// lwz r8,1836(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r11,r8,r30
	REX_STORE_U16(ctx.r8.u32 + ctx.r30.u32, ctx.r11.u16);
	// lwz r9,1836(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r7,r9,r29
	ctx.r7.u64 = ctx.r9.u64 + ctx.r29.u64;
	// sth r11,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r11.u16);
	// lwz r6,1836(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r11,r6,r29
	REX_STORE_U16(ctx.r6.u32 + ctx.r29.u32, ctx.r11.u16);
	// lwz r11,1840(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// sth r10,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r10.u16);
	// lwz r4,1840(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r10,r4,r30
	REX_STORE_U16(ctx.r4.u32 + ctx.r30.u32, ctx.r10.u16);
	// lwz r11,1840(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// sth r10,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r10.u16);
	// lwz r11,1840(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r10,r11,r29
	REX_STORE_U16(ctx.r11.u32 + ctx.r29.u32, ctx.r10.u16);
	// b 0x827e5c24
	goto loc_827E5C24;
loc_827E5270:
	// lwz r28,1368(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x827e5284
	if (!ctx.cr6.eq) goto loc_827E5284;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827e528c
	goto loc_827E528C;
loc_827E5284:
	// lhz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// mullw r11,r11,r17
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r17.s32);
loc_827E528C:
	// lwz r10,1392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1392);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x827e52a4
	if (ctx.cr6.eq) goto loc_827E52A4;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// li r27,0
	ctx.r27.s64 = 0;
	// bne cr6,0x827e52a8
	if (!ctx.cr6.eq) goto loc_827E52A8;
loc_827E52A4:
	// li r27,1
	ctx.r27.s64 = 1;
loc_827E52A8:
	// add r9,r11,r18
	ctx.r9.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lwz r7,376(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 376);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwzx r8,r8,r7
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// srawi r8,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 16;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// cmpwi cr6,r4,16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 16384, ctx.xer);
	// beq cr6,0x827e59d4
	if (ctx.cr6.eq) goto loc_827E59D4;
	// add r9,r17,r9
	ctx.r9.u64 = ctx.r17.u64 + ctx.r9.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// rlwinm r6,r28,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r30,r8,31
	ctx.r30.u64 = ctx.r8.u32 & 0x1;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r29,r6,-1
	ctx.r29.s64 = ctx.r6.s64 + -1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// srawi r7,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 16;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lwz r3,4(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// srawi r9,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 16;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// srawi r3,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// beq cr6,0x827e5344
	if (ctx.cr6.eq) goto loc_827E5344;
	// add r11,r29,r8
	ctx.r11.u64 = ctx.r29.u64 + ctx.r8.u64;
	// lwz r14,560(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 560);
	// lwz r15,528(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 528);
	// srawi r19,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r19.s64 = ctx.r11.s32 >> 1;
	// stw r4,544(r1)
	REX_STORE_U32(ctx.r1.u32 + 544, ctx.r4.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r19,576(r1)
	REX_STORE_U32(ctx.r1.u32 + 576, ctx.r19.u32);
	// b 0x827e5360
	goto loc_827E5360;
loc_827E5344:
	// mr r15,r4
	ctx.r15.u64 = ctx.r4.u64;
	// lwz r4,544(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 544);
	// srawi r14,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r14.s64 = ctx.r8.s32 >> 1;
	// lwz r19,576(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 576);
	// stw r15,528(r1)
	REX_STORE_U32(ctx.r1.u32 + 528, ctx.r15.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r14,560(r1)
	REX_STORE_U32(ctx.r1.u32 + 560, ctx.r14.u32);
loc_827E5360:
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e5398
	if (ctx.cr6.eq) goto loc_827E5398;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,544
	ctx.r4.s64 = ctx.r1.s64 + 544;
	// add r7,r29,r7
	ctx.r7.u64 = ctx.r29.u64 + ctx.r7.u64;
	// addi r25,r1,576
	ctx.r25.s64 = ctx.r1.s64 + 576;
	// srawi r7,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r5,r8,r4
	REX_STORE_U32(ctx.r8.u32 + ctx.r4.u32, ctx.r5.u32);
	// stwx r7,r8,r25
	REX_STORE_U32(ctx.r8.u32 + ctx.r25.u32, ctx.r7.u32);
	// lwz r4,544(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 544);
	// lwz r19,576(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 576);
	// b 0x827e53bc
	goto loc_827E53BC;
loc_827E5398:
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r26,r1,528
	ctx.r26.s64 = ctx.r1.s64 + 528;
	// addi r21,r1,560
	ctx.r21.s64 = ctx.r1.s64 + 560;
	// srawi r7,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r5,r8,r26
	REX_STORE_U32(ctx.r8.u32 + ctx.r26.u32, ctx.r5.u32);
	// stwx r7,r8,r21
	REX_STORE_U32(ctx.r8.u32 + ctx.r21.u32, ctx.r7.u32);
	// lwz r15,528(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 528);
	// lwz r14,560(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 560);
loc_827E53BC:
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// lwz r26,564(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 564);
	// lwz r20,568(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 568);
	// lwz r5,532(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 532);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r21,536(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 536);
	// lwz r25,552(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 552);
	// lwz r24,548(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 548);
	// lwz r23,584(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 584);
	// lwz r22,580(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 580);
	// beq cr6,0x827e5424
	if (ctx.cr6.eq) goto loc_827E5424;
	// add r4,r29,r9
	ctx.r4.u64 = ctx.r29.u64 + ctx.r9.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,544
	ctx.r7.s64 = ctx.r1.s64 + 544;
	// addi r9,r1,576
	ctx.r9.s64 = ctx.r1.s64 + 576;
	// srawi r4,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r6,r8,r7
	REX_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
	// stwx r4,r8,r9
	REX_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r25,552(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 552);
	// lwz r23,584(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 584);
	// lwz r24,548(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 548);
	// lwz r4,544(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 544);
	// lwz r22,580(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 580);
	// lwz r19,576(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 576);
	// b 0x827e5458
	goto loc_827E5458;
loc_827E5424:
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,560
	ctx.r5.s64 = ctx.r1.s64 + 560;
	// addi r7,r1,528
	ctx.r7.s64 = ctx.r1.s64 + 528;
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r9,r8,r5
	REX_STORE_U32(ctx.r8.u32 + ctx.r5.u32, ctx.r9.u32);
	// stwx r6,r8,r7
	REX_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
	// lwz r20,568(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 568);
	// lwz r21,536(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 536);
	// lwz r5,532(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 532);
	// lwz r15,528(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 528);
	// lwz r26,564(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 564);
	// lwz r14,560(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 560);
loc_827E5458:
	// clrlwi r9,r3,31
	ctx.r9.u64 = ctx.r3.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e54a0
	if (ctx.cr6.eq) goto loc_827E54A0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,544
	ctx.r8.s64 = ctx.r1.s64 + 544;
	// add r7,r29,r3
	ctx.r7.u64 = ctx.r29.u64 + ctx.r3.u64;
	// addi r6,r1,576
	ctx.r6.s64 = ctx.r1.s64 + 576;
	// srawi r4,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r30,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r30.u32);
	// stwx r4,r9,r6
	REX_STORE_U32(ctx.r9.u32 + ctx.r6.u32, ctx.r4.u32);
	// lwz r25,552(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 552);
	// lwz r24,548(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 548);
	// lwz r19,576(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 576);
	// lwz r4,544(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 544);
	// lwz r23,584(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 584);
	// lwz r22,580(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 580);
	// b 0x827e54d4
	goto loc_827E54D4;
loc_827E54A0:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,528
	ctx.r8.s64 = ctx.r1.s64 + 528;
	// addi r7,r1,560
	ctx.r7.s64 = ctx.r1.s64 + 560;
	// srawi r6,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r30,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r30.u32);
	// stwx r6,r9,r7
	REX_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// lwz r21,536(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 536);
	// lwz r5,532(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 532);
	// lwz r15,528(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 528);
	// lwz r20,568(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 568);
	// lwz r26,564(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 564);
	// lwz r14,560(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 560);
loc_827E54D4:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x827e5740
	if (!ctx.cr6.gt) goto loc_827E5740;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// subf r11,r4,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r4.u64;
	// bne cr6,0x827e5558
	if (!ctx.cr6.eq) goto loc_827E5558;
	// subf r10,r25,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r25.u64;
	// subf r9,r4,r25
	ctx.r9.u64 = ctx.r25.u64 - ctx.r4.u64;
	// subf r8,r19,r22
	ctx.r8.u64 = ctx.r22.u64 - ctx.r19.u64;
	// subf r7,r23,r22
	ctx.r7.u64 = ctx.r22.u64 - ctx.r23.u64;
	// xor r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// subf r5,r19,r23
	ctx.r5.u64 = ctx.r23.u64 - ctx.r19.u64;
	// xor r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r11.u64;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// srawi r11,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 31;
	// xor r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 ^ ctx.r8.u64;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// and r5,r10,r4
	ctx.r5.u64 = ctx.r10.u64 & ctx.r4.u64;
	// andc r4,r25,r7
	ctx.r4.u64 = ctx.r25.u64 & ~ctx.r7.u64;
	// and r10,r8,r19
	ctx.r10.u64 = ctx.r8.u64 & ctx.r19.u64;
	// andc r3,r23,r6
	ctx.r3.u64 = ctx.r23.u64 & ~ctx.r6.u64;
	// or r8,r4,r5
	ctx.r8.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r6,r3,r10
	ctx.r6.u64 = ctx.r3.u64 | ctx.r10.u64;
	// and r5,r9,r22
	ctx.r5.u64 = ctx.r9.u64 & ctx.r22.u64;
	// and r7,r11,r24
	ctx.r7.u64 = ctx.r11.u64 & ctx.r24.u64;
	// or r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x827e59dc
	goto loc_827E59DC;
loc_827E5558:
	// subf r10,r24,r25
	ctx.r10.u64 = ctx.r25.u64 - ctx.r24.u64;
	// subf r9,r25,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r25.u64;
	// srawi r11,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 31;
	// subf r8,r24,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r24.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// subf r7,r25,r24
	ctx.r7.u64 = ctx.r24.u64 - ctx.r25.u64;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r6,r4,r25
	ctx.r6.u64 = ctx.r25.u64 - ctx.r4.u64;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// srawi r6,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 31;
	// not r3,r8
	ctx.r3.u64 = ~ctx.r8.u64;
	// not r5,r11
	ctx.r5.u64 = ~ctx.r11.u64;
	// not r8,r7
	ctx.r8.u64 = ~ctx.r7.u64;
	// not r7,r6
	ctx.r7.u64 = ~ctx.r6.u64;
	// and r30,r4,r5
	ctx.r30.u64 = ctx.r4.u64 & ctx.r5.u64;
	// and r26,r24,r3
	ctx.r26.u64 = ctx.r24.u64 & ctx.r3.u64;
	// not r6,r10
	ctx.r6.u64 = ~ctx.r10.u64;
	// and r21,r24,r8
	ctx.r21.u64 = ctx.r24.u64 & ctx.r8.u64;
	// and r20,r25,r7
	ctx.r20.u64 = ctx.r25.u64 & ctx.r7.u64;
	// and r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 & ctx.r7.u64;
	// and r30,r26,r6
	ctx.r30.u64 = ctx.r26.u64 & ctx.r6.u64;
	// not r15,r9
	ctx.r15.u64 = ~ctx.r9.u64;
	// lwz r9,556(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 556);
	// and r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 & ctx.r8.u64;
	// and r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 & ctx.r3.u64;
	// and r5,r21,r5
	ctx.r5.u64 = ctx.r21.u64 & ctx.r5.u64;
	// and r26,r20,r6
	ctx.r26.u64 = ctx.r20.u64 & ctx.r6.u64;
	// or r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 | ctx.r30.u64;
	// and r8,r8,r15
	ctx.r8.u64 = ctx.r8.u64 & ctx.r15.u64;
	// or r5,r5,r26
	ctx.r5.u64 = ctx.r5.u64 | ctx.r26.u64;
	// and r3,r3,r15
	ctx.r3.u64 = ctx.r3.u64 & ctx.r15.u64;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// or r7,r5,r3
	ctx.r7.u64 = ctx.r5.u64 | ctx.r3.u64;
	// subf r5,r8,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r3,r9,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r9.u64;
	// subf r26,r7,r8
	ctx.r26.u64 = ctx.r8.u64 - ctx.r7.u64;
	// xor r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 ^ ctx.r6.u64;
	// xor r30,r11,r15
	ctx.r30.u64 = ctx.r11.u64 ^ ctx.r15.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// srawi r5,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r26.s32 >> 31;
	// eqv r5,r5,r11
	ctx.r5.u64 = ~(ctx.r5.u64 ^ ctx.r11.u64);
	// eqv r3,r3,r11
	ctx.r3.u64 = ~(ctx.r3.u64 ^ ctx.r11.u64);
	// xor r11,r10,r15
	ctx.r11.u64 = ctx.r10.u64 ^ ctx.r15.u64;
	// or r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 | ctx.r3.u64;
	// and r4,r30,r4
	ctx.r4.u64 = ctx.r30.u64 & ctx.r4.u64;
	// and r6,r6,r24
	ctx.r6.u64 = ctx.r6.u64 & ctx.r24.u64;
	// and r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 & ctx.r3.u64;
	// andc r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ~ctx.r10.u64;
	// and r7,r5,r9
	ctx.r7.u64 = ctx.r5.u64 & ctx.r9.u64;
	// or r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 | ctx.r4.u64;
	// or r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 | ctx.r8.u64;
	// and r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 & ctx.r25.u64;
	// or r10,r4,r7
	ctx.r10.u64 = ctx.r4.u64 | ctx.r7.u64;
	// or r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// subf r3,r19,r22
	ctx.r3.u64 = ctx.r22.u64 - ctx.r19.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r9,r22,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r22.u64;
	// srawi r8,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 1;
	// subf r7,r23,r19
	ctx.r7.u64 = ctx.r19.u64 - ctx.r23.u64;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 31;
	// not r6,r9
	ctx.r6.u64 = ~ctx.r9.u64;
	// not r5,r8
	ctx.r5.u64 = ~ctx.r8.u64;
	// xor r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// xor r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 ^ ctx.r5.u64;
	// subf r8,r22,r19
	ctx.r8.u64 = ctx.r19.u64 - ctx.r22.u64;
	// subf r7,r23,r22
	ctx.r7.u64 = ctx.r22.u64 - ctx.r23.u64;
	// and r3,r3,r19
	ctx.r3.u64 = ctx.r3.u64 & ctx.r19.u64;
	// and r4,r4,r22
	ctx.r4.u64 = ctx.r4.u64 & ctx.r22.u64;
	// xor r30,r9,r5
	ctx.r30.u64 = ctx.r9.u64 ^ ctx.r5.u64;
	// subf r26,r19,r23
	ctx.r26.u64 = ctx.r23.u64 - ctx.r19.u64;
	// srawi r9,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 31;
	// srawi r8,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 31;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r3,r30,r23
	ctx.r3.u64 = ctx.r30.u64 & ctx.r23.u64;
	// srawi r7,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r26.s32 >> 31;
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// lwz r9,588(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 588);
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// and r26,r19,r10
	ctx.r26.u64 = ctx.r19.u64 & ctx.r10.u64;
	// and r24,r22,r8
	ctx.r24.u64 = ctx.r22.u64 & ctx.r8.u64;
	// and r25,r22,r30
	ctx.r25.u64 = ctx.r22.u64 & ctx.r30.u64;
	// and r22,r23,r7
	ctx.r22.u64 = ctx.r23.u64 & ctx.r7.u64;
	// and r7,r26,r7
	ctx.r7.u64 = ctx.r26.u64 & ctx.r7.u64;
	// and r26,r25,r6
	ctx.r26.u64 = ctx.r25.u64 & ctx.r6.u64;
	// and r8,r23,r8
	ctx.r8.u64 = ctx.r23.u64 & ctx.r8.u64;
	// and r10,r24,r10
	ctx.r10.u64 = ctx.r24.u64 & ctx.r10.u64;
	// and r6,r22,r6
	ctx.r6.u64 = ctx.r22.u64 & ctx.r6.u64;
	// and r30,r19,r30
	ctx.r30.u64 = ctx.r19.u64 & ctx.r30.u64;
	// and r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	// or r7,r7,r26
	ctx.r7.u64 = ctx.r7.u64 | ctx.r26.u64;
	// or r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 | ctx.r6.u64;
	// and r5,r30,r5
	ctx.r5.u64 = ctx.r30.u64 & ctx.r5.u64;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// or r7,r6,r5
	ctx.r7.u64 = ctx.r6.u64 | ctx.r5.u64;
	// subf r6,r8,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r5,r9,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r9.u64;
	// subf r30,r7,r8
	ctx.r30.u64 = ctx.r8.u64 - ctx.r7.u64;
	// srawi r10,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 31;
	// srawi r6,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r5.s32 >> 31;
	// srawi r5,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r30.s32 >> 31;
	// eqv r6,r6,r10
	ctx.r6.u64 = ~(ctx.r6.u64 ^ ctx.r10.u64);
	// eqv r5,r5,r10
	ctx.r5.u64 = ~(ctx.r5.u64 ^ ctx.r10.u64);
	// and r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 & ctx.r9.u64;
	// or r9,r6,r5
	ctx.r9.u64 = ctx.r6.u64 | ctx.r5.u64;
	// and r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	// andc r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ~ctx.r9.u64;
	// or r6,r4,r3
	ctx.r6.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 | ctx.r8.u64;
	// or r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 | ctx.r10.u64;
	// add r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 + ctx.r6.u64;
	// srawi r3,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x827e59dc
	goto loc_827E59DC;
loc_827E5740:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x827e5770
	if (!ctx.cr6.eq) goto loc_827E5770;
	// add r11,r5,r15
	ctx.r11.u64 = ctx.r5.u64 + ctx.r15.u64;
	// add r10,r26,r14
	ctx.r10.u64 = ctx.r26.u64 + ctx.r14.u64;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x827e59dc
	goto loc_827E59DC;
loc_827E5770:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// subf r11,r15,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r15.u64;
	// bne cr6,0x827e57ec
	if (!ctx.cr6.eq) goto loc_827E57EC;
	// subf r10,r21,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r21.u64;
	// subf r9,r15,r21
	ctx.r9.u64 = ctx.r21.u64 - ctx.r15.u64;
	// subf r8,r14,r26
	ctx.r8.u64 = ctx.r26.u64 - ctx.r14.u64;
	// subf r7,r20,r26
	ctx.r7.u64 = ctx.r26.u64 - ctx.r20.u64;
	// xor r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// subf r4,r14,r20
	ctx.r4.u64 = ctx.r20.u64 - ctx.r14.u64;
	// xor r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r11.u64;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// srawi r11,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 31;
	// xor r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 ^ ctx.r8.u64;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// and r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 & ctx.r5.u64;
	// andc r4,r21,r7
	ctx.r4.u64 = ctx.r21.u64 & ~ctx.r7.u64;
	// and r11,r9,r26
	ctx.r11.u64 = ctx.r9.u64 & ctx.r26.u64;
	// andc r3,r20,r6
	ctx.r3.u64 = ctx.r20.u64 & ~ctx.r6.u64;
	// and r10,r10,r15
	ctx.r10.u64 = ctx.r10.u64 & ctx.r15.u64;
	// or r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r7,r3,r11
	ctx.r7.u64 = ctx.r3.u64 | ctx.r11.u64;
	// and r6,r8,r14
	ctx.r6.u64 = ctx.r8.u64 & ctx.r14.u64;
	// or r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x827e59dc
	goto loc_827E59DC;
loc_827E57EC:
	// subf r10,r5,r21
	ctx.r10.u64 = ctx.r21.u64 - ctx.r5.u64;
	// subf r9,r21,r15
	ctx.r9.u64 = ctx.r15.u64 - ctx.r21.u64;
	// srawi r11,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 31;
	// subf r8,r5,r15
	ctx.r8.u64 = ctx.r15.u64 - ctx.r5.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// subf r7,r21,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r21.u64;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// subf r6,r15,r21
	ctx.r6.u64 = ctx.r21.u64 - ctx.r15.u64;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// srawi r6,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 31;
	// not r3,r7
	ctx.r3.u64 = ~ctx.r7.u64;
	// not r4,r11
	ctx.r4.u64 = ~ctx.r11.u64;
	// not r7,r6
	ctx.r7.u64 = ~ctx.r6.u64;
	// and r30,r21,r3
	ctx.r30.u64 = ctx.r21.u64 & ctx.r3.u64;
	// and r3,r5,r3
	ctx.r3.u64 = ctx.r5.u64 & ctx.r3.u64;
	// and r25,r15,r4
	ctx.r25.u64 = ctx.r15.u64 & ctx.r4.u64;
	// not r6,r9
	ctx.r6.u64 = ~ctx.r9.u64;
	// lwz r9,540(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 540);
	// not r24,r10
	ctx.r24.u64 = ~ctx.r10.u64;
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// and r23,r21,r7
	ctx.r23.u64 = ctx.r21.u64 & ctx.r7.u64;
	// and r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 & ctx.r4.u64;
	// and r30,r30,r6
	ctx.r30.u64 = ctx.r30.u64 & ctx.r6.u64;
	// and r7,r25,r7
	ctx.r7.u64 = ctx.r25.u64 & ctx.r7.u64;
	// and r25,r5,r8
	ctx.r25.u64 = ctx.r5.u64 & ctx.r8.u64;
	// and r3,r23,r24
	ctx.r3.u64 = ctx.r23.u64 & ctx.r24.u64;
	// and r8,r15,r8
	ctx.r8.u64 = ctx.r15.u64 & ctx.r8.u64;
	// or r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 | ctx.r7.u64;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r30,r25,r24
	ctx.r30.u64 = ctx.r25.u64 & ctx.r24.u64;
	// and r3,r8,r6
	ctx.r3.u64 = ctx.r8.u64 & ctx.r6.u64;
	// or r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 | ctx.r30.u64;
	// or r7,r4,r3
	ctx.r7.u64 = ctx.r4.u64 | ctx.r3.u64;
	// subf r4,r8,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r3,r9,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r9.u64;
	// xor r30,r11,r24
	ctx.r30.u64 = ctx.r11.u64 ^ ctx.r24.u64;
	// xor r25,r11,r6
	ctx.r25.u64 = ctx.r11.u64 ^ ctx.r6.u64;
	// subf r24,r7,r8
	ctx.r24.u64 = ctx.r8.u64 - ctx.r7.u64;
	// srawi r11,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 31;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 31;
	// eqv r4,r4,r11
	ctx.r4.u64 = ~(ctx.r4.u64 ^ ctx.r11.u64);
	// eqv r3,r3,r11
	ctx.r3.u64 = ~(ctx.r3.u64 ^ ctx.r11.u64);
	// xor r11,r10,r6
	ctx.r11.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// or r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r6,r11,r21
	ctx.r6.u64 = ctx.r11.u64 & ctx.r21.u64;
	// andc r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 & ~ctx.r10.u64;
	// and r5,r30,r5
	ctx.r5.u64 = ctx.r30.u64 & ctx.r5.u64;
	// and r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 & ctx.r3.u64;
	// or r8,r6,r5
	ctx.r8.u64 = ctx.r6.u64 | ctx.r5.u64;
	// and r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 & ctx.r9.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r7,r25,r15
	ctx.r7.u64 = ctx.r25.u64 & ctx.r15.u64;
	// or r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 | ctx.r9.u64;
	// or r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 | ctx.r7.u64;
	// subf r5,r14,r26
	ctx.r5.u64 = ctx.r26.u64 - ctx.r14.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r3,r26,r20
	ctx.r3.u64 = ctx.r20.u64 - ctx.r26.u64;
	// srawi r11,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 1;
	// subf r8,r20,r14
	ctx.r8.u64 = ctx.r14.u64 - ctx.r20.u64;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 31;
	// srawi r9,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// not r6,r9
	ctx.r6.u64 = ~ctx.r9.u64;
	// not r5,r8
	ctx.r5.u64 = ~ctx.r8.u64;
	// xor r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// xor r3,r9,r5
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r5.u64;
	// and r7,r4,r26
	ctx.r7.u64 = ctx.r4.u64 & ctx.r26.u64;
	// subf r9,r26,r14
	ctx.r9.u64 = ctx.r14.u64 - ctx.r26.u64;
	// and r4,r3,r20
	ctx.r4.u64 = ctx.r3.u64 & ctx.r20.u64;
	// subf r8,r20,r26
	ctx.r8.u64 = ctx.r26.u64 - ctx.r20.u64;
	// xor r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 ^ ctx.r5.u64;
	// subf r30,r14,r20
	ctx.r30.u64 = ctx.r20.u64 - ctx.r14.u64;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// or r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 | ctx.r7.u64;
	// and r3,r3,r14
	ctx.r3.u64 = ctx.r3.u64 & ctx.r14.u64;
	// srawi r7,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r30.s32 >> 31;
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// and r25,r20,r8
	ctx.r25.u64 = ctx.r20.u64 & ctx.r8.u64;
	// and r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 & ctx.r8.u64;
	// and r24,r14,r10
	ctx.r24.u64 = ctx.r14.u64 & ctx.r10.u64;
	// and r23,r20,r7
	ctx.r23.u64 = ctx.r20.u64 & ctx.r7.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// lwz r9,572(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 572);
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// and r25,r25,r5
	ctx.r25.u64 = ctx.r25.u64 & ctx.r5.u64;
	// and r8,r23,r6
	ctx.r8.u64 = ctx.r23.u64 & ctx.r6.u64;
	// and r7,r24,r7
	ctx.r7.u64 = ctx.r24.u64 & ctx.r7.u64;
	// and r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 & ctx.r30.u64;
	// and r30,r14,r30
	ctx.r30.u64 = ctx.r14.u64 & ctx.r30.u64;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// and r6,r26,r6
	ctx.r6.u64 = ctx.r26.u64 & ctx.r6.u64;
	// or r7,r25,r7
	ctx.r7.u64 = ctx.r25.u64 | ctx.r7.u64;
	// and r8,r30,r5
	ctx.r8.u64 = ctx.r30.u64 & ctx.r5.u64;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 | ctx.r8.u64;
	// subf r5,r7,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r7.u64;
	// subf r8,r9,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r9.u64;
	// subf r30,r6,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r6.u64;
	// srawi r10,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 31;
	// srawi r5,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 31;
	// srawi r8,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r30.s32 >> 31;
	// eqv r5,r5,r10
	ctx.r5.u64 = ~(ctx.r5.u64 ^ ctx.r10.u64);
	// eqv r10,r8,r10
	ctx.r10.u64 = ~(ctx.r8.u64 ^ ctx.r10.u64);
	// and r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 & ctx.r9.u64;
	// or r8,r5,r10
	ctx.r8.u64 = ctx.r5.u64 | ctx.r10.u64;
	// and r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 & ctx.r10.u64;
	// andc r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 & ~ctx.r8.u64;
	// or r6,r4,r3
	ctx.r6.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// or r10,r4,r9
	ctx.r10.u64 = ctx.r4.u64 | ctx.r9.u64;
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// srawi r10,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x827e59dc
	goto loc_827E59DC;
loc_827E59D4:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_827E59DC:
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// lwz r10,1788(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1788);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e59fc
	if (ctx.cr6.eq) goto loc_827E59FC;
	// rlwinm r9,r28,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r9,r9,1
	ctx.xer.ca = ctx.r9.u32 <= 1;
	ctx.r9.u64 = static_cast<uint64_t>(1) - ctx.r9.u64;
	// subf r8,r9,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x827e5a00
	goto loc_827E5A00;
loc_827E59FC:
	// li r9,0
	ctx.r9.s64 = 0;
loc_827E5A00:
	// lwz r7,1460(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1460);
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	// mullw r6,r11,r10
	ctx.r6.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r27,r7
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r7.s32, ctx.xer);
	// addi r7,r10,-256
	ctx.r7.s64 = ctx.r10.s64 + -256;
	// beq cr6,0x827e5a9c
	if (ctx.cr6.eq) goto loc_827E5A9C;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// beq cr6,0x827e5a58
	if (ctx.cr6.eq) goto loc_827E5A58;
	// mullw r5,r8,r10
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r10,r8,r7
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addi r8,r6,255
	ctx.r8.s64 = ctx.r6.s64 + 255;
	// addi r7,r5,255
	ctx.r7.s64 = ctx.r5.s64 + 255;
	// addi r6,r11,255
	ctx.r6.s64 = ctx.r11.s64 + 255;
	// addi r5,r10,255
	ctx.r5.s64 = ctx.r10.s64 + 255;
	// srawi r11,r8,9
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FF) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 9;
	// srawi r4,r7,9
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1FF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 9;
	// srawi r8,r6,9
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1FF) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 9;
	// srawi r3,r5,9
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1FF) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 9;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r3,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x827e5b20
	goto loc_827E5B20;
loc_827E5A58:
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addi r6,r6,64
	ctx.r6.s64 = ctx.r6.s64 + 64;
	// addi r5,r10,64
	ctx.r5.s64 = ctx.r10.s64 + 64;
	// addi r4,r11,64
	ctx.r4.s64 = ctx.r11.s64 + 64;
	// addi r3,r8,64
	ctx.r3.s64 = ctx.r8.s64 + 64;
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r11,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 8;
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r6,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 8;
	// srawi r8,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 8;
	// srawi r5,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 8;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r5,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x827e5b20
	goto loc_827E5B20;
loc_827E5A9C:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x827e5aec
	if (ctx.cr6.eq) goto loc_827E5AEC;
	// mullw r5,r8,r10
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r11,r7
	ctx.r4.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// mullw r3,r8,r7
	ctx.r3.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// addi r8,r8,255
	ctx.r8.s64 = ctx.r8.s64 + 255;
	// addi r7,r7,255
	ctx.r7.s64 = ctx.r7.s64 + 255;
	// srawi r11,r11,9
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1FF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 9;
	// srawi r6,r10,9
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 9;
	// srawi r8,r8,9
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 9;
	// srawi r5,r7,9
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1FF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 9;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r5,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x827e5b20
	goto loc_827E5B20;
loc_827E5AEC:
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addi r6,r6,128
	ctx.r6.s64 = ctx.r6.s64 + 128;
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// addi r3,r8,128
	ctx.r3.s64 = ctx.r8.s64 + 128;
	// srawi r11,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 8;
	// srawi r10,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 8;
	// srawi r8,r4,8
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 8;
	// srawi r7,r3,8
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 8;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
loc_827E5B20:
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r18,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r9,r10,r16
	ctx.r9.u64 = ctx.r10.u64 + ctx.r16.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// add r5,r17,r18
	ctx.r5.u64 = ctx.r17.u64 + ctx.r18.u64;
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// stw r6,608(r1)
	REX_STORE_U32(ctx.r1.u32 + 608, ctx.r6.u32);
	// sth r4,2(r9)
	REX_STORE_U16(ctx.r9.u32 + 2, ctx.r4.u16);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r3,616(r1)
	REX_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// rlwinm r10,r18,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r14,r4
	ctx.r14.u64 = ctx.r4.u64;
	// add r7,r7,r16
	ctx.r7.u64 = ctx.r7.u64 + ctx.r16.u64;
	// mr r15,r30
	ctx.r15.u64 = ctx.r30.u64;
	// lwz r8,1836(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// sth r4,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r4.u16);
	// lwz r8,1836(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r4,r8,r11
	REX_STORE_U16(ctx.r8.u32 + ctx.r11.u32, ctx.r4.u16);
	// lwz r8,1836(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// sth r4,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r4.u16);
	// lwz r8,1836(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r4,r8,r10
	REX_STORE_U16(ctx.r8.u32 + ctx.r10.u32, ctx.r4.u16);
	// sth r30,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r30.u16);
	// lwz r8,1840(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// sth r30,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r30.u16);
	// lwz r4,1840(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r30,r4,r11
	REX_STORE_U16(ctx.r4.u32 + ctx.r11.u32, ctx.r30.u16);
	// lwz r8,1840(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// sth r30,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r30.u16);
	// lwz r5,1840(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r30,r5,r10
	REX_STORE_U16(ctx.r5.u32 + ctx.r10.u32, ctx.r30.u16);
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r4.u32);
	// stw r4,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// stw r4,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// lwz r9,1844(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// sth r3,2(r9)
	REX_STORE_U16(ctx.r9.u32 + 2, ctx.r3.u16);
	// lwz r8,1844(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r3,r8,r11
	REX_STORE_U16(ctx.r8.u32 + ctx.r11.u32, ctx.r3.u16);
	// lwz r9,1844(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r3,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r3.u16);
	// lwz r5,1844(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r3,r5,r10
	REX_STORE_U16(ctx.r5.u32 + ctx.r10.u32, ctx.r3.u16);
	// lwz r9,1848(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// sth r6,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r6.u16);
	// lwz r3,1848(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r6,r11,r3
	REX_STORE_U16(ctx.r11.u32 + ctx.r3.u32, ctx.r6.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r6,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r6.u16);
	// lwz r9,1848(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r6,r10,r9
	REX_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u16);
loc_827E5C24:
	// lwz r16,628(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 628);
	// clrlwi r10,r15,31
	ctx.r10.u64 = ctx.r15.u32 & 0x1;
	// li r17,0
	ctx.r17.s64 = 0;
	// slw r11,r14,r16
	ctx.r11.u64 = ctx.r16.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r16.u8 & 0x3F));
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e5c64
	if (ctx.cr6.eq) goto loc_827E5C64;
	// lwz r10,448(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 448);
	// slw r9,r15,r16
	ctx.r9.u64 = ctx.r16.u8 & 0x20 ? 0 : (ctx.r15.u32 << (ctx.r16.u8 & 0x3F));
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rlwinm r6,r8,0,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwimi r7,r29,3,31,28
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r7.u64 & 0x6);
	// srawi r5,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 1;
	// or r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 | ctx.r6.u64;
	// b 0x827e5c7c
	goto loc_827E5C7C;
loc_827E5C64:
	// slw r10,r15,r16
	ctx.r10.u64 = ctx.r16.u8 & 0x20 ? 0 : (ctx.r15.u32 << (ctx.r16.u8 & 0x3F));
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// rlwinm r8,r10,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// or r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 | ctx.r8.u64;
loc_827E5C7C:
	// lwz r23,128(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// lwz r28,116(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r10,r23,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 17) & 0xFFFE0000;
	// lwz r9,300(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// rlwinm r7,r11,1,15,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// or r8,r10,r28
	ctx.r8.u64 = ctx.r10.u64 | ctx.r28.u64;
	// rlwinm r19,r8,6,0,25
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r10,r7,r19
	ctx.r10.u64 = ctx.r19.u64 - ctx.r7.u64;
	// subf r6,r19,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r19.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// addis r3,r5,128
	ctx.r3.s64 = ctx.r5.s64 + 8388608;
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r9,r9,0,16,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827e5db0
	if (ctx.cr6.eq) goto loc_827E5DB0;
	// lwz r10,1368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// srawi r6,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r4,r28,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r23,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// rlwinm r10,r6,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// bne cr6,0x827e5d08
	if (!ctx.cr6.eq) goto loc_827E5D08;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x827e5d24
	if (ctx.cr6.eq) goto loc_827E5D24;
	// li r7,-35
	ctx.r7.s64 = -35;
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// b 0x827e5d2c
	goto loc_827E5D2C;
loc_827E5D08:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x827e5d24
	if (ctx.cr6.eq) goto loc_827E5D24;
	// li r7,-37
	ctx.r7.s64 = -37;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// b 0x827e5d2c
	goto loc_827E5D2C;
loc_827E5D24:
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// li r7,-36
	ctx.r7.s64 = -36;
loc_827E5D2C:
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// cmpwi cr6,r10,-17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -17, ctx.xer);
	// bge cr6,0x827e5d4c
	if (!ctx.cr6.lt) goto loc_827E5D4C;
	// li r10,-17
	ctx.r10.s64 = -17;
	// b 0x827e5d60
	goto loc_827E5D60;
loc_827E5D4C:
	// lhz r8,50(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x827e5d64
	if (!ctx.cr6.gt) goto loc_827E5D64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_827E5D60:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E5D64:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x827e5d74
	if (!ctx.cr6.lt) goto loc_827E5D74;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x827e5d8c
	goto loc_827E5D8C;
loc_827E5D74:
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x827e5d84
	if (!ctx.cr6.gt) goto loc_827E5D84;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x827e5d8c
	goto loc_827E5D8C;
loc_827E5D84:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x827e5dac
	if (ctx.cr6.eq) goto loc_827E5DAC;
loc_827E5D8C:
	// subf r8,r4,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r9,r6,30
	ctx.r9.u64 = ctx.r6.u32 & 0x3;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_827E5DAC:
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827E5DB0:
	// srawi r15,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r15.s64 = ctx.r11.s32 >> 16;
	// extsh r14,r11
	ctx.r14.s64 = ctx.r11.s16;
	// stw r15,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r15.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r14,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r14.u32);
	// clrlwi r20,r15,30
	ctx.r20.u64 = ctx.r15.u32 & 0x3;
	// beq cr6,0x827e5df8
	if (ctx.cr6.eq) goto loc_827E5DF8;
	// lwz r10,1368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// or r5,r6,r20
	ctx.r5.u64 = ctx.r6.u64 | ctx.r20.u64;
	// subf r11,r9,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r9.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x827e5e04
	goto loc_827E5E04;
loc_827E5DF8:
	// srawi r11,r15,3
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r15.s32 >> 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r10,r20
	ctx.r11.u64 = ctx.r10.u64 | ctx.r20.u64;
loc_827E5E04:
	// clrlwi r21,r14,30
	ctx.r21.u64 = ctx.r14.u32 & 0x3;
	// lbz r9,31(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r10,r11,30
	ctx.r10.u64 = ctx.r11.u32 & 0x3;
	// addi r8,r21,1
	ctx.r8.s64 = ctx.r21.s64 + 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// srawi r10,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r6,r10,r14
	ctx.r6.u64 = ctx.r10.u64 + ctx.r14.u64;
	// srawi r10,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 1;
	// srawi r9,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 2;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// beq cr6,0x827e5e78
	if (ctx.cr6.eq) goto loc_827E5E78;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e5e58
	if (ctx.cr6.eq) goto loc_827E5E58;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x827e5e54
	if (!ctx.cr6.gt) goto loc_827E5E54;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x827e5e58
	goto loc_827E5E58;
loc_827E5E54:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_827E5E58:
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e5e78
	if (ctx.cr6.eq) goto loc_827E5E78;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827e5e74
	if (!ctx.cr6.gt) goto loc_827E5E74;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x827e5e78
	goto loc_827E5E78;
loc_827E5E74:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_827E5E78:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x827e5e90
	if (ctx.cr6.eq) goto loc_827E5E90;
	// lwz r9,1368(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
loc_827E5E90:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,468(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r8,352(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r11,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r4,r11,15,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF0000;
	// or r3,r5,r7
	ctx.r3.u64 = ctx.r5.u64 | ctx.r7.u64;
	// or r11,r4,r7
	ctx.r11.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r10,r23,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 16) & 0xFFFF0000;
	// stwx r3,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r3.u32);
	// rlwinm r9,r11,1,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// lwz r5,316(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// or r8,r10,r28
	ctx.r8.u64 = ctx.r10.u64 | ctx.r28.u64;
	// subf r10,r9,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rlwinm r22,r8,5,0,26
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r4,r11,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r11.u64;
	// add r7,r10,r22
	ctx.r7.u64 = ctx.r10.u64 + ctx.r22.u64;
	// subf r3,r22,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r22.u64;
	// addis r6,r7,24
	ctx.r6.s64 = ctx.r7.s64 + 1572864;
	// addi r6,r6,20
	ctx.r6.s64 = ctx.r6.s64 + 20;
	// or r10,r6,r3
	ctx.r10.u64 = ctx.r6.u64 | ctx.r3.u64;
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r9,r9,0,16,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x827e5f8c
	if (ctx.cr6.eq) goto loc_827E5F8C;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lhz r7,52(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhz r5,50(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// rlwinm r10,r28,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// rlwinm r8,r23,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x827e5f48
	if (!ctx.cr6.lt) goto loc_827E5F48;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// b 0x827e5f5c
	goto loc_827E5F5C;
loc_827E5F48:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x827e5f5c
	if (!ctx.cr6.gt) goto loc_827E5F5C;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_827E5F5C:
	// cmpwi cr6,r8,-9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -9, ctx.xer);
	// bge cr6,0x827e5f74
	if (!ctx.cr6.lt) goto loc_827E5F74;
	// addi r10,r8,9
	ctx.r10.s64 = ctx.r8.s64 + 9;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// b 0x827e5f88
	goto loc_827E5F88;
loc_827E5F74:
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x827e5f88
	if (!ctx.cr6.gt) goto loc_827E5F88;
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_827E5F88:
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827E5F8C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// srawi r24,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r24.s64 = ctx.r11.s32 >> 16;
	// lwz r11,180(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// extsh r25,r10
	ctx.r25.s64 = ctx.r10.s16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x827e890c
	if (ctx.cr6.gt) goto loc_827E890C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e63d8
	if (ctx.cr6.eq) goto loc_827E63D8;
	// bdz 0x827e63d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_827E63D8;
	// bdz 0x827e6270
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_827E6270;
	// lhz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r9,r15,2
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r15.s32 >> 2;
	// lwz r10,1060(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r8,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r14.s32 >> 2;
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r30,76(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// srawi r3,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 2;
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// srawi r9,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x827e6000
	if (!ctx.cr6.eq) goto loc_827E6000;
	// lwz r6,504(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// lwz r5,508(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 508);
	// lwz r4,488(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 488);
	// b 0x827e600c
	goto loc_827E600C;
loc_827E6000:
	// lwz r6,480(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r5,484(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 484);
	// lwz r4,464(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
loc_827E600C:
	// add r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lhz r28,90(r31)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r31.u32 + 90);
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mullw r9,r3,r30
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r29,r6,r9
	ctx.r29.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r30,r7,r9
	ctx.r30.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,560(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// add r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,576(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 576);
	// lwz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 580);
	// li r6,128
	ctx.r6.s64 = 128;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r23,r8,r11
	ctx.r23.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r22,r7,r11
	ctx.r22.u64 = ctx.r7.u64 + ctx.r11.u64;
	// dcbt r6,r27
	// addi r5,r28,128
	ctx.r5.s64 = ctx.r28.s64 + 128;
	// dcbt r5,r27
	// addi r4,r28,64
	ctx.r4.s64 = ctx.r28.s64 + 64;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r3,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r27
	// addi r10,r28,32
	ctx.r10.s64 = ctx.r28.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r9,r27
	// rotlwi r11,r28,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 2);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r7,r28,r11
	ctx.r7.u64 = ctx.r28.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r27
	// rotlwi r5,r28,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r28.u32, 3);
	// subf r11,r28,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r28.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r27
	// lbz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bne cr6,0x827e6120
	if (!ctx.cr6.eq) goto loc_827E6120;
	// addi r11,r21,52
	ctx.r11.s64 = ctx.r21.s64 + 52;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E60F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827e613c
	if (ctx.cr6.eq) goto loc_827E613C;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827828d0
	ctx.lr = 0x827E611C;
	sub_827828D0(ctx, base);
	// b 0x827e613c
	goto loc_827E613C;
loc_827E6120:
	// addi r11,r21,56
	ctx.r11.s64 = ctx.r21.s64 + 56;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E613C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827E613C:
	// lhz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r30
	// addi r10,r4,128
	ctx.r10.s64 = ctx.r4.s64 + 128;
	// dcbt r10,r30
	// addi r9,r4,64
	ctx.r9.s64 = ctx.r4.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r30
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r30
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r10,r30
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r30
	// clrlwi r11,r25,30
	ctx.r11.u64 = ctx.r25.u32 & 0x3;
	// clrlwi r10,r24,30
	ctx.r10.u64 = ctx.r24.u32 & 0x3;
	// addi r6,r11,56
	ctx.r6.s64 = ctx.r11.s64 + 56;
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// rlwinm r28,r3,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r11,r28,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E61E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r29
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// dcbt r9,r29
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r7,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r29
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r3,r29
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r29
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// lwzx r11,r28,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E626C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x827e890c
	goto loc_827E890C;
loc_827E6270:
	// lhz r11,74(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r9,r15,2
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r15.s32 >> 2;
	// lwz r10,1060(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r8,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r14.s32 >> 2;
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r30,76(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// srawi r3,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 2;
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// srawi r9,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x827e62b8
	if (!ctx.cr6.eq) goto loc_827E62B8;
	// lwz r6,552(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r5,556(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// lwz r4,536(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 536);
	// b 0x827e62c4
	goto loc_827E62C4;
loc_827E62B8:
	// lwz r6,528(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 528);
	// lwz r5,532(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r4,512(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
loc_827E62C4:
	// add r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lhz r28,90(r31)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r31.u32 + 90);
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mullw r9,r3,r30
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r29,r6,r9
	ctx.r29.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r30,r7,r9
	ctx.r30.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,560(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// add r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,576(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 576);
	// lwz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 580);
	// li r6,128
	ctx.r6.s64 = 128;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r23,r8,r11
	ctx.r23.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r22,r7,r11
	ctx.r22.u64 = ctx.r7.u64 + ctx.r11.u64;
	// dcbt r6,r27
	// addi r5,r28,128
	ctx.r5.s64 = ctx.r28.s64 + 128;
	// dcbt r5,r27
	// addi r4,r28,64
	ctx.r4.s64 = ctx.r28.s64 + 64;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r3,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r27
	// addi r10,r28,32
	ctx.r10.s64 = ctx.r28.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r9,r27
	// rotlwi r11,r28,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 2);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r7,r28,r11
	ctx.r7.u64 = ctx.r28.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r27
	// rotlwi r5,r28,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r28.u32, 3);
	// subf r11,r28,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r28.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r27
	// lbz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bne cr6,0x827e6120
	if (!ctx.cr6.eq) goto loc_827E6120;
	// addi r11,r21,52
	ctx.r11.s64 = ctx.r21.s64 + 52;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E63AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827e613c
	if (ctx.cr6.eq) goto loc_827E613C;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827828d0
	ctx.lr = 0x827E63D4;
	sub_827828D0(ctx, base);
	// b 0x827e613c
	goto loc_827E613C;
loc_827E63D8:
	// lhz r30,74(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r11,r15,2
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r15.s32 >> 2;
	// lwz r18,1060(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r9,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r14.s32 >> 2;
	// rlwinm r10,r30,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// lhz r29,76(r31)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r4,8(r18)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r18.u32 + 8);
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// srawi r3,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 2;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// srawi r11,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x827e6420
	if (!ctx.cr6.eq) goto loc_827E6420;
	// lwz r7,504(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// lwz r6,508(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 508);
	// lwz r5,488(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 488);
	// b 0x827e642c
	goto loc_827E642C;
loc_827E6420:
	// lwz r7,480(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r6,484(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 484);
	// lwz r5,464(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
loc_827E642C:
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r27,616(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 616);
	// add r7,r6,r11
	ctx.r7.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r11,r3,r29
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r29.s32);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r29,r8,r11
	ctx.r29.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r26,r9,r4
	ctx.r26.u64 = ctx.r9.u64 + ctx.r4.u64;
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r26
	// addi r10,r30,128
	ctx.r10.s64 = ctx.r30.s64 + 128;
	// dcbt r10,r26
	// addi r9,r30,64
	ctx.r9.s64 = ctx.r30.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r26
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r26
	// addi r6,r30,32
	ctx.r6.s64 = ctx.r30.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r26
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r26
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r30,r11
	ctx.r3.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r26
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r30,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r30.u64;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r26
	// lbz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// rlwinm r11,r21,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bne cr6,0x827e6540
	if (!ctx.cr6.eq) goto loc_827E6540;
	// addi r11,r11,241
	ctx.r11.s64 = ctx.r11.s64 + 241;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwzx r11,r3,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E650C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827e6604
	if (ctx.cr6.eq) goto loc_827E6604;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x827826a0
	ctx.lr = 0x827E653C;
	sub_827826A0(ctx, base);
	// b 0x827e6604
	goto loc_827E6604;
loc_827E6540:
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// addi r11,r11,257
	ctx.r11.s64 = ctx.r11.s64 + 257;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// rlwinm r23,r11,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwzx r11,r23,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6568;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// lwzx r11,r23,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r27,8
	ctx.r5.s64 = ctx.r27.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r3,r26,8
	ctx.r3.s64 = ctx.r26.s64 + 8;
	// bctrl 
	ctx.lr = 0x827E6598;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// rlwinm r11,r30,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r27,128
	ctx.r5.s64 = ctx.r27.s64 + 128;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwzx r11,r23,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E65D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwzx r11,r23,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r27,136
	ctx.r5.s64 = ctx.r27.s64 + 136;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r26,8
	ctx.r3.s64 = ctx.r26.s64 + 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r23,128(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
loc_827E6604:
	// lhz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r29
	// addi r10,r4,128
	ctx.r10.s64 = ctx.r4.s64 + 128;
	// dcbt r10,r29
	// addi r9,r4,64
	ctx.r9.s64 = ctx.r4.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r29
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r10,r29
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r29
	// clrlwi r30,r24,30
	ctx.r30.u64 = ctx.r24.u32 & 0x3;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// rlwinm r11,r25,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xC;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// clrlwi r26,r25,30
	ctx.r26.u64 = ctx.r25.u32 & 0x3;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r7,r11,257
	ctx.r7.s64 = ctx.r11.s64 + 257;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r27,256
	ctx.r5.s64 = ctx.r27.s64 + 256;
	// lwzx r11,r3,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E66B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r28
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// dcbt r9,r28
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r7,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r28
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r3,r28
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r28
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r28
	// rlwinm r11,r25,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xC;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r6,r11,257
	ctx.r6.s64 = ctx.r11.s64 + 257;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r27,320
	ctx.r5.s64 = ctx.r27.s64 + 320;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bctrl 
	ctx.lr = 0x827E6764;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,608(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 608);
	// lwz r9,616(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 616);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// slw r11,r9,r16
	ctx.r11.u64 = ctx.r16.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r16.u8 & 0x3F));
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e67a4
	if (ctx.cr6.eq) goto loc_827E67A4;
	// lwz r9,448(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 448);
	// slw r8,r10,r16
	ctx.r8.u64 = ctx.r16.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r16.u8 & 0x3F));
	// subf r7,r9,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r9.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm r5,r7,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwimi r6,r29,3,31,28
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r6.u64 & 0x6);
	// srawi r4,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// or r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 | ctx.r5.u64;
	// b 0x827e67bc
	goto loc_827E67BC;
loc_827E67A4:
	// slw r10,r10,r16
	ctx.r10.u64 = ctx.r16.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r16.u8 & 0x3F));
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// rlwinm r8,r10,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// or r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 | ctx.r8.u64;
loc_827E67BC:
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// lwz r10,300(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// rlwinm r9,r11,1,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r10,r9,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r7,r19,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r19.u64;
	// add r6,r10,r19
	ctx.r6.u64 = ctx.r10.u64 + ctx.r19.u64;
	// addis r5,r6,128
	ctx.r5.s64 = ctx.r6.s64 + 8388608;
	// addi r5,r5,56
	ctx.r5.s64 = ctx.r5.s64 + 56;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r3,r4,0,0,16
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r3,r3,0,16,0
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827e68e0
	if (ctx.cr6.eq) goto loc_827E68E0;
	// lwz r10,1368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// srawi r6,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 16;
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r4,r8,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r23,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// rlwinm r10,r6,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// bne cr6,0x827e6838
	if (!ctx.cr6.eq) goto loc_827E6838;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x827e6854
	if (ctx.cr6.eq) goto loc_827E6854;
	// li r7,-35
	ctx.r7.s64 = -35;
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// b 0x827e685c
	goto loc_827E685C;
loc_827E6838:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x827e6854
	if (ctx.cr6.eq) goto loc_827E6854;
	// li r7,-37
	ctx.r7.s64 = -37;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// b 0x827e685c
	goto loc_827E685C;
loc_827E6854:
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// li r7,-36
	ctx.r7.s64 = -36;
loc_827E685C:
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// cmpwi cr6,r10,-17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -17, ctx.xer);
	// bge cr6,0x827e687c
	if (!ctx.cr6.lt) goto loc_827E687C;
	// li r10,-17
	ctx.r10.s64 = -17;
	// b 0x827e6890
	goto loc_827E6890;
loc_827E687C:
	// lhz r8,50(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x827e6894
	if (!ctx.cr6.gt) goto loc_827E6894;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_827E6890:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E6894:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x827e68a4
	if (!ctx.cr6.lt) goto loc_827E68A4;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x827e68bc
	goto loc_827E68BC;
loc_827E68A4:
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x827e68b4
	if (!ctx.cr6.gt) goto loc_827E68B4;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x827e68bc
	goto loc_827E68BC;
loc_827E68B4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x827e68dc
	if (ctx.cr6.eq) goto loc_827E68DC;
loc_827E68BC:
	// subf r8,r4,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r9,r6,30
	ctx.r9.u64 = ctx.r6.u32 & 0x3;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_827E68DC:
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827E68E0:
	// srawi r4,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 16;
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// stw r4,608(r1)
	REX_STORE_U32(ctx.r1.u32 + 608, ctx.r4.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r3,616(r1)
	REX_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// clrlwi r20,r4,30
	ctx.r20.u64 = ctx.r4.u32 & 0x3;
	// beq cr6,0x827e6928
	if (ctx.cr6.eq) goto loc_827E6928;
	// lwz r10,1368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// or r5,r6,r20
	ctx.r5.u64 = ctx.r6.u64 | ctx.r20.u64;
	// subf r11,r9,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r9.u64;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// b 0x827e6934
	goto loc_827E6934;
loc_827E6928:
	// srawi r11,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r10,r10,r20
	ctx.r10.u64 = ctx.r10.u64 | ctx.r20.u64;
loc_827E6934:
	// clrlwi r21,r3,30
	ctx.r21.u64 = ctx.r3.u32 & 0x3;
	// lbz r9,31(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r11,r10,30
	ctx.r11.u64 = ctx.r10.u32 & 0x3;
	// addi r8,r21,1
	ctx.r8.s64 = ctx.r21.s64 + 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r6,r11,r3
	ctx.r6.u64 = ctx.r11.u64 + ctx.r3.u64;
	// srawi r11,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 1;
	// srawi r9,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 2;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// srawi r10,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// beq cr6,0x827e69a8
	if (ctx.cr6.eq) goto loc_827E69A8;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e6988
	if (ctx.cr6.eq) goto loc_827E6988;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827e6984
	if (!ctx.cr6.gt) goto loc_827E6984;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x827e6988
	goto loc_827E6988;
loc_827E6984:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_827E6988:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827e69a8
	if (ctx.cr6.eq) goto loc_827E69A8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x827e69a4
	if (!ctx.cr6.gt) goto loc_827E69A4;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x827e69a8
	goto loc_827E69A8;
loc_827E69A4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_827E69A8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x827e69c0
	if (ctx.cr6.eq) goto loc_827E69C0;
	// lwz r9,1368(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
loc_827E69C0:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,316(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// subf r7,r22,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r22.u64;
	// rlwimi r11,r8,15,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 15) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// rlwinm r6,r11,1,15,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// subf r5,r11,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r10,r6,r22
	ctx.r10.u64 = ctx.r22.u64 - ctx.r6.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addis r9,r10,24
	ctx.r9.s64 = ctx.r10.s64 + 1572864;
	// addi r9,r9,20
	ctx.r9.s64 = ctx.r9.s64 + 20;
	// or r8,r9,r5
	ctx.r8.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwinm r7,r8,0,0,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r7,r7,0,16,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x827e6a94
	if (ctx.cr6.eq) goto loc_827E6A94;
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhz r7,52(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r5,50(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// rlwinm r8,r23,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x827e6a50
	if (!ctx.cr6.lt) goto loc_827E6A50;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// b 0x827e6a64
	goto loc_827E6A64;
loc_827E6A50:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x827e6a64
	if (!ctx.cr6.gt) goto loc_827E6A64;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_827E6A64:
	// cmpwi cr6,r8,-9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -9, ctx.xer);
	// bge cr6,0x827e6a7c
	if (!ctx.cr6.lt) goto loc_827E6A7C;
	// addi r10,r8,9
	ctx.r10.s64 = ctx.r8.s64 + 9;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// b 0x827e6a90
	goto loc_827E6A90;
loc_827E6A7C:
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x827e6a90
	if (!ctx.cr6.gt) goto loc_827E6A90;
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_827E6A90:
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827E6A94:
	// lhz r26,74(r31)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r23,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r23.s64 = ctx.r11.s32 >> 16;
	// extsh r24,r11
	ctx.r24.s64 = ctx.r11.s16;
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// srawi r11,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 2;
	// lhz r30,76(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r8,r26,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r4,8(r18)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r18.u32 + 8);
	// srawi r9,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 2;
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// srawi r3,r23,2
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r23.s32 >> 2;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// srawi r11,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r24.s32 >> 2;
	// bne cr6,0x827e6ae0
	if (!ctx.cr6.eq) goto loc_827E6AE0;
	// lwz r7,552(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r6,556(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// lwz r5,536(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 536);
	// b 0x827e6aec
	goto loc_827E6AEC;
loc_827E6AE0:
	// lwz r7,528(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 528);
	// lwz r6,532(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r5,512(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
loc_827E6AEC:
	// add r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// lwz r30,428(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r29,r8,r10
	ctx.r29.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r25,r9,r4
	ctx.r25.u64 = ctx.r9.u64 + ctx.r4.u64;
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r25
	// addi r10,r26,128
	ctx.r10.s64 = ctx.r26.s64 + 128;
	// dcbt r10,r25
	// addi r9,r26,64
	ctx.r9.s64 = ctx.r26.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r25
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r25
	// addi r6,r26,32
	ctx.r6.s64 = ctx.r26.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r25
	// rlwinm r11,r26,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r25
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r26,r11
	ctx.r3.u64 = ctx.r26.u64 + ctx.r11.u64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r25
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r26,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r26.u64;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r25
	// lbz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// rlwinm r11,r21,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bne cr6,0x827e6c00
	if (!ctx.cr6.eq) goto loc_827E6C00;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// addi r11,r11,241
	ctx.r11.s64 = ctx.r11.s64 + 241;
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwzx r11,r3,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6BCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827e6cc0
	if (ctx.cr6.eq) goto loc_827E6CC0;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x827826a0
	ctx.lr = 0x827E6BFC;
	sub_827826A0(ctx, base);
	// b 0x827e6cc0
	goto loc_827E6CC0;
loc_827E6C00:
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// addi r11,r11,257
	ctx.r11.s64 = ctx.r11.s64 + 257;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// rlwinm r22,r11,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwzx r11,r22,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// lwzx r11,r22,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r30,8
	ctx.r5.s64 = ctx.r30.s64 + 8;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r3,r25,8
	ctx.r3.s64 = ctx.r25.s64 + 8;
	// bctrl 
	ctx.lr = 0x827E6C58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r26,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r30,128
	ctx.r5.s64 = ctx.r30.s64 + 128;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwzx r11,r22,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6C90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwzx r11,r22,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r30,136
	ctx.r5.s64 = ctx.r30.s64 + 136;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r25,8
	ctx.r3.s64 = ctx.r25.s64 + 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6CC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827E6CC0:
	// lhz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r29
	// addi r10,r4,128
	ctx.r10.s64 = ctx.r4.s64 + 128;
	// dcbt r10,r29
	// addi r9,r4,64
	ctx.r9.s64 = ctx.r4.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r29
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r10,r29
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r29
	// clrlwi r26,r23,30
	ctx.r26.u64 = ctx.r23.u32 & 0x3;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// rlwinm r11,r24,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xC;
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// clrlwi r25,r24,30
	ctx.r25.u64 = ctx.r24.u32 & 0x3;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r7,r11,257
	ctx.r7.s64 = ctx.r11.s64 + 257;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r30,256
	ctx.r5.s64 = ctx.r30.s64 + 256;
	// lwzx r11,r3,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E6D74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,76(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r28
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// dcbt r9,r28
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r7,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r28
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r3,r28
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r28
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r28
	// rlwinm r11,r24,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xC;
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// stw r17,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r6,r11,257
	ctx.r6.s64 = ctx.r11.s64 + 257;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r30,320
	ctx.r5.s64 = ctx.r30.s64 + 320;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bctrl 
	ctx.lr = 0x827E6E20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r25,16
	ctx.r25.s64 = 16;
	// li r24,32
	ctx.r24.s64 = 32;
	// lhz r4,74(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// li r23,48
	ctx.r23.s64 = 48;
	// lwz r11,560(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 560);
	// lwz r10,8(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 8);
	// li r22,64
	ctx.r22.s64 = 64;
	// li r21,80
	ctx.r21.s64 = 80;
	// lvx128 v0,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r20,96
	ctx.r20.s64 = 96;
	// lvx128 v13,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r19,112
	ctx.r19.s64 = 112;
	// lvx128 v10,r27,r25
	ea = (ctx.r27.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r30,r25
	ea = (ctx.r30.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rotlwi r29,r4,1
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// lvx128 v9,r30,r24
	ea = (ctx.r30.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r27,r24
	ea = (ctx.r27.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v11,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v6,r30,r23
	ea = (ctx.r30.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r3,r4,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lvx128 v4,r27,r23
	ea = (ctx.r27.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v8,v10,v12
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// lvx128 v3,r30,r22
	ea = (ctx.r30.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r28,r29,r4
	ctx.r28.u64 = ctx.r29.u64 + ctx.r4.u64;
	// lvx128 v1,r27,r22
	ea = (ctx.r27.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v5,v7,v9
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// lvx128 v31,r30,r21
	ea = (ctx.r30.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r30,128
	ctx.r6.s64 = ctx.r30.s64 + 128;
	// lvx128 v29,r27,r21
	ea = (ctx.r27.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v2,v4,v6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v28,r30,r20
	ea = (ctx.r30.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,576(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 576);
	// lvx128 v26,r30,r19
	ea = (ctx.r30.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r9,76(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// lvx128 v25,r27,r20
	ea = (ctx.r27.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r27,128
	ctx.r7.s64 = ctx.r27.s64 + 128;
	// lvx128 v24,r27,r19
	ea = (ctx.r27.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v30,v1,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// add r30,r3,r4
	ctx.r30.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lwz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 580);
	// stvx128 v11,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v27,v29,v31
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// add r27,r3,r29
	ctx.r27.u64 = ctx.r3.u64 + ctx.r29.u64;
	// stvx128 v8,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r26,r28,r3
	ctx.r26.u64 = ctx.r28.u64 + ctx.r3.u64;
	// vavgub v23,v25,v28
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// stvx128 v5,r29,r8
	ea = (ctx.r29.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v22,v24,v26
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// stvx128 v2,r28,r8
	ea = (ctx.r28.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r17,r1,800
	ctx.r17.s64 = ctx.r1.s64 + 800;
	// stvx128 v27,r30,r8
	ea = (ctx.r30.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r16,r1,736
	ctx.r16.s64 = ctx.r1.s64 + 736;
	// stvx128 v23,r27,r8
	ea = (ctx.r27.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stvx128 v22,r26,r8
	ea = (ctx.r26.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// rotlwi r5,r4,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// lvx128 v15,r6,r21
	ea = (ctx.r6.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r6,r22
	ea = (ctx.r6.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v18,r7,r22
	ea = (ctx.r7.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r6,r25
	ea = (ctx.r6.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v19,r7,r25
	ea = (ctx.r7.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v13,v19,v21
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v21.u8)));
	// vavgub v10,v18,v17
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)ctx.v17.u8)));
	// lvx128 v20,r7,r23
	ea = (ctx.r7.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v16,r7,r24
	ea = (ctx.r7.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v14,r6,r24
	ea = (ctx.r6.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r6,r23
	ea = (ctx.r6.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 + ctx.r8.u64;
	// vavgub v7,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// lvx128 v6,r7,r21
	ea = (ctx.r7.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v12,v16,v14
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)ctx.v14.u8)));
	// lvx128 v3,r6,r20
	ea = (ctx.r6.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v11,v20,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v2,r6,r19
	ea = (ctx.r6.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r7,r20
	ea = (ctx.r7.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v9,v6,v15
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// lvx128 v4,r7,r19
	ea = (ctx.r7.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v8,v5,v3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// stvx128 v7,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v0,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// stvx128 v13,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,128
	ctx.r5.s64 = ctx.r7.s64 + 128;
	// stvx128 v12,r29,r8
	ea = (ctx.r29.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r6,128
	ctx.r7.s64 = ctx.r6.s64 + 128;
	// stvx128 v11,r28,r8
	ea = (ctx.r28.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,768
	ctx.r6.s64 = ctx.r1.s64 + 768;
	// stvx128 v10,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,768
	ctx.r29.s64 = ctx.r1.s64 + 768;
	// stvx128 v9,r30,r8
	ea = (ctx.r30.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// stvx128 v8,r27,r8
	ea = (ctx.r27.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// stvx128 v0,r26,r8
	ea = (ctx.r26.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,752
	ctx.r30.s64 = ctx.r1.s64 + 752;
	// stvx128 v12,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,848
	ctx.r6.s64 = ctx.r1.s64 + 848;
	// addi r28,r1,784
	ctx.r28.s64 = ctx.r1.s64 + 784;
	// addi r27,r1,832
	ctx.r27.s64 = ctx.r1.s64 + 832;
	// addi r8,r1,816
	ctx.r8.s64 = ctx.r1.s64 + 816;
	// stvx128 v11,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// stvx128 v9,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,784
	ctx.r30.s64 = ctx.r1.s64 + 784;
	// stvx128 v8,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,816
	ctx.r28.s64 = ctx.r1.s64 + 816;
	// addi r26,r1,800
	ctx.r26.s64 = ctx.r1.s64 + 800;
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v25,r5,r24
	ea = (ctx.r5.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r5,r20
	ea = (ctx.r5.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v31,r5,r21
	ea = (ctx.r5.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v28,r5,r25
	ea = (ctx.r5.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r7,r21
	ea = (ctx.r7.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v18,r7,r20
	ea = (ctx.r7.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r7,r19
	ea = (ctx.r7.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r7,r22
	ea = (ctx.r7.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v23,r5,r22
	ea = (ctx.r5.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v20,r7,r23
	ea = (ctx.r7.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v15,r5,r19
	ea = (ctx.r5.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r7,r25
	ea = (ctx.r7.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r7,r24
	ea = (ctx.r7.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v12,v25,v27
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)ctx.v27.u8)));
	// vavgub v19,v22,v21
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)ctx.v21.u8)));
	// stvx128 v12,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v13,v28,v26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v26.u8)));
	// lvx128 v24,r5,r23
	ea = (ctx.r5.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v16,v17,v18
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)));
	// vavgub v0,v31,v30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v30.u8)));
	// stvx128 v19,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v14,v15,v1
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// stvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v11,v24,v20
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v20.u8)));
	// vavgub v10,v23,v29
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// stvx128 v16,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,768(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 768);
	// stvx128 v14,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,772(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 772);
	// lwz r30,776(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 776);
	// lwz r29,848(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 848);
	// lwz r8,736(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 736);
	// lwz r7,740(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 740);
	// lwz r6,744(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 744);
	// lwz r5,748(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 748);
	// lwz r28,852(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 852);
	// lwz r27,856(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 856);
	// stw r29,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
	// lwz r26,860(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 860);
	// lwz r25,780(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 780);
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// stwux r27,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r10.u32 = ea;
	// lwz r29,832(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 832);
	// lwz r28,836(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 836);
	// lwz r27,840(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 840);
	// lwz r24,844(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 844);
	// stw r26,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r26.u32);
	// stwux r8,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwz r8,800(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 800);
	// lwz r26,804(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 804);
	// lwz r23,808(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 808);
	// lwz r22,812(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 812);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stwux r6,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r10.u32 = ea;
	// lwz r7,752(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 752);
	// lwz r6,756(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 756);
	// lwz r21,760(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 760);
	// lwz r20,764(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 764);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// stwux r4,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r4.u32);
	ctx.r10.u32 = ea;
	// lwz r5,784(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 784);
	// lwz r4,788(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 788);
	// lwz r19,792(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 792);
	// lwz r18,796(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 796);
	// stw r3,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// stwux r30,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r10.u32 = ea;
	// lwz r3,816(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 816);
	// lwz r30,820(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 820);
	// lwz r17,824(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 824);
	// lwz r16,828(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 828);
	// stw r25,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r25.u32);
	// stwux r29,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r29.u32);
	ctx.r10.u32 = ea;
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// stwux r27,r10,r9
	ea = ctx.r10.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r10.u32 = ea;
	// stw r24,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r24.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
	// stwux r23,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r23.u32);
	ctx.r11.u32 = ea;
	// stw r22,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// stwux r7,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stwux r21,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r21.u32);
	ctx.r11.u32 = ea;
	// stw r20,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r20.u32);
	// stwux r5,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r5.u32);
	ctx.r11.u32 = ea;
	// stw r4,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r4.u32);
	// stwux r19,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r19.u32);
	ctx.r11.u32 = ea;
	// stw r18,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r18.u32);
	// stwux r3,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// stw r30,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stwux r17,r11,r9
	ea = ctx.r11.u32 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r17.u32);
	ctx.r11.u32 = ea;
	// stw r16,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r16.u32);
	// b 0x827e890c
	goto loc_827E890C;
loc_827E7170:
	// lwz r10,444(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 444);
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// stw r11,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r11.u32);
	// stw r11,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,728(r1)
	REX_STORE_U32(ctx.r1.u32 + 728, ctx.r9.u32);
	// rlwinm r11,r8,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x827e71b4
	if (!ctx.cr6.eq) goto loc_827E71B4;
	// lwz r15,1836(r31)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r14,1840(r31)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
	// lwz r10,1844(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// lwz r9,1848(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// b 0x827e71c8
	goto loc_827E71C8;
loc_827E71B4:
	// lwz r15,1844(r31)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r31.u32 + 1844);
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r14,1848(r31)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r10,1836(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1836);
	// lwz r9,1840(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1840);
loc_827E71C8:
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// stw r10,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// mr r16,r17
	ctx.r16.u64 = ctx.r17.u64;
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r9,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// addi r9,r31,36
	ctx.r9.s64 = ctx.r31.s64 + 36;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stw r14,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r14.u32);
	// stw r15,620(r1)
	REX_STORE_U32(ctx.r1.u32 + 620, ctx.r15.u32);
	// mr r18,r17
	ctx.r18.u64 = ctx.r17.u64;
	// rlwinm r6,r7,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r9,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// stw r17,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r17.u32);
	// stw r17,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r17.u32);
	// stw r17,468(r1)
	REX_STORE_U32(ctx.r1.u32 + 468, ctx.r17.u32);
	// stw r6,596(r1)
	REX_STORE_U32(ctx.r1.u32 + 596, ctx.r6.u32);
	// stw r17,452(r1)
	REX_STORE_U32(ctx.r1.u32 + 452, ctx.r17.u32);
loc_827E7218:
	// lwz r10,168(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// srawi r8,r16,1
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r16.s32 >> 1;
	// lwz r9,1060(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// clrlwi r11,r16,31
	ctx.r11.u64 = ctx.r16.u32 & 0x1;
	// lwz r6,348(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// lwz r5,128(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lhz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// rlwinm r7,r5,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r27,r8,r7
	ctx.r27.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lhz r28,50(r31)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// add r22,r10,r9
	ctx.r22.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r9,r27,31
	ctx.r9.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r21,r22,2,0,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r21,708(r1)
	REX_STORE_U32(ctx.r1.u32 + 708, ctx.r21.u32);
	// srawi r23,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r28.s32 >> 1;
	// add r24,r11,r10
	ctx.r24.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwzx r20,r6,r21
	ctx.r20.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r21.u32);
	// stw r20,600(r1)
	REX_STORE_U32(ctx.r1.u32 + 600, ctx.r20.u32);
	// bne cr6,0x827e72a0
	if (!ctx.cr6.eq) goto loc_827E72A0;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x827e7294
	if (ctx.cr6.eq) goto loc_827E7294;
	// srawi r11,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r27.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e72a0
	if (ctx.cr6.eq) goto loc_827E72A0;
loc_827E7294:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x827e72a8
	goto loc_827E72A8;
loc_827E72A0:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_827E72A8:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r19,r20,16
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0xFFFF) != 0);
	ctx.r19.s64 = ctx.r20.s32 >> 16;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r30,376(r1)
	REX_STORE_U32(ctx.r1.u32 + 376, ctx.r30.u32);
	// stw r30,372(r1)
	REX_STORE_U32(ctx.r1.u32 + 372, ctx.r30.u32);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// subf r7,r8,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r8.u64;
	// stw r30,368(r1)
	REX_STORE_U32(ctx.r1.u32 + 368, ctx.r30.u32);
	// stw r30,404(r1)
	REX_STORE_U32(ctx.r1.u32 + 404, ctx.r30.u32);
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// stw r30,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, ctx.r30.u32);
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// stw r19,704(r1)
	REX_STORE_U32(ctx.r1.u32 + 704, ctx.r19.u32);
	// stw r7,408(r1)
	REX_STORE_U32(ctx.r1.u32 + 408, ctx.r7.u32);
	// bne cr6,0x827e7300
	if (!ctx.cr6.eq) goto loc_827E7300;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27024
	ctx.r9.s64 = ctx.r11.s64 + -27024;
	// addi r8,r10,-26744
	ctx.r8.s64 = ctx.r10.s64 + -26744;
	// b 0x827e7330
	goto loc_827E7330;
loc_827E7300:
	// lwz r11,1372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1372);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e7320
	if (!ctx.cr6.eq) goto loc_827E7320;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27712
	ctx.r9.s64 = ctx.r11.s64 + -27712;
	// addi r8,r10,-27304
	ctx.r8.s64 = ctx.r10.s64 + -27304;
	// b 0x827e7330
	goto loc_827E7330;
loc_827E7320:
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27584
	ctx.r9.s64 = ctx.r11.s64 + -27584;
	// addi r8,r10,-27648
	ctx.r8.s64 = ctx.r10.s64 + -27648;
loc_827E7330:
	// stw r9,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// stw r8,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// beq cr6,0x827e73b4
	if (ctx.cr6.eq) goto loc_827E73B4;
	// addi r11,r22,-1
	ctx.r11.s64 = ctx.r22.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r15,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r15.u32 + ctx.r11.u32);
	// lhzx r9,r14,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r14.u32 + ctx.r11.u32);
	// sth r10,126(r1)
	REX_STORE_U16(ctx.r1.u32 + 126, ctx.r10.u16);
	// sth r9,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r9.u16);
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e73b4
	if (ctx.cr6.eq) goto loc_827E73B4;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7394
	if (ctx.cr6.eq) goto loc_827E7394;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E7388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,368(r1)
	REX_STORE_U32(ctx.r1.u32 + 368, ctx.r3.u32);
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x827e73b0
	goto loc_827E73B0;
loc_827E7394:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,368(r1)
	REX_STORE_U32(ctx.r1.u32 + 368, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E73A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
loc_827E73B0:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E73B4:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x827e751c
	if (!ctx.cr6.eq) goto loc_827E751C;
	// subf r29,r28,r22
	ctx.r29.u64 = ctx.r22.u64 - ctx.r28.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r15,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r15.u32 + ctx.r11.u32);
	// lhzx r9,r14,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r14.u32 + ctx.r11.u32);
	// sth r10,126(r1)
	REX_STORE_U16(ctx.r1.u32 + 126, ctx.r10.u16);
	// sth r9,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r9.u16);
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e7454
	if (ctx.cr6.eq) goto loc_827E7454;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7420
	if (ctx.cr6.eq) goto loc_827E7420;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E7410;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,188(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// b 0x827e7448
	goto loc_827E7448;
loc_827E7420:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E743C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,188(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
loc_827E7448:
	// lwz r14,96(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stwx r3,r11,r8
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r3.u32);
loc_827E7454:
	// cmpwi cr6,r23,1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 1, ctx.xer);
	// ble cr6,0x827e751c
	if (!ctx.cr6.gt) goto loc_827E751C;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x827e749c
	if (ctx.cr6.eq) goto loc_827E749C;
	// xor r11,r27,r24
	ctx.r11.u64 = ctx.r27.u64 ^ ctx.r24.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e7484
	if (ctx.cr6.eq) goto loc_827E7484;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// cmpw cr6,r24,r11
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r11.s32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// blt cr6,0x827e7488
	if (ctx.cr6.lt) goto loc_827E7488;
loc_827E7484:
	// li r11,1
	ctx.r11.s64 = 1;
loc_827E7488:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r11,r22
	ctx.r10.u64 = ctx.r22.u64 - ctx.r11.u64;
	// subf r11,r28,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r28.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x827e74a0
	goto loc_827E74A0;
loc_827E749C:
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
loc_827E74A0:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r15,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r15.u32 + ctx.r11.u32);
	// lhzx r9,r14,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r14.u32 + ctx.r11.u32);
	// sth r10,126(r1)
	REX_STORE_U16(ctx.r1.u32 + 126, ctx.r10.u16);
	// sth r9,124(r1)
	REX_STORE_U16(ctx.r1.u32 + 124, ctx.r9.u16);
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e751c
	if (ctx.cr6.eq) goto loc_827E751C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e74f8
	if (ctx.cr6.eq) goto loc_827E74F8;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,400
	ctx.r10.s64 = ctx.r1.s64 + 400;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E74EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// b 0x827e7518
	goto loc_827E7518;
loc_827E74F8:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E7510;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
loc_827E7518:
	// stwx r3,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E751C:
	// add r11,r25,r26
	ctx.r11.u64 = ctx.r25.u64 + ctx.r26.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e76a8
	if (!ctx.cr6.gt) goto loc_827E76A8;
	// lhz r11,378(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 378);
	// lhz r10,374(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 374);
	// lhz r9,370(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 370);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,376(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 376);
	// extsh r28,r9
	ctx.r28.s64 = ctx.r9.s16;
	// lhz r7,372(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 372);
	// lhz r6,368(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 368);
	// extsh r27,r8
	ctx.r27.s64 = ctx.r8.s16;
	// lhz r5,410(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 410);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r23,r6
	ctx.r23.s64 = ctx.r6.s16;
	// lhz r4,406(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 406);
	// subf r10,r28,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r28.u64;
	// lhz r11,402(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 402);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r6,404(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 404);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,408(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 408);
	// subf r7,r28,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r28.u64;
	// lhz r21,400(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 400);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r23,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r23.u64;
	// subf r19,r27,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r27.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r4,r23,r27
	ctx.r4.u64 = ctx.r27.u64 - ctx.r23.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 & ctx.r28.u64;
	// and r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 & ctx.r23.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r23,r5,r4
	ctx.r23.u64 = ctx.r5.u64 | ctx.r4.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r23
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r23.u64;
	// lwz r20,188(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r28,124(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// andc r28,r27,r28
	ctx.r28.u64 = ctx.r27.u64 & ~ctx.r28.u64;
	// or r27,r7,r6
	ctx.r27.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// or r8,r28,r8
	ctx.r8.u64 = ctx.r28.u64 | ctx.r8.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r27
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r27.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r21,708(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 708);
	// lwz r19,704(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 704);
	// lwz r18,176(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r17,468(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r20,600(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 600);
	// lwz r16,112(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r14,96(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r15,620(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 620);
	// sth r5,466(r1)
	REX_STORE_U16(ctx.r1.u32 + 466, ctx.r5.u16);
	// sth r4,464(r1)
	REX_STORE_U16(ctx.r1.u32 + 464, ctx.r4.u16);
	// sth r11,462(r1)
	REX_STORE_U16(ctx.r1.u32 + 462, ctx.r11.u16);
	// sth r10,460(r1)
	REX_STORE_U16(ctx.r1.u32 + 460, ctx.r10.u16);
	// b 0x827e76d8
	goto loc_827E76D8;
loc_827E76A8:
	// bne cr6,0x827e76c0
	if (!ctx.cr6.eq) goto loc_827E76C0;
	// lwz r11,368(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 368);
	// lwz r10,400(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// stw r11,464(r1)
	REX_STORE_U32(ctx.r1.u32 + 464, ctx.r11.u32);
	// stw r10,460(r1)
	REX_STORE_U32(ctx.r1.u32 + 460, ctx.r10.u32);
	// b 0x827e76d8
	goto loc_827E76D8;
loc_827E76C0:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,464(r1)
	REX_STORE_U32(ctx.r1.u32 + 464, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r7,460(r1)
	REX_STORE_U32(ctx.r1.u32 + 460, ctx.r7.u32);
loc_827E76D8:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// lwz r8,452(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 452);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e76f4
	if (ctx.cr6.eq) goto loc_827E76F4;
	// cmpw cr6,r26,r25
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r25.s32, ctx.xer);
	// ble cr6,0x827e7700
	if (!ctx.cr6.gt) goto loc_827E7700;
	// b 0x827e7704
	goto loc_827E7704;
loc_827E76F4:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7704
	if (ctx.cr6.eq) goto loc_827E7704;
loc_827E7700:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E7704:
	// clrlwi r11,r19,31
	ctx.r11.u64 = ctx.r19.u32 & 0x1;
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,460(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 460);
	// bne cr6,0x827e771c
	if (!ctx.cr6.eq) goto loc_827E771C;
	// lwz r10,464(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 464);
loc_827E771C:
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r6,66(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// lhz r7,62(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// rlwinm r5,r22,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// stw r4,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// lhz r6,126(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 126);
	// lhz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 124);
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// and r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 & ctx.r3.u64;
	// subf r7,r7,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r7.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sthx r6,r15,r5
	REX_STORE_U16(ctx.r15.u32 + ctx.r5.u32, ctx.r6.u16);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// lwz r9,348(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// add r4,r9,r21
	ctx.r4.u64 = ctx.r9.u64 + ctx.r21.u64;
	// sth r6,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r6.u16);
	// lhz r3,64(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// lhz r7,68(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r3,r7
	ctx.r3.s64 = ctx.r7.s16;
	// add r4,r10,r19
	ctx.r4.u64 = ctx.r10.u64 + ctx.r19.u64;
	// and r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 & ctx.r3.u64;
	// subf r9,r6,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r6.u64;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// sthx r7,r14,r5
	REX_STORE_U16(ctx.r14.u32 + ctx.r5.u32, ctx.r7.u16);
	// lwz r5,348(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 348);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// sthx r7,r5,r21
	REX_STORE_U16(ctx.r5.u32 + ctx.r21.u32, ctx.r7.u16);
	// beq cr6,0x827e7858
	if (ctx.cr6.eq) goto loc_827E7858;
	// lwz r9,448(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 448);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,720(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 720);
	// addi r6,r1,688
	ctx.r6.s64 = ctx.r1.s64 + 688;
	// subf r5,r9,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r4,1368(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// subf r3,r7,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r7.u64;
	// lwz r7,180(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lwz r30,100(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r5,r5,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwimi r10,r8,3,31,28
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r10.u64 & 0x6);
	// rlwinm r9,r4,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// rlwimi r29,r8,3,31,28
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r29.u64 & 0x6);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// srawi r8,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r29.s32 >> 1;
	// addi r5,r9,-4
	ctx.r5.s64 = ctx.r9.s64 + -4;
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r9,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 3;
	// addi r5,r1,640
	ctx.r5.s64 = ctx.r1.s64 + 640;
	// rlwimi r10,r9,2,0,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// subf r10,r4,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r4.u64;
	// rlwinm r3,r3,0,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r9,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// stwx r11,r17,r5
	REX_STORE_U32(ctx.r17.u32 + ctx.r5.u32, ctx.r11.u32);
	// or r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 | ctx.r3.u64;
	// stwx r7,r17,r6
	REX_STORE_U32(ctx.r17.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// stw r17,468(r1)
	REX_STORE_U32(ctx.r1.u32 + 468, ctx.r17.u32);
	// bne cr6,0x827e7850
	if (!ctx.cr6.eq) goto loc_827E7850;
	// addi r29,r31,488
	ctx.r29.s64 = ctx.r31.s64 + 488;
	// b 0x827e78a8
	goto loc_827E78A8;
loc_827E7850:
	// addi r29,r31,536
	ctx.r29.s64 = ctx.r31.s64 + 536;
	// b 0x827e78a8
	goto loc_827E78A8;
loc_827E7858:
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// lwz r7,172(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// rlwinm r6,r10,0,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r4,r9,30
	ctx.r4.u64 = ctx.r9.u32 & 0x3;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// or r10,r4,r6
	ctx.r10.u64 = ctx.r4.u64 | ctx.r6.u64;
	// addi r9,r1,672
	ctx.r9.s64 = ctx.r1.s64 + 672;
	// srawi r6,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 1;
	// addi r4,r7,1
	ctx.r4.s64 = ctx.r7.s64 + 1;
	// stwx r11,r8,r3
	REX_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r11.u32);
	// rlwimi r6,r10,0,30,31
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFFC);
	// addi r3,r8,4
	ctx.r3.s64 = ctx.r8.s64 + 4;
	// stw r4,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r4.u32);
	// stwx r6,r8,r9
	REX_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// stw r3,452(r1)
	REX_STORE_U32(ctx.r1.u32 + 452, ctx.r3.u32);
	// addi r29,r31,464
	ctx.r29.s64 = ctx.r31.s64 + 464;
	// beq cr6,0x827e78a8
	if (ctx.cr6.eq) goto loc_827E78A8;
	// addi r29,r31,512
	ctx.r29.s64 = ctx.r31.s64 + 512;
loc_827E78A8:
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// lwz r10,596(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 596);
	// lwz r9,300(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// rlwinm r7,r11,1,15,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// subf r6,r11,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r11.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addis r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 8388608;
	// addi r4,r4,56
	ctx.r4.s64 = ctx.r4.s64 + 56;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// rlwinm r10,r3,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r10,r10,0,16,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827e79d4
	if (ctx.cr6.eq) goto loc_827E79D4;
	// lwz r10,1368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// srawi r6,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 16;
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r4,r8,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r7,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r10,r6,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// bne cr6,0x827e792c
	if (!ctx.cr6.eq) goto loc_827E792C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x827e7948
	if (ctx.cr6.eq) goto loc_827E7948;
	// li r7,-35
	ctx.r7.s64 = -35;
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// b 0x827e7950
	goto loc_827E7950;
loc_827E792C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x827e7948
	if (ctx.cr6.eq) goto loc_827E7948;
	// li r7,-37
	ctx.r7.s64 = -37;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// b 0x827e7950
	goto loc_827E7950;
loc_827E7948:
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// li r7,-36
	ctx.r7.s64 = -36;
loc_827E7950:
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// cmpwi cr6,r10,-17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -17, ctx.xer);
	// bge cr6,0x827e7970
	if (!ctx.cr6.lt) goto loc_827E7970;
	// li r10,-17
	ctx.r10.s64 = -17;
	// b 0x827e7984
	goto loc_827E7984;
loc_827E7970:
	// lhz r8,50(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x827e7988
	if (!ctx.cr6.gt) goto loc_827E7988;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_827E7984:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E7988:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x827e7998
	if (!ctx.cr6.lt) goto loc_827E7998;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x827e79b0
	goto loc_827E79B0;
loc_827E7998:
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x827e79a8
	if (!ctx.cr6.gt) goto loc_827E79A8;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x827e79b0
	goto loc_827E79B0;
loc_827E79A8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x827e79d0
	if (ctx.cr6.eq) goto loc_827E79D0;
loc_827E79B0:
	// subf r10,r4,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r9,r6,30
	ctx.r9.u64 = ctx.r6.u32 & 0x3;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_827E79D0:
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827E79D4:
	// addi r9,r31,560
	ctx.r9.s64 = ctx.r31.s64 + 560;
	// lhz r30,90(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 90);
	// srawi r10,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 16;
	// lwzx r8,r29,r18
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r18.u32);
	// rlwinm r6,r30,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r5,1060(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r4,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 2;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwzx r7,r9,r18
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r18.u32);
	// mullw r9,r6,r4
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r4.s32);
	// lwz r11,8(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r8,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 2;
	// add r28,r7,r11
	ctx.r28.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// add r29,r9,r11
	ctx.r29.u64 = ctx.r9.u64 + ctx.r11.u64;
	// dcbt r5,r29
	// addi r4,r30,128
	ctx.r4.s64 = ctx.r30.s64 + 128;
	// dcbt r4,r29
	// addi r3,r30,64
	ctx.r3.s64 = ctx.r30.s64 + 64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r11,r29
	// rotlwi r11,r30,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r29
	// addi r8,r30,32
	ctx.r8.s64 = ctx.r30.s64 + 32;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r7,r29
	// rotlwi r11,r30,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 2);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// dcbt r5,r29
	// rotlwi r11,r30,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// add r4,r30,r11
	ctx.r4.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r29
	// rotlwi r11,r30,3
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 3);
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r29
	// lbz r8,48(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// clrlwi r27,r6,30
	ctx.r27.u64 = ctx.r6.u32 & 0x3;
	// clrlwi r26,r10,30
	ctx.r26.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bne cr6,0x827e7af4
	if (!ctx.cr6.eq) goto loc_827E7AF4;
	// addi r11,r27,52
	ctx.r11.s64 = ctx.r27.s64 + 52;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E7AC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827e7b10
	if (ctx.cr6.eq) goto loc_827E7B10;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827828d0
	ctx.lr = 0x827E7AF0;
	sub_827828D0(ctx, base);
	// b 0x827e7b10
	goto loc_827E7B10;
loc_827E7AF4:
	// addi r11,r27,56
	ctx.r11.s64 = ctx.r27.s64 + 56;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E7B10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827E7B10:
	// lwz r11,168(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 168);
	// addi r18,r18,4
	ctx.r18.s64 = ctx.r18.s64 + 4;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stw r18,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r18.u32);
	// stw r16,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r16.u32);
	// cmpwi cr6,r18,16
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 16, ctx.xer);
	// stw r10,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// blt cr6,0x827e7218
	if (ctx.cr6.lt) goto loc_827E7218;
	// lwz r17,1060(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r19,128(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lhz r26,50(r31)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r18,116(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r11,r19,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r24,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r24.s64 = ctx.r26.s32 >> 1;
	// lwz r23,0(r17)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r25,r18,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x827e7b8c
	if (!ctx.cr6.eq) goto loc_827E7B8C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7b80
	if (ctx.cr6.eq) goto loc_827E7B80;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e7b8c
	if (ctx.cr6.eq) goto loc_827E7B8C;
loc_827E7B80:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r16,0
	ctx.r16.s64 = 0;
	// b 0x827e7b94
	goto loc_827E7B94;
loc_827E7B8C:
	// li r16,0
	ctx.r16.s64 = 0;
	// mr r29,r16
	ctx.r29.u64 = ctx.r16.u64;
loc_827E7B94:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r20,1
	ctx.r20.s64 = 65536;
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r16,440(r1)
	REX_STORE_U32(ctx.r1.u32 + 440, ctx.r16.u32);
	// stw r16,436(r1)
	REX_STORE_U32(ctx.r1.u32 + 436, ctx.r16.u32);
	// mr r27,r16
	ctx.r27.u64 = ctx.r16.u64;
	// subf r8,r9,r20
	ctx.r8.u64 = ctx.r20.u64 - ctx.r9.u64;
	// stw r16,432(r1)
	REX_STORE_U32(ctx.r1.u32 + 432, ctx.r16.u32);
	// stw r16,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r16.u32);
	// mr r30,r16
	ctx.r30.u64 = ctx.r16.u64;
	// stw r16,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r16.u32);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// stw r8,296(r1)
	REX_STORE_U32(ctx.r1.u32 + 296, ctx.r8.u32);
	// bne cr6,0x827e7be8
	if (!ctx.cr6.eq) goto loc_827E7BE8;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27024
	ctx.r9.s64 = ctx.r11.s64 + -27024;
	// addi r8,r10,-26744
	ctx.r8.s64 = ctx.r10.s64 + -26744;
	// b 0x827e7c18
	goto loc_827E7C18;
loc_827E7BE8:
	// lwz r11,1372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1372);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e7c08
	if (!ctx.cr6.eq) goto loc_827E7C08;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27712
	ctx.r9.s64 = ctx.r11.s64 + -27712;
	// addi r8,r10,-27304
	ctx.r8.s64 = ctx.r10.s64 + -27304;
	// b 0x827e7c18
	goto loc_827E7C18;
loc_827E7C08:
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// addi r9,r11,-27584
	ctx.r9.s64 = ctx.r11.s64 + -27584;
	// addi r8,r10,-27648
	ctx.r8.s64 = ctx.r10.s64 + -27648;
loc_827E7C18:
	// lwz r22,160(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r21,164(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// stw r9,1744(r31)
	REX_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// stw r8,1748(r31)
	REX_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// beq cr6,0x827e7ca4
	if (ctx.cr6.eq) goto loc_827E7CA4;
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r22,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r22.u32 + ctx.r11.u32);
	// lhzx r9,r21,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r21.u32 + ctx.r11.u32);
	// sth r10,150(r1)
	REX_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
	// sth r9,148(r1)
	REX_STORE_U16(ctx.r1.u32 + 148, ctx.r9.u16);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e7ca4
	if (ctx.cr6.eq) goto loc_827E7CA4;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7c84
	if (ctx.cr6.eq) goto loc_827E7C84;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E7C78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,432(r1)
	REX_STORE_U32(ctx.r1.u32 + 432, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// b 0x827e7ca0
	goto loc_827E7CA0;
loc_827E7C84:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,432(r1)
	REX_STORE_U32(ctx.r1.u32 + 432, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E7C98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r3.u32);
	// li r28,1
	ctx.r28.s64 = 1;
loc_827E7CA0:
	// li r30,1
	ctx.r30.s64 = 1;
loc_827E7CA4:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x827e7dc8
	if (!ctx.cr6.eq) goto loc_827E7DC8;
	// subf r29,r26,r23
	ctx.r29.u64 = ctx.r23.u64 - ctx.r26.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r22,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r22.u32 + ctx.r11.u32);
	// lhzx r9,r21,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r21.u32 + ctx.r11.u32);
	// sth r10,150(r1)
	REX_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
	// sth r9,148(r1)
	REX_STORE_U16(ctx.r1.u32 + 148, ctx.r9.u16);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e7d30
	if (ctx.cr6.eq) goto loc_827E7D30;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r15,r30,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7d08
	if (ctx.cr6.eq) goto loc_827E7D08;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r15,r10
	REX_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E7CFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// b 0x827e7d28
	goto loc_827E7D28;
loc_827E7D08:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r15,r10
	REX_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E7D20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_827E7D28:
	// stwx r3,r15,r9
	REX_STORE_U32(ctx.r15.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_827E7D30:
	// cmpwi cr6,r24,1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 1, ctx.xer);
	// ble cr6,0x827e7dc8
	if (!ctx.cr6.gt) goto loc_827E7DC8;
	// addi r11,r26,-2
	ctx.r11.s64 = ctx.r26.s64 + -2;
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x827e7d4c
	if (!ctx.cr6.eq) goto loc_827E7D4C;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_827E7D4C:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r22,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r22.u32 + ctx.r11.u32);
	// lhzx r9,r21,r11
	ctx.r9.u64 = REX_LOAD_U16(ctx.r21.u32 + ctx.r11.u32);
	// sth r10,150(r1)
	REX_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
	// sth r9,148(r1)
	REX_STORE_U16(ctx.r1.u32 + 148, ctx.r9.u16);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x827e7dc8
	if (ctx.cr6.eq) goto loc_827E7DC8;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7da4
	if (ctx.cr6.eq) goto loc_827E7DA4;
	// lwz r11,1744(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1744);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E7D98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// b 0x827e7dc4
	goto loc_827E7DC4;
loc_827E7DA4:
	// lwz r11,1748(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1748);
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stwx r4,r30,r10
	REX_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// bctrl 
	ctx.lr = 0x827E7DBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_827E7DC4:
	// stwx r3,r30,r9
	REX_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_827E7DC8:
	// add r11,r27,r28
	ctx.r11.u64 = ctx.r27.u64 + ctx.r28.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x827e7f4c
	if (!ctx.cr6.gt) goto loc_827E7F4C;
	// lhz r11,442(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 442);
	// lhz r10,438(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 438);
	// lhz r9,434(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 434);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,440(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 440);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,436(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 436);
	// lhz r6,432(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 432);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r5,298(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 298);
	// subf r10,r26,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r26.u64;
	// lhz r4,294(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 294);
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r11,290(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 290);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// lhz r6,292(r1)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r1.u32 + 292);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,296(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 296);
	// subf r7,r26,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r26.u64;
	// lhz r21,288(r1)
	ctx.r21.u64 = REX_LOAD_U16(ctx.r1.u32 + 288);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r20,r22,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r22.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// subf r4,r22,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r22.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// stw r6,596(r1)
	REX_STORE_U32(ctx.r1.u32 + 596, ctx.r6.u32);
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,600(r1)
	REX_STORE_U32(ctx.r1.u32 + 600, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// lwz r26,600(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 600);
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// lwz r20,596(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 596);
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// or r24,r5,r4
	ctx.r24.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// or r9,r26,r9
	ctx.r9.u64 = ctx.r26.u64 | ctx.r9.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r25
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 | ctx.r8.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r24
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r24.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r21,164(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r22,160(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// li r16,0
	ctx.r16.s64 = 0;
	// lwz r18,116(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r19,128(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r17,1060(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// sth r5,498(r1)
	REX_STORE_U16(ctx.r1.u32 + 498, ctx.r5.u16);
	// sth r4,496(r1)
	REX_STORE_U16(ctx.r1.u32 + 496, ctx.r4.u16);
	// sth r11,490(r1)
	REX_STORE_U16(ctx.r1.u32 + 490, ctx.r11.u16);
	// sth r10,488(r1)
	REX_STORE_U16(ctx.r1.u32 + 488, ctx.r10.u16);
	// b 0x827e7f78
	goto loc_827E7F78;
loc_827E7F4C:
	// bne cr6,0x827e7f64
	if (!ctx.cr6.eq) goto loc_827E7F64;
	// lwz r11,432(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 432);
	// lwz r10,288(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 288);
	// stw r11,496(r1)
	REX_STORE_U32(ctx.r1.u32 + 496, ctx.r11.u32);
	// stw r10,488(r1)
	REX_STORE_U32(ctx.r1.u32 + 488, ctx.r10.u32);
	// b 0x827e7f78
	goto loc_827E7F78;
loc_827E7F64:
	// lwz r11,1368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r16,496(r1)
	REX_STORE_U32(ctx.r1.u32 + 496, ctx.r16.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r20
	ctx.r9.u64 = ctx.r20.u64 - ctx.r10.u64;
	// stw r9,488(r1)
	REX_STORE_U32(ctx.r1.u32 + 488, ctx.r9.u32);
loc_827E7F78:
	// lwz r11,1396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1396);
	// lwz r29,184(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r30,612(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 612);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7f9c
	if (ctx.cr6.eq) goto loc_827E7F9C;
	// cmpw cr6,r28,r27
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r27.s32, ctx.xer);
	// ble cr6,0x827e7fa8
	if (!ctx.cr6.gt) goto loc_827E7FA8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827e7fac
	if (!ctx.cr6.eq) goto loc_827E7FAC;
loc_827E7F9C:
	// lwz r11,1400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e7fac
	if (ctx.cr6.eq) goto loc_827E7FAC;
loc_827E7FA8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827E7FAC:
	// lwz r11,488(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 488);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827e7fbc
	if (!ctx.cr6.eq) goto loc_827E7FBC;
	// lwz r11,496(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 496);
loc_827E7FBC:
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// rlwinm r10,r23,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,728(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 728);
	// stw r11,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// add r7,r22,r10
	ctx.r7.u64 = ctx.r22.u64 + ctx.r10.u64;
	// add r6,r23,r9
	ctx.r6.u64 = ctx.r23.u64 + ctx.r9.u64;
	// lwz r28,180(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// add r4,r21,r10
	ctx.r4.u64 = ctx.r21.u64 + ctx.r10.u64;
	// lwz r3,172(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r28,r3
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r3.s32, ctx.xer);
	// add r6,r22,r11
	ctx.r6.u64 = ctx.r22.u64 + ctx.r11.u64;
	// add r5,r21,r11
	ctx.r5.u64 = ctx.r21.u64 + ctx.r11.u64;
	// lhz r9,170(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 170);
	// lhz r8,168(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 168);
	// sthx r9,r22,r11
	REX_STORE_U16(ctx.r22.u32 + ctx.r11.u32, ctx.r9.u16);
	// sth r9,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r9.u16);
	// sth r9,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r9.u16);
	// sthx r9,r22,r10
	REX_STORE_U16(ctx.r22.u32 + ctx.r10.u32, ctx.r9.u16);
	// sth r8,2(r5)
	REX_STORE_U16(ctx.r5.u32 + 2, ctx.r8.u16);
	// sthx r8,r21,r11
	REX_STORE_U16(ctx.r21.u32 + ctx.r11.u32, ctx.r8.u16);
	// sth r8,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r8.u16);
	// sthx r8,r21,r10
	REX_STORE_U16(ctx.r21.u32 + ctx.r10.u32, ctx.r8.u16);
	// ble cr6,0x827e82ec
	if (!ctx.cr6.gt) goto loc_827E82EC;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x827e85c4
	if (ctx.cr6.gt) goto loc_827E85C4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x827e804c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_827E804C;
	// bdzf 4*cr6+eq,0x827e8078
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_827E8078;
	// bne cr6,0x827e80fc
	if (!ctx.cr6.eq) goto loc_827E80FC;
	// lwz r29,640(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r30,688(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 688);
	// b 0x827e85c4
	goto loc_827E85C4;
loc_827E804C:
	// lwz r10,644(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r9,640(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r11,692(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 692);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,688(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 688);
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addze r29,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r30,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r30.s64 = temp.s64;
	// b 0x827e85c4
	goto loc_827E85C4;
loc_827E8078:
	// lwz r10,644(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r11,640(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r9,648(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 648);
	// lwz r6,696(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 696);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r8,688(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 688);
	// subf r4,r9,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r7,692(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 692);
	// subf r3,r11,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r11.u64;
	// xor r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// subf r30,r8,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r8.u64;
	// subf r29,r6,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// xor r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// xor r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r30.u64;
	// srawi r5,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 31;
	// xor r30,r28,r30
	ctx.r30.u64 = ctx.r28.u64 ^ ctx.r30.u64;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// or r29,r5,r4
	ctx.r29.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r28,r3,r30
	ctx.r28.u64 = ctx.r3.u64 | ctx.r30.u64;
	// and r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 & ctx.r10.u64;
	// andc r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// andc r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// and r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 & ctx.r3.u64;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// and r5,r4,r11
	ctx.r5.u64 = ctx.r4.u64 & ctx.r11.u64;
	// or r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 & ctx.r30.u64;
	// or r29,r6,r5
	ctx.r29.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r30,r4,r3
	ctx.r30.u64 = ctx.r4.u64 | ctx.r3.u64;
	// b 0x827e85c4
	goto loc_827E85C4;
loc_827E80FC:
	// lwz r11,640(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r10,644(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r9,648(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 648);
	// subf r6,r11,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,652(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 652);
	// subf r4,r10,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r7,692(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 692);
	// subf r30,r9,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r8,688(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 688);
	// subf r29,r10,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r5,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 31;
	// lwz r6,696(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 696);
	// subf r28,r9,r10
	ctx.r28.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r4,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 31;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// subf r27,r11,r9
	ctx.r27.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r29,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 31;
	// srawi r28,r28,31
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 31;
	// not r25,r5
	ctx.r25.u64 = ~ctx.r5.u64;
	// srawi r27,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 31;
	// not r29,r29
	ctx.r29.u64 = ~ctx.r29.u64;
	// not r28,r28
	ctx.r28.u64 = ~ctx.r28.u64;
	// and r22,r10,r29
	ctx.r22.u64 = ctx.r10.u64 & ctx.r29.u64;
	// and r23,r11,r25
	ctx.r23.u64 = ctx.r11.u64 & ctx.r25.u64;
	// not r24,r4
	ctx.r24.u64 = ~ctx.r4.u64;
	// not r27,r27
	ctx.r27.u64 = ~ctx.r27.u64;
	// and r21,r10,r28
	ctx.r21.u64 = ctx.r10.u64 & ctx.r28.u64;
	// and r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 & ctx.r29.u64;
	// not r30,r30
	ctx.r30.u64 = ~ctx.r30.u64;
	// and r28,r9,r28
	ctx.r28.u64 = ctx.r9.u64 & ctx.r28.u64;
	// and r23,r23,r27
	ctx.r23.u64 = ctx.r23.u64 & ctx.r27.u64;
	// and r22,r22,r24
	ctx.r22.u64 = ctx.r22.u64 & ctx.r24.u64;
	// and r27,r9,r27
	ctx.r27.u64 = ctx.r9.u64 & ctx.r27.u64;
	// and r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 & ctx.r30.u64;
	// and r25,r21,r25
	ctx.r25.u64 = ctx.r21.u64 & ctx.r25.u64;
	// and r28,r28,r30
	ctx.r28.u64 = ctx.r28.u64 & ctx.r30.u64;
	// or r23,r23,r22
	ctx.r23.u64 = ctx.r23.u64 | ctx.r22.u64;
	// and r27,r27,r24
	ctx.r27.u64 = ctx.r27.u64 & ctx.r24.u64;
	// or r29,r25,r29
	ctx.r29.u64 = ctx.r25.u64 | ctx.r29.u64;
	// or r28,r23,r28
	ctx.r28.u64 = ctx.r23.u64 | ctx.r28.u64;
	// or r29,r29,r27
	ctx.r29.u64 = ctx.r29.u64 | ctx.r27.u64;
	// subf r27,r28,r3
	ctx.r27.u64 = ctx.r3.u64 - ctx.r28.u64;
	// subf r25,r3,r29
	ctx.r25.u64 = ctx.r29.u64 - ctx.r3.u64;
	// xor r23,r30,r5
	ctx.r23.u64 = ctx.r30.u64 ^ ctx.r5.u64;
	// xor r24,r24,r5
	ctx.r24.u64 = ctx.r24.u64 ^ ctx.r5.u64;
	// subf r22,r29,r28
	ctx.r22.u64 = ctx.r28.u64 - ctx.r29.u64;
	// srawi r5,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r27.s32 >> 31;
	// srawi r27,r25,31
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r25.s32 >> 31;
	// srawi r25,r22,31
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x7FFFFFFF) != 0);
	ctx.r25.s64 = ctx.r22.s32 >> 31;
	// eqv r27,r27,r5
	ctx.r27.u64 = ~(ctx.r27.u64 ^ ctx.r5.u64);
	// eqv r5,r25,r5
	ctx.r5.u64 = ~(ctx.r25.u64 ^ ctx.r5.u64);
	// xor r4,r30,r4
	ctx.r4.u64 = ctx.r30.u64 ^ ctx.r4.u64;
	// or r30,r27,r5
	ctx.r30.u64 = ctx.r27.u64 | ctx.r5.u64;
	// and r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 & ctx.r9.u64;
	// and r10,r24,r10
	ctx.r10.u64 = ctx.r24.u64 & ctx.r10.u64;
	// and r5,r28,r5
	ctx.r5.u64 = ctx.r28.u64 & ctx.r5.u64;
	// andc r4,r29,r30
	ctx.r4.u64 = ctx.r29.u64 & ~ctx.r30.u64;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 | ctx.r5.u64;
	// and r11,r23,r11
	ctx.r11.u64 = ctx.r23.u64 & ctx.r11.u64;
	// and r5,r3,r27
	ctx.r5.u64 = ctx.r3.u64 & ctx.r27.u64;
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r11,r9,r5
	ctx.r11.u64 = ctx.r9.u64 | ctx.r5.u64;
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r9,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 1;
	// subf r5,r6,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r6.u64;
	// addze r29,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r11,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 31;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// not r3,r10
	ctx.r3.u64 = ~ctx.r10.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// xor r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// xor r5,r30,r10
	ctx.r5.u64 = ctx.r30.u64 ^ ctx.r10.u64;
	// and r28,r9,r7
	ctx.r28.u64 = ctx.r9.u64 & ctx.r7.u64;
	// and r27,r5,r6
	ctx.r27.u64 = ctx.r5.u64 & ctx.r6.u64;
	// xor r25,r30,r11
	ctx.r25.u64 = ctx.r30.u64 ^ ctx.r11.u64;
	// subf r4,r7,r8
	ctx.r4.u64 = ctx.r8.u64 - ctx.r7.u64;
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r24,r8,r6
	ctx.r24.u64 = ctx.r6.u64 - ctx.r8.u64;
	// lwz r10,700(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 700);
	// srawi r9,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 31;
	// srawi r4,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r24.s32 >> 31;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// not r4,r4
	ctx.r4.u64 = ~ctx.r4.u64;
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// not r5,r5
	ctx.r5.u64 = ~ctx.r5.u64;
	// and r24,r11,r4
	ctx.r24.u64 = ctx.r11.u64 & ctx.r4.u64;
	// and r23,r9,r3
	ctx.r23.u64 = ctx.r9.u64 & ctx.r3.u64;
	// and r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 & ctx.r5.u64;
	// and r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 & ctx.r3.u64;
	// and r3,r24,r8
	ctx.r3.u64 = ctx.r24.u64 & ctx.r8.u64;
	// and r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 & ctx.r7.u64;
	// and r24,r23,r7
	ctx.r24.u64 = ctx.r23.u64 & ctx.r7.u64;
	// and r7,r4,r6
	ctx.r7.u64 = ctx.r4.u64 & ctx.r6.u64;
	// and r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 & ctx.r30.u64;
	// and r4,r9,r30
	ctx.r4.u64 = ctx.r9.u64 & ctx.r30.u64;
	// and r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 & ctx.r6.u64;
	// or r3,r3,r24
	ctx.r3.u64 = ctx.r3.u64 | ctx.r24.u64;
	// or r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 | ctx.r7.u64;
	// and r6,r4,r8
	ctx.r6.u64 = ctx.r4.u64 & ctx.r8.u64;
	// or r5,r3,r9
	ctx.r5.u64 = ctx.r3.u64 | ctx.r9.u64;
	// or r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 | ctx.r6.u64;
	// subf r3,r5,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r5.u64;
	// subf r9,r10,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r10.u64;
	// subf r7,r4,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r4.u64;
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// srawi r6,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 31;
	// srawi r3,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 31;
	// eqv r9,r6,r11
	ctx.r9.u64 = ~(ctx.r6.u64 ^ ctx.r11.u64);
	// eqv r7,r3,r11
	ctx.r7.u64 = ~(ctx.r3.u64 ^ ctx.r11.u64);
	// and r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 & ctx.r9.u64;
	// or r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 | ctx.r7.u64;
	// and r11,r5,r7
	ctx.r11.u64 = ctx.r5.u64 & ctx.r7.u64;
	// andc r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 & ~ctx.r3.u64;
	// or r9,r27,r28
	ctx.r9.u64 = ctx.r27.u64 | ctx.r28.u64;
	// or r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 | ctx.r11.u64;
	// and r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 & ctx.r8.u64;
	// or r11,r7,r6
	ctx.r11.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 | ctx.r8.u64;
	// b 0x827e85b8
	goto loc_827E85B8;
loc_827E82EC:
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// mr r26,r16
	ctx.r26.u64 = ctx.r16.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x827e85c4
	if (ctx.cr6.gt) goto loc_827E85C4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x827e831c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_827E831C;
	// bdzf 4*cr6+eq,0x827e8348
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_827E8348;
	// bne cr6,0x827e83cc
	if (!ctx.cr6.eq) goto loc_827E83CC;
	// lwz r29,656(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r30,672(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 672);
	// b 0x827e85c4
	goto loc_827E85C4;
loc_827E831C:
	// lwz r10,660(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 660);
	// lwz r9,656(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r11,676(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 676);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,672(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 672);
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addze r29,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r30,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r30.s64 = temp.s64;
	// b 0x827e85c4
	goto loc_827E85C4;
loc_827E8348:
	// lwz r10,660(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 660);
	// lwz r11,656(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r9,664(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 664);
	// lwz r6,680(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 680);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r8,672(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 672);
	// subf r4,r9,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r7,676(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 676);
	// subf r3,r11,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r11.u64;
	// xor r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// subf r30,r8,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r8.u64;
	// subf r29,r6,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// xor r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// xor r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r30.u64;
	// srawi r5,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 31;
	// xor r30,r28,r30
	ctx.r30.u64 = ctx.r28.u64 ^ ctx.r30.u64;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// or r29,r5,r4
	ctx.r29.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r28,r3,r30
	ctx.r28.u64 = ctx.r3.u64 | ctx.r30.u64;
	// and r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 & ctx.r5.u64;
	// andc r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// andc r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// and r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 & ctx.r3.u64;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// and r5,r11,r4
	ctx.r5.u64 = ctx.r11.u64 & ctx.r4.u64;
	// or r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 & ctx.r30.u64;
	// or r29,r6,r5
	ctx.r29.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r30,r4,r3
	ctx.r30.u64 = ctx.r4.u64 | ctx.r3.u64;
	// b 0x827e85c4
	goto loc_827E85C4;
loc_827E83CC:
	// lwz r11,656(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r10,660(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 660);
	// lwz r9,664(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 664);
	// subf r6,r11,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,668(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 668);
	// subf r4,r10,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r7,676(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 676);
	// subf r30,r9,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r8,672(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 672);
	// subf r29,r10,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r5,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 31;
	// lwz r6,680(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 680);
	// subf r28,r9,r10
	ctx.r28.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r4,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 31;
	// subf r27,r11,r9
	ctx.r27.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// srawi r29,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 31;
	// srawi r28,r28,31
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 31;
	// srawi r27,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 31;
	// not r24,r5
	ctx.r24.u64 = ~ctx.r5.u64;
	// not r27,r27
	ctx.r27.u64 = ~ctx.r27.u64;
	// not r25,r4
	ctx.r25.u64 = ~ctx.r4.u64;
	// not r29,r29
	ctx.r29.u64 = ~ctx.r29.u64;
	// not r28,r28
	ctx.r28.u64 = ~ctx.r28.u64;
	// and r23,r24,r27
	ctx.r23.u64 = ctx.r24.u64 & ctx.r27.u64;
	// and r22,r29,r25
	ctx.r22.u64 = ctx.r29.u64 & ctx.r25.u64;
	// not r30,r30
	ctx.r30.u64 = ~ctx.r30.u64;
	// and r27,r27,r25
	ctx.r27.u64 = ctx.r27.u64 & ctx.r25.u64;
	// and r24,r24,r28
	ctx.r24.u64 = ctx.r24.u64 & ctx.r28.u64;
	// and r22,r22,r10
	ctx.r22.u64 = ctx.r22.u64 & ctx.r10.u64;
	// and r23,r23,r11
	ctx.r23.u64 = ctx.r23.u64 & ctx.r11.u64;
	// and r28,r28,r30
	ctx.r28.u64 = ctx.r28.u64 & ctx.r30.u64;
	// and r27,r27,r9
	ctx.r27.u64 = ctx.r27.u64 & ctx.r9.u64;
	// and r24,r24,r10
	ctx.r24.u64 = ctx.r24.u64 & ctx.r10.u64;
	// and r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 & ctx.r30.u64;
	// and r28,r28,r9
	ctx.r28.u64 = ctx.r28.u64 & ctx.r9.u64;
	// or r23,r23,r22
	ctx.r23.u64 = ctx.r23.u64 | ctx.r22.u64;
	// or r27,r24,r27
	ctx.r27.u64 = ctx.r24.u64 | ctx.r27.u64;
	// and r29,r29,r11
	ctx.r29.u64 = ctx.r29.u64 & ctx.r11.u64;
	// or r28,r23,r28
	ctx.r28.u64 = ctx.r23.u64 | ctx.r28.u64;
	// or r29,r27,r29
	ctx.r29.u64 = ctx.r27.u64 | ctx.r29.u64;
	// subf r27,r28,r3
	ctx.r27.u64 = ctx.r3.u64 - ctx.r28.u64;
	// subf r24,r3,r29
	ctx.r24.u64 = ctx.r29.u64 - ctx.r3.u64;
	// xor r23,r30,r5
	ctx.r23.u64 = ctx.r30.u64 ^ ctx.r5.u64;
	// xor r25,r25,r5
	ctx.r25.u64 = ctx.r25.u64 ^ ctx.r5.u64;
	// subf r22,r29,r28
	ctx.r22.u64 = ctx.r28.u64 - ctx.r29.u64;
	// srawi r5,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r27.s32 >> 31;
	// srawi r27,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r24.s32 >> 31;
	// srawi r24,r22,31
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x7FFFFFFF) != 0);
	ctx.r24.s64 = ctx.r22.s32 >> 31;
	// eqv r27,r27,r5
	ctx.r27.u64 = ~(ctx.r27.u64 ^ ctx.r5.u64);
	// eqv r5,r24,r5
	ctx.r5.u64 = ~(ctx.r24.u64 ^ ctx.r5.u64);
	// xor r4,r30,r4
	ctx.r4.u64 = ctx.r30.u64 ^ ctx.r4.u64;
	// or r30,r27,r5
	ctx.r30.u64 = ctx.r27.u64 | ctx.r5.u64;
	// and r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 & ctx.r9.u64;
	// and r10,r25,r10
	ctx.r10.u64 = ctx.r25.u64 & ctx.r10.u64;
	// andc r4,r29,r30
	ctx.r4.u64 = ctx.r29.u64 & ~ctx.r30.u64;
	// and r3,r3,r27
	ctx.r3.u64 = ctx.r3.u64 & ctx.r27.u64;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// and r11,r23,r11
	ctx.r11.u64 = ctx.r23.u64 & ctx.r11.u64;
	// or r9,r4,r3
	ctx.r9.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r5,r28,r5
	ctx.r5.u64 = ctx.r28.u64 & ctx.r5.u64;
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r11,r9,r5
	ctx.r11.u64 = ctx.r9.u64 | ctx.r5.u64;
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r9,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 1;
	// subf r5,r6,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r6.u64;
	// addze r29,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r11,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 31;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// not r3,r10
	ctx.r3.u64 = ~ctx.r10.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// xor r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// xor r5,r30,r10
	ctx.r5.u64 = ctx.r30.u64 ^ ctx.r10.u64;
	// and r28,r9,r7
	ctx.r28.u64 = ctx.r9.u64 & ctx.r7.u64;
	// and r27,r5,r6
	ctx.r27.u64 = ctx.r5.u64 & ctx.r6.u64;
	// xor r25,r30,r11
	ctx.r25.u64 = ctx.r30.u64 ^ ctx.r11.u64;
	// subf r4,r7,r8
	ctx.r4.u64 = ctx.r8.u64 - ctx.r7.u64;
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r24,r8,r6
	ctx.r24.u64 = ctx.r6.u64 - ctx.r8.u64;
	// lwz r10,684(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 684);
	// srawi r9,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 31;
	// srawi r4,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r24.s32 >> 31;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// not r4,r4
	ctx.r4.u64 = ~ctx.r4.u64;
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// not r5,r5
	ctx.r5.u64 = ~ctx.r5.u64;
	// and r24,r11,r4
	ctx.r24.u64 = ctx.r11.u64 & ctx.r4.u64;
	// and r23,r9,r3
	ctx.r23.u64 = ctx.r9.u64 & ctx.r3.u64;
	// and r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 & ctx.r5.u64;
	// and r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 & ctx.r3.u64;
	// and r3,r24,r8
	ctx.r3.u64 = ctx.r24.u64 & ctx.r8.u64;
	// and r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 & ctx.r7.u64;
	// and r24,r23,r7
	ctx.r24.u64 = ctx.r23.u64 & ctx.r7.u64;
	// and r7,r4,r6
	ctx.r7.u64 = ctx.r4.u64 & ctx.r6.u64;
	// and r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 & ctx.r30.u64;
	// and r4,r9,r30
	ctx.r4.u64 = ctx.r9.u64 & ctx.r30.u64;
	// and r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 & ctx.r6.u64;
	// or r3,r3,r24
	ctx.r3.u64 = ctx.r3.u64 | ctx.r24.u64;
	// or r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 | ctx.r7.u64;
	// and r6,r4,r8
	ctx.r6.u64 = ctx.r4.u64 & ctx.r8.u64;
	// or r5,r3,r9
	ctx.r5.u64 = ctx.r3.u64 | ctx.r9.u64;
	// or r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 | ctx.r6.u64;
	// subf r3,r5,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r5.u64;
	// subf r9,r10,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r10.u64;
	// subf r7,r4,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r4.u64;
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// srawi r6,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 31;
	// srawi r3,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 31;
	// eqv r9,r6,r11
	ctx.r9.u64 = ~(ctx.r6.u64 ^ ctx.r11.u64);
	// eqv r7,r3,r11
	ctx.r7.u64 = ~(ctx.r3.u64 ^ ctx.r11.u64);
	// and r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 & ctx.r9.u64;
	// or r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 | ctx.r7.u64;
	// and r9,r25,r8
	ctx.r9.u64 = ctx.r25.u64 & ctx.r8.u64;
	// andc r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 & ~ctx.r3.u64;
	// or r11,r27,r28
	ctx.r11.u64 = ctx.r27.u64 | ctx.r28.u64;
	// and r8,r5,r7
	ctx.r8.u64 = ctx.r5.u64 & ctx.r7.u64;
	// or r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 | ctx.r6.u64;
	// or r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 | ctx.r9.u64;
	// or r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 | ctx.r8.u64;
loc_827E85B8:
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// addze r30,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r30.s64 = temp.s64;
loc_827E85C4:
	// clrlwi r10,r29,30
	ctx.r10.u64 = ctx.r29.u32 & 0x3;
	// lbz r9,31(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r11,r30,30
	ctx.r11.u64 = ctx.r30.u32 & 0x3;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r6,r11,r29
	ctx.r6.u64 = ctx.r11.u64 + ctx.r29.u64;
	// srawi r9,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 1;
	// srawi r11,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 2;
	// stw r9,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// beq cr6,0x827e8640
	if (ctx.cr6.eq) goto loc_827E8640;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e8620
	if (ctx.cr6.eq) goto loc_827E8620;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x827e8618
	if (!ctx.cr6.gt) goto loc_827E8618;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x827e861c
	goto loc_827E861C;
loc_827E8618:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_827E861C:
	// stw r9,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
loc_827E8620:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827e8640
	if (ctx.cr6.eq) goto loc_827E8640;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827e863c
	if (!ctx.cr6.gt) goto loc_827E863C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x827e8640
	goto loc_827E8640;
loc_827E863C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_827E8640:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x827e8658
	if (ctx.cr6.eq) goto loc_827E8658;
	// lwz r10,1368(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
loc_827E8658:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,4(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 4);
	// lwz r8,352(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 352);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r11,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// rlwinm r10,r19,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r3,r11,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,612(r1)
	REX_STORE_U32(ctx.r1.u32 + 612, ctx.r11.u32);
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// or r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 | ctx.r7.u64;
	// or r9,r10,r18
	ctx.r9.u64 = ctx.r10.u64 | ctx.r18.u64;
	// stwx r4,r6,r8
	REX_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r4.u32);
	// rlwinm r8,r11,1,15,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// lwz r4,316(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// rlwinm r7,r9,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// subf r3,r7,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r7.u64;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r10,r11,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r11.u64;
	// addis r5,r6,24
	ctx.r5.s64 = ctx.r6.s64 + 1572864;
	// addi r5,r5,20
	ctx.r5.s64 = ctx.r5.s64 + 20;
	// or r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 | ctx.r10.u64;
	// rlwinm r8,r9,0,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r8,r8,0,16,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x827e875c
	if (ctx.cr6.eq) goto loc_827E875C;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lhz r7,52(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhz r5,50(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// rlwinm r8,r18,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// rlwinm r7,r19,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x827e8718
	if (!ctx.cr6.lt) goto loc_827E8718;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// b 0x827e872c
	goto loc_827E872C;
loc_827E8718:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x827e872c
	if (!ctx.cr6.gt) goto loc_827E872C;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_827E872C:
	// cmpwi cr6,r8,-9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -9, ctx.xer);
	// bge cr6,0x827e8744
	if (!ctx.cr6.lt) goto loc_827E8744;
	// addi r10,r8,9
	ctx.r10.s64 = ctx.r8.s64 + 9;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// b 0x827e8758
	goto loc_827E8758;
loc_827E8744:
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x827e8758
	if (!ctx.cr6.gt) goto loc_827E8758;
	// subf r10,r8,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_827E8758:
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827E875C:
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lhz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r8,12(r17)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r17.u32 + 12);
	// srawi r5,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 2;
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r7,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 2;
	// mullw r11,r5,r4
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpwi cr6,r6,4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 4, ctx.xer);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bne cr6,0x827e87ac
	if (!ctx.cr6.eq) goto loc_827E87AC;
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// bne cr6,0x827e87a0
	if (!ctx.cr6.eq) goto loc_827E87A0;
	// lwz r6,504(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// lwz r7,508(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 508);
	// b 0x827e87c8
	goto loc_827E87C8;
loc_827E87A0:
	// lwz r6,480(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r7,484(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 484);
	// b 0x827e87c8
	goto loc_827E87C8;
loc_827E87AC:
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// bne cr6,0x827e87c0
	if (!ctx.cr6.eq) goto loc_827E87C0;
	// lwz r6,552(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r7,556(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 556);
	// b 0x827e87c8
	goto loc_827E87C8;
loc_827E87C0:
	// lwz r6,528(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 528);
	// lwz r7,532(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 532);
loc_827E87C8:
	// add r30,r7,r11
	ctx.r30.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r3,r6,r11
	ctx.r3.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lwz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 580);
	// li r7,128
	ctx.r7.s64 = 128;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// dcbt r7,r3
	// addi r6,r4,128
	ctx.r6.s64 = ctx.r4.s64 + 128;
	// dcbt r6,r3
	// addi r5,r4,64
	ctx.r5.s64 = ctx.r4.s64 + 64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r11,r3
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r3
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r3
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r3
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r3
	// rlwinm r5,r4,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r4,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r4.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r3
	// clrlwi r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	// lwz r11,576(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 576);
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// rlwinm r29,r9,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r29,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E8878;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// li r7,128
	ctx.r7.s64 = 128;
	// dcbt r7,r30
	// addi r6,r4,128
	ctx.r6.s64 = ctx.r4.s64 + 128;
	// dcbt r6,r30
	// addi r5,r4,64
	ctx.r5.s64 = ctx.r4.s64 + 64;
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r3,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r30
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r9,r30
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r30
	// rotlwi r5,r4,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r4.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r30
	// lwzx r11,r29,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E8904;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r15,104(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,108(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
loc_827E890C:
	// lwz r7,1060(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r9,632(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 632);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lwz r6,444(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 444);
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// lhz r8,18(r7)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + 18);
	// addi r5,r6,24
	ctx.r5.s64 = ctx.r6.s64 + 24;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// addi r3,r8,2
	ctx.r3.s64 = ctx.r8.s64 + 2;
	// lwz r10,8(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r11,12(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// stw r5,444(r1)
	REX_STORE_U32(ctx.r1.u32 + 444, ctx.r5.u32);
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// stw r4,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// stw r9,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// stw r8,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r8.u32);
	// stw r6,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r6.u32);
	// sth r3,18(r7)
	REX_STORE_U16(ctx.r7.u32 + 18, ctx.r3.u16);
	// blt cr6,0x827e3368
	if (ctx.cr6.lt) goto loc_827E3368;
loc_827E8970:
	// lwz r9,1060(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 1060);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r7,592(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 592);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lwz r5,712(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 712);
	// lwz r6,604(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 604);
	// lhz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 16);
	// add r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 + ctx.r7.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// lwz r11,724(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 724);
	// lwz r7,716(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 716);
	// sth r5,16(r9)
	REX_STORE_U16(ctx.r9.u32 + 16, ctx.r5.u16);
	// add r3,r11,r6
	ctx.r3.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stw r8,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// stw r4,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, ctx.r4.u32);
	// stw r3,604(r1)
	REX_STORE_U32(ctx.r1.u32 + 604, ctx.r3.u32);
	// lhz r11,50(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// blt cr6,0x827e333c
	if (ctx.cr6.lt) goto loc_827E333C;
loc_827E89C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1024
	ctx.r1.s64 = ctx.r1.s64 + 1024;
	// b 0x826a1cd0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827E8A00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lhz r10,52(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 52);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lhz r9,50(r4)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r4.u32 + 50);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r4,r10,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r9,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// lwz r11,1316(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1316);
	// beq cr6,0x827e8ab4
	if (ctx.cr6.eq) goto loc_827E8AB4;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r7,r10,-28184
	ctx.r7.s64 = ctx.r10.s64 + -28184;
loc_827E8A34:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x827e8aa8
	if (ctx.cr6.eq) goto loc_827E8AA8;
	// cntlzw r9,r5
	ctx.r9.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// rlwinm r8,r9,28,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x2;
loc_827E8A4C:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r12,3855
	ctx.r12.s64 = 3855;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rldicr r12,r12,32,31
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 32) & 0xFFFFFFFF00000000;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// oris r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 252641280;
	// rlwinm r9,r3,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 3855;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// ldx r3,r9,r7
	ctx.r3.u64 = REX_LOAD_U64(ctx.r9.u32 + ctx.r7.u32);
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// rldicl r3,r9,56,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r9.u8);
	// rldicl r31,r3,56,8
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r3,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r3.u8);
	// rldicl r9,r31,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r31,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, ctx.r31.u8);
	// rldicl r3,r9,56,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r9.u8);
	// rldicl r31,r3,56,8
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r3,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, ctx.r3.u8);
	// stbu r31,6(r11)
	ea = 6 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r31.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x827e8a4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827E8A4C;
loc_827E8AA8:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x827e8a34
	if (ctx.cr6.lt) goto loc_827E8A34;
loc_827E8AB4:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8AC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a1cbc
	ctx.lr = 0x827E8AC8;
	__savegprlr_29(ctx, base);
	// lhz r11,52(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 52);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r10,50(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 50);
	// rlwinm r31,r11,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r11,1316(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 1316);
	// rlwinm r6,r10,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x827e8b98
	if (ctx.cr6.eq) goto loc_827E8B98;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r7,r10,-28184
	ctx.r7.s64 = ctx.r10.s64 + -28184;
loc_827E8AF8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x827e8b14
	if (ctx.cr6.eq) goto loc_827E8B14;
	// lwz r10,22192(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 22192);
	// lwzx r9,r10,r4
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x827e8b18
	if (ctx.cr6.eq) goto loc_827E8B18;
loc_827E8B14:
	// li r9,1
	ctx.r9.s64 = 1;
loc_827E8B18:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x827e8b88
	if (ctx.cr6.eq) goto loc_827E8B88;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_827E8B2C:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r12,3855
	ctx.r12.s64 = 3855;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rldicr r12,r12,32,31
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 32) & 0xFFFFFFFF00000000;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// oris r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 252641280;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 3855;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// ldx r9,r9,r7
	ctx.r9.u64 = REX_LOAD_U64(ctx.r9.u32 + ctx.r7.u32);
	// and r9,r9,r12
	ctx.r9.u64 = ctx.r9.u64 & ctx.r12.u64;
	// rldicl r30,r9,56,8
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r9.u8);
	// rldicl r29,r30,56,8
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r30,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r30.u8);
	// rldicl r9,r29,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r29,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, ctx.r29.u8);
	// rldicl r30,r9,56,8
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r9.u8);
	// rldicl r29,r30,56,8
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r30,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, ctx.r30.u8);
	// stbu r29,6(r11)
	ea = 6 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r29.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x827e8b2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827E8B2C;
loc_827E8B88:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// cmplw cr6,r5,r31
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x827e8af8
	if (ctx.cr6.lt) goto loc_827E8AF8;
loc_827E8B98:
	// b 0x826a1d0c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827E8BA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a1c80
	ctx.lr = 0x827E8BA8;
	__savegprlr_14(ctx, base);
	// stwu r1,-2624(r1)
	ea = -2624 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,22488(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 22488);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r9,1312(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 1312);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r7,3076(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 3076);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,2644(r1)
	REX_STORE_U32(ctx.r1.u32 + 2644, ctx.r3.u32);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,20(r5)
	REX_STORE_U32(ctx.r5.u32 + 20, ctx.r10.u32);
	// lwz r6,22500(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 22500);
	// stw r6,24(r5)
	REX_STORE_U32(ctx.r5.u32 + 24, ctx.r6.u32);
	// lwz r5,616(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 616);
	// stw r5,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r5.u32);
	// lwz r4,428(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 428);
	// stw r4,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r4.u32);
	// lwz r10,1164(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1164);
	// stw r10,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r10.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// sth r11,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
	// sth r11,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r11.u16);
	// lhz r4,50(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// lhz r6,74(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 74);
	// lhz r5,76(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// lhz r8,52(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 52);
	// rlwinm r10,r8,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r4,r4,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stw r7,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r6,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// stw r4,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// stw r5,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// ble cr6,0x827e98ec
	if (!ctx.cr6.gt) goto loc_827E98EC;
	// b 0x827e8c58
	goto loc_827E8C58;
loc_827E8C50:
	// lwz r3,2644(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 2644);
	// li r11,0
	ctx.r11.s64 = 0;
loc_827E8C58:
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r9,120(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// sth r11,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r11.u16);
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// stw r9,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r9.u32);
	// lwz r8,22164(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 22164);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e8c98
	if (ctx.cr6.eq) goto loc_827E8C98;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,1304(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x827e8c98
	if (ctx.cr6.eq) goto loc_827E8C98;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
loc_827E8C98:
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x827e9888
	if (!ctx.cr6.gt) goto loc_827E9888;
loc_827E8CA8:
	// lwz r9,124(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r8,r9,8
	ctx.r8.s64 = ctx.r9.s64 + 8;
	// lwz r27,128(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// clrlwi r11,r10,29
	ctx.r11.u64 = ctx.r10.u32 & 0x7;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// stw r8,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// ld r22,0(r9)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// addi r7,r11,588
	ctx.r7.s64 = ctx.r11.s64 + 588;
	// addi r6,r10,596
	ctx.r6.s64 = ctx.r10.s64 + 596;
	// rldicl r5,r22,3,61
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r22.u64, 3) & 0x7;
	// rldicl r4,r22,10,54
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r22.u64, 10) & 0x3FF;
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwimi r5,r4,0,30,31
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x3) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFFC);
	// li r11,2
	ctx.r11.s64 = 2;
	// clrlwi r14,r5,29
	ctx.r14.u64 = ctx.r5.u32 & 0x7;
	// lhzx r9,r3,r31
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + ctx.r31.u32);
	// rlwinm r6,r27,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r10,r31
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// add r18,r14,r31
	ctx.r18.u64 = ctx.r14.u64 + ctx.r31.u64;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// stb r14,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r14.u8);
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// rlwinm r10,r7,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r9,r31,472
	ctx.r9.s64 = ctx.r31.s64 + 472;
	// lbz r28,1879(r18)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r18.u32 + 1879);
	// add r29,r6,r27
	ctx.r29.u64 = ctx.r6.u64 + ctx.r27.u64;
	// rlwinm r7,r5,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
loc_827E8D20:
	// clrlwi r11,r28,31
	ctx.r11.u64 = ctx.r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827e8d70
	if (ctx.cr6.eq) goto loc_827E8D70;
	// lwz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,-8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -8);
	// lwz r8,12(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// lwz r3,8(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// add r5,r8,r4
	ctx.r5.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// dcbt r10,r11
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + ctx.r27.u64;
	// dcbt r4,r11
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// dcbt r3,r11
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + ctx.r29.u64;
	// dcbt r4,r11
	// dcbt r7,r5
	// dcbt r7,r8
loc_827E8D70:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r28,r28,31,1,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x7FFFFFFF;
	// bdnz 0x827e8d20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827E8D20;
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r11,r31,1912
	ctx.r11.s64 = ctx.r31.s64 + 1912;
	// lwz r9,1912(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1912);
	// rlwinm r21,r10,2,0,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r21,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// beq cr6,0x827e981c
	if (ctx.cr6.eq) goto loc_827E981C;
	// lwz r10,1916(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1916);
	// rldicl r9,r22,17,47
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r22.u64, 17) & 0x1FFFF;
	// lbz r8,30(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 30);
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// clrlwi r20,r9,31
	ctx.r20.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwzx r24,r21,r10
	ctx.r24.u64 = REX_LOAD_U32(ctx.r21.u32 + ctx.r10.u32);
	// beq cr6,0x827e8dc8
	if (ctx.cr6.eq) goto loc_827E8DC8;
	// rlwinm r11,r11,0,17,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// rlwinm r10,r24,0,17,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// rlwinm r25,r11,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r24,r10,1,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
loc_827E8DC8:
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r9,2316(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 2316);
	// lwz r10,1788(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1788);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lhz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// subf r9,r9,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r9.u64;
	// beq cr6,0x827e8e48
	if (ctx.cr6.eq) goto loc_827E8E48;
	// addi r7,r11,255
	ctx.r7.s64 = ctx.r11.s64 + 255;
	// subf r11,r8,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addi r6,r10,255
	ctx.r6.s64 = ctx.r10.s64 + 255;
	// addi r5,r9,255
	ctx.r5.s64 = ctx.r9.s64 + 255;
	// srawi r4,r7,9
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1FF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 9;
	// addi r3,r11,255
	ctx.r3.s64 = ctx.r11.s64 + 255;
	// srawi r11,r6,9
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1FF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 9;
	// srawi r10,r5,9
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1FF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 9;
	// srawi r9,r3,9
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1FF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 9;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r8,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r7,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r7.u16);
	// sth r6,90(r1)
	REX_STORE_U16(ctx.r1.u32 + 90, ctx.r6.u16);
	// sth r5,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r5.u16);
	// b 0x827e8e7c
	goto loc_827E8E7C;
loc_827E8E48:
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// subf r11,r8,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// addi r5,r9,128
	ctx.r5.s64 = ctx.r9.s64 + 128;
	// srawi r4,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 8;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// srawi r11,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 8;
	// sth r4,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r4.u16);
	// srawi r10,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 8;
	// srawi r9,r3,8
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 8;
	// sth r11,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// sth r10,90(r1)
	REX_STORE_U16(ctx.r1.u32 + 90, ctx.r10.u16);
	// sth r9,88(r1)
	REX_STORE_U16(ctx.r1.u32 + 88, ctx.r9.u16);
loc_827E8E7C:
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,16(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r27,1892(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 1892);
	// rlwinm r10,r5,1,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x10000;
	// lwz r26,1904(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 1904);
	// rlwinm r11,r28,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// subf r9,r11,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r11.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r8,r5,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r5.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// rlwinm r6,r7,0,0,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r6,r6,0,16,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x827e8ed4
	if (ctx.cr6.eq) goto loc_827E8ED4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827563b0
	ctx.lr = 0x827E8ED0;
	sub_827563B0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_827E8ED4:
	// lwz r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r11,r28,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// rlwinm r10,r5,1,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x10000;
	// subf r9,r11,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r11.u64;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// subf r8,r5,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r5.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// rlwinm r6,r7,0,0,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r6,r6,0,16,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x827e8f20
	if (ctx.cr6.eq) goto loc_827E8F20;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827563b0
	ctx.lr = 0x827E8F20;
	sub_827563B0(ctx, base);
loc_827E8F20:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r14,1
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 1, ctx.xer);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r28,r31,1912
	ctx.r28.s64 = ctx.r31.s64 + 1912;
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r24,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r24.u32);
	// lwz r9,1912(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1912);
	// stwx r29,r21,r9
	REX_STORE_U32(ctx.r21.u32 + ctx.r9.u32, ctx.r29.u32);
	// lwz r8,1916(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1916);
	// stwx r3,r21,r8
	REX_STORE_U32(ctx.r21.u32 + ctx.r8.u32, ctx.r3.u32);
	// beq cr6,0x827e92bc
	if (ctx.cr6.eq) goto loc_827E92BC;
	// subfic r23,r14,5
	ctx.xer.ca = ctx.r14.u32 <= 5;
	ctx.r23.u64 = static_cast<uint64_t>(5) - ctx.r14.u64;
	// cmplwi cr6,r14,2
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 2, ctx.xer);
	// beq cr6,0x827e8f68
	if (ctx.cr6.eq) goto loc_827E8F68;
	// stw r25,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r25.u32);
	// stw r24,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r24.u32);
	// b 0x827e8f70
	goto loc_827E8F70;
loc_827E8F68:
	// stw r25,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r25.u32);
	// stw r24,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r24.u32);
loc_827E8F70:
	// lwz r25,104(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r29,r1,136
	ctx.r29.s64 = ctx.r1.s64 + 136;
	// subfic r27,r31,-1912
	ctx.xer.ca = ctx.r31.u32 <= 4294965384;
	ctx.r27.u64 = static_cast<uint64_t>(-1912) - ctx.r31.u64;
	// li r26,2
	ctx.r26.s64 = 2;
loc_827E8F80:
	// clrlwi r11,r23,31
	ctx.r11.u64 = ctx.r23.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e92a8
	if (ctx.cr6.eq) goto loc_827E92A8;
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// stw r10,1908(r31)
	REX_STORE_U32(ctx.r31.u32 + 1908, ctx.r10.u32);
	// beq cr6,0x827e9054
	if (ctx.cr6.eq) goto loc_827E9054;
	// lhz r11,18(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 18);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827e9238
	if (ctx.cr6.eq) goto loc_827E9238;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// beq cr6,0x827e9238
	if (ctx.cr6.eq) goto loc_827E9238;
	// lwz r10,2320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2320);
	// rlwinm r9,r11,1,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// lwz r8,16(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r7,r4,471
	ctx.r7.s64 = ctx.r4.s64 + 471;
	// addi r6,r4,474
	ctx.r6.s64 = ctx.r4.s64 + 474;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// subfic r10,r10,5
	ctx.xer.ca = ctx.r10.u32 <= 5;
	ctx.r10.u64 = static_cast<uint64_t>(5) - ctx.r10.u64;
	// lwzx r6,r5,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// lwzx r5,r7,r31
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// subf r9,r9,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r9.u64;
	// subf r8,r10,r5
	ctx.r8.u64 = ctx.r5.u64 - ctx.r10.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r7,r11,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// rlwinm r5,r6,0,0,16
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r5,r5,0,16,0
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x827e9238
	if (ctx.cr6.eq) goto loc_827E9238;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x827e904c
	if (!ctx.cr6.eq) goto loc_827E904C;
	// lwz r10,1168(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1168);
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// bne cr6,0x827e904c
	if (!ctx.cr6.eq) goto loc_827E904C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827ac200
	ctx.lr = 0x827E9048;
	sub_827AC200(ctx, base);
	// b 0x827e9238
	goto loc_827E9238;
loc_827E904C:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// b 0x827e922c
	goto loc_827E922C;
loc_827E9054:
	// lhz r11,18(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 18);
	// lhz r9,50(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,4(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// neg r6,r8
	ctx.r6.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// srawi r5,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 31;
	// subfc r4,r11,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r11.u32;
	ctx.r4.u64 = ctx.r8.u64 - ctx.r11.u64;
	// eqv r3,r11,r8
	ctx.r3.u64 = ~(ctx.r11.u64 ^ ctx.r8.u64);
	// subf r11,r9,r7
	ctx.r11.u64 = ctx.r7.u64 - ctx.r9.u64;
	// rlwinm r9,r3,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r4,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r4.s64 = temp.s64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r4,1,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x2;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwzx r9,r6,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r9,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,-4(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + -4);
	// xor r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// and r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 & ctx.r5.u64;
	// rlwinm r8,r4,0,17,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4000;
	// rlwinm r3,r11,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r10,r7,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// xor r7,r3,r11
	ctx.r7.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// rlwinm r5,r10,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r7,0,17,17
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4000;
	// xor r4,r5,r10
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r10.u64;
	// rlwinm r7,r4,0,17,17
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4000;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add. r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x827e90f8
	if (!ctx.cr0.gt) goto loc_827E90F8;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// bne cr6,0x827e9220
	if (!ctx.cr6.eq) goto loc_827E9220;
	// cmplwi cr6,r9,16384
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16384, ctx.xer);
	// bne cr6,0x827e9200
	if (!ctx.cr6.eq) goto loc_827E9200;
	// li r9,0
	ctx.r9.s64 = 0;
loc_827E90F8:
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r4,2320(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 2320);
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r24,16(r30)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// subf r6,r9,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r9.u64;
	// rlwinm r19,r10,16,0,15
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r3,r11,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r17,r9,16,0,15
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// xor r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// xor r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r16,r3,r19
	ctx.r16.u64 = ctx.r19.u64 - ctx.r3.u64;
	// subf r5,r17,r19
	ctx.r5.u64 = ctx.r19.u64 - ctx.r17.u64;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// subf r6,r17,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r17.u64;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// xor r16,r16,r5
	ctx.r16.u64 = ctx.r16.u64 ^ ctx.r5.u64;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// xor r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// nor r8,r8,r7
	ctx.r8.u64 = ~(ctx.r8.u64 | ctx.r7.u64);
	// and r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ctx.r9.u64;
	// srawi r6,r16,31
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r16.s32 >> 31;
	// srawi r5,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 31;
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// nor r9,r6,r5
	ctx.r9.u64 = ~(ctx.r6.u64 | ctx.r5.u64);
	// and r7,r6,r19
	ctx.r7.u64 = ctx.r6.u64 & ctx.r19.u64;
	// and r8,r5,r17
	ctx.r8.u64 = ctx.r5.u64 & ctx.r17.u64;
	// or r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// and r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 & ctx.r3.u64;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// or r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 | ctx.r3.u64;
	// srawi r11,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 16;
	// addi r9,r4,471
	ctx.r9.s64 = ctx.r4.s64 + 471;
	// addi r8,r4,474
	ctx.r8.s64 = ctx.r4.s64 + 474;
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r10,16,16,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// or r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 | ctx.r7.u64;
	// clrlwi r9,r4,31
	ctx.r9.u64 = ctx.r4.u32 & 0x1;
	// rlwinm r8,r3,1,15,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x10000;
	// lwzx r7,r5,r31
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// subfic r11,r9,5
	ctx.xer.ca = ctx.r9.u32 <= 5;
	ctx.r11.u64 = static_cast<uint64_t>(5) - ctx.r9.u64;
	// lwzx r6,r10,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// slw r11,r24,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r11.u8 & 0x3F));
	// subf r5,r3,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r3.u64;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// subf r9,r11,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r11.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// rlwinm r7,r8,0,0,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r7,r7,0,16,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x827e9238
	if (ctx.cr6.eq) goto loc_827E9238;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x827e9228
	if (!ctx.cr6.eq) goto loc_827E9228;
	// lwz r11,1168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1168);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x827e9228
	if (!ctx.cr6.eq) goto loc_827E9228;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827ac200
	ctx.lr = 0x827E91FC;
	sub_827AC200(ctx, base);
	// b 0x827e9238
	goto loc_827E9238;
loc_827E9200:
	// cmplwi cr6,r10,16384
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16384, ctx.xer);
	// bne cr6,0x827e9210
	if (!ctx.cr6.eq) goto loc_827E9210;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x827e90f8
	goto loc_827E90F8;
loc_827E9210:
	// cmplwi cr6,r11,16384
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16384, ctx.xer);
	// bne cr6,0x827e90f8
	if (!ctx.cr6.eq) goto loc_827E90F8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827e90f8
	goto loc_827E90F8;
loc_827E9220:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827e9238
	goto loc_827E9238;
loc_827E9228:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_827E922C:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827563b0
	ctx.lr = 0x827E9238;
	sub_827563B0(ctx, base);
loc_827E9238:
	// clrlwi r11,r20,24
	ctx.r11.u64 = ctx.r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827e9290
	if (!ctx.cr6.eq) goto loc_827E9290;
	// lhz r10,2(r29)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r29.u32 + 2);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// lhz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r29.u32 + 0);
	// srawi r6,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 16;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhz r11,62(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// lhz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 64);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r5,66(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 66);
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lhz r4,68(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 68);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 + ctx.r10.u64;
	// and r8,r3,r5
	ctx.r8.u64 = ctx.r3.u64 & ctx.r5.u64;
	// and r7,r9,r4
	ctx.r7.u64 = ctx.r9.u64 & ctx.r4.u64;
	// subf r3,r11,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r6,r10,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r10.u64;
	// rlwimi r3,r6,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
loc_827E9290:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stwx r3,r11,r28
	REX_STORE_U32(ctx.r11.u32 + ctx.r28.u32, ctx.r3.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stwx r3,r21,r10
	REX_STORE_U32(ctx.r21.u32 + ctx.r10.u32, ctx.r3.u32);
loc_827E92A8:
	// srawi r23,r23,1
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r23.s32 >> 1;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// bne 0x827e8f80
	if (!ctx.cr0.eq) goto loc_827E8F80;
	// b 0x827e92cc
	goto loc_827E92CC;
loc_827E92BC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r3,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
loc_827E92CC:
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// lwz r9,388(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 388);
	// rldicl r10,r22,8,56
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r22.u64, 8) & 0xFF;
	// stw r11,2312(r31)
	REX_STORE_U32(ctx.r31.u32 + 2312, ctx.r11.u32);
	// addi r8,r31,1852
	ctx.r8.s64 = ctx.r31.s64 + 1852;
	// clrlwi r11,r10,26
	ctx.r11.u64 = ctx.r10.u32 & 0x3F;
	// addi r7,r1,1312
	ctx.r7.s64 = ctx.r1.s64 + 1312;
	// stw r8,700(r31)
	REX_STORE_U32(ctx.r31.u32 + 700, ctx.r8.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rldicl r6,r22,16,48
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r22.u64, 16) & 0xFFFF;
	// stw r7,2308(r31)
	REX_STORE_U32(ctx.r31.u32 + 2308, ctx.r7.u32);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r16,r22
	ctx.r16.u64 = ctx.r22.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r15,r6,26
	ctx.r15.u64 = ctx.r6.u32 & 0x3F;
	// add r17,r11,r9
	ctx.r17.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r21,r31,1876
	ctx.r21.s64 = ctx.r31.s64 + 1876;
	// addi r24,r31,464
	ctx.r24.s64 = ctx.r31.s64 + 464;
	// subfic r20,r31,-464
	ctx.xer.ca = ctx.r31.u32 <= 4294966832;
	ctx.r20.u64 = static_cast<uint64_t>(-464) - ctx.r31.u64;
	// li r19,2
	ctx.r19.s64 = 2;
	// lbz r18,1879(r18)
	ctx.r18.u64 = REX_LOAD_U8(ctx.r18.u32 + 1879);
loc_827E9320:
	// clrlwi r11,r18,31
	ctx.r11.u64 = ctx.r18.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e95dc
	if (ctx.cr6.eq) goto loc_827E95DC;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// add r22,r20,r24
	ctx.r22.u64 = ctx.r20.u64 + ctx.r24.u64;
	// lwz r9,16(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r8,1884(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1884);
	// lwz r7,1896(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 1896);
	// rlwinm r11,r9,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r3,r10,r22
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// subf r6,r11,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r11.u64;
	// rlwinm r5,r3,1,15,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x10000;
	// subf r4,r3,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r3.u64;
	// subf r10,r5,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r5.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r10,r10,0,16,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827e93a8
	if (ctx.cr6.eq) goto loc_827E93A8;
	// lwz r11,1168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 1168);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x827e9394
	if (!ctx.cr6.eq) goto loc_827E9394;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827ac200
	ctx.lr = 0x827E9390;
	sub_827AC200(ctx, base);
	// b 0x827e93a8
	goto loc_827E93A8;
loc_827E9394:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827563b0
	ctx.lr = 0x827E93A8;
	sub_827563B0(ctx, base);
loc_827E93A8:
	// srawi r26,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r26.s64 = ctx.r3.s32 >> 16;
	// lhz r4,90(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 90);
	// extsh r25,r3
	ctx.r25.s64 = ctx.r3.s16;
	// lwz r9,0(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// srawi r10,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r26.s32 >> 2;
	// lwz r8,8(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r11,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 2;
	// lbz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 48);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// lwz r23,1844(r24)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r24.u32 + 1844);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// clrlwi r27,r26,30
	ctx.r27.u64 = ctx.r26.u32 & 0x3;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r29,r25,30
	ctx.r29.u64 = ctx.r25.u32 & 0x3;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bne cr6,0x827e9444
	if (!ctx.cr6.eq) goto loc_827E9444;
	// addi r11,r29,44
	ctx.r11.s64 = ctx.r29.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E9418;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x827e9460
	if (ctx.cr6.eq) goto loc_827E9460;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,35(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lhz r4,90(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 90);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827c8aa0
	ctx.lr = 0x827E9440;
	sub_827C8AA0(ctx, base);
	// b 0x827e9460
	goto loc_827E9460;
loc_827E9444:
	// addi r11,r29,48
	ctx.r11.s64 = ctx.r29.s64 + 48;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827E9460;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827E9460:
	// lwz r8,1172(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 1172);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827e9484
	if (ctx.cr6.eq) goto loc_827E9484;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r25,r10
	ctx.r25.s64 = ctx.r10.s16;
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
loc_827E9484:
	// clrlwi r11,r25,30
	ctx.r11.u64 = ctx.r25.u32 & 0x3;
	// lbz r10,31(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r9,r26,30
	ctx.r9.u64 = ctx.r26.u32 & 0x3;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lbzx r11,r11,r21
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r21.u32);
	// lbzx r10,r9,r21
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r21.u32);
	// add r7,r11,r25
	ctx.r7.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r6,r10,r26
	ctx.r6.u64 = ctx.r10.u64 + ctx.r26.u64;
	// srawi r10,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// srawi r11,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 1;
	// beq cr6,0x827e94e0
	if (ctx.cr6.eq) goto loc_827E94E0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// ble cr6,0x827e94c4
	if (!ctx.cr6.gt) goto loc_827E94C4;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// b 0x827e94c8
	goto loc_827E94C8;
loc_827E94C4:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_827E94C8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// ble cr6,0x827e94dc
	if (!ctx.cr6.gt) goto loc_827E94DC;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// b 0x827e94e0
	goto loc_827E94E0;
loc_827E94DC:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_827E94E0:
	// sth r10,94(r1)
	REX_STORE_U16(ctx.r1.u32 + 94, ctx.r10.u16);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// sth r11,92(r1)
	REX_STORE_U16(ctx.r1.u32 + 92, ctx.r11.u16);
	// beq cr6,0x827e9550
	if (ctx.cr6.eq) goto loc_827E9550;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,2324(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2324);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,2328(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 2328);
	// rlwinm r7,r4,1,15,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x10000;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r5,r11,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// subf r3,r5,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r5.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r9,r4,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r4.u64;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r7,r8,0,0,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r7,r7,0,16,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x827e9548
	if (ctx.cr6.eq) goto loc_827E9548;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827ac2e0
	ctx.lr = 0x827E9544;
	sub_827AC2E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_827E9548:
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// b 0x827e9554
	goto loc_827E9554;
loc_827E9550:
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_827E9554:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lhz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// lwz r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// lwz r10,8(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 8);
	// clrlwi r6,r11,30
	ctx.r6.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r8,r5,30
	ctx.r8.u64 = ctx.r5.u32 & 0x3;
	// srawi r3,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 2;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// mullw r11,r3,r4
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r8,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 2;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r27,r7,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r11,r9
	ctx.r28.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r29,r23,768
	ctx.r29.s64 = ctx.r23.s64 + 768;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwzx r11,r27,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r31.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r3,r10,r28
	ctx.r3.u64 = ctx.r10.u64 + ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827E95B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwzx r10,r27,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,16(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 16);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r29,16
	ctx.r5.s64 = ctx.r29.s64 + 16;
	// lhz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827E95DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827E95DC:
	// srawi r18,r18,1
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x1) != 0);
	ctx.r18.s64 = ctx.r18.s32 >> 1;
	// addic. r19,r19,-1
	ctx.xer.ca = ctx.r19.u32 > 0;
	ctx.r19.s64 = ctx.r19.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// bne 0x827e9320
	if (!ctx.cr0.eq) goto loc_827E9320;
	// lbz r25,80(r1)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r28,0
	ctx.r28.s64 = 0;
loc_827E95F4:
	// srawi r27,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r27.s64 = ctx.r28.s32 >> 2;
	// addi r11,r28,140
	ctx.r11.s64 = ctx.r28.s64 + 140;
	// addi r10,r27,2
	ctx.r10.s64 = ctx.r27.s64 + 2;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r7,r15,31
	ctx.r7.u64 = ctx.r15.u32 & 0x1;
	// rldicl r6,r16,20,44
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r16.u64, 20) & 0xFFFFF;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwzx r9,r9,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// clrlwi r11,r6,29
	ctx.r11.u64 = ctx.r6.u32 & 0x7;
	// lwzx r10,r8,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r30.u32);
	// add r26,r10,r9
	ctx.r26.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x827e97ac
	if (ctx.cr6.eq) goto loc_827E97AC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827e96fc
	if (!ctx.cr6.eq) goto loc_827E96FC;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// lwz r4,444(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 444);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r17)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// lwz r6,4(r17)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r17.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r29,40(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r3,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// dcbzl r0,r29
	ea = (ctx.r29.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x827e9684
	if (ctx.cr6.lt) goto loc_827E9684;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82731930
	ctx.lr = 0x827E967C;
	sub_82731930(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x827e96dc
	goto loc_827E96DC;
loc_827E9684:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x827e96d8
	if (!ctx.cr6.gt) goto loc_827E96D8;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_827E9690:
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r24,r3,24,8,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r24,r7
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r7.s32);
	// lbzx r24,r10,r4
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r24,r5
	ctx.r23.u64 = REX_LOAD_U8(ctx.r24.u32 + ctx.r5.u32);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r3,r3
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// rotlwi r24,r24,1
	ctx.r24.u64 = __builtin_rotateleft32(ctx.r24.u32, 1);
	// xor r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r3,r3,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r3.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r3,r24,r29
	REX_STORE_U16(ctx.r24.u32 + ctx.r29.u32, ctx.r3.u16);
	// bdnz 0x827e9690
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827E9690;
loc_827E96D8:
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
loc_827E96DC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bne cr6,0x827e96f4
	if (!ctx.cr6.eq) goto loc_827E96F4;
	// bl 0x82740728
	ctx.lr = 0x827E96F0;
	sub_82740728(ctx, base);
	// b 0x827e9740
	goto loc_827E9740;
loc_827E96F4:
	// bl 0x827ae860
	ctx.lr = 0x827E96F8;
	sub_827AE860(ctx, base);
	// b 0x827e9740
	goto loc_827E9740;
loc_827E96FC:
	// rldicl r10,r16,24,40
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r16.u64, 24) & 0xFFFFFF;
	// lwz r7,36(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// rlwinm r11,r11,0,29,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x6;
	// clrlwi r5,r10,28
	ctx.r5.u64 = ctx.r10.u32 & 0xF;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// add r9,r5,r31
	ctx.r9.u64 = ctx.r5.u64 + ctx.r31.u64;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// lbz r10,320(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 320);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r8,r11,159
	ctx.r8.s64 = ctx.r11.s64 + 159;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827E9740;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_827E9740:
	// clrlwi r14,r25,24
	ctx.r14.u64 = ctx.r25.u32 & 0xFF;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// cmplwi cr6,r14,2
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 2, ctx.xer);
	// bgt cr6,0x827e9778
	if (ctx.cr6.gt) goto loc_827E9778;
	// addi r11,r27,45
	ctx.r11.s64 = ctx.r27.s64 + 45;
	// lwz r10,700(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 700);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r5,2312(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 2312);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,2308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 2308);
	// lbzx r8,r28,r10
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// lhzx r7,r9,r31
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r31.u32);
	// bl 0x827e9b10
	ctx.lr = 0x827E9774;
	sub_827E9B10(ctx, base);
	// b 0x827e9808
	goto loc_827E9808;
loc_827E9778:
	// lwz r11,700(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 700);
	// subfic r10,r14,581
	ctx.xer.ca = ctx.r14.u32 <= 581;
	ctx.r10.u64 = static_cast<uint64_t>(581) - ctx.r14.u64;
	// addi r9,r27,45
	ctx.r9.s64 = ctx.r27.s64 + 45;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lbzx r6,r28,r11
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// lwzx r11,r8,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lhzx r6,r7,r31
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x827b4bc0
	ctx.lr = 0x827E97A8;
	sub_827B4BC0(ctx, base);
	// b 0x827e9808
	goto loc_827E9808;
loc_827E97AC:
	// cmplwi cr6,r14,2
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 2, ctx.xer);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bgt cr6,0x827e97dc
	if (ctx.cr6.gt) goto loc_827E97DC;
	// addi r11,r27,45
	ctx.r11.s64 = ctx.r27.s64 + 45;
	// lwz r10,700(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 700);
	// lwz r5,2312(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 2312);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,2308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 2308);
	// lbzx r6,r28,r10
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// lhzx r7,r9,r31
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r31.u32);
	// bl 0x827e9a00
	ctx.lr = 0x827E97D8;
	sub_827E9A00(ctx, base);
	// b 0x827e9808
	goto loc_827E9808;
loc_827E97DC:
	// lwz r11,700(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 700);
	// subfic r10,r14,581
	ctx.xer.ca = ctx.r14.u32 <= 581;
	ctx.r10.u64 = static_cast<uint64_t>(581) - ctx.r14.u64;
	// addi r9,r27,45
	ctx.r9.s64 = ctx.r27.s64 + 45;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r6,r28,r11
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// lwzx r11,r8,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lhzx r5,r7,r31
	ctx.r5.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x827b4b00
	ctx.lr = 0x827E9808;
	sub_827B4B00(ctx, base);
loc_827E9808:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwinm r15,r15,31,25,31
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 31) & 0x7F;
	// rldicr r16,r16,8,55
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r28,6
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 6, ctx.xer);
	// blt cr6,0x827e95f4
	if (ctx.cr6.lt) goto loc_827E95F4;
loc_827E981C:
	// lhz r8,18(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 18);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r3,r8,2
	ctx.r3.s64 = ctx.r8.s64 + 2;
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r7,r5,1
	ctx.r7.s64 = ctx.r5.s64 + 1;
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r5,r4,4
	ctx.r5.s64 = ctx.r4.s64 + 4;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r7,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// stw r5,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// stw r9,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// stw r6,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
	// stw r4,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r4.u32);
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// sth r3,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r3.u16);
	// blt cr6,0x827e8ca8
	if (ctx.cr6.lt) goto loc_827E8CA8;
loc_827E9888:
	// lhz r8,16(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 16);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// addi r7,r8,2
	ctx.r7.s64 = ctx.r8.s64 + 2;
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r8,120(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// sth r7,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r7.u16);
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r5,1
	ctx.r7.s64 = ctx.r5.s64 + 1;
	// lwz r8,144(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stw r7,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r3,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// lhz r11,50(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 50);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r5,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r5.u32);
	// blt cr6,0x827e8c50
	if (ctx.cr6.lt) goto loc_827E8C50;
loc_827E98EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,2624
	ctx.r1.s64 = ctx.r1.s64 + 2624;
	// b 0x826a1cd0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827E98F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a1cb8
	ctx.lr = 0x827E9900;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32106
	ctx.r11.s64 = -2104098816;
	// addi r28,r3,22640
	ctx.r28.s64 = ctx.r3.s64 + 22640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,30024(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 30024);
	// bl 0x827d1cd0
	ctx.lr = 0x827E991C;
	sub_827D1CD0(ctx, base);
	// addi r29,r31,17360
	ctx.r29.s64 = ctx.r31.s64 + 17360;
	// addi r30,r31,15952
	ctx.r30.s64 = ctx.r31.s64 + 15952;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827ea200
	ctx.lr = 0x827E9934;
	sub_827EA200(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827e99f8
	if (!ctx.cr6.eq) goto loc_827E99F8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827e9e00
	ctx.lr = 0x827E994C;
	sub_827E9E00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827e99f8
	if (!ctx.cr6.eq) goto loc_827E99F8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827e8ba0
	ctx.lr = 0x827E9964;
	sub_827E8BA0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827e99f8
	if (!ctx.cr6.eq) goto loc_827E99F8;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827e99d0
	if (ctx.cr6.eq) goto loc_827E99D0;
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x827e9994
	if (!ctx.cr6.eq) goto loc_827E9994;
	// bl 0x827e8ac0
	ctx.lr = 0x827E9990;
	sub_827E8AC0(ctx, base);
	// b 0x827e9998
	goto loc_827E9998;
loc_827E9994:
	// bl 0x827e8a00
	ctx.lr = 0x827E9998;
	sub_827E8A00(ctx, base);
loc_827E9998:
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// lwz r6,3748(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// bl 0x82732760
	ctx.lr = 0x827E99D0;
	sub_82732760(ctx, base);
loc_827E99D0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827d2018
	ctx.lr = 0x827E99DC;
	sub_827D2018(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r10.u32);
	// stw r11,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r11.u32);
	// stw r11,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
loc_827E99F8:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x826a1d08
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827E9A00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,144
	ctx.r8.s64 = 144;
	// add r4,r4,r6
	ctx.r4.u64 = ctx.r4.u64 + ctx.r6.u64;
	// add r2,r5,r6
	ctx.r2.u64 = ctx.r5.u64 + ctx.r6.u64;
	// li r6,48
	ctx.r6.s64 = 48;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// li r7,96
	ctx.r7.s64 = 96;
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,192
	ctx.r9.s64 = 192;
	// lvx128 v11,r0,r2
	ea = (ctx.r2.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,240
	ctx.r10.s64 = 240;
	// lvx128 v2,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v1,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// lvx128 v12,r2,r6
	ea = (ctx.r2.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,288
	ctx.r11.s64 = 288;
	// li r12,336
	ctx.r12.s64 = 336;
	// lvx128 v3,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r2,r7
	ea = (ctx.r2.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v2,v2,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// lvx128 v4,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v3,v3,v13
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// lvx128 v14,r2,r8
	ea = (ctx.r2.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v24,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// lvx128 v5,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v4,v4,v14
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v14.u16)));
	// lvx128 v15,r2,r9
	ea = (ctx.r2.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v25,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// lvx128 v6,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v5,v5,v15
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v15.u16)));
	// lvx128 v7,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v26,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// lvx128 v8,r4,r12
	ea = (ctx.r4.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// lvx128 v16,r2,r10
	ea = (ctx.r2.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r6,r5,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v17,r2,r11
	ea = (ctx.r2.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v6,v6,v16
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	// vpkshus v27,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// lvx128 v18,r2,r12
	ea = (ctx.r2.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v7,v7,v17
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// stvewx v24,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// add r7,r5,r6
	ctx.r7.u64 = ctx.r5.u64 + ctx.r6.u64;
	// vpkshus v28,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvewx v24,r0,r4
	ea = (ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// vavguh v8,v8,v18
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// stvewx v25,r3,r5
	ea = (ctx.r3.u32 + ctx.r5.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v29,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// stvewx v25,r4,r5
	ea = (ctx.r4.u32 + ctx.r5.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v26,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// add r9,r5,r8
	ctx.r9.u64 = ctx.r5.u64 + ctx.r8.u64;
	// vpkshus v30,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// stvewx v26,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v27,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// vpkshus v31,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvewx v27,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v28,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stvewx v28,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9B10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,144
	ctx.r9.s64 = 144;
	// add r2,r5,r8
	ctx.r2.u64 = ctx.r5.u64 + ctx.r8.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// add r4,r4,r8
	ctx.r4.u64 = ctx.r4.u64 + ctx.r8.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,96
	ctx.r8.s64 = 96;
	// lvx128 v14,r2,r9
	ea = (ctx.r2.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,192
	ctx.r10.s64 = 192;
	// lvx128 v11,r0,r2
	ea = (ctx.r2.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r12,r6,1,0,30
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v4,v4,v14
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v14.u16)));
	// lvx128 v2,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v1,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// lvx128 v3,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 + ctx.r10.u64;
	// lvx128 v12,r2,r7
	ea = (ctx.r2.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r2,r8
	ea = (ctx.r2.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v2,v2,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// lvx128 v15,r2,r10
	ea = (ctx.r2.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r2,r2,r10
	ctx.r2.u64 = ctx.r2.u64 + ctx.r10.u64;
	// li r10,64
	ctx.r10.s64 = 64;
	// vavguh v3,v3,v13
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// lvx128 v6,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v5,v5,v15
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v15.u16)));
	// lvx128 v7,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// lvx128 v16,r2,r7
	ea = (ctx.r2.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v17,r2,r8
	ea = (ctx.r2.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v18,r2,r9
	ea = (ctx.r2.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v6,v6,v16
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	// lvx128 v16,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// vavguh v7,v7,v17
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// lvx128 v20,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r5,r7
	ea = (ctx.r5.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v24,v1,v16
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vavguh v8,v8,v18
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// lvx128 v18,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v25,v2,v17
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// lvx128 v19,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v26,v3,v18
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vpkshus v24,v24,v24
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// vaddshs v27,v4,v19
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vpkshus v25,v25,v25
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16)));
	// vaddshs v28,v5,v20
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vpkshus v26,v26,v26
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vpkshus v27,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// lvx128 v21,r5,r7
	ea = (ctx.r5.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r6,r12
	ctx.r7.u64 = ctx.r6.u64 + ctx.r12.u64;
	// lvx128 v23,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v28,v28,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// stvewx v24,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stvewx v24,r0,r4
	ea = (ctx.r4.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// vaddshs v29,v6,v21
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// stvewx v25,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// vaddshs v30,v7,v22
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// stvewx v25,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// vaddshs v31,v8,v23
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// stvewx v26,r3,r12
	ea = (ctx.r3.u32 + ctx.r12.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// add r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 + ctx.r8.u64;
	// stvewx v26,r4,r12
	ea = (ctx.r4.u32 + ctx.r12.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v29,v29,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// stvewx v27,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v30,v30,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// stvewx v27,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// add r10,r12,r8
	ctx.r10.u64 = ctx.r12.u64 + ctx.r8.u64;
	// stvewx v28,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v31,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stvewx v28,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9E00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a1c80
	ctx.lr = 0x827E9E08;
	__savegprlr_14(ctx, base);
	// stwu r1,-1728(r1)
	ea = -1728 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r25,1312(r4)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r4.u32 + 1312);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// ori r8,r10,39772
	ctx.r8.u64 = ctx.r10.u64 | 39772;
	// addi r9,r1,223
	ctx.r9.s64 = ctx.r1.s64 + 223;
	// addi r7,r1,796
	ctx.r7.s64 = ctx.r1.s64 + 796;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r6,r9,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// lwzx r10,r3,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// rlwinm r5,r7,0,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r6,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r6.u32);
	// stw r5,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// lwz r10,22492(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 22492);
	// li r15,0
	ctx.r15.s64 = 0;
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// mr r19,r25
	ctx.r19.u64 = ctx.r25.u64;
	// lwz r11,22504(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 22504);
	// addi r14,r11,4
	ctx.r14.s64 = ctx.r11.s64 + 4;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r21,r15
	ctx.r21.u64 = ctx.r15.u64;
	// stw r15,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r15.u32);
	// mr r20,r15
	ctx.r20.u64 = ctx.r15.u64;
	// stw r15,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r15.u32);
	// mr r18,r15
	ctx.r18.u64 = ctx.r15.u64;
	// sth r15,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r15.u16);
	// mr r17,r15
	ctx.r17.u64 = ctx.r15.u64;
	// lhz r10,52(r29)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r29.u32 + 52);
	// clrlwi r6,r9,16
	ctx.r6.u64 = ctx.r9.u32 & 0xFFFF;
	// lhz r5,74(r29)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r29.u32 + 74);
	// rlwinm r7,r9,16,22,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0x3FF;
	// lhz r11,76(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// mr r23,r15
	ctx.r23.u64 = ctx.r15.u64;
	// lhz r8,50(r29)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r29.u32 + 50);
	// rlwinm r24,r8,31,1,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r16,r10,31,1,31
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// beq cr6,0x827ea038
	if (ctx.cr6.eq) goto loc_827EA038;
	// lis r27,-32106
	ctx.r27.s64 = -2104098816;
	// lis r26,-32106
	ctx.r26.s64 = -2104098816;
loc_827E9EC4:
	// stw r18,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r18.u32);
	// cmplw cr6,r23,r7
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r7.u32, ctx.xer);
	// stw r17,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r17.u32);
	// sth r15,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r15.u16);
	// bne cr6,0x827e9fe4
	if (!ctx.cr6.eq) goto loc_827E9FE4;
	// mr r22,r15
	ctx.r22.u64 = ctx.r15.u64;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x827e9fe4
	if (ctx.cr6.eq) goto loc_827E9FE4;
loc_827E9EE4:
	// cmplw cr6,r22,r6
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x827e9f98
	if (!ctx.cr6.eq) goto loc_827E9F98;
	// ld r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r25.u32 + 0);
	// mr r30,r15
	ctx.r30.u64 = ctx.r15.u64;
	// rldicl r10,r11,8,56
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// clrlwi r28,r10,26
	ctx.r28.u64 = ctx.r10.u32 & 0x3F;
loc_827E9EFC:
	// srawi r11,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 2;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r9,r30,140
	ctx.r9.s64 = ctx.r30.s64 + 140;
	// lwz r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// li r4,-128
	ctx.r4.s64 = -128;
	// lwzx r10,r6,r29
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// lwzx r11,r5,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// dcbt r4,r3
	// dcbzl r0,r8
	ea = (ctx.r8.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// srawi r10,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 2;
	// lwz r8,392(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 392);
	// rlwinm r11,r28,6,18,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 6) & 0x3FC0;
	// addi r10,r10,45
	ctx.r10.s64 = ctx.r10.s64 + 45;
	// lwz r9,29984(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 29984);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r6,29980(r27)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r27.u32 + 29980);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,40(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lhzx r8,r8,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// bl 0x8277dbd0
	ctx.lr = 0x827E9F64;
	sub_8277DBD0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,6
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 6, ctx.xer);
	// blt cr6,0x827e9efc
	if (ctx.cr6.lt) goto loc_827E9EFC;
	// lwz r11,0(r14)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r14.u32 + 0);
	// addi r14,r14,4
	ctx.r14.s64 = ctx.r14.s64 + 4;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r7,r11,16,22,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0x3FF;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// clrlwi r6,r11,16
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplw cr6,r23,r7
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x827e9ee4
	if (ctx.cr6.eq) goto loc_827E9EE4;
	// b 0x827e9fe4
	goto loc_827E9FE4;
loc_827E9F98:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// lhz r8,18(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 18);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r8,2
	ctx.r4.s64 = ctx.r8.s64 + 2;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// cmplw cr6,r22,r24
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r24.u32, ctx.xer);
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// sth r4,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r4.u16);
	// blt cr6,0x827e9ee4
	if (ctx.cr6.lt) goto loc_827E9EE4;
loc_827E9FE4:
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 16);
	// rlwinm r11,r24,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,88(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r21,r10,r21
	ctx.r21.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r19,r11,r19
	ctx.r19.u64 = ctx.r11.u64 + ctx.r19.u64;
	// addi r4,r9,2
	ctx.r4.s64 = ctx.r9.s64 + 2;
	// stw r21,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r21.u32);
	// add r20,r24,r20
	ctx.r20.u64 = ctx.r24.u64 + ctx.r20.u64;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r4,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r4.u16);
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r20,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r20.u32);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// add r18,r10,r18
	ctx.r18.u64 = ctx.r10.u64 + ctx.r18.u64;
	// add r17,r11,r17
	ctx.r17.u64 = ctx.r11.u64 + ctx.r17.u64;
	// cmplw cr6,r23,r16
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x827e9ec4
	if (ctx.cr6.lt) goto loc_827E9EC4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_827EA038:
	// addi r1,r1,1728
	ctx.r1.s64 = ctx.r1.s64 + 1728;
	// b 0x826a1cd0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827EA200) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a1c80
	ctx.lr = 0x827EA208;
	__savegprlr_14(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2952(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2952);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// lwz r10,2112(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 2112);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// addi r8,r11,732
	ctx.r8.s64 = ctx.r11.s64 + 732;
	// lwz r9,3984(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 3984);
	// addi r7,r11,735
	ctx.r7.s64 = ctx.r11.s64 + 735;
	// stw r3,356(r1)
	REX_STORE_U32(ctx.r1.u32 + 356, ctx.r3.u32);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,372(r1)
	REX_STORE_U32(ctx.r1.u32 + 372, ctx.r5.u32);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwzx r11,r6,r15
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r15.u32);
	// addi r4,r10,266
	ctx.r4.s64 = ctx.r10.s64 + 266;
	// li r17,1
	ctx.r17.s64 = 1;
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// stw r11,2904(r15)
	REX_STORE_U32(ctx.r15.u32 + 2904, ctx.r11.u32);
	// lwzx r8,r5,r15
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r15.u32);
	// stw r8,2916(r15)
	REX_STORE_U32(ctx.r15.u32 + 2916, ctx.r8.u32);
	// lwz r7,2124(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 2124);
	// stw r7,2116(r15)
	REX_STORE_U32(ctx.r15.u32 + 2116, ctx.r7.u32);
	// lwzx r6,r10,r15
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r15.u32);
	// stw r6,2120(r15)
	REX_STORE_U32(ctx.r15.u32 + 2120, ctx.r6.u32);
	// bne cr6,0x827ea284
	if (!ctx.cr6.eq) goto loc_827EA284;
	// stw r25,456(r15)
	REX_STORE_U32(ctx.r15.u32 + 456, ctx.r25.u32);
	// b 0x827ea288
	goto loc_827EA288;
loc_827EA284:
	// stw r17,456(r15)
	REX_STORE_U32(ctx.r15.u32 + 456, ctx.r17.u32);
loc_827EA288:
	// lwz r11,14808(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 14808);
	// lwz r10,3416(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 3416);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x827ea2ac
	if (ctx.cr6.eq) goto loc_827EA2AC;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x827ea2b4
	goto loc_827EA2B4;
loc_827EA2AC:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,3
	ctx.r10.s64 = 3;
loc_827EA2B4:
	// stw r10,14816(r15)
	REX_STORE_U32(ctx.r15.u32 + 14816, ctx.r10.u32);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// stw r11,14812(r15)
	REX_STORE_U32(ctx.r15.u32 + 14812, ctx.r11.u32);
	// beq cr6,0x827ea2d0
	if (ctx.cr6.eq) goto loc_827EA2D0;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bne cr6,0x827ea2d4
	if (!ctx.cr6.eq) goto loc_827EA2D4;
loc_827EA2D0:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_827EA2D4:
	// lwz r10,1996(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 1996);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,76(r10)
	REX_STORE_U32(ctx.r10.u32 + 76, ctx.r11.u32);
	// lwz r4,248(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 248);
	// lwz r3,1996(r15)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r15.u32 + 1996);
	// bl 0x8276fa60
	ctx.lr = 0x827EA2EC;
	sub_8276FA60(ctx, base);
	// lwz r11,248(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 248);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x827ea308
	if (!ctx.cr6.lt) goto loc_827EA308;
	// addi r11,r15,2488
	ctx.r11.s64 = ctx.r15.s64 + 2488;
	// addi r10,r15,2504
	ctx.r10.s64 = ctx.r15.s64 + 2504;
	// addi r9,r15,2544
	ctx.r9.s64 = ctx.r15.s64 + 2544;
	// b 0x827ea32c
	goto loc_827EA32C;
loc_827EA308:
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// bge cr6,0x827ea320
	if (!ctx.cr6.lt) goto loc_827EA320;
	// addi r11,r15,2476
	ctx.r11.s64 = ctx.r15.s64 + 2476;
	// addi r10,r15,2516
	ctx.r10.s64 = ctx.r15.s64 + 2516;
	// addi r9,r15,2556
	ctx.r9.s64 = ctx.r15.s64 + 2556;
	// b 0x827ea32c
	goto loc_827EA32C;
loc_827EA320:
	// addi r11,r15,2464
	ctx.r11.s64 = ctx.r15.s64 + 2464;
	// addi r10,r15,2528
	ctx.r10.s64 = ctx.r15.s64 + 2528;
	// addi r9,r15,2568
	ctx.r9.s64 = ctx.r15.s64 + 2568;
loc_827EA32C:
	// stw r11,2500(r15)
	REX_STORE_U32(ctx.r15.u32 + 2500, ctx.r11.u32);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// stw r10,2540(r15)
	REX_STORE_U32(ctx.r15.u32 + 2540, ctx.r10.u32);
	// stw r9,2580(r15)
	REX_STORE_U32(ctx.r15.u32 + 2580, ctx.r9.u32);
	// lwz r11,268(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 268);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82731b08
	ctx.lr = 0x827EA348;
	sub_82731B08(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x82756b90
	ctx.lr = 0x827EA354;
	sub_82756B90(ctx, base);
	// lwz r10,22488(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 22488);
	// lhz r9,50(r18)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r18.u32 + 50);
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// lhz r8,52(r18)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r18.u32 + 52);
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// rlwinm r7,r9,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// rlwinm r26,r8,31,1,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r25,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r25.u32);
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// mr r14,r25
	ctx.r14.u64 = ctx.r25.u64;
	// lwz r6,22500(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 22500);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stw r6,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// lwz r5,22492(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 22492);
	// stw r5,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
	// lwz r4,22504(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 22504);
	// stw r25,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r25.u32);
	// stw r25,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r7,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// stw r26,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r26.u32);
	// stw r4,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// stw r25,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
	// stw r25,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// sth r25,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r25.u16);
	// sth r25,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r25.u16);
	// ble cr6,0x827ecdcc
	if (!ctx.cr6.gt) goto loc_827ECDCC;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r16,r11,-30000
	ctx.r16.s64 = ctx.r11.s64 + -30000;
	// addi r11,r10,-30440
	ctx.r11.s64 = ctx.r10.s64 + -30440;
	// stw r16,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r16.u32);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_827EA3D8:
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// sth r25,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r25.u16);
	// stw r27,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// lwz r11,22164(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 22164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827ea5f0
	if (ctx.cr6.eq) goto loc_827EA5F0;
	// lwz r11,1304(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1304);
	// rlwinm r10,r14,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x827ea5f0
	if (ctx.cr6.eq) goto loc_827EA5F0;
	// lwz r11,84(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// ld r10,104(r18)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r18.u32 + 104);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// lwz r9,112(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 112);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// stw r9,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lwz r7,84(r15)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,116(r18)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r18.u32 + 116);
	// stw r6,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r6.u32);
	// lwz r5,84(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r4,120(r18)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r18.u32 + 120);
	// stw r4,16(r5)
	REX_STORE_U32(ctx.r5.u32 + 16, ctx.r4.u32);
	// lwz r3,84(r15)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,124(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 124);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r9,128(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 128);
	// stw r9,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,132(r18)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r18.u32 + 132);
	// stw r7,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,136(r18)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r18.u32 + 136);
	// stw r5,32(r6)
	REX_STORE_U32(ctx.r6.u32 + 32, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r3,140(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 140);
	// stw r3,36(r4)
	REX_STORE_U32(ctx.r4.u32 + 36, ctx.r3.u32);
	// lwz r11,84(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r10,144(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 144);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r9,84(r15)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r8,148(r18)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r18.u32 + 148);
	// stw r8,44(r9)
	REX_STORE_U32(ctx.r9.u32 + 44, ctx.r8.u32);
	// lwz r7,84(r15)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,152(r18)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r18.u32 + 152);
	// stw r6,48(r7)
	REX_STORE_U32(ctx.r7.u32 + 48, ctx.r6.u32);
	// lwz r31,84(r15)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,28(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x827ea538
	if (ctx.cr6.eq) goto loc_827EA538;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x827ea514
	if (!ctx.cr6.lt) goto loc_827EA514;
loc_827EA4BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827ea514
	if (ctx.cr6.eq) goto loc_827EA514;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827ea504
	if (!ctx.cr0.lt) goto loc_827EA504;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EA504;
	sub_82725E38(ctx, base);
loc_827EA504:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827ea4bc
	if (ctx.cr6.gt) goto loc_827EA4BC;
loc_827EA514:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r9,r30,32
	ctx.r9.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// subf. r8,r30,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// sld r7,r11,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// std r7,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r7.u64);
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// bge 0x827ea538
	if (!ctx.cr0.lt) goto loc_827EA538;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EA538;
	sub_82725E38(ctx, base);
loc_827EA538:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r4,r11,29
	ctx.r4.u64 = ctx.r11.u32 & 0x7;
	// bl 0x82725f80
	ctx.lr = 0x827EA548;
	sub_82725F80(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x8275e738
	ctx.lr = 0x827EA554;
	sub_8275E738(ctx, base);
	// lwz r10,84(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ld r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// std r9,104(r18)
	REX_STORE_U64(ctx.r18.u32 + 104, ctx.r9.u64);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,112(r18)
	REX_STORE_U32(ctx.r18.u32 + 112, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,12(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r5,116(r18)
	REX_STORE_U32(ctx.r18.u32 + 116, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// stw r11,120(r18)
	REX_STORE_U32(ctx.r18.u32 + 120, ctx.r11.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// stw r9,124(r18)
	REX_STORE_U32(ctx.r18.u32 + 124, ctx.r9.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,24(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 24);
	// stw r7,128(r18)
	REX_STORE_U32(ctx.r18.u32 + 128, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,28(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 28);
	// stw r5,132(r18)
	REX_STORE_U32(ctx.r18.u32 + 132, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,32(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
	// stw r11,136(r18)
	REX_STORE_U32(ctx.r18.u32 + 136, ctx.r11.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// stw r9,140(r18)
	REX_STORE_U32(ctx.r18.u32 + 140, ctx.r9.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,40(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 40);
	// stw r7,144(r18)
	REX_STORE_U32(ctx.r18.u32 + 144, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,44(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 44);
	// stw r5,148(r18)
	REX_STORE_U32(ctx.r18.u32 + 148, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,48(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 48);
	// stw r11,152(r18)
	REX_STORE_U32(ctx.r18.u32 + 152, ctx.r11.u32);
	// stb r17,1251(r18)
	REX_STORE_U8(ctx.r18.u32 + 1251, ctx.r17.u8);
	// bne cr6,0x827ece8c
	if (!ctx.cr6.eq) goto loc_827ECE8C;
loc_827EA5F0:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827ecd64
	if (!ctx.cr6.gt) goto loc_827ECD64;
loc_827EA600:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r26,84(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,128
	ctx.r10.s64 = 128;
	// ori r25,r11,32768
	ctx.r25.u64 = ctx.r11.u64 | 32768;
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// dcbt r10,r9
	// lis r12,-4289
	ctx.r12.s64 = -281083904;
	// lwz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r19,0
	ctx.r19.s64 = 0;
	// ori r12,r12,63743
	ctx.r12.u64 = ctx.r12.u64 | 63743;
	// li r22,0
	ctx.r22.s64 = 0;
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r7,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r7.u32);
	// li r20,0
	ctx.r20.s64 = 0;
	// li r21,0
	ctx.r21.s64 = 0;
	// lbz r6,24(r18)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r18.u32 + 24);
	// stb r6,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r6.u8);
	// lwz r5,1824(r18)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r18.u32 + 1824);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x827ea68c
	if (!ctx.cr6.eq) goto loc_827EA68C;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827ea680
	if (!ctx.cr0.lt) goto loc_827EA680;
	// bl 0x82725e38
	ctx.lr = 0x827EA680;
	sub_82725E38(ctx, base);
loc_827EA680:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r11,r31,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_827EA68C:
	// lbz r11,26(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 26);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827ea6cc
	if (!ctx.cr6.eq) goto loc_827EA6CC;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827ea6c0
	if (!ctx.cr0.lt) goto loc_827EA6C0;
	// bl 0x82725e38
	ctx.lr = 0x827EA6C0;
	sub_82725E38(ctx, base);
loc_827EA6C0:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r11,r31,31,0,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_827EA6CC:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bne cr6,0x827ea6e4
	if (!ctx.cr6.eq) goto loc_827EA6E4;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// b 0x827eab80
	goto loc_827EAB80;
loc_827EA6E4:
	// rlwinm r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827eaac8
	if (!ctx.cr6.eq) goto loc_827EAAC8;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,336(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 336);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,10,54
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 10) & 0x3FF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ea7d8
	if (ctx.cr6.lt) goto loc_827EA7D8;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827ea7d0
	if (!ctx.cr6.lt) goto loc_827EA7D0;
loc_827EA738:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827ea764
	if (ctx.cr6.lt) goto loc_827EA764;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827EA754;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827ea738
	if (ctx.cr6.eq) goto loc_827EA738;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ea814
	goto loc_827EA814;
loc_827EA764:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_827EA7D0:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ea814
	goto loc_827EA814;
loc_827EA7D8:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EA7E4;
	sub_82725F80(ctx, base);
loc_827EA7E4:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EA7FC;
	sub_82725F80(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ea7e4
	if (ctx.cr6.lt) goto loc_827EA7E4;
loc_827EA814:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// li r10,37
	ctx.r10.s64 = 37;
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// subfc r7,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r7.u64 = ctx.r11.u64 - ctx.r10.u64;
	// adde. r10,r8,r9
	temp.u8 = (ctx.r8.u32 + ctx.r9.u32 < ctx.r8.u32) | (ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// extsw r23,r10
	ctx.r23.s64 = ctx.r10.s32;
	// beq 0x827ea838
	if (ctx.cr0.eq) goto loc_827EA838;
	// addi r11,r11,-37
	ctx.r11.s64 = ctx.r11.s64 + -37;
loc_827EA838:
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827eaaa4
	if (ctx.cr6.eq) goto loc_827EAAA4;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bge cr6,0x827ea990
	if (!ctx.cr6.lt) goto loc_827EA990;
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// srawi r7,r8,24
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 24;
	// srawi r6,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 4;
	// srawi r5,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 8;
	// clrlwi r11,r8,28
	ctx.r11.u64 = ctx.r8.u32 & 0xF;
	// clrlwi r28,r6,28
	ctx.r28.u64 = ctx.r6.u32 & 0xF;
	// srawi r4,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 16;
	// add. r30,r28,r11
	ctx.r30.u64 = ctx.r28.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// clrlwi r27,r7,24
	ctx.r27.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r26,r5,24
	ctx.r26.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r25,r4,24
	ctx.r25.u64 = ctx.r4.u32 & 0xFF;
	// ble 0x827ea940
	if (!ctx.cr0.gt) goto loc_827EA940;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bgt cr6,0x827ea940
	if (ctx.cr6.gt) goto loc_827EA940;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x827ea940
	if (ctx.cr6.eq) goto loc_827EA940;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827ea900
	if (!ctx.cr6.gt) goto loc_827EA900;
loc_827EA8A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827ea900
	if (ctx.cr6.eq) goto loc_827EA900;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827ea8f0
	if (!ctx.cr0.lt) goto loc_827EA8F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EA8F0;
	sub_82725E38(ctx, base);
loc_827EA8F0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827ea8a8
	if (ctx.cr6.gt) goto loc_827EA8A8;
loc_827EA900:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827ea938
	if (!ctx.cr0.lt) goto loc_827EA938;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EA938;
	sub_82725E38(ctx, base);
loc_827EA938:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x827ea944
	goto loc_827EA944;
loc_827EA940:
	// li r10,0
	ctx.r10.s64 = 0;
loc_827EA944:
	// sraw r11,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r11.s64 = ctx.r10.s32 >> temp.u32;
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ctx.r27.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// clrlwi r7,r9,31
	ctx.r7.u64 = ctx.r9.u32 & 0x1;
	// add r6,r11,r25
	ctx.r6.u64 = ctx.r11.u64 + ctx.r25.u64;
	// neg r4,r7
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// neg r5,r8
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// add r3,r10,r26
	ctx.r3.u64 = ctx.r10.u64 + ctx.r26.u64;
	// lwz r26,84(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// xor r11,r6,r4
	ctx.r11.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// xor r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// subf r9,r4,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r4.u64;
	// subf r11,r5,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r5.u64;
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// ori r25,r8,32768
	ctx.r25.u64 = ctx.r8.u64 | 32768;
	// b 0x827eaaa4
	goto loc_827EAAA4;
loc_827EA990:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// bne cr6,0x827ea9a4
	if (!ctx.cr6.eq) goto loc_827EA9A4;
	// mr r24,r17
	ctx.r24.u64 = ctx.r17.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827eaaa4
	goto loc_827EAAA4;
loc_827EA9A4:
	// lbz r11,30(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 30);
	// li r29,0
	ctx.r29.s64 = 0;
	// lhz r10,70(r18)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r18.u32 + 70);
	// lhz r9,72(r18)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r18.u32 + 72);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r28,r11,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// add r30,r28,r27
	ctx.r30.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x827ea9d8
	if (!ctx.cr6.gt) goto loc_827EA9D8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x827eaa84
	goto loc_827EAA84;
loc_827EA9D8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x827ea9e8
	if (!ctx.cr6.eq) goto loc_827EA9E8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x827eaa84
	goto loc_827EAA84;
loc_827EA9E8:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827eaa48
	if (!ctx.cr6.gt) goto loc_827EAA48;
loc_827EA9F0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eaa48
	if (ctx.cr6.eq) goto loc_827EAA48;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eaa38
	if (!ctx.cr0.lt) goto loc_827EAA38;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAA38;
	sub_82725E38(ctx, base);
loc_827EAA38:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827ea9f0
	if (ctx.cr6.gt) goto loc_827EA9F0;
loc_827EAA48:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eaa80
	if (!ctx.cr0.lt) goto loc_827EAA80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAA80;
	sub_82725E38(ctx, base);
loc_827EAA80:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_827EAA84:
	// slw r11,r17,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r27.u8 & 0x3F));
	// slw r9,r17,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r28.u8 & 0x3F));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sraw r8,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r8.s64 = ctx.r10.s32 >> temp.u32;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// and r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 & ctx.r8.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827EAAA4:
	// rldicr r10,r23,8,55
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// or r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 | ctx.r24.u64;
	// rldimi r9,r8,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// rldicl r7,r9,24,40
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 24) & 0xFFFFFF;
	// rldicl r6,r9,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// clrlwi r30,r7,31
	ctx.r30.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r22,r6,31
	ctx.r22.u64 = ctx.r6.u32 & 0x1;
	// rotlwi r20,r9,0
	ctx.r20.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
loc_827EAAC8:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x827eab80
	if (!ctx.cr6.eq) goto loc_827EAB80;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x827eaaec
	if (ctx.cr6.eq) goto loc_827EAAEC;
	// li r10,3
	ctx.r10.s64 = 3;
	// rlwimi r11,r10,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// b 0x827eab7c
	goto loc_827EAB7C;
loc_827EAAEC:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eab14
	if (!ctx.cr0.lt) goto loc_827EAB14;
	// bl 0x82725e38
	ctx.lr = 0x827EAB14;
	sub_82725E38(ctx, base);
loc_827EAB14:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x827eab30
	if (!ctx.cr6.eq) goto loc_827EAB30;
	// lwz r11,1828(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1828);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r10,r11,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x827eab80
	goto loc_827EAB80;
loc_827EAB30:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eab58
	if (!ctx.cr0.lt) goto loc_827EAB58;
	// bl 0x82725e38
	ctx.lr = 0x827EAB58;
	sub_82725E38(ctx, base);
loc_827EAB58:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x827eab74
	if (!ctx.cr6.eq) goto loc_827EAB74;
	// lwz r11,1832(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1832);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r10,r11,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x827eab80
	goto loc_827EAB80;
loc_827EAB74:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r11,r17,6,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 6) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
loc_827EAB7C:
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_827EAB80:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827eab9c
	if (ctx.cr6.eq) goto loc_827EAB9C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,5(r26)
	REX_STORE_U8(ctx.r26.u32 + 5, ctx.r11.u8);
	// b 0x827eb988
	goto loc_827EB988;
loc_827EAB9C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x827eaed8
	if (!ctx.cr6.eq) goto loc_827EAED8;
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// lbz r10,27(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 27);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827eae94
	if (ctx.cr6.eq) goto loc_827EAE94;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x827eb984
	if (ctx.cr6.eq) goto loc_827EB984;
	// lbz r10,1245(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1245);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827eac0c
	if (ctx.cr6.eq) goto loc_827EAC0C;
	// rlwinm r11,r11,20,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xF;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827eabf0
	if (ctx.cr6.eq) goto loc_827EABF0;
	// lbz r11,1246(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// stb r10,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r10.u8);
	// b 0x827eae68
	goto loc_827EAE68;
loc_827EABF0:
	// lbz r10,1244(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r9.u8);
	// b 0x827eae68
	goto loc_827EAE68;
loc_827EAC0C:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// lbz r11,1250(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1250);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x827eacfc
	if (ctx.cr6.eq) goto loc_827EACFC;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x827eac8c
	if (!ctx.cr6.lt) goto loc_827EAC8C;
loc_827EAC34:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eac8c
	if (ctx.cr6.eq) goto loc_827EAC8C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eac7c
	if (!ctx.cr0.lt) goto loc_827EAC7C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAC7C;
	sub_82725E38(ctx, base);
loc_827EAC7C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eac34
	if (ctx.cr6.gt) goto loc_827EAC34;
loc_827EAC8C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eacc4
	if (!ctx.cr0.lt) goto loc_827EACC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EACC4;
	sub_82725E38(ctx, base);
loc_827EACC4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x827eace0
	if (ctx.cr6.eq) goto loc_827EACE0;
	// lbz r11,1246(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x827eae68
	goto loc_827EAE68;
loc_827EACE0:
	// lbz r10,1244(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x827eae68
	goto loc_827EAE68;
loc_827EACFC:
	// li r30,3
	ctx.r30.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x827ead60
	if (!ctx.cr6.lt) goto loc_827EAD60;
loc_827EAD08:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827ead60
	if (ctx.cr6.eq) goto loc_827EAD60;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827ead50
	if (!ctx.cr0.lt) goto loc_827EAD50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAD50;
	sub_82725E38(ctx, base);
loc_827EAD50:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827ead08
	if (ctx.cr6.gt) goto loc_827EAD08;
loc_827EAD60:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827ead98
	if (!ctx.cr0.lt) goto loc_827EAD98;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAD98;
	sub_82725E38(ctx, base);
loc_827EAD98:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x827eae54
	if (!ctx.cr6.eq) goto loc_827EAE54;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r30,5
	ctx.r30.s64 = 5;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x827eae14
	if (!ctx.cr6.lt) goto loc_827EAE14;
loc_827EADBC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eae14
	if (ctx.cr6.eq) goto loc_827EAE14;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eae04
	if (!ctx.cr0.lt) goto loc_827EAE04;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAE04;
	sub_82725E38(ctx, base);
loc_827EAE04:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eadbc
	if (ctx.cr6.gt) goto loc_827EADBC;
loc_827EAE14:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eae4c
	if (!ctx.cr0.lt) goto loc_827EAE4C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EAE4C;
	sub_82725E38(ctx, base);
loc_827EAE4C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x827eae5c
	goto loc_827EAE5C;
loc_827EAE54:
	// lbz r11,1244(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1244);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_827EAE5C:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
loc_827EAE68:
	// lbz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x827eae7c
	if (ctx.cr6.lt) goto loc_827EAE7C;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// ble cr6,0x827eae94
	if (!ctx.cr6.gt) goto loc_827EAE94;
loc_827EAE7C:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x827eb9a4
	goto loc_827EB9A4;
loc_827EAE94:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x827eb984
	if (ctx.cr6.eq) goto loc_827EB984;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eaec4
	if (!ctx.cr0.lt) goto loc_827EAEC4;
	// bl 0x82725e38
	ctx.lr = 0x827EAEC4;
	sub_82725E38(ctx, base);
loc_827EAEC4:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// b 0x827eb984
	goto loc_827EB984;
loc_827EAED8:
	// rlwinm r11,r11,0,24,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bne cr6,0x827eb2e0
	if (!ctx.cr6.eq) goto loc_827EB2E0;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,336(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 336);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,10,54
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 10) & 0x3FF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827eafcc
	if (ctx.cr6.lt) goto loc_827EAFCC;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827eafc4
	if (!ctx.cr6.lt) goto loc_827EAFC4;
loc_827EAF2C:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827eaf58
	if (ctx.cr6.lt) goto loc_827EAF58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827EAF48;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827eaf2c
	if (ctx.cr6.eq) goto loc_827EAF2C;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827eb008
	goto loc_827EB008;
loc_827EAF58:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_827EAFC4:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827eb008
	goto loc_827EB008;
loc_827EAFCC:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EAFD8;
	sub_82725F80(ctx, base);
loc_827EAFD8:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EAFF0;
	sub_82725F80(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827eafd8
	if (ctx.cr6.lt) goto loc_827EAFD8;
loc_827EB008:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// li r10,37
	ctx.r10.s64 = 37;
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// subfc r7,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r7.u64 = ctx.r11.u64 - ctx.r10.u64;
	// adde. r10,r8,r9
	temp.u8 = (ctx.r8.u32 + ctx.r9.u32 < ctx.r8.u32) | (ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// extsw r23,r10
	ctx.r23.s64 = ctx.r10.s32;
	// beq 0x827eb02c
	if (ctx.cr0.eq) goto loc_827EB02C;
	// addi r11,r11,-37
	ctx.r11.s64 = ctx.r11.s64 + -37;
loc_827EB02C:
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827eb298
	if (ctx.cr6.eq) goto loc_827EB298;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bge cr6,0x827eb184
	if (!ctx.cr6.lt) goto loc_827EB184;
	// lwz r10,12(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// srawi r7,r8,24
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 24;
	// srawi r6,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 4;
	// srawi r5,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 8;
	// clrlwi r11,r8,28
	ctx.r11.u64 = ctx.r8.u32 & 0xF;
	// clrlwi r28,r6,28
	ctx.r28.u64 = ctx.r6.u32 & 0xF;
	// srawi r4,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 16;
	// add. r30,r28,r11
	ctx.r30.u64 = ctx.r28.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// clrlwi r27,r7,24
	ctx.r27.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r26,r5,24
	ctx.r26.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r25,r4,24
	ctx.r25.u64 = ctx.r4.u32 & 0xFF;
	// ble 0x827eb134
	if (!ctx.cr0.gt) goto loc_827EB134;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bgt cr6,0x827eb134
	if (ctx.cr6.gt) goto loc_827EB134;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x827eb134
	if (ctx.cr6.eq) goto loc_827EB134;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827eb0f4
	if (!ctx.cr6.gt) goto loc_827EB0F4;
loc_827EB09C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb0f4
	if (ctx.cr6.eq) goto loc_827EB0F4;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eb0e4
	if (!ctx.cr0.lt) goto loc_827EB0E4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB0E4;
	sub_82725E38(ctx, base);
loc_827EB0E4:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eb09c
	if (ctx.cr6.gt) goto loc_827EB09C;
loc_827EB0F4:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eb12c
	if (!ctx.cr0.lt) goto loc_827EB12C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB12C;
	sub_82725E38(ctx, base);
loc_827EB12C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x827eb138
	goto loc_827EB138;
loc_827EB134:
	// li r10,0
	ctx.r10.s64 = 0;
loc_827EB138:
	// sraw r11,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r11.s64 = ctx.r10.s32 >> temp.u32;
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ctx.r27.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// clrlwi r7,r9,31
	ctx.r7.u64 = ctx.r9.u32 & 0x1;
	// add r6,r11,r25
	ctx.r6.u64 = ctx.r11.u64 + ctx.r25.u64;
	// neg r4,r7
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// neg r5,r8
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// add r3,r10,r26
	ctx.r3.u64 = ctx.r10.u64 + ctx.r26.u64;
	// lwz r26,84(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// xor r11,r6,r4
	ctx.r11.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// xor r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// subf r9,r4,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r4.u64;
	// subf r11,r5,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r5.u64;
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// ori r25,r8,32768
	ctx.r25.u64 = ctx.r8.u64 | 32768;
	// b 0x827eb298
	goto loc_827EB298;
loc_827EB184:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// bne cr6,0x827eb198
	if (!ctx.cr6.eq) goto loc_827EB198;
	// mr r24,r17
	ctx.r24.u64 = ctx.r17.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827eb298
	goto loc_827EB298;
loc_827EB198:
	// lbz r11,30(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 30);
	// li r29,0
	ctx.r29.s64 = 0;
	// lhz r10,70(r18)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r18.u32 + 70);
	// lhz r9,72(r18)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r18.u32 + 72);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r28,r11,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// add r30,r28,r27
	ctx.r30.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x827eb1cc
	if (!ctx.cr6.gt) goto loc_827EB1CC;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x827eb278
	goto loc_827EB278;
loc_827EB1CC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x827eb1dc
	if (!ctx.cr6.eq) goto loc_827EB1DC;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x827eb278
	goto loc_827EB278;
loc_827EB1DC:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827eb23c
	if (!ctx.cr6.gt) goto loc_827EB23C;
loc_827EB1E4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb23c
	if (ctx.cr6.eq) goto loc_827EB23C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eb22c
	if (!ctx.cr0.lt) goto loc_827EB22C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB22C;
	sub_82725E38(ctx, base);
loc_827EB22C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eb1e4
	if (ctx.cr6.gt) goto loc_827EB1E4;
loc_827EB23C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eb274
	if (!ctx.cr0.lt) goto loc_827EB274;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB274;
	sub_82725E38(ctx, base);
loc_827EB274:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_827EB278:
	// slw r11,r17,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r27.u8 & 0x3F));
	// slw r9,r17,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r28.u8 & 0x3F));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sraw r8,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r8.s64 = ctx.r10.s32 >> temp.u32;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_827EB298:
	// rldicr r10,r23,8,55
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// or r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 | ctx.r24.u64;
	// rldimi r9,r8,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// rldicl r7,r9,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// rldicl r6,r9,24,40
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u64, 24) & 0xFFFFFF;
	// clrlwi r5,r7,31
	ctx.r5.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r11,r6,31
	ctx.r11.u64 = ctx.r6.u32 & 0x1;
	// or r4,r5,r22
	ctx.r4.u64 = ctx.r5.u64 | ctx.r22.u64;
	// rotlwi r21,r9,0
	ctx.r21.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x827eb75c
	if (!ctx.cr6.eq) goto loc_827EB75C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x827eb2e0
	if (!ctx.cr6.eq) goto loc_827EB2E0;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// oris r10,r11,16384
	ctx.r10.u64 = ctx.r11.u64 | 1073741824;
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x827eb984
	goto loc_827EB984;
loc_827EB2E0:
	// lbz r11,29(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 29);
	// lbz r28,28(r18)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r18.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb300
	if (ctx.cr6.eq) goto loc_827EB300;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x827eb300
	if (!ctx.cr6.eq) goto loc_827EB300;
	// mr r27,r17
	ctx.r27.u64 = ctx.r17.u64;
	// b 0x827eb344
	goto loc_827EB344;
loc_827EB300:
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x827eb344
	if (ctx.cr6.eq) goto loc_827EB344;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eb334
	if (!ctx.cr0.lt) goto loc_827EB334;
	// bl 0x82725e38
	ctx.lr = 0x827EB334;
	sub_82725E38(ctx, base);
loc_827EB334:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_827EB344:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,356(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 356);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,8,56
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827eb42c
	if (ctx.cr6.lt) goto loc_827EB42C;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827eb424
	if (!ctx.cr6.lt) goto loc_827EB424;
loc_827EB38C:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827eb3b8
	if (ctx.cr6.lt) goto loc_827EB3B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827EB3A8;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827eb38c
	if (ctx.cr6.eq) goto loc_827EB38C;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827eb468
	goto loc_827EB468;
loc_827EB3B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_827EB424:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827eb468
	goto loc_827EB468;
loc_827EB42C:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EB438;
	sub_82725F80(ctx, base);
loc_827EB438:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EB450;
	sub_82725F80(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827eb438
	if (ctx.cr6.lt) goto loc_827EB438;
loc_827EB468:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// mr r19,r30
	ctx.r19.u64 = ctx.r30.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827eb494
	if (ctx.cr6.eq) goto loc_827EB494;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x827eb9a4
	goto loc_827EB9A4;
loc_827EB494:
	// lbz r11,27(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 27);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb774
	if (ctx.cr6.eq) goto loc_827EB774;
	// lbz r11,1245(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1245);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb4f0
	if (ctx.cr6.eq) goto loc_827EB4F0;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r9,r10,20,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xF;
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x827eb4d4
	if (ctx.cr6.eq) goto loc_827EB4D4;
	// lbz r11,1246(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// stb r10,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r10.u8);
	// b 0x827eb748
	goto loc_827EB748;
loc_827EB4D4:
	// lbz r10,1244(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r9.u8);
	// b 0x827eb748
	goto loc_827EB748;
loc_827EB4F0:
	// lbz r11,1250(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1250);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x827eb5dc
	if (ctx.cr6.eq) goto loc_827EB5DC;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x827eb56c
	if (!ctx.cr6.lt) goto loc_827EB56C;
loc_827EB514:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb56c
	if (ctx.cr6.eq) goto loc_827EB56C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eb55c
	if (!ctx.cr0.lt) goto loc_827EB55C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB55C;
	sub_82725E38(ctx, base);
loc_827EB55C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eb514
	if (ctx.cr6.gt) goto loc_827EB514;
loc_827EB56C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eb5a4
	if (!ctx.cr0.lt) goto loc_827EB5A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB5A4;
	sub_82725E38(ctx, base);
loc_827EB5A4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x827eb5c0
	if (ctx.cr6.eq) goto loc_827EB5C0;
	// lbz r11,1246(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x827eb748
	goto loc_827EB748;
loc_827EB5C0:
	// lbz r10,1244(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x827eb748
	goto loc_827EB748;
loc_827EB5DC:
	// li r30,3
	ctx.r30.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x827eb640
	if (!ctx.cr6.lt) goto loc_827EB640;
loc_827EB5E8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb640
	if (ctx.cr6.eq) goto loc_827EB640;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eb630
	if (!ctx.cr0.lt) goto loc_827EB630;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB630;
	sub_82725E38(ctx, base);
loc_827EB630:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eb5e8
	if (ctx.cr6.gt) goto loc_827EB5E8;
loc_827EB640:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eb678
	if (!ctx.cr0.lt) goto loc_827EB678;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB678;
	sub_82725E38(ctx, base);
loc_827EB678:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x827eb734
	if (!ctx.cr6.eq) goto loc_827EB734;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// li r30,5
	ctx.r30.s64 = 5;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x827eb6f4
	if (!ctx.cr6.lt) goto loc_827EB6F4;
loc_827EB69C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eb6f4
	if (ctx.cr6.eq) goto loc_827EB6F4;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827eb6e4
	if (!ctx.cr0.lt) goto loc_827EB6E4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB6E4;
	sub_82725E38(ctx, base);
loc_827EB6E4:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827eb69c
	if (ctx.cr6.gt) goto loc_827EB69C;
loc_827EB6F4:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827eb72c
	if (!ctx.cr0.lt) goto loc_827EB72C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EB72C;
	sub_82725E38(ctx, base);
loc_827EB72C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x827eb73c
	goto loc_827EB73C;
loc_827EB734:
	// lbz r11,1244(r18)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r18.u32 + 1244);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_827EB73C:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,4(r26)
	REX_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
loc_827EB748:
	// lbz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x827eb75c
	if (ctx.cr6.lt) goto loc_827EB75C;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// ble cr6,0x827eb774
	if (!ctx.cr6.gt) goto loc_827EB774;
loc_827EB75C:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x827eb9a4
	goto loc_827EB9A4;
loc_827EB774:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r10,r11,0,2,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// beq cr6,0x827eb7f4
	if (ctx.cr6.eq) goto loc_827EB7F4;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eb7b0
	if (!ctx.cr0.lt) goto loc_827EB7B0;
	// bl 0x82725e38
	ctx.lr = 0x827EB7B0;
	sub_82725E38(ctx, base);
loc_827EB7B0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x827eb7e8
	if (ctx.cr6.eq) goto loc_827EB7E8;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eb7e4
	if (!ctx.cr0.lt) goto loc_827EB7E4;
	// bl 0x82725e38
	ctx.lr = 0x827EB7E4;
	sub_82725E38(ctx, base);
loc_827EB7E4:
	// add r11,r31,r30
	ctx.r11.u64 = ctx.r31.u64 + ctx.r30.u64;
loc_827EB7E8:
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r10,r11,22,8,9
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0xC00000) | (ctx.r10.u64 & 0xFFFFFFFFFF3FFFFF);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
loc_827EB7F4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x827eb984
	if (ctx.cr6.eq) goto loc_827EB984;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,360(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 360);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,8,56
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827eb8e4
	if (ctx.cr6.lt) goto loc_827EB8E4;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827eb8dc
	if (!ctx.cr6.lt) goto loc_827EB8DC;
loc_827EB844:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827eb870
	if (ctx.cr6.lt) goto loc_827EB870;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827EB860;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827eb844
	if (ctx.cr6.eq) goto loc_827EB844;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827eb920
	goto loc_827EB920;
loc_827EB870:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_827EB8DC:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827eb920
	goto loc_827EB920;
loc_827EB8E4:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EB8F0;
	sub_82725F80(ctx, base);
loc_827EB8F0:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EB908;
	sub_82725F80(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827eb8f0
	if (ctx.cr6.lt) goto loc_827EB8F0;
loc_827EB920:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827eb938
	if (ctx.cr6.eq) goto loc_827EB938;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x827eb9a4
	goto loc_827EB9A4;
loc_827EB938:
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// subfc r8,r11,r30
	ctx.xer.ca = ctx.r30.u32 >= ctx.r11.u32;
	ctx.r8.u64 = ctx.r30.u64 - ctx.r11.u64;
	// eqv r7,r11,r30
	ctx.r7.u64 = ~(ctx.r11.u64 ^ ctx.r30.u64);
	// addi r6,r16,-64
	ctx.r6.s64 = ctx.r16.s64 + -64;
	// rlwinm r5,r7,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// rlwimi r10,r3,28,3,3
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 28) & 0x10000000) | (ctx.r10.u64 & 0xFFFFFFFFEFFFFFFF);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// lwzx r11,r9,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// rlwimi r10,r11,24,5,7
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x7000000) | (ctx.r10.u64 & 0xFFFFFFFFF8FFFFFF);
	// stw r10,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// lwzx r10,r9,r16
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r16.u32);
	// lwz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r9,r10,20,10,11
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x300000) | (ctx.r9.u64 & 0xFFFFFFFFFFCFFFFF);
	// rlwinm r8,r9,0,5,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r8,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r8.u32);
loc_827EB984:
	// stb r19,5(r26)
	REX_STORE_U8(ctx.r26.u32 + 5, ctx.r19.u8);
loc_827EB988:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x827eb99c
	if (ctx.cr6.eq) goto loc_827EB99C;
	// li r11,16384
	ctx.r11.s64 = 16384;
	// rldimi r11,r11,32,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r11.u64 & 0xFFFFFFFF);
	// b 0x827eb9a4
	goto loc_827EB9A4;
loc_827EB99C:
	// clrldi r11,r20,32
	ctx.r11.u64 = ctx.r20.u64 & 0xFFFFFFFF;
	// rldimi r11,r21,32,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r21.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r11.u64 & 0xFFFFFFFF);
loc_827EB9A4:
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r9,r10,0,24,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r9,96
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 96, ctx.xer);
	// beq cr6,0x827eb9c0
	if (ctx.cr6.eq) goto loc_827EB9C0;
	// lwz r10,3720(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 3720);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827ecdc0
	if (ctx.cr6.eq) goto loc_827ECDC0;
loc_827EB9C0:
	// li r10,1
	ctx.r10.s64 = 1;
	// rldicr r9,r11,0,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xC000000000000000;
	// rldicr r8,r10,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// cmpld cr6,r9,r8
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r8.u64, ctx.xer);
	// beq cr6,0x827ecdc0
	if (ctx.cr6.eq) goto loc_827ECDC0;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r7,16384
	ctx.r7.s64 = 16384;
	// lwz r8,1912(r18)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r18.u32 + 1912);
	// sradi r5,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r5.s64 = ctx.r11.s64 >> 32;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rldimi r7,r7,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
	// cmpld cr6,r11,r7
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r7.u64, ctx.xer);
	// stwx r11,r8,r6
	REX_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r11.u32);
	// lwz r3,1916(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 1916);
	// stwx r5,r3,r6
	REX_STORE_U32(ctx.r3.u32 + ctx.r6.u32, ctx.r5.u32);
	// bne cr6,0x827ec818
	if (!ctx.cr6.eq) goto loc_827EC818;
	// lbz r11,4(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 4);
	// clrlwi r8,r14,31
	ctx.r8.u64 = ctx.r14.u32 & 0x1;
	// lwz r7,372(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lbz r6,5(r26)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r26.u32 + 5);
	// neg r5,r8
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// lwz r9,388(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 388);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhz r3,50(r18)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r18.u32 + 50);
	// lbz r31,28(r18)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r18.u32 + 28);
	// lwz r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,1312(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1312);
	// and r15,r5,r3
	ctx.r15.u64 = ctx.r5.u64 & ctx.r3.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r6,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r17,r10,r11
	ctx.r17.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x827eba78
	if (ctx.cr6.eq) goto loc_827EBA78;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,396(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 396);
	// lwz r9,400(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 400);
	// rlwinm r11,r11,12,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// b 0x827eba88
	goto loc_827EBA88;
loc_827EBA78:
	// addi r11,r18,404
	ctx.r11.s64 = ctx.r18.s64 + 404;
	// addi r10,r18,416
	ctx.r10.s64 = ctx.r18.s64 + 416;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
loc_827EBA88:
	// lwz r9,372(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// li r16,0
	ctx.r16.s64 = 0;
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,32(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// or r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 | ctx.r8.u64;
	// stw r5,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// lwz r11,32(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// stw r4,32(r9)
	REX_STORE_U32(ctx.r9.u32 + 32, ctx.r4.u32);
	// lhz r11,50(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 50);
	// lwz r3,1304(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 1304);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// add r14,r11,r8
	ctx.r14.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r11,r3,r7
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// stw r7,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
loc_827EBADC:
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// srawi. r11,r16,2
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r16.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// li r27,119
	ctx.r27.s64 = 119;
	// clrlwi r19,r10,31
	ctx.r19.u64 = ctx.r10.u32 & 0x1;
	// bne 0x827ebb48
	if (!ctx.cr0.eq) goto loc_827EBB48;
	// addi r10,r16,18
	ctx.r10.s64 = ctx.r16.s64 + 18;
	// lwz r7,92(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r6,r11,1,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// lwz r8,432(r18)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r18.u32 + 432);
	// srawi r9,r16,1
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r16.s32 >> 1;
	// lwz r22,348(r18)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r18.u32 + 348);
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,1224(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1224);
	// or r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 | ctx.r9.u64;
	// lwz r21,104(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// add r4,r15,r7
	ctx.r4.u64 = ctx.r15.u64 + ctx.r7.u64;
	// addi r3,r10,184
	ctx.r3.s64 = ctx.r10.s64 + 184;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r5,r18
	ctx.r9.u64 = REX_LOAD_U16(ctx.r5.u32 + ctx.r18.u32);
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lhzx r6,r7,r18
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r18.u32);
	// add r29,r10,r8
	ctx.r29.u64 = ctx.r10.u64 + ctx.r8.u64;
	// extsh r20,r6
	ctx.r20.s64 = ctx.r6.s16;
	// b 0x827ebb88
	goto loc_827EBB88;
loc_827EBB48:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r9,r16,105
	ctx.r9.s64 = ctx.r16.s64 + 105;
	// lwz r22,352(r18)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r18.u32 + 352);
	// addi r6,r10,182
	ctx.r6.s64 = ctx.r10.s64 + 182;
	// lwz r11,1228(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1228);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r21,108(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// srawi r10,r15,1
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r15.s32 >> 1;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r9,r7,r18
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r18.u32);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lhzx r4,r5,r18
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + ctx.r18.u32);
	// add r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsh r20,r4
	ctx.r20.s64 = ctx.r4.s16;
loc_827EBB88:
	// lwz r9,372(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r10,28(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// lwz r25,16(r8)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// addi r23,r10,-128
	ctx.r23.s64 = ctx.r10.s64 + -128;
	// stw r23,28(r9)
	REX_STORE_U32(ctx.r9.u32 + 28, ctx.r23.u32);
	// dcbzl r0,r23
	ea = (ctx.r23.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// li r26,0
	ctx.r26.s64 = 0;
	// lbz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// subfic r7,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r7.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrldi r6,r7,32
	ctx.r6.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// srd r5,r11,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r6.u8 & 0x7F));
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r3,r28
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + ctx.r28.u32);
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ebc98
	if (ctx.cr6.lt) goto loc_827EBC98;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827ebc90
	if (!ctx.cr6.lt) goto loc_827EBC90;
loc_827EBBF8:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827ebc24
	if (ctx.cr6.lt) goto loc_827EBC24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827EBC14;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827ebbf8
	if (ctx.cr6.eq) goto loc_827EBBF8;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ebcd8
	goto loc_827EBCD8;
loc_827EBC24:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_827EBC90:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ebcd8
	goto loc_827EBCD8;
loc_827EBC98:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EBCA0;
	sub_82725F80(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r24,r11,32768
	ctx.r24.u64 = ctx.r11.u64 | 32768;
loc_827EBCA8:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EBCC0;
	sub_82725F80(ctx, base);
	// add r10,r30,r24
	ctx.r10.u64 = ctx.r30.u64 + ctx.r24.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r28
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ebca8
	if (ctx.cr6.lt) goto loc_827EBCA8;
loc_827EBCD8:
	// clrlwi r30,r30,16
	ctx.r30.u64 = ctx.r30.u32 & 0xFFFF;
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x827ebe00
	if (ctx.cr6.eq) goto loc_827EBE00;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x827ebf24
	if (ctx.cr6.eq) goto loc_827EBF24;
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// bne cr6,0x827ebd38
	if (!ctx.cr6.eq) goto loc_827EBD38;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge 0x827ebd20
	if (!ctx.cr0.lt) goto loc_827EBD20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EBD20;
	sub_82725E38(ctx, base);
loc_827EBD20:
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x827ebee8
	goto loc_827EBEE8;
loc_827EBD38:
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// bne cr6,0x827ebee8
	if (!ctx.cr6.eq) goto loc_827EBEE8;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,2
	ctx.r30.s64 = 2;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x827ebdb0
	if (!ctx.cr6.lt) goto loc_827EBDB0;
loc_827EBD58:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827ebdb0
	if (ctx.cr6.eq) goto loc_827EBDB0;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827ebda0
	if (!ctx.cr0.lt) goto loc_827EBDA0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EBDA0;
	sub_82725E38(ctx, base);
loc_827EBDA0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827ebd58
	if (ctx.cr6.gt) goto loc_827EBD58;
loc_827EBDB0:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r28
	ctx.r30.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827ebde8
	if (!ctx.cr0.lt) goto loc_827EBDE8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EBDE8;
	sub_82725E38(ctx, base);
loc_827EBDE8:
	// rlwinm r11,r24,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x827ebee8
	goto loc_827EBEE8;
loc_827EBE00:
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// bgt cr6,0x827ebe14
	if (ctx.cr6.gt) goto loc_827EBE14;
	// srawi r11,r25,1
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 1;
	// subfic r11,r11,3
	ctx.xer.ca = ctx.r11.u32 <= 3;
	ctx.r11.u64 = static_cast<uint64_t>(3) - ctx.r11.u64;
	// b 0x827ebe18
	goto loc_827EBE18;
loc_827EBE14:
	// li r11,0
	ctx.r11.s64 = 0;
loc_827EBE18:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// ble cr6,0x827ebe38
	if (!ctx.cr6.gt) goto loc_827EBE38;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827ebee4
	goto loc_827EBEE4;
loc_827EBE38:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x827ebe48
	if (!ctx.cr6.eq) goto loc_827EBE48;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x827ebee4
	goto loc_827EBEE4;
loc_827EBE48:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827ebea8
	if (!ctx.cr6.gt) goto loc_827EBEA8;
loc_827EBE50:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827ebea8
	if (ctx.cr6.eq) goto loc_827EBEA8;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x827ebe98
	if (!ctx.cr0.lt) goto loc_827EBE98;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EBE98;
	sub_82725E38(ctx, base);
loc_827EBE98:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827ebe50
	if (ctx.cr6.gt) goto loc_827EBE50;
loc_827EBEA8:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r9,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r28
	ctx.r30.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x827ebee0
	if (!ctx.cr0.lt) goto loc_827EBEE0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EBEE0;
	sub_82725E38(ctx, base);
loc_827EBEE0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_827EBEE4:
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
loc_827EBEE8:
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// rldicl r28,r10,1,63
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge 0x827ebf10
	if (!ctx.cr0.lt) goto loc_827EBF10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725e38
	ctx.lr = 0x827EBF10;
	sub_82725E38(ctx, base);
loc_827EBF10:
	// rlwinm r11,r28,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r30
	ctx.r10.s64 = ctx.r30.s16;
	// subfic r9,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r9.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// extsh r26,r8
	ctx.r26.s64 = ctx.r8.s16;
loc_827EBF24:
	// sth r26,0(r23)
	REX_STORE_U16(ctx.r23.u32 + 0, ctx.r26.u16);
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x827ecdc0
	if (!ctx.cr6.eq) goto loc_827ECDC0;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x827ebf5c
	if (ctx.cr6.eq) goto loc_827EBF5C;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// lwz r4,0(r21)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r6,444(r18)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r18.u32 + 444);
	// bl 0x827abe30
	ctx.lr = 0x827EBF54;
	sub_827ABE30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x827ecdc0
	if (ctx.cr6.lt) goto loc_827ECDC0;
loc_827EBF5C:
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r14,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,50(r18)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r18.u32 + 50);
	// rlwinm r7,r16,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 0) & 0x2;
	// add r9,r10,r22
	ctx.r9.u64 = ctx.r10.u64 + ctx.r22.u64;
	// rlwinm r30,r8,31,1,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// srawi r8,r16,2
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r16.s32 >> 2;
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r25,1
	ctx.r25.s64 = 1;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// li r28,0
	ctx.r28.s64 = 0;
	// rlwinm r5,r6,0,27,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x18;
	// li r27,0
	ctx.r27.s64 = 0;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r26,r4,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x827ebfc4
	if (!ctx.cr6.eq) goto loc_827EBFC4;
	// lwz r7,132(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x827ebfd4
	if (ctx.cr6.eq) goto loc_827EBFD4;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r7.u64;
	// lwz r5,0(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r5,16384
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16384, ctx.xer);
	// bne cr6,0x827ebfd4
	if (!ctx.cr6.eq) goto loc_827EBFD4;
loc_827EBFC4:
	// rlwinm r10,r20,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 5) & 0xFFFFFFE0;
	// li r25,8
	ctx.r25.s64 = 8;
	// subf r28,r10,r29
	ctx.r28.u64 = ctx.r29.u64 - ctx.r10.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_827EBFD4:
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// and r5,r6,r16
	ctx.r5.u64 = ctx.r6.u64 & ctx.r16.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x827ec000
	if (!ctx.cr6.eq) goto loc_827EC000;
	// lwz r7,92(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x827ec25c
	if (ctx.cr6.eq) goto loc_827EC25C;
	// lwz r7,-4(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + -4);
	// cmpwi cr6,r7,16384
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 16384, ctx.xer);
	// bne cr6,0x827ec25c
	if (!ctx.cr6.eq) goto loc_827EC25C;
loc_827EC000:
	// addic. r27,r29,-32
	ctx.xer.ca = ctx.r29.u32 > 31;
	ctx.r27.s64 = ctx.r29.s64 + -32;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// li r25,1
	ctx.r25.s64 = 1;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// beq 0x827ec588
	if (ctx.cr0.eq) goto loc_827EC588;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x827ec25c
	if (ctx.cr6.eq) goto loc_827EC25C;
	// clrlwi r7,r16,30
	ctx.r7.u64 = ctx.r16.u32 & 0x3;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x827ec030
	if (ctx.cr6.eq) goto loc_827EC030;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x827ec048
	if (ctx.cr6.eq) goto loc_827EC048;
loc_827EC030:
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r7.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmpwi cr6,r4,16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 16384, ctx.xer);
	// bne cr6,0x827ec050
	if (!ctx.cr6.eq) goto loc_827EC050;
loc_827EC048:
	// lhz r9,-16(r28)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r28.u32 + -16);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
loc_827EC050:
	// lhz r9,16(r28)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r28.u32 + 16);
	// lhz r8,0(r27)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// lbz r7,27(r18)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r18.u32 + 27);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x827ec220
	if (ctx.cr6.eq) goto loc_827EC220;
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x827ec168
	if (ctx.cr6.eq) goto loc_827EC168;
	// cmpwi cr6,r16,4
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 4, ctx.xer);
	// beq cr6,0x827ec168
	if (ctx.cr6.eq) goto loc_827EC168;
	// cmpwi cr6,r16,5
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 5, ctx.xer);
	// beq cr6,0x827ec168
	if (ctx.cr6.eq) goto loc_827EC168;
	// cmpwi cr6,r16,1
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 1, ctx.xer);
	// lis r31,2
	ctx.r31.s64 = 131072;
	// bne cr6,0x827ec0fc
	if (!ctx.cr6.eq) goto loc_827EC0FC;
	// rlwinm r7,r30,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,388(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 388);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// subf r7,r7,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r7.u64;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r24,r8,r9
	ctx.r24.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r8,r7,26
	ctx.r8.u64 = ctx.r7.u32 & 0x3F;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r24,16(r24)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r24.u32 + 16);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r7,r24,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwzx r8,r7,r3
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// lwz r7,16(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// mullw r9,r8,r7
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// mullw r7,r7,r5
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// mullw r6,r9,r6
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// mullw r5,r8,r7
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// add r9,r6,r31
	ctx.r9.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r8,r5,r31
	ctx.r8.u64 = ctx.r5.u64 + ctx.r31.u64;
	// srawi r6,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 18;
	// srawi r5,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 18;
	// b 0x827ec228
	goto loc_827EC228;
loc_827EC0FC:
	// cmpwi cr6,r16,2
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 2, ctx.xer);
	// bne cr6,0x827ec224
	if (!ctx.cr6.eq) goto loc_827EC224;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,-8(r17)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r17.u32 + -8);
	// lwz r9,388(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 388);
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r8,r7,26
	ctx.r8.u64 = ctx.r7.u32 & 0x3F;
	// rlwinm r7,r3,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,16(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,16(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwzx r9,r8,r3
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// mullw r8,r7,r4
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r4.s32);
	// mullw r7,r9,r7
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// mullw r6,r7,r6
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// mullw r4,r9,r8
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r9,r6,r31
	ctx.r9.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r8,r4,r31
	ctx.r8.u64 = ctx.r4.u64 + ctx.r31.u64;
	// srawi r6,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 18;
	// srawi r4,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 18;
	// b 0x827ec228
	goto loc_827EC228;
loc_827EC168:
	// rlwinm r7,r30,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r3,-8(r17)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r17.u32 + -8);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,388(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 388);
	// subf r31,r7,r17
	ctx.r31.u64 = ctx.r17.u64 - ctx.r7.u64;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r24,-8(r31)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r31.u32 + -8);
	// add r23,r7,r9
	ctx.r23.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r22,r8,r3
	ctx.r22.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lbz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r8,r24,26
	ctx.r8.u64 = ctx.r24.u32 & 0x3F;
	// clrlwi r7,r7,26
	ctx.r7.u64 = ctx.r7.u32 & 0x3F;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r7,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r24,16(r23)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r23.u32 + 16);
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// rlwinm r3,r22,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + ctx.r31.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r23,r3,r9
	ctx.r23.u64 = ctx.r3.u64 + ctx.r9.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r24,r24,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,16(r23)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r23.u32 + 16);
	// lis r31,2
	ctx.r31.s64 = 131072;
	// lwz r8,16(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// mullw r4,r9,r4
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// lwzx r24,r24,r3
	ctx.r24.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r3.u32);
	// lwz r9,16(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// mullw r8,r24,r8
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r8.s32);
	// mullw r7,r24,r9
	ctx.r7.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r9.s32);
	// mullw r6,r8,r6
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// mullw r5,r7,r5
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// mullw r4,r24,r4
	ctx.r4.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r4.s32);
	// add r9,r6,r31
	ctx.r9.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r8,r5,r31
	ctx.r8.u64 = ctx.r5.u64 + ctx.r31.u64;
	// add r7,r4,r31
	ctx.r7.u64 = ctx.r4.u64 + ctx.r31.u64;
	// srawi r6,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 18;
	// srawi r5,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 18;
	// srawi r4,r7,18
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 18;
	// b 0x827ec228
	goto loc_827EC228;
loc_827EC220:
	// lis r31,2
	ctx.r31.s64 = 131072;
loc_827EC224:
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
loc_827EC228:
	// subf r9,r5,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r5.u64;
	// subf r8,r4,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r4.u64;
	// srawi r7,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 31;
	// srawi r6,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 31;
	// xor r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r7.u64;
	// xor r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// subf r9,r7,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r7.u64;
	// subf r8,r6,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r6.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x827ec264
	if (!ctx.cr6.lt) goto loc_827EC264;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// li r25,8
	ctx.r25.s64 = 8;
	// b 0x827ec264
	goto loc_827EC264;
loc_827EC25C:
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lis r31,2
	ctx.r31.s64 = 131072;
loc_827EC264:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827ec588
	if (ctx.cr6.eq) goto loc_827EC588;
	// lbz r9,27(r18)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r18.u32 + 27);
	// neg r8,r26
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r26.u64);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// or r25,r8,r25
	ctx.r25.u64 = ctx.r8.u64 | ctx.r25.u64;
	// beq cr6,0x827ec57c
	if (ctx.cr6.eq) goto loc_827EC57C;
	// cmplw cr6,r10,r27
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x827ec3fc
	if (!ctx.cr6.eq) goto loc_827EC3FC;
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x827ec2d0
	if (ctx.cr6.eq) goto loc_827EC2D0;
	// cmpwi cr6,r16,2
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 2, ctx.xer);
	// beq cr6,0x827ec2d0
	if (ctx.cr6.eq) goto loc_827EC2D0;
	// cmpwi cr6,r16,4
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 4, ctx.xer);
	// beq cr6,0x827ec2d0
	if (ctx.cr6.eq) goto loc_827EC2D0;
	// cmpwi cr6,r16,5
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 5, ctx.xer);
	// beq cr6,0x827ec2d0
	if (ctx.cr6.eq) goto loc_827EC2D0;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r11,r10,-2
	ctx.r11.s64 = ctx.r10.s64 + -2;
	// addi r10,r8,-2
	ctx.r10.s64 = ctx.r8.s64 + -2;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827EC2BC:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x827ec2bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827EC2BC;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// b 0x827ec588
	goto loc_827EC588;
loc_827EC2D0:
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,-8(r17)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r17.u32 + -8);
	// lwz r8,388(r18)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r18.u32 + 388);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r7
	ctx.r4.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lhz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r4,r9,r7
	ctx.r4.u64 = ctx.r9.u64 + ctx.r7.u64;
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r6,16(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 16);
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwzx r8,r5,r3
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,146
	ctx.r5.s64 = ctx.r1.s64 + 146;
	// addi r7,r1,138
	ctx.r7.s64 = ctx.r1.s64 + 138;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,16(r4)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// addi r27,r1,148
	ctx.r27.s64 = ctx.r1.s64 + 148;
	// addi r11,r10,6
	ctx.r11.s64 = ctx.r10.s64 + 6;
	// lwzx r3,r6,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// mullw r6,r4,r30
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// mullw r4,r3,r6
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + ctx.r31.u64;
	// subf r6,r10,r28
	ctx.r6.u64 = ctx.r28.u64 - ctx.r10.u64;
	// srawi r4,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 18;
	// subf r5,r10,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r10.u64;
	// sth r4,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r4.u16);
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
loc_827EC358:
	// lhz r4,-4(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// lhz r3,-2(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// lhz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lhz r28,2(r11)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lhz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// mullw r4,r4,r8
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// mullw r3,r3,r8
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r30,r30,r8
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r8.s32);
	// mullw r28,r28,r8
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r8.s32);
	// mullw r4,r4,r9
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r27,r9
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r9.s32);
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// mullw r30,r30,r9
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r9.s32);
	// mullw r28,r28,r9
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// add r4,r4,r31
	ctx.r4.u64 = ctx.r4.u64 + ctx.r31.u64;
	// mullw r27,r8,r27
	ctx.r27.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// srawi r4,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 18;
	// add r28,r28,r31
	ctx.r28.u64 = ctx.r28.u64 + ctx.r31.u64;
	// srawi r3,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 18;
	// sth r4,8(r7)
	REX_STORE_U16(ctx.r7.u32 + 8, ctx.r4.u16);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// srawi r30,r30,18
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3FFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 18;
	// sthu r3,10(r7)
	ea = 10 + ctx.r7.u32;
	REX_STORE_U16(ea, ctx.r3.u16);
	ctx.r7.u32 = ea;
	// srawi r28,r28,18
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3FFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 18;
	// srawi r27,r27,18
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3FFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 18;
	// sthx r30,r6,r11
	REX_STORE_U16(ctx.r6.u32 + ctx.r11.u32, ctx.r30.u16);
	// sthx r28,r5,r11
	REX_STORE_U16(ctx.r5.u32 + ctx.r11.u32, ctx.r28.u16);
	// sthx r27,r10,r11
	REX_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r27.u16);
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bdnz 0x827ec358
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827EC358;
	// lhz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 144);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// sth r11,160(r1)
	REX_STORE_U16(ctx.r1.u32 + 160, ctx.r11.u16);
	// b 0x827ec588
	goto loc_827EC588;
loc_827EC3FC:
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x827ec444
	if (ctx.cr6.eq) goto loc_827EC444;
	// cmpwi cr6,r16,1
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 1, ctx.xer);
	// beq cr6,0x827ec444
	if (ctx.cr6.eq) goto loc_827EC444;
	// cmpwi cr6,r16,4
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 4, ctx.xer);
	// beq cr6,0x827ec444
	if (ctx.cr6.eq) goto loc_827EC444;
	// cmpwi cr6,r16,5
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 5, ctx.xer);
	// beq cr6,0x827ec444
	if (ctx.cr6.eq) goto loc_827EC444;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r11,r10,-2
	ctx.r11.s64 = ctx.r10.s64 + -2;
	// addi r10,r8,-2
	ctx.r10.s64 = ctx.r8.s64 + -2;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827EC430:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x827ec430
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827EC430;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// b 0x827ec588
	goto loc_827EC588;
loc_827EC444:
	// rlwinm r8,r30,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,388(r18)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r18.u32 + 388);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// subf r5,r8,r17
	ctx.r5.u64 = ctx.r17.u64 - ctx.r8.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + 0);
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// li r11,3
	ctx.r11.s64 = 3;
	// clrlwi r9,r8,26
	ctx.r9.u64 = ctx.r8.u32 & 0x3F;
	// addi r6,r1,148
	ctx.r6.s64 = ctx.r1.s64 + 148;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,16(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// add r27,r9,r8
	ctx.r27.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r4,r3
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// rlwinm r5,r27,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,146
	ctx.r4.s64 = ctx.r1.s64 + 146;
	// add r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 + ctx.r7.u64;
	// addi r7,r6,-10
	ctx.r7.s64 = ctx.r6.s64 + -10;
	// subf r6,r10,r28
	ctx.r6.u64 = ctx.r28.u64 - ctx.r10.u64;
	// lwzx r3,r11,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// addi r27,r1,148
	ctx.r27.s64 = ctx.r1.s64 + 148;
	// addi r11,r10,6
	ctx.r11.s64 = ctx.r10.s64 + 6;
	// lwz r28,16(r5)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// subf r5,r10,r4
	ctx.r5.u64 = ctx.r4.u64 - ctx.r10.u64;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// mullw r4,r28,r30
	ctx.r4.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// mullw r3,r3,r4
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r4,r3,r31
	ctx.r4.u64 = ctx.r3.u64 + ctx.r31.u64;
	// srawi r3,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 18;
	// sth r3,144(r1)
	REX_STORE_U16(ctx.r1.u32 + 144, ctx.r3.u16);
loc_827EC4D8:
	// lhz r4,-4(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// lhz r3,-2(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// lhz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lhz r28,2(r11)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lhz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// mullw r4,r4,r8
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// mullw r3,r3,r8
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r30,r30,r8
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r8.s32);
	// mullw r28,r28,r8
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r8.s32);
	// mullw r4,r4,r9
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r27,r9
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r9.s32);
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// mullw r30,r30,r9
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r9.s32);
	// mullw r28,r28,r9
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// add r4,r4,r31
	ctx.r4.u64 = ctx.r4.u64 + ctx.r31.u64;
	// mullw r27,r8,r27
	ctx.r27.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// srawi r4,r4,18
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 18;
	// add r28,r28,r31
	ctx.r28.u64 = ctx.r28.u64 + ctx.r31.u64;
	// srawi r3,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 18;
	// sth r4,8(r7)
	REX_STORE_U16(ctx.r7.u32 + 8, ctx.r4.u16);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// srawi r30,r30,18
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3FFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 18;
	// sthu r3,10(r7)
	ea = 10 + ctx.r7.u32;
	REX_STORE_U16(ea, ctx.r3.u16);
	ctx.r7.u32 = ea;
	// srawi r28,r28,18
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3FFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 18;
	// srawi r27,r27,18
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3FFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 18;
	// sthx r30,r11,r6
	REX_STORE_U16(ctx.r11.u32 + ctx.r6.u32, ctx.r30.u16);
	// sthx r28,r11,r5
	REX_STORE_U16(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u16);
	// sthx r27,r11,r10
	REX_STORE_U16(ctx.r11.u32 + ctx.r10.u32, ctx.r27.u16);
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bdnz 0x827ec4d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827EC4D8;
	// lhz r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 144);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// sth r11,160(r1)
	REX_STORE_U16(ctx.r1.u32 + 160, ctx.r11.u16);
	// b 0x827ec588
	goto loc_827EC588;
loc_827EC57C:
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x827ec588
	if (!ctx.cr6.eq) goto loc_827EC588;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_827EC588:
	// lwz r11,372(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// beq cr6,0x827ec76c
	if (ctx.cr6.eq) goto loc_827EC76C;
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r6.u16);
	// sth r6,0(r29)
	REX_STORE_U16(ctx.r29.u32 + 0, ctx.r6.u16);
	// sth r6,16(r29)
	REX_STORE_U16(ctx.r29.u32 + 16, ctx.r6.u16);
	// bne cr6,0x827ec6a0
	if (!ctx.cr6.eq) goto loc_827EC6A0;
	// lhz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r6.u16);
	// sth r6,2(r29)
	REX_STORE_U16(ctx.r29.u32 + 2, ctx.r6.u16);
	// lhz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// sth r9,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r9.u16);
	// sth r9,4(r29)
	REX_STORE_U16(ctx.r29.u32 + 4, ctx.r9.u16);
	// lhz r9,6(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,6(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r5.u16);
	// sth r5,6(r29)
	REX_STORE_U16(ctx.r29.u32 + 6, ctx.r5.u16);
	// lhz r3,8(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// add r9,r3,r8
	ctx.r9.u64 = ctx.r3.u64 + ctx.r8.u64;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,8(r11)
	REX_STORE_U16(ctx.r11.u32 + 8, ctx.r8.u16);
	// sth r8,8(r29)
	REX_STORE_U16(ctx.r29.u32 + 8, ctx.r8.u16);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lhz r8,10(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,10(r11)
	REX_STORE_U16(ctx.r11.u32 + 10, ctx.r4.u16);
	// sth r4,10(r29)
	REX_STORE_U16(ctx.r29.u32 + 10, ctx.r4.u16);
	// lhz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// lhz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// sth r7,12(r11)
	REX_STORE_U16(ctx.r11.u32 + 12, ctx.r7.u16);
	// sth r7,12(r29)
	REX_STORE_U16(ctx.r29.u32 + 12, ctx.r7.u16);
	// lhz r9,14(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 14);
	// lhz r10,14(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,14(r11)
	REX_STORE_U16(ctx.r11.u32 + 14, ctx.r3.u16);
	// sth r3,14(r29)
	REX_STORE_U16(ctx.r29.u32 + 14, ctx.r3.u16);
	// lhz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 16);
	// sth r10,18(r29)
	REX_STORE_U16(ctx.r29.u32 + 18, ctx.r10.u16);
	// lhz r9,32(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 32);
	// sth r9,20(r29)
	REX_STORE_U16(ctx.r29.u32 + 20, ctx.r9.u16);
	// lhz r8,48(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 48);
	// sth r8,22(r29)
	REX_STORE_U16(ctx.r29.u32 + 22, ctx.r8.u16);
	// lhz r7,64(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 64);
	// sth r7,24(r29)
	REX_STORE_U16(ctx.r29.u32 + 24, ctx.r7.u16);
	// lhz r6,80(r11)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + 80);
	// sth r6,26(r29)
	REX_STORE_U16(ctx.r29.u32 + 26, ctx.r6.u16);
	// lhz r5,96(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 96);
	// sth r5,28(r29)
	REX_STORE_U16(ctx.r29.u32 + 28, ctx.r5.u16);
	// lhz r4,112(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 112);
	// sth r4,30(r29)
	REX_STORE_U16(ctx.r29.u32 + 30, ctx.r4.u16);
	// b 0x827ec7c8
	goto loc_827EC7C8;
loc_827EC6A0:
	// cmpwi cr6,r25,8
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 8, ctx.xer);
	// bne cr6,0x827ec778
	if (!ctx.cr6.eq) goto loc_827EC778;
	// lhz r9,2(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// sth r9,2(r29)
	REX_STORE_U16(ctx.r29.u32 + 2, ctx.r9.u16);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r8.u32);
	// ld r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// std r7,8(r29)
	REX_STORE_U64(ctx.r29.u32 + 8, ctx.r7.u64);
	// lhz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 16);
	// lhz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,16(r11)
	REX_STORE_U16(ctx.r11.u32 + 16, ctx.r3.u16);
	// sth r3,18(r29)
	REX_STORE_U16(ctx.r29.u32 + 18, ctx.r3.u16);
	// lhz r8,32(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 32);
	// lhz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,32(r11)
	REX_STORE_U16(ctx.r11.u32 + 32, ctx.r5.u16);
	// sth r5,20(r29)
	REX_STORE_U16(ctx.r29.u32 + 20, ctx.r5.u16);
	// lhz r3,6(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,48(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 48);
	// add r9,r3,r8
	ctx.r9.u64 = ctx.r3.u64 + ctx.r8.u64;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,48(r11)
	REX_STORE_U16(ctx.r11.u32 + 48, ctx.r8.u16);
	// sth r8,22(r29)
	REX_STORE_U16(ctx.r29.u32 + 22, ctx.r8.u16);
	// lhz r8,64(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 64);
	// lhz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,64(r11)
	REX_STORE_U16(ctx.r11.u32 + 64, ctx.r4.u16);
	// sth r4,24(r29)
	REX_STORE_U16(ctx.r29.u32 + 24, ctx.r4.u16);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// lhz r8,80(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 80);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,80(r11)
	REX_STORE_U16(ctx.r11.u32 + 80, ctx.r6.u16);
	// sth r6,26(r29)
	REX_STORE_U16(ctx.r29.u32 + 26, ctx.r6.u16);
	// lhz r8,96(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 96);
	// lhz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// sth r9,96(r11)
	REX_STORE_U16(ctx.r11.u32 + 96, ctx.r9.u16);
	// sth r9,28(r29)
	REX_STORE_U16(ctx.r29.u32 + 28, ctx.r9.u16);
	// lhz r10,14(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// lhz r9,112(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 112);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,112(r11)
	REX_STORE_U16(ctx.r11.u32 + 112, ctx.r5.u16);
	// sth r5,30(r29)
	REX_STORE_U16(ctx.r29.u32 + 30, ctx.r5.u16);
	// b 0x827ec7c8
	goto loc_827EC7C8;
loc_827EC76C:
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// sth r10,0(r29)
	REX_STORE_U16(ctx.r29.u32 + 0, ctx.r10.u16);
	// sth r10,16(r29)
	REX_STORE_U16(ctx.r29.u32 + 16, ctx.r10.u16);
loc_827EC778:
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// sth r10,2(r29)
	REX_STORE_U16(ctx.r29.u32 + 2, ctx.r10.u16);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// ld r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// std r8,8(r29)
	REX_STORE_U64(ctx.r29.u32 + 8, ctx.r8.u64);
	// lhz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 16);
	// sth r7,18(r29)
	REX_STORE_U16(ctx.r29.u32 + 18, ctx.r7.u16);
	// lhz r6,32(r11)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + 32);
	// sth r6,20(r29)
	REX_STORE_U16(ctx.r29.u32 + 20, ctx.r6.u16);
	// lhz r5,48(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 48);
	// sth r5,22(r29)
	REX_STORE_U16(ctx.r29.u32 + 22, ctx.r5.u16);
	// lhz r4,64(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 64);
	// sth r4,24(r29)
	REX_STORE_U16(ctx.r29.u32 + 24, ctx.r4.u16);
	// lhz r3,80(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 80);
	// sth r3,26(r29)
	REX_STORE_U16(ctx.r29.u32 + 26, ctx.r3.u16);
	// lhz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 96);
	// sth r10,28(r29)
	REX_STORE_U16(ctx.r29.u32 + 28, ctx.r10.u16);
	// lhz r9,112(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 112);
	// sth r9,30(r29)
	REX_STORE_U16(ctx.r29.u32 + 30, ctx.r9.u16);
loc_827EC7C8:
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r16,6
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 6, ctx.xer);
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// blt cr6,0x827ebadc
	if (ctx.cr6.lt) goto loc_827EBADC;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r7,372(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r5,5(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// clrlwi r8,r11,1
	ctx.r8.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// lbz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// rldimi r5,r6,8,48
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u64, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// rldicr r4,r5,48,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u64, 48) & 0xFFFF000000000000;
	// lwz r3,4(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r11,1312(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 1312);
	// rlwinm r9,r3,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// stdx r4,r9,r11
	REX_STORE_U64(ctx.r9.u32 + ctx.r11.u32, ctx.r4.u64);
	// b 0x827ecce0
	goto loc_827ECCE0;
loc_827EC818:
	// lbz r10,29(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 29);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lbz r25,34(r18)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r18.u32 + 34);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// lbz r20,5(r26)
	ctx.r20.u64 = REX_LOAD_U8(ctx.r26.u32 + 5);
	// rlwinm r23,r11,12,30,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x3;
	// rlwinm r19,r11,4,31,31
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827ec844
	if (ctx.cr6.eq) goto loc_827EC844;
	// rlwinm r25,r11,8,29,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0x7;
loc_827EC844:
	// lbz r10,28(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827ec860
	if (ctx.cr6.eq) goto loc_827EC860;
	// lwz r10,396(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 396);
	// rlwinm r11,r11,12,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xC;
	// add r22,r11,r10
	ctx.r22.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x827ec864
	goto loc_827EC864;
loc_827EC860:
	// addi r22,r18,404
	ctx.r22.s64 = ctx.r18.s64 + 404;
loc_827EC864:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r17,372(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// li r21,0
	ctx.r21.s64 = 0;
	// ori r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 32768;
loc_827EC874:
	// clrlwi r11,r20,31
	ctx.r11.u64 = ctx.r20.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827ecc70
	if (ctx.cr6.eq) goto loc_827ECC70;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// and r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 & ctx.r19.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x827ec9d4
	if (ctx.cr6.eq) goto loc_827EC9D4;
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,608(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 608);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,6,58
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 6) & 0x3F;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ec978
	if (ctx.cr6.lt) goto loc_827EC978;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827ec970
	if (!ctx.cr6.lt) goto loc_827EC970;
loc_827EC8D8:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827ec904
	if (ctx.cr6.lt) goto loc_827EC904;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827EC8F4;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827ec8d8
	if (ctx.cr6.eq) goto loc_827EC8D8;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ec9b4
	goto loc_827EC9B4;
loc_827EC904:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r5,r10,8,55
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r6,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
loc_827EC970:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ec9b4
	goto loc_827EC9B4;
loc_827EC978:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EC984;
	sub_82725F80(ctx, base);
loc_827EC984:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827EC99C;
	sub_82725F80(ctx, base);
	// add r10,r30,r27
	ctx.r10.u64 = ctx.r30.u64 + ctx.r27.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ec984
	if (ctx.cr6.lt) goto loc_827EC984;
loc_827EC9B4:
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x827ecdc0
	if (!ctx.cr6.eq) goto loc_827ECDC0;
	// add r11,r30,r18
	ctx.r11.u64 = ctx.r30.u64 + ctx.r18.u64;
	// add r10,r30,r18
	ctx.r10.u64 = ctx.r30.u64 + ctx.r18.u64;
	// lbz r25,684(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 684);
	// lbz r23,692(r10)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r10.u32 + 692);
loc_827EC9D4:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x827eca1c
	if (!ctx.cr6.eq) goto loc_827ECA1C;
	// lwz r31,20(r17)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r17.u32 + 20);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r4,0(r22)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lbz r5,160(r18)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r18.u32 + 160);
	// bl 0x827aba90
	ctx.lr = 0x827EC9F4;
	sub_827ABA90(ctx, base);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// lwz r10,24(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 24);
	// ori r24,r24,1
	ctx.r24.u64 = ctx.r24.u64 | 1;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r8,20(r17)
	REX_STORE_U32(ctx.r17.u32 + 20, ctx.r8.u32);
	// stb r3,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// lwz r11,24(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 24);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,24(r17)
	REX_STORE_U32(ctx.r17.u32 + 24, ctx.r7.u32);
	// b 0x827ecc6c
	goto loc_827ECC6C;
loc_827ECA1C:
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// bgt cr6,0x827ecaa0
	if (ctx.cr6.gt) goto loc_827ECAA0;
	// or r11,r19,r28
	ctx.r11.u64 = ctx.r19.u64 | ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827eca38
	if (ctx.cr6.eq) goto loc_827ECA38;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// b 0x827ecbd8
	goto loc_827ECBD8;
loc_827ECA38:
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eca60
	if (!ctx.cr0.lt) goto loc_827ECA60;
	// bl 0x82725e38
	ctx.lr = 0x827ECA60;
	sub_82725E38(ctx, base);
loc_827ECA60:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x827eca98
	if (!ctx.cr6.eq) goto loc_827ECA98;
	// lwz r3,0(r18)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x827eca90
	if (!ctx.cr0.lt) goto loc_827ECA90;
	// bl 0x82725e38
	ctx.lr = 0x827ECA90;
	sub_82725E38(ctx, base);
loc_827ECA90:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// b 0x827ecbd8
	goto loc_827ECBD8;
loc_827ECA98:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x827ecbd8
	goto loc_827ECBD8;
loc_827ECAA0:
	// lwz r31,0(r18)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,612(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 612);
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,6,58
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 6) & 0x3F;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ecb88
	if (ctx.cr6.lt) goto loc_827ECB88;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x827ecb80
	if (!ctx.cr6.lt) goto loc_827ECB80;
loc_827ECAE8:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827ecb14
	if (ctx.cr6.lt) goto loc_827ECB14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725d78
	ctx.lr = 0x827ECB04;
	sub_82725D78(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x827ecae8
	if (ctx.cr6.eq) goto loc_827ECAE8;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ecbc4
	goto loc_827ECBC4;
loc_827ECB14:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r5,r10,8,55
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r6,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
loc_827ECB80:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x827ecbc4
	goto loc_827ECBC4;
loc_827ECB88:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82725f80
	ctx.lr = 0x827ECB94;
	sub_82725F80(ctx, base);
loc_827ECB94:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82725f80
	ctx.lr = 0x827ECBAC;
	sub_82725F80(ctx, base);
	// add r10,r30,r27
	ctx.r10.u64 = ctx.r30.u64 + ctx.r27.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x827ecb94
	if (ctx.cr6.lt) goto loc_827ECB94;
loc_827ECBC4:
	// lwz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x827ecdc0
	if (!ctx.cr6.eq) goto loc_827ECDC0;
loc_827ECBD8:
	// rlwinm r10,r25,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r17,372(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// add r9,r11,r18
	ctx.r9.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lwz r27,0(r22)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// add r6,r25,r18
	ctx.r6.u64 = ctx.r25.u64 + ctx.r18.u64;
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// lwz r28,24(r17)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r17.u32 + 24);
	// lbz r29,320(r9)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r9.u32 + 320);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r30,20(r17)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r17.u32 + 20);
	// or r24,r5,r24
	ctx.r24.u64 = ctx.r5.u64 | ctx.r24.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lbz r26,160(r6)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r6.u32 + 160);
	// ble cr6,0x827ecc44
	if (!ctx.cr6.gt) goto loc_827ECC44;
loc_827ECC18:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x827aba90
	ctx.lr = 0x827ECC2C;
	sub_827ABA90(ctx, base);
	// stbx r3,r31,r28
	REX_STORE_U8(ctx.r31.u32 + ctx.r28.u32, ctx.r3.u8);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x827ecc18
	if (ctx.cr6.lt) goto loc_827ECC18;
loc_827ECC44:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x827ecdc0
	if (ctx.cr6.eq) goto loc_827ECDC0;
	// lwz r11,24(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 24);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r30,20(r17)
	REX_STORE_U32(ctx.r17.u32 + 20, ctx.r30.u32);
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r26,84(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// ori r27,r10,32768
	ctx.r27.u64 = ctx.r10.u64 | 32768;
	// stw r9,24(r17)
	REX_STORE_U32(ctx.r17.u32 + 24, ctx.r9.u32);
	// lwz r17,372(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
loc_827ECC6C:
	// li r28,0
	ctx.r28.s64 = 0;
loc_827ECC70:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// rlwinm r20,r20,31,25,31
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 31) & 0x7F;
	// rldicr r24,r24,8,55
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r21,6
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 6, ctx.xer);
	// blt cr6,0x827ec874
	if (ctx.cr6.lt) goto loc_827EC874;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// rldicl r9,r24,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u64, 56) & 0xFFFFFFFFFFFFFF;
	// lbz r8,4(r26)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r26.u32 + 4);
	// rlwinm r7,r11,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// lbz r6,5(r26)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r26.u32 + 5);
	// rlwinm r5,r11,1,23,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1C0;
	// lwz r4,4(r17)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r17.u32 + 4);
	// or r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 | ctx.r8.u64;
	// lwz r8,1312(r18)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r18.u32 + 1312);
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r7,372(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// rlwinm r6,r5,8,16,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF00;
	// rldicr r5,r11,0,32
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFF80000000;
	// or r3,r6,r3
	ctx.r3.u64 = ctx.r6.u64 | ctx.r3.u64;
	// rlwinm r6,r4,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// rldimi r5,r3,32,0
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r5.u64 & 0xFFFFFFFF);
	// rlwinm r4,r11,27,29,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7;
	// rldicr r3,r5,16,47
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u64, 16) & 0xFFFFFFFFFFFF0000;
	// or r11,r3,r9
	ctx.r11.u64 = ctx.r3.u64 | ctx.r9.u64;
	// stdx r11,r6,r8
	REX_STORE_U64(ctx.r6.u32 + ctx.r8.u32, ctx.r11.u64);
loc_827ECCE0:
	// addi r5,r10,24
	ctx.r5.s64 = ctx.r10.s64 + 24;
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// li r17,1
	ctx.r17.s64 = 1;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// lwz r9,4(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// addi r6,r3,1
	ctx.r6.s64 = ctx.r3.s64 + 1;
	// lwz r31,100(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lhz r8,18(r7)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + 18);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// lwz r10,8(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// addi r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 1;
	// lwz r11,12(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// lwz r31,112(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lwz r16,116(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r14,96(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmpw cr6,r6,r31
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r31.s32, ctx.xer);
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r4,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// stw r3,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r3.u32);
	// stw r10,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r11,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r11.u32);
	// sth r8,18(r7)
	REX_STORE_U16(ctx.r7.u32 + 18, ctx.r8.u16);
	// lwz r15,356(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 356);
	// blt cr6,0x827ea600
	if (ctx.cr6.lt) goto loc_827EA600;
	// lwz r27,124(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r28,120(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r26,136(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
loc_827ECD64:
	// lwz r9,372(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// stw r14,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r14.u32);
	// cmpw cr6,r14,r26
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r26.s32, ctx.xer);
	// lhz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 16);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// sth r11,16(r9)
	REX_STORE_U16(ctx.r9.u32 + 16, ctx.r11.u16);
	// lhz r11,50(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 50);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// lhz r5,76(r18)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r18.u32 + 76);
	// lhz r6,74(r18)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r18.u32 + 74);
	// rotlwi r10,r6,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 4);
	// rotlwi r11,r5,3
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 3);
	// add r28,r10,r28
	ctx.r28.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r27,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r27.u32);
	// bge cr6,0x827ecdcc
	if (!ctx.cr6.lt) goto loc_827ECDCC;
	// rotlwi r31,r9,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x827ea3d8
	goto loc_827EA3D8;
loc_827ECDC0:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x826a1cd0
	__restgprlr_14(ctx, base);
	return;
loc_827ECDCC:
	// lwz r11,372(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 372);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,22504(r15)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r15.u32 + 22504);
	// li r8,-1
	ctx.r8.s64 = -1;
	// ori r7,r10,39772
	ctx.r7.u64 = ctx.r10.u64 | 39772;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,32(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// subf r5,r9,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r9.u64;
	// rlwinm r4,r5,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// stwx r4,r15,r7
	REX_STORE_U32(ctx.r15.u32 + ctx.r7.u32, ctx.r4.u32);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// ld r9,104(r18)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r18.u32 + 104);
	// std r9,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,112(r18)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r18.u32 + 112);
	// stw r7,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r5,116(r18)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r18.u32 + 116);
	// lwz r6,84(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// stw r5,12(r6)
	REX_STORE_U32(ctx.r6.u32 + 12, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,120(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 120);
	// stw r11,16(r4)
	REX_STORE_U32(ctx.r4.u32 + 16, ctx.r11.u32);
	// lwz r9,84(r15)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r10,124(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 124);
	// stw r10,20(r9)
	REX_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,128(r18)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r18.u32 + 128);
	// stw r7,24(r8)
	REX_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r5,84(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,132(r18)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r18.u32 + 132);
	// stw r6,28(r5)
	REX_STORE_U32(ctx.r5.u32 + 28, ctx.r6.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,136(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 136);
	// stw r11,32(r4)
	REX_STORE_U32(ctx.r4.u32 + 32, ctx.r11.u32);
	// lwz r10,140(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 140);
	// lwz r9,84(r15)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// stw r10,36(r9)
	REX_STORE_U32(ctx.r9.u32 + 36, ctx.r10.u32);
	// lwz r7,144(r18)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r18.u32 + 144);
	// lwz r8,84(r15)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// stw r7,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,148(r18)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r18.u32 + 148);
	// stw r5,44(r6)
	REX_STORE_U32(ctx.r6.u32 + 44, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,152(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 152);
	// stw r11,48(r4)
	REX_STORE_U32(ctx.r4.u32 + 48, ctx.r11.u32);
loc_827ECE8C:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x826a1cd0
	__restgprlr_14(ctx, base);
	return;
}

