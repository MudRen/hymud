// /d/yuehou/tulu.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
������һ����᫵���·��·����������һЩ��ľ����Ϊû��
�����ݣ�·��ǳ�����Ţ������������·�ľ�ͷ������������
��㳡�ı��ࡣ
LONG
        );

       set("exits", ([
                "south"             : __DIR__"center_n",
                "north"             : __DIR__"tulu2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

