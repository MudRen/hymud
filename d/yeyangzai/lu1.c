// Room: /open/stst/sazai/lu1.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
        ����ͨ�����䳡��·����������㻹�Ǳ�����Ϊ�á�������һ��
С·�����Ͼ���կ���ˡ�

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu2",
  "south" : __DIR__"men",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

