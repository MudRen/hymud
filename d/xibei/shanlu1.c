inherit ROOM;
void create()
{
    set("short","山路");
    set("long",@LONG
这里已到秦，渭二州交界之处，地势渐高，北面是六盘山，纵伸百余里，过
了六盘山向北一直走，穿过大片边境屯田就是西夏境内了。两边山上不时可见梯
田房舍。
LONG);
    set("exits",([
        "north"   : __DIR__"kongdong_shan",
        "southwest"  : __DIR__"qinzhou_fu",
  ]));
set("outdoors","xibei");
  setup();
}

