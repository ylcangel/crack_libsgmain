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
