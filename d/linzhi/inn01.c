// Room: /d/linzhi/inn01.c

inherit ROOM;

void create()
{
	set("short", "�͵�����");
	set("long", @LONG
�����ǿ͵����������������İڷ������Ρ�һЩ��������
���ƳԷ������ǹ�̨����һ���ƹ�ģ���������ڵ�ͷ���ʣ�����
С����æ����赹ˮ�������������һ��¥��ͨ��¥�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"inn",
  "eastup" : __DIR__"inn03",
  "westup" : __DIR__"inn04",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/dawa" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
