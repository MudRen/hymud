// /d/yuehou/troad4.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������Ľֵ����ֵ����Ե��������Ƿ�æ����������
��פ�㣬�����Լ����ճ����衣������������һ��С���£���
���ǽֵ�����ͷ��������һ���ӻ��꣬������С��㳡��
LONG
        );

       set("exits", ([
                "north"             : __DIR__"tupo",
                "west"             : __DIR__"troad3",
                "east"             : __DIR__"tcenter",
                "south"             : __DIR__"house2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

