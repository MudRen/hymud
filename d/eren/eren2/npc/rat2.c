 inherit NPC;
void create()
{
        set_name("����", ({ "rat" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("attitude", "aggressive");
        set("int",10);
        set("long", "һֻ��Բ��׳�ĺ����󣬺ݺݵص����㡣\n");
        set("max_qi", 100);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 80); 
        setup();
        carry_object(__DIR__"obj/zhuguo");
        carry_object(__DIR__"obj/zhuguo");
}      
