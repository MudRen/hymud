// Room: /city/nandajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ʮ�ﳤ��");
	set("long", @LONG
ʮ�ﳤ��ԭ�������ݵ����ģ�����֮�����ֱ߲�����¥����������
��ֿ��꣬���ַǷ���ÿ��ҹ������ʱ����Ҹ߹ҵ�������ҹ��������
�𲻾�����������浽����ÿ�س���Ϧ�������ɴ���������Ի����п�
�С������ڽֱߵĵ��̶�����³ǣ�ʮ�ﳤ�ֵķ��ٽ�������ѷɫ���࣬
����Ϊ�������ݵ�Ҫ������������ӵ��������������������һ�����ֵ�
�㳡��������һ�ҵ��̣�ǽ��д��һ�����ġ������֣���ϸ����������
����ѹ�͵��ּۻ��۵���������������һƬ�����������š�һ��һʮ����
��Ǯ����ԭ�����Ƿ�Բǧ��֮������һ�Ҷĳ���
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west"  : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
	]));

	setup();
	replace_program(ROOM);
}
