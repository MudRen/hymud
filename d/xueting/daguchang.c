// work.c
//
inherit ROOM;
void create()
{
        set("short", "��ʯ�̵�");
        set("long", @LONG
����һ���ʯ�̵꣬ѩͤ�򱱱��¿�����һ���󳡣���������
��Դ���Ǻܳ���ġ������������ѡ����ʯȻ��ȥұ���ɽ�����Ʒ��
ǽ�Ϲ���һ�����ӣ�Sign�������߾���ѩͤ��Ľֵ���
LONG
);
       set("no_beg",1);
       set("no_sleep_room",1);
       set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"street02",
]));
	        set("objects",([
	__DIR__"npc/kuangshiboss" : 1,
]));
        set("item_desc", ([
                "sign": @TEXT
������۸��ֳ����Ŀ�ʯ��
TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
    setup();
}