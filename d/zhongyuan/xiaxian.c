// xiaxian.c
inherit ROOM;

void create()
{   
    set("short","夏县");
    set("long",@LONG
这里南边也有一座首阳山，当地百姓都认为伯夷、叔齐是在这里不食周栗而
亡的。因此也修起庙、坟祭拜，这里和关中的首阳山，到底哪个是真，无人知晓。
道旁多是农田，种了许多小麦、油菜、花生等等。靠山脚下有几个大庄院，粉墙
黑瓦，颇为气派。
LONG );
    set("exits",([
        "southwest" : __DIR__"zhongtiao_shan3",
        "north" : __DIR__"jiangxian"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
