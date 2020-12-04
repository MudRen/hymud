// Room: /d/snow/guangchang.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "�㳡����");
        set("long", @LONG
������ѩͤ��㳡�����룬һ��޴���������̸�����վ��
���룬һЩ��ͯ������������������Ϸ���������ߺ�����ط�����
�ų��ʹ���ЪϢ���죬���Ի���һ��ˮ�׹�·��ȡˮ��ʡ�
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/gammer" : 1,
        ]));
        set("all_water",200);
        set("item_desc", ([ /* sizeof() == 2 */
                "����": "����������˵Ҳ�����������ˣ�һ������������������������棬
������Ϊ�������˸������Եù⻬��
",
                "����": "ʮ����ͨ�����ĳ��ʣ���������ˣ����ؿ�����������������Ϣ��
",
]));
        set("exits", ([ /* sizeof() == 4 */
                "east"  : __DIR__"guangchang_e",
                "north" : __DIR__"guangchang_n",
                "west"  : __DIR__"guangchang_w",
                "south" : __DIR__"guangchang_s",
        ]));
        set("outdoors", "xueting");
        setup();
}
/* void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object obj;
      //  object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "����" ) 
	{
        message_vision("$N��������������������ȥ��\n", this_player());
        if( this_player()->move(__DIR__"tree") )
                message("vision", this_player()->name() + "����������������\n",
                environment(this_player()), this_player());
        return 1;
	}
   	else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
*/
void init()
{
	add_action("do_drink", "drink");
	add_action("do_climb", "climb");
}

int do_drink(string arg)
{
	object me = this_player();

	if(query("all_water") <= 0)
		return notify_fail("ˮ����һ��ˮҲû���ˡ�\n");

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");

	message_vision("$N��ˮ�ױ��ñ���Ҩ��ˮ���˼��ڡ�\n", me);
	me->add("water", 20);
	add("all_water",-1);
	if(query("all_water") <= 0)
		return notify_fail("ˮ���Ѿ�������ȸ��ˡ�\n");
	return 1;
}
int do_climb(string arg)
{
        if( arg!="����" ) return 0;
        message_vision("$N��������������������ȥ��\n", this_player());
        this_player()->move(__DIR__"tree");
        message("vision", this_player()->name() + "�������µ�����������\n",
                environment(this_player()), this_player());
        return 1;
}