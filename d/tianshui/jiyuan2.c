// Room: /u/xiaozhen/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������.ÿ���岽�����Ҹ�һ�š��������м�
�ţ��ź�����������ÿ��ʮ�������һյ������������
����ϸ�������ƺ�ÿ���տա�����������������ǰ��
չ��һ����������ͷ���ſ�����һ������(pai)��
LONG
	);
	//set("no_steal",1);
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"ji4",
  "down" : __DIR__"jiyuan",
  "west" : __DIR__"ji2",
  "north" : __DIR__"ji1",
  "south" : __DIR__"ji3",
]));

	set("item_desc",([
	"pai" : "
ÿ�����Ӫҵ��

��ͨ����(putong)   ��������
��Χ����(yinwei)   ʮ������
��Χ����(jinwei) ��ʮ������

�����԰�(order)���ֻ���\n\n"
]));

	//set("NORIDE",1);
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/gui_nu" :1,
  __DIR__"npc/m_boss" :1
]));
	setup();
}

void init()
{
	add_action("do_accept","accept");
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int do_accept(string arg)
{
	object obj,me = this_player();
	if(!me->query_temp("jiyuan/order")) return 0;
	if(!arg) return notify_fail("��ū˵����Ҫ����λ���\n");
	if(!obj = present(arg,this_object()))
		return notify_fail("��ū˵����Ҫ����λ���\n");
	if(!obj = present(arg,this_object())
	|| obj->query("class") != "jiyuan"
	|| obj->query("gender") != "Ů��"
	|| obj->query("id") == "m_boss")
		return notify_fail("��ū˵����Ҫ����λ���\n");
	me->delete_temp("jiyuan/shangqian");
	me->set_temp("jiyuan/shangqian",obj->name());
	message_vision("$N��ɬ��һƳ$n���εε�˵��лү������ū������ү�ܲ�����ū�����ٽ����䡣\n",obj,me);
	return 1;
}


int valid_leave(object me,string dir)
{
	object obj;
if (userp(me))
{
	if(dir == "down" && userp(me))
	{
	if(!me->query_temp("jiyuan/order")) return 1;
	call_out("zou_ren",2);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
        return ::valid_leave(me,dir);

	}
}
        return ::valid_leave(me,dir);

}

void zou_ren()
{
	object obj;
	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
	if(obj = present("wan xiang",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
	if(obj = present("xiang yu",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
	if(obj = present("hong xiu",this_object())) {
		tell_object(this_object(),obj->name()+"���ˡ�\n");
		destruct(obj);
		}
}
