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

struct vdata_64176 { // 對應版本6.4.176
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
	void* f9;
	void* f10;
	void* f11;
};

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
	struct vdata_6436_nest* nest;
};

struct dcryptdata {
	void* v;
	int caseno;
	void* v1;
	void* decryptdata_;
	struct vdata* key;
	struct vdata* cryptedata;
};

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

struct global_command_entry { // 記錄著生成和執行command的核心方法
	void* goto_make_command_entry; // 對應sub_9B3C
	void* goto_do_command1; // // 對應sub_9d82; command_native_inner
	void* goto_do_command2; // 對應sub_9e7e; 和sub_9d82差不多
};

struct command_nest {
	void* nf1;
	void* nf2;
	int len;
};

struct command_vdata {
	struct data** datalist; // 第一層$8bitstruct
	int data_count;
	int data_size;
	void* f1;
	void* f2; // make_vdata
	void* f3;
	struct command_nest* nest;
};

struct $8bitstruct { // 第一層結構
	int command_arg1; // command arg1
	struct command_vdata* vdata; // 指向第二層
};

struct $24bitstruct { // 第二層結構
	int command_arg1; // command arg1
	int command_arg2; // command arg2
	long time;
	int c; // (time >> 31)
	struct command_vdata* vdata; // 指向第三層
	int d; // 未知
};

struct $16bitstruct { // 第三層結構
	int command_arg1; // command arg1
	int command_arg2; // command arg2
	int command_arg3; // command arg3
	int xoraddr;
};

struct command_arg {
	int arg1;
	int arg2;
	int arg3;
	_JNIEnv* env;
	void* args;
};

struct vstring {
	int len;
	char* str;
};
