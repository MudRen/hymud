// Room: /d/jinghai/jhd21.c

inherit ROOM;

void create()
{
	set("short", "�Է�");
	set("long", @LONG
�����Ǿ����ɿ�ɽ��ʦ֮һ���������ķ������¹�����ң�
����Ĳ������൭�š�ȴ�ֲ�ʧ�ˬ֮�磬�ַ��˺ųƶ�������
�����书��ԣ���������������������ض��ã������ھ����ɼ�
�����ж��кܸߵ�������
LONG
	);

	

	set("sleep_room", 1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jhd20",
]));

	setup();
	replace_program(ROOM);
}
