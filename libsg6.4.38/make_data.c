vdata * make_data(vdata *dstdata, int databuf_, signed int datalen_)
{
  vdata *v3; // r5@1
  signed int datalen; // r4@1
  int databuf; // r6@1
  __int64 v6; // r0@4 
              
//      va = ma + 4 = 0;
//      vb = ma->data_mlen = 0x11
//      memcpy(r1, mb, 0x10); 第一次mb = "DcO/lcK+h?m3c*q@"
//      ma->data_len = data_mlen -1;

  v3 = dstdata;
  datalen = datalen_;
  databuf = databuf_;
  if ( dstdata && databuf_ && datalen_ >= 1 )
  {
    v6 = *(_QWORD *)&dstdata->data_len;
    if ( (signed int)v6 + datalen_ >= SHIDWORD(v6) )
    {
      dstdata = (vdata *)sub_8C392((void **)&v3->data, datalen_);
      if ( (signed int)dstdata < 0 )
        return dstdata;
      LODWORD(v6) = v3->data_len;
    }
    _aeabi_memcpy((char *)v3->data + v6, databuf, datalen);
    dstdata = (vdata *)(v3->data_len + datalen);
    v3->data_len = (int)dstdata;
  }
  return dstdata;
}