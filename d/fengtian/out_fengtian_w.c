
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/fengtian/out_fengtian_w.c

inherit ROOM;

void create()
{
	set("short", "ʢ����������");
	set("long", @LONG
�ߵ�����͵���ʢ���ˡ�������ʢ���������ţ������پ���
�̲��Ź��������ˡ�������ȥ��һ����ֱ����ʯ�ٵ���
LONG
	);

	set("exits", ([
	"east" : __DIR__"w_gate",
  "west" : "/d/menggu/caoyuan4",
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
	&& (dir == "east") )
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
