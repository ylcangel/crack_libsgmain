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


signed int __fastcall sub_73668(int a1, int a2, int a3, int a4)
{
  signed int v4; // r5@1
  int v5; // r3@1
  _JNIEnv *v6; // r0@1
  _JNIEnv *v7; // r4@1
  int v8; // r0@2
  int v9; // r5@2
  int v10; // r3@3
  int v12; // [sp+0h] [bp-10h]@2
  int v13; // [sp+4h] [bp-Ch]@1
  int v14; // [sp+8h] [bp-8h]@2
  int v15; // [sp+Ch] [bp-4h]@2

  v4 = 0;
  goto_getenv(0, a2, a3, a4, *(_DWORD *)off_8AC00, v13);
  v7 = v6;
  if ( v6 )
  {
    call_decrypto_entry((int)&unk_860DC, (int)(&v12 - 14), 54, v5, v12, v13, v14, v15);
	// "com/taobao/wireless/security/adapter/umid/UmidAdapter"
    v8 = ((int (__fastcall *)(_JNIEnv *, int *))v7->functions->FindClass)(v7, &v12 - 14);
    v9 = v8;
    if ( v8 )
    {
      UmidAdapterRef = ((int (__fastcall *)(_JNIEnv *, int))v7->functions->NewGlobalRef)(v7, v8);
      ((void (__fastcall *)(_JNIEnv *, int))v7->functions->DeleteLocalRef)(v7, v9);
      call_decrypto_entry((int)&unk_86113, (int)(&v12 - 4), 16, v10, v12, v13, v14, v15);
      v4 = 1;
	  // umidInitAdapter methodID
      umidInitAdapterMethodId = ((int (__fastcall *)(_JNIEnv *, int, int *, const char *))v7->functions->GetStaticMethodID)(
                                  v7,
                                  UmidAdapterRef,
                                  &v12 - 4,
                                  "(I)I");
    }
    else
    {
      v4 = 0;
    }
  }
  if ( *(_DWORD *)off_8AC00 != v12 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v12, v12);
  return v4;
}