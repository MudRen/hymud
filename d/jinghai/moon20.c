// Room: /d/jinghai/moon20.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ˮկ��կ�������ң����ڰڷ��ż��Ŵ�ľ�崲��
ǽ�Ϲ���һ�ź������Ӳ������֪����ʲô�������ɵġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"moon9",
]));

	
        set("sleep_room", 1);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
