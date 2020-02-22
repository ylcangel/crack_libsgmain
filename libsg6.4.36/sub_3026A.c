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