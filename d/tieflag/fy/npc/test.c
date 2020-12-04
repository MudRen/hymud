#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����Ʒ", ({ "tester" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ��Ϊ��������ձ�����С���ˣ�\n");
          set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}  
void die(){
    object killer;
    string location;
    int difficulty;     
    location="���п�";
    
    killer = this_object()->query_temp("last_damage_from");
         
    if(!killer->query("m_killer/tester")&& !this_object()->is_ghost()) {
         killer->set("m_killer/tester",1);
         difficulty =1;
         this_object()->master_reward(this_object(),killer,location,difficulty);
        }
        
    ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
    object money_reward;
    int i, pot, combat_exp, score;
    string reward_msg,kill_msg;    
    string *kill_type = ({ "��ɱ", "��ɱ", "��ɱ", "����","��ɱ" });
    reward_msg="";
    
    kill_msg= kill_type[random(5)];
    
    if (killer->query("combat_exp")>victim->query("combat_exp")/50) {
        
        pot = difficulty*200;
        combat_exp = difficulty*20000;
        score = difficulty*50;
    
        killer->add("potential",pot);
        killer->add("combat_exp", combat_exp);
        killer->add("score", score);
        for(i=0; i<difficulty+1; i++) {
        money_reward = new("/clone/money/tenthousand-cash");
        money_reward ->move(killer);
        }
        
        CHANNEL_D->do_sys_channel(
        "info",sprintf("%s��%s��%s%s%s��", NATURE_D->game_time(),
                killer->name(), location, kill_msg, this_object()->name()) );  
        reward_msg +=HIW+"��ɹ���ɱ����һ�������콾���㱻�����ˣ�\n\t\t" +
        chinese_number(combat_exp) + "��ʵս����\n\t\t"+
        chinese_number(pot) + "��Ǳ��\n\t\t" +
        chinese_number(score) + "������\n\t\t" + 
        chinese_number(difficulty+1) + "��������\n" + NOR;
                
        tell_object(killer,reward_msg); 
        } 
}        
