// #pragma optimize
// #pragma save_binary

inherit F_DBASE;

#include <ansi.h>

int clean_up() { return 1; }

void auto_relaim();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "内存精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "内存精灵已经启动。");
        //call_out("auto_relaim", 40);
}
