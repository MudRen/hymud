/* yumenguan.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */
#include <ansi.h>
inherit ROOM;

void CloneCorpse();

void create()
{
    set( "short","玉门关外" );
    set( "long",@LONG
玉门关是西域通往中原的一个重要关卡。这里气候干燥，日照强烈，周围又
都是沙漠、戈壁，寸草不生，故王之涣有诗云“羌笛何须冤杨柳，春风不渡玉门
关”。抬头四望，眼前无树无草，只有青灰色的石子单调地铺满地面；戈壁、沙
漠中蒸腾起来的蜃气，构成了一幅幅幻景。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"desert/shamo0",
        "southeast" : __DIR__"dunhuang",
        "south"  : "/d/qilian/yumenguan",	
    ]) );
    set( "outdoors","silk");
    setup();
}

void init()
{
    object me = this_player();
    me -> set( "hydra/desert/from","中原" );
    if ( !random(5) )
    {
        CloneCorpse();
    }
    if ( me->query_temp_marks("is_riding") == "只野骆驼" )
    {
        write( MAG"野骆驼见你走出了沙漠，轻轻把你掀在地上，一转身，消失茫茫沙漠中。\n"NOR);
        me->delete_temp_marks("is_riding");
    }
}

void CloneCorpse()
{
    object ob,corpse;
    ob = new(__DIR__"npc/compass");
    corpse = new("/clone/misc/corpse");
    corpse ->set("name","干枯的尸体");
    corpse ->set("long",@LONG
一具干枯的尸体，显然是在沙漠中水分消耗光，好不容易挣扎出了
沙漠，缺还是死了。
LONG
    );
    corpse->set_max_encumbrance( 1000 );
    corpse->move(this_object());
    ob->move(corpse);
}
