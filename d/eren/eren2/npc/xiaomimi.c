#include <ansi.h>
inherit NPC;
void special_smart_fight(); 
void create()
{
        set_name("������",({"xiao mimi"}));
        set("title",HIM"�����˲�����"NOR);
        set("long", "һ��������ȹ���ױ�б���Ŷ�軨���ٸ�������������ô��ȣ���֫��
��ô��ӯ��\n"); 
        set("age",30);
        set("attitude", "aggressive");
        set("combat_exp", 20000000);
        set("dungeon_npc","eren2");
        set("class","huashan"); 
        set("max_atman", 20000);
        set("atman", 20000);
        set("max_mana", 20000);
        set("mana", 20000);
        set("max_neili",30000);
        set("neili",30000);
        set("force_factor",100);
        set("no_busy",100);
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set_skill("sword",250);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("parry",300);
        set_skill("unarmed",300);
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: special_smart_fight() :),    
        }) );
        
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
} 
void special_smart_fight() {
        
        object me, *enemy, owner,victim;
        int num,i;
        string msg;
        
        me=this_object();
        enemy=me->query_enemy();
        if (!random(100)) {
                for (i=0;i<sizeof(enemy);i++) {
/*                      if (!userp(enemy[i])) { 
                                if(owner=enemy[i]->query("possessed")) {
                                        victim = owner;
                                        }
                        } else victim = enemy[i];*/
                        victim=enemy[i];
                        if (!victim) continue;
                   if (environment(victim)!=environment(me)) continue;
                        msg = HIW "$n��ɫ��òҰ���ֽ��˫������ָ�ⷢ��ӨӨ�Ĺ�â�� 
$n��Ȼ��һ����õ�������$N��ǰ��˫צ�����ץ��$N�Ŀڣ� \n"NOR;
                        msg += RED"\n\n$N"RED"�ò������ŵ��۹⿴���Լ��Ŀڵ�Ѫ��������һ�Σ����ڵ��ϡ� \n" NOR;
                        victim->receive_wound("qi", victim->query("max_qi")+300000,me);
                        message_vision(msg, victim, me);
                        return;
                }
        }
        if (!random(10)) {
                message_vision(HIM"$NͻȻͣ��������ȻһЦ��������Ҫɱ�ң���Ҳû�취��\n"NOR,me);
                for (i=0;i<sizeof(enemy);i++) {
                        if (random(enemy[i]->query("cps"))<20){
                                enemy[i]->start_busy(2);
                                message_vision(WHT"$N����$n�����ɵó��ˡ�\n"NOR,enemy[i],me);
                }
                }
                message_vision(CYN"$N��̾����������������������ֻ֪��������룬��������£���
��Ҳû���ӡ���\n"NOR,me);
                return;
        }
        if (!random(10)) {
                message_vision(
                
                HIG"\n$Nͣס���֣���ƮƮ���۹�����������㣬������˿����Цӯӯ ...\n\n"NOR
                WHT"$N��������ǰ�죬��ֻ����ϸ��������������覴ã����������ص�����֮����\n\n\n" NOR, me);
                for (i=0;i<sizeof(enemy);i++) {
                        if (random(enemy[i]->query("cor"))<30){
                                enemy[i]->receive_damage("jing", random(3000));
                                enemy[i]->receive_damage("qi", random(1000));
                                message_vision(RED"$N��ͷ����̰��ʹ�����ĺ�������Ѫ����\n"NOR,enemy[i]);
                        }
                }
        }
        return;
}     
