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


int __fastcall sub_32F44(unsigned int a1)
{
  unsigned int v1; // r4@1
  int v2; // r0@2
  int v3; // r4@4

  v1 = a1;
  pthread_mutex_lock((pthread_mutex_t *)&pthread_lock_0);
  if ( v1 <= 2 && (v2 = dword_8CE6C[v1]) != 0 && *(_DWORD *)(v2 + 4) )
    v3 = (*(int (**)(void))(v2 + 40))();
  else
    v3 = 0;
  pthread_mutex_unlock((pthread_mutex_t *)&pthread_lock_0);
  return v3;
}