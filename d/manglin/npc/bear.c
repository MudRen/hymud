 inherit NPC;
void create()
{
        set_name("�׾�����", ({ "bear", "big bear" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ�����ޱȵĻ�ɫ��\n");
        
        set("str", 48);
        set("cor", 52);
        set("cps", 22); 
        set("max_qi", 600);
        set("max_jing", 600);
        set("max_jing", 900);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
                set("combat_exp", 20000);
                set("bellicosity", 3000 );
        
        set_temp("apply/attack", 100);
        set_temp("apply/armor", 220);
        set_temp("apply/damage", 100);
        setup();
} 
