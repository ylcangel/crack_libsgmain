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


static main(void)
{ // 所有JNI_OnLoad 函數，以及我認爲重要的函數斷點
	auto bpt;

	auto libsgmain_base = 0;
	auto base = GetFirstModule();
	auto name = GetModuleName(base);
	auto size = GetModuleSize(base);

	while(1) {
		base = GetNextModule(base);
		name = GetModuleName(base);
		size = GetModuleSize(base);
		if (strstr (name, "libsgmainso-6.4.36.so") != -1) {
			libsgmain_base = base;
			Message("libsgmain_base = %x\n", libsgmain_base);
			break;
		}
	}
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x7B86C); // create_command_vdata
	Breakpoints.Add(bpt);
	Message("call create_command_vdata %x\n", (libsgmain_base + 0x7B86C));

	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x73ed8); // goto_dcrypto
	Breakpoints.Add(bpt);
	Message("call goto_dcrypto %x\n", (libsgmain_base + 0x73ed8));

	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x73eec); // memcpy
	Breakpoints.Add(bpt);
	Message("call memcpy %x\n", (libsgmain_base + 0x73eec));
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x9a14); // build_command
	Breakpoints.Add(bpt);
	Message("call build_command %x\n", (libsgmain_base + 0x9a14));
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x9D82); // do_command_native_inner
	Breakpoints.Add(bpt);
	Message("call memcpy %x\n", (libsgmain_base + 0x9D82));
	
  
    bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x7C4F4); // 創建全局objects
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x7C5B0); // goto_getEnv
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x72CCC); // goto_do_httpuitl
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x73634); // goto_do_umidAdapter
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x73E24); // goto_decrypt_entry
	Breakpoints.Add(bpt);

	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xb534);
	Breakpoints.Add(bpt);

	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xb538);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x69D68);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x197B4); // goto_do_DataReportJniBridgerer
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xE240);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x9EE4);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x71D68); // goto_do_SPUtility2
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xE7DC); // DeviceInfoCapturer
	Breakpoints.Add(bpt);
	
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xB8B0);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x5F0F4);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x70640);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x11F3C); // android 原生類處理， context pm pkgmgr appinfo
	Breakpoints.Add(bpt);
	
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x21C3C);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x2148C);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x210E0);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x41B58);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x27920);
	Breakpoints.Add(bpt);
	
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x29918);
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x293E8); // unZip android pm appinfo
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x208F4); // do UserTrackMethodJniBridge
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xB7B0); // env->registerNatives
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0xB69C); // doCommandNative
	Breakpoints.Add(bpt);
	
	bpt = Breakpoint();
	bpt.set_abs_bpt(libsgmain_base + 0x9D60); // goto_docommand_native_inner
	Breakpoints.Add(bpt);
	
}
