// Room: /d/china/junying/xiaozhen/xianjing.c

inherit ROOM;

void create()
{
	set("short", "������Դ");
	set("long", @LONG
�ߵ���������ǰ��Ȼ���ʣ�û�뵽��ɽ֮��û�����ط���
����滨����ݡ�������������������������һ����ݣ�һλ
�뷢�԰׵��������������յ����ڲ���ǰ��ε�������ϼ������
Ʈ��������һ���˼��ɾ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xianjing_entry",
]));

	

	set("objects",([
	__DIR__"npc/xiaoyao_weng" : 1,
]));
	setup();
	replace_program(ROOM);
}
