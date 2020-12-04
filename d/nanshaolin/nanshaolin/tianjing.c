// Last Modified by Winder on May. 29 2601
// Npc: /kungfu/class/nanshaolin/tianjing.c

#include "tian.h";
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_yes();
string ask_me();
string ask_murenxiang();

void create()
{
	set_name("�쾵��ʦ", ({ "tianjing dashi", "tianjing", "dashi"}));
	set("long",
		"����һλ�������ɮ����һϮ��˿������ġ�����Ĳ��ߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 120);
	set("max_qi", 30000);
	set("max_jing", 12600);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali",260);
	set("combat_exp", 6000000);
	set("score", 10000);
set_skill("ruying-leg", 360);
		set_skill("zhanzhuang-gong", 360);
	set_skill("shaolin-cuff", 360);
	set_skill("shaolin-leg", 360);
	set_skill("yiwei-dujiang", 360);
	set_skill("boluomi-hand", 360);
	set_skill("jingang-strike", 360);
	set_skill("wuxiang-finger", 360);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 260);
	set_skill("yijinjing", 260);
	set_skill("force", 260);
	set_skill("yijinjing", 260);
	set_skill("dodge", 260);
	set_skill("shaolin-shenfa", 300);
	set_skill("cuff", 260);
	set_skill("hunyuan-yiqi", 300);
	set_skill("luohan-quan", 300);
	set_skill("jingang-quan", 300);
	set_skill("leg", 260);
	set_skill("zui-gun", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("hand", 260);
	set_skill("fengyun-shou", 300);
	set_skill("qianye-shou", 300);
	set_skill("strike", 260);
	set_skill("sanhua-zhang", 300);
	set_skill("sanhua-zhang", 300);
	set_skill("weituo-gun", 300);
	set_skill("banruo-zhang", 300);
	set_skill("finger", 260);
	set_skill("yizhi-chan", 300);
	set_skill("yizhi-chan", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("yizhi-chan", 300);
	set_skill("claw", 260);
	set_skill("qianye-shou", 300);
	set_skill("yingzhua-gong", 300);
	set_skill("longzhua-gong", 300);
	set_skill("staff", 260);
	set_skill("pudu-zhang", 300);
	set_skill("wuchang-zhang", 300);
	set_skill("blade", 260);
	set_skill("cibei-dao", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("club", 260);
	set_skill("zui-gun", 300);
	set_skill("zui-gun", 300);
	set_skill("sword", 260);
	set_skill("damo-jian", 300);
	set_skill("whip", 260);
set_skill("hunyuan-yiqi", 260);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("leg", "nianhua-zhi");

	map_skill("strike", "banruo-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
	map_skill("staff", "wuchang-zhang");
	map_skill("blade", "xiuluo-dao");
	map_skill("club", "zui-gun");
	map_skill("parry", "wuxiang-finger");
  map_skill("parry","wuxiang-finger");
  map_skill("unarmed","wuxiang-finger");
  map_skill("finger","wuxiang-finger");
  map_skill("hand","boluomi-hand");
  map_skill("strike","jingang-strike");
	//prepare_skill("finger", "wuxiang-finger");
	prepare_skill("hand", "boluomi-hand");
	prepare_skill("strike", "jingang-strike");

//set_skill("hellfire-whip", 360);
set_skill("buddha-club", 380);
//set_skill("lunhui-zhang", 320);
set_skill("zhanzhuang-gong", 320);
set_skill("buddhism", 350);
	map_skill("club", "buddha-club");
	//map_skill("whip", "hellfire-whip");
	//map_skill("staff", "lunhui-zhang");
		map_skill("force", "zhanzhuang-gong");
		
	map_skill("dodge", "shaolin-shenfa");
  map_skill("parry","ruying-leg");
  map_skill("unarmed","ruying-leg");
  map_skill("leg","ruying-leg");
	prepare_skill("leg", "ruying-leg");
       
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		
(: perform_action, "club.baifo" :),
(: perform_action, "club.fantian" :),
(: perform_action, "club.pili" :),
(: perform_action, "club.qiankun" :),
(: perform_action, "club.wu" :),
		 (: perform_action, "leg.ruying" :),
		(: exert_function, "powerup" :),
		(: exert_function, "lianhua" :),	
		(: exert_function, "bighammer" :),	
		(: exert_function, "pudu" :),										
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);

	set("inquiry",([
		"ľ����" : (: ask_murenxiang :),
	]));


	create_family("��������", 18, "��ĦԺ����");
	setup();
		carry_object(__DIR__"obj/gclub")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_yes", "yes");
	add_action("do_nod", "nod");
}

string ask_murenxiang()
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query("muren_winner") && !wizardp(me)) 
		return RANK_D->query_respect(me) + "�����Ѿ�����ľ������ô���ɲ�Ҫ�����Ŀ������Ц��";
	if (me->query("combat_exp", 1) < 10000)
		return RANK_D->query_respect(me) + "�Ĺ������������ǲ�Ҫ��ľ����Ϊ�ã�";
//	if (me->query("score") < 10000)
//	        return RANK_D->query_respect(me) + "�������������ǲ�Ҫ��ľ����Ϊ�ã�"; 
	command("look " + this_player()->query("id"));
	command("nod");
	me->set_temp("ask_muren", 1);
	say(HIC"�쾵��ʦ����˵����ľ��������������Ϊ���յ�ȥ��֮һ�����б鲼�ֳ�������ľ�ˣ�\n������ֻ����ǰ�ߣ����޷���֮·������һ����Ҫͣ��̫��ʱ�䡣\n"NOR);
	return "��������Ѷ����͸�����(yes)��\n";
}

int do_yes()
{
	object me = this_player();

	if( !me->query_temp("ask_muren") ) return 0;
	message_vision("$nת������ƿ����ķ��񣬺���¶��һ��С�ţ�\n\n$n�������$N��һ�ƣ���$N�ƽ����ڣ�\n\n$nѸ�ٽ������ƻ�ԭλ��\n\n", me, this_object());
	me->move("/d/nanshaolin/entrance");
	me->look();
	return 1;
}

