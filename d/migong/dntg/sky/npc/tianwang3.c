//modified by vikee
//2000.10
inherit NPC;
#include "huoyannpc2.h"

string send_me(object me);
void create()
{
        set_name("ħ����", ({ "moli qing", "zengzhang tianwang", "qing", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"��������Ϊ�Ĵ�����֮��, ��߶����ĳ�, ����һ�˳�ǹ, \n"
		"ǹ���Ƿ��켫, �����ܴ������Ʊ�����, ���أ�ˮ���𣬷硹\n"
		"��ʽһ��, ���޽���Ҳ���ӡ�\n"
	);
	set("age",50);
	set("title", "��������");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_qi",1100);
	set("qi",1100);
	set("max_jing",1100);
	set("jing",1100);
	set("combat_exp",2000000);
    set("daoxing",1500000);
	set("neili",2500);
	set("max_neili",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 80);
	set("mana_factor",80);
	
    
    set("nkgain", 800);
	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
	set("inquiry", ([
		"name" : "������������ħ���࣬��ʥ�Ͱ��������š�",
		"here" : "�������������, ���ھ�������ˡ�",
		"��ȥ": (: send_me :),
		"back": (: send_me:),
	]) );

	setup();
	carry_object(__DIR__"obj/dragonstick")->wield();
	carry_object(__DIR__"obj/jinjia")->wear();
}

string send_me(object me)
{
        me=this_player();
	        if( me->is_fighting() )
		return ("���������鷳�����Ҫ���㣡\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
		return ("æ����˵�ɡ�����\n");

	message_vision("��������������Ц����$N˵����������������ȥ��\n", me);
	message_vision("������������һ�Ű�$N������ȥ������\n", me);
        me->move("/d/city/guangchang");
	tell_room( environment(me), "�����ˡ�һ���������ϵ��¸�������\n", ({me}));
	write("�������ˤ�����������˸��������ף�\n");
	return ("�Ϸ��������������\n");
}

void hurting(object me, object ob)
{
   remove_call_out("hurting");

   if(environment(me)!=environment(ob) || !me->is_fighting()) return;
   me->command_function("perform chaofeng");

   call_out("hurting",5+random(6),me,ob);
}

