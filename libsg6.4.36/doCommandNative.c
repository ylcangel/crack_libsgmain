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