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