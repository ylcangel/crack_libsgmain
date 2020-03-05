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


int sub_E890(int a1, int a2, int a3, int a4)
{
  _JNIEnv *v4; // r4@1
  int v5; // r3@1
  int v6; // r0@1
  int v7; // r5@1
  int v8; // r3@2
  int result; // r0@3
  int v10; // [sp+0h] [bp-70h]@1
  int v11; // [sp+4h] [bp-6Ch]@1
  int v12; // [sp+8h] [bp-68h]@1
  int v13; // [sp+Ch] [bp-64h]@1
  char v14; // [sp+4Ah] [bp-26h]@1
  int v15; // [sp+60h] [bp-10h]@1

  v4 = (_JNIEnv *)a1;
  v15 = *(_DWORD *)off_8AC00;
  // "(I)Ljava/lang/String;"
  goto_decrypt_entry((int)&unk_841F3, (int)&v14, 22, a4, v10, v11, v12, v13);
  // "com/taobao/wireless/security/adapter/datacollection/DeviceInfoCapturer"
  goto_decrypt_entry((int)&unk_8420A, (int)&v10 + 3, 71, v5, v10, v11, v12, v13);
  v6 = ((int (__fastcall *)(_JNIEnv *, char *))v4->functions->FindClass)(v4, (char *)&v10 + 3);
  v7 = v6;
  if ( v6 )
  {
    global_DeviceInfoCapturer_ref = ((int (__fastcall *)(_JNIEnv *, int))v4->functions->NewGlobalRef)(v4, v6);
    ((void (__fastcall *)(_JNIEnv *, int))v4->functions->DeleteLocalRef)(v4, v7);
    goto_decrypt_entry((int)&unk_84252, (int)(&v10 - 6), 19, v8, v10, v11, v12, v13);
    global_DeviceInfoCapturer_methodId = ((int (__fastcall *)(_JNIEnv *, int, int *, char *))v4->functions->GetStaticMethodID)(
                    v4,
                    dword_8CA98,
                    &v10 - 6,
                    &v14);
  }
  result = *(_DWORD *)off_8AC00 - v15;
  if ( *(_DWORD *)off_8AC00 != v15 )
    _stack_chk_fail(result, v15);
  return result;
}