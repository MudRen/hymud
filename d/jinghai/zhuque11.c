// Room: /d/jinghai/zhuque11.c

inherit ROOM;

void create()
{
	set("short", "�Է�");
	set("long", @LONG
����һ����ܰ���ʵ��Է������ĺ�ľ���������������
һ��ССױ̨��ױ̨�Աߵ�ǽ����ȴ����һ��һ�˶�ߵ�ͭ����
���ߵ���ǰ������һ���Լ������ָ�ƽ���޽ǵ��ҷ���[����]��
����һ���ٴ��������򿪴������ƺ��������������İ���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"zhuque9",
]));
        
        set("sleep_room", 1);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
