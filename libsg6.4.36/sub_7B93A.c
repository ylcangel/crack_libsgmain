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


signed int __fastcall make_command_vdata(command_vdata *vdata, int index, $8bitstruct *a3)
{
  command_vdata *gcommand_build_vdata; // r4@1
  $8bitstruct *first_8bitstr_ptr; // r9@1
  int v5; // r6@1
  signed int result; // r0@2
  int data_count; // r1@3
  int new_extend_data; // r0@5
  int data_size; // r8@6
  int v10; // r0@8
  int v11; // r2@8

  gcommand_build_vdata = vdata;
  first_8bitstr_ptr = a3;
  v5 = index;
  if ( !vdata )
    return 0;
  result = 0;
  if ( index < 0 )
    return result;
  data_count = gcommand_build_vdata->data_count;
  if ( data_count < v5 )
    return result;
  if ( data_count == gcommand_build_vdata->data_size )
  {
    new_extend_data = realloc(gcommand_build_vdata->datalist, 4 * data_count + 128);
    if ( new_extend_data )
    {
      gcommand_build_vdata->datalist = (struct data **)new_extend_data;
      data_size = gcommand_build_vdata->data_size;
      memset(new_extend_data + 4 * data_size, 128);
      gcommand_build_vdata->data_size = data_size + 32;
      data_count = gcommand_build_vdata->data_count;
      goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  if ( data_count != v5 )
  { // 雖然這段代碼可能不會執行，但是感覺這段代碼明顯存在bug
	// 應該是while(v10) 可能永遠為true
    v10 = v5 - data_count;
    v11 = data_count;
    do
    {
      ++v10;
      gcommand_build_vdata->datalist[v11] = gcommand_build_vdata->datalist[v11 - 1];
      --v11;
    }
    while ( v10 );
  }
  gcommand_build_vdata->datalist[v5] = (struct data *) first_8bitstr_ptr;
  gcommand_build_vdata->data_count = data_count + 1;
  return 1;
}