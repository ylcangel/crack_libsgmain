struct data {
	char* d; // 可变长数据
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
	void* f10; // f10 f11 = long long ,低四字节存放sub_B3BB1512，高四字节存放sub_B3BB1528
	void* f11;
};


struct vdata*  create_vdata(int datalen) {
	
	if (data_len < 1) {
		return NULL;
	}
	
	struct vdata* vdata  = malloc(56);
	if (vdata) {
		memset(vdata->data_len, 0, 52) // (char*) vdata + 4
		vdata->data = 0;
		vdata->data_mlen = datalen;
		
		struct vdata* data = malloc(datalen);
		if(data) {
			memset(data, 0, datalen);
			vdata->data_len = 0;
			vdata->data = data;
			vdata->f1 = make_data;
			vdata->f3 = sub_B3BB1392;
			vdata->f4 = sub_B3BB13F4;
			vdata->f5 = sub_B3BB1412;
			vdata->f6 = sub_B3BB144A;
			vdata->f7 = sub_B3BB1468;
			vdata->f2 = sub_B3BB14D2;
			vdata->f8 = sub_B3BB14AC;
			vdata->f9 = sub_B3BB1500;
			vdata->f10 = sub_B3BB1512;
			vdata->f11 = sub_B3BB1528;
		}
		free(vdata);
		vdata = NULL;
	}
	return vdata;
}
