
inherit NPC;

void create()
{
       set_name("������", ({"aqi po", "po"}));
       set("long", "һ������������ʮ�꣬�����������ص���̫�š�\n");
       set("gender", "Ů��");
        set("combat_exp", 5000);
	set("per", 18);
       set("age", 66);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
	set_skill("dodge", 20);
        setup();
       add_money("silver", 7);
        carry_object("/d/qujing/gao/obj/ao")->wear();

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
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "���������ص�˵������λ" +
RANK_D->query_respect(ob)
                                + "���϶�ҡ�⣬����֮���ţ�\n");
                        break;
		case 1:
                        say( "���������������첻֪˵��Щʲô��\n");
                        break;
		case 2:
                        say( "������̧ͷ���˿��㡣\n");
                        break;
		case 3:
                        say( "��������Ц�˼�����\n");
                        break;
                case 4:
                        say( "�����������������������Ҫ��ȼ�����\n");
                        break;


        }
}

