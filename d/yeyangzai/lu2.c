// Room: /open/stst/sazai/lu2.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
        ����ͨ�����䳡��·����������㻹�Ǳ�����Ϊ�á��ϱ���һ��
С·�������������䳡�ˡ�

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lianwu",
  "south" : __DIR__"lu1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
