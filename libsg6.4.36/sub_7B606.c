vstring *__fastcall create_vstring(vdata *a1)
{
  vdata *v1; // r5@1
  vstring *v2; // r4@2
  vstring *result; // r0@2
  char *v4; // r8@3
  void *v5; // r0@4
  int v6; // r6@4

  v1 = a1;
  if ( !a1 )
    return 0;
  v2 = (vstring *)malloc(8u);
  result = 0;
  if ( v2 )
  {
    v2->str = 0;
    v2->len = 0;
    result = v2;
    v4 = (char *)v1->data_len;
    if ( v4 )
    {
      v5 = malloc((size_t)(v4 + 1));
      v6 = (int)v5;
      if ( v5 )
      {
        memset(v5, v4 + 1);
        v2->len = v6;
        _aeabi_memcpy(v6, v1->data, v4);
        v2->str = v4;
        return v2;
      }
      free(v2);
      return 0;
    }
  }
  return result;
}