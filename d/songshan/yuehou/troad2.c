// /d/yuehou/troad2.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
������һ��С��·��С·��Χ����Ұ���������������ߣ�
���ܿ���������Ĵ�ڡ�
LONG
        );

       set("exits", ([
                "north"             : __DIR__"troad1",
                "east"             : __DIR__"wenter",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

