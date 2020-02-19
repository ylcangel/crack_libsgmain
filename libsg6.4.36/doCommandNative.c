int doCommandNative(JNIEnv *env, jobject obj, int command, jarray args)
{ // sub_B6F6
  int v5; // r5
  struc_2 *a5; // r6
  int v9; // r1
  int v11; // [sp+Ch] [bp-14h]
  int v12; // [sp+10h] [bp-10h]
  v5 = 0;
  v12 = *(_DWORD *)off_8AC00;
  v11 = 0;
  a5 = (struc_2 *)malloc(0x14u);
  if ( a5 )
  {
    a5->field_0 = 0;
    a5->field_4 = 0;
    a5->field_8 = 0;
    a5->field_C = 0;
    v9 = command % 10000 / 100;
    a5->field_0 = command / 10000;
    a5->field_4 = v9;
    a5->field_8 = command % 100;
    a5->field_C = env;
    a5->field_10 = args;
    v5 = goto_docommand_native_inner(command / 10000, v9, command % 100, 1, (int)a5, &v11);
  }
  free(v8);
  if ( !v5 && v22 )
    goto_throw_exception(v4, v22, (int)&byte_83ED7);
  if ( *(_DWORD *)off_8AC00 != v23 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v23, v23);
  return v5;
}


int sub_B6F6(int a1, int a2, int a3, int a4)
{ // doCommandNative
  int v4; // r8@1
  int v5; // r5@1
  int v6; // r9@1
  _DWORD *v8; // r6@1
  int v17; // r0@2
  int v20; // r1@2
  int v22; // [sp+Ch] [bp-14h]@1
  int v23; // [sp+10h] [bp-10h]@1

  v4 = a1;
  v5 = 0;
  v6 = a4;
  _R4 = a3; // 10601
  v23 = *(_DWORD *)off_8AC00;
  v22 = 0;
  v8 = malloc(0x14u);
  if ( v8 )
  {
    _R0 = 1759218605; // 68DB8BAD
    _R2 = 1374389535; // 51EB851F
    __asm { SMMUL.W         R0, R4, R0 } // ‭2B6AFEF5‬
    *v8 = 0;
    v8[1] = 0;
    v8[2] = 0;
    v8[3] = 0;
    __asm { SMMUL.W         R3, R4, R2 } // ‭51EB90B7‬
    v17 = ((signed int)_R0 >> 12) + (_R0 >> 31); //0x2b6af 參數1
    _R1 = _R4 - 10000 * v17; // 0x89792fa1 參數2 
    __asm { SMMUL.W         R1, R1, R2 } // 5174E057‬‬‬  
    v20 = ((signed int)_R1 >> 5) + (_R1 >> 31); // 28BA702‬‬‬
    *v8 = v17;
    v8[1] = v20;
	
    v8[2] = _R4 - 100 * (((signed int)_R3 >> 5) + (_R3 >> 31)); // 10601 - 1000023F4 = 0x0575‬ 參數3

    v8[3] = v4;
    v8[4] = v6;
    v5 = sub_9D60(v17, _R1， v8[2]， 1， v8, v22);
  }
  free(v8);
  if ( !v5 && v22 )
    sub_7CF34(v4);
  if ( *(_DWORD *)off_8AC00 != v23 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v23);
  return v5;
}


舉例：
int _R4 = 10601; // command
int _R0 = 0x68DB8BAD; // 68DB8BAD
int _R2 = 0x51EB851F; // 51EB851F

int r0 = _R0 * _R4;
int r3 = _R2 * _R4;

r0 = ((signed int)r0 >> 0xc) + (r0 >> 31); // 參數1
int r1 = _R4 - r0 * 10000 ; // 參數2
r1 = _R4 * r1;
r2 = _R4 - (((signed int)r3 >> 5) + (r3 >> 31)) * 100; // 參數3

r0 = 2b6af
r1 = 89792fa1
r2 = 575

goto_docommand_native_inner
sub_9D60->sub_9D82
docommand_native_inner

int __fastcall sub_9D82(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int *v6; // r4@1
  int v7; // r0@3
  int result; // r0@6
  int (__fastcall *v9)(int, int *); // [sp+8h] [bp-10h]@1
  int v10; // [sp+Ch] [bp-Ch]@1

  v6 = &dword_8CA7C;
  v10 = *(_DWORD *)off_8AC00;
  v9 = 0;
  if ( a4 )
    v6 = &dword_8CA78;
  v7 = sub_9854(*v6, a1, a2, a3);
  if ( v7 )
  {
    if ( a6 )
      *a6 = v7;
    result = 0;
  }
  else
  {
    result = v9(a5, a6);
  }
  if ( *(_DWORD *)off_8AC00 != v10 )
    _stack_chk_fail(result);
  return result;
}
