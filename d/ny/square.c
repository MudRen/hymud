
// Room: /d/snow/square.c

inherit ROOM;

void create()
{
        set("coor",({0,4750,10}));
       set("my_point","��Զ��");
        set("short", "��Զ�����Ĺ㳡");
        set("long",
"��������Զ�ǽֵ������Ĺ㳡�Ŀյأ����������������ʯ�塣�㳡������һ��ľͷ��ļ�\n"
"�ӣ���������ķ紵��ɹ���ܣ������ǳ��ƾɡ����ܽ�����������������Կ���һ���ջ��\n"
"���������ƺ��ܺá�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad1",
  "west" : __DIR__"inn",
  "northwest" : __DIR__"mstreet1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"temple",
]));
        set("outdoors", "ny");

        setup();
}

