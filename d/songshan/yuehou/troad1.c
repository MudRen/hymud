// /d/yuehou/troad1.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
������һ��С��·��С·��Χ����Ұ���������������ߣ�
����ͨ��������Ĵ���ˡ�
LONG
        );

       set("exits", ([
                "west"             : __DIR__"hroad2",
                "south"             : __DIR__"troad2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}


