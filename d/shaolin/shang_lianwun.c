inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�������̼ұ������һ�����䳡�������ĳ�����������ϸϸ
�Ļ����������ʺ����䡣���������Ӳݴ������������Ѿ��ķϺ�
��һ��ʱ���ˡ�������һ����(men)��
LONG);
	set("exits", ([
		"south"  : __DIR__"shang_houyuan",
	]));
	setup();
	//replace_program(ROOM);
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/north"))
		return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("laofang key", this_player())))
//	if (!(ob = present("lywintwo", this_player())))
		return notify_fail("�㲻��������\n");
	set("exits/north", __DIR__"shang_dongxiang");
	message_vision("$N��һ��Կ�״������ţ�����Կ��ȴ���ˡ�\n", this_player());
	destruct(ob);
	return 1;
}