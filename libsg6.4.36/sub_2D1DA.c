int __fastcall sub_2D1DA(unsigned int a1, int a2)
{ // 參數1是jarray第一個值，參數2是程序傳遞下來的9 
  int v2; // r5@1
  unsigned int v3; // r4@1
  int v4; // r8@1
  int v5; // r0@1
  int v6; // r6@1
  int v7; // r0@3

  v2 = a2;
  v3 = a1;
  v4 = goto_make_vdata6436(a1, a2);
  v5 = goto_read_off_8AA50(v3, v2);
  v6 = v5;
  if ( !v5 || !*(_DWORD *)(v5 + 4) )
  {
    goto_free_vdata(v5);
    v7 = sub_30D24(v4);
    v6 = v7;
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 4) )
        sub_302C8(v7, v3, v2);
    }
    else
    {
      v6 = 0;
    }
  }
  goto_free_vdata(v4);
  return v6;
}