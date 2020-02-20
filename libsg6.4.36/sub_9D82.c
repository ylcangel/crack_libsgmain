int  sub_9D82(int a1, int a2, int a3, int a4, int a5, int *a6)
{ // goto_docommand_native_inner
  int *v6; // r4@1
  int v7; // r0@3
  int v8; // r0@3
  int result; // r0@6
  int (__fastcall *v10)(int, int *); // [sp+8h] [bp-10h]@1
  int v11; // [sp+Ch] [bp-Ch]@1

  v6 = &dword_8CA7C;
  v11 = *(_DWORD *)off_8AC00;
  v10 = 0;
  if ( a4 )
    v6 = &dword_8CA78;
  v7 = *v6;
  sub_9854();
  if ( v8 )
  {
    if ( a6 )
      *a6 = v8;
    result = 0;
  }
  else
  {
    result = v10(a5, a6);
  }
  if ( *(_DWORD *)off_8AC00 != v11 )
    _stack_chk_fail(result, *(_DWORD *)off_8AC00 - v11);
  return result;
}
