// Room: /d/jinghai/moon21.c

inherit ROOM;

void create()
{
	set("short", "���Ⱦ�ͷ");
	set("long", @LONG
˳�������ߵ����������û��·�ˡ�����֣���������
�ȵľ�ͷ�������ǽ����������ձ��ѣ�������������ţ���
���Ĺ����У�����Լ���������ǽ�Ͽ���һЩ[ʯ��]ʯ������
���Ǹ���ħ�������������Ÿֲ档���˲������ʯ��ͻ����
ǽ�档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"moon9",
]));

	setup();
}
void init()
{
        add_action("do_an","an");
}

int do_an(string arg)
{
        object me = this_player();

	if( !arg && arg != "ʯ��" && arg != "shixiang")
		return 0;
	message_vision("����ͻȻ�ѿ�һ������$N�о�����һ��������ȥ��\n",me);
	me->move(__DIR__"moon28");
	return 1;
}
