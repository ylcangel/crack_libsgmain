int __fastcall sub_32C46(unsigned int a1)
{ // 第一個jarray的值，這裏為1
  unsigned int v1; // r6@1
  int v2; // r4@2
  int v3; // r2@3
  int v4; // r5@3
  int v5; // r0@4
  int v7; // r0@9
  int v8; // r8@9
  int v9; // r2@9
  int v10; // r0@9
  int v11; // r6@9

  v1 = a1;
  if ( a1 > 2 )
    return 0;
  v4 = sub_30590();
  if ( v4 || (sub_32CC8(0, v1, v3), (v4 = v5) != 0) && *(_DWORD *)(v5 + 4) )
  {
    v2 = (*(int (__fastcall **)(int))(v4 + 40))(v4);
LABEL_7:
    goto_free_vdata(v4);
    return v2;
  }
  goto_free_vdata(v5);
  v2 = 0;
  v7 = sub_30240(v1, 0);
  v8 = v7;
  sub_32CC8(v7, v1, v9);
  v11 = v10;
  v4 = 0;
  if ( v10 )
  {
    if ( *(_DWORD *)(v10 + 4) )
      v2 = (*(int (__fastcall **)(int))(v10 + 40))(v10);
    else
      v2 = 0;
    v4 = v11;
  }
  if ( v8 )
    goto_free_vdata(v8);
  if ( v4 )
    goto LABEL_7;
  return v2;
}