// Room: /d/jinghai/moon1.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "��������ͷ");
	set("long", @LONG
վ�ں��ߣ���ᷢ�������и����塣��������ɽ�³ʰ�����
һֱ���ӵ���������ĺ�ˮ�峺���ף���ɫ���˻������ų��
�ź����ߵ���ʯ����������������������ˡ�һ��ľ���ɵ���
ͷ̤�����������ͣ������ֻСľ����һ��С·ͨ��������
���ɽ�¡�С·����һ���ª��Сé���ڷ���ҡ���š�
LONG
	);
	set("outdoors", "jinghai");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/boy1" : 1,
  __DIR__"npc/fisher1" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"moon37",
  "west" : __DIR__"moon22",
  "northwest" : __DIR__"moon2",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(10);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫȥ��½������\n");

	setup();
}

// �����������ʹ�������˲���Ǯ
protected int valid_passenger(object who)
{
	if(who->query("class") == "jinghai")
	{
		who->set_temp("payed_duchuan", 1);
		return 1;
	}

	else return ::valid_passenger(who);
}
