// Room: /d/huijiang/yixiangting.c
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","����ͤ");
	set("long",@LONG
����һ�����ɱ��µ�Сͤ�����顰����ͤ�������֣�����ͦ����Ȼ
���ǳ¼�����ֱʡ��Ա߼���С��д���ǣ���������ʱ��Ѫ����ʱ��
һ������޶Ͼ�����Ү��Ү����Ϊ���������¼��������������㹫����
ʱ�򣬳�һ�������˶�����
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"east" : __DIR__"zoulang2",
	]));
	set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([
		CLASS_D("honghua")+"/chen-jialuo" : 1,
		"/quest/menpai/newmp/shi1" : 1,
"/d/biwu/champion_hua":1,
		__DIR__"obj/xiangcha" : 2,
		__DIR__"npc/dizi" : 4,
		__DIR__"obj/dianxin" : 1,
	]));
	set("coor/x", -50080);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	tell_object(me,	"                         ");
	tell_object(me,	YEL"����������\n"NOR);
	tell_object(me,	"                         ");
	tell_object(me, YEL"��"NOR);
	tell_object(me, HIG"����ͤ"NOR);  
	tell_object(me, YEL"��\n"NOR);
	tell_object(me,	"                         ");
	tell_object(me,	YEL"����������\n"NOR);
}
