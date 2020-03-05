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
	char* d; // 可变长数据
};

struct vdata{
	struct data* data;
	int data_len; // 前一次记录的内存大小
	int data_mlen; // 占总内存大小
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
			vdata->f3 = extend_vdata;
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
