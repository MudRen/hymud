// Room: /d/zuojiacun/mujiang.c

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
���Ǵ����ľ���꣬��������˸������ε��ӣ����������
���Ա�æ����š�һ����ʮ���������վ��һ��ָָ��㣬����
�������ϰ�����ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu16",
]));
  	set("objects",([
	__DIR__"npc/mujiang" : 1,
]));
	setup();
	replace_program(ROOM);
}
