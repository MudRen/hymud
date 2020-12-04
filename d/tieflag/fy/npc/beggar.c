 // TIE@FY3
inherit NPC;
void create()
{
        set_name("����ؤ", ({ "old beggar","beggar" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ��������˪֮ɫ������ؤ��\n");
        set("combat_exp", 100);
        create_family("ؤ��", 12, "����");
        set("title","ؤ��һ������");
        set("class","beggar");
        set("str", 27);
        set("neili", 20);
        set("max_neili", 20);
        set("force_factor", 2);
        set_skill("begging",350);
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                (: random_move :),
        }) );
        carry_object(__DIR__"obj/old_book");
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
} 
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"������С������뿪��\n");
        return 0;
}
 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        } 
} 
void greeting(object ob)
        {
                command("beg silver from "+ob->get_id());
        }      
