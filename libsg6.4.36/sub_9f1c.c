signed int sub_9F1C()
{
  int v0; // r0@1
  tmp_vdata *v1; // r4@2
  signed int result; // r0@2

  sub_B3FA1D90();
  if ( !v0 )
  {
    v1 = (tmp_vdata *)malloc(12);
    result = 0;
    if ( !v1 )
      return result;
    v1->f1 = 0;
    v1->wh = 0;
    tmp1_data1_ = goto_create_tmp1vdata(0);     // 0x20,0
    tmp1_data2 = goto_create_tmp1vdata(0);      // 0x20,0
    v1->wh = (char *)&dword_B3F37A99;
    v1->f1 = sub_B3F37DF4;
    v1->f2 = sub_B3F37E48;
    sub_B3FA1DD4(v1);
  }
  return 1;
}