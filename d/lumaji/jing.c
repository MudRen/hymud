// Room: /d/lumaji/jing.c

inherit ROOM;

void create()
{
	set("short", "ˮ��");
	set("long", @LONG
���Ǵ�����е�һ��ˮ����������ʯש������һ����̨����
����һ��ľ�Ƶ���񡣴�����˶��������ˮ����Ҫ�ǿ��ˣ���
���������Щˮ��(fill)��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu3",
]));
	set("outdoors", "lumaji");
        set("resource/water",1);
	setup();
	replace_program(ROOM);
}
