void sub_9970()
{
  int v0; // r5@0
  int v1; // r6@0
  int v2; // r9@0
  int v3; // r1@1
  int v4; // r2@1
  int v5; // r3@1
  int v6; // r4@1
  int v7; // r1@2
  int v8; // r0@3
  int v9; // r0@3
  int v10; // ST04_4@3

  v6 = malloc(24);
  if ( !v6 )
  {
    sub_B3F31998(0, v3, v4, v5);
    v6 = v7;
  }
  ((void (__fastcall *)(int, signed int))memset0)(v6, 24);
  *(_DWORD *)v6 = v1;
  *(_DWORD *)(v6 + 4) = v2;
  v8 = time(0);
  v9 = srand48(v8);
  *(_QWORD *)(v6 + 8) = lrand48(v9);
  *(_DWORD *)(v6 + 16) = goto_create_tmp1vdata(0);
  (*(void (__cdecl **)(_DWORD, int))(*(_DWORD *)(v0 + 4) + 16))(*(_DWORD *)(v0 + 4), v6);
  v10 = *(_DWORD *)(*(_DWORD *)(v6 + 16) + 4);
  dyna_pc(2);
  JUMPOUT(5);
}