// /d/map/zhongyuan/tulu.c

inherit ROOM;

void create()
{
    set("short", "土路");
    set("long", @LONG
一条黄土路蜿蜒的向远方延伸着，一眼看不到尽头。路的两边都是水田和鱼
塘，稻花醉人的清香随风飘扬。淮南是有名的「鱼米乡」，这里水网纵横，河湖
众多，在阳光的照耀下如同镶嵌在大地上的缎带和真珠般闪闪发亮。蔚蓝的天空
中飘着朵朵白云，远处丘陵淡淡的青影波浪般地起伏。
LONG
       );
    set("exits", ([ 
        "west"      : __DIR__"chuzhou/dong_men",
        ///"east"      : "/d/place/xkdao/tantu1",
    ]));
    set("outdoors", "zhongyuan");
    setup();
}

