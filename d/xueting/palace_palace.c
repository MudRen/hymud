// Room: /u/palace/palace_palace.c

inherit ROOM;

void create()
{
	set("short", "���˶�");
	set("long", @LONG
����ʯ����ֻ����ľ�״У��滨���ף�һ���������ӻ�ľ�
к��ʯ϶֮�¡�������֮��������Ϫк��ʯ���ƣ���ʯΪ����
�������ӣ�ʯ�����ۣ��������¡�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
//	__DIR__"master/quest-man" : 1,
	]));
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 2 */
	"westdown" : __DIR__"palace_front",
]));
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
