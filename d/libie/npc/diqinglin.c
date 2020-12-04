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
        carry_object(__DIR__"obj/letter2");
} 
void init()
{
                if( !query_heart_beat(this_object()) ) set_heart_beat(1);
//              ::init();
} 
void heart_beat()
{
        object di,yang,room,ying;
        int rival;
        
        ::heart_beat();
        di=this_object();
        room=environment();
        yang=present("yang zheng",room);
        if(query("yang_die"))
        {
                ying=present("ying wuwu",room);
                di->start_call_out( (: call_other, di, "kill_ying" ,di,ying:), 3);
                delete("yang_die");
        }
        if(rival=query("begin_rival"))
        {
                if((rival==4)||(rival==3))
                        command("nod");
                if(rival==2)
                        command("say ֻҪ������������ı�������ң�����������ģ��ҵ���Ҳ����ģ��㶼���Դ��ߡ�");
                if(rival==1)
                {
                   di->kill_ob(yang);
                        yang->kill_ob(di);
                        call_out("do_busy",5,di);
                        delete("begin_rival");
                } 
                yang->add("begin_rival",-1);
        } 
        
        
        if (objectp(yang))
        if (di->is_fighting(yang))
        if (random(3)==1&&!yang->query_busy()&&query("do_busy"))
        {
                message_vision(RED"\n$N����һת��������$n��۵�����Ѩ�ϣ�$nֻ��������飬��Ҳ���ܶ��ˡ�\n"NOR,di,yang);
                yang->start_busy(200);
        }
} 
int do_busy(object di)
{
        di->set("do_busy",1);
        return 1;
} 
int kill_ying(object di,object ying)
{
        object room,who;
        
        room=environment(); 
        if(objectp(ying))
        {
                message_vision(CYN"$N�Ų��ߵ�$n���ʲô��Ҳû˵��ͻȻ����һ������$n
�������$p�����ࡣ\n"NOR,di,ying);
                who=ying->query("busy_object");
                message_vision(CYN"$N¶��һ�ֹŹֿ־�����񣬵���$n���ԣ��þ����һ˿������
Ϊ$n�⿪Ѩ����\n"NOR,ying,who);
                who->start_busy(1);
                ying->die();
                call_out("kill_who",3,di,who);
                return 1;
        }
        return 0;
} 
int kill_who(object di, object who)
{
        message_vision(HIY"$N��$n΢Ц��������˵����ֻҪ�ܹ�ʤ���ң�ʲô�㶼������ȥ����\n"NOR,di,who);
        di->kill_ob(who);
        who->kill_ob(di);
        return 1;
}
        
void die()
{
        object yang,room,me,yangcorpse,ying;
         
        room=environment();
        
        yang=present("yang zheng",room);
        ying=present("ying wuwu",room);
        if(objectp(yang))
        {
                yang->set("killed_di",1);
                ying->set("sad_leave",1);
        }
        else
                if(me=room->query("�������"))
        {
                if (me->query("libie/���_ɱ��������")!=1 
                && me->query("libie/���_ɱ��������")!=2) {
                        me->add("score",200);
                        me->add("potential",200);
                        me->add("combat_exp",10000);
                }
                me->set("libie/���_ɱ��������",1);
                
        }
        ::die();
}  
int return_home(object home)
{
        home=environment();
        if(!present("yang zheng",home))
   {
                destruct(this_object());
                home->delete("�������");
        }
        return 1;
}  
