inherit NPC;
#include <ansi.h>
int big_blowing();
int hurting();
void create()
{
        set_name(HIR"�һ�����"NOR, ({ "dragon lord", "dragon" }) );
        set("vendetta_mark","dragon");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 200);
        
        set("long", 
"����һ��ȫ���죬�����֮��Ļ����������������
��ȫ��ɢ���ų��ɫ�Ļ���\n");
        
        set("str", 100+random(20));
        set("con", 52);
        set("dex", 20);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("resistance/qi",40);
        set("no_curse",1);
        set("max_qi", 60000);
        set("max_jing", 30000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                (: big_blowing :)
        }) ); 
        set("combat_exp", 9000000);
        set("bellicosity", 3000 );
        
        set_temp("apply/attack", 800+random(800));
        set_temp("apply/unarmed_damage",200+random(200));
        set_temp("apply/armor", 1000+random(1000)); 
        setup();
}

int big_blowing() 
{
        remove_call_out("hurting");
        message_vision( HIR "\n\n$N"HIR"���������һ�ڻ�����ȫ��תΪ�ʺ�Ļ�ɫ�����������ʹ��˼�������\n\n"NOR,
        this_object());
        hurting();
        start_busy(3+random(2));
} 
int hurting()
{
        int i;
        int dam;
        object *inv;
        
        message_vision( HIR "\n\n$N"+HIR"�³�һ�ɳ�ɷٽ�Ļ��森����������ƺ�����ȼ���ţ�����\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = (random(1000)+1000) * (1 - inv[i]->query_temp("apply/reduce_fire"));
        if(dam <0) dam = 0;
        inv[i]->receive_wound("qi",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
