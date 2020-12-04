// yidao1.c
inherit ROOM;

void create()
{   
    set("short","驿道");
    set("long",@LONG
这条驿道穿行晋北诸州，自太原直抵雁门关，是朝廷为巩固雁门关防守而特
地修筑的，路宽一丈，尽除碎石岩砾，即使纵马奔驰也不会出事。驿道弯弯曲曲
穿插在山谷之中，东边是系舟山，西边是云中山，道上不时有骑兵乘马飞驰而过，
激起满地的尘土。
LONG );
    set("exits",([
        "south": __DIR__"jinyang_chengxia",
        "east" : __DIR__"yidao2" ]) );
    set("outdoors","zhongyuan");
    setup();
}

