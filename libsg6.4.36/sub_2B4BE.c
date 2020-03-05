/**
 * Author: sp00f
 * 本人聲明： 該項目僅用於學習和交流目的，不能用於其他目的，否則後果自負；
 * 另外該項目所有權僅屬於我個人，你可以下載或者fork該項目，但不能用於其他目的（如發表文章、出書、投稿等），否則必究。
 * 你可以吐槽我，不过还是希望尊重我的辛苦成果，有不对的地方，可以指出，大家互相探讨
 * 对于逆向我也是个小学生，水平有限，还请大佬们一笑而过
 * 出于时间考虑，我分析完之后，没有对调试过程返回来看，但应该大致描述清楚了
 * 如果纰漏，请见谅
 *
*/


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