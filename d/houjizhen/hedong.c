// hezhong.c
// by dicky

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "ˮ�׶�Ѩ");
    set("long", @LONG
���������񣬽���ˮ�׶�Ѩ������û��̫��Ĺ��ߣ�ֻ��ģģ����
�Ŀ���һЩ������ͻȻ��һ��Ȼ���������˹�������æ�˹��ֿ���ͻ��
�����������в�����Щ���š�
LONG
        );

	set("outdoors", "houjizhen");

	set("exits", ([
		"out" :  __DIR__"hedi",
	]));

        set("objects",([
		__DIR__"npc/eyu" : 1,
	]));

	set("outdoors", "houjizhen");
	setup();
}