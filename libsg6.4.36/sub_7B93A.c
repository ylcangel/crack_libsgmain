signed int sub_7B93A(tmp1_vdata *a1, int a2, int a3)
{ // 參數2好像代表chunk偏移，參數3為數據起始地址
  tmp1_vdata *v3; // r4@1
  int v4; // r9@1
  int v5; // r6@1
  signed int result; // r0@2
  int v7; // r1@3
  int v8; // r0@5
  int v9; // r8@6
  int v10; // r0@8
  int v11; // r2@8

  v3 = a1;
  v4 = a3;
  v5 = a2;
  if ( !a1 )
    return 0;
  result = 0;
  if ( a2 < 0 )
    return result;
  v7 = v3->lastoff;
  if ( v7 < v5 )
    return result;
  if ( v7 == v3->chunk_size )
  {
    v8 = ((int (__fastcall *)(struct data *, int))realloc)(v3->data, 4 * v7 + 128);
    if ( v8 )
    {
      v3->data = (struct data *)v8;
      v9 = v3->chunk_size;
      ((void (__fastcall *)(int, signed int))memset2)(v8 + 4 * v9, 128);
      v3->chunk_size = v9 + 32;
      v7 = v3->lastoff;
      goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( v7 != v5 )
  {
    v10 = v5 - v7;
    v11 = v7;
    do
    {
      ++v10;
      v3->data[v11].d = v3->data[v11 - 1].d;
      --v11;
    }
    while ( v10 );
  }
  v3->data[v5].d = (char *)v4;
  v3->lastoff = v7 + 1;
  return 1;
}