signed int registerNatives(int a1, int a2)
{
  _JNIEnv *v2; // r5@1
  void *v3; // r8@1
  signed int v4; // r0@1
  char v6; // [sp+7h] [bp-55h]@1
  char v7; // [sp+30h] [bp-2Ch]@1
  char *v8; // [sp+40h] [bp-1Ch]@1
  char *v9; // [sp+44h] [bp-18h]@1
  void (*v10)(); // [sp+48h] [bp-14h]@1
  int v11; // [sp+4Ch] [bp-10h]@1

  v2 = (_JNIEnv *)a1;
  v3 = (void *)a2;
  v11 = _stack_chk_guard;
  ((void (__fastcall *)(void *, char *, signed int))goto_dcrypto_entry)(&unk_B3EEEED9, &v7, 16);
  ((void (__fastcall *)(void *, char *, signed int))goto_dcrypto_entry)(&unk_B3EEEEEA, &v6, 41);
  v8 = &v7;
  v9 = &v6;
  v10 = sub_B3E7669C;
  v4 = v2->functions->RegisterNatives((JNIEnv *)v2, v3, (const JNINativeMethod *)&v8, 1);
  if ( _stack_chk_guard != v11 )
    sub_B3E6F13C(v4, _stack_chk_guard - v11);
  return v4 >> 31;
}