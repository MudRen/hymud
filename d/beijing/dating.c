#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������������ػ���ľ�ô�����ֻ��һ�Ű����Ϲ�������
���ƣ��м�һ��д�š���������֮λ�������һ��д�š�������ƽ����
֣֮λ����������һ���ľ (baimu)��������������ȫ��Ѫ�֡�������
һ������(duilian)�������ǲ������ϱ����ǰ�����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"andao10",
		"north" : __DIR__"tuzai",
		"east"  : __DIR__"ceting",
		"west"  : __DIR__"lianwu",
	]));
	
set("roomif","$botten#��������|��������|���˷���|�������:ask jinnan about job|ask jinnan about work|ask jinnan about ʧ��|ask jinnan about done$#");
	
	set("item_desc", ([
		"baimu" : 
HIR "\n  ֻ����ľ��д����������У��ظ����������˵�ͬ��������\n"
"����԰���£�ԼΪ�ֵܣ��պ�����������Ϊһ�ҡ�����Ϊ����\n"
"�ݵ�Ϊĸ, ��Ϊ�֣���Ϊ��ã��������ģ�һѩǰ�ܣ�˳��\n"
"�е����ָ��������ѪΪ�ˣ�����������\n" NOR,
	"duilian":
HIC "\n����߸ԣ�һ��Ϫɽǧ����\n" NOR +
HIG "�ų��󺣣����Ӻ�ˮ������\n" NOR,
	]));
        set("objects", ([
                "quest/menpaijob/yunlong/chen" : 1,
                "/kungfu/class/yunlong/dizi" : 2,
                "/d/biwu/champion_yl":1,
        		__DIR__"npc/yldizinew" : 2,
        ]));

	set("coor/x", -212);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	"/clone/board/tiandihui_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir== "north")
		message("vision","գ�ۼ䣬���׳���ͻȻ����һ���ˡ�\n","/d/beijing/tuzai");
	return ::valid_leave(me, dir);
}