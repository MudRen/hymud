 inherit NPC;
void hide();
void create()
{
        if( random(2))
        set_name("�����", ({ "cockroach" }) );
        else
        set_name("С���", ({ "cockroach" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�ǳ����ĵ���롣 \n"); 
        set("combat_exp",7000);
        set("score", 200);
        set("neili", 200);
         set("max_neili", 200);
        set_skill("dodge", 100);
        set("arrive_msg", "�ɿ�����˹���");
        set("leave_msg", "�ɿ��������");
        set("limbs", ({ "ͷ��", "����"}) );
         set("verbs", ({ "bite" }) );
        set_temp("armor", 50); 
    set("chat_chance", 25);
    set("chat_msg", ({
            (: random_move :),
            (: hide :)
    }) ); 
        setup();
} 
void hide()
{
        if( !environment() ) return;
        message("vision", "��������������ǽ�ߵ��ѷ��ˡ�\n", environment());
        call_out("disappear", 1);
} 
void disappear()
{
        destruct(this_object());
}      
