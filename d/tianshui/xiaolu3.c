// Room: /d/tianshui/xiaolu3.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С·��·�߳�������ݣ�������м��겻֪���Ĺ�
ľ��ż��С�紵��һ��ɳɳ�����졣��������ˮ��Ķ���ңң��
����������һƬ�ݵء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaolu4",
  "west" : __DIR__"xiaolu2",
]));
	set("item_desc",([
	"��ľ" : "һ��Ͱ��Ĺ�ľ��ϡ���Ҷ���ﳤ�ż��ź���С���ӡ�\n",

]));
	set("num",3);
	set("outdoors", "tianshui");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_zhai",({"zhai", "pick"}));
}

int do_push(string arg)
{
        object me;
        if(!arg || arg=="") return 0;
        if( arg != "grass" && arg != "���" && arg != "��") return 0;

        me = this_player();
        message_vision("$N����·�ߵ���ݣ�������һ���򱱵�·��\n", me);
        if( !query("exits/north") )
        set("exits/north", __DIR__"enter_hole");
        call_out("close_path", 5);
        return 1;
}

int do_zhai(string arg)
{
	object obj;
	if(!arg || arg == "")
		return notify_fail("��Ҫժʲô��\n");
	if(arg != "С����" && arg != "����")
		return notify_fail("��Ҫժʲô��\n");
	if(!query("num"))
		return notify_fail("С�����Ѿ���ժ���ˡ�\n");
	message_vision("$N����ժ����һ��С���ӡ�\n",this_player());
	add("num",-1);
	obj = new(__DIR__"obj/guozi");
	obj->move(this_player());
	return 1;
}

void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","һ��С�紵������·����û�����ˡ�\n",this_object() );
        delete("exits/north");
}
