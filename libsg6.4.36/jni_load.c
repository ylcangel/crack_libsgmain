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