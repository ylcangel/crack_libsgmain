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


void  sub_72080(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r1@4
  _JNIEnv *v10; // r4@0
  int v11; // r5@0
  int v12; // r7@0
  int v13; // r2@1
  int v14; // ST08_4@2
  int v15; // r1@2
  int v16; // r2@2

  *(_DWORD *)(v12 - 16) = a1;
  goto_decrypt_entry(a2 + 1, v11, a3);
  // "com/taobao/wireless/security/adapter/common/SPUtility2"
  if ( ((int (__fastcall *)(_JNIEnv *, int))v10->functions->FindClass)(v10, v11) )
  {
    v14 = ((int (__fastcall *)(_JNIEnv *))v10->functions->NewGlobalRef)(v10);
    *(_DWORD *)(v14 - 1275465542) = dyna_arg(v14, v15, v16);
    JUMPOUT(&goto_dynapc2);
  }
  dyna_arg(0, 0, v13);
  v9 = *(_DWORD *)(v12 - 16);
  JUMPOUT(__CS__, a9);
}