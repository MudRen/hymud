 // mind_beast.c
inherit NPC; 
void create()
{
        set_name("����", ({ "heaven lion", "lion" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 3);
        set("long", "�����ͨ����ǳ����ɫ��������ʨ��ʨ���������\n");
        
        set("str", 48);
        set("cor", 52);
        set("cps", 22); 
        set("max_qi", 600);
        set("max_jing", 600);
        set("max_sen", 900);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
                set("combat_exp", 20000);
        
        set_temp("apply/attack", 160);
        set_temp("apply/armor", 140);
        set_temp("apply/damage", 200); 
        setup();
        carry_object(__DIR__"obj/raw_cloth")->wear(); 
}
 
void init()
{
        object me;
        me = this_player();
        if( interactive(me))
                if( me->query("class") )
                if( me->query("class") != "yinshi") 
                kill_ob(me); 
} 
