/**
 * Author: sp00f
 * 本人聲明： 該項目僅用於學習和交流目的，不能用於其他目的，否則後果自負；
 * 另外該項目所有權僅屬於我個人，你可以下載或者fork該項目，但不能用於其他目的（如發表文章、出書、投稿等），否則必究。
 * 你可以吐槽我，不过还是希望尊重我的辛苦成果，有不对的地方，可以指出，大家互相探讨
 * 对于逆向我也是个小学生，水平有限，还请大佬们一笑而过
 * 出于时间考虑，我分析完之后，没有对调试过程返回来看，但应该大致描述清楚了
 * 如果纰漏，请见谅
 *
*/


int __fastcall decrypt_entry(int encdata, int decdata, int datalen)
{
  int v3; // r10@1
  int v4; // r6@1
  int v5; // r5@1
  int v6; // r8@1
  vdata *v7; // r11@1
  vdata *v8; // r9@1
  int v9; // r4@4
  int v10; // r5@5
  int v11; // r0@5
  struct dcryptdata* v13; // [sp+0h] [bp-30h]@5
  int v14; // [sp+4h] [bp-2Ch]@5
  vdata *v15; // [sp+10h] [bp-20h]@5
  vdata *v16; // [sp+14h] [bp-1Ch]@5
  int v17; // [sp+1Ch] [bp-14h]@1
  int v18; // [sp+20h] [bp-10h]@1

  v3 = encdata;
  v4 = 0;
  v5 = datalen;
  v6 = decdata;
  v18 = _stack_chk_guard;
  v17 = 0;
  v7 = (vdata *)goto_create_vdata(17);
  v8 = (vdata *)goto_create_vdata(v5);
  if ( !v7 )
  {
    v9 = 0;
    goto LABEL_12;
  }
  // make_vdata 填充數據
  ((void (__fastcall *)(vdata *, const char *, signed int))v7->f1)(v7, "DcO/lcK+h?m3c*q@", 16); 
  if ( !v8 )
  {
LABEL_9:
    v4 = 0;
    goto LABEL_10;
  }
  v4 = 0;
  if ( !v3 )
  {
LABEL_10:
    v9 = 0;
    goto LABEL_11;
  }
  v9 = 0;
  if ( v6 )
  {
    ((void (__fastcall *)(int, int))memset0)(v6, v5);
    v10 = v5 - 1;
	// make_vdata 填充數據
    ((void (__fastcall *)(vdata *, int, int))v8->f1)(v8, v3, v10);
    ((void (__fastcall *)(int *, signed int))memset0)(&v13, 20);
    v14 = 3;
    v15 = v7;
    v16 = v8;
	// 調用rc4解密
	// 解密出"com/taobao/wireless/security/adapter/common/HttpUtil"
    v11 = ((int (__fastcall *)(int *, int *))goto_dcrypto)(&v13, &v17); 
    v9 = v11;
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 4) != v10 )
        goto LABEL_19;
	  // 拷貝到傳入的緩衝區
      ((void (__fastcall *)(int, _DWORD, int))memcpy)(v6, *(_DWORD *)v11, v10);
      v4 = *(_DWORD *)(v9 + 4);
      goto LABEL_11;
    }
    goto LABEL_9;
  }
LABEL_11:
  while ( 1 )
  {
    ((void (__fastcall *)(vdata *))goto_free_vdata)(v7);
LABEL_12:
    if ( v8 )
      ((void (__fastcall *)(vdata *))goto_free_vdata)(v8);
    if ( v9 )
      ((void (__fastcall *)(int))goto_free_vdata)(v9);
    if ( _stack_chk_guard == v18 )
      break;
    ((void (__fastcall *)(int))unk_B3F3113C)(_stack_chk_guard - v18);
LABEL_19:
    v4 = 0;
  }
  return v4;
}