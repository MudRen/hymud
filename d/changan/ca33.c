// Room: /d/changan/ca33.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���ȹر�Ӫ");
	set("long", @LONG
������ǹź��Źء���������ɽ���������򣬹�����С�����
ǿ��һ��֮�أ��ƹض������������Զ�������ɨ���£�������Ϊ
���ݴˣ����ɹ����˿��أ���������ʤ֮������������������Ҳ��
�ڴ�����������¾���ǧ�����£��������ж�������
LONG
);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ca32",
//  "east" : "/d/quanzhen/dadao1",
]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
