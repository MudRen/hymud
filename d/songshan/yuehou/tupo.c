// /d/yuehou/tupo.c

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
������һ��С���£���˵ԭ����һ��ɽ�𡣴�����������
Լ���Կ���һ������
LONG
        );

       set("exits", ([
                "south"             : __DIR__"troad4",
                "north"             : __DIR__"tupo2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

