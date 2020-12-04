// yidao11.c
inherit ROOM;

void create()
{   
    set("short","驿道");
    set("long",@LONG
驿道穿过太行山的崇山峻岭，从晋阳城直通到真定府。一路上山道崎岖，乱
石遍地，走起来十分艰难。两边时而是高高的山峰，时而是陡峭的山坡；路转难
尽，又时而面临一片平坦的河滩田地，清澈的河水缓缓流动。
LONG );
    set("exits",([
        "west" : __DIR__"yidao10",
        "northeast" : __DIR__"yidao12" ]) );
    set("outdoors","zhongyuan");
    setup();
}

