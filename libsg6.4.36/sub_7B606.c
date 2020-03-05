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


vstring *__fastcall create_vstring(vdata *a1)
{
  vdata *v1; // r5@1
  vstring *v2; // r4@2
  vstring *result; // r0@2
  char *v4; // r8@3
  void *v5; // r0@4
  int v6; // r6@4

  v1 = a1;
  if ( !a1 )
    return 0;
  v2 = (vstring *)malloc(8u);
  result = 0;
  if ( v2 )
  {
    v2->str = 0;
    v2->len = 0;
    result = v2;
    v4 = (char *)v1->data_len;
    if ( v4 )
    {
      v5 = malloc((size_t)(v4 + 1));
      v6 = (int)v5;
      if ( v5 )
      {
        memset(v5, v4 + 1);
        v2->len = v6;
        _aeabi_memcpy(v6, v1->data, v4);
        v2->str = v4;
        return v2;
      }
      free(v2);
      return 0;
    }
  }
  return result;
}