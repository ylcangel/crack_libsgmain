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


int __fastcall read_off_8AA50(unsigned int off, int index)
{
  unsigned int v2; // r4@1
  int v3; // r5@1
  bool v4; // zf@2
  int v5; // r0@6
  int v6; // r4@8

  v2 = off;
  v3 = index;
  if ( off > 2 )
    goto LABEL_15;
  v4 = (index | 4) == 7;
  if ( (index | 4) != 7 )
    v4 = (index | 9) == 9;
  if ( v4 )
  {
    pthread_mutex_lock((pthread_mutex_t *)&pthread_lock);
	// 第一次計算off_8AA50[9] = 0xB3EF7E54 = 文件偏移8CE54
	// 第二次計算 [0xB3EF7E54 + 4] =  0
	// libsgmainso_6.4.36.so:B3EF7E58 DCD 0
    v5 = *(_DWORD *)(off_8AA50[index] + 4 * off); 
    if ( v5 && *(_DWORD *)(v5 + 4) ) // 不成立
      v6 = (*(int (**)(void))(v5 + 40))();
    else
      v6 = 0; // 返回0
    pthread_mutex_unlock((pthread_mutex_t *)&pthread_lock);
  }
  else
  {
LABEL_15:
    v6 = 0;
  }
  return v6;
}