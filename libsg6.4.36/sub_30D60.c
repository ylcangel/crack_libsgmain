int sub_30D60(vdata_6436 *a1)
{
  __int64 v1; // kr00_8@1
  int v2; // r5@1
  int v3; // r0@1
  int v4; // r4@1
  int v6; // [sp+4h] [bp-1Ch]@1
  int v7; // [sp+8h] [bp-18h]@1
  int v8; // [sp+Ch] [bp-14h]@1
  int v9; // [sp+10h] [bp-10h]@1
  int v10; // [sp+14h] [bp-Ch]@1

  v10 = *(_DWORD *)off_8AC00;
  v6 = 0;
  v1 = *(_QWORD *)&a1->data;
  v2 = geto_create_vdata32(a1->data, a1->data_len);                   // sub_7C258
  v7 = v2; // vdata32
  v8 = 1;
  v9 = 7;
  v3 = sub_73D90(); // 讀取90804的值到寄存器r0, 調試時為ACB3B600
  // v3 + 4 = 0x9df5, 最終是sub_9E30，即goto_docommand_native_inner
  v4 = (*(int (__fastcall **)(signed int, signed int, signed int, int *))(v3 + 4))(1, 21, 2, &v7);
  goto_callfree(v2);
  if ( *(_DWORD *)off_8AC00 != v10 )
    _stack_chk_fail(*(_DWORD *)off_8AC00 - v10, v10);
  return v4;
}