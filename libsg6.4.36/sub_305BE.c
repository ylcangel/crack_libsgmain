int __fastcall sub_305BE(unsigned int a1, signed int a2)
{
  unsigned int v2; // r5@1
  signed int v3; // r6@1
  int v4; // r4@2
  int v5; // r0@3
  int v6; // r0@5

  v2 = a1;
  v3 = a2;
  if ( a1 <= 2 )
  {
    v5 = goto_read_off_8AA50(a1, 9);
    v4 = v5;
    if ( !v5 || !*(_DWORD *)(v5 + 4) )
    {
      v6 = sub_2D228(v2);
      v4 = v6;
      if ( v6 && *(_DWORD *)(v6 + 4) )
      {
        sub_302C8(v6, v2, 9);
      }
      else if ( v3 >= 1 )
      {
        sub_304E4(v2, 0);
      }
    }
  }
  else
  {
    v4 = 0;
  }
  return v4;
}