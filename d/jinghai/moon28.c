// Room: /d/jinghai/moon28.c

inherit ROOM;

void create()
{
	set("short", "�ܵ���");
	set("long", @LONG
������һ����խ�Ĺ���������ͨ���η���Ψһͨ�����ı���
������ʯ���ɡ��ܵ���ֻ��ǽ���ϵ�С�͵ƣ�����谵��ʪ��
ż�����������еδ�δ����ˮ������������û��һ�����졣��
�����ˡ�ǽ����������һ���ִܴ��[����]���ܵ��򱱼�������
�š�
LONG
	);
       set("item_desc", ([ 
	"����" : "����(climb)���ԡ�/n",
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"moon29",
]));

	setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();

	if( !arg && arg != "����" && arg != "shengzi")
		return 0;
        message_vision("$N˫������ץס���ӣ�����һ�������ʵǶ�ȥ��\n",me);
        me->move(__DIR__"moon23");

        return 1;
}
