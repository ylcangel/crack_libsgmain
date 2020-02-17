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