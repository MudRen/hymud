#include <ansi.h>
 inherit NPC;
int strangle();
int slash();
int bite();
int octopus_attack(); 
void create()
{
        set_name("������" , ({ "octopus" }) );
        set("title", HIW "ǧ��޹�"NOR);
        set("race", "Ұ��");
        set("age", 10000);
        set("long", "����һ�������޴�����㣬�����ס����Ǻ�ɫ�Ĵ����ľ޴��۾��������㡣��
�İ�ֻ�첲������˵��ֻ�ţ��������Դ��ϣ�����������˫����ô����������
������踾�˵�ͷ��������Ʈ����ֶ������졪�����ʵ��죬���������ĵ�һ
��������ֱ�Ļ򿪻�ϡ����Ĺ��ʵ���ͷ�����м��ż���������������¶����
һ�������Ĵ���ǯ�� ����������һ������!�����������Ĵ��Σ��������ͣ���
��һ����飬�������¶�����������ǧ������ϵĲ�������ɫ������ֶ���
�ļ���������Ѹ�ٵĸı��ţ��ӻҰ�ɫ½����Ϊ���ɫ��\n");
        
        set("combat_exp", 5000000);
        
        set("dex", 290);
        set("str", 290);
        set("cor", 100);
        set("cps", 30);
        set("dur", 30);
        set("agi", 30);
        set("boss",1);
        set("max_jing",250000);
        set("max_qi",2200000);
        set("max_jing",250000);
        set_skill("dodge",800);
        
        set("no_curse",1);
        set("resistance/kee",50);
        
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite"}) );
        
        
           set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                30:     (: octopus_attack() :),
        ]) );           
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: bite()  :),     
        }) );
        
        set("chat_chance",1);
        set("chat_msg",({
                "������������һ����۾������㣬ʹ�㲻��������\n",
        }) );  
        
        set_temp("apply/attack", 600);
        set_temp("apply/armor",  200);
        set_temp("apply/dodge",  450);
        set_temp("apply/damage", 50);
        setup();
        if (!random(2)) carry_object(__DIR__"obj/claw");
        if (!random(200)) carry_object(__DIR__"obj/pearl2");
} 
int octopus_attack() {
        
        if(time()-query("bite_time")<4) return 1;
        switch (random(2)) {
                case 0: strangle();break;
                case 1: slash();break;
        }
        return 1;
}  
int strangle(){
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        enemy=ob->query_enemy();
        for (i=0;i<6;i++){
                me=enemy[random(sizeof(enemy))];
           if (!me->is_busy()) break;
        }
        if (me->is_busy()) return 1;
        
        message_vision(HIW"\n$N�Ĵ��ֺ�Ȼ���ſ������������ߴ�����ֻ�۾���һ���������˳�����
��һ�ž�����$n������ס��\n"NOR,ob,me);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}
         
int slash () {
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        enemy=ob->query_enemy();
                
        message_vision(HIM"\n$N�������Ȼ�����ɫ���漴���һ���������а����������·��ɣ�
�����ڳ���ÿһ���ˡ�\n"NOR,ob); 
        for (i=0;i<sizeof(enemy);i++) {
                tell_object(enemy[i],HIB"����ö�����棬ͷ��Ŀѣ��\n"NOR);
                enemy[i]->receive_damage("jing",300,ob);
                if (!userp(enemy[i])) enemy[i]->receive_damage("jing",300);
                COMBAT_D->report_status(enemy[i]);
        }       
        if (ob->query_busy()<2) ob->start_busy(1);
        return 1;
}  
int bite() {
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        ob->set("bite_time",time());
        enemy=ob->query_enemy();
        me=enemy[random(sizeof(enemy))];
        message_vision(HIR"\n$N���Դ�������һ����ת�ţ���Ȼ���ſ�Ѫ����죬һ����$nҧȥ��\n"NOR,ob,me);
        me->receive_wound("qi",1000);
        COMBAT_D->report_status(me);
        if (ob->query_busy()<3) ob->start_busy(2);
   return 1;
}  
void die()
{
        object rstone, me,owner,money_reward;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        environment(this_object())->set("octopus_death",time());
        
        if(objectp(me)) { 
                if(!me->query("m_killer/������")){
                        CHANNEL_D->do_sys_channel("info",sprintf("%s��%s��%s%s%s��", NATURE_D->game_time(),
                                me->query("name"), environment(this_object())->query("short"),"նɱ", name())); 
                        me->set("m_killer/������",1);
                        me->add("score",100);
                        me->add("combat_exp",10000);
                        me->add("potential", 2000);
                        money_reward = new("/clone/money/gold");
                        money_reward->set_amount(100);
                        money_reward ->move(me);
                        tell_object(me,WHT"��ϲ��ɱ���˴����㣬�㱻������!!!\n"NOR);
                }
        } 
        ::die();
}  
