int __fastcall real_JNI_OnLoad(JavaVM *vm) {
   int result; // r0  
   jclass clazz; // r0 MAPDST   
   int v4; // r0   
   JNIEnv *env; // r4  
   int v6; // [sp-40h] [bp-5Ch]   
   int v7; // [sp+Ch] [bp-10h]  
   v7 = *(_DWORD *)off_8AC00;   
   if ( !vm )     
	   goto LABEL_39;   
   sub_7C4F4();   // 創建全局 jboolean， jinteger、jstring
   env = (JNIEnv *)sub_7C5B0(0);  // 獲取env, goto_getenv()
   if ( !env )     
	   goto LABEL_39;   
   v4 = sub_72CCC();   // goto_do_httpuitl
   sub_73634(v4);   // goto_do_umidAdapter
   sub_73E24(&unk_83EA6, &v6, 49);   // goto_decrypt_entry
   clazz = (jclass)((int (__fastcall *)(JNIEnv *, int *))(*env)->FindClass)(env, &v6);   
   if ( clazz     && 
   (sub_9EE4(),  // goto_create_tmp1vdata_       
   sub_71D68(env), // goto_do_SPUtility2
   sub_E7DC(env) >= 0   // 處理了DeviceInfoCapturer，pack_or_unpack_command
   && sub_69D68(env) >= 0   // 啥也沒乾
   && sub_197B4(env, clazz) >= 0   // 處理了DataReportJniBridgerer，pack_or_unpack_command
   && sub_E240(env, clazz) >= 0    // pack_or_unpack_command
   && sub_B8B0(env, clazz) >= 0    // pack_or_unpack_command
   && sub_5F0F4(env, clazz) >= 0   // pack_or_unpack_command
   && sub_70640(env, clazz) >= 0   // pack_or_unpack_command
   && sub_11F3C(env) >= 0   // 處理android相關類
   && sub_21C3C(env, clazz) >= 0   // pack_or_unpack_command
   && sub_2148C(env, clazz) >= 0   // pack_or_unpack_command
   && sub_210E0(env, clazz) >= 0  //  pack_or_unpack_command
   && sub_41B58(env, clazz) >= 0     //  pack_or_unpack_command
   && sub_27920(env, clazz) >= 0    //  pack_or_unpack_command
   && sub_293E8(env, clazz) >= 0    // 處理ZipUtils、CallbackHelper和android相關類
   && sub_208F4(env, clazz) >= 0) ) // 處理UserTrackMethodJniBridge
   {     
   result = (sub_B7B0(env, clazz) >> 31) | 0x10004;   // 注冊doCommandNaitve
   }   else   { 
   LABEL_39:    
   result = -1;   
   }  
   return result; 
   } 