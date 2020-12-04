// Room: /d/fengtian/out_fengtian_s.c

inherit ROOM;

void create()
{
	set("short", "ʢ����������");
	set("long", @LONG
�ߵ�����͵���ʢ���ˡ�������ʢ���������ţ������پ���
�̲��Ź��������ˡ����Ͽ�ȥ��һ����ֱ����ʯ�ٵ���
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"s_gate",
  "south" : "/d/yanjing/to_yj3",
]));
        set("objects",([
        	__DIR__"npc/jinbing" :3,        	
        ]));

	set("outdoors","fengtian");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "north") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("ͻȻ�ӱ�������������ʿ˵�����Ҵ�%s���Ǻ��ˣ���Ĳ��ͷ�����\n",
				inv[0]->query("name")));
	}
	return ::valid_leave(ob,dir);
}
