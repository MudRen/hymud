// xinjiang.c
inherit ROOM;

void create()
{   
    set("short","新绛");
    set("long",@LONG
这里也曾是晋国的国都，想当年文公重耳逃难四方，流离廿载，直到年过半
百才登上君位，得以施展鸿图，将晋国发扬光大，南敌蛮楚，西抗强秦，成就一
代霸业，最终不过是一场过眼烟云，黄梁酣梦而已。如今哪里还有什么城的痕迹？
LONG );
    set("exits",([
        "south" : __DIR__"jiangxian",
        "northeast" : __DIR__"fenhe_gudi1"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
