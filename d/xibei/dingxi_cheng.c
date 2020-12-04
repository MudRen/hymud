inherit ROOM;
void create()
{
    set("short","定西军城");
    set("long",@LONG
定西军城内驻扎有上万官军，城高墙厚，是一处著名的军事要塞。自从修了
此城，西夏，吐蕃军队很少再敢深入洮，岷等州抢掠。以定西称为基地，向北百
余里遍布军寨，相互呼应。东面是一条宽阔的驿道一直通向秦州府，北边的道路
逐渐变窄，两边都是农田。
LONG);
    set("exits",([
        "east"   : __DIR__"yidao9",
        "north"  : __DIR__"tuntian1",
    ]));
        set("objects", ([
                __DIR__"npc/keshang" : 2,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                ]) );
 set("outdoors","xibei");
    setup();
}

