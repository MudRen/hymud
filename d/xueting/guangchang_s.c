// Room: /d/xueting/square_s.c
inherit ROOM;
void create()
{
        set("short", "�㳡�ϲ�");
        set("long", @LONG
������ѩͤ��㳡���ϱߣ�������������һ��ߴ����������
��������Ϊ�����γ�һ��ʮ���ɼ����Ĵ�յء��ֵ�����ͨ�����⣬
���߲�Զ���м�������ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sstreet1",
  "north" : __DIR__"guangchang",
  "west"  : __DIR__"guangchang_sw",
  "east"  : __DIR__"smithy",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}
