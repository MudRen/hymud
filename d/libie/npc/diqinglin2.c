#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("������", ({ "di qinglin","di","qinglin" }) );
        set("long",
                "һ��ѩ�׵����ѣ�һ����Ⱦ��һ�Ų԰���������ϣ����Ǵ������䵭����
�ı��顣������ӹ��������糾����ȴ�������������������ĵ�С��ү��\n"); 
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 20);
        set("age",27);
        set("str", 100);
        set("cor",50);
        set("agi",50);
        set("cps",75);
        set("con",70);
        set("title", HIY"��Ϯһ�Ⱥ�"NOR); 
        set("combat_exp", 3000000+random(1000000));
        set("max_neili",2000);
        set("force",2000);
        set("force_factor",50);
         
        set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 50);
        set("combat_exp", 9800000);
        set("score", 180000);

        set_skill("lamaism", 250);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 380);
        set_skill("sword", 120);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 280);
        set_skill("hand", 280);
        set_skill("cuff", 280);
        set_skill("yujiamu-quan", 380);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 320);
        set_skill("xue-dao", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");


if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
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
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
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
"���������ᶶ����һ����Ⱦ��ѩ�׳��£����ͻȻ����һ������Ц�⡣��\n"
}) );

        setup(); 

        carry_object(__DIR__"obj/shirt")->wear();
        carry_object(__DIR__"obj/thinblade")->wield();
} 
void init()
{
        ::init();
        add_action("do_sitdown","sitdown");
        add_action("do_answer","answer");
} 
int kill_him(object ob)
{
        if(!ob||environment(ob)!=environment())
                return 0;
        message_vision(HIC"�������$N΢΢��̾�˿������������Ǿ��Ʋ��ԳԷ��ơ�������\n"NOR,ob);
        //dont allow player answer now
        ob->delete_temp("answering");
        kill_ob(ob);
        ob->kill_ob(this_object());
        return 1;
} 
int greeting(object ob)
{
        message_vision(HIY"��������$N΢һ��ף�˵����������sitdown������\n"NOR,ob);
        call_out("kill_him",10,ob);
        return 1;
} 
int do_sitdown(string arg)
{
        object me=this_player();
        
        message_vision(HIW"$N�ϻ̳Ͽֵ������������ϡ�\n"NOR,me);
        message_vision(HIC"�������������$N�ʵ�������λ"+RANK_D->query_respect(me)+"���ٱִ�������Ϊ�������һ�ٰ�ʮ��������������
��answer yes/no��\n"NOR,me);
        me->set_temp("answering",1);
        remove_call_out("kill_him");
        call_out("kill_him",10,me);     
        return 1;
} 
int player_leave(object me)
{
        message_vision("�����뽫$N�ϳ��������\n",me);
        me->move("/d/libie/corrider");
        return 1;
} 
int do_answer(string arg)
{
        object me=this_player();
        
        if(!me->query_temp("answering"))
                return 0;
        if(arg=="yes")
        {
                remove_call_out("kill_him");            
                if(me->query("libie/���_С���ӵľ���"))
                {
                        message_vision(HIW"�������Ȼ΢Ц��������������Ҳ����ô���ѡ���\n"NOR,me);
                        message_vision(HIR"�����벻����İ���һ����ߵ�һ�����棬$N���µ����ź�Ȼ����֨֨�����졣\n"NOR,me);
                        if(me->query("libie/���_����ү������"))
                        {
                                tell_object(me,HIW"������һ������Ȼ������ү�Ľ��档\n"NOR);
                                message_vision(CYN"$N��æ����������ֻ�������µĵذ��Ȼ������ȥ��¶����һ���ڶ����������붴�У�һ���Ӿ���ʧ�ˡ�\n"NOR,me);
                                message_vision(HIY"������΢΢һ㵣��漴��΢Ц�Ŷ�$N�������ο࣬��ʵ����ʹ�෴����һЩ��������\n"NOR,me);
                                this_object()->kill_ob(me);
                                me->kill_ob(this_object());
                        }
                        else
                        {
                                message_vision(HIC"�����µĵ����Ȼ�ѿ���$Nֻ������һ�ᣬ��ֱ׹��ȥ����\n"NOR,me);
                                message_vision(RED"������ڶ���һ˲�䣬$N�����Ϻ�Ȼ��¶���ޱȿ־�ı��飬��Ϊ$P�����ľ�������������������
���޷�����Ŀֲ�������\n"NOR,me);
                                me->set("qi",-1000);
                                me->move("/d/libie/void");
                   }
                        return 1;
                }
                else
                {
                        message_vision(HIC"�������Ȼ��Ц��������ô�����������飬ֻ�����Ǹ���˰ɡ���\n"NOR,me);
                        me->set_temp("libie/СҶ��ɱ",1);
                        call_out("player_leave",2,me);
                        return 1;
                }
        }
        if(arg=="no")
        {
                remove_call_out("kill_him");            
                message_vision(HIC"�������������Ȼ��������ˡ�������ˣ����߰ɡ���\n"NOR,me);
                call_out("player_leave",2,me);
                return 1;
        }
        return 0;
}
int return_home(object home)
{
        destruct(this_object());
        return 1;
} 
             
