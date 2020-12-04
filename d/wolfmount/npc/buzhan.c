 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��ս", ({ "master bu", "master" }) );
        set("nickname", HIW"ս����"NOR);
        set("gender", "����" );
        set("apprentice_available", 5);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("age", 46);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_neili", 200);
        set("force", 200);
        set("force_factor", 30); 
        set("long",
                "�����Ź������Ȼ�������ƣ�ȴ������˵�������������š�\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
                "��սһ�ֽ������ź���ǹ�����ǰ�ú���������ң�˭ɱ������ɱ�ǳ�\n���⣬�Ϸ���������ڡ�\n",
        }) );
        create_family("��ɽ", 3, "��ͷ��");
         set("rank_nogen",1); 
        set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,RED"��˧"NOR,HIR"��ɽ��"NOR }));
        set("combat_exp", 2200000);
        	set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
      	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        setup();
        carry_object(__DIR__"obj/silkcloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
       carry_object(__DIR__"obj/mysterypicture"); 
} 
void reset()
{
        set("apprentice_available", 5);
} 
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ�����ɽ�ӵ�,ͬ����֦,�����������꣡\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
