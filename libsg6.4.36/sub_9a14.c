// w = 0代表查找， w = 1代表創建
// n1, n2, n3 為command 三層索引
// build_addr 正向時為被處理地址， 反向時為返回地址
void* pack_or_unpack_command(command_vdata* g_build_vdata, int n1, int n2, int n3, w = 1, void* build_addr) {
	
	int data_count = g_build_vdata->data_count;
	int i = 0;
	if (data_count < 1) {
		if (w == 0) {
			return 0x26b0;
		}
		
		struct $8bitstruct* _8bitstruct = (struct $8bitstruct*) malloc(8); // B4E01130
		memset(_8bitstruct, 0, 8);
		_8bitstruct->command_arg1 = n1;
		// -> 7BB98
		
		// vdata = ACB4A3F8, datalist = ACB32980
		// vdata 初始化略; 默認data_size為120字節
		struct command_vdata* second_command_vdata = (struct command_vdata*) malloc(36); 
		
		_8bitstruct->vdata = second_command_vdata;
		// make_command_vdata， 填充數據
		// 這裏僅僅執行了 vdata->datalist->d = _8bitstruct;
		// vdata->data_count++;
		g_build_vdata->f2(g_build_vdata, 0, _8bitstruct); 
		
		if(second_command_vdata->data_count < 1) {
			if (w == NULL) {
				return 0x26B1;
			}
			// ACB12478
			struct $24bitstruct* _24bitstr = (struct $24bitstruct*) malloc(24);
			memset(_24bitstr, 0, 24);
			_24bitstr->command_arg1 = n1; // command arg1
			_24bitstr->command_arg2 = n2; // command arg2
			time_t seed;
			seed = time(NULL); // 5E58B699
			srand(seed);
			int random_time = (int) rand() >> 31; // 074D4C00
			int c = (int) random_time >> 31; // 0
			_24bitstr->time = random_time;
			_24bitstr->c = c;
			// 創建第三層command_vdata結構
			// vdata = ACB4A498; data = ACB32A00
			// vdata 初始化略
			struct command_vdata* third_command_vdata = (struct command_vdata*) malloc(36); 
			_24bitstr->vdata = third_command_vdata;
			// 這裏僅僅執行了 vdata->datalist->d = _24bitstr;
			// vdata->data_count++;
			second_command_vdata->f2(second_command_vdata, _24bitstr); // make_command_vdata
			if (third_command_vdata->data_count < 1) {
				if (w == 0) {
					return 0x270F;
				}
				// ACB3B540
				struct $16bitstruct* _16bitstr = (struct $16bitstruct*) malloc(16);
				_16bitstr->command_arg1 = n1;
				_16bitstr->command_arg2 = n2;
				_16bitstr->command_arg3 = n3;
				// make_command_vdata， 填充數據
				// 這裏僅僅執行了 vdata->datalist->d = _16bitstr;
				// vdata->data_count++;
				third_command_vdata->f2(third_command_vdata, _16bitstr);// make_command_vdata
				// 異或加密地址存儲
				_16bitstr->xoraddr = _24bitstr->time ^ build_addr;
				return 0;
				
			} else {
				i  = 0;
				while (i < third_command_vdata->data_count) {
					// 這裏後面在說
				}
			}
		} else {
			i = 0;
			while(i < second_command_vdata->data_count) {
				// 這裏後面在說
			}
			
		}
	} else {
		struct data** datalist = g_build_vdata->datalist;
		struct $8bitstruct* _8bitstr = NULL;
		for (int i = 0 ; i < g_build_vdata->data_count; i++) {
			_8bitstr = datalist[i];
			if(_8bitstr->command_arg1 == n1) {
				break;
			}
		}
		// 取第二層機構
		struct command_vdata* second_command_vdata = _8bitstr->vdata;
		if (second_command_vdata->data_count < 1 ) {
			return 0x26B1;
		}
		
		datalist = second_command_vdata->datalist;
		struct $24bitstruct* _24bitstr = NULL;
		
		for (int j = 0 ; j < second_command_vdata->data_count ; j++) {
			if((struct $24bitstruct*) datalist[i]->command_arg2 == n2) {
				_24bitstr = datalist[i];
				break;
			}
		}
		
		if (w == 0) {
			return ??;
		}
		
		if (_24bitstr == NULL) {
			_24bitstr = malloc(24);
			// 創建$24bitstruct 結構體
			// 創建third_command_vdata ACB4A4C0;同上
			// 更新second_command_vdata datalist同時data_count++等
			// ACB124C0  24bitstr, 
			// 創建完后調用
		}
		
		// 取第三層
		struct $16bitstruct* _16bitstr = NULL;
		struct command_vdata* third_command_vdata = _24bitstr->vdata;
		if(third_command_vdata->data_count < 1) {
			
		}
		
		for (j = 0; j < third_command_vdata->data_count; j++) {
			if ((struct $16bitstruct*) third_command_vdata[j]->command_arg3 == n3) {
				_16bitstr = third_command_vdata[j];
				break;
			}
		}
		
		if (w == 0) {
			return ??;
		}
		
		if (_16bitstr == NULL) {
			_16bitstr = malloc(16);
			// ACB11F50
			// 創建$16bitstruct; 同上
			return 0;
		}
	}
}
