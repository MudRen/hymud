 //TIE@FY3`
inherit NPC;
void create()
{
        set_name("��ԯ��ȱ", ({ "san que" }) );
        set("gender", "����" );
        set("age", 53);
        set("title","���۵���");
        set("long", "��ԯ���ɵ��ֵܣ��书�߾���Ϊ���ĺ�������\n");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
        set("fly_target",1);
        set("intellgent",1);
        set("difficulty", 5);
//      set("str", 27);
        set("neili", 200);
//        set("attitude", "aggressive");
        set("attitude", "friendly");
        set("max_neili", 200);
        set("force_factor", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
"��ԯ��ȱ��Ц���������ҵġ����ذ�����ɱ���󡱣�\n",
"��ԯ��ȱЦ������ʮһ���������������ǰѸ�¹�����������ҵ���ɱ����\n",
                (: random_move :),
         }) );
        set("inquiry", ([
                "��ʮһ��" : "�Ҹոմ��������ϸ���һ���⣬�����ˡ�\n",
                "xiao 11" : "�Ҹոմ��������ϸ���һ���⣬�����ˡ�\n",
        ]) );
        setup();
    add_money("gold", 3);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/qin")->wield();
}       

void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N����Ŀ����㣺��������ڣ��ѵ������ܣ�����ɱ���㣡����������\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                command("hug "+ob->query("id"));
                message_vision("$N������Ц�����ֵܽ����ֵ������ҽ��᣿\n", this_object() );
        }
        return;
}     
