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