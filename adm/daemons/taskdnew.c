// #pragma optimize
// #pragma save_binary

inherit F_DBASE;

#include <ansi.h>

int clean_up() { return 1; }

void auto_relaim();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�ڴ澫��");
        CHANNEL_D->do_channel( this_object(), "sys", "�ڴ澫���Ѿ�������");
        //call_out("auto_relaim", 40);
}
