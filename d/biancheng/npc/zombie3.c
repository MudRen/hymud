#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void do_bite(); 
void create()
{
        set_name("�߽�ʬ",({"zombie"}));
        set("title","�˼����");
        set("long","�����������۾���һ����ƽ�������������������Ǳ��Ӻͱǿף�һ���ѷ�
������ͣ��촽û���ˣ���������¶�����档һֻ�ֱ�Ť������������
��һ��һ�ͣ������˻��Ǵӹ��Ź����߻����Ľ�ʬ��\n"); 
        set("gender","����");
        set("attitude", "aggressive");
        
        set("combat_exp",5000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        set("str",40);
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_neili",1000+random(500));
        set("neili",query("max_neili"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
        
        set_skill("unarmed",800);
        set_skill("dodge",800);
        set_skill("parry",800);
        set_skill("move",800);
        set_skill("force",800);
                
        
        setup();
    
} 
void do_bite()
{
        object *enemy;
        message_vision(HIB"$N�������һ��������Ż�ĳ�����ʹ�����ͷ�����͡�\n"NOR,this_object());
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("jing", 400);
                COMBAT_D->report_status(enemy[i]);
        }
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(me->query("wanma/׼��ɱ��ʬ"))
                        me->add_temp("wanma/��ʬ",3);
        message_vision("$N�����ص���ȥ��ʧ�ˡ�\n",this_object());
        destruct(this_object());
}
