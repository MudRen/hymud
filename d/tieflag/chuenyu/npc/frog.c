 inherit NPC;
void create()
{
        set_name("����", ({ "insect" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ��ͷ���ԵĴ�����\n");
        set("max_qi", 1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) ); 
        set_skill("dodge", 150); 
        setup();
}        
