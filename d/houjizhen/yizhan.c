// yizhan.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "��վ");
	set("long", @LONG
�������һ��ǳ�Ѱ����վ��רΪ��͢���͹�Ա�����ݹ���
֮�ã����û�й���ż��Ҳ����������Ϊ���������ṩʳ�ޡ�
������Ǻ��ֵ���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"shilu6",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
