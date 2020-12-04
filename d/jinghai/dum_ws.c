// Room: /d/path2/duchuan.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"


inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "ս��");
	set("long", @LONG
����һ���ܴ��ս����ľͷ�ṹ��������������ʮ���˵�����
��վ������ңң�λΣ����˸о��ܲ���ʵ��
LONG
	);
	
	set("no_clean_up",1);
	set("invalid_fuji", 1);

	set_boat_master(__DIR__"npc/sy_zm");
	set_boat_bank1(__DIR__"wm1");
	set_boat_bank2(__DIR__"jhd1");
	set_bank1_desc("������");
	set_bank2_desc("������");
	set_cross_msg("�ɺ�");

	setup();
}
