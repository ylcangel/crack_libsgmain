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


struct data {
	char* d;
};

struct tmp1_nest_struct {
	void* tmp1_nf1;
	void* tmp1_nf2;
	int len;
};

struct tmp1_vdata {
	struct data* datalist;
	int chunk_count;
	int chunk_size;
	void* tmp1_f1;
	void* tmp1_f2;
	void* tmp1_f3;
	struct tmp1_nest_struct tmp1_nest;
};

tmp1_vdata* sub_7B86C(signed int a1, int a2)
{ // create_tmp1_vdata, 第一次傳入0x20, 0
  signed int v2; // r5@1
  int v3; // r8@1
  tmp1_vdata *v4; // r0@2
  tmp1_vdata *v5; // r4@2
  struct data *v6; // r0@3
  struct data *v7; // r6@3
  tmp1_nest_struct *v8; // r0@4

  v2 = a1; // 傳入為0x20
  v3 = a2;
  if ( a1 < 1 )
    return 0;
  v4 = (tmp1_vdata *)malloc(0x24u);
  v5 = v4;
  if ( !v4 )
    return 0;
  memset(v4, 36);
  v6 = (struct data *)malloc(4 * v2); // 0x80 = 128
  v7 = v6;
  if ( !v6 )
  {
    free(v5);
    return 0;
  }
  memset(v6, 4 * v2);
  v5->data = v7;
  v5->chunk_count = 0;
  v5->chunk_size = v2;
  v5->tmp1_f1 = sub_7B8F8;
  v8 = &v5->tmp1_nest;
  v5->tmp1_f2 = sub_7B9B4;
  v5->tmp1_f3 = byte_7B9F5;
  v8->tmp1_nf1 = sub_7BA80;
  v8->tmp1_nf2 = sub_7BAF0;
  v8->len = v3;
  return v5;
}