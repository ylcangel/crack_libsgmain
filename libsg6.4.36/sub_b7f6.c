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