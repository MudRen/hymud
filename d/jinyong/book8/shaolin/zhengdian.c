// Room: /d/shaolin/dxbdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µĴ��۱�����й������������������Ҹ���
���⡢����������һȺ����С���������ڷ���ǰ�ĵ����о���
�����������󳪽�����һ�����ӷ����黨ǳЦ�����ݣ����˶�
ʱ���𼸷�����֮�С���߾�����һ�Ӷ�ɮ�������룬������
�ֳֽ䵶���ƺ���Ѳ�µ�ɮ�ˡ�
LONG );
	set("exits", ([
		"south" : "/d/shaolin/dxbdian",
	]));
	set("objects",([
		__DIR__"npc/yu" : 1,
		__DIR__"npc/chongxu" : 1,
		__DIR__"npc/fangzheng" : 1,
		__DIR__"npc/renwoxing" : 1,
		__DIR__"npc/xiang" : 1,
	]));
	setup();
}
