 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "长老院");
        set("long", @LONG
东林历代以来，除方丈外，还有四位护寺长老，武功必须绝高，且佛
法精深，四长老执掌僧监，维护东林安全和声誉，辈分不在方丈之下，具
传现在这四位长老是东林千年来最出色的四位，近五十年来还无人能逃出
东林僧监。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"laon",
  "southwest" : __DIR__"laos",
  "west": __DIR__"jian",
]));
        set("objects", ([
                __DIR__"npc/master_17_2" : 1,
       ]) );
        set("coor/x",-180);
        set("coor/y",380);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}      
