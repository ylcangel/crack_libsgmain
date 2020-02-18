int __fastcall doCommandNative(JNIEnv *env, jobject obj, int command, jarray args) { 
  int v5; // r5   
  struc_2 *a5; // r6  
  int v9; // r1   
  int v11; // [sp+Ch] [bp-14h]   
  int v12; // [sp+10h] [bp-10h]   
  v5 = 0;  
  v12 = *(_DWORD *)off_8AC00;  
  v11 = 0;   a5 = (struc_2 *)malloc(0x14u);  
  if ( a5 )   {   
  a5->field_0 = 0;    
  a5->field_4 = 0;   
  a5->field_8 = 0;   
  a5->field_C = 0;   
  v9 = command % 10000 / 100;  
  a5->field_0 = command / 10000;   
  a5->field_4 = v9;   
  a5->field_8 = command % 100; 
  a5->field_C = env;    
  a5->field_10 = args;  
  v5 = sub_9D60(command / 10000, v9, command % 100, 1, (int)a5, &v11);  
  }   
  free(a5);   
  if ( !v5 && v11 )    
	  sub_7CF34(env, v11, &byte_83ED7);  
  return v5; 
  } 