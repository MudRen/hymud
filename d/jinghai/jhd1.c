// Room: /d/jinghai/jhd1.c
#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;


void create()
{
	set("short", "��������ͷ");
	set("long", @LONG
̤�����СС����ͷ��������鲻���������������⵹����
ȫ����Ϊ�����ĺ��ľ��������̳�����������С���ϣ�������
����ͷ��һƬ�ں�������ľ������Χ��������ֻ�ճ��򺣵�һ��
���ӷ��ܵ������Ͽ�ȥ��һ�������͵�ʯɽֱ����ʣ���ɽ�Ķ�
��Ƭʯ��бб�������������Ψһ�ĳ��ڣ�����һֻ���˶��׵�
���������������������ʳ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jhd2",
  "west" : __DIR__"jhd3",
]));

	set_boat_file(__DIR__"dum_ws");
	set_max_passenger(6);
        set("outdoors","jinghai");

	setup();
	//replace_program(ROOM);
}
