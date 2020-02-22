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
	struct vdata_6436_nest* nest6436;
};



struct dcryptdata {
	void* v;
	int caseno;
	void* v1;
	void* decryptdata_;
	struct vdata* key;
	struct vdata* cryptedata;
};

struct tmp1_nest_struct {
	void* tmp1_nf1;
	void* tmp1_nf2;
	int len;
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

struct tmp1_vdata {
	struct data* datalist; // 指向16bitstruct的數組指針
	int chunk_count;
	int chunk_size;
	void* tmp1_f1;
	void* tmp1_f2;
	void* tmp1_f3;
	struct tmp1_nest_struct tmp1_nest;
};

struct tmp_vdata { // 創建tmp1_vdata時用到
	char* wh;
	void* f1;
	void* f2;
};

struct $8bitstruct {
	int count;
	struct tmp1_vdata* vdata;
};

struct $24bitstruct {
	int a; // 1
	int b; // 9
	long time;
	int c;
	struct tmp1_vdata* vdata; // tmp1_vdata4
	int d;
};

struct $16bitstruct {
	int t;
	int lrand;
	int random;
	int sec;
};

struct command_arg {
	int arg1;
	int arg2;
	int arg3;
	_JNIEnv* env;
	void* args;
};