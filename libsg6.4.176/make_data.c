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


vdata* make_data(vdata *old_vdata, char* databuf, int new_len)
{ // 创建数据
  // vdata结构相当于一个数据容器
  // 完成向容器中添加数据
  
    // 第一次执行示例      
	//      va = ma + 4 = 0;
	//      vb = ma->data_mlen = 0x11
	//      memcpy(r1, mb, 0x10); 第一次mb = "DcO/lcK+h?m3c*q@"
	//      ma->data_len = data_mlen -1;

  if ( old_vdata && databuf && new_len >= 1 ) {
    old_data_len = old_vdata->data_len;
	
    if ( (int)(old_data_len + new_len) >= old_vdata->data_mlen ) {
		
      old_vdata = (vdata *)extend_vdata(old_vdata, new_len);
      if ( (int)old_vdata < 0 )
        return old_vdata;
    }
	
    memcpy((char *)old_vdata->data + old_data_len, databuf, new_len);
    old_vdata->data_len = (int)(old_vdata->data_len + new_len);
  }
  return old_vdata;
}