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


vdata*  call_rc4(vdata *key, vdata *cryptedata)
{
  int key_len; // r0@3
  vdata* decrypted_data; // r4@4
  char swapkey[264]; // [sp+0h] [bp-120h]@9

  if ( !key )
    goto exit1;
  if ( !key->data )
    goto exit1;
  key_len = key->data_len;
  if ( !key_len )
    goto exit1;
  decrypted_data = 0;
  if ( !cryptedata || key_len < 16 )
    goto exit;
  if ( !cryptedata->data || !cryptedata->data_len || (key->data_len = 16, (decrypted_data = create_vdata(cryptedata->data_len)) == 0) )
  {
    goto exit;
  }
  memset(swapkey, 0, 264); // 实际只用256，算法里面是swapkey+8开始的
  init_rc4key(swapkey, key->data, key->data_len);
  rc4_(swapkey, cryptedata->data_len, cryptedata->data, decrypted_data->data);
  if ( decrypted_data->data )
    decrypted_data->data_len = cryptedata->data_len;

exit1:
    decrypted_data = 0;
exit:
  return decrypted_data;
}