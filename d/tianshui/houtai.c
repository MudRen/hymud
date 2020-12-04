// design by ���ֺ�(find) . all right reserved.

// Room: /u/xiaozhen/houtai.c

inherit ROOM;

mapping xingtou = ([
"zhuge" : 1,
"zhangfei" : 1,
"guanyu" : 1,
]),

cname = ([
"zhuge" : "�����",
"zhangfei" : "�ŷ�",
"guanyu" : "����",
]),

skill = ([
"zhuge" : "literate",
"zhangfei" : "fork",
"guanyu" : "blade",
]);

int max_skill = 45;

string query_xt();

void create()
{
	set("short", "��̨");
	set("long", @LONG
�����Ǻ�̨��һ�ų����Ϸ���һ��ͭ����������Ϸ���ǻ�ױ
�õģ����Ϸ���һЩ��ͷ(xingtou)����֪�����Ǹ�ʲô�õġ�
LONG
	);
	set("no_clean_up", 1);

	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"taishang",
  "east" : __DIR__"xitai",
]));

	set("item_desc",([
	"xingtou" : (: query_xt :),
]));
	

	set("zhuge","�����(zhuge) ");
	set("zhangfei","�ŷ�(zhangfei) ");
	set("guanyu","����(guanyu) ");
	set("numpu",3);
	setup();
}

void init()
{
	add_action("do_ban","ban");
	add_action("do_quit","quit");
}

int do_ban(string arg)
{
	object me = this_player();

	if(!arg || arg == "" || undefinedp(xingtou[arg]))
		return notify_fail("��Ҫ������λ���\n");

	if(me->query_temp("tianshui_playing"))
		return notify_fail("���Ѿ�����ױ�ˡ�\n");

	if(!xingtou[arg])
		return notify_fail(sprintf("%s�������Ѿ�����ȡ���ˡ�\n",cname[arg]));

	if(me->query_skill(skill[arg],1) > max_skill)
		return notify_fail(sprintf("���Ѿ�����ͨ����Ϸ����%s�ˡ�\n",to_chinese(skill[arg])));

	xingtou[arg] = 0;

	message_vision(sprintf("$N����%s�����ף����軭��һ���������%s��\n",cname[arg],cname[arg]),me);

	me->add_temp("apply/name",({ cname[arg] }));
	me->set_temp("tianshui_playing",arg);

	write("�ǲ���Ӧ����̨��(chang)һ�Σ�\n");

	return 1;
}

int valid_leave(object who,string arg)
{
	string play;

	if( arg == "eastup" )
	{
		if(!who->query_temp("tianshui_playing"))
			return notify_fail(sprintf("Ϸ��ͷ��ס�����ȥ·������λ%s�ɱ���̨����ѽ����\n",
				RANK_D->query_respect(who)));
		if( who->query_temp("on_rided") )
			return notify_fail("Ϸ��ͷ������˵��������ľͷ���Ϸ̨�ɽ���ס������������ŵ㡣\n");
		return 1;
	}

	if(arg == "east")
	{
		if(!userp(who))
			return 1;

		if(stringp(play = who->query_temp("tianshui_playing"))
		&& !undefinedp(xingtou[play]))
		{
			xingtou[play] = 1;
			message_vision(sprintf("$N��%s�����׷��˻�ȥ��\n",cname[play]),who);
			who->delete_temp("tianshui_playing");
			who->delete_temp("apply/name");
			return 1;
		}
	}

	return 1;
}

int do_quit(string arg)
{
	string play;

	object who = this_player();

	if(stringp(play = who->query_temp("tianshui_playing"))
	&& !undefinedp(xingtou[play]))
	{
		xingtou[play] = 1;
		message_vision(sprintf("$N��%s�����׷��˻�ȥ��\n",cname[play]),who);
		who->delete_temp("tianshui_playing");
		who->delete_temp("apply/name");
	}
	return 0;
}

string query_xt()
{
	int n;
	string *who;

	if(!(n = sizeof(values(xingtou) - ({ 0 }))))
		return "����ԭ������Ϸ���ǻ�ױ�õ����ף��������Ѿ�û���ˡ�\n";

	who = keys(xingtou);

	return sprintf("�������%s�����ף������Ϸ������Ϸʱ���ģ�
�У�%s%s%s
���ǲ���Ҳ���԰���(ban)��һλ��̨���ԣ�\n",
	chinese_number(n),
	xingtou[who[0]]?sprintf("%s(%s) ",cname[who[0]],who[0]):"",
	xingtou[who[1]]?sprintf("%s(%s) ",cname[who[1]],who[1]):"",
	xingtou[who[2]]?sprintf("%s(%s) ",cname[who[2]],who[2]):"",
);
}

void do_xie(object who)
{
	string play;

	if(!objectp(who) || !userp(who))
		return;

	if(stringp(play = who->query_temp("tianshui_playing"))
	&& !undefinedp(xingtou[play]))
	{
		xingtou[play] = 1;
		who->delete_temp("tianshui_playing");
		who->delete_temp("apply/name");
	}
}
