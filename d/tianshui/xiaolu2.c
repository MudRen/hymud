// Room: /d/tianshui/xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С·��·�߳�������ݣ�������м��겻֪���Ĺ�
ľ��ż��С�紵��һ��ɳɳ�����졣��������ˮ��Ķ���ңң��
����һ����·�����졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaolu1",
  "east" : __DIR__"xiaolu3",
]));
	set("item_desc",([
	"��ľ" : "һ��Ͱ��Ĺ�ľ��ϡ���Ҷ���ﳤ�ż��ź���С���ӡ�\n",

]));
	set("num",3);
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
}

void init()
{
	add_action("do_zhai",({"zhai", "pick"}));
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