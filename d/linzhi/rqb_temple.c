// Room: /d/linzhi/rqb_temple.c

inherit ROOM;

void create()
{
	set("short", "���ձ���");
	set("long", @LONG
���ձ�����ī��������Ժ��λ��ī�Ѵ���������ɽ�ϡ�
����ʱ�������ŰͶ�Ǩ�󲻾ã����Լ8���ˡ��ݴ����ɸʲ�
���еĻ��ʲ������ģ������һ����12��ǽ�Ͷ����ϱ���
�ŵ�ʯľ�ṹ���㽨�������жƽ�ͭ���������

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lin28",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/monk3" : 1,
  __DIR__"npc/monk4" : 1,
  __DIR__"npc/lama2" : 1,
__DIR__"npc/xintu2" : 2,  	
]));
	setup();
	replace_program(ROOM);
}
