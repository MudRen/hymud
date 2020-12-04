 // waiter.c
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg); 
void create()
{
        set_name("�ϲ÷�", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 52);
        set("long",
                "��λ�ϲ÷���Ц�����æ��������ʱ�Ĳ�һ���Լ����ϻ��ۡ�\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
 //       add_action("do_ding", "ding"); 
 //       add_action("do_bu", "bu");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�ϲ÷�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������·��ɡ�\n");
                        break;
                case 1:
                        say( "�ϲ÷��ü����˵������λ" + RANK_D->query_respect(ob)
                                + "���������ְ�����ﲻ���㡣\n");
                        break;
        }
} 


