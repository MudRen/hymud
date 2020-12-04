#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��ʦ", ({"da fashi","fashi"}) );
        set("gender", "����" );
        set("class", "taoist");
        set("nickname", HIR"ʳ������"NOR);
        set("long", "һ��̬�Ⱥ���������ˣ����Ŷ�Բ���Ķ�ǩ��һ��Ѫ������ĳ���\n���أ�ѩ�׵ĺ���ʹ���������������𾴡�\n");
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("fly_target",1);
        set("cor", 35);
        set("cps", 3);
        set("age", 54);
      set("max_qi",  18000);
        set("max_jing", 18000);
        set("neili", 35000);
        set("max_neili", 35000);
        set("jiali", 100);
        set("combat_exp", 8500000);
        set("score", 500000);

        set_skill("necromancy", 380);
        set_skill("force", 200);
        set_skill("xiaowuxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("strike", 320);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 380);
        set_skill("literate", 100);
        set_skill("staff", 100);
        set_skill("xiangmo-chu", 380 );
        set_skill("strike", 300 );
        set_skill("huoyan-dao", 380);
	set_skill("dashou-yin", 320);
	        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        set("combat_exp", random(800000)+2500000);
        
        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
        
if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ʦ�ٺ�Ц����С������ⲻ���óԣ������̲��úܡ�\n",
        }) );
        set_temp("apply/armor", 50);
        setup();
        carry_object(__DIR__"obj/cassock")->wear();
        carry_object(__DIR__"obj/hat")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
} 
void greeting(object ob)
{   
        if (ob->query("gender") == "Ů��")
        {
                message_vision("$N���ſ�ˮ������$n����ϸƤ����ģ��ظ�һ���ܺóԡ���\n", this_object(),ob );
                this_object()->kill_ob(ob);
        }
        return;
} 
