// Room: /d/linzhi/lin40.c

inherit ROOM;

void create()
{
	set("short", "�ϻ����ٲ�");
	set("long", @LONG
���������ֻ����ն�к�������������ӵ�����׹����գ�
������ʯ����ն�ϣ���ʱѩ�˷ɽ�������ǧ�򴮶��ߵ����飬��
������׹�벻���׵���Ԩ������ˮȴ�����������������������
���ĺ������·�����Ͽ�ȶ��ڲ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lin39",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
