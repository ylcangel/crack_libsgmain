int sub_9d82(int n1, int n2, int n3, int w,  struct command_arg* arg, int* next_addr) {
	struct tmp1_vdata* vdata = &dword_8CA7C; 
	if (w != 0) {
		vdata = &dword_8CA78;
	}
	// sub_9a14(tmp1_vdata, n1, n2, n3, w, 0)
	// 最外層
	datalist = vdata->datalist;
	
	int i = 0;
	struct $8bitstruct* _8bitstruct = NULL;
	while(i < n1) {
		_8bitstruct = datalist[i]->d; // 取第一層8bitstruct指針
		int ra = _8bitstruct->command_arg1; // 第一層命令
		if (ra == n1) { // 第一層對比相等
			break;
		}
		i++;
	}
	// w不爲0，可能返回0x270F、0x26B0、0x26B1
	// 這裏暫不做分析
	if (_8bitstruct == NULL && w == 0) { // 沒找到的情況
		return 0x26b0;
	}
	//獲取第二層
	struct tmp1_vdata* vdata1 = _8bitstruct->vdata;
	int count = vdata1->data_count;
	i = 0;
	struct $24bitstruct _24bitstr = NULL;
	while(i < count) {
		_24bitstr = vdata1->datalist[i]->d;
		int rb = _24bitstr->command_arg2;
		if (rb = n2) { // 第二層對比
			break;
		}
		i++;
	}
	// w不爲0，可能返回0x270F、0x26B0、0x26B1
	// 這裏暫不做分析
	if(_24bitstr == NULL && w == 0) { // 沒找到的情況
		return 0x26b0;
	}
	
	// 獲取第三層
	struct tmp1_vdata* vdata2 = _24bitstr->vdata;
	count = vdata2->data_count;
	i = 0;
	struct $16bitstruct _16bitstr = NULL;
	while(i < count) {
		_16bitstr = vdata2->datalist[i]->d;
		int rc = _16bitstr->command_arg3;
		if(rc == n3) {
			int xor_addr = _16bitstr->xoraddr ^ _24bitstr->time;
			*next_addr = xor_addr;
			break;
		}
		i++;
	}
	typedef *func(void* void*) nfunc;
	nfunc nextf= (nfunc) next_addr;
	return nextf(command_arg, next_addr);
}