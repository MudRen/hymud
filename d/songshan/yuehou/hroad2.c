// /d/yuehou/hroad2.c

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ����Ţ�Ļ���·�����ڸո��¹��꣬���Կ�������
�ǳ�ʪ��·�ϵ����˴Ҵ�ææ�ĸ�·���ƺ�û����ע�⵽�㡣
LONG
        );

       set("exits", ([
                "north"             : __DIR__"hroad1",
                "east"             : __DIR__"troad1",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

