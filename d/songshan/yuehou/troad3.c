// /d/yuehou/troad3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������Ľֵ����ֵ������в�������������ڽ�����
�ò����֡��������������������С��ڣ�������һ����լ����
���߻��ǽֵ���
LONG
        );

       set("exits", ([
                "west"             : __DIR__"wenter",
                "east"             : __DIR__"troad4",
                "south"             : __DIR__"house1",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

