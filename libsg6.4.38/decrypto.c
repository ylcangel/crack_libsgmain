struct dcryptdata {
	void* v;
	int caseno;
	void* v1;
	void* decryptdata_;
	struct vdata* key;
	struct vdata* cryptedata;
}

decryptdata_ 取值 820000 880000 890000  

int decrypto(struct dcryptdata* decryptdata_, int* a2) {
// 传递两个参数 一个代表待解密结构体，一个代表返回码
// 应该是解密算法
// 内置n种解密算法
// 如rc4
// 解压缩等
// 传递两个参数
// 应该是解密算法
// 内置n种解密算法
// 如rc4
// 解压缩等
  int caseno; // r1@3
  int result; // r0@4

  *a2 = 820000;
  if ( !decryptdata_ || !decryptdata_->cryptedata || (caseno = decryptdata_->caseno, (unsigned int)v5 > 0x1B) )
  {
    result = 0;
    *a2 = 890000;
    return result;
  }
  v3 = 880000;
  result = 0;
  switch ( caseno )
  {
    case 0x10u:
    case 0x11u:
    case 0x12u:
      result = ((int (__fastcall *)(void *))unk_A409A4F8)(decryptdata_->v);
      break;
    case 3u:
      result = ((int (__fastcall *)(struct vdata *, struct vdata *))unk_A409DEEC)(decryptdata_->key, decryptdata_->cryptedata);
      break;
    case 0x14u:
      result = ((int (__fastcall *)(void *, struct vdata *))unk_A409E31C)(decryptdata_->v, decryptdata_->cryptedata);
      break;
    case 0x15u:
      result = ((int (__fastcall *)(void *, struct vdata *, _DWORD *))unk_A409A998)(decryptdata_->v, decryptdata_->cryptedata, v4);
      break;
    case 0x16u:
      result = ((int (__fastcall *)(struct vdata *))unk_A409AF3C)(decryptdata_->cryptedata);
      break;
    case 0x17u:
      result = ((int (__fastcall *)(struct vdata *, struct vdata *))unk_A409AE54)(decryptdata_->key, decryptdata_->cryptedata);
      break;
    case 0x18u:
      result = ((int (__fastcall *)(struct vdata *))unk_A409BD48)(decryptdata_->cryptedata);
      break;
    case 0x19u:
      result = ((int (__fastcall *)(struct vdata *))unk_A409DE84)(decryptdata_->cryptedata);
      break;
    case 0x1Au:
      result = (int)sub_A409E338((int)decryptdata_->v, (int)decryptdata_->v1, (int)decryptdata_->cryptedata, v4);
      break;
	      default:
			result = 0;
			*a2 = 880000;
			return result;
  }

  if ( result ) {
	 result = 0;
	*a2 = 0;
	return result;
  }

  return 0;
}