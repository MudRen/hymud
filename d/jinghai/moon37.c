// /d/jinghai/moon37.c

inherit ROOM;

void create()
{
        set("short", "��̲��");
        set("long", @LONG
������һƬǳ̲�����ڸ���һ������ˮ�ݷ�ʢ�����������
��Ϻ�ܶ࣬�ر���һ�ֺ���ÿ�궼�����������ѣ�������һ�ֵ�
ˮ�㣬��������ϸ�ۣ�ζ���ǳ������������������ĺ��Ӻ�Ů
�˾������������� (lao)���㣬��Ҳ���԰ɣ���˵�еõط�ר��
�չ������㡣
LONG
);

	set("exits",([
	"northwest" : __DIR__"moon1",
]));

        set("outdoors", "jinghai");

        setup();
}

void init()
{
	add_action("do_lao","lao");
}

int do_lao(string arg)
{
        object me = this_player();

        if( !arg && arg != "��" && arg != "fish")
		return 0;

	if (me->query("class") != "jinghai")
		return notify_fail("����������һ��ˮ�³��㺰���������Ǿ����ĵ��̣����˲���������㣡��\n˵�Ű������е����������ˡ�\n");

	if (me->query("jing") < 10 || me->query("kee") < 10 || me->query("sen") < 10)
		return notify_fail("������������������������ûʲô�����ˡ�\n");

	me->start_busy(3);
	message_vision("$NŤ���粽��һʹ�����������˳�ȥ��\n",me);
	call_out("finish_lao",3,me);

	return 1;
}

void finish_lao(object me)
{
	if(!objectp(me))
		return;

	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
	me->receive_damage("qi",10);

	message_vision("$N������ʲôԤ�У�Ѹ�ٵĽ��������˻�����\n",me);
	if(random(10) < 7)
	{
		object ob;
		int n;

		ob=new(__DIR__"obj/shiban");
		write(sprintf("���������﷭�˷�������������һ��%s��\n",ob->name()));

		if(!ob->move(me))
			ob->move(this_object());
		ob->set("time",time());
		if(me->query("combat_exp") < 25000)
		{
			n = 10 + random(30);
			write(sprintf("\n��õ��� %d �㾭�顣\n\n",n));
			me->add("combat_exp",n);
		}
	}
	else
		write("���������﷭�˰��췢��ʲôҲû�С�\n");
	me->stop_busy();
}
