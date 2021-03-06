 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","普照寺");
  set("long",@LONG
普照寺兴于六朝，有一株六朝松做历史见证，寺内清幽古雅，飘逸
绝俗，每日暮鼓晨钟，虽不大，但是庄严不减，寺内松柏映照，除了那
六朝松之外，更有一株“一品大夫松”，比普照寺更加久远，历代君王
但凡信佛者，来泰山封禅后必到普照寺进香礼佛，所以普照寺香火之盛，
也是一时无俩。 
LONG
  );
  set("exits",([
        "eastdown" : __DIR__"hongmen",
               ]));
        set("objects", ([
        __DIR__"obj/tree" : 1,
        __DIR__"npc/lengqingping" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",300);
        set("coor/y",2380);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}    
