// Room: /d/jinghai/jhd7.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ڷ��ܵ��������У�����������˵�еľ��˹�һ�㣬��
��������Ѳ�֪�����˼�������ÿһ�ö�����ʮ�ɸߣ��㲻����
����̾���츫��֮���档ż��һ�����������������ܵľ��ף�
�ƺ���Ϊ���������һ�����ص����ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"westup" : __DIR__"jhd8",
	"east" : __DIR__"jhd3",
	"enter" : __DIR__"mi1",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
