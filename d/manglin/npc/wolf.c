 inherit NPC;
void create()
{
        set_name("��ë����", ({ "wolf", "big wolf" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ�����ޱȵĻ�ɫ����\n");
        
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
                "��������񺿼�����\n",
                "����������̹�ʹ�㲻��������\n"
        }) );
                set("combat_exp", 20000);
                set("bellicosity", 3000 );
        
        set_temp("apply/attack", 120);
        set_temp("apply/armor", 120); 
        setup();
        if (!random(50)) carry_object(__DIR__"obj/wolftooth");
}      
