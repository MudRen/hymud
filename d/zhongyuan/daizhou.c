// daizhou.c
inherit ROOM;

void create()
{   
    set("short","代州");
    set("long",@LONG
代州已经是北方前线，四周皆是崇山峻岭，凡是山高视广之处，皆建有敌楼
风火台。由于平地稀少，居民不多，只在山坡上稀稀落落的有些农田，房舍都是
破破烂烂的。倒是山坡上不时有一群山羊在有限地吃草。东边山腰上是代州城，
小而坚固。北边就是雁门关了。
LONG );
    set("exits",([
        "southwest": __DIR__"yidao4",
        "northwest": __DIR__"yanmen_guan",
        "northeast": __DIR__"shanlu1" ]) );
    set("outdoors","zhongyuan");
    setup();
}

