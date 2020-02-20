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

對著匯編逆向分析:
struct command_arg {
	int arg1;
	int arg2;
	int arg3;
	JNIEnv* env;
	void* args;
};

int sub_B6F6(JNIEnv *env, jobject obj, int command, jarray args)
{ // doCommandNative
  int v4; // r8@1
  int v5; // r5@1
  int v6; // r9@1
  struct command_arg* v8; // r6@1
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
  command_arg = (struct command_arg*) malloc(0x14u);
  if ( command_arg )
  {
	// 以一次調試爲例
	int _R4 = 12302; // command
	int _R0 = 0x68DB8BAD; // 68DB8BAD
	int _R2 = 0x51EB851F; // 51EB851F

	int r0 = _R0 * _R4; // 000013AE, SMMUL.W取高位
	int r3 = _R2 * _R4; // 00000F60, SMMUL.W取高位
	// (signed int)r0 >> 0xc) = (signed int) (13AE >> 0xc) = 00000001
	// r0 >> 31 = 0
	r0 = ((signed int)r0 >> 0xc) + (r0 >> 31); // 0x1, 參數1
	int r1 = _R4 - r0 * 10000 ; // 000008FE(2302)
	r1 = _R4 * r1; // 2E0, SMMUL.W取高位
	// ((signed int)r3 >> 5) = 0000007B(123)
	// (r3 >> 31) = 0
	r2 = _R4 - (((signed int)r3 >> 5) + (r3 >> 31)) * 100; // 2, 參數3
	r3 = (signed) r1 >> 5 = 00000017(23)
	r1 = r3 + (r1 >> 31) = 1; // 0x17， 參數2
	
	command_arg->arg1 = 1;
	command_arg->arg2 = 0x17;
	command_arg->arg3 = 2;
	command_arg->env = env;
	command_arg->args = args;
	
    v5 = sub_9D60(r0, r1， r2， 1， command_arg, v22);
  }
  free(command_arg);
  if ( !v5 && v22 )
    sub_7CF34(v4);
  if ( *(_DWORD *)off_8AC00 != v23 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v23);
  return v5;
}

goto_docommand_native_inner
sub_9D60->sub_9D82
docommand_native_inner