int  createGlobalBoolean_Integer_String(_JavaVM *a1)
{ // 对应源码
  _JNIEnv *env; // r0@1
  _JNIEnv *envf; // r4@1
  int v3; // r0@1
  int v4; // r0@1
  int v5; // r0@1
  int result; // r0@1

  javavm = (int)a1;
  env = (_JNIEnv *)getEnv(0);
  envf = env;
  v3 = ((int (*)(void))env->functions->FindClass)();
  global_jbooleanobj = ((int (__fastcall *)(_JNIEnv *, int))envf->functions->NewGlobalRef)(envf, v3);
  v4 = ((int (__fastcall *)(_JNIEnv *, const char *))envf->functions->FindClass)(envf, "java/lang/Integer");
  global_jintegerobj = ((int (__fastcall *)(_JNIEnv *, int))envf->functions->NewGlobalRef)(envf, v4);
  v5 = ((int (__fastcall *)(_JNIEnv *, const char *))envf->functions->FindClass)(envf, "java/lang/String");
  result = ((int (__fastcall *)(_DWORD, _DWORD))envf->functions->NewGlobalRef)(envf, v5);
  global_jstringobj = result;
  return result;
}
