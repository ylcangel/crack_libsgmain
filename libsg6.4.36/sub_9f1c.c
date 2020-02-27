struct global_command_entry { // 記錄著生成和執行command的核心方法
	void* goto_make_command_entry; // 對應sub_9B3C; 生成command結構核心算法
	void* goto_do_command1; // // 對應sub_9d82; command_native_inner
	void* goto_do_command2; // 對應sub_9e7e; 和sub_9d82差不多
};

signed int make_global_command_ptr()
{
  struct global_command_entry *v0; // r4@2
  signed int result; // r0@2

  if ( !get_global_command_entryptr() ) // 全局
  {
    v0 = (global_command_entry *)malloc(12);
    result = 0;
    if ( !v0 )
      return result;
    v0->goto_do_command1 = 0;
    v0->goto_make_command_entry = 0;
    gcommand_vdata1 = goto_create_tmp1vdata_(0); // 全局，記錄有關command結構指針
    gcommand_vdata2 = goto_create_tmp1vdata_(0); // 全局，記錄有關command結構指針
    v0->goto_make_command_entry = sub_B3E74A98;
    v0->goto_do_command1 = sub_B3E74DF4;
    v0->goto_do_command2 = sub_B3E74E48;
    set_global_command_entryptr(v0);
  }
  return 1;
}