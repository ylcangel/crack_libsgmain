struct data {
	char* d;
};

struct vdata{
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