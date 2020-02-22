int sub_2A01E(int a1, int a2)
{ // 參數1是第一個jarray的值，參數2不知道是啥，第一次傳0
  int v2; // r8@1
  int v3; // r5@2
  int v4; // r0@4
  int v5; // r6@4
  int v6; // r0@6
  int v7; // r0@6
  int v8; // r0@8
  int v9; // r4@10
  int v11; // [sp+4h] [bp-20h]@14
  int v12; // [sp+8h] [bp-1Ch]@14
  int v13; // [sp+Ch] [bp-18h]@14
  int v14; // [sp+10h] [bp-14h]@14
  int v15; // [sp+14h] [bp-10h]@1

  v2 = a2;
  v15 = *(_DWORD *)off_8AC00;
  if ( *(_DWORD *)(a1 + 4) )
    v3 = *(_DWORD *)a1;
  else
    v3 = sub_2AD20();
  v4 = sub_32C00(v3);
  v5 = v4;
  if ( v4 && *(_DWORD *)(v4 + 4) >= 32 )
  {
    v9 = sub_7B5D4(v4);
    goto LABEL_15;
  }
  v6 = goto_free_vdata(v4);
  v7 = sub_2B468(v6);
  v5 = v7;
  if ( !v7 || !*(_DWORD *)(v7 + 4) )
  {
    goto_free_vdata(v7);
    v8 = go_create_vadata(25);
    v5 = v8;
    if ( !v8 )
    {
      v9 = 0;
      v5 = 0;
      goto LABEL_14;
    }
    (*(void (**)(void))(v8 + 12))();
    if ( !*(_DWORD *)(v5 + 4) )
    {
      v9 = 0;
      goto LABEL_14;
    }
  }
  v9 = sub_7B5D4(v5);
LABEL_14:
  v11 = v3;
  v12 = 0;
  v13 = 0;
  v14 = 1;
  sub_29E98(&v11, v2);
LABEL_15:
  goto_free_vdata(v5);
  if ( *(_DWORD *)off_8AC00 != v15 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v15, v15);
  return v9;
}