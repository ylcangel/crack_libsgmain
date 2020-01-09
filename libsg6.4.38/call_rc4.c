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