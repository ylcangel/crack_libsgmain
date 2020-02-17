signed int sub_2AC24‬(int a1)
{
  int v1; // r4@1

  v1 = a1;
  if ( a1 )
  {
    pthread_mutex_lock(&plock);
    if ( !dword_B3FB9E0C )
      dword_B3FB9E0C = v1;
    pthread_mutex_unlock(&plock);
  }
  return 1;
}