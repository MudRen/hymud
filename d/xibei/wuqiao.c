//wuqiao.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ѿ������˺������ȵĶ����.

LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "lianglu3",            
                "northwest"     :       __DIR__ "lianglu5",
                ])
        );
//      replace_program(ROOM);
        setup();
}

