// jiangxian.c
inherit ROOM;

void create()
{   
    set("short","绛县");
    set("long",@LONG
周武王讨伐商纣，建立赫赫八百年大周天下。他死后，成王将他的弟弟封在
这一带地方，号称“晋国”。春秋诸侯纷争，晋侯曾经在这里建都。站在土岗上
放眼看去，尽是漫漫黄土，几许轻烟人家，旧屋残垣，却哪里还有什么城池的痕
迹？
LONG );
    set("exits",([
        "south" : __DIR__"xiaxian",
        "north" : __DIR__"xinjiang"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
