// /d/yuehou/wenter.c

inherit ROOM;

void create()
{
        set("short", "С���");
        set("long", @LONG
�������������С��ڣ�·��������һ��ʯ��������д�š�
�������������֣���˵�����������������̵�ʱ������������
���
LONG
        );

       set("exits", ([
                "west"             : __DIR__"troad2",
                "east"             : __DIR__"troad3",
]) );
        set("objects", ([
                "/clone/npc/man" : 2,
        ]));
       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

