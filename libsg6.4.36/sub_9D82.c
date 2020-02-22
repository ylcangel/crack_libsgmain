int sub_9d82(int n1, int n2, int n3, int w,  struct command_arg* arg, void* r) {
	struct tmp1_vdata* vdata = &dword_8CA7C; 
	if (w != 0) {
		vdata = &dword_8CA78;
	}
	
	// sub_9a14(tmp1_vdata, n1, n2, n3, )
	
	
	int data_count = vdata->chunk_count;
	if( data_count < 1) {
		if(arg == NULL) {
			return 0x26b0;
		}
		
		$8bitstruct 8bitstruct = malloc(8);
		...
	}
	
	datalist = tmp1_vdata->datalist;
	data = datalist[0]; //datalist[i>>2]; i = 0;
	int ra = tmp1_vdata->chunk_count;
	if (a == ra) { // 1, data[0] == tmp1_vdata->chunk_count
		tmp1_vdata1 = data[1];
		count = tmp1_vdata1->chunk_count;
		int i = 0;
		while(i < count) { // c
			datalist1 = tmp1_vdata1->datalist;
			data1 = datalist1[i];
			int rb = data1[1]; // 9 
			if(b != rb) {
				i++;
			}
			24bitstruct 24bitstr = data1[5];
			tmp1_vdata2 = 24bitstr->vdata;
			if(tmp1_vdata2->chunk_count != 1) {
				datalist2 = tmp1_vdata2->datalist;
				int j = 0;
				while(j < datalist2->chunk_count) {
					16bitstr = datalist2[j];
					int rc = 16bitstr[3];
					if(rc == c) {
						// 這裏和棧上參數做了個對比，之前沒記錄
						// R11, [R7,#0x1C]
						// 另外對比了r10 沒記錄
						// CMP.W           R10, #0
						time = 24bitstr->time; // 0x7A005EB3
						sec = 16bitstr->sec;
						
						int xor = time ^ sec; // B3E94525 // 程序下一步的跳轉地址
						[r11] = xor; // [stack]:BE892148 DCD 0
					}
				}
			}
		}
	}
}