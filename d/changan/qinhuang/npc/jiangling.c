#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"

void create()
{
        string *names = ({ "��ٸ����" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "jiang ling"}));
        set("long", @LONG
����һ����˯�ڻ���ǧ����ٸ���죬��߰˳����࣬���������ƶ��ɣ�������ʮ�ּ�
Ӳ�����ֳ�һ����ͭ������������Ϊ���䡣�ڻ�����Ϣ�������£�������֫���Ի��
���ؽ���Ҳ��ģ���������ܹ鲻��ǳ���
LONG);
        set("title", YEL "�����Ʒ����" NOR); 
 
        set("str", 120);
        set("con", 120);
        set("dex", 120); 
        set("int", 120);
        set("max_qi", 600000);
        set("max_jing", 600000);
        set("neili", 650000);
        set("max_neili", 650000);
        set("max_jingli", 600000);
        set("attitude", "killer");
        set("auto_perfrom", 1);

        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );  
        set("combat_exp", 18000000);
        set("death_msg",YEL"\n$N������һ�ѻ�����\n\n"NOR);

        set("bonus", 15000);
        set_temp("apply/attack", 800);
        set_temp("apply/parry", 800);
        set_temp("apply/damage", 800);
        set_temp("apply/unarmed_damage", 800);
        set_temp("apply/armor", 800);          
        setup();
initlvl(250+random(370)); 
} 

void init()
{
        object me;

        ::init();
        if( !interactive(me = this_player()) || 
            this_object()->is_fighting())
                return;
                

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
 

void sp_attack() 
{
        object *enemies,enemy;
        string msg;
 
        enemies = query_enemy();
        if( !enemies || sizeof(enemies)==0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        msg = RED"$N"RED"һ�����У������³���ɳ������Х���Ǽ�����Х���絶���罣��Խ��Խ��... Խ��Խ��...����\n"
              RED"$n"RED"ȫ���ʱǧ���ٿף���Ѫֱӿ������\n"NOR;
        message_vision(msg, this_object(), enemy);
        enemy->receive_damage("qi",300+random(500));
        COMBAT_D->report_status(enemy);
        if( !enemy->is_busy() )
                enemy->start_busy(2);        
        return;
}

