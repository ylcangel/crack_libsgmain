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