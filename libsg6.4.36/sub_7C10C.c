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


struct vdata32_nest {
	void* nf1;
	void* nf2;
	void* nf3;
	void* nf4;
};

struct vdata32 {
	struct data* data128;
	int data_count;
	int chunk_size;
	void* f1; // goto_make_vdata32;
	struct vdata32_nest* nest;
};

vdata32 *create_vdata32()
{
  vdata32 *v0; // r0@1
  vdata32 *v1; // r4@1
  struct data *v2; // r0@2
  struct data *v3; // r5@2
  vdata32_nest *v4; // r12@3

  v0 = (vdata32 *)malloc(0x20u);
  v1 = v0;
  if ( !v0 )
    return 0;
  memset(v0, 32);
  v2 = (struct data *)malloc(0x80u);
  v3 = v2;
  if ( !v2 )
  {
    free(v1);
    return 0;
  }
  memset(v2, 128);
  v4 = (vdata32_nest *)&v1->nest;
  v1->data128 = v3;
  v1->chunk_size = 128;
  v1->f1 = sub_7C180;
  v4->nf1 = sub_7C3C0;
  v4->nf2 = sub_7C280; // make_vdata32
  v4->nf3 = sub_7C43C;
  v4->nf4 = sub_7C49C;
  return v1;
}