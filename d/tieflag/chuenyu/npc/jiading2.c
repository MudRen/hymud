 // jiading.c
inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("���¼Ҷ�", ({ "guard" }) );
        set("gender", "����" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23); 
        set("max_neili", 100);
        set("neili", 100);
        set("force_factor", 10); 
        set("attitude", "heroism"); 
        set("long",@LONG
����һλ���ɱ��ļҶ���ר�����̲�ȥ���ɱ������ˡ�
LONG); 
        set("combat_exp", 3500);
        set("score", 50); 
        set_skill("hammer", 50);
        set_skill("dodge", 40);
        set_skill("parry", 50);
        setup();
        add_money( "coin" , 50);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/7hammer")->wield();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checklooking");
                call_out("checklooking", 1, ob);
        }
} 
void checklooking(object ob)
{ 
    if ( random((int)ob->query("per")) < 10  )
         {
        command("say վס�����ʲô�ġ�");
        command("say ��������ü���ۣ����������������������ʲô�ö�����");
                kill_passenger(ob);
         }      
} 
string kill_passenger(object who)
{
        set("attitude", "aggressive");
        kill_ob(who);
        return 0;
}     