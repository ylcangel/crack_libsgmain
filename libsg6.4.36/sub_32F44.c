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