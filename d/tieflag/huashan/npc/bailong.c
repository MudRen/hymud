#include <ansi.h>
inherit NPC;
int do_leave(object me);
void create()
{
        set_name("��Զ��", ({ "sun yuanchao", "sun" }) );
        set("gender", "����" );
        set("age", 28);
        set("nickname", HIW"�������"NOR);
        set("long", @LONG
�����������˫Ŀ��Ȼ������ȥһ���˲ġ�
LONG
);        
set("combat_exp", 3800000+random(500000));
    set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        

         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/feitian/npc/blackblade")->wield();
} 
void die(){
        object me;
        
        if(objectp(me=query_temp("last_damage_from") )){ 
                if(me->query("marks/���������")){
                        me->delete("marks/���������");
                        if(!me->query("m_success/�ȷ����")){
                                me->set("m_success/�ȷ����",1);
                                me->add("score",800);
                                me->add("combat_exp", 3000);
                                me->add("potential", 2000);
                        }
                environment(this_object())->check_rescue(me);
                }
        }       
        ::die();
}      
