// /d/yuehou/tcenter.c

inherit ROOM;

void create()
{
        set("short", "С��㳡");
        set("long", @LONG
������������Ĺ㳡���㳡���в���С�̷����Ÿ���������
����һЩ�������й䡣����������С��ı��棬���ǹ㳡��
�࣬������һ��С������
LONG
        );

       set("exits", ([
                "north"             : __DIR__"center_n",
                "west"             : __DIR__"troad4",
                "east"             : __DIR__"center_e",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

