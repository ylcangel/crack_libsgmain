int call_docommand_innerx()
{
  int v0; // r4@1
  int v1; // r0@1
  const char *v2; // r5@1
  size_t v3; // r0@3
  void (__fastcall *v4)(int, const char *, size_t); // r6@4
  size_t v5; // r0@4
  int v7; // [sp+4h] [bp-14h]@1
  int v8; // [sp+8h] [bp-10h]@1

  v0 = 0;
  v8 = *(_DWORD *)off_8AC00;
  v7 = 0;
  sub_73D90(); // 保存著包含do_command_inner的結構
  // v1 + 4 指向的是do_command_inner的函數指針
  v2 = (const char *)(*(int (__fastcall **)(signed int, signed int, signed int, signed int))(v1 + 4))(1, 9, 2, 111);
  if ( v2 ) 
  { // 調試時返回0
    if ( *v2 && (v3 = strlen(v2), (v0 = goto_create_vadata(v3 + 1)) != 0) ) // 這裏應該包含一個解密，解密出一個結構
    {
      v4 = *(void (__fastcall **)(int, const char *, size_t))(v0 + 12);
      v5 = strlen(v2);
      v4(v0, v2, v5);
    }
    else
    {
      v0 = 0;
    }
    free((void *)v2);
  }
  if ( *(_DWORD *)off_8AC00 != v8 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v8, v8);
  return v0;
}