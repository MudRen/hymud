//er2.c

inherit ROOM;

void create()
{
        set("short","������");
        set("long", @LONG
һ�����ߺ촰������,��ɮ������Ӻʹ��������ĵط�.
LONG
        );
        set("exits", ([ 
                "west"          :       __DIR__ "tingyuan",
                ])
        );
//      replace_program(ROOM);
        setup();
}

