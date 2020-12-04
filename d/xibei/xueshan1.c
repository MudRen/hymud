#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","大雪山");
    set("long",@LONG
大雪山山势挺拔，似有冲天之势，山上到处是数十丈厚的积雪和冰川，中间
偶尔露出黑黝黝的山岩；阳光照耀下，夺目耀眼，令人睁不开眼睛。山上寒冷异
常，疾风刺骨，加之气候多变，不时突降大雪，令人难以移步。脚下冰块光滑难
攀，一不留神就会摔倒；四周没有半点生机。
    东边下山是一片广阔的高原草甸和沼泽，湖泊零落棋布。
LONG);
    set("exits",([
        "eastdown"    : __DIR__"xingxiu_hai",
    ]));
    set("outdoors","xibei");
    setup();
}
void init()
{
        object ob;
        ob = this_player();
        if( (int)ob->query("max_neili") > 400) return;
        
        tell_object(ob,BLU "你觉得一阵寒风似乎直吹进了你的骨子里..........\n\n" NOR);
        ob->start_busy(3);
        //ob->apply_condition("ganmao",15);
        return;
}


