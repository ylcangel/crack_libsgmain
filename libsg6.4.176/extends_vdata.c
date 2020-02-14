// 主要完成扩展vdata
// @old_vdata 待扩展vdata结构
// @extend_len 扩展长度
int extend_vdata(vdata *old_vdata, int extend_len) { 
  int newlen; // r1@3
  struct data *newdata; // r0@3
  int oldlen; // r6@4
  int result; // r0@4

  if ( old_vdata ) {
    if ( old_vdata->data ) {
      extendlen = extend_len + 100; // 扩展长度加100
      newlen = old_vdata->data_mlen + extendlen;
      newdata = relloc(old_vdata->data, newlen);
      if ( newdata ) {
        oldlen = old_vdata->data_mlen;
        old_vdata->data = (struct data *) newdata;
        memset(newdata + oldlen, 0,  extendlen);
        old_vdata->data_mlen = extendlen + oldlen;
        return 0;
      }
    } else {
      if ( relen <= 100 )
        relen = 100;
      newdata = (struct data *) malloc(relen);
      if ( newdata ) {
        memset(newdata, 0, relen);
        old_vdata->data = newdata;
        old_vdata->data_len = 0;
        old_vdata->data_mlen = relen;
        return 0;
      }
      old_vdata->data = 0;
    }
  }
  return -1;
}