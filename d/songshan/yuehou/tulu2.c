// /d/yuehou/tulu2.c

inherit ROOM;

void create()
{
        set("short", "��·��ͷ");
        set("long", @LONG
��������᫵���·�ľ�ͷ��Զ���ƺ���ʲô�������ֿ����塣
LONG
        );

       set("exits", ([
                "south"             : __DIR__"tulu",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

