// Room: /d/fengtian/smith.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����̵�¯�����ĺ�������һ�߽��͸о�һ�������������
����������������Ӻ�����Ĵ�����������Ȼ�Ǳ������о�����
̫���ˡ��ſڹ���һ��С����(ban)��
LONG
	);

	set("item_desc",([
	"ban" : "�߼��չ����������ף�������(pei)Կ�ף�����(xiuli)������\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wy6",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
