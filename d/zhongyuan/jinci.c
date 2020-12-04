// jinci.c
inherit ROOM;

void create()
{   
    set("short","晋祠");
    set("long",@LONG
这里已经是太原府的辖境了。路边有一座朱墙大院，院前木栅门两边摆着兵
器执事，院门的两边各一头清石狮子，黑漆大门上悬着一块镏金大匾，上书“子
乔祠”三个大字。这就是晋祠，是纪念周文王之弟，晋国始祖叔虞而建的。
LONG );
    set("exits",([
        "southwest": __DIR__"fenhe_gudi8",
        "northeast" : __DIR__"jinyang_chengxia"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
