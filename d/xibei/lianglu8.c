//lianglu8.c

inherit ROOM;

void create()
{
        set("short", "沙砾路");
        set("long", @LONG
西边是凉州城，城楼高大巍峨，城上有许多兵丁来回巡逻，并不时俯视一下城下过往
的客商和行人。城门口有几个校尉警惕地注视着每一个过路的人，城门边的城墙上贴
着几张捉拿间谍的堞文，显然在这里发生了不寻常的事件.
LONG
        );
        set("exits", ([ 
                "east"          :       __DIR__ "lianglu7",            
             "west"     :       __DIR__"liangzhou/dongmen",
                ])
        );
//      replace_program(ROOM);
        setup();
}

