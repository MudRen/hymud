inherit ROOM;
void create()
{
    set("short","驿道");
    set("long",@LONG
渭河上游的水灌溉着这一带广阔的农田，田野里多种着高粱和谷子；一到秋
天便是望不到边的一片火红。这里已是秦州地界，是关西一带人口稠密，地产富
饶的宝地。南边是起伏不断的秦岭与岷山；北面远处隐隐有一带群山。
LONG);
    set("exits",([
        "east"   : __DIR__"yidao1",
        "west"  : __DIR__"qinzhou_fu",
    ]));
 set("outdoors","xibei");
    setup();
}

