// xiaocui.c

#define DATONG	"/d/datong/"

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("С��", ({ "xiao cui" }) );

	set("gender", "Ů��" );

	set("age", 17);

	set("long","����һλʮ�߰����СѾ�ߡ�\n");
	set("combat_exp", 100);

	set("no_kill", 1);
	set("attitude", "friendly");

	set("inquiry",([
	"�·�" : (: ask_me :),
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me(object who)
{
	string *pos = ({DATONG"huayanlu1",DATONG"shizilukou",DATONG"hongchanglu5",DATONG"hongchanglu1"}),where;
	object room,ob;

	if(!who->query("quest/shaolin_quest/win_zhuge"))
		return 0;

	if(who->query("quest/shaolin_quest/asked_yahuan"))
	{
		write(sprintf(CYN"%s˵�������Ǹ������Ѿ��ͳ�ȥ�ˣ�����Ҳû�á�\n"NOR,name()));
		return 1;
	}

	where = pos[random(sizeof(pos))];
	room = find_object(where);
	if(!room)
		room = load_object(where);
	if(!room)
		return 0;

	if(!objectp(ob = new(__DIR__"blind_beggar")))
		return 0;

	write(sprintf(CYN"%s˵����Ŷ����˵������ү�Ǽ�����С�˵����·����Ǽ��·���ү
          �þö������ˣ��ֲ�����ϴ��ǰ����������ľ��·�һ
          �𶼲�ʩ���������ؤ�ˡ��Ǽ��·��Ҽǵú����Ǳ�һ
          ��Ϲ������ؤ�����ˡ���ȥ���Ұɡ�\n"NOR,name()));

	who->set("quest/shaolin_quest/asked_yahuan",1);
	who->add("quest/shaolin_quest/hint",sprintf("      %s\n",
		"С��������·���һ����ͬ���ġ�Ϲ����ؤ�������ˡ�"));

	ob->move(room);
	tell_room(sprintf("%s���˹�����\n",ob->name()));

	return 1;
}
