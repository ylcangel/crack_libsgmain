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

struct tmp1_nest {
	void* tmp1_nf1;
	void* tmp1_nf2;
	int len;
};

struct tmp1_vdata {
	struct data** datalist; // 第一層$8bitstruct
	int data_count;
	int data_size;
	void* tmp1_f1;
	void* tmp1_f2;
	void* tmp1_f3;
	struct tmp1_nest* nest;
};

struct $8bitstruct {
	int command_arg1; // command arg1
	struct tmp1_vdata* vdata; // 指向第二層
};

struct $24bitstruct {
	int command_arg1; // command arg1
	int command_arg2; // command arg2
	long time;
	int c; // 未知
	struct tmp1_vdata* vdata; // 指向第三層
	int d; // 未知
};

struct $16bitstruct {
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

struct tmp_vdata { // 創建tmp1_vdata時用到
	char* wh;
	void* f1;
	void* f2;
};
