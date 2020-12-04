 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "太室阙南");
        set("long", @LONG
这座高近四米的石阙，是嵩山三座汉阙中保存最为完好，时代
最古老的一座，南面刻有“中岳太室阳城”六个纂字，还有汉隶和
纂隶参半的铭文，阙身四面有各类画像五十余幅，是绝世瑰宝。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"zhongyue", 
]));
        set("outdoors", "songshanfy");
        set("coor/x",-180);
        set("coor/y",100);
        set("coor/z",0);
        set("objects", ([
                __DIR__"obj/shique" : 1,
                __DIR__"npc/xian1" : 1,
       ]) );
        setup();
        replace_program(ROOM);
}    
