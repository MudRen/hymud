inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
��������̨�ɴ���ʯ������ÿ���ʯ����ü���ƽ����������Ϊ��
��������������ģ�������£��ƿ����ʣ����費������Ŀ��������ң
���ɸ����ţ��ƺ�����һ�ߣ��������������������ڣ����϶��ǵ�����
ɽ��
LONG );
	set("exits", ([
		"eastdown" : "/d/songshan/fengchantai",
	]));
	set("objects", ([
                "/d/jinyong/book8/songshan/npc/linghu" : 1,
		"/d/jinyong/book8/songshan/npc/moda" : 1,
		"/d/jinyong/book8/songshan/npc/yu" : 1,
		"/d/jinyong/book8/songshan/npc/yue-buqun" : 1,
		"/d/jinyong/book8/songshan/npc/zuo" : 1,
		"/d/jinyong/book8/songshan/npc/renwoxing" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
