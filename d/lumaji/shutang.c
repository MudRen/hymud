// Room: /d/lumaji/shutang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǵ���Ψһ����ʶ�ֵĵط�������������ǰ�Ǹ��̻���
���ڰ���ŵ����������顣������˶�ûʲô�Ļ�����������Ҳ
ֻ��һЩ�򵥵Ķ���������շ�Ҳ�ܵ͡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu8",
]));
	setup();
	replace_program(ROOM);
}
