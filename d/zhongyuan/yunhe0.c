// /d/map/zhongyuan/yunhe0.c
// by lala, 1997-12-11
inherit ROOM;

void create()
{   
    set("short","真楚运河边");
    set("long",@LONG
离开楚州城，行人走在真楚运河的岸边。所谓真楚运河，就是北起楚州入淮，
南至真州入江的一段运河，是南北大运河最重要的一段。这里运河纵贯淮南大地，
成为河网中的主动脉，不时有小河道汇入。淮南是重要的产盐区，大批的盐船满
载着食盐向长江下行而去，它们准备在运河南端的真州和由江南运河上行而来的
运载漕米的粮船交换它们的货物，然后再掉头驶向来路。
LONG );
    set("exits",([
        "north"     : __DIR__"chuzhou/nan_men",
        "southeast" : __DIR__"yunhe1",
        "west" : __DIR__"guandao12",	
    ]));                    
    set("outdoors","zhongyuan");
    setup();
}

