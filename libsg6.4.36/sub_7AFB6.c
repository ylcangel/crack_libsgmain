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


struct vdata_6436_nest {
	void* nf1;
	void* nf2;
	void* nf3;
};

struct vdata_6436 { // 對應版本6.4.36
	struct data* data;
	int data_len;
	int data_mlen; // = len + 1
	void* f1;
	void* f2;
	void* f3;
	void* f4;
	void* f5;
	void* f6;
	void* f7;
	void* f8;
	struct vdata_6436_nest* nest6436;
};

vdata_6436 *__fastcall create_vdata6436(signed int datalen)
{
  int v1; // r5@1
  vdata_6436 *v2; // r4@2
  vdata_6436 *v3; // r6@2
  data *v4; // r6@3
  vdata_6436_nest *v5; // r3@4

  v1 = datalen;
  if ( datalen < 1 )
    goto LABEL_6;
  v2 = (vdata_6436 *)malloc(56);
  v3 = 0;
  if ( v2 )
  {
    memset(v2, 0, 56);
    v2->data_mlen = v1;
    v2->data = 0;
    v4 = (data *)malloc(v1);
    if ( v4 )
    {
      memset(v4, 0, v1);
      v2->data = v4;
      v2->data_len = 0;
      v2->f1 = &dword_B3EE5A5D;
      v2->f3 = sub_B3EE5AE0;
      v2->f4 = sub_B3EE5B7C;
      v2->f5 = sub_B3EE5BC8;
      v5 = (vdata_6436_nest *)&v2->nest6436;
      v2->f6 = sub_B3EE5C34;
      v2->f7 = sub_B3EE5C9C;
      v2->f8 = sub_B3EE5D0C;
      v2->f2 = &unk_B3EE5D75;
      v3 = v2;
      v5->nf1 = sub_B3EE5DE8;
      v5->nf2 = sub_B3EE5E38;
      v5->nf3 = sub_B3EE5E9C;
      return v3;
    }
    free(v2);
LABEL_6:
    v3 = 0;
  }
  return v3;
}