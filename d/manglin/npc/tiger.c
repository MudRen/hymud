 // mind_beast.c
inherit NPC; 
void create()
{
        set_name("�׶��ͻ�", ({ "tiger", "big tiger" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ�����ޱȵİ׶��ͻ�\n");
        
        set("str", 48);
        set("cor", 52);
        set("cps", 22); 
        set("max_qi", 600);
        set("max_jing", 600);
        set("max_jing", 900);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "�׶��ͻ��͵�����һ�ˣ�\n",
                "�׶��ͻ��ݺݵ���β������ɨ����\n"
        }) ); 
                set("combat_exp", 20000);
                set("bellicosity", 3000 );
        
        set_temp("apply/attack", 160);
        set_temp("apply/armor", 140); 
        setup();
}      
