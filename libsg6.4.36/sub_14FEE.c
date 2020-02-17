int sub_14FEE(_JNIEnv *a1, int a2, int a3, int a4)
{
  _JNIEnv *v4; // r4@1
  int v5; // r5@3
  const struct JNINativeInterface *v6; // r1@3
  int v7; // r2@3
  char v8; // r1@5
  int *v9; // r0@5
  int v11; // [sp+0h] [bp-8h]@0
  int v12; // [sp+4h] [bp-4h]@0
  int savedregs; // [sp+8h] [bp+0h]@0
  int savedregs_4; // [sp+Ch] [bp+4h]@0

  v4 = a1;
  if ( !a1 )
  {
    v8 = 0;
    v9 = &dword_B3EB5B04;
LABEL_7:
    *(_BYTE *)v9 = v8;
    return 0;
  }
  if ( !(_BYTE)dword_B3EB5B04 )
  {
    v5 = 0;
    v6 = a1->functions;
    dword_B3EB5B0C = (int)a1->functions->GetFieldID;
    dword_B3EB5B1C = (int)v6->GetStaticFieldID;
    v7 = (int)v6->GetMethodID;
    dword_B3EB5B10 = (int)v6->GetMethodID;
    dword_B3EB5B20 = (int)v6->GetStaticMethodID;
    do
      sub_1511C((int)v4, v5++, v7, a4, v11, v12, savedregs, savedregs_4);
    while ( v5 != 9 );
    v8 = 1;
    v9 = &dword_B3EB5B04;
    goto LABEL_7;
  }
  return 0;
}